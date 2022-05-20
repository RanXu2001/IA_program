//
// Created by 16003 on 2022/5/19.
//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <time.h>


struct Email{

};

void Displaymainmenu();//显示主菜单
int getList();//Get a list of messages and sizes  success:0,fail:-1
int getMailStatus();//Get mail status             success:0,fail:-1
int displayDetail();//Display mail in detail      success:0,fail:-1
int search();//Search text in all mails           success:0,fail:-1
int displayBySubjects();//Display by subjects     success:0,fail:-1
int downloadDelete();//Download the mail and delete in the remote service          success:0,fail:-1
int quit();//Quit                                 success:0,fail:-1
void nextStep();//show next step
int login();//get in the pop.163.com              success:0,fail:-1

//我认为需要的
struct Email decoder(char[100]); //输入相对路径解码Email文件

int main()
{
    //TCP链接

    //login
    if(login() < 0)
        printf("login() fail.\n");
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
                if(displayDetail() < 0)
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

int quit(){
    printf("This is quite.\n");
    return 0;
}

int login(){
    printf("This is login.\n");
    return 0;
}

int downloadDelete(){
    printf("This is downloadDelete.\n");
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

int displayDetail(){
    printf("This is displayDetail.\n");
    return 0;
}

int getMailStatus(){
    printf("This is getMailStatus.\n");
    return 0;
}

int getList(){
    printf("This is getList.\n");
    return 0;
}

struct Email decoder(char[100]){

}
