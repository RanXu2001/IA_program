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
#include <dirent.h>
#include <termios.h>

#define FILE_MODE 0777
#define IP_LEN	64
FILE *f1;
int fd;
int sock;
const char* USERNAME = "IA_pop3_client";
const char* PASSWORD = "111111";

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


void Displaymainmenu();//显示主菜单
void loginToSystem();
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
int findsubject(char*);
int is_in(char *,char *);
int selectAllemlForTarget();
int countFiles();
unsigned char *base64_decode(unsigned char *code);
int main()
{
    //TCP链接
    loginToSystem();
    connectToServer();
    rcvFromServer();
    printf("%s",rcvBuff);
    memset(rcvBuff,0,sizeof(rcvBuff));
    //login
    switch (login())
    {
        case 0:
            printf("nothing returned from server\n");
            memset(rcvBuff,0,sizeof(rcvBuff));
            exit(0);

        case -1:
            printf("receive error\n");
            memset(rcvBuff,0,sizeof(rcvBuff));
            exit(0);

        case 1:
            printf("successfully login!\n");
            printf("%s",rcvBuff);
            break;

        case 2:
            printf("return error\n");
            memset(rcvBuff,0,sizeof(rcvBuff));
            exit(0);

        default:
            memset(rcvBuff,0,sizeof(rcvBuff));
            exit(0);
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
        printf("mypop >");
        scanf("%d",&choice);
        switch(choice) {
            case 1:{
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
                break;
            }

            case 2:{
                switch(getMailStatus()){
                    case -1:
                        printf("receive error\n");
                        break;
                    case 0:
                        printf("nothing returned from server\n");
                        break;
                    case 1:
                        printf("%s",rcvBuff);
                        break;
                    case 2:
                        printf("input parameter fault\n");
                        break;
                }
                memset(rcvBuff,0,sizeof(rcvBuff));
                break;
            }

            case 3:{
                char* input = NULL;
                printf("Please select the mail number you want to view:\n");
                printf("mypop >");
                scanf("%s", input);
                if(getMailDetail(input) < 0)
                    printf("getMailDetail() fail.\n");
                memset(rcvBuff,0,sizeof(rcvBuff));
                break;
            }

            case 4:{
                if(search() < 0)
                    printf("search() fail.\n");
                memset(rcvBuff,0,sizeof(rcvBuff));
                break;
            }

            case 5:{
                if(displayBySubjects() < 0)
                    printf("displayBySubjects() fail.\n");
                memset(rcvBuff,0,sizeof(rcvBuff));
                break;
            }

            case 6:{
                char* input = NULL;
                printf("Please select the mail number you want to download:\n");
                printf("mypop >");
                scanf("%s",input);
                if(downloadDelete(input) < 0)
                    printf("downloadDelete() fail.\n");
                memset(rcvBuff,0,sizeof(rcvBuff));
                break;
            }

            case 7:{
                if(quit() < 0)
                    printf("quit() fail.\n");
                memset(rcvBuff,0,sizeof(rcvBuff));
                exit(0);
            }

            default:{//仅限数字
                printf("The correct option was not detected.\n");
                memset(rcvBuff,0,sizeof(rcvBuff));
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
    printf("mypop >");
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
    printf("mypop >");
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
void loginToSystem(){
    char username[30];
    // int i = 0;
    struct termios old,new;
    tcgetattr(0,&old);
    new = old;
    new.c_lflag &= ~(ECHO|ICANON);

    char passwd_stdin[20]={0};
    char passwd_true[]="111111";
    char ch;
    int i=0;




    printf("Please enter your username:\n");
    printf("mypop >");
    scanf("%s",username);
    printf("Please enter your password:");
    while(1)
    {
        tcsetattr(0, TCSANOW, &new);//进入循环将stdin设置为不回显状态
        printf("mypop >");
        scanf("%c",&ch);//在不回显状态下输入密码
        tcsetattr(0, TCSANOW, &old);//每次输入一个密码的字符就恢复正常回显状态
        if(i==20 || ch == '\n')//输入回车符表示密码输入完毕，退出循环；或者超出密码长度退出循环
            break;
        passwd_stdin[i] = ch;//将输入的单个字符依次存入数组中

        printf("*");//在回显状态下输出*
        i++;
    }



    if(strcmp(username,USERNAME)&&strcmp(passwd_stdin,passwd_true)==0){
        printf("Password correct! You can login to mail system!");
    }

    else{
        printf("Your username and password don't match!");
        exit(0);
    }


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
}

int login(){
    sendReceive("USER IA_pop3_client\n");
    memset(rcvBuff,0,sizeof(rcvBuff));
    sendReceive("PASS NHRIWKBTQGCWGIUB\n");
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
    selectAllemlForTarget();
    return 0;
}

int getMailDetail(char *i){
    char str[100]="RETR ";
    strcat(str, i);
    sendReceive(str);
}

int getMailStatus(){
    sendReceive("STAT\n");

}

int getList(){
    sendReceive("LIST\n");

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

int findsubject(char* fliename){
    int len;
    char subject[9]="Subject: ";
    if((f1 = fopen(fliename,"r"))== NULL)
        return -1;

    while(fgets(fileBuff,20000,f1) != NULL)
    {
        len = strlen(fileBuff);
        fileBuff[len-1] = '\0';  /*去掉换行符*/
        if(strncmp(fileBuff,subject,9) == 0){
            //tsub = &fileBuff[9];
            //printf("%s\n",tsub);
            char *data = strstr(fileBuff,subject);
            printf("The %s mail's subject is %s\n",fliename,data+9);
        }
        //printf("%s %d \n",fileBuff,len - 1);
    }
    return 0;
}

int is_in(char *wenben, char *search_word)
{
    int i = 0, j = 0, flag = -1;
    while (i < strlen(wenben) && j < strlen(search_word))
    {
        if (wenben[i] == search_word[j])
        { //如果字符相同则两个字符都增加
            i++;
            j++;
        }
        else
        {
            i = i - j + 1; //主串字符回到比较最开始比较的后一个字符
            j = 0;         //字串字符重新开始
        }
        if (j == strlen(search_word))
        {             //如果匹配成功
            flag = 1; //字串出现
            break;
        }
    }
    return flag;
}

int selectAllemlForTarget(){
    struct dirent *p;
    //打开指定的文件夹
    DIR *dirp=opendir("./");
    if(dirp==NULL){
        perror("opendir");
        return -1;
    }
    //printf("directory open success..\n");
    while((p=readdir(dirp))!=NULL){
        if (is_in(p->d_name, ".eml") == 1) // 调用函数：参数二：比较文本，参数一：原文本
        {
            findsubject(p->d_name);
        }
    }
    //关闭文件夹
    closedir(dirp);
    return 0;
}

int countFiles(){
    int fileCount=0;
    struct dirent *p;
    //打开指定的文件夹
    DIR *dirp=opendir("./");
    if(dirp==NULL){
        perror("opendir");
        return -1;
    }
    //printf("directory open success..\n");
    while((p=readdir(dirp))!=NULL) {
        if (is_in(p->d_name, ".eml") == 1) // 调用函数：参数二：比较文本，参数一：原文本
        {
            fileCount++;
        }
    }
    printf("you have %d mails\n", fileCount);
    closedir(dirp);
    return 0;
}

int search(){
    int hasCount=0;
    struct dirent *p;
    char result[200] = "VGhpcyBpcyB0ZXN0MSwgdGhlIHBsYWluIHRleHQgbWFpbC4=";
    char *content;
    char search[2000];
    printf("Please in put the text you want to search:\n");
    printf("mypop >");
    scanf("%s",search);
    //打开指定的文件夹
    DIR *dirp=opendir("./");
    if(dirp==NULL){
        perror("opendir");
        return -1;
    }
    //printf("directory open success..\n");
    countFiles();
    while((p=readdir(dirp))!=NULL){
        if (is_in(p->d_name, ".eml") == 1) // 调用函数：参数二：比较文本，参数一：原文本
        {
            content = base64_decode(result);
            if(is_in(content,search) == 1){
                hasCount++;
                printf("The mail of %s has the text.\n",p->d_name);
            }
        }
    }
    printf("There is(are) %d mail(s) including the text.\n",hasCount);
    //关闭文件夹
    closedir(dirp);
    return 0;
}
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
