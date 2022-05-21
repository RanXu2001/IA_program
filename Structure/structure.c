//
// Created by 16003 on 2022/5/19.
//
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

struct Email{
    char subject[50];
    char content[1000];
};

void Displaymainmenu();//显示主菜单
int getList();//Get a list of messages and sizes  success:0,fail:-1
int getMailStatus();//Get mail status             success:0,fail:-1
int getMailDetail(char *);//Display mail in detail      success:0,fail:-1
int search();//Search text in all mails           success:0,fail:-1
int displayBySubjects();//Display by subjects     success:0,fail:-1
int downloadDelete(char *);//Download the mail and delete in the remote service          success:0,fail:-1
int quit();//Quit                                 success:0,fail:-1
void nextStep();//show next step
int login();//get in the pop.163.com              success:0,fail:-1
int getIpFormDomainName(char* , char* , unsigned char);
int getIpFormDomainName(char* , char* , unsigned char);
int sendToServer(char *);
int rcvFromServer();
int isSuccessful(char*);
int anythingRecieved(int);
int sendReceive(char* );
int reset();
int readFlie(char* );
int connectToServer();


int main()
{
    //TCP链接
    connectToServer();
    rcvFromServer();
    printf("%s",rcvBuff);
    memset(rcvBuff,0,sizeof(rcvBuff));
    //login
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



    //Display main menu

    Displaymainmenu();
    return 0;
}
void Displaymainmenu()//显示主菜单
{
    int choice;
    printf("----------------------------------------------------------------------------\n");
    printf("                   Please enter the option number(1~7)                      \n");
    printf("----------------------------------------------------------------------------\n");
    printf("|                              POP3 client                                 |\n");
    printf("|                  1 --Get a list of messages and sizes                    |\n");
    printf("|                  2 --Get mail status                                     |\n");
    printf("|                  3 --Display mail in detail                              |\n");
    printf("|                  4 --Search text in all mails                            |\n");
    printf("|                  5 --Display by subjects                                 |\n");
    printf("|                  6 --Download the mail and delete in the remote service  |\n");
    printf("|                  7 --Quit                                                |\n");
    printf("|               Program written by Ran Xu and Yichen Liu                   |\n");
    printf("----------------------------------------------------------------------------\n");
    printf("Please choose number:\n");
    do
    {
        scanf("%d",&choice);
        switch(choice) {
            case 1:{
                if(getList() < 0)
                    printf("getList() fail.\n");
                break;
            }

            case 2:{
                if(getMailStatus() < 0)
                    printf("getMailStatus() fail.\n");
                break;
            }

            case 3:{
                if(getMailDetail() < 0)
                    printf("displayDetail() fail.\n");
                break;
            }

            case 4:{
                if(search() < 0)
                    printf("search() fail.\n");
                break;
            }

            case 5:{
                if(displayBySubjects() < 0)
                    printf("displayBySubjects() fail.\n");
                break;
            }

            case 6:{
                if(downloadDelete() < 0)
                    printf("downloadDelete() fail.\n");
                break;
            }

            case 7:{
                if(quit() < 0)
                    printf("quit() fail.\n");
                exit(0);
            }

            default:{//仅限数字
                printf("The correct option was not detected.\n");
                break;
            }
        }
        //invoke next step
        if(choice != 7)
            nextStep();
    }
    while(choice!=7);
}
void nextStep(){
    int a=0;
    printf("\n----------------------------------------------------------------------------\n");
    printf("Press 1 to return to main interface\n");
    printf("Press 2 to return to quit\n");
    scanf("%d",&a);
    switch (a) {
        case 1 :{
            system("cls");
            Displaymainmenu();
        }

        case 2 :{
            if(quit() < 0)
                printf("quit() fail.\n");
            exit(0);
        }

        default :{
            printf("The correct option was not detected.\n");
            nextStep();
        }
    }
}

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

int quit(){
    sendReceive("QUIT\n");
    return 0;
}

int login(){
    sendReceive("USER IA_pop3_client\n");
    memset(rcvBuff,0,sizeof(rcvBuff));
    sendReceive("PASS NHRIWKBTQGCWGIUB\n");
    return 0;
}

int downloadDelete(char *i){
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
    return 0;
}

int displayBySubjects(){
    printf("This is displayBySubjects.\n");
    return 0;
}

int search(){
    printf("This is search.\n");
    return 0;
}

int getMailDetail(char *i){
    char str[100]="RETR ";
    strcat(str, i);
    sendReceive(str);
    return 0;
}

int getMailStatus(){
    sendReceive("STAT\n");
    return 0;
}

int getList(){
    sendReceive("LIST\n");
    return 0;
}

int reset(){
    sendReceive("RSET\n");
}

int readFlie(char* fliename){
    if((fd = open(fliename,O_RDONLY,0))==-1)
        return -1;

    int i = read(fd,fileBuff,sizeof(fileBuff));
    close(fd);
    return i;
}
