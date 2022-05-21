#include <stdio.h> /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), sendto() and recvfrom() */
#include <arpa/inet.h> /* for sockaddr_in and inet_addr() */
#include <stdlib.h> /* for atoi() and exit() */
#include <string.h> /* for memset() */
#include <unistd.h> /* for close() */
#include <netdb.h>
#include <fcntl.h>

#define FILE_MODE 0777
#define IP_LEN	64
int fd;
int sock;

struct sockaddr_in serverSockAddr; /* server address */
struct sockaddr_in clientSockAddr; /* client address */

char sendBuff[20000];
char rcvBuff[20000];
char fileBuff[20000];

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
int sendToServer(char *message){
    //sendBuff = message;
    if(send(sock,message,strlen(message),0)==-1){
        return -1;
    }
    return 0;

}
int rcvFromServer(){
    return  recv(sock,rcvBuff,sizeof (rcvBuff),0);

}

int isSuccessful(char* str){
    char* str2 = "OK";
    if(strstr(str, str2)==NULL)
        return -1;
    else
        return 0;
}

int anythingRecieved(int charNum){////-1:receive error   0:no received message    1:normal
    if(charNum == -1){
        return -1;
    }
    if(charNum == 0){
        return 0;
    }
    return 1;
}

int sendReceive(char* str){//return:-1:receive error   0:receive nothing   1:success   2:return -ERR
    sendToServer(str);
    int i = rcvFromServer();
    if(anythingRecieved(i) <=0)
        return anythingRecieved(i);
    else
    {
        if(isSuccessful(rcvBuff)==0)
            return 1;
        else
            return 2;
    }
}

////////////////////////////////////after login and getlist and functions who set rcvBuff, clear buff with memset(rcvBuff,0,sizeof(rcvBuff));
///login after connection finished, automatically login.
int login(){
    sendReceive("USER IA_pop3_client\n");
    memset(rcvBuff,0,sizeof(rcvBuff));
    sendReceive("PASS NHRIWKBTQGCWGIUB\n");
}

int getList(){//////return:-1:receive error   0:receive nothing   1:success   2:return -ERR
    sendReceive("LIST\n");
}
int getMailStatus(){//////return:-1:receive error   0:receive nothing   1:success   2:return -ERR
    sendReceive("STAT\n");
}
int getMailDetail(char *i){///usage: getMailDetail("1\n")
    char str[100]="RETR ";
    strcat(str, i);
    sendReceive(str);
}

int downloadDelete(char *i){////first reterive, then store
    int v = getMailDetail(i);

    char str[100]="DELE ";
    strcat(str, i);

    if(v!=1)
        return v;
    else{
        FILE *fp;
        fp = fopen("test.eml","w+");///////the name here must match the mail user selects
        fprintf(fp,"%s",rcvBuff);
        fclose(fp);

        memset(rcvBuff,0,sizeof(rcvBuff));
        sendReceive(str);
    }
}
int reset(){
    sendReceive("RSET\n");
}

int quit(){
    sendReceive("QUIT\n");
}

int readFlie(char* fliename){
    if((fd = open(fliename,O_RDONLY,0))==-1)
        return -1;

    int i = read(fd,fileBuff,sizeof(fileBuff));
    close(fd);
    return i;
}

int main(){

    connectToServer();
    rcvFromServer();
    printf("%s",rcvBuff);
    memset(rcvBuff,0,sizeof(rcvBuff));
    switch (login())
    {
        case 0:
            printf("nothing returned from server\n");
            break;

        case -1:
            printf("receive error\n");
            break;

        case 1:
            printf("successfully login!\n");
            printf("%s",rcvBuff);
            break;

        case 2:
            printf("return error\n");
            break;

        default:
            break;
    }
    memset(rcvBuff,0,sizeof(rcvBuff));






    // memset(rcvBuff,0,sizeof(rcvBuff));

    switch (getList())
    {
        case 0:
            printf("nothing returned from server\n");
            break;

        case -1:
            printf("receive error\n");
            break;

        case 1:
            printf("%s",rcvBuff);
            break;

    }
    memset(rcvBuff,0,sizeof(rcvBuff));

    int v = readFlie("test.eml");
    printf("%s",fileBuff);
    printf("%d bytes are read",v);
    // downloadDelete("1\n");

    // printf("%s",rcvBuff);
    // switch (getMailDetail("1\n"))
    // {
    // case 0:
    //     printf("nothing returned from server\n");
    //     break;

    // case -1:
    //     printf("receive error\n");
    //     break;

    // case 1:
    //     printf("%s",rcvBuff);
    //     break;

    // case 2:
    //     printf("return error\n");
    //     break;

    // default:
    //     break;
    // }
    //

}