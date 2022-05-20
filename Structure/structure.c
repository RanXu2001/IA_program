//
// Created by 16003 on 2022/5/19.
//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <time.h>


struct BOOK
{
    char booknum[10];//图书编号
    char bookname[50];//书名
    char writer[20];//作者
    float price;//价格
    char publisher[50];//出版社
    char publishtime[50];//出版日期
    char bookintroduction[100];//图书简介
    int booksum;//书本总个数
    char booklocation[10];//图书位置
    int lend;//是否被借走：借走了是1；没借走是0
    int borrow;//馆内数目 ////////////////////////////////////存疑
    int lendtimes;//借出次数
};
struct students
{
    char idnumber[11];//学号
    char school[50];//学院
    char major[100];//专业
    char name[10];//姓名
    char gender[5];//性别
    char phonenumber[12];//电话号码
    char password[20];//密码
    char mailbox[20];//邮箱
    int borrow_book_num; //已经外借了几本书
    int if_Frozen;//0正常，1冻结
};
struct teachers
{
    char idnumber_t[11];//工号
    char name_t[10];//姓名
    char password_t[20];//密码
    char mailbox_t[20];//邮箱
};
struct buffer
{
    char idnumber_[11];//购物车学号
    char booknumber[7];//购物车书号
};
struct BorrowInfo
{
    char borrow_booknum[10];//借走的书的编号
    char borrow_bookname[100];//借走的书的名字
    int borrow_year;//借走年份
    int borrow_month;//借走月份
    int borrow_day;//借走日
    int borrow_hour;//借走时
    int borrow_minute;//借走分钟
    int return_year;//还书年份
    int return_month;//还书月份
    int return_day;//还书日
    int return_hour;//还书时
    int return_minute;//还书分
    int renew_num;//续借次数
    char borrow_student_idnum[20];//借走书的学生的学号
    char borrow_student_name[10];//借走书的学生的姓名
};

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

            }

            case 2:{}

            case 0:{}

            default:{}
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

void Displaystudentmenu()//显示学生菜单
{
    printf("--------------------------------------------------------------------------\n\n");
    printf("                              请输入选项编号（0~8）                       \n\n");
    printf("--------------------------------------------------------------------------\n\n");
    printf("                                学生端功能                                \n\n\n");
    printf("                         1 ——借书             	 	 				  \n\n");
    printf("                         2 ——续借                     				  \n\n");
    printf("                         3 ——查询图书                					  \n\n");
    printf("                         4 ——查询借阅结果                               \n\n");
    printf("                         5 ——删除借阅信息                               \n\n");
    printf("                         6 ——个人信息管理                               \n\n");
    printf("                         7 ——还书             	 	 				  \n\n");
    printf("                         8 ——返回上一级                                 \n\n");
    printf("                         0 ——退出             	 	 				  \n\n");
    printf("--------------------------------------------------------------------------\n");
    printf("请选择：");
}
void Displayteachermenu()//显示教师菜单
{
    printf("--------------------------------------------------------------------------\n\n");
    printf("                          请输入选项编号（0~6）                           \n\n");
    printf("--------------------------------------------------------------------------\n\n");
    printf("                            图书管理员端功能                              \n\n\n");
    printf("                         1 ——图书管理             	 	 			  \n\n");
    printf("                         2 ——删除图书                     			  \n\n");
    printf("                         3 ——借阅管理                					  \n\n");
    printf("                         4 ——统计借阅信息                               \n\n");
    printf("                         5 ——个人信息管理                               \n\n");
    printf("                         6 ——返回上一级                                 \n\n");
    printf("                         0 ——退出                                       \n\n");
    printf("--------------------------------------------------------------------------\n");
    printf("请选择：");
}
void Displayborrowmenu()//显示借书菜单
{
    printf("--------------------------------------------------------------------------\n\n");
    printf("                          请输入选项编号（1~3）                           \n\n");
    printf("--------------------------------------------------------------------------\n\n");
    printf("                            借阅图书功能                   	              \n\n\n");
    printf("                         1 ——选书放入购物车          	 	 			  \n\n");
    printf("                         2 ——查看购物车                     			  \n\n");
    printf("                         3 ——返回上一级              					  \n\n");
    printf("--------------------------------------------------------------------------\n");
    printf("请选择：");
}
void DisplayBOOKMANAGEmenu()//显示图书管理菜单
{
    printf("--------------------------------------------------------------------------\n\n");
    printf("                          请输入选项编号（1~4）                           \n\n");
    printf("--------------------------------------------------------------------------\n\n");
    printf("                            图书管理功能                   	              \n\n\n");
    printf("                         1 ——图书查询             	 	 			  \n\n");
    printf("                         2 ——添加图书                     			  \n\n");
    printf("                         3 ——修改图书             					  \n\n");
    printf("                         4 ——返回上一级             					  \n\n");
    printf("--------------------------------------------------------------------------\n");
    printf("请选择：");
}
void DisplayBOOKsearchmenu()//显示图书查询菜单
{
    printf("--------------------------------------------------------------------------\n\n");
    printf("                          请输入选项编号（1~3）                           \n\n");
    printf("--------------------------------------------------------------------------\n\n");
    printf("                            查询图书功能                   	              \n\n\n");
    printf("                         1 ——根据书名查询          	 	 			  \n\n");
    printf("                         2 ——根据出版社查询                  			  \n\n");
    printf("                         3 ——返回上一级              					  \n\n");
    printf("--------------------------------------------------------------------------\n");
    printf("请选择：");
}
void Display_student_book_searchmenu()//显示学生图书查询菜单
{
    printf("--------------------------------------------------------------------------\n\n");
    printf("                          请输入选项编号（1~5）                           \n\n");
    printf("--------------------------------------------------------------------------\n\n");
    printf("                            图书查询功能                   	              \n\n\n");
    printf("                         1 ——根据书名查询            	 	 			  \n\n");
    printf("                         2 ——根据作者查询                    			  \n\n");
    printf("                         3 ——根据借阅次数查询        					  \n\n");
    printf("                         4 ——根据价格排序书目       					  \n\n");;
    printf("                         5 ——返回上一级             					  \n\n");
    printf("--------------------------------------------------------------------------\n");
    printf("请选择：");
}
void Display_loan_management() //显示借阅管理菜单
{
    printf("--------------------------------------------------------------------------\n\n");
    printf("                             请输入选项编号（1~3）                        \n\n");
    printf("--------------------------------------------------------------------------\n\n");
    printf("                            借阅管理功能                   	              \n\n\n");
    printf("                          1 ——查看借阅情况                     	      \n\n");
    printf("                          2 ——借阅账户管理                              \n\n");
    printf("                          3——返回上一级             					  \n\n");
    printf("--------------------------------------------------------------------------\n");
    printf("请输入：");
}
void Display_check_borrowing_status()//显示检查借阅情况菜单
{
    printf("--------------------------------------------------------------------------\n\n");
    printf("                             请输入选项编号（1~5）                        \n\n");
    printf("--------------------------------------------------------------------------\n\n");
    printf("                          1 ——查询所有图书的借阅情况                    \n\n");
    printf("                          2 ——查询借阅图书的学生信息                    \n\n");
    printf("                          3 ——查询超期未还图书情况                      \n\n");
    printf("                          4 ——查询超期未还学生名单                      \n\n");
    printf("                          5 ——返回上级菜单                              \n\n");
    printf("--------------------------------------------------------------------------\n");
    printf("请输入：");
}
void Display_loan_account_management()//显示借阅账户管理菜单
{
    printf("--------------------------------------------------------------------------\n\n");
    printf("                             请输入选项编号（1~3）                        \n\n");
    printf("--------------------------------------------------------------------------\n\n");
    printf("                         1 ——冻结有超期未还图书的账户                   \n\n");
    printf("                         2 ——归还图书后解冻账户                         \n\n");
    printf("                         3 ——返回上级菜单                               \n\n");
    printf("--------------------------------------------------------------------------\n");
    printf("请输入：");
}
void Display_tongjijieyuexinxipaixu()//显示统计借阅信息排序菜单
{
    printf("--------------------------------------------------------------------------\n\n");
    printf("                             请输入选项编号（1~4）                        \n\n");
    printf("--------------------------------------------------------------------------\n\n");
    printf("                         1 ——按借阅时间长短排序所有图书                 \n\n");
    printf("                         2 ——按照借阅次数排序所有在馆图书               \n\n");
    printf("                         3 ——按专业统计学生最爱的借阅书目               \n\n");
    printf("                         4 ——返回上级菜单                               \n\n");
    printf("--------------------------------------------------------------------------\n");
    printf("请输入：");
}
int Check_studentid()//学生登录
{
    FILE *fps;
    FILE *fpt;
    char idnumber[10],password[10];
    struct students *ps;
    struct teachers *pt;
    int a=0,b;//a是看有没有这个学生
    printf("请输入学生号：\n");
    scanf("%s",idnumber);
    printf("请输入学生密码【初始密码为学生号】:\n");
    scanf("%s",password);
    fps=fopen("学生信息.txt","a+");
    if(fps==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    ps=(struct students*)malloc(LONGS);
    while(!feof(fps))
    {
        fscanf(fps,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,&ps->borrow_book_num,&ps->if_Frozen);
        if(strcmp(idnumber,ps->idnumber)==0)
        {
            a=1;
            if(ps->if_Frozen==1)///冻结账号
            {
                system("cls");
                printf("您的帐号已经被冻结，请联系图书管理员查询\n");///打印管理员信息 姓名 邮箱
                fpt=fopen("图书管理员信息.txt","a+");
                if(fpt==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
                pt=(struct teachers*)malloc(LONGT);
                while(!feof(fpt))
                {
                    fscanf(fpt,"%s %s %s %s\n",pt->idnumber_t,pt->name_t,pt->password_t,pt->mailbox_t);
                    printf("-------------------------------------------\n\n");
                    printf("       姓名          邮箱\n\n");
                    printf("-------------------------------------------\n\n");
                    printf("       %s             %s\n\n",pt->name_t,pt->mailbox_t);
                }
                fclose(fpt);
                fclose(fps);
                system("pause");
                system("cls");
                return 0;

            }
            else
            {
                if(strcmp(password,ps->password)==0)
                {
                    system("cls");
                    printf("登陆成功，欢迎使用%s\n",ps->name);
                    strcpy(STUDENTID,idnumber);
                    fclose(fps);
                    return 1;
                }
                else
                {
                    system("cls");
                    printf("密码错误\n");
                    fclose(fps);
                    return 0;
                }
            }
        }
    }
    fclose(fps);
    if(a==0)
    {
        int aa=0;
        fclose(fps);
        system("cls");
        printf("未能找到您的学生号\n"); //////注册
        printf("是否注册帐号1\n1)注册\n2)不注册\n");
        scanf("%d",&aa);
        if(aa==1)
        {
            student_enrolment();
            return 0;
        }
        else
            return 0;
    }
    else
    {
        fclose(fps);
        return 1;
    }
    fclose(fps);
}
int Check_teacherid()//图书管理员登录
{
    FILE *fpt;
    char idnumber_t[10],password_t[10];
    struct teachers *pt;
    int a=0;//a是看有没有这个老师
    printf("请输入工号：\n");
    scanf("%s",idnumber_t);
    printf("请输入图书管理员密码【初始密码为工号】:\n");
    scanf("%s",password_t);
    fpt=fopen("图书管理员信息.txt","a+");
    if(fpt==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    pt=(struct teachers*)malloc(LONGT);
    while(!feof(fpt))
    {
        fscanf(fpt,"%s %s %s %s\n",pt->idnumber_t,pt->name_t,pt->password_t,pt->mailbox_t);
        if(strcmp(idnumber_t,pt->idnumber_t)==0)
        {
            a=1;
            if(strcmp(password_t,pt->password_t)==0)
            {
                system("cls");
                printf("登陆成功，欢迎使用%s\n",pt->name_t);
                strcpy(TEACHERID,idnumber_t);
                fclose(fpt);
                return 1;
            }
            else
            {
                system("cls");
                printf("密码错误\n");
                fclose(fpt);
                return 0;
            }
        }
    }
    if(a==0)
    {
        int aa=0;
        fclose(fpt);
        system("cls");
        printf("未能找到您的工号\n"); //注册
        printf("是否注册帐号1\n1)注册\n2)不注册\n");
        scanf("%d",&aa);
        if(aa==1)
        {
            teacher_enrolment();
            return 0;
        }
        else
            return 0;
    }
    else
    {
        fclose(fpt);
        return 1;
    }
}
void BORROW(char ID[20])//借书
{
    int a;
    do
    {
        Displayborrowmenu();
        scanf("%d",&a);
        system("cls");
        switch(a)
        {
            case 1://选书放入购物车
            {
                if(borrow_buffer(ID)==0)
                {
                    printf("请重新选择\n");
                    break;
                }
            }
            case 2://查看购物车
            {
                if(borrow_borrow(ID)==0)
                {
                    printf("请重新选择\n");
                    break;
                }
            }
            case 3://返回上一级
            {
                system("cls");
                break;
            }
            default://容错
            {
                system("cls");
                printf("\n\n您的输入错误，请重新选择\n\n");
                break;
            }
        }
    }
    while(a!=3);
}
int borrow_buffer(char Id[20])//借书_购物车
{
    FILE *fp,*fps,*fpbuffer;
    char bookname[50],booknum[50],idnumber[50],date[50];
    struct BOOK *p;
    struct students *ps;
    struct buffer *pbuffer;
    int a,as,ab,b,c,d,e,f,count;//a看有没有这本书,as看有没有这个学生,ab看有没有这个编号
    do
    {
        a=0;as=0;ab=0;b=0;c=0;d=0;e=0;f=0;count=0;
        printf("--------------------------------------------------------------------------\n");
        printf("                              欢迎使用购物车                              \n");
        printf("                          					                              \n");
        printf("                         请输入你想借阅的书籍名称                         \n");
        printf("--------------------------------------------------------------------------\n");
        printf("请输入书名：");
        scanf("%s",bookname);
        fp=fopen("图书基本信息.txt","r");
        if(fp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
        p=(struct BOOK*)malloc(LONG);
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
            if(strcmp(bookname,p->bookname)==0)
            {
                a=1;
                if(p->lend==0)
                {
                    printf("=================================================\n");
                    printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","编号：",p->booknum,"书名：",p->bookname,"单价：",p->price);
                    printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","作者：",p->writer,"出版社：",p->publisher,"出版时间:",p->publishtime);
                    printf("%-8s%s\n\n\n\n","图书位置：",p->booklocation);
                    count=1;
                }
            }
        }
        fclose(fp);
        if(a==0)
        {
            system("cls");
            printf("\a\n 未找到与条件相符的图书,请您重新查找 \n\n");
            printf("=====================================================================\n");
            printf("			是否继续查找其他书籍             \n");
            printf("		【1】继续查找		【2】返回上一级      \n");
            printf("=====================================================================\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1:
                {
                    system("cls");
                    continue;
                }
                case 2:
                {
                    system("cls");
                    return 0;
                    break;
                }
                default://容错
                {
                    system("cls");
                    printf("\n\n您的输入错误，请重新选择\n\n");
                    break;
                }
            }
        }
        if(count==0)
        {
            printf("十分抱歉，该书已被全部借出，不可借阅\n");
            printf("=====================================================================\n");
            printf("			是否继续查找其他书籍             \n");
            printf("		【1】继续查找		【2】返回上一级      \n");
            printf("=====================================================================\n");
            scanf("%d",&b);
            switch(b)
            {
                case 1:
                {
                    system("cls");
                    continue;
                }
                case 2:
                {
                    system("cls");
                    return 0;
                    break;
                }
                default://容错
                {
                    system("cls");
                    printf("\n\n您的输入错误，请重新选择\n\n");
                    break;
                }
            }
        }
        if(count==1)//正式借取
        {
            do
            {
                printf("=====================================================================\n");
                printf("                  请输入图书编号将该书放入购物车             \n");
                printf("=====================================================================\n");
                scanf("%s",booknum);
                fp=fopen("图书基本信息.txt","r");
                if(fp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
                while(!feof(fp))
                {
                    fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
                    if(strcmp(booknum,p->booknum)==0)
                        ab=1;
                }
                fclose(fp);
                if(ab==0)
                {
                    printf("\n图书编号输入错误！请重新输入\n");
                    d=1;
                }
                else
                {
                    do
                    {
                        fps=fopen("学生信息.txt","r");
                        if(fps==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
                        ps=(struct students*)malloc(LONGS);
                        while(!feof(fps))
                        {
                            fscanf(fps,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,&ps->borrow_book_num,&ps->if_Frozen);
                            if(strcmp(Id,ps->idnumber)==0) //查看该同学借了几本书
                                as=1;
                        }
                        fclose(fps);
                        if(as==0)
                        {
                            printf("\n输入错误！请重新输入\n");
                            e=1;
                        }
                        else//录入
                        {
                            fpbuffer=fopen("购物车.txt","a+");
                            if(fpbuffer==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
                            pbuffer=(struct buffer*)malloc(LONGBUFFER);
                            strcpy(pbuffer->idnumber_,Id);
                            strcpy(pbuffer->booknumber,booknum);
                            fprintf(fpbuffer,"%s %s\n",pbuffer->idnumber_,pbuffer->booknumber);
                            fflush(fpbuffer);
                            fclose(fpbuffer);
                            borrow_buffer_change_lend(booknum);//lend变成1
                            printf("成功加入购物车\n");
                            printf("=====================================================================\n");
                            printf("			是否继续查找其他书籍             \n");
                            printf("		【1】继续查找		【2】返回上一级      \n");
                            printf("=====================================================================\n");
                            scanf("%d",&f);
                            switch(f)
                            {
                                case 1:
                                {
                                    system("cls");
                                    fclose(fps);
                                    continue;
                                }
                                case 2:
                                {
                                    system("cls");
                                    fclose(fps);
                                    return 0;
                                }
                                default://容错
                                {
                                    system("cls");
                                    fclose(fps);
                                    printf("\n\n您的输入错误，请重新选择\n\n");
                                    break;
                                }
                            }
                        }
                    }while(e!=0);
                }
            }while(d!=0);
        }
    }while(c!=2);
    fclose(fps);
}
int borrow_borrow(char Id[20])//借书_正式借出_ 更改图书被借次数
{
    FILE *fp,*fps,*fpbuffer,*fpborrow;
    char bookname[50],booknum[50],idnumber[50];
    struct BOOK *p;
    struct students *ps;
    struct buffer *pbuffer;
    struct BorrowInfo *pborrow;
    int a=0,b,c=0,d,e,f=0,count;//a看有没有购物车信息
    do
    {
        a=0;c=0;d=0;f=0;e=0;count=0;
        printf("--------------------------------------------------------------------------\n");
        printf("                              欢迎查看购物车                              \n");
        printf("                          					                              \n");
        printf("--------------------------------------------------------------------------\n");
        fpbuffer=fopen("购物车.txt","a+");
        if(fpbuffer==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
        pbuffer=(struct buffer*)malloc(LONGBUFFER);
        while(!feof(fpbuffer))
        {
            fscanf(fpbuffer,"%s %s\n",pbuffer->idnumber_,pbuffer->booknumber);
            if(strcmp(Id,pbuffer->idnumber_)==0)
            {
                a=1;//有购物车信息
                fp=fopen("图书基本信息.txt","r");
                if(fp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
                p=(struct BOOK*)malloc(LONG);
                while(!feof(fp))
                {
                    fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
                    if(strcmp(pbuffer->booknumber,p->booknum)==0)
                    {
                        strcpy(bookname,p->bookname);
                    }
                }
                fclose(fp);
                printf("\n=====================================================================\n");
                printf("\n	学生号         图书编号            书本名称\n");
                printf("\n---------------------------------------------------------------------\n");
                printf("\n	%-10s	%-12s%12s\n\n",Id,pbuffer->booknumber,bookname);
                printf("\n---------------------------------------------------------------------\n\n");
            }
        }
        fclose(fpbuffer);
        if(a==0)//没有该学生购物信息
        {
            system("cls");
            printf("\a\n 未找到该学生的购物车信息,请您重新查找 \n\n");
            printf("\n=====================================================================\n");
            printf("			【1】返回上一级      \n");
            printf("=====================================================================\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1:
                {
                    system("cls");
                    return 0;
                    break;
                }
                default://容错
                {
                    system("cls");
                    fclose(fps);
                    printf("\n\n您的输入错误，请重新选择\n\n");
                    break;
                }
            }
        }
        else//询问是否正式借出
        {
            do
            {
                printf("\n\n=====================================================================\n");
                printf("				是否借出图书             \n");
                printf("			【1】是		【2】否      \n");
                printf("=====================================================================\n");
                scanf("%d",&d);
                switch(d)
                {
                    case 1:
                    {
                        count++;
                        break;
                    }
                    case 2:
                    {
                        system("cls");
                        return 0;
                        break;
                    }
                    default://容错
                    {
                        system("cls");
                        printf("\n\n您的输入错误，请重新选择\n\n");
                        break;
                    }
                }
                do//查看该学生是否满足借书条件 （3本，？超时？）
                {
                    printf("请输入想借出的图书的图书编号：\n");
                    scanf("%s",booknum);
                    if(count>=3)//已经一次性借了三本
                    {
                        e=1;
                        system("cls");
                        printf("\n本馆只允许学生一次性最多借阅三本，您已达到上限\n");
                        return 0;
                    }
                    else
                    {
                        fps=fopen("学生信息.txt","r");
                        if(fps==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
                        ps=(struct students*)malloc(LONGS);
                        while(!feof(fps))//如果自己手里已经达到上限
                        {
                            fscanf(fps,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,&ps->borrow_book_num,&ps->if_Frozen);
                            if(strcmp(Id,ps->idnumber)==0)
                            {
                                if(ps->borrow_book_num>=3)
                                {
                                    fclose(fps);
                                    e=1;
                                    system("cls");
                                    printf("\n本馆只允许学生最多外借三本图书，您已达到上限\n");
                                    return 0;
                                }
                                else//判断是否存在超时
                                {
                                    if(borrowtime(Id)==0)
                                    {
                                        fclose(fps);
                                        e=1;
                                        system("cls");
                                        printf("\n您有书需要续借，请去学生主界面办理续借\n");
                                        return 0;
                                    }
                                    else////合格用户 办理借书 (剔除购物车里的信息，加入到借阅信息文件里，记录当前时间)
                                    {
                                        fclose(fps);
                                        borrow_borrow_load(Id,booknum);
                                        printf("成功办理借书祝您阅读愉快\n\n");
                                        printf("=====================================================================\n");
                                        printf("			是否继续借阅其他书籍             \n");
                                        printf("		【1】继续查找		【2】返回上一级      \n");
                                        printf("=====================================================================\n");
                                        scanf("%d",&f);
                                        switch(f)
                                        {
                                            case 1:
                                            {
                                                system("cls");
                                                d=2;
                                                e=0;
                                                break;
                                            }
                                            case 2:
                                            {
                                                system("cls");
                                                return 0;
                                                break;
                                            }
                                            default://容错
                                            {
                                                system("cls");
                                                printf("\n\n您的输入错误，请重新选择\n\n");
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        fclose(fps);
                    }
                }while(e!=0);
                fclose(fps);
            }while(d!=2);
        }
    }while(c!=1);
    fclose(fps);
}
void borrow_borrow_load(char idnum[50],char booknumber[50])//借书_正式借出_更改文件信息
{
    FILE *fp,*fps,*fpbuffer,*fpborrow;
    char bookname[50],name[50];
    int a,b,i=0,j=0;
    struct BOOK *p;
    struct students *ps;
    struct buffer *pbuffer;
    struct BorrowInfo *pborrow;
    fp=fopen("图书基本信息.txt","r");//提取书名以及学生姓名	///书名
    if(fp==NULL){printf("1数据库打开错误！请检查……\n");exit(0);}
    p=(struct BOOK*)malloc(LONG);
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
        if(a!=1&&strcmp(booknumber,p->booknum)==0)
        {
            a=1;
            strcpy(bookname,p->bookname);
        }
    }
    fclose(fp);
    fps=fopen("学生信息.txt","r");	///学生姓名
    if(fps==NULL){printf("2数据库打开错误！请检查……\n");exit(0);}
    ps=(struct students*)malloc(LONGS);
    while(!feof(fps))
    {
        fscanf(fps,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,&ps->borrow_book_num,&ps->if_Frozen);
        if(b!=1&&strcmp(idnum,ps->idnumber)==0)
        {
            b=1;
            strcpy(name,ps->name);
        }
    }
    fclose(fps);
    time_t timep;//提取现在时间
    struct tm *ptm;
    time (&timep);
    ptm=gmtime(&timep); 	//录入进借阅信息
    fpborrow=fopen("图书借还信息.txt","a+");
    if(fpborrow==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    pborrow=(struct BorrowInfo*)malloc(LONGBORROW);
    while(!feof(fpborrow))
    {
        fscanf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,&pborrow->borrow_year,&pborrow->borrow_month,&pborrow->borrow_day,&pborrow->borrow_hour,&pborrow->borrow_minute,&pborrow->return_year,&pborrow->return_month,&pborrow->return_day,&pborrow->return_hour,&pborrow->return_minute,&pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
        if(strcmp(booknumber,pborrow->borrow_booknum)==0&&strcmp(idnum,pborrow->borrow_student_idnum)==0&&pborrow->return_year==0)
            pborrow->renew_num++;
        else
            pborrow->renew_num=0;
        strcpy(pborrow->borrow_booknum,booknumber);
        strcpy(pborrow->borrow_bookname,bookname);
        pborrow->borrow_year=ptm->tm_year+1900;
        pborrow->borrow_month=ptm->tm_mon+1;
        pborrow->borrow_day=ptm->tm_mday;
        pborrow->borrow_hour=ptm->tm_hour+8;
        pborrow->borrow_minute=ptm->tm_min;
        pborrow->return_year=0;
        pborrow->return_month=0;
        pborrow->return_day=0;
        pborrow->return_hour=0;
        pborrow->return_minute=0;
        strcpy(pborrow->borrow_student_idnum,idnum);
        strcpy(pborrow->borrow_student_name,name);
    }
    fprintf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,pborrow->borrow_year,pborrow->borrow_month,pborrow->borrow_day,pborrow->borrow_hour,pborrow->borrow_minute,pborrow->return_year,pborrow->return_month,pborrow->return_day,pborrow->return_hour,pborrow->return_minute,pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
    fflush(fpborrow);
    fclose(fpborrow);
    borrow_borrow_change_lendtime(booknumber);//书本被借阅数量+1
    borrow_borrow_delet(idnum,booknumber);	//删除购物车里的信息
    fclose(fps);
    borrow_borrow_change_borrow_book_num(idnum);//学生借书数+1
}
int borrowtime(char idnumber[50])//1 正常 0 有问题
{
    FILE *fpborrow;
    struct BorrowInfo *pborrow;
    int a,resttime,borrow_year,borrow_month,borrow_day,borrow_hour,borrow_minute;
    fpborrow=fopen("图书借还信息.txt","a+");
    if(fpborrow==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    pborrow=(struct BorrowInfo*)malloc(LONGBORROW);
    while(!feof(fpborrow))
    {
        a=1;
        fscanf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,&pborrow->borrow_year,&pborrow->borrow_month,&pborrow->borrow_day,&pborrow->borrow_hour,&pborrow->borrow_minute,&pborrow->return_year,&pborrow->return_month,&pborrow->return_day,&pborrow->return_hour,&pborrow->return_minute,&pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
        if(strcmp(idnumber,pborrow->borrow_student_idnum)==0)//提取借书时间
        {
            borrow_year=pborrow->borrow_year;
            borrow_month=pborrow->borrow_month;
            borrow_day=pborrow->borrow_day;
            borrow_hour=pborrow->borrow_hour;
            borrow_minute=pborrow->borrow_minute;
            a=0;
        }
        if(a==0)
        {
            time_t timep;
            struct tm *ptm;
            time (&timep);
            ptm=gmtime(&timep);
            resttime=((1900+ptm->tm_year-2020)*12*30*24*60+(1+ptm->tm_mon)*30*24*60+ptm->tm_mday*24*60+(8+ptm->tm_hour)*60+ptm->tm_min)-((borrow_year-2020)*12*30*24*60+borrow_month*30*24*60+borrow_day*24*60+borrow_hour*60+borrow_minute);
            if(resttime<43200)
            {
                fclose(fpborrow);
                return 1;//未超期
            }
            else
            {
                fclose(fpborrow);
                return 0;//超期
            }
        }
    }
    fclose(fpborrow);
}
void borrow_borrow_delet(char idnum[50],char booknum[50])//借书_正式借出_删除购物车记录
{
    FILE *fpbuffer,*fpbuffertemp;
    struct buffer *pbuffer;
    fpbuffer=fopen("购物车.txt","r");
    if(fpbuffer==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    fpbuffertemp=fopen("临时购物车.txt","a+");
    if(fpbuffer==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    pbuffer=(struct buffer*)malloc(LONGBUFFER);
    while(!feof(fpbuffer))//studentnum:学生数,recordnum:buffer里的词条数
    {

        fscanf(fpbuffer,"%s %s\n",pbuffer->idnumber_,pbuffer->booknumber);
        if(strcmp(pbuffer->idnumber_,idnum)!=0)//不是我想要的那条
            fprintf(fpbuffertemp,"%s %s\n",pbuffer->idnumber_,pbuffer->booknumber);
        else    //是我想要的那条,继续验证enter的编码号是不是正确，如果不正确，则也输入到临时文件里
        {
            if(strcmp(pbuffer->booknumber,booknum)!=0)
                fprintf(fpbuffertemp,"%s %s\n",pbuffer->idnumber_,pbuffer->booknumber);
        }
    }
    fclose(fpbuffer);fclose(fpbuffertemp);
    system("del 购物车.txt");
    system("rename 临时购物车.txt 购物车.txt");	//将原文件删除，临时文件改成原文件的名字
}
void borrow_buffer_change_lend(char booknumer[50])//借书_购物车_更改图书lend（借阅状态）
{
    FILE *fp,*fptemp;
    struct BOOK *p;
    fp=fopen("图书基本信息.txt","r");
    if(fp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    fptemp=fopen("临时图书基本信息.txt","a+");
    if(fptemp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    p=(struct BOOK*)malloc(LONG);
    while(!feof(fp))
    {

        fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
        if(strcmp(p->booknum,booknumer)!=0)//不是我想要的那条
            fprintf(fptemp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,p->price,p->publisher,p->publishtime,p->bookintroduction,p->booksum,p->booklocation,p->lend,p->borrow,p->lendtimes);
        else    //是我想要改的那条
        {
            p->lend=1;
            fprintf(fptemp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,p->price,p->publisher,p->publishtime,p->bookintroduction,p->booksum,p->booklocation,p->lend,p->borrow,p->lendtimes);
        }
    }
    fclose(fp);fclose(fptemp);
    system("del 图书基本信息.txt");
    system("rename 临时图书基本信息.txt 图书基本信息.txt");	//将原文件删除，临时文件改成原文件的名字
}
void borrow_borrow_change_lendtime(char booknumer[50])//借书_正式借出_ 更改图书被借次数
{
    FILE *fp,*fptemp;
    struct BOOK *p;
    fp=fopen("图书基本信息.txt","r");
    if(fp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    fptemp=fopen("临时图书基本信息.txt","a+");
    if(fptemp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    p=(struct BOOK*)malloc(LONG);
    while(!feof(fp))
    {

        fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
        if(strcmp(p->booknum,booknumer)!=0)//不是我想要的那条
            fprintf(fptemp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,p->price,p->publisher,p->publishtime,p->bookintroduction,p->booksum,p->booklocation,p->lend,p->borrow,p->lendtimes);
        else    //是我想要改的那条
        {
            p->lendtimes=p->lendtimes+1;
            fprintf(fptemp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,p->price,p->publisher,p->publishtime,p->bookintroduction,p->booksum,p->booklocation,p->lend,p->borrow,p->lendtimes);
        }
    }
    fclose(fp);fclose(fptemp);
    system("del 图书基本信息.txt");
    system("rename 临时图书基本信息.txt 图书基本信息.txt");	//将原文件删除，临时文件改成原文件的名字
}
void borrow_borrow_change_borrow_book_num(char studentidnum[50])//借书_ 正式借出_更改学生外借图书数量
{
    FILE *fps,*fpstemp;
    struct students *ps;
    fps=fopen("学生信息.txt","r");
    if(fps==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    fpstemp=fopen("临时学生信息.txt","a+");
    if(fpstemp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    ps=(struct students*)malloc(LONGS);
    while(!feof(fps))
    {
        fscanf(fps,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,&ps->borrow_book_num,&ps->if_Frozen);
        if(strcmp(ps->idnumber,studentidnum)!=0)//不是我想要的那条
            fprintf(fpstemp,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,ps->borrow_book_num,ps->if_Frozen);
        else    //是我想要改的那条
        {
            ps->borrow_book_num=ps->borrow_book_num+1;
            fprintf(fpstemp,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,ps->borrow_book_num,ps->if_Frozen);
        }
    }
    fclose(fps);fclose(fpstemp);
    system("del 学生信息.txt");
    system("rename 临时学生信息.txt 学生信息.txt");		//将原文件删除，临时文件改成原文件的名字
}
int Return(char ID[20])//还书
{
    FILE *fp,*fps,*fpborrow;
    char bookname[50],booknum[20];
    struct BOOK *p;
    struct students *ps;
    struct BorrowInfo *pborrow;
    int a,b,c,d,e,f;
    do
    {
        system("cls");
        a=0;c=0;d=0;e=0;f=0;//是否与借书记录
        printf("--------------------------------------------------------------------------\n");
        printf("                            欢迎使用还书系统                              \n");
        printf("                          					                              \n");
        printf("--------------------------------------------------------------------------\n");
        fpborrow=fopen("图书借还信息.txt","r");
        if(fpborrow==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
        pborrow=(struct BorrowInfo*)malloc(LONGBORROW);
        while(!feof(fpborrow))
        {
            fscanf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,&pborrow->borrow_year,&pborrow->borrow_month,&pborrow->borrow_day,&pborrow->borrow_hour,&pborrow->borrow_minute,&pborrow->return_year,&pborrow->return_month,&pborrow->return_day,&pborrow->return_hour,&pborrow->return_minute,&pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
            if(strcmp(ID,pborrow->borrow_student_idnum)==0&&pborrow->return_year==0)//提取图书信息
            {
                a=1;
                fp=fopen("图书基本信息.txt","r");
                if(fp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
                p=(struct BOOK*)malloc(LONG);
                while(!feof(fp))
                {
                    fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
                    if(strcmp(pborrow->borrow_booknum,p->booknum)==0)
                        strcpy(bookname,p->bookname);
                }
                fclose(fp);
                printf("\n================================================================================================\n");
                printf("\n	学生号         图书编号            书本名称                借书时间\n");
                printf("\n------------------------------------------------------------------------------------------------\n");
                printf("\n	%-10s	%-12s%12s             %d年%d月%d日%d时%d分\n\n",ID,pborrow->borrow_booknum,pborrow->borrow_bookname,pborrow->borrow_year,pborrow->borrow_month,pborrow->borrow_day,pborrow->borrow_hour,pborrow->borrow_minute);
            }
        }
        if(a==0)//没找到这个学生
        {
            fclose(fpborrow);
            system("cls");
            printf("\a\n 未找到该学生的借阅信息,请您重新查找 \n\n");
            printf("\n=====================================================================\n");
            printf("			【1】返回上一级      \n");
            printf("=====================================================================\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1:
                {
                    system("cls");
                    return 0;
                    break;
                }
                default://容错
                {
                    system("cls");
                    fclose(fps);
                    printf("\n\n您的输入错误，请重新选择\n\n");
                    break;
                }
            }
        }
        else//是否正式还书
        {
            fclose(fpborrow);
            do
            {
                printf("\n\n=====================================================================\n");
                printf("				是否归还图书             \n");
                printf("			【1】是		【2】否      \n");
                printf("=====================================================================\n");
                scanf("%d",&d);
                switch(d)
                {
                    case 1:
                    {
                        break;
                    }
                    case 2:
                    {
                        system("cls");
                        //fclose(fps);
                        return 0;
                        break;
                    }
                    default://容错
                    {
                        system("cls");
                        fclose(fps);
                        printf("\n\n您的输入错误，请重新选择\n\n");
                        break;
                    }
                }
                do
                {
                    printf("请输入想归还的图书的图书编号：\n");
                    scanf("%s",booknum);
                    if(borrowtime(ID)==0)
                    {
                        printf("\n您有书需要续借，请去学生主界面办理续借\n");
                        system("pause");
                        return 0;
                    }
                    else
                    {
                        fclose(fpborrow);
                        Return_change_lend(booknum);//更改图书信息 lend由1变0
                        Return_change_borrow_book_num(ID);//更改学生已借书数目 borrow_book_num  -1
                        Return_change_return_date(ID,booknum);//更改借阅信息，还书日期
                        printf("成功办理还书祝您阅读愉快\n\n");
                        printf("=====================================================================\n");
                        printf("			是否继续返还其他书籍             \n");
                        printf("		【1】继续还书		【2】返回上一级      \n");
                        printf("=====================================================================\n");
                        scanf("%d",&f);
                        switch(f)
                        {
                            case 1:
                            {
                                system("cls");
                                d=2;
                                break;
                            }
                            case 2:
                            {
                                system("cls");
                                return 0;
                                break;
                            }
                            default://容错
                            {
                                system("cls");
                                printf("\n\n您的输入错误，请重新选择\n\n");
                                break;
                            }
                        }
                    }
                }while(e!=0);
            }while(d!=2);
        }
    }while(c!=1);
}
void Return_change_lend(char booknumer[50])//还书_更改图书lend（借阅状态）
{
    FILE *fp,*fptemp;
    struct BOOK *p;
    fp=fopen("图书基本信息.txt","r");
    if(fp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    fptemp=fopen("临时图书基本信息.txt","a+");
    if(fptemp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    p=(struct BOOK*)malloc(LONG);
    while(!feof(fp))
    {

        fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
        if(strcmp(p->booknum,booknumer)!=0)//不是我想要的那条
            fprintf(fptemp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,p->price,p->publisher,p->publishtime,p->bookintroduction,p->booksum,p->booklocation,p->lend,p->borrow,p->lendtimes);
        else    //是我想要改的那条
        {
            p->lend=0;
            fprintf(fptemp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,p->price,p->publisher,p->publishtime,p->bookintroduction,p->booksum,p->booklocation,p->lend,p->borrow,p->lendtimes);
        }
    }
    fclose(fp);fclose(fptemp);
    system("del 图书基本信息.txt");
    system("rename 临时图书基本信息.txt 图书基本信息.txt");//将原文件删除，临时文件改成原文件的名字
}
void Return_change_return_date(char id[50],char booknumber[50])//还书_更改_还书日期
{
    FILE *fpborrow,*fpborrowtemp;
    struct BorrowInfo *pborrow;
    int a=1;
    fpborrow=fopen("图书借还信息.txt","r");
    if(fpborrow==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    fpborrowtemp=fopen("临时图书借还信息.txt","a+");
    if(fpborrowtemp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    pborrow=(struct BorrowInfo*)malloc(LONGBORROW);
    time_t timep;
    struct tm *ptm;
    time (&timep);
    ptm=gmtime(&timep);
    while(!feof(fpborrow))
    {
        fscanf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,&pborrow->borrow_year,&pborrow->borrow_month,&pborrow->borrow_day,&pborrow->borrow_hour,&pborrow->borrow_minute,&pborrow->return_year,&pborrow->return_month,&pborrow->return_day,&pborrow->return_hour,&pborrow->return_minute,&pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
        //先找书号//再找学号//再找年份等于0
        if(strcmp(booknumber,pborrow->borrow_booknum)!=0&&strcmp(id,pborrow->borrow_student_idnum)==0&&pborrow->return_year==0)
            fprintf(fpborrowtemp,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,pborrow->borrow_year,pborrow->borrow_month,pborrow->borrow_day,pborrow->borrow_hour,pborrow->borrow_minute,pborrow->return_year,pborrow->return_month,pborrow->return_day,pborrow->return_hour,pborrow->return_minute,pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
        else
        {
            pborrow->return_year=ptm->tm_year+1900;
            pborrow->return_month=ptm->tm_mon+1;
            pborrow->return_day=ptm->tm_mday;
            pborrow->return_hour=ptm->tm_hour+8;
            pborrow->return_minute=ptm->tm_min;
            fprintf(fpborrowtemp,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,pborrow->borrow_year,pborrow->borrow_month,pborrow->borrow_day,pborrow->borrow_hour,pborrow->borrow_minute,pborrow->return_year,pborrow->return_month,pborrow->return_day,pborrow->return_hour,pborrow->return_minute,pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
        }
    }
    fclose(fpborrow);fclose(fpborrowtemp);
    system("del 图书借还信息.txt");
    system("rename 临时图书借还信息.txt 图书借还信息.txt");//将原文件删除，临时文件改成原文件的名字
}
void Return_change_borrow_book_num(char studentidnum[50])//还书_更改_学生外借图书数量
{
    FILE *fps,*fpstemp;
    struct students *ps;
    fps=fopen("学生信息.txt","r");
    if(fps==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    fpstemp=fopen("临时学生信息.txt","a+");
    if(fpstemp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    ps=(struct students*)malloc(LONGS);
    while(!feof(fps))
    {
        fscanf(fps,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,&ps->borrow_book_num,&ps->if_Frozen);
        if(strcmp(ps->idnumber,studentidnum)!=0)//不是我想要的那条
            fprintf(fpstemp,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,ps->borrow_book_num,ps->if_Frozen);
        else    //是我想要改的那条
        {
            ps->borrow_book_num=ps->borrow_book_num-1;
            fprintf(fpstemp,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,ps->borrow_book_num,ps->if_Frozen);
        }
    }
    fclose(fps);fclose(fpstemp);
    system("del 学生信息.txt");
    system("rename 临时学生信息.txt 学生信息.txt");//将原文件删除，临时文件改成原文件的名字
}
//**********************************************************还书
void student_enrolment()//学生注册
{
    char idnumber[30],school[30],major[30],name[30],gender[30],phonenumber[30],password[30],mailbox[30];
    FILE*fp;FILE*fp1;
    struct students temp;
    struct students temp1;
    struct students *pt;
    struct students *pt1;
    pt=&temp;
    pt1=&temp1;
    if((fp=fopen("学生信息.txt","r"))==NULL){printf("                            文件打开错误!                                   \n");exit(1);}
    if((fp1=fopen("学生信息temp_.txt","w+"))==NULL)//临时文件，pt1为指针。 {printf("                            文件打开错误!                                   \n");exit(1);}
        printf("\n=====================================================================\n");
    printf("                        欢迎来到学生注册界面！                         \n");
    printf("                           输入您的id号码：                            \n");
    printf("\n=====================================================================\n");
    scanf("%s",idnumber);
    while(idnumbervalidation(idnumber)==0)//判断id号码是否符合格式
    {
        printf("                         格式错误，请重新输入:                             \n");
        scanf("%s",idnumber);
    }
    while(!feof(fp))//将原文件的内容读到临时文件里
    {
        fscanf(fp,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,&pt->borrow_book_num,&pt->if_Frozen);
        fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,pt->borrow_book_num,pt->if_Frozen);//临时
    }
    rewind(fp);
    while(!feof(fp))//遍历文件查看该账号是否已经注册过
    {
        fscanf(fp,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,&pt->borrow_book_num,&pt->if_Frozen);
        if(strcmp(pt->idnumber,idnumber)==0)//是我想要的那条
        {
            printf("                          您已经注册过了！                                 \n");//
            fclose(fp);
            fclose(fp1);
            system("del 学生信息temp_.txt");//如果已经注册过，保留原文件，删除临时文件
            return;
        }
    }
    printf("                           输入您的学院：                              \n");
    scanf("%s",school);
    printf("                           输入您的专业：                              \n");
    scanf("%s",major);
    printf("                           输入您的姓名：                              \n");
    scanf("%s",name);
    printf("                           输入您的性别：                              \n");
    scanf("%s",gender);
    printf("                          输入您的电话号码：                           \n");
    scanf("%s",phonenumber);
    while(phonenumbervalidation(phonenumber)==0)
    {
        printf("                        格式错误，请重新输入：                         \n");
        scanf("%s",phonenumber);
    }
    printf("                           输入您的密码：                              \n");
    scanf("%s",password);
    printf("                           输入您的邮箱：                              \n");
    scanf("%s",mailbox);
    while(mailboxvalidation(mailbox)==0)
    {
        printf("                        格式错误，请重新输入：                         \n");
        scanf("%s",mailbox);
    }
    fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",idnumber,school,major,name,gender,phonenumber,password,mailbox,0,0);
    fclose(fp);
    fclose(fp1);
    system("del 学生信息.txt");
    system("rename 学生信息temp_.txt 学生信息.txt");//将原文件删除，临时文件命名为原文件的名字
}
void teacher_enrolment()//图书管理员注册
{
    char idnumber[30],name[30],password[30],mailbox[30];
    FILE*fp;FILE*fp1;
    struct teachers temp;
    struct teachers *pt;
    pt=&temp;
    if((fp=fopen("图书管理员信息.txt","r"))==NULL){printf("                            文件打开错误!                                   \n");exit(1);}
    if((fp1=fopen("图书管理员信息temp_.txt","w+"))==NULL){printf("                            文件打开错误!                                   \n");exit(1);}
    printf("\n=====================================================================\n");
    printf("                        欢迎来到管理员注册界面！                         \n");
    printf("                           输入您的id号码：                              \n");
    printf("\n=====================================================================\n");
    scanf("%s",idnumber);
    while(idnumbervalidation(idnumber)==0)//判断输入的id号码是否符合格式
    {
        printf("                         格式错误，请重新输入：                             \n");
        scanf("%s",idnumber);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %s\n",pt->idnumber_t,pt->name_t,pt->password_t,pt->mailbox_t);
        fprintf(fp1,"%s %s %s %s\n",pt->idnumber_t,pt->name_t,pt->password_t,pt->mailbox_t);
    }
    rewind(fp);
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %s\n",pt->idnumber_t,pt->name_t,pt->password_t,pt->mailbox_t);
        if(strcmp(pt->idnumber_t,idnumber)==0)//是我想要的那条
        {
            printf("                          您已经注册过了！                                 \n");
            fclose(fp);
            fclose(fp1);
            system("del 图书管理员信息temp_.txt");
            return;
        }
    }
    printf("                           输入您的姓名：                              \n");
    scanf("%s",name);
    printf("                           输入您的密码：                              \n");
    scanf("%s",password);
    printf("                           输入您的邮箱：                              \n");
    scanf("%s",mailbox);
    while(mailboxvalidation(mailbox)==0)
    {
        printf("                         格式错误，请重新输入：                             \n");
        scanf("%s",mailbox);
    }
    fprintf(fp,"%s %s %s %s\n",idnumber,name,password,mailbox);
    fclose(fp);
    fclose(fp1);
    system("del 图书管理员信息.txt");
    system("rename 图书管理员信息temp_.txt 图书管理员信息.txt");//将原文件删除，临时文件改成原文件的名字
}
int idnumbervalidation(char idnumber[20])//学号/工号格式判断//符合返回1
{
    int index,n=0;
    if(strlen(idnumber)!=10)
        return 0;
    for(index=0;index<=9;index++)
    {
        if(idnumber[index]>='0'&&idnumber[index]<='9')
            n++;
    }
    if(n==10)
        return 1;
    else
        return 0;
}
int booknumbervalidation(char booknumber[20])//图书编号格式判断//符合返回1
{
    int index,status=0;
    if((strlen(booknumber)==1&&(booknumber[0]=='n'||booknumber[1]=='N')))
        return 1;
    else
    {
        if(strlen(booknumber)!=6)
            return 0;
        else
        {
            for(index=0;index<=5;index++)
            {
                if(booknumber[index]<='9'&&booknumber[index]>='0');
                else status++;
            }
            if(status==0)
                return 1;
            else
                return 0;
        }
    }
}
int phonenumbervalidation(char phonenumber[20])//电话格式判断     //符合返回1，不符合返回0
{
    int index,n=0;
    if(strlen(phonenumber)!=11)
        return 0;
    for(index=0;index<=10;index++)
    {
        if(phonenumber[index]>='0'&&phonenumber[index]<='9')
            n++;
    }
    if(n==11)
        return 1;
    else
        return 0;
}
int mailboxvalidation(char mailbox[])//邮箱格式判断    //符合返回1，不符合返回0
{
    int n=strlen(mailbox),index,status1=0,status2=0;
    for(index=0;index<n;index++)
    {
        if(mailbox[index]=='@'||mailbox[index]=='.')
        {
            if(mailbox[index]=='@')
                status1++;
            else
            {
                if(status1!=1)
                    return 0;
                if(status1=1)
                    status2++;
            }
        }
    }
    if(status2==1&&status1==1)
        return 1;
    else
        return 0;
}

void studentinfo_management(char idnumber_[20])//该学生的序号
{
    struct students studentinformation;
    struct students studentinformation1;
    struct students *pt;
    struct students *pt1;
    pt1=&studentinformation1;
    pt=&studentinformation;
    FILE *fp,*fp1;
    char newpassword[30],newmailbox[30],newphonenumber[30];
    int index1,index,choice;
    printf("\n=====================================================================\n");
    printf("                      选择你想要修改的数据：                           \n");
    printf("1.改密码                   2.改邮箱                        3.改电话号码\n");
    printf("\n=====================================================================\n");
    scanf("%d",&choice);
    while(!(choice>=1&&choice<=3))//输入的是字符，都在容错范围内
    {
        printf("                      格式错误，请重新输入：                           \n");
        scanf("%d",&choice);
    }
    if((fp=fopen("学生信息.txt","r"))==NULL){printf("无法打开该文件!\n");exit(1);}
    if((fp1=fopen("学生信息temp.txt","w+"))==NULL){printf("无法打开该文件!\n");exit(1);}
    switch(choice)
    {
        case 1://改密码
        {
            printf("                            你的新密码：                         \n");
            scanf("%s",newpassword); //读入新的密码
            while(!feof(fp))
            {
                fscanf(fp,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,&(pt->borrow_book_num),&pt->if_Frozen);
                if(strcmp(pt->idnumber,idnumber_)==0)//是我想要的那条
                {
                    strcpy(pt1->password,newpassword);
                    strcpy(pt1->idnumber,pt->idnumber);
                    strcpy(pt1->school,pt->school);
                    strcpy(pt1->major,pt->major);
                    strcpy(pt1->name,pt->name);
                    strcpy(pt1->gender,pt->gender);
                    strcpy(pt1->phonenumber,pt->phonenumber);
                    strcpy(pt1->mailbox,pt->mailbox);
                    pt1->borrow_book_num=pt->borrow_book_num;
                    pt1->if_Frozen=pt->if_Frozen;
                }
                else    //不是我想要的那条
                    fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,pt->borrow_book_num,pt->if_Frozen);
            }
            fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt1->idnumber,pt1->school,pt1->major,pt1->name,pt1->gender,pt1->phonenumber,pt1->password,pt1->mailbox,pt1->borrow_book_num,pt1->if_Frozen);
            fclose(fp);
            fclose(fp1);
            system("del 学生信息.txt");
            system("rename 学生信息temp.txt 学生信息.txt");//将原文件删除，临时文件改成原文件的名字
            break;
        }
        case 2://改邮箱
        {
            printf("                            你的新邮箱：                         \n");
            scanf("%s",newmailbox);
            while(mailboxvalidation(newmailbox)==0)
            {
                printf("                      格式错误，请重新输入：                           \n");
                scanf("%s",newmailbox);
            } //使用是否为格式正确的邮箱的函数
            while(!feof(fp))//studentnum:学生数
            {
                fscanf(fp,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,&(pt->borrow_book_num),&pt->if_Frozen);            //修改文件内容
                if(strcmp(pt->idnumber,idnumber_)==0)//是我想要的那条
                {
                    strcpy(pt1->password,pt->password);
                    strcpy(pt1->idnumber,pt->idnumber);
                    strcpy(pt1->school,pt->school);
                    strcpy(pt1->major,pt->major);
                    strcpy(pt1->name,pt->name);
                    strcpy(pt1->gender,pt->gender);
                    strcpy(pt1->phonenumber,pt->phonenumber);
                    strcpy(pt1->mailbox,newmailbox);
                    pt1->borrow_book_num=pt->borrow_book_num;
                    pt1->if_Frozen=pt->if_Frozen;
                }
                else    //bu是我想要的那条
                    fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,pt->borrow_book_num,pt->if_Frozen);
            }
            fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt1->idnumber,pt1->school,pt1->major,pt1->name,pt1->gender,pt1->phonenumber,pt1->password,pt1->mailbox,pt1->borrow_book_num,pt1->if_Frozen);
            fclose(fp);
            fclose(fp1);
            system("del 学生信息.txt");
            system("rename 学生信息temp.txt 学生信息.txt");//将原文件删除，临时文件改成原文件的名字
            break;
        }
        case 3://改电话
        {
            printf("                           你的新电话号码：                         \n");
            scanf("%s",newphonenumber);
            while(phonenumbervalidation(newphonenumber)==0)
            {
                printf("                      格式错误，请重新输入：                           \n");
                fgets(newphonenumber,12,stdin);
            }
            while(!feof(fp))//studentnum:学生数
            {
                fscanf(fp,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,&(pt->borrow_book_num),&pt->if_Frozen);            //修改文件内容
                if(strcmp(pt->idnumber,idnumber_)==0)//是我想要的那条
                {
                    strcpy(pt1->password,pt->password);
                    strcpy(pt1->idnumber,pt->idnumber);
                    strcpy(pt1->school,pt->school);
                    strcpy(pt1->major,pt->major);
                    strcpy(pt1->name,pt->name);
                    strcpy(pt1->gender,pt->gender);
                    strcpy(pt1->phonenumber,newphonenumber);
                    strcpy(pt1->mailbox,pt->mailbox);
                    pt1->borrow_book_num=pt->borrow_book_num;
                    pt1->if_Frozen=pt->if_Frozen;
                }
                else    //bu是我想要的那条
                    fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,pt->borrow_book_num,pt->if_Frozen);

            }
            fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt1->idnumber,pt1->school,pt1->major,pt1->name,pt1->gender,pt1->phonenumber,pt1->password,pt1->mailbox,pt1->borrow_book_num,pt1->if_Frozen);
            fclose(fp);
            fclose(fp1);
            system("del 学生信息.txt");
            system("rename 学生信息temp.txt 学生信息.txt");//将原文件删除，临时文件改成原文件的名字
            break;
        }
    }
}
void teacherinfo_management(char idnumber_[20])//该teacher的序号
{
    struct teachers teacherinformation;
    struct teachers teacherinformation1;
    struct teachers *pt;
    struct teachers *pt1;
    pt=&teacherinformation;
    pt1=&teacherinformation1;
    FILE *fp;
    FILE *fp1;
    char newpassword[30],newmailbox[30],tempidnumber[30]; //修改文件时用到
    int index1,index,choice;
    printf("\n=====================================================================\n");
    printf("                      选择你想要修改的数据：                           \n");
    printf("1.         改密码                           2.改邮箱                   \n");
    printf("\n=====================================================================\n");
    scanf("%d",&choice);
    while(!(choice>=1&&choice<=2))//输入的是字符，都在容错范围内
    {
        printf("输入错误，请重新输入：");
        scanf("%d",&choice);
    }
    if((fp=fopen("图书管理员信息.txt","r"))==NULL){printf("                            文件打开错误!                                   \n");exit(1);}
    if ((fp1=fopen("图书管理员信息temp.txt","w"))==NULL){printf("                            文件打开错误!                                   \n");exit(1); }
    switch(choice)
    {
        case 1://改密码
        {
            printf("                            你的新密码：                         \n");
            scanf("%s",newpassword); //读入新的密码
            while(!feof(fp))
            {
                fscanf(fp,"%s %s %s %s\n",pt->idnumber_t,pt->name_t,pt->password_t,pt->mailbox_t);
                if(strcmp(pt->idnumber_t,idnumber_)==0)//是我想要的那条
                {
                    strcpy(pt1->password_t,newpassword);
                    strcpy(pt1->idnumber_t,pt->idnumber_t);
                    strcpy(pt1->name_t,pt->name_t);
                    strcpy(pt1->mailbox_t,pt->mailbox_t);
                }
                else    //bu是我想要的那条
                {
                    fprintf(fp1,"%s %s %s %s\n",pt->idnumber_t,pt->name_t,pt->password_t,pt->mailbox_t);
                }
                fprintf(fp1,"%s %s %s %s\n",pt1->idnumber_t,pt1->name_t,pt1->password_t,pt1->mailbox_t);
            }
            fclose(fp);
            fclose(fp1);
            system("del 图书管理员信息.txt");
            system("rename 图书管理员信息temp.txt 图书管理员信息.txt");//将原文件删除，临时文件改成原文件的名字
            break;
        }
        case 2://改邮箱
        {
            printf("                            你的新邮箱：                         \n");
            scanf("%s",newmailbox);
            while(mailboxvalidation(newmailbox)==0)
            {
                printf("                        格式错误，请重新输入：                   \n");
                scanf("%s",newmailbox);
            } //使用是否为格式正确的邮箱的函数

            while(!feof(fp))//studentnum:学生数
            {
                fscanf(fp,"%s %s %s %s\n",pt->idnumber_t,pt->name_t,pt->password_t,pt->mailbox_t);            //修改文件内容
                if(strcmp(pt->idnumber_t,idnumber_)==0)//是我想要的那条
                {
                    strcpy(pt1->password_t,pt->password_t);
                    strcpy(pt1->idnumber_t,pt->idnumber_t);
                    strcpy(pt1->name_t,pt->name_t);
                    strcpy(pt1->mailbox_t,newmailbox);
                }
                else    //bu是我想要的那条
                {
                    fprintf(fp1,"%s %s %s %s\n",pt->idnumber_t,pt->name_t,pt->password_t,pt->mailbox_t);
                }
            }
            fprintf(fp1,"%s %s %s %s\n",pt1->idnumber_t,pt1->name_t,pt1->password_t,pt1->mailbox_t);
            fclose(fp);
            fclose(fp1);
            system("del 图书管理员信息.txt");
            system("rename 图书管理员信息temp.txt 图书管理员信息.txt");//将原文件删除，临时文件改成原文件的名字
            break;
        }
    }
}
void deleteborrowinfo(char idnum[20])//只负责删除，不负责判断购物车文件里的词条数
{
    FILE *fpbuffer,*fpbuffertemp,*fp;
    char booknum[20],bookname[20];
    struct buffer *pbuffer;
    struct BOOK *p;
    int status=0;
    fpbuffer=fopen("购物车.txt","a+");
    if(fpbuffer==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    pbuffer=(struct buffer*)malloc(LONGBUFFER);
    while(!feof(fpbuffer))
    {
        fscanf(fpbuffer,"%s %s\n",pbuffer->idnumber_,pbuffer->booknumber);
        if(strcmp(idnum,pbuffer->idnumber_)==0)
        {
            fp=fopen("图书基本信息.txt","r");
            if(fp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
            p=(struct BOOK*)malloc(LONG);
            while(!feof(fp))
            {
                fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
                if(strcmp(pbuffer->booknumber,p->booknum)==0)
                    strcpy(bookname,p->bookname);
            }
            fclose(fp);
            printf("\n=====================================================================\n");
            printf("\n	学生号         图书编号            书本名称\n");
            printf("\n---------------------------------------------------------------------\n");
            printf("\n	%-10s	%-12s%12s\n\n",idnum,pbuffer->booknumber,bookname);
            printf("\n---------------------------------------------------------------------\n\n");
        }
    }
    fclose(fpbuffer);
    fclose(fp);
    printf("===============================================\n\n");
    printf("请输入想删除的记录的图书编号\n");
    printf("===============================================\n\n");
    scanf("%s",booknum);
    while(booknumbervalidation(booknum)==0)
    {
        printf("                         格式错误，请重新输入：                             \n");
        scanf("%s",booknum);
    }
    fpbuffer=fopen("购物车.txt","r");
    if(fpbuffer==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    fpbuffertemp=fopen("临时购物车.txt","a+");
    if(fpbuffer==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    pbuffer=(struct buffer*)malloc(LONGBUFFER);
    while(!feof(fpbuffer))//studentnum:学生数,recordnum:buffer里的词条数
    {
        fscanf(fpbuffer,"%s %s\n",pbuffer->idnumber_,pbuffer->booknumber);
        if(strcmp(pbuffer->idnumber_,idnum)!=0)//不是我想要的那条
            fprintf(fpbuffertemp,"%s %s\n",pbuffer->idnumber_,pbuffer->booknumber);
        else    //是我想要的那条,继续验证enter的编码号是不是正确，如果不正确，则也输入到临时文件里
        {
            if(strcmp(pbuffer->booknumber,booknum)!=0)
                fprintf(fpbuffertemp,"%s %s\n",pbuffer->idnumber_,pbuffer->booknumber);
            else status++;
        }
    }
    fclose(fpbuffer);
    fclose(fpbuffertemp);
    system("del 购物车.txt");
    system("rename 临时购物车.txt 购物车.txt");	//将原文件删除，临时文件改成原文件的名字
    Return_change_lend(booknum);//修改图书借阅状态为“可借”
    system("pause");
}
int search_by_writername()//按照作者查询
{
    int c;
    do
    {
        c=0;
        int i=0,a=0;
        char searchname[100];
        FILE *fp;
        struct BOOK *p;
        fp=fopen("图书基本信息.txt","a+");
        if(fp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
        p=(struct BOOK*)malloc(LONG);
        printf("===================================\n");
        printf("请输入查询图书的作者\n");
        printf("===================================\n");
        scanf("%s",searchname);
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
            if(strcmp(searchname,p->writer)==0)
            {
                a=1;
                //printf("%s %s %s %f %s %s %s %d %s %d %d %d",*mbook[i].booknum,*mbook[i].bookname,*mbook[i].writer,*mbook[i].price,*mbook[i].publisher,*mbook[i].publishtime,*mbook[i].bookintroduction,*mbook[i].booksum,*mbook[i].booklocation,*mbook[i].lend,*mbook[i].borrow,*mbook[i].lendtimes);
                printf("=================================================\n");
                printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","编号：",p->booknum,"书名：",p->bookname,"单价：",p->price);
                printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","作者：",p->writer,"出版社：",p->publisher,"出版时间:",p->publishtime);
                printf("%-8s%s\n\n","图书位置：",p->booklocation);
                printf("\n\n");
            }
        }
        fclose(fp);
        if(a==0)
        {
            system("cls");
            printf("\a\n 未找到与条件相符的图书,请您重新查找 \n\n");
            printf("=====================================================================\n");
            printf("			是否继续查找其他书籍             \n");
            printf("		【1】继续查找		【2】返回上一级      \n");
            printf("=====================================================================\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1:
                {
                    system("cls");
                    continue;
                }
                case 2:
                {
                    system("cls");
                    return 0;
                    break;
                }
                default://容错
                {
                    system("cls");
                    printf("\n\n您的输入错误，请重新选择\n\n");
                    break;
                }
            }
        }
        if(a==1)
        {
            printf("=====================================================================\n");
            printf("			是否继续查找其他书籍             \n");
            printf("		【1】继续查找		【2】返回上一级      \n");
            printf("=====================================================================\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1:
                {
                    system("cls");
                    continue;
                }
                case 2:
                {
                    system("cls");
                    return 0;
                    break;
                }
                default://容错
                {
                    system("cls");
                    printf("\n\n您的输入错误，请重新选择\n\n");
                    break;
                }
            }
        }
    }while(c!=2);
}
int search_by_name()//按照书名查询
{
    int c;
    do
    {
        c=0;
        int i=0,a=0;
        char searchname[100];
        FILE *fp;
        struct BOOK *p;
        fp=fopen("图书基本信息.txt","a+");
        if(fp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
        p=(struct BOOK*)malloc(LONG);
        printf("===================================\n");
        printf("请输入查询图书的书名\n");
        printf("===================================\n");
        scanf("%s",searchname);
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
            if(strcmp(searchname,p->bookname)==0)
            {
                a=1;
                printf("=================================================\n");
                printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","编号：",p->booknum,"书名：",p->bookname,"单价：",p->price);
                printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","作者：",p->writer,"出版社：",p->publisher,"出版时间:",p->publishtime);
                printf("%-8s%s\n\n","图书位置：",p->booklocation);
                printf("\n\n");
            }
        }
        fclose(fp);
        if(a==0)
        {
            system("cls");
            printf("\a\n 未找到与条件相符的图书,请您重新查找 \n\n");
            printf("=====================================================================\n");
            printf("			是否继续查找其他书籍             \n");
            printf("		【1】继续查找		【2】返回上一级      \n");
            printf("=====================================================================\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1:
                {
                    system("cls");
                    continue;
                }
                case 2:
                {
                    system("cls");
                    return 0;
                    break;
                }
                default://容错
                {
                    system("cls");
                    printf("\n\n您的输入错误，请重新选择\n\n");
                    break;
                }
            }
        }
        if(a==1)
        {
            printf("=====================================================================\n");
            printf("			是否继续查找其他书籍             \n");
            printf("		【1】继续查找		【2】返回上一级      \n");
            printf("=====================================================================\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1:
                {
                    system("cls");
                    continue;
                }
                case 2:
                {
                    system("cls");
                    return 0;
                    break;
                }
                default://容错
                {
                    system("cls");
                    printf("\n\n您的输入错误，请重新选择\n\n");
                    break;
                }
            }
        }
    }while(c!=2);
}
int search_by_press()//按照出版社查询
{
    int c;
    do
    {
        c=0;
        int i=0,a=0;
        char searchname[100];
        FILE *fp;
        struct BOOK *p;
        fp=fopen("图书基本信息.txt","a+");
        if(fp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
        p=(struct BOOK*)malloc(LONG);
        printf("===================================\n");
        printf("请输入查询图书的出版社(*****出版社)\n");
        printf("===================================\n");
        scanf("%s",searchname);
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
            if(strcmp(searchname,p->publisher)==0)
            {
                a=1;
                printf("=================================================\n");
                printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","编号：",p->booknum,"书名：",p->bookname,"单价：",p->price);
                printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","作者：",p->writer,"出版社：",p->publisher,"出版时间:",p->publishtime);
                printf("%-8s%s\n\n","图书位置：",p->booklocation);
                printf("\n\n");
            }
        }
        fclose(fp);
        if(a==0)
        {
            system("cls");
            printf("\a\n 未找到与条件相符的图书,请您重新查找 \n\n");
            printf("=====================================================================\n");
            printf("			是否继续查找其他书籍             \n");
            printf("		【1】继续查找		【2】返回上一级      \n");
            printf("=====================================================================\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1:
                {
                    system("cls");
                    continue;
                }
                case 2:
                {
                    system("cls");
                    return 0;
                    break;
                }
                default://容错
                {
                    system("cls");
                    printf("\n\n您的输入错误，请重新选择\n\n");
                    break;
                }
            }
        }
        if(a==1)
        {
            printf("=====================================================================\n");
            printf("			是否继续查找其他书籍             \n");
            printf("		【1】继续查找		【2】返回上一级      \n");
            printf("=====================================================================\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1:
                {
                    system("cls");
                    continue;
                }
                case 2:
                {
                    system("cls");
                    return 0;
                    break;
                }
                default://容错
                {
                    system("cls");
                    printf("\n\n您的输入错误，请重新选择\n\n");
                    break;
                }
            }
        }
    }while(c!=2);
}
int book_add()//图书添加
{
    while(1)
    {
        FILE *fp;
        struct BOOK book[1000];
        struct BOOK *p1;
        p1=book;
        int a=100000,b,c=10100,m,n,p=0,i=0;
        char z;
        fp=fopen("图书基本信息.txt","a+");
        while(fscanf(fp,"%c",&z)!=EOF)
        {
            if(z=='\n')
            {
                p++;
            }
        }
        a=a+p;
        c=c+p;
        system("cls");
        printf("请输入新图书信息：\n");
        printf("============================================================================\n");
        printf(" 书名  作者  价格 出版社  出版年_月_日  简介 数量\n");
        printf("----------------------------------------------------------------------------\n");
        scanf("%s %s %f %s %s %s %d",(p1+p)->bookname,(p1+p)->writer,&(p1+p)->price,(p1+p)->publisher,(p1+p)->publishtime,(p1+p)->bookintroduction,&(p1+p)->booksum);
        (p1+p)->lend=0;
        (p1+p)->borrow=(p1+p)->booksum;
        (p1+p)->lendtimes=0;
        if((p1+p)->booksum==1)
        {
            a=a+1;
            c=c+1;
            fprintf(fp,"%d %s %s %f %s %s %s %d %d %d %d %d\n",a,(p1+p)->bookname,(p1+p)->writer,(p1+p)->price,(p1+p)->publisher,(p1+p)->publishtime,(p1+p)->bookintroduction,(p1+p)->booksum,c,(p1+p)->lend,(p1+p)->borrow,(p1+p)->lendtimes);
            fflush(fp);
        }
        else
        {
            for(b=1;b<=(p1+p)->booksum;b++)
            {
                a=a+1;
                c=c+1;
                fprintf(fp,"%d %s %s %f %s %s %s %d %d %d %d %d\n",a,(p1+p)->bookname,(p1+p)->writer,(p1+p)->price,(p1+p)->publisher,(p1+p)->publishtime,(p1+p)->bookintroduction,(p1+p)->booksum,c,(p1+p)->lend,(p1+p)->borrow,(p1+p)->lendtimes);
                fflush(fp);
            }
        }
        fclose(fp);
        printf("----------------------------------------------\n");
        printf("|        [1].继续录入    [2].结束录入        |\n");
        printf("----------------------------------------------\n");
        printf("请选择：");
        scanf("%d",&n);
        switch(n)
        {
            case 1:break;
            case 2:
            {
                return 0;
                break;
            }
        }
    }
    printf("谢谢使用！\n");
    return 1;
}
int update()//修改图书
{
    int c;
    do
    {
        c=0;
        int i=0,a=2,b,d,e,f,g,z;//b为选择
        char bookintroduction[200],booklocation[50],updnum[10];///updnum是字符串数组
        struct BOOK *pb;//=mbook;///指针初始化
        struct BOOK *qb;//=ubook;
        FILE *fp,*fq;
        fp=fopen("图书基本信息.txt","r");///源文件
        pb=(struct BOOK*)malloc(LONG);
        qb=(struct BOOK*)malloc(LONG);
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,&pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,&pb->booksum,pb->booklocation,&pb->lend,&pb->borrow,&pb->lendtimes);
            printf("=================================================\n");
            printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","编号：",pb->booknum,"书名：",pb->bookname,"单价：",pb->price);
            printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","作者：",pb->writer,"出版社：",pb->publisher,"出版时间:",pb->publishtime);
            printf("%-8s%s\n\n","图书位置：",pb->booklocation);
            printf("%-6s%s\n\n","图书简介：",pb->bookintroduction);
            printf("\n\n");
        }
        fclose(fp);
        printf("请输入想修改的图书编号：\n") ;
        scanf("%s",updnum);
        system("cls");
        fp=fopen("图书基本信息.txt","r");///源文件
        while(!feof(fp))//判断该图书是否被借出	借出则不能修改
        {
            fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,&pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,&pb->booksum,pb->booklocation,&pb->lend,&pb->borrow,&pb->lendtimes);
            if(strcmp(updnum,pb->booknum)==0)//被借走了
            {
                d=1;
                if(pb->lend==1)
                    a=1;
                else
                    a=0;
            }
        }
        if(d==1)
        {
            if(a==1)
            {
                fclose(fp);
                system("cls");
                printf("\n这本书已经被借走，无法修改\n\n");////////
                printf("=====================================================================\n");
                printf("			是否继续查找其他书籍             \n");
                printf("		【1】继续查找		【2】返回上一级      \n");
                printf("=====================================================================\n");
                scanf("%d",&c);
                switch(c)
                {
                    case 1:
                    {
                        system("cls");
                        continue;
                    }
                    case 2:
                    {
                        system("cls");
                        return 0;
                        break;
                    }
                    default://容错
                    {
                        system("cls");
                        printf("\n\n您的输入错误，请重新选择\n\n");
                        break;
                    }
                }
            }
            if(a==0)
            {
                do
                {
                    fclose(fp);
                    printf("=====================================================================\n");
                    printf("			请选择需要修改的信息             \n");
                    printf("		【1】图书简介		【2】书架位置      \n");
                    printf("=====================================================================\n");
                    scanf("%d",&b);
                    switch(b)
                    {
                        case 1://更改图书简介
                        {
                            fp=fopen("图书基本信息.txt","r");///源文件
                            while(!feof(fp))
                            {
                                fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,&pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,&pb->booksum,pb->booklocation,&pb->lend,&pb->borrow,&pb->lendtimes);
                                if(strcmp(updnum,pb->booknum)==0)
                                {
                                    printf("=================================================\n");
                                    printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","编号：",pb->booknum,"书名：",pb->bookname,"单价：",pb->price);
                                    printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","作者：",pb->writer,"出版社：",pb->publisher,"出版时间:",pb->publishtime);
                                    printf("%-8s%s\n\n","图书位置：",pb->booklocation);
                                    printf("%-6s%s\n\n","图书简介：",pb->bookintroduction);
                                    printf("\n\n");
                                }
                            }
                            fclose(fp);
                            printf("请输入修改后的图书简介：");
                            scanf("%s",bookintroduction);
                            fp=fopen("图书基本信息.txt","r");///源文件
                            fq=fopen("result.txt","a+");///目标文件
                            while(!feof(fp))
                            {
                                fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,&pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,&pb->booksum,pb->booklocation,&pb->lend,&pb->borrow,&pb->lendtimes);
                                if(strcmp(updnum,pb->booknum)==0)
                                {
                                    strcpy(pb->bookintroduction,bookintroduction);
                                    fprintf(fq,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,pb->booksum,pb->booklocation,pb->lend,pb->borrow,pb->lendtimes);
                                }
                                else
                                    fprintf(fq,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,pb->booksum,pb->booklocation,pb->lend,pb->borrow,pb->lendtimes);
                            }
                            printf("修改成功\n");
                            fclose(fp);
                            fclose(fq);
                            system("del 图书基本信息.txt");
                            system("rename result.txt 图书基本信息.txt");//将原文件删除，临时文件改成原文件的名字
                            f=0;
                            break;
                        }
                        case 2:
                        {
                            fp=fopen("图书基本信息.txt","r");///源文件
                            while(!feof(fp))
                            {
                                fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,&pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,&pb->booksum,pb->booklocation,&pb->lend,&pb->borrow,&pb->lendtimes);
                                if(strcmp(updnum,pb->booknum)==0)
                                {
                                    printf("=================================================\n");
                                    printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","编号：",pb->booknum,"书名：",pb->bookname,"单价：",pb->price);
                                    printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","作者：",pb->writer,"出版社：",pb->publisher,"出版时间:",pb->publishtime);
                                    printf("%-8s%s\n\n","图书位置：",pb->booklocation);
                                    printf("%-6s%s\n\n","图书简介：",pb->bookintroduction);
                                    printf("\n\n");
                                }
                            }
                            fclose(fp);
                            printf("请输入修改后的书架位置（例：1排1层）：");
                            scanf("%s",booklocation);
                            fp=fopen("图书基本信息.txt","r");///源文件
                            while(!feof(fp))
                            {
                                fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,&pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,&pb->booksum,pb->booklocation,&pb->lend,&pb->borrow,&pb->lendtimes);
                                if(strcmp(booklocation,pb->booklocation)==0)
                                {
                                    e=1;
                                    break;
                                }
                                else
                                    e=0;
                            }
                            fclose(fp);
                            if(e!=1)
                            {
                                f=0;
                                fp=fopen("图书基本信息.txt","r");///源文件
                                fq=fopen("result.txt","a+");///目标文件
                                while(!feof(fp))
                                {
                                    fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,&pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,&pb->booksum,pb->booklocation,&pb->lend,&pb->borrow,&pb->lendtimes);
                                    if(strcmp(updnum,pb->booknum)==0)
                                    {
                                        strcpy(pb->booklocation,booklocation);
                                        fprintf(fq,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,pb->booksum,pb->booklocation,pb->lend,pb->borrow,pb->lendtimes);
                                    }
                                    else
                                        fprintf(fq,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,pb->booksum,pb->booklocation,pb->lend,pb->borrow,pb->lendtimes);
                                }
                                printf("修改成功\n");
                                fclose(fp);
                                fclose(fq);
                                system("del 图书基本信息.txt");
                                system("rename result.txt 图书基本信息.txt");//将原文件删除，临时文件改成原文件的名字
                            }
                            else//书架位置重复了
                            {
                                printf("该书架位置存在书本，请重新输入\n");
                                f=1;
                            }
                            break;
                        }
                    }
                }while(f!=0);
                fclose(fp);
                printf("=====================================================================\n");
                printf("			是否继续查找其他书籍             \n");
                printf("		【1】继续查找		【2】返回上一级      \n");
                printf("=====================================================================\n");
                scanf("%d",&c);
                switch(c)
                {
                    case 1:
                    {
                        system("cls");
                        continue;
                    }
                    case 2:
                    {
                        system("cls");
                        return 0;
                        break;
                    }
                    default://容错
                    {
                        system("cls");
                        printf("\n\n您的输入错误，请重新选择\n\n");
                        break;
                    }
                }
            }
        }
        else
        {
            system("cls");
            printf("\a\n 未找到与条件相符的图书,请您重新查找 \n\n");
            printf("=====================================================================\n");
            printf("			是否继续查找其他书籍             \n");
            printf("		【1】继续查找		【2】返回上一级      \n");
            printf("=====================================================================\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1:
                {
                    system("cls");
                    continue;
                }
                case 2:
                {
                    system("cls");
                    return 0;
                    break;
                }
                default://容错
                {
                    system("cls");
                    printf("\n\n您的输入错误，请重新选择\n\n");
                    break;
                }
            }
        }
    }while(c!=2);
}
int book_delete()//删除图书
{
    int c;
    do
    {
        c=0;
        int a=0,a1=0,a2=0;
        struct BOOK *pb;
        pb=(struct BOOK*)malloc(LONG);
        FILE *ff,*fp;
        char b[10];//保存用户输入的编号
        ff=fopen("图书基本信息.txt","r");//读打开原文件数据库.txt
        if(ff==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
        while(!feof(ff))
        {
            fscanf(ff,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,&pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,&pb->booksum,pb->booklocation,&pb->lend,&pb->borrow,&pb->lendtimes);
            printf("=================================================\n");
            printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","编号：",pb->booknum,"书名：",pb->bookname,"单价：",pb->price);
            printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","作者：",pb->writer,"出版社：",pb->publisher,"出版时间:",pb->publishtime);
            printf("%-8s%s\n\n","图书位置：",pb->booklocation);
            printf("%-6s%s\n\n","图书简介：",pb->bookintroduction);
            printf("\n\n");
        }
        printf("请输入要删除的图书编号:\n");
        scanf("%s",b);
        fclose(ff);
        ff=fopen("图书基本信息.txt","r");//读打开原文件数据库.txt
        while(!feof(ff))//查看是否有这个编号
        {
            fscanf(ff,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,&pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,&pb->booksum,pb->booklocation,&pb->lend,&pb->borrow,&pb->lendtimes);
            if(strcmp(b,pb->booknum)==0)
                a=1;//有这个编号
        }
        fclose(ff);
        if(a==1)
        {
            ff=fopen("图书基本信息.txt","r");//读打开原文件数据库.txt
            while(!feof(ff))
            {
                fscanf(ff,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,&pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,&pb->booksum,pb->booklocation,&pb->lend,&pb->borrow,&pb->lendtimes);
                if(strcmp(b,pb->booknum)==0)
                {
                    if(pb->lend==1)
                        a1=1;
                    else
                        a1=0;
                }
            }
            fclose(ff);
            if(a1==1)
            {
                a=0;
            }
            if(a1==0)
            {
                ff=fopen("图书基本信息.txt","r");//读打开原文件数据库.txt
                fp=fopen("临时图书基本信息.txt","a+");//写打开临时文件result.txt
                while(!feof(ff))
                {
                    fscanf(ff,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,&pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,&pb->booksum,pb->booklocation,&pb->lend,&pb->borrow,&pb->lendtimes);
                    if(strcmp(b,pb->booknum)!=0)
                        fprintf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,pb->booksum,pb->booklocation,pb->lend,pb->borrow,pb->lendtimes);
                }
                fclose(ff);
                fclose(fp);
                system("del 图书基本信息.txt");
                system("rename 临时图书基本信息.txt 图书基本信息.txt");//将原文件删除，临时文件改成原文件的名字
                a=0;
                a2=1;
            }
        }
        if(a==0)
        {
            system("cls");
            if(a1==1)
                printf("这本书正在外借无法删除\n");
            else if(a2==1)
                printf("删除成功\n");
            else
                printf("\a\n 未找到与条件相符的图书,请您重新查找 \n\n");
            printf("=====================================================================\n");
            printf("			是否继续查找其他书籍             \n");
            printf("		【1】继续查找		【2】返回上一级      \n");
            printf("=====================================================================\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1:
                {
                    system("cls");
                    continue;
                }
                case 2:
                {
                    system("cls");
                    return 0;
                    break;
                }
                default://容错
                {
                    system("cls");
                    printf("\n\n您的输入错误，请重新选择\n\n");
                    break;
                }
            }
        }
    }while(c!=2);
}
int Borrow_Time_Overdue_Book_Situation()//超时未还图书
{
    FILE*fp1;
    int i,a;
    char booknum[10],name[10];
    fp1=fopen("图书借还信息.txt","r");
    struct BorrowInfo *m;
    printf("--------------------------------------------------------------------------\n");
    printf("                                                                          \n");
    printf("超期未还图书情况：\n");
    printf("\n");
    printf("--------------------------------------------------------------------------\n");
    while(!feof(fp1))
    {
        m=(struct BorrowInfo*)malloc(LONGBORROW);
        fscanf(fp1,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",m->borrow_booknum,m->borrow_bookname,&m->borrow_year,&m->borrow_month,&m->borrow_day,&m->borrow_hour,&m->borrow_minute,&m->return_year,&m->return_month,&m->return_day,&m->return_hour,&m->return_minute,&m->renew_num,m->borrow_student_idnum,m->borrow_student_name);
        strcpy(booknum,m->borrow_booknum);
        i=borrowtime_booknumber(booknum);
        if(i==0)
        {
            printf("\n借阅学生学号   学生姓名  续借次数  书目编号        书名    借出时间\n ");
            printf("%s    %8s      %2d",m->borrow_student_idnum,m->borrow_student_name,m->renew_num);
            printf("    %s  %12s ",m->borrow_booknum,m->borrow_bookname);
            printf("   %d年%2d月%2d日%2d时%2d分\n\n",m->borrow_year,m->borrow_month,m->borrow_day,m->borrow_hour,m->borrow_minute);
            printf("--------------------------------------------------------------------------\n");
        }
    }
    fclose(fp1);
    system("pause");
    return 0;
}
int Borrow_Time_Overdue_Students_Situation()//超时未还行为学生
{
    FILE*fp1;
    int i;
    char id[50],name[10];
    fp1=fopen("学生信息.txt","r");
    struct students *m;
    printf("--------------------------------------------------------------------------\n");
    printf("                                                                          \n");
    printf("超期未还学生名单：\n");
    printf("\n");
    printf("         学生姓名              学生学号\n");
    while(!feof(fp1))
    {
        m=(struct students*)malloc(LONGS);
        fscanf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",m->idnumber,m->school,m->major,m->name,m->gender,m->phonenumber,m->password,m->mailbox,&m->borrow_book_num,&m->if_Frozen);
        strcpy(id,m->idnumber);
        i=borrowtime(id);
        if(i==0)
            printf("         %8s            %s\n",m->name,m->idnumber);
        printf("\n");
    }
    printf("--------------------------------------------------------------------------\n");
    fclose(fp1);
    system("pause");
    return 0;
}
int Borrow_Time_Overdue_Frozen()//账号冻结
{
    FILE*fp1;
    int i,a,b=0,t;
    char id[50];
    struct students *m;
    struct students *p;
    do
    {
        system("cls");
        fp1=fopen("学生信息.txt","r");
        printf("--------------------------------------------------------------------------\n");
        printf("                                                                          \n");
        printf("                           超期未还的学生名单：                           \n");
        printf("                                                                          \n");
        printf("--------------------------------------------------------------------------\n");
        m=(struct students*)malloc(LONGS);
        while(!feof(fp1))
        {
            fscanf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",m->idnumber,m->school,m->major,m->name,m->gender,m->phonenumber,m->password,m->mailbox,&m->borrow_book_num,&m->if_Frozen);
            strcpy(id,m->idnumber);
            i=borrowtime(id);
            if(i==0)
            {
                printf("                                                                          \n");
                printf("     姓名：%s 学号%s",m->name,m->idnumber);
                if(m->if_Frozen==1)//1是冻结
                    printf("      该学生账户已经被冻结");
                printf("\n");
            }
        }
        fclose(fp1);
        printf("                                                                          \n");
        printf("--------------------------------------------------------------------------\n");
        printf("                                                                          \n");
        printf("                           请输入（1~2）：                                \n");
        printf("                           1.冻结学生账户                                 \n");
        printf("                           2.返回上一界面                                 \n");
        printf("                                                                          \n");
        printf("--------------------------------------------------------------------------\n");
        printf("请输入：");
        scanf("%d",&b);
        if(b==1)
        {
            printf("--------------------------------------------------------------------------\n");
            printf("请输入您想冻结账户的学生学号：");
            scanf("%s",id);
            a=1;
            fp1=fopen("学生信息.txt","r");
            p=(struct students*)malloc(LONGS);
            while(!feof(fp1))
            {
                fscanf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",p->idnumber,p->school,p->major,p->name,p->gender,p->phonenumber,p->password,p->mailbox,&p->borrow_book_num,&p->if_Frozen);
                if(strcmp(id,p->idnumber)==0)
                {
                    t=borrowtime(id);
                    if(t==0)
                        a=0;
                    if(t==1)
                        a=2;
                }
            }
            if(a==1)
            {
                printf("--------------------------------------------------------------------------\n");
                printf("                                                                          \n");
                printf("                          未找到该学生信息\n");
                printf("                                                                          \n");
                printf("--------------------------------------------------------------------------\n");
            }
            if(a==2)
            {
                printf("--------------------------------------------------------------------------\n");
                printf("                                                                          \n");
                printf("                      该学生没有超期未还的图书\n");
                printf("                                                                          \n");
                printf("--------------------------------------------------------------------------\n");
            }
            fclose(fp1);
            if(a==0)
            {
                Frozen_Account(id);
                printf("--------------------------------------------------------------------------\n");
                printf("                                                                          \n");
                printf("                  学号为%s的学生账号已被冻结\n",id);
                printf("                                                                          \n");
                printf("--------------------------------------------------------------------------\n");
            }
        }
        if(b!=1&&b!=2)
        {
            printf("--------------------------------------------------------------------------\n");
            printf("                                                                          \n");
            printf("                          您输入错误，请重新输入                          \n");
            printf("                                                                          \n");
            printf("--------------------------------------------------------------------------\n");
        }
        system("pause");
    }while(b!=2);
    return 0;
}
int Borrow_Time_Overdue_Frozen1()//账号解冻
{
    FILE *fp1;
    int i,a,b=0,c;
    char id[50];
    struct students *m;
    struct students *p;
    do
    {
        system("cls");
        fp1=fopen("学生信息.txt","r");
        printf("--------------------------------------------------------------------------\n");
        printf("                                                                          \n");
        printf("                            已经被冻结的学生名单：                      \n\n");
        printf("                                                                          \n");
        while(!feof(fp1))
        {
            m=(struct students*)malloc(LONGS);
            fscanf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",m->idnumber,m->school,m->major,m->name,m->gender,m->phonenumber,m->password,m->mailbox,&m->borrow_book_num,&m->if_Frozen);
            strcpy(id,m->idnumber);
            if(m->if_Frozen==1)//1是冻结
            {
                printf("%s %s\n",m->name,m->idnumber);
                printf("--------------------------------------------------------------------------\n");
            }
        }
        fclose(fp1);
        printf("                               请输入（1~2）\n");
        printf("                                                                          \n");
        printf("                              1.解冻学生账户\n");
        printf("                                                                          \n");
        printf("                              2.返回上一界面\n");
        printf("                                                                          \n");
        printf("--------------------------------------------------------------------------\n");
        printf("请输入：");
        scanf("%d",&b);
        printf("\n");
        if(b==1)
        {
            printf("--------------------------------------------------------------------------\n");
            printf("                                                                          \n");
            printf("                         请输入您想解冻的学生学号：                       \n");
            printf("                                                                          \n");
            printf("--------------------------------------------------------------------------\n");
            printf("请输入：");
            scanf("%s",id);
            printf("\n");
            a=1;
            fp1=fopen("学生信息.txt","r");
            while(!feof(fp1))
            {
                p=(struct students*)malloc(LONGS);
                fscanf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",p->idnumber,p->school,p->major,p->name,p->gender,p->phonenumber,p->password,p->mailbox,&p->borrow_book_num,&p->if_Frozen);
                if(strcmp(id,p->idnumber)==0)
                    a=0;
            }
            if(a==1)
            {
                printf("--------------------------------------------------------------------------\n");
                printf("                                                                          \n");
                printf("                             未找到该学生信息                             \n");
                printf("                                                                          \n");
                printf("--------------------------------------------------------------------------\n");
            }
            fclose(fp1);
            if(a==0)
            {
                Frozen_Account1(id);
                printf("--------------------------------------------------------------------------\n");
                printf("                                                                          \n");
                printf("                    学号为%s的学生账号已被解冻\n",id);
                printf("                                                                          \n");
                printf("--------------------------------------------------------------------------\n");
            }
        }
        if(b!=1&&b!=2)
        {
            printf("--------------------------------------------------------------------------\n");
            printf("                                                                          \n");
            printf("                          您输入错误，请重新输入                          \n");
            printf("                                                                          \n");
            printf("--------------------------------------------------------------------------\n");
            system("pause");
        }
    }while(b!=2);
    printf("--------------------------------------------------------------------------\n");
    return 0;
}
void Frozen_Account(char idnumber[50])//冻结账号
{
    FILE *fp,*fp1;
    int a=1;
    fp=fopen("学生信息.txt","r");
    fp1=fopen("学生信息temp.txt","a+");
    if(fp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    struct students *pt;
    while(!feof(fp))
    {
        pt=(struct students*)malloc(LONGS);
        fscanf(fp,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,&pt->borrow_book_num,&pt->if_Frozen);
        if(strcmp(pt->idnumber,idnumber)==0)//是我想要的那条
        {
            pt->if_Frozen=a;
            fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,pt->borrow_book_num,pt->if_Frozen);
        }
        else    //不是我想要的那条
            fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,pt->borrow_book_num,pt->if_Frozen);
    }
    fclose(fp);
    fclose(fp1);
    system("del 学生信息.txt");
    system("rename 学生信息temp.txt 学生信息.txt");//将原文件删除，临时文件改成原文件的名字
}
void Frozen_Account1(char idnumber[50])//解冻账号
{
    FILE *fp,*fp1;
    int a=0;
    fp=fopen("学生信息.txt","r");
    fp1=fopen("学生信息temp.txt","a+");
    if(fp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    struct students *pt;
    pt=(struct students*)malloc(LONGS);
    while(!feof(fp))
    {
        pt=(struct students*)malloc(LONGS);
        fscanf(fp,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,&pt->borrow_book_num,&pt->if_Frozen);
        if(strcmp(pt->idnumber,idnumber)==0)//是我想要的那条
        {
            pt->if_Frozen=a;
            fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,pt->borrow_book_num,pt->if_Frozen);
        }
        else    //不是我想要的那条
            fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,pt->borrow_book_num,pt->if_Frozen);
    }
    fclose(fp);
    fclose(fp1);
    system("del 学生信息.txt");
    system("rename 学生信息temp.txt 学生信息.txt");//将原文件删除，临时文件改成原文件的名字
}
int BOOK_Borrow_situation()//图书借阅情况查询
{
    int i=0,a=0,b,NotBorrowNum=0,BorrowNum=0;
    char name[100];
    FILE *fp1,*fp2;
    struct BOOK *p;
    struct BorrowInfo *m;
    fp1=fopen("图书基本信息.txt","r");
    m=(struct BorrowInfo*)malloc(LONGBORROW);
    p=(struct BOOK*)malloc(LONG);
    while(!feof(fp1))
    {
        fscanf(fp1,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
        if (p->lend==0)
            NotBorrowNum+=1;
        else
            BorrowNum+=1;
    }
    fclose(fp1);
    do
    {
        b=0;
        system("cls");
        printf("--------------------------------------------------------------------------\n");
        printf("                                                                          \n");
        printf("                              已借数量：%d\n",BorrowNum);
        printf("                              在馆数量：%d\n\n",NotBorrowNum);
        printf("--------------------------------------------------------------------------\n");
        printf("                                                                          \n");
        printf("                             请输入（1~2）\n");
        printf("                            1.进行书目查询\n");
        printf("                            2.返回上级菜单\n");
        printf("                                                                          \n");
        printf("--------------------------------------------------------------------------\n");
        printf("请输入：");
        scanf("%d",&a);
        if(a==1)
        {
            printf("请您输入想搜寻图书名字：");//根据图书编号查询图书借阅情况
            scanf("%s",name);
            b=0;
            fp2=fopen("图书借还信息.txt","r");
            while(!feof(fp2))
            {
                fscanf(fp2,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",m->borrow_booknum,m->borrow_bookname,&m->borrow_year,&m->borrow_month,&m->borrow_day,&m->borrow_hour,&m->borrow_minute,&m->return_year,&m->return_month,&m->return_day,&m->return_hour,&m->return_minute,&m->renew_num,m->borrow_student_idnum,m->borrow_student_name);
                if(strcmp(name,m->borrow_bookname)==0)
                {
                    printf("--------------------------------------------------------------------------\n");
                    printf("书目编号：%s\n",m->borrow_booknum);
                    printf("借书时间：%d年%d月%d日%d时%d分\n",m->borrow_year,m->borrow_month,m->borrow_day,m->borrow_hour,m->borrow_minute);
                    printf("还书时间：%d年%d月%d日%d时%d分\n",m->return_year,m->return_month,m->return_day,m->return_hour,m->return_minute);
                    printf("续借次数：%d\n",m->renew_num);
                    printf("借阅学生学号：%s\n",m->borrow_student_idnum);
                    printf("借阅学生姓名：%s\n\n",m->borrow_student_name);
                    b=1;
                }
            }
            fclose(fp2);
            if(b==0)
                printf("未找到与条件相符的图书！\n");
        }
        if(a!=1&&a!=2)
        {
            printf("--------------------------------------------------------------------------\n");
            printf("                                                                          \n");
            printf("                         您输入错误，请重新输入                          \n");
            printf("                                                                          \n");
            printf("--------------------------------------------------------------------------\n");
        }
        system("pause");
    }while(a!=2);
    return 0;
}
int Search_By_Student_Name_Or_Title()//学生借阅情况查询
{
    int i=0,a=0,b=0,c;
    char name1[10],name2[100];
    FILE *fp1,*fp2;
    struct BOOK *p;
    struct BorrowInfo *q;
    struct students *m;
    p=(struct BOOK*)malloc(LONG);
    q=(struct BorrowInfo*)malloc(LONGBORROW);
    m=(struct students*)malloc(LONGS);
    struct students information1;//学生信息
    struct BorrowInfo information2;//学生借阅信息
    do
    {
        system("cls");
        printf("--------------------------------------------------------------------------\n");
        printf("                                                                          \n");
        printf("                        请输入（1~3）\n");
        printf("                      1.根据学生姓名查询\n");
        printf("                      2.根据书名查询\n");
        printf("                      3.返回上级菜单\n");
        printf("                                                                          \n");
        printf("--------------------------------------------------------------------------\n");
        printf("请输入：");
        scanf("%d",&a);
        b=0;
        if(a==1)
        {
            system("cls");
            b=0;
            fp1=fopen("学生信息.txt","r");
            printf("--------------------------------------------------------------------------\n");
            printf("                                                                          \n");
            printf("           请您输入想查询的学生姓名：");//根据学生姓名查询借阅图书的学生信息
            scanf("%s",name1);
            system("cls");
            while(!feof(fp1))
            {
                c=0;
                fscanf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",m->idnumber,m->school,m->major,m->name,m->gender,m->phonenumber,m->password,m->mailbox,&m->borrow_book_num,&m->if_Frozen);
                if(strcmp(name1,m->name)==0)
                {
                    printf("--------------------------------------------------------------------------\n");
                    printf("                                                                          \n");
                    printf("学生姓名：%s\n",name1);
                    printf("学生信息：\n");
                    printf("  学号：%s 院系：%s 专业：%s 性别：%s \n",m->idnumber,m->school,m->major,m->gender);
                    printf("  电话：%s 邮箱：%s \n",m->phonenumber,m->mailbox);
                    printf("                                                                          \n");
                    printf("--------------------------------------------------------------------------\n");
                    b=1;
                    c=1;
                    break;
                }
            }
            fclose(fp1);
            if(c==0)
            {
                printf("未能找到该学生信息\n");
                c=1;
            }
            if(b==1)
            {
                c=0;
                fp2=fopen("图书借还信息.txt","r");
                printf("--------------------------------------------------------------------------\n");
                printf("                                                                          \n");
                printf("                   该学生借书情况如下");
                printf("                                                                          \n");
                printf("书目编号       书名        借出时间                归还时间             续借次数 \n");
                while(!feof(fp2))
                {
                    fscanf(fp2,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",q->borrow_booknum,q->borrow_bookname,&q->borrow_year,&q->borrow_month,&q->borrow_day,&q->borrow_hour,&q->borrow_minute,&q->return_year,&q->return_month,&q->return_day,&q->return_hour,&q->return_minute,&q->renew_num,q->borrow_student_idnum,q->borrow_student_name);
                    if(strcmp(name1,q->borrow_student_name)==0)
                    {
                        printf("%6s %12s   %4d年%2d月%2d日%2d时%2d分   %4d年%2d月%2d日%2d时%2d分     %3d \n",q->borrow_booknum,q->borrow_bookname,q->borrow_year,q->borrow_month,q->borrow_day,q->borrow_hour,q->borrow_minute,q->return_year,q->return_month,q->return_day,q->return_hour,q->return_minute,q->renew_num);
                        b=1;
                        c=1;
                    }
                }
                fclose(fp2);
                printf("\n--------------------------------------------------------------------------\n");
                if(c==0)
                {
                    printf("未找到该学生借书信息\n");
                    c=1;
                }
            }
        }
        else if(a==2)
        {
            system("cls");
            fp2=fopen("图书借还信息.txt","r");
            printf("--------------------------------------------------------------------------\n");
            printf("                                                                          \n");
            printf("请您输入想查询书名：");//根据书名查询借阅学生的信息
            printf("\n");
            scanf("%s",name2);
            c=0;
            b=0;
            printf("--------------------------------------------------------------------------\n\n");
            while(!feof(fp2))
            {
                fscanf(fp2,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",q->borrow_booknum,q->borrow_bookname,&q->borrow_year,&q->borrow_month,&q->borrow_day,&q->borrow_hour,&q->borrow_minute,&q->return_year,&q->return_month,&q->return_day,&q->return_hour,&q->return_minute,&q->renew_num,q->borrow_student_idnum,q->borrow_student_name);
                if(strcmp(name2,q->borrow_bookname)==0)
                {
                    printf("书目编号   书名         借出时间                   归还时间       续借次数      学生学号   学生姓名\n\n");
                    printf("%6s   %6s   %4d年%2d月%2d日%2d时%2d分   %4d年%2d月%2d日%2d时%2d分    %2d           %s         %s\n\n",q->borrow_booknum,q->borrow_bookname,q->borrow_year,q->borrow_month,q->borrow_day,q->borrow_hour,q->borrow_minute,q->return_year,q->return_month,q->return_day,q->return_hour,q->return_minute,q->renew_num,q->borrow_student_idnum,q->borrow_student_name);
                    b=1;
                    c=1;
                    fp1=fopen("学生信息.txt","r");
                    while(!feof(fp1))
                    {
                        fscanf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",m->idnumber,m->school,m->major,m->name,m->gender,m->phonenumber,m->password,m->mailbox,&m->borrow_book_num,&m->if_Frozen);
                        if(strcmp(q->borrow_student_name,m->name)==0)
                        {
                            printf("        学号：%s    院系：%s     专业：%s    性别：%s \n\n",m->idnumber,m->school,m->major,m->gender);
                            printf("        电话：%s      邮箱：%20s \n\n",m->phonenumber,m->mailbox);
                            printf("\n--------------------------------------------------------------------------\n");
                            b=1;
                        }
                    }
                    fclose(fp1);
                    //	break;
                }
            }
            fclose(fp2);
            if(c==0)
            {
                printf("                   未找到与条件相符的图书！\n");
                printf("                                                                          \n");
                printf("--------------------------------------------------------------------------\n");
                c=1;
            }
        }
        if(a!=1&&a!=2&&a!=3)
        {
            printf("--------------------------------------------------------------------------\n");
            printf("                                                                          \n");
            printf("                          您输入错误，请重新输入                          \n");
            printf("                                                                          \n");
            printf("--------------------------------------------------------------------------\n");
        }
        system("pause");
    }while(a!=3);
    return 0;
}
int Sort_borrow_number()//通过借阅次数排序
{
    FILE *fp1;
    int i=0,j,a=0,t,x=0,lendtimes[100];
    char readed[100][100],y[100],name[10],id[50];
    fp1=fopen("图书基本信息.txt","r");
    struct BOOK *p;
    system("cls");
    printf("--------------------------------------------------------------------------\n");
    printf("                                                                          \n");
    printf("                              借阅次数排序：                              \n\n");
    while(!feof(fp1))
    {
        p=(struct BOOK*)malloc(LONG);
        fscanf(fp1,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
        a=0;
        for(j=0;j<i;j++)
        {
            if(strcmp(readed[j],p->bookname)==0)
                a=1;
        }
        if(a==0)
        {
            strcpy(readed[i],p->bookname);
            i++;
        }
    }
    fclose(fp1);
    for(j=0;j<i;j++)
    {
        fp1=fopen("图书基本信息.txt","r");
        lendtimes[j]=0;
        while(!feof(fp1))
        {
            p=(struct BOOK*)malloc(LONG);
            fscanf(fp1,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
            if(strcmp(readed[j],p->bookname)==0)
                lendtimes[j]=lendtimes[j]+p->lendtimes;
        }
        fclose(fp1);
    }
    t=i;
    for(i=0;i<t-1;i++)
    {
        for(j=t-1;j>i;j--)
        {
            if(lendtimes[j]>lendtimes[j-1])
            {
                x=lendtimes[j];
                strcpy(y,readed[j]);
                lendtimes[j]=lendtimes[j-1];
                strcpy(readed[j],readed[j-1]);
                lendtimes[j-1]=x;
                strcpy(readed[j-1],y);
            }
        }
    }
    for(j=0;j<t;j++)
    {
        printf("       书目:%20s       ",readed[j]);
        printf("借阅次数：%10d\n",lendtimes[j]);
        printf("                                                                          \n");
    }
    printf("\n--------------------------------------------------------------------------\n");
    system("pause");
    return 0;
}
int Sort_borrow_time()//通过借阅时间长短排序
{
    FILE *fp1,*fp2;
    int i=0,j,a=0,t,x,readtime[100];
    char y[100],readed[100][100],name[10],id[50];
    fp1=fopen("图书借还信息.txt","r");
    fp2=fopen("图书基本信息.txt","r");
    struct BorrowInfo *m;
    struct BOOK *p;
    system("cls");
    printf("--------------------------------------------------------------------------\n");
    printf("                                                                          \n");
    printf("                            借阅时间长短排序：                            \n");
    m=(struct BorrowInfo*)malloc(LONGBORROW);
    while(!feof(fp1))
    {
        fscanf(fp1,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",m->borrow_booknum,m->borrow_bookname,&m->borrow_year,&m->borrow_month,&m->borrow_day,&m->borrow_hour,&m->borrow_minute,&m->return_year,&m->return_month,&m->return_day,&m->return_hour,&m->return_minute,&m->renew_num,m->borrow_student_idnum,m->borrow_student_name);
        a=0;
        for(j=0;j<i;j++)
        {
            if(strcmp(readed[j],m->borrow_bookname)==0)
                a=1;
        }
        if(a==0)
        {
            strcpy(readed[i],m->borrow_bookname);
            i++;
        }
    }

    fclose(fp1);
    for(j=0;j<i;j++)
    {
        readtime[j]=bookname_borrowtime(readed[j]);
    }
    t=i;
    for(i=0;i<t-1;i++)
    {
        for(j=t;j>i;j--)
        {
            if(readtime[j]>readtime[j-1])
            {
                x= readtime[j];
                strcpy(y,readed[j]);

                readtime[j] = readtime[j-1];
                strcpy(readed[j],readed[j-1]);

                readtime[j-1] = x;
                strcpy(readed[j-1],y);
            }
        }
    }
    for(j=1;j<t;j++)
    {
        printf("       书目:%20s       ",readed[j]);
        printf("借阅时长：%10d分钟\n",readtime[j]);
        printf("                                                                          \n");
    }
    p=(struct BOOK*)malloc(LONG);
    while(!feof(fp2))
    {
        a=1;
        fscanf(fp2,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
        for(i=0;i<t;i++)
        {
            if(strcmp(readed[i],p->bookname)==0)
                a=0;
        }
        if(a==1)
            printf("       书目:%20s       借阅时长:          0分钟\n\n",p->bookname);
    }
    fclose(fp2);
    printf("\n\n--------------------------------------------------------------------------\n");
    system("pause");
    return 0;
}
int Sort_By_Book_Price()
{
    system("cls");
    FILE *fp1;
    int i=0,j,a=0,t;
    float x=0,price[100];
    char id[50],name[10],y[100],readed[100][100];
    fp1=fopen("图书基本信息.txt","r");
    struct BOOK *p;
    printf("--------------------------------------------------------------------------\n");
    printf("                                                                          \n");
    printf("                              图书价格排序：                              \n");
    p=(struct BOOK*)malloc(LONG);
    while(!feof(fp1))
    {
        fscanf(fp1,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
        a=0;
        for(j=0;j<i;j++)
        {
            if(strcmp(readed[j],p->bookname)==0)
            {
                a=1;
            }
        }
        if(a==0)
        {
            strcpy(readed[i],p->bookname);
            i++;
        }
    }
    fclose(fp1);
    for(j=0;j<i;j++)
    {
        fp1=fopen("图书基本信息.txt","r");
        price[j]=0;
        p=(struct BOOK*)malloc(LONG);
        while(!feof(fp1))
        {
            fscanf(fp1,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
            if(strcmp(readed[j],p->bookname)==0)
            {
                price[j]=p->price;
            }
        }
        fclose(fp1);
    }
    t=i;
    for(i=0;i<t-1;i++)
    {
        for(j=t-1;j>i;j--)
        {
            if(price[j]>price[j-1])
            {
                x=price[j];
                strcpy(y,readed[j]);

                price[j]=price[j-1];
                strcpy(readed[j],readed[j-1]);

                price[j-1]=x;
                strcpy(readed[j-1],y);
            }
        }
    }
    for(j=0;j<t;j++)
    {
        printf("       书目:%20s       ",readed[j]);
        printf("书目价格：%3.2f\n\n",price[j]);
    }
    printf("\n--------------------------------------------------------------------------\n");
    system("pause");
    return 0;
}
int bookname_borrowtime(char bookname[100])//计算出每一本书的借阅总时长
{
    int a;
    FILE *fpborrow;
    struct BorrowInfo *pborrow;
    int resttime1,resttime2,resttime3,resttime=0,borrow_year,borrow_month,borrow_day,borrow_hour,borrow_minute,return_year,return_month,return_day,return_hour,return_minute;
    fpborrow=fopen("图书借还信息.txt","r");
    if(fpborrow==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    pborrow=(struct BorrowInfo*)malloc(LONGBORROW);
    while(!feof(fpborrow))
    {
        a=1;
        fscanf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,&pborrow->borrow_year,&pborrow->borrow_month,&pborrow->borrow_day,&pborrow->borrow_hour,&pborrow->borrow_minute,&pborrow->return_year,&pborrow->return_month,&pborrow->return_day,&pborrow->return_hour,&pborrow->return_minute,&pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
        if(strcmp(bookname,pborrow->borrow_bookname)==0)//提取借书时间
        {
            borrow_year=pborrow->borrow_year;
            borrow_month=pborrow->borrow_month;
            borrow_day=pborrow->borrow_day;
            borrow_hour=pborrow->borrow_hour;
            borrow_minute=pborrow->borrow_minute;
            return_year=pborrow->return_year;
            return_month=pborrow->return_month;
            return_day=pborrow->return_day;
            return_hour=pborrow->return_hour;
            return_minute=pborrow->return_minute;
            a=0;
        }
        if(a==0)
        {
            time_t timep;
            struct tm *ptm;
            time (&timep);
            ptm=gmtime(&timep);
            resttime1=((1900+ptm->tm_year-2020)*12*30*24*60+(1+ptm->tm_mon)*30*24*60+ptm->tm_mday*24*60+(8+ptm->tm_hour)*60+ptm->tm_min)-((borrow_year-2020)*12*30*24*60+borrow_month*30*24*60+borrow_day*24*60+borrow_hour*60+borrow_minute);
            if(pborrow->return_year==0)
                resttime=resttime+resttime1;
            else
            {
                resttime2=((1900+ptm->tm_year-2020)*12*30*24*60+(1+ptm->tm_mon)*30*24*60+ptm->tm_mday*24*60+(8+ptm->tm_hour)*60+ptm->tm_min)-((return_year-2020)*12*30*24*60+return_month*30*24*60+return_day*24*60+return_hour*60+return_minute);
                resttime3=resttime1-resttime2;//单次借阅时间
                resttime=resttime+resttime3;
            }
        }
    }
    fclose(fpborrow);
    return resttime;
}
int student_borrow_history(char studentid[20])//学生借阅历史查询
{
    int a=0;
    FILE *fpborrow;
    struct BorrowInfo *pborrow;
    FILE *fp;
    struct BOOK *p;
    char booknum[20];
    fpborrow=fopen("图书借还信息.txt","r");
    if(fpborrow==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    pborrow=(struct BorrowInfo*)malloc(LONGBORROW);
    while(!feof(fpborrow))
    {
        fscanf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,&pborrow->borrow_year,&pborrow->borrow_month,&pborrow->borrow_day,&pborrow->borrow_hour,&pborrow->borrow_minute,&pborrow->return_year,&pborrow->return_month,&pborrow->return_day,&pborrow->return_hour,&pborrow->return_minute,&pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
        if(strcmp(studentid,pborrow->borrow_student_idnum)==0)
        {
            a=1;
            strcpy(booknum,pborrow->borrow_booknum);
            fp=fopen("图书基本信息.txt","r");
            if(fp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
            p=(struct BOOK*)malloc(LONG);
            while(!feof(fp))
            {
                fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
                if(strcmp(booknum,p->booknum)==0)
                {
                    printf("=================================================\n");
                    printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","编号：",p->booknum,"书名：",p->bookname,"单价：",p->price);
                    printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","作者：",p->writer,"出版社：",p->publisher,"出版时间:",p->publishtime);
                    printf("%-8s%s\n\n","图书位置：",p->booklocation);
                    printf("\n\n");
                }
            }
            fclose(fp);
        }
    }
    fclose(fpborrow);
    if(a==0)
    {
        printf("未找到该学生的借阅历史记录\n");
        return 0;
    }
    system("pause");
    return 1;
}
void renew_a_book(char stuID[20])//续借
{
    int z,y,i;//z为1的时候退出该函数
    do
    {
        FILE *fpborrow;
        FILE *fp;
        FILE *fpt;
        struct BOOK *p;
        struct BorrowInfo *pborrow;
        struct teachers *pt;
        char booknum1[20],booknum[20];
        int resttime,borrow_year,borrow_month,borrow_day,borrow_hour,borrow_minute;
        pt=(struct teachers*)malloc(LONGT);
        p=(struct BOOK*)malloc(LONG);
        pborrow=(struct BorrowInfo*)malloc(LONGBORROW);
        z=0;i=0;
        if(borrowtime(stuID)==0)//有超时
        {
            fpborrow=fopen("图书借还信息.txt","r");
            if(fpborrow==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
            while(!feof(fpborrow))//提取打印的书的信息 并打印
            {
                fscanf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,&pborrow->borrow_year,&pborrow->borrow_month,&pborrow->borrow_day,&pborrow->borrow_hour,&pborrow->borrow_minute,&pborrow->return_year,&pborrow->return_month,&pborrow->return_day,&pborrow->return_hour,&pborrow->return_minute,&pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
                if(strcmp(stuID,pborrow->borrow_student_idnum)==0)
                {
                    borrow_year=pborrow->borrow_year;
                    borrow_month=pborrow->borrow_month;
                    borrow_day=pborrow->borrow_day;
                    borrow_hour=pborrow->borrow_hour;
                    borrow_minute=pborrow->borrow_minute;
                    time_t timep;
                    struct tm *ptm;
                    time (&timep);
                    ptm=gmtime(&timep);
                    resttime=((1900+ptm->tm_year-2020)*12*30*24*60+(1+ptm->tm_mon)*30*24*60+ptm->tm_mday*24*60+(8+ptm->tm_hour)*60+ptm->tm_min)-((borrow_year-2020)*12*30*24*60+borrow_month*30*24*60+borrow_day*24*60+borrow_hour*60+borrow_minute);
                    if(resttime>=43200)//输出图书信息
                    {
                        strcpy(booknum1,pborrow->borrow_booknum);
                        fp=fopen("图书基本信息.txt","r");
                        if(fp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
                        while(!feof(fp))
                        {
                            fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
                            if(strcmp(booknum1,p->booknum)==0)
                            {
                                printf("=================================================\n");
                                printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","编号：",p->booknum,"书名：",p->bookname,"单价：",p->price);
                                printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","作者：",p->writer,"出版社：",p->publisher,"出版时间:",p->publishtime);
                                printf("%-8s%s\n\n\n\n","图书位置：",p->booklocation);
                            }
                        }
                        fclose(fp);
                    }
                }
            }
            fclose(fpborrow);
            printf("==========================================================\n\n");
            do
            {
                printf("请输入想续借的图书编号\n");
                scanf("%s",booknum);
                //判断续借次数是否小于等于2
                fpborrow=fopen("图书借还信息.txt","r");
                if(fpborrow==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
                while(!feof(fpborrow))
                {
                    fscanf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,&pborrow->borrow_year,&pborrow->borrow_month,&pborrow->borrow_day,&pborrow->borrow_hour,&pborrow->borrow_minute,&pborrow->return_year,&pborrow->return_month,&pborrow->return_day,&pborrow->return_hour,&pborrow->return_minute,&pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
                    if(strcmp(booknum,pborrow->borrow_booknum)==0&&pborrow->return_year==0&&strcmp(stuID,pborrow->borrow_student_idnum)==0&&pborrow->renew_num<2)//可以续借
                        i=1;
                }
                fclose(fpborrow);
                if(i==1)//更改信息：借书时间->改为现在时间；续借次数加一
                {
                    renew_a_book_change_borrowtime_and_renew_num(stuID,booknum);
                    printf("\n续借成功\n");
                }
                if(i==0)
                {
                    z=1;
                    printf("\n\n这本书已经达到续借上限\n请联系图书管理员，以免账号被冻结\n");
                    fpt=fopen("图书管理员信息.txt","a+");					//打印图书管理员信息
                    if(fpt==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
                    while(!feof(fpt))
                    {
                        fscanf(fpt,"%s %s %s %s\n",pt->idnumber_t,pt->name_t,pt->password_t,pt->mailbox_t);
                        printf("-------------------------------------------\n\n");
                        printf("       姓名          邮箱\n\n");
                        printf("-------------------------------------------\n\n");
                        printf("       %s             %s\n\n",pt->name_t,pt->mailbox_t);
                    }
                    fclose(fpt);
                }
                do
                {
                    printf("\n=========================================================\n");
                    printf("          【1】继续续借         【2】返回上一级\n");
                    printf("\n=========================================================\n");
                    scanf("%d",&y);
                    switch(y)
                    {
                        case 1:
                        {
                            z=0;
                            y=2;
                            break;
                        }
                        case 2:
                        {
                            z=1;
                            system("cls");
                            break;
                        }
                        default://容错
                        {
                            system("cls");
                            printf("输入错误请重新输入\n");
                            break;
                        }
                    }
                }while(y!=2);
            }while(z!=1);
        }
        else
        {
            printf("\n\n===========================================\n");
            printf("              无超时书目，无需办理续借\n");
            printf("\n\n===========================================\n");
            do
            {
                printf("请输入【1】返回上一级");
                scanf("%d",&z);
                switch(z)
                {
                    case 1:
                    {
                        system("cls");
                        break;
                    }
                    default://容错
                    {
                        printf("请重新输入:\n");
                        break;
                    }
                }
            }while(z!=1);
        }
    }while(z!=1);
}
void renew_a_book_change_borrowtime_and_renew_num(char id[50],char booknumber[50])//续借_更改图书借书时间以及续借次数
{
    FILE *fpborrow,*fpborrowtemp;
    struct BorrowInfo *pborrow;
    int a=1;
    fpborrow=fopen("图书借还信息.txt","r");
    if(fpborrow==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    fpborrowtemp=fopen("临时图书借还信息.txt","a+");
    if(fpborrowtemp==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    pborrow=(struct BorrowInfo*)malloc(LONGBORROW);
    time_t timep;
    struct tm *ptm;
    time (&timep);
    ptm=gmtime(&timep);
    while(!feof(fpborrow))
    {
        fscanf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,&pborrow->borrow_year,&pborrow->borrow_month,&pborrow->borrow_day,&pborrow->borrow_hour,&pborrow->borrow_minute,&pborrow->return_year,&pborrow->return_month,&pborrow->return_day,&pborrow->return_hour,&pborrow->return_minute,&pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
        if(strcmp(booknumber,pborrow->borrow_booknum)!=0&&strcmp(id,pborrow->borrow_student_idnum)==0&&pborrow->return_year==0)//先找书号//再找学号//再找年份等于0
            fprintf(fpborrowtemp,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,pborrow->borrow_year,pborrow->borrow_month,pborrow->borrow_day,pborrow->borrow_hour,pborrow->borrow_minute,pborrow->return_year,pborrow->return_month,pborrow->return_day,pborrow->return_hour,pborrow->return_minute,pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
        else
        {
            pborrow->borrow_year=ptm->tm_year+1900;
            pborrow->borrow_month=ptm->tm_mon+1;
            pborrow->borrow_day=ptm->tm_mday;
            pborrow->borrow_hour=ptm->tm_hour+8;
            pborrow->borrow_minute=ptm->tm_min;
            pborrow->renew_num++;
            fprintf(fpborrowtemp,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,pborrow->borrow_year,pborrow->borrow_month,pborrow->borrow_day,pborrow->borrow_hour,pborrow->borrow_minute,pborrow->return_year,pborrow->return_month,pborrow->return_day,pborrow->return_hour,pborrow->return_minute,pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
        }
    }
    fclose(fpborrow);fclose(fpborrowtemp);
    system("del 图书借还信息.txt");
    system("rename 临时图书借还信息.txt 图书借还信息.txt");	//将原文件删除，临时文件改成原文件的名字
}
int borrowtime_booknumber(char idnumber[10])//根据图书编号查询该图书是否超时
{
    int a;
    FILE *fpborrow;
    struct BorrowInfo *pborrow;
    int resttime,borrow_year,borrow_month,borrow_day,borrow_hour,borrow_minute;
    fpborrow=fopen("图书借还信息.txt","r");
    if(fpborrow==NULL){printf("数据库打开错误！请检查……\n");exit(0);}
    pborrow=(struct BorrowInfo*)malloc(LONGBORROW);
    while(!feof(fpborrow))
    {
        a=1;
        fscanf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,&pborrow->borrow_year,&pborrow->borrow_month,&pborrow->borrow_day,&pborrow->borrow_hour,&pborrow->borrow_minute,&pborrow->return_year,&pborrow->return_month,&pborrow->return_day,&pborrow->return_hour,&pborrow->return_minute,&pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
        if(strcmp(idnumber,pborrow->borrow_booknum)==0)//提取借书时间
        {
            borrow_year=pborrow->borrow_year;
            borrow_month=pborrow->borrow_month;
            borrow_day=pborrow->borrow_day;
            borrow_hour=pborrow->borrow_hour;
            borrow_minute=pborrow->borrow_minute;
            a=0;
        }
        if(a==0)
        {
            time_t timep;
            struct tm *ptm;
            time (&timep);
            ptm=gmtime(&timep);
            resttime=((1900+ptm->tm_year-2020)*12*30*24*60+(1+ptm->tm_mon)*30*24*60+ptm->tm_mday*24*60+(8+ptm->tm_hour)*60+ptm->tm_min)-((borrow_year-2020)*12*30*24*60+borrow_month*30*24*60+borrow_day*24*60+borrow_hour*60+borrow_minute);
            if(resttime<43200)
            {
                fclose(fpborrow);
                return 1;//未超期
            }

            else
            {
                fclose(fpborrow);
                return 0;//超期
            }

        }
    }
}
int Students_Favorite_Books_Each_Major()//按专业统计学生最爱的借阅书目
{
    FILE *fp1,*fp2,*fp3;
    int i=0,j=0,k=0,z=0,a=0,t=0,x=0,lendtimes[100];
    char bookname[100][100],major[100][100],y[100],name[10],id[50];
    struct BOOK *p;
    struct students *m;
    struct BorrowInfo *q;
    printf("--------------------------------------------------------------------------\n");
    printf("                                                                          \n");
    printf("                        各个专业学生最爱借阅的书目                        \n\n");
    fp1=fopen("图书基本信息.txt","r");
    while(!feof(fp1))
    {
        p=(struct BOOK*)malloc(LONG);
        fscanf(fp1,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
        a=0;
        for(j=0;j<t;j++)
        {
            if(strcmp(bookname[t],p->bookname)==0)
            {
                a=1;
            }
        }
        if(a==0)
        {
            strcpy(bookname[t],p->bookname);
            t++;
        }
    }
    fclose(fp1);
    fp2=fopen("学生信息.txt","r");
    while(!feof(fp2))
    {
        m=(struct students*)malloc(LONGS);
        fscanf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",m->idnumber,m->school,m->major,m->name,m->gender,m->phonenumber,m->password,m->mailbox,&m->borrow_book_num,&m->if_Frozen);
        a=0;
        for(j=0;j<z;j++)
        {
            if(strcmp(major[j],m->major)==0)
            {
                a=1;
            }
        }
        if(a==0)
        {
            strcpy(major[z],m->major);
            z++;
        }
    }
    fclose(fp2);
    for(j=0;j<z;j++)
    {
        printf("%16s     ",major[j]);
        for(k=0;k<t;k++)//将每本书的统计借阅次数清零
        {
            lendtimes[k]=0;
        }
        fp2=fopen("学生信息.txt","r");
        while(!feof(fp2))
        {
            m=(struct students*)malloc(LONGS);
            fscanf(fp2,"%s %s %s %s %s %s %s %s %d %d\n",m->idnumber,m->school,m->major,m->name,m->gender,m->phonenumber,m->password,m->mailbox,&m->borrow_book_num,&m->if_Frozen);
            if(strcmp(major[j],m->major)==0)//如果该学生专业和目前统计的专业一样
            {
                fp3=fopen("图书借还信息.txt","r");
                while(!feof(fp3))
                {
                    q=(struct BorrowInfo*)malloc(LONGBORROW);
                    fscanf(fp3,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",q->borrow_booknum,q->borrow_bookname,&q->borrow_year,&q->borrow_month,&q->borrow_day,&q->borrow_hour,&q->borrow_minute,&q->return_year,&q->return_month,&q->return_day,&q->return_hour,&q->return_minute,&q->renew_num,q->borrow_student_idnum,q->borrow_student_name);
                    if(strcmp(m->name,q->borrow_student_name)==0)//去借阅信息找该学生借阅情况
                    {
                        for(k=0;k<t;k++)
                        {
                            if(strcmp(bookname[k],q->borrow_bookname)==0)//
                                lendtimes[k]++;
                        }
                    }
                }
                fclose(fp3);
            }
        }
        fclose(fp2);
        for(i=0;i<t-1;i++)
        {
            for(k=t-1;k>i;k--)
            {
                if(lendtimes[k]>lendtimes[k-1])
                {
                    x=lendtimes[k];
                    strcpy(y,bookname[k]);
                    lendtimes[k]=lendtimes[k-1];
                    strcpy(bookname[k],bookname[k-1]);
                    lendtimes[k-1]=x;
                    strcpy(bookname[k-1],y);
                }
            }
        }
        printf("书目名：%8s     借阅次数:%d\n\n",bookname[0],lendtimes[0]);
    }
    printf("\n--------------------------------------------------------------------------\n");
    system("pause");
    return 0;
}
