//
// Created by 16003 on 2022/5/31.
//
#include <stdio.h> /* for printf() and fprintf() */
#include <stdlib.h> /* for atoi() and exit() */
#include <string.h> /* for memset() */
#include <unistd.h> /* for close() */
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>

FILE *f1;
char fileBuff[20000];
char subjectName[20000][20000];




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

int selectAlleml(){
    struct dirent *p;
    //打开指定的文件夹
    DIR *dirp=opendir("/.");
    if(dirp==NULL){
        perror("opendir");
        return 1;
    }
    printf("directory open success..\n");
    while((p=readdir(dirp))!=NULL){
        printf("%s\t%lu\n",\
			p->d_name,p->d_ino);

    }
    //关闭文件夹
    closedir(dirp);
    return 0;
}

int main(){
    int v= findsubject("em1.eml");
    printf(v);
    return 0;
}