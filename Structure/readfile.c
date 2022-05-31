//
// Created by 16003 on 2022/5/31.
//
#include <stdio.h> /* for printf() and fprintf() */
#include <stdlib.h> /* for atoi() and exit() */
#include <string.h> /* for memset() */
#include <unistd.h> /* for close() */
#include <fcntl.h>
#include <dirent.h>

FILE *f1;
char fileBuff[20000];





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
            printf("The %s Mail's %s\n",fliename,data+9);
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

int selectAlleml(){
    struct dirent *p;
    //打开指定的文件夹
    DIR *dirp=opendir("./");
    if(dirp==NULL){
        perror("opendir");
        return 1;
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

int main(){
    //int v= findsubject("em1.eml");
    //printf(v);
    selectAlleml();
    return 0;
}