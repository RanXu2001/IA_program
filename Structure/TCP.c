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

int readFile(char* fliename){
    if((fd = open(fliename,O_RDONLY,0))==-1)
        return -1;

    int i = read(fd,fileBuff,sizeof(fileBuff));
    close(fd);
    return i;
}
// int decodeMail(char* mailName){//Use lseek to locate "Content-Transfer-Encoding: base64"
//     char encodedContent[20000];
//     const char* base64Head = "Content-Transfer-Encoding: base64\n";
//     char tempBuff[sizeof(base64Head)];
//     const char* contentEndMark = "--";
//     char tempEndBuff[sizeof(contentEndMark)];
//     memset(tempEndBuff,0,sizeof(tempEndBuff));
//     memset(tempBuff,0,sizeof(tempBuff));

//     int fd;
//     if((fd = open(mailName,O_RDONLY,0))==-1)
//         return -1;
//     int i = read(fd,fileBuff,sizeof(fileBuff));
//     close(fd);

//     for(int i = 0; i<strlen(fileBuff);i++){
//         lseek(fd,i,SEEK_CUR);
//         read(fd,tempBuff,sizeof(base64Head));
//         if(strcmp(base64Head,tempBuff)==0){
//             lseek(fd,strlen(base64Head),SEEK_CUR);

//             for(i;i<strlen(fileBuff);i++){
//                 lseek(fd,i,SEEK_CUR);
//                 read(fd,tempEndBuff,sizeof(contentEndMark));
//                 if(strcmp(contentEndMark, tempEndBuff)==0){

//                 }
//             }
//             break;
//         }

//         else{
//             memset(tempBuff,0,sizeof(tempBuff));
//         }

//     }

//     read(fd,encodedContent,50);
// }
unsigned char *base64_decode(unsigned char *code)
{
//根据base64表，以字符找到对应的十进制数据
    int table[]={0,0,0,0,0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,62,0,0,0,
                 63,52,53,54,55,56,57,58,
                 59,60,61,0,0,0,0,0,0,0,0,
                 1,2,3,4,5,6,7,8,9,10,11,12,
                 13,14,15,16,17,18,19,20,21,
                 22,23,24,25,0,0,0,0,0,0,26,
                 27,28,29,30,31,32,33,34,35,
                 36,37,38,39,40,41,42,43,44,
                 45,46,47,48,49,50,51
    };
    long len;
    long str_len;
    unsigned char *res;
    int i,j;

//计算解码后的字符串长度
    len=strlen(code);
//判断编码后的字符串后是否有=
    if(strstr(code,"=="))
        str_len=len/4*3-2;
    else if(strstr(code,"="))
        str_len=len/4*3-1;
    else
        str_len=len/4*3;

    res=malloc(sizeof(unsigned char)*str_len+1);
    res[str_len]='\0';

//以4个字符为一位进行解码
    for(i=0,j=0;i < len-2;j+=3,i+=4)
    {
        res[j]=((unsigned char)table[code[i]])<<2 | (((unsigned char)table[code[i+1]])>>4); //取出第一个字符对应base64表的十进制数的前6位与第二个字符对应base64表的十进制数的后2位进行组合
        res[j+1]=(((unsigned char)table[code[i+1]])<<4) | (((unsigned char)table[code[i+2]])>>2); //取出第二个字符对应base64表的十进制数的后4位与第三个字符对应bas464表的十进制数的后4位进行组合
        res[j+2]=(((unsigned char)table[code[i+2]])<<6) | ((unsigned char)table[code[i+3]]); //取出第三个字符对应base64表的十进制数的后2位与第4个字符进行组合
    }

    return res;

}

void decodeMailFile(char* mailName){
    const char* base64Head = "Content-Transfer-Encoding: base64";
    unsigned char content[20000];
    char *decodedContent;
    readFile(mailName);
    char *currentMail;
    char *endOfCurrentMail;
    currentMail = fileBuff;
    currentMail = strstr(currentMail,base64Head);
    currentMail = strstr(currentMail,"\n");
    // p1=p3;

    if(currentMail[0]=='\n'){
        memmove(currentMail, currentMail+1, strlen(currentMail));
    }
    endOfCurrentMail = strstr(currentMail,"\n");

    memcpy(content,currentMail,(strchr(currentMail,'-')-currentMail-1));
    // for(;*currentMail!='\n';*currentMail++,*p2++){
    //     *p2 = *currentMail;
    // }
    // printf("%s",content);
    unsigned char*str = content;
    if(str[0]=='\n'){
        memmove(str, str+1, strlen(str));
    }
    printf("%s",str);
    decodedContent = base64_decode(str);
    printf("%s",decodedContent);






}

int main(){
    decodeMailFile("test.eml");

    // connectToServer();
    // rcvFromServer();
    // printf("%s",rcvBuff);
    // memset(rcvBuff,0,sizeof(rcvBuff));
    // switch (login())
    // {
    // case 0:
    //     printf("nothing returned from server\n");
    //     break;

    // case -1:
    //     printf("receive error\n");
    //     break;

    // case 1:
    //     printf("successfully login!\n");
    //     printf("%s",rcvBuff);
    //     break;

    // case 2:
    //     printf("return error\n");
    //     break;

    // default:
    //     break;
    // }
    // memset(rcvBuff,0,sizeof(rcvBuff));






    // memset(rcvBuff,0,sizeof(rcvBuff));

    //     switch (getList())
    //     {
    //     case 0:
    //         printf("nothing returned from server\n");
    //         break;

    //     case -1:
    //         printf("receive error\n");
    //         break;

    //     case 1:
    //         printf("%s",rcvBuff);
    //         break;

    // }
    //     memset(rcvBuff,0,sizeof(rcvBuff));

    // int v = readFlie("test.eml");
    // printf("%s",fileBuff);
    // printf("%d bytes are read",v);
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