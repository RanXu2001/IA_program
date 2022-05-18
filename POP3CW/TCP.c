#include <stdio.h> /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), sendto() and recvfrom() */
#include <arpa/inet.h> /* for sockaddr_in and inet_addr() */
#include <stdlib.h> /* for atoi() and exit() */
#include <string.h> /* for memset() */
#include <unistd.h> /* for close() */
#include <netdb.h>


#define IP_LEN	64
int sock;

struct sockaddr_in serverSockAddr; /* server address */
struct sockaddr_in clientSockAddr; /* client address */

char sendBuff[20000];
char rcvBuff[20000];

char servIP[64];
char servDomainName[64];

int rcvLength;
int sendLength;

const unsigned short servPort = 110;

int getIpFormDomainName(char* servDomainName, char* servIP, unsigned char ipLen)
{
    struct hostent* host = NULL;
    host = gethostbyname(servDomainName);

    if(NULL == host)
    {
        return -1;
    }
    inet_ntop(host->h_addrtype, host->h_addr, servIP, ipLen);

    return 0;
}
int connectToServer(){//成功返回0，失败返-1
    printf("Enter the domain name you want to connect:\n");
    scanf("%s",servDomainName);


    if(getIpFormDomainName(servDomainName,servIP,IP_LEN)==-1){
        printf("Fail to get IP address from domain name\n");
        return -1;
    }


    if ((sock = socket(PF_INET, SOCK_STREAM, 0)) < 0){
        printf("socket() failed.\n");
        return -1;
    }

    memset(&serverSockAddr, 0, sizeof(serverSockAddr));   /*Zero out structure*/
    serverSockAddr.sin_family = AF_INET;                /* Internet addr family */
    serverSockAddr.sin_addr.s_addr = inet_addr(servIP); //IP address in numbers-and-dots notation (ASCII string) to IP address structure in network byte order
    serverSockAddr.sin_port = htons(servPort);      /* Server port */

    if(connect(sock,(struct sockaddr *) &serverSockAddr,sizeof(serverSockAddr))<0){
        printf("connecting to %s\n",servIP);
        printf("connect failed.\n");
        return -1;
    }
    else
        printf("Connect to server successfully!\n");
    return 1;
}
void sendToServer(char *message){
    //sendBuff = message;
    if(send(sock,message,sizeof (message),0)!=sizeof (message)){
        printf("Send an unexpected number of bytes\n");
    }
    printf("Successfully send %s",message);

}
void rcvFromServer(){
    recv(sock,rcvBuff,sizeof (rcvBuff),0);
    rcvBuff[255] = '\0';
}

int isSuccessful(char* str){
    char* str2 = "OK";
    if(strstr(str, str2)==NULL)
        return -1;
    else
        return 0;
}
int main(){

    connectToServer();
    rcvFromServer();
    printf("%s",rcvBuff);
    memset(rcvBuff,0,sizeof(rcvBuff));

    sendToServer("USER IA_pop3_client@163.com");
    rcvFromServer();
    printf("%s",rcvBuff);
    memset(rcvBuff,0,sizeof(rcvBuff));

//    if(isSuccessful(rcvBuff)==0)
//        printf("login successful!");
    //顺序不能错

    sendToServer("PASS NHRIWKBTQGCWGIUB");
    rcvFromServer();
    printf("%s",rcvBuff);
    memset(rcvBuff,0,sizeof(rcvBuff));

    //

}