//
// Created by 16003 on 2022/5/19.
//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <time.h>



void Displaymainmenu();//显示主菜单

int main()
{
    int a;
    //开始界面功能
    do
    {
        Displaymainmenu();
        scanf("%d",&a);
        switch(a) {
            case 1:{
                system ("cls");
                break;
            }

            case 2:{
                system ("cls");
                break;
            }

            case 0:{
                system ("cls");
                break;
            }

            default:{
                system ("cls");
                break;
            }
        }
    }
    while(a!=0);
    return 0;
}
void Displaymainmenu()//显示主菜单
{
    printf("--------------------------------------------------------------------------\n\n");
    printf("                              请输入选项编号（0~2）                       \n\n");
    printf("--------------------------------------------------------------------------\n\n");
    printf("                                图书管理系统                              \n\n\n");
    printf("                         1 ——以学生身份登录                     		  \n\n");
    printf("                         2 ——以图书管理员身份登录                       \n\n");
    printf("                         0 ——退出                                	      \n\n");
    printf("               版权@2020北京邮电大学**国际学院**电信工程及管理            \n");
    printf("--------------------------------------------------------------------------\n");
    printf("请选择您想使用的功能：\n");
}