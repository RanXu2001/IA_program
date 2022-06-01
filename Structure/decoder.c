//
// Created by 16003 on 2022/5/31.
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

int fd;
char fileBuff[20000];
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
int readFile(char* fliename){
    if((fd = open(fliename,O_RDONLY,0))==-1)
        return -1;

    int i = read(fd,fileBuff,sizeof(fileBuff));
    close(fd);
    return i;
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

int countFiles(){
    int fileCount=0;
    struct dirent *p;
    //打开指定的文件夹
    DIR *dirp=opendir("./");
    if(dirp==NULL){
        perror("opendir");
        return 1;
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

int selectAllemlforDetials(){
    int hasCount=0;
    struct dirent *p;
    char result[200] = "VGhpcyBpcyB0ZXN0MSwgdGhlIHBsYWluIHRleHQgbWFpbC4=";
    char *content;
    char search[2000];
    printf("Please in put the text you want to search:\n");
    scanf("%s",search);
    //打开指定的文件夹
    DIR *dirp=opendir("./");
    if(dirp==NULL){
        perror("opendir");
        return 1;
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
int main(){
    char result[20000]="VGhpcyBpcyBhbiBlbWFpbCB3aXRoIGh0bWwuPGRpdj48YSBocmVmPSJodHRwczovL21haWwu\n"
                       "YnVwdC5lZHUuY24vY2dpLWJpbi9mcmFtZV9odG1sP3NpZD1JNGk3dl9mNE5kaFBHalpVLDIm\n"
                       "YW1wO3NpZ25fdHlwZT0mYW1wO3I9MjRkYWI1MzZmN2I5MjQzOGYyMTQ5Yzc4YWUyYjY2MTMi\n"
                       "Pmh0bWw8L2E+PC9kaXY+";
    printf("%s\n",base64_decode(result));
    //selectAllemlforDetials();
    return 0;
}