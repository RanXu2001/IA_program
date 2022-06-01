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
int main(){
    char result[200]="VGhpcyBpcyB0ZXN0MSwgdGhlIHBsYWluIHRleHQgbWFpbC4=";
    printf("%s\n",base64_decode(result));
    return 0;
}