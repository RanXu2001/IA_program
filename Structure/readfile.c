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
char subjectName[20000][20000];

int findsubject(char* fliename,char value[1024]){
    int len;
    char subject[1024]="Subject: ";
    strcat(subject,value);
    char *tsub;
    if((f1 = fopen(fliename,"r"))== NULL)
        return -1;

    while(fgets(fileBuff,20000,f1) != NULL)
    {
        len = strlen(fileBuff);
        fileBuff[len-1] = '\0';  /*去掉换行符*/
        if(strcmp(fileBuff,subject) == 0){
            //tsub = &fileBuff[9];
            //printf("%s\n",tsub);
            //char *data = strstr(fileBuff,subject);
            //printf("%s\n",data+9);
            printf("find it!");
        }
        //printf("%s %d \n",fileBuff,len - 1);
    }
    return 0;
}

int main(){
    int v= findsubject("em2.eml","TEST 1");
    printf(v);
    return 0;
}