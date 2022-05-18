#include <stdio.h> /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), sendto() and recvfrom() */
#include <arpa/inet.h> /* for sockaddr_in and inet_addr() */
#include <stdlib.h> /* for atoi() and exit() */
#include <string.h> /* for memset() */
#include <unistd.h> /* for close() */
#include <netdb.h>
int sock;

struct sockaddr_in serverSockAddr; /* server address */
struct sockaddr_in clientSockAddr; /* client address */

char *sendBuff;
char *rcvBuff;

struct  hostent  *serverHostEnt;
char **servIpAddresses;

char *servIP;
char *servDomainName;
const unsigned short servPort = 110;
void connectToServer(){
    servIP = "123.126.97.79";
    printf("Enter the domain name you want to connect:\n");
    scanf("%s",servDomainName);
//    if ((serverHostEnt  =  gethostbyname(servDomainName))  ==  NULL)
//    {
//        printf( "  gethostbyname error for host:%s\n " , servDomainName);
//        return   0 ;
//    }
//    servIpAddresses = serverHostEnt -> h_addr_list;
//    servIP = inet_ntop(serverHostEnt -> h_addrtype,  serverHostEnt ->  h_addr, servIP,  sizeof (servIP));

    if ((sock = socket(PF_INET, SOCK_STREAM, 0)) < 0)
        printf("socket() failed.\n");

    memset(&serverSockAddr, 0, sizeof(serverSockAddr));   /*Zero out structure*/
    serverSockAddr.sin_family = AF_INET;                /* Internet addr family */
    serverSockAddr.sin_addr.s_addr = inet_addr(servIP); //IP address in numbers-and-dots notation (ASCII string) to IP address structure in network byte order
    serverSockAddr.sin_port = htons(servPort);      /* Server port */

    if(connect(sock,(struct sockaddr *) &serverSockAddr,sizeof(serverSockAddr))<0){
        printf("connecting to %s",servIP);
        printf("connect failed.\n");
    }
    else
        printf("Connect to server successfully!\n");
}

void sendToServer(char *message){
    sendBuff = message;
    if(send(sock,sendBuff,sizeof (sendBuff),0)!=sizeof (sendBuff)){
        printf("Send an unexpected number of bytes\n");
    }

}
void rcvFromServer(){
    recv(sock,rcvBuff,sizeof (rcvBuff),0);

    printf("%s\n",rcvBuff);

}

int main(){
    connectToServer();
    sendToServer("USER IA_pop3_client");
    rcvFromServer();

}

