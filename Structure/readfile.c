//
// Created by 16003 on 2022/5/31.
//
#include <stdio.h> /* for printf() and fprintf() */

#include <stdlib.h> /* for atoi() and exit() */
#include <string.h> /* for memset() */
#include <unistd.h> /* for close() */
#include <fcntl.h>
int fd;
char fileBuff[20000];

typedef struct split_str_struct
{
    char *str;
    unsigned short length;
}SPLITSTRUCT;

static  unsigned short StringSplit(char *instr, char *token, SPLITSTRUCT *out_strs)
{
    char *start = instr;
    char *end = NULL;
    int ind = 0;

    if(!instr || !instr[0])
        return -1;

    end = strstr(start, token);
    while(end != NULL) {
        out_strs[ind].str = start;
        out_strs[ind].length = end - start;

        ind ++;
        start = end + strlen(token);
        end = strstr(start, token);
    }
    out_strs[ind].str = start;
    out_strs[ind].length = strlen(start);

    return ind + 1;
}

int readFlie(char* fliename){
    if((fd = open(fliename,O_RDONLY,0))==-1)
        return -1;

    int i = read(fd,fileBuff,sizeof(fileBuff));
    close(fd);
    return i;
}

int main(){
    int v= readFlie("em1.eml");
    printf("%s",fileBuff);
    return 0;
}