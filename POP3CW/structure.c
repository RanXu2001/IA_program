//
// Created by 16003 on 2022/5/19.
//

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <time.h>

#define LONG sizeof(struct BOOK)
#define LONGS sizeof(struct students)
#define LONGT sizeof(struct teachers)
#define LONGBUFFER sizeof(struct buffer)
#define LONGBORROW sizeof(struct BorrowInfo)

struct BOOK
{
	char booknum[10];//ͼ����
	char bookname[50];//����
	char writer[20];//����
	float price;//�۸�
	char publisher[50];//������
	char publishtime[50];//��������
	char bookintroduction[100];//ͼ����
	int booksum;//�鱾�ܸ���
	char booklocation[10];//ͼ��λ��
	int lend;//�Ƿ񱻽��ߣ���������1��û������0
	int borrow;//������Ŀ ////////////////////////////////////����
	int lendtimes;//�������
};
struct students
{
	char idnumber[11];//ѧ��
	char school[50];//ѧԺ
	char major[100];//רҵ
	char name[10];//����
	char gender[5];//�Ա�
	char phonenumber[12];//�绰����
	char password[20];//����
	char mailbox[20];//����
	int borrow_book_num; //�Ѿ�����˼�����
	int if_Frozen;//0������1����
};
struct teachers
{
	char idnumber_t[11];//����
	char name_t[10];//����
	char password_t[20];//����
	char mailbox_t[20];//����
};
struct buffer
{
	char idnumber_[11];//���ﳵѧ��
	char booknumber[7];//���ﳵ���
};
struct BorrowInfo
{
	char borrow_booknum[10];//���ߵ���ı��
	char borrow_bookname[100];//���ߵ��������
	int borrow_year;//�������
	int borrow_month;//�����·�
	int borrow_day;//������
	int borrow_hour;//����ʱ
	int borrow_minute;//���߷���
	int return_year;//�������
	int return_month;//�����·�
	int return_day;//������
	int return_hour;//����ʱ
	int return_minute;//�����
	int renew_num;//�������
	char borrow_student_idnum[20];//�������ѧ����ѧ��
	char borrow_student_name[10];//�������ѧ��������
};

void Displaymainmenu();//��ʾ���˵�
void Displaystudentmenu();//��ʾѧ���˵�
void Displayteachermenu();//��ʾ��ʦ�˵�
void DisplayBORROWmenu(); //��ʾ����˵�
void DisplayBOOKMANAGEmenu();//��ʾͼ�����˵�
void DisplayBOOKsearchmenu();//��ʾͼ���ѯ�˵�
void Display_loan_management();//��ʾ���Ĺ���˵�
void Display_student_book_searchmenu();//��ʾѧ��ͼ���ѯ�˵�
void Display_check_borrowing_status();//��ʾ����������˵�
void Display_loan_account_management();//��ʾ�����˻�����˵�
void Display_tongjijieyuexinxipaixu();//��ʾͳ�ƽ�����Ϣ����˵�
int Check_studentid();//ѧ����¼�˵�
int Check_teacherid();//ͼ�����Ա��½�˵�
void BORROW(char[]); //����ģ��
int borrow_buffer(char[]); //����_���ﳵ
void borrow_buffer_change_lend(char[]);//����_���ﳵ_����ͼ��lend������״̬��
int borrow_borrow(char[]);//����_��ʽ���
void borrow_borrow_load(char[],char[]);//����_��ʽ���_�����ļ���Ϣ
void borrow_borrow_delet(char[],char[]);//����_��ʽ���_ɾ�����ﳵ��¼
void borrow_borrow_change_borrow_book_num(char[]);//����_ ��ʽ���_����ѧ�����ͼ������
void borrow_borrow_change_lendtime(char[]);//����_��ʽ���_ ����ͼ�鱻�����
int borrowtime(char[]);//��ѧ���ж��Ƿ�ʱ��ʱ0������ʱ1
void renew(char[]);//����
int Return(char[]);//����
void Return_change_lend(char[]);//����_����ͼ��lend������״̬��
void Return_change_return_date(char[],char[]);//����_����_��������
void Return_change_borrow_book_num(char[]);//����_����_ѧ�����ͼ������
void teacher_enrolment(void); //ͼ�����Աע��
void student_enrolment(void);//ѧ��ע��
int idnumbervalidation(char[]);//ѧ��/���Ÿ�ʽ�ж�
int phonenumbervalidation(char[]);//�绰�����ʽ�ж�
int mailboxvalidation(char[]);//�����ʽ�ж�
int booknumbervalidation(char[]);//ͼ���Ÿ�ʽ�ж�
void teacherinfo_management(char[]);//ͼ�����Ա������Ϣ����
void studentinfo_management(char[]);//ѧ��������Ϣ����
void deleteborrowinfo(char[]);//ɾ�����ﳵ��¼
int search_by_name();//ͨ��������ѯ
int search_by_writername();//ͨ�����߲�ѯ
int search_by_press();//ͨ���������ѯ
int book_add();//���ͼ��
int book_delete();//ɾ��ͼ��
int update();//����ͼ��
int Borrow_Time_Overdue_Book_Situation();//��ʱδ��ͼ��
int Borrow_Time_Overdue_Students_Situation();//��ʱδ����Ϊѧ��
int Borrow_Time_Overdue_Frozen();//����ѧ���˺�
int Borrow_Time_Overdue_Frozen1();//�ⶳѧ���˺�
void Frozen_Account(char[]);//����_�޸�Frozen
void Frozen_Account1(char[]);//�ⶳ_�޸�Frozen
int BOOK_Borrow_situation();//ͼ����������ѯ
int Search_By_Student_Name_Or_Title();//ͨ��ѧ��������������ѯ
int Sort_borrow_number();//ͨ�����Ĵ�������
int Sort_borrow_time();//ͨ������ʱ�䳤������
int Sort_By_Book_Price();//ͨ���۸�����
int bookname_borrowtime(char[]);//�����ÿһ����Ľ�����ʱ��
int student_borrow_history(char[]);//ѧ��������ʷ��ѯ
void renew_a_book(char[]);//����
void renew_a_book_change_borrowtime_and_renew_num(char[],char[]);//����_����ͼ�����ʱ���Լ��������
int borrowtime_booknumber(char[]);//�Ե����鱾�ж��Ƿ�ʱ��ʱ0������ʱ1
int Students_Favorite_Books_Each_Major();//��רҵͳ��ѧ����Ľ�����Ŀ

char STUDENTID[20];
char TEACHERID[20];

int main()
{
	int a,b,b1,c,d,e,e1,f,f1,f2,f3;
	printf("\n==========================================================================\n");
	printf("\n                         ��ӭʹ��ͼ�����ϵͳ\n");
	printf("                              �����ȵ�¼ϵͳ\n");
	printf("\n==========================================================================\n\n\n");
	//��ʼ���湦��
	do
	{
		Displaymainmenu();
		scanf("%d",&a);
		switch(a)
		{
			case 1://ѧ��	��¼
			{
				system("cls");
				if(Check_studentid()==0)
				{
					printf("�����µ�¼\n");
					break;
				}
				else//��½�ɹ�
				{
					do
					{
//						system("cls");
						Displaystudentmenu();//ѧ���˵�
						scanf("%d",&b);
						switch(b)
						{
							case 1://���� ok
							{
								system("cls");
								BORROW(STUDENTID);
								system("cls");
								break;
							}
							case 2://���� ok
							{
								system("cls");
								renew_a_book(STUDENTID);
								break;
							}
							case 3://��ѯͼ�� ok
							{
								do
								{
									system("cls");
									Display_student_book_searchmenu();//ѧ��ͼ���ѯ�˵�
									scanf("%d",&b1);
									switch(b1)
									{
										case 1://����������ѯ ok
										{
											if(search_by_name()==0)
											{
												printf("����������\n");
												break;
											}
										}
										case 2://�������߲�ѯ ok
										{
											if(search_by_writername()==0)
											{
												printf("����������\n");
												break;
											}
										}
										case 3://���ݽ��Ĵ������� ok
										{
											if(Sort_borrow_number()==0)
											{
												system("cls");
												break;
											}
											break;
										}
										case 4://���ݼ۸���������ͼ�� ok
										{
											if(Sort_By_Book_Price()==0)
											{
												system("cls");
												break;
											}
											break;
										}
										case 5://������һ��
										{
											system("cls");
											break;
										}
										default://�ݴ�
										{
											system("cls");
											printf("\n\n�����������������ѡ��\n\n");
											break;
										}
									}
								}while(b1!=5);
							break;
							}
							case 4://��ѯ���Ľ�� ok
							{
								system("cls");
								if(student_borrow_history(STUDENTID)==0)
								{
									//system("cls");
									break;
								}
								system("cls");
								break;
							}
							case 5://ɾ��������Ϣ ok
							{
								system("cls");
								deleteborrowinfo(STUDENTID);
								break;
							}
							case 6://������Ϣ���� ok
							{
								system("cls");
								studentinfo_management(STUDENTID);
								break;
							}
							case 7://���� ok
							{
								if(Return(STUDENTID)==0)
								{
									printf("����������\n");
									break;
								}
							}
							case 8://������һ��
							{
								system("cls");
								break;
							}
							case 0://�˳�
							{
								system("cls");
								printf("----------------------------------------\n");
								printf("       -= ��лʹ�ã��ټ��� =- \n");
								printf("----------------------------------------\n");
								exit(0);
							}
							default://�ݴ�
							{
								system("cls");
								printf("\n\n�����������������ѡ��\n\n");
								break;
							}
						}
					}
					while(b!=8);
				}
			break;
			}
			case 2://ͼ�����Ա	��¼ ok
			{
				system("cls");
				if(Check_teacherid()==0)
				{
					printf("�����µ�¼\n");
					break;
				}
				else
				{
					do
					{
						Displayteachermenu();
						scanf("%d",&c);
						switch(c)
						{
							case 1://ͼ����� ok
							{
								do
								{
									system("cls");
									DisplayBOOKMANAGEmenu();
									scanf("%d",&d);
									switch(d)
									{
										case 1://ͼ���ѯ ok
										{
											system("cls");
											do
											{
												DisplayBOOKsearchmenu();
												scanf("%d",&e);
												switch(e)
												{
													case 1://������ѯ
													{
														if(search_by_name()==0)
														{
															printf("����������\n");
															break;
														}
													}
													case 2://�������ѯ
													{
														if(search_by_press()==0)
														{
															printf("����������\n");
															break;
														}
													}
													case 3:
													{
														system("cls");
														break;
													}
													default://�ݴ�
													{
														system("cls");
														printf("\n\n�����������������ѡ��\n\n");
														break;
													}
												}
											}while(e!=3);
											break;
										}
										case 2://���ͼ�� ok
										{
											if(book_add()==0)
											{
												printf("����������\n");
												break;
											}
										}
										case 3://�޸�ͼ��ok
										{
											if(update()==0)
											{
												printf("����������\n");
												break;
											}
										}
										case 4://������һ��
										{
											system("cls");
											break;
										}
										default://�ݴ�
										{
											system("cls");
											printf("\n\n�����������������ѡ��\n\n");
											break;
										}
									}
								}while(d!=4);
							break;
							}
							case 2://ɾ��ͼ�� ok
							{
								system("cls");
								if(book_delete()==0)
								{
									printf("����������\n");
									break;
								}
							}
							case 3://���Ĺ��� ok
							{
								system("cls");
								do
								{
									system("cls");
									Display_loan_management();
									scanf("%d",&f);
									switch(f)
									{
										case 1://��ѯ������� ok
										{
											do
											{
												system("cls");
												Display_check_borrowing_status();
												scanf("%d",&f1);
												switch(f1)
												{
													case 1://���������ѯ ok
													{
														system("cls");
														if(BOOK_Borrow_situation()==0)
														{
															break;
														}
													}
													case 2://����ѧ��������������ѯ ok
													{
														if(Search_By_Student_Name_Or_Title()==0)
														{
															break;
														}
													}
													case 3://��ѯ����δ��ͼ����� ok
													{
														system("cls");
														if(Borrow_Time_Overdue_Book_Situation()==0)
														{
															break;
														}
													}
													case 4://��ѯ����δ��ѧ������ ok
													{
														system("cls");
														if(Borrow_Time_Overdue_Students_Situation()==0)
														{
															break;
														}
													}
													case 5://������һ��
													{
														system("cls");
														break;
													}
													default://�ݴ�
													{
														system("cls");
														printf("\n\n�����������������ѡ��\n\n");
														break;
													}
												}
											}while(f1!=5);
											break;
										}
										case 2://�����˻�����  ok
										{
											do
											{
												system("cls");
												Display_loan_account_management();
												scanf("%d",&f2);
												switch(f2)
												{
													case 1://�˺Ŷ��� ok
													{
														if(Borrow_Time_Overdue_Frozen()==0)
														{
															system("cls");
															printf("����������\n");
															break;
														}
													}
													case 2://�˺Žⶳ ok
													{
														if(Borrow_Time_Overdue_Frozen1()==0)
														{
															system("cls");
															printf("����������\n");
															break;
														}
													}
													case 3://������һ��
													{
														system("cls");
														break;
													}
													default://�ݴ�
													{
														system("cls");
														printf("\n\n�����������������ѡ��\n\n");
														break;
													}
												}
											}while(f2!=3);
											break;
										}
										case 3://������һ��
										{
											system("cls");
											break;
										}
										default://�ݴ�
										{
											system("cls");
											printf("\n\n�����������������ѡ��\n\n");
											break;
										}
									}
								}while(f!=3);
								break;
							}
							case 4://ͳ�ƽ�����Ϣ ���� ok
							{
								do
								{
									system("cls");
									Display_tongjijieyuexinxipaixu();
									scanf("%d",&f3);
									switch(f3)
									{
										case 1://������ʱ�䳤����������ͼ��
										{
											if(Sort_borrow_time()==0)
											{
												system("cls");
												break;
											}
										}
										case 2://���ս��Ĵ������������ڹ�ͼ��
										{
											if(Sort_borrow_number()==0)
											{
												system("cls");
												break;
											}
										}
										case 3://��רҵͳ��ѧ����Ľ�����Ŀ////
										{
											if(Students_Favorite_Books_Each_Major()==0)
											{
												system("cls");
												break;
											}
										}
										case 4://������һ��
										{
											system("cls");
											break;
										}
									}
								}while(f3!=4);
								break;
							}
							case 5://������Ϣ���� ok
							{
								system("cls");
								teacherinfo_management(TEACHERID);
								break;
							}
							case 6://������һ��
							{
								system("cls");
								break;
							}
							case 0:
							{
								system("cls");
								printf("----------------------------------------\n");
								printf("       -= ��лʹ�ã��ټ��� =- \n");
								printf("----------------------------------------\n");
								exit(0);
							}
							default://�ݴ�
							{
								system("cls");
								printf("\n\n�����������������ѡ��\n\n");
								break;
							}
						}
					}while(c!=6);
				}
			break;
			}
			case 0:
			{
				system("cls");
				printf("----------------------------------------\n");
				printf("       -= ��лʹ�ã��ټ��� =- \n");
				printf("----------------------------------------\n");
				exit(0);
			}
			default://�ݴ�
			{
				system("cls");
				printf("\n\n�����������������ѡ��\n\n");
				break;
			}
		}
	}
	while(a!=0);
	return 0;
}
void Displaymainmenu()//��ʾ���˵�
{
	printf("--------------------------------------------------------------------------\n\n");
	printf("                              ������ѡ���ţ�0~2��                       \n\n");
	printf("--------------------------------------------------------------------------\n\n");
	printf("                                ͼ�����ϵͳ                              \n\n\n");
	printf("                         1 ������ѧ����ݵ�¼                     		  \n\n");
	printf("                         2 ������ͼ�����Ա��ݵ�¼                       \n\n");
	printf("                         0 �����˳�                                	      \n\n");
	printf("               ��Ȩ@2020�����ʵ��ѧ**����ѧԺ**���Ź��̼�����            \n");
	printf("--------------------------------------------------------------------------\n");
	printf("��ѡ������ʹ�õĹ��ܣ�\n");
}

void Displaystudentmenu()//��ʾѧ���˵�
{
	printf("--------------------------------------------------------------------------\n\n");
	printf("                              ������ѡ���ţ�0~8��                       \n\n");
	printf("--------------------------------------------------------------------------\n\n");
	printf("                                ѧ���˹���                                \n\n\n");
	printf("                         1 ��������             	 	 				  \n\n");
	printf("                         2 ��������                     				  \n\n");
	printf("                         3 ������ѯͼ��                					  \n\n");
	printf("                         4 ������ѯ���Ľ��                               \n\n");
	printf("                         5 ����ɾ��������Ϣ                               \n\n");
	printf("                         6 ����������Ϣ����                               \n\n");
	printf("                         7 ��������             	 	 				  \n\n");
	printf("                         8 ����������һ��                                 \n\n");
	printf("                         0 �����˳�             	 	 				  \n\n");
	printf("--------------------------------------------------------------------------\n");
	printf("��ѡ��");
}
void Displayteachermenu()//��ʾ��ʦ�˵�
{
	printf("--------------------------------------------------------------------------\n\n");
	printf("                          ������ѡ���ţ�0~6��                           \n\n");
	printf("--------------------------------------------------------------------------\n\n");
	printf("                            ͼ�����Ա�˹���                              \n\n\n");
	printf("                         1 ����ͼ�����             	 	 			  \n\n");
	printf("                         2 ����ɾ��ͼ��                     			  \n\n");
	printf("                         3 �������Ĺ���                					  \n\n");
	printf("                         4 ����ͳ�ƽ�����Ϣ                               \n\n");
	printf("                         5 ����������Ϣ����                               \n\n");
	printf("                         6 ����������һ��                                 \n\n");
	printf("                         0 �����˳�                                       \n\n");
	printf("--------------------------------------------------------------------------\n");
	printf("��ѡ��");
}
void Displayborrowmenu()//��ʾ����˵�
{
	printf("--------------------------------------------------------------------------\n\n");
	printf("                          ������ѡ���ţ�1~3��                           \n\n");
	printf("--------------------------------------------------------------------------\n\n");
	printf("                            ����ͼ�鹦��                   	              \n\n\n");
	printf("                         1 ����ѡ����빺�ﳵ          	 	 			  \n\n");
	printf("                         2 �����鿴���ﳵ                     			  \n\n");
	printf("                         3 ����������һ��              					  \n\n");
	printf("--------------------------------------------------------------------------\n");
	printf("��ѡ��");
}
void DisplayBOOKMANAGEmenu()//��ʾͼ�����˵�
{
	printf("--------------------------------------------------------------------------\n\n");
	printf("                          ������ѡ���ţ�1~4��                           \n\n");
	printf("--------------------------------------------------------------------------\n\n");
	printf("                            ͼ�������                   	              \n\n\n");
	printf("                         1 ����ͼ���ѯ             	 	 			  \n\n");
	printf("                         2 �������ͼ��                     			  \n\n");
	printf("                         3 �����޸�ͼ��             					  \n\n");
	printf("                         4 ����������һ��             					  \n\n");
	printf("--------------------------------------------------------------------------\n");
	printf("��ѡ��");
}
void DisplayBOOKsearchmenu()//��ʾͼ���ѯ�˵�
{
	printf("--------------------------------------------------------------------------\n\n");
	printf("                          ������ѡ���ţ�1~3��                           \n\n");
	printf("--------------------------------------------------------------------------\n\n");
	printf("                            ��ѯͼ�鹦��                   	              \n\n\n");
	printf("                         1 ��������������ѯ          	 	 			  \n\n");
	printf("                         2 �������ݳ������ѯ                  			  \n\n");
	printf("                         3 ����������һ��              					  \n\n");
	printf("--------------------------------------------------------------------------\n");
	printf("��ѡ��");
}
void Display_student_book_searchmenu()//��ʾѧ��ͼ���ѯ�˵�
{
	printf("--------------------------------------------------------------------------\n\n");
	printf("                          ������ѡ���ţ�1~5��                           \n\n");
	printf("--------------------------------------------------------------------------\n\n");
	printf("                            ͼ���ѯ����                   	              \n\n\n");
	printf("                         1 ��������������ѯ            	 	 			  \n\n");
	printf("                         2 �����������߲�ѯ                    			  \n\n");
	printf("                         3 �������ݽ��Ĵ�����ѯ        					  \n\n");
	printf("                         4 �������ݼ۸�������Ŀ       					  \n\n");;
	printf("                         5 ����������һ��             					  \n\n");
	printf("--------------------------------------------------------------------------\n");
	printf("��ѡ��");
}
void Display_loan_management() //��ʾ���Ĺ���˵�
{
	printf("--------------------------------------------------------------------------\n\n");
   	printf("                             ������ѡ���ţ�1~3��                        \n\n");
	printf("--------------------------------------------------------------------------\n\n");
	printf("                            ���Ĺ�����                   	              \n\n\n");
   	printf("                          1 �����鿴�������                     	      \n\n");
   	printf("                          2 ���������˻�����                              \n\n");
	printf("                          3����������һ��             					  \n\n");
   	printf("--------------------------------------------------------------------------\n");
	printf("�����룺");
}
void Display_check_borrowing_status()//��ʾ����������˵�
{
	printf("--------------------------------------------------------------------------\n\n");
   	printf("                             ������ѡ���ţ�1~5��                        \n\n");
	printf("--------------------------------------------------------------------------\n\n");
   	printf("                          1 ������ѯ����ͼ��Ľ������                    \n\n");
   	printf("                          2 ������ѯ����ͼ���ѧ����Ϣ                    \n\n");
   	printf("                          3 ������ѯ����δ��ͼ�����                      \n\n");
   	printf("                          4 ������ѯ����δ��ѧ������                      \n\n");
    printf("                          5 ���������ϼ��˵�                              \n\n");
   	printf("--------------------------------------------------------------------------\n");
	printf("�����룺");
}
void Display_loan_account_management()//��ʾ�����˻�����˵�
{
	printf("--------------------------------------------------------------------------\n\n");
   	printf("                             ������ѡ���ţ�1~3��                        \n\n");
	printf("--------------------------------------------------------------------------\n\n");
   	printf("                         1 ���������г���δ��ͼ����˻�                   \n\n");
   	printf("                         2 �����黹ͼ���ⶳ�˻�                         \n\n");
    printf("                         3 ���������ϼ��˵�                               \n\n");
   	printf("--------------------------------------------------------------------------\n");
	printf("�����룺");
}
void Display_tongjijieyuexinxipaixu()//��ʾͳ�ƽ�����Ϣ����˵�
{
	printf("--------------------------------------------------------------------------\n\n");
   	printf("                             ������ѡ���ţ�1~4��                        \n\n");
	printf("--------------------------------------------------------------------------\n\n");
   	printf("                         1 ����������ʱ�䳤����������ͼ��                 \n\n");
   	printf("                         2 �������ս��Ĵ������������ڹ�ͼ��               \n\n");
   	printf("                         3 ������רҵͳ��ѧ����Ľ�����Ŀ               \n\n");
    printf("                         4 ���������ϼ��˵�                               \n\n");
   	printf("--------------------------------------------------------------------------\n");
	printf("�����룺");
}
int Check_studentid()//ѧ����¼
{
	FILE *fps;
	FILE *fpt;
	char idnumber[10],password[10];
	struct students *ps;
	struct teachers *pt;
	int a=0,b;//a�ǿ���û�����ѧ��
	printf("������ѧ���ţ�\n");
	scanf("%s",idnumber);
	printf("������ѧ�����롾��ʼ����Ϊѧ���š�:\n");
	scanf("%s",password);
	fps=fopen("ѧ����Ϣ.txt","a+");
	if(fps==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	ps=(struct students*)malloc(LONGS);
	while(!feof(fps))
	{
		fscanf(fps,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,&ps->borrow_book_num,&ps->if_Frozen);
		if(strcmp(idnumber,ps->idnumber)==0)
		{
			a=1;
			if(ps->if_Frozen==1)///�����˺�
			{
				system("cls");
				printf("�����ʺ��Ѿ������ᣬ����ϵͼ�����Ա��ѯ\n");///��ӡ����Ա��Ϣ ���� ����
				fpt=fopen("ͼ�����Ա��Ϣ.txt","a+");
				if(fpt==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
				pt=(struct teachers*)malloc(LONGT);
				while(!feof(fpt))
				{
					fscanf(fpt,"%s %s %s %s\n",pt->idnumber_t,pt->name_t,pt->password_t,pt->mailbox_t);
					printf("-------------------------------------------\n\n");
					printf("       ����          ����\n\n");
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
					printf("��½�ɹ�����ӭʹ��%s\n",ps->name);
					strcpy(STUDENTID,idnumber);
					fclose(fps);
					return 1;
				}
				else
				{
					system("cls");
					printf("�������\n");
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
		printf("δ���ҵ�����ѧ����\n"); //////ע��
		printf("�Ƿ�ע���ʺ�1\n1)ע��\n2)��ע��\n");
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
int Check_teacherid()//ͼ�����Ա��¼
{
	FILE *fpt;
	char idnumber_t[10],password_t[10];
	struct teachers *pt;
	int a=0;//a�ǿ���û�������ʦ
	printf("�����빤�ţ�\n");
	scanf("%s",idnumber_t);
	printf("������ͼ�����Ա���롾��ʼ����Ϊ���š�:\n");
	scanf("%s",password_t);
	fpt=fopen("ͼ�����Ա��Ϣ.txt","a+");
	if(fpt==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
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
				printf("��½�ɹ�����ӭʹ��%s\n",pt->name_t);
				strcpy(TEACHERID,idnumber_t);
				fclose(fpt);
				return 1;
			}
			else
			{
				system("cls");
				printf("�������\n");
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
		printf("δ���ҵ����Ĺ���\n"); //ע��
		printf("�Ƿ�ע���ʺ�1\n1)ע��\n2)��ע��\n");
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
void BORROW(char ID[20])//����
{
	 int a;
	 do
	 {
 		Displayborrowmenu();
 		scanf("%d",&a);
 		system("cls");
	 	switch(a)
	 	{
	 		case 1://ѡ����빺�ﳵ
	 		{
	 			if(borrow_buffer(ID)==0)
	 			{
			 		printf("������ѡ��\n");
					break;
			 	}
		 	}
	 		case 2://�鿴���ﳵ
	 		{
		 		if(borrow_borrow(ID)==0)
		 		{
		 			printf("������ѡ��\n");
		 			break;
		 		}
		 	}
	 		case 3://������һ��
		 	{
 				system("cls");
 				break;
 			}
	 		default://�ݴ�
			{
				system("cls");
				printf("\n\n�����������������ѡ��\n\n");
				break;
			}
	 	}
 	 }
	 while(a!=3);
}
int borrow_buffer(char Id[20])//����_���ﳵ
{
	FILE *fp,*fps,*fpbuffer;
	char bookname[50],booknum[50],idnumber[50],date[50];
	struct BOOK *p;
	struct students *ps;
	struct buffer *pbuffer;
	int a,as,ab,b,c,d,e,f,count;//a����û���Ȿ��,as����û�����ѧ��,ab����û��������
	do
	{
		a=0;as=0;ab=0;b=0;c=0;d=0;e=0;f=0;count=0;
		printf("--------------------------------------------------------------------------\n");
		printf("                              ��ӭʹ�ù��ﳵ                              \n");
		printf("                          					                              \n");
		printf("                         ������������ĵ��鼮����                         \n");
		printf("--------------------------------------------------------------------------\n");
		printf("������������");
		scanf("%s",bookname);
		fp=fopen("ͼ�������Ϣ.txt","r");
		if(fp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
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
					printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","��ţ�",p->booknum,"������",p->bookname,"���ۣ�",p->price);
					printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","���ߣ�",p->writer,"�����磺",p->publisher,"����ʱ��:",p->publishtime);
					printf("%-8s%s\n\n\n\n","ͼ��λ�ã�",p->booklocation);
					count=1;
				}
			}
		}
		fclose(fp);
		if(a==0)
		{
			system("cls");
			printf("\a\n δ�ҵ������������ͼ��,�������²��� \n\n");
			printf("=====================================================================\n");
			printf("			�Ƿ�������������鼮             \n");
			printf("		��1����������		��2��������һ��      \n");
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
				default://�ݴ�
				{
					system("cls");
					printf("\n\n�����������������ѡ��\n\n");
					break;
				}
			}
		}
		if(count==0)
		{
			printf("ʮ�ֱ�Ǹ�������ѱ�ȫ����������ɽ���\n");
			printf("=====================================================================\n");
			printf("			�Ƿ�������������鼮             \n");
			printf("		��1����������		��2��������һ��      \n");
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
				default://�ݴ�
				{
					system("cls");
					printf("\n\n�����������������ѡ��\n\n");
					break;
				}
			}
		}
		if(count==1)//��ʽ��ȡ
		{
			do
			{
				printf("=====================================================================\n");
				printf("                  ������ͼ���Ž�������빺�ﳵ             \n");
				printf("=====================================================================\n");
				scanf("%s",booknum);
				fp=fopen("ͼ�������Ϣ.txt","r");
				if(fp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
				while(!feof(fp))
				{
					fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
					if(strcmp(booknum,p->booknum)==0)
					ab=1;
				}
				fclose(fp);
				if(ab==0)
				{
					printf("\nͼ���������������������\n");
					d=1;
				}
				else
				{
					do
					{
						fps=fopen("ѧ����Ϣ.txt","r");
						if(fps==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
						ps=(struct students*)malloc(LONGS);
						while(!feof(fps))
						{
							fscanf(fps,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,&ps->borrow_book_num,&ps->if_Frozen);
							if(strcmp(Id,ps->idnumber)==0) //�鿴��ͬѧ���˼�����
							as=1;
						}
						fclose(fps);
						if(as==0)
						{
							printf("\n�����������������\n");
							e=1;
						}
						else//¼��
						{
							fpbuffer=fopen("���ﳵ.txt","a+");
							if(fpbuffer==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
							pbuffer=(struct buffer*)malloc(LONGBUFFER);
							strcpy(pbuffer->idnumber_,Id);
							strcpy(pbuffer->booknumber,booknum);
							fprintf(fpbuffer,"%s %s\n",pbuffer->idnumber_,pbuffer->booknumber);
							fflush(fpbuffer);
							fclose(fpbuffer);
							borrow_buffer_change_lend(booknum);//lend���1
							printf("�ɹ����빺�ﳵ\n");
							printf("=====================================================================\n");
							printf("			�Ƿ�������������鼮             \n");
							printf("		��1����������		��2��������һ��      \n");
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
								default://�ݴ�
								{
									system("cls");
									fclose(fps);
									printf("\n\n�����������������ѡ��\n\n");
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
int borrow_borrow(char Id[20])//����_��ʽ���_ ����ͼ�鱻�����
{
	FILE *fp,*fps,*fpbuffer,*fpborrow;
	char bookname[50],booknum[50],idnumber[50];
	struct BOOK *p;
	struct students *ps;
	struct buffer *pbuffer;
	struct BorrowInfo *pborrow;
	int a=0,b,c=0,d,e,f=0,count;//a����û�й��ﳵ��Ϣ
	do
	{
		a=0;c=0;d=0;f=0;e=0;count=0;
		printf("--------------------------------------------------------------------------\n");
		printf("                              ��ӭ�鿴���ﳵ                              \n");
		printf("                          					                              \n");
		printf("--------------------------------------------------------------------------\n");
		fpbuffer=fopen("���ﳵ.txt","a+");
		if(fpbuffer==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
		pbuffer=(struct buffer*)malloc(LONGBUFFER);
		while(!feof(fpbuffer))
		{
			fscanf(fpbuffer,"%s %s\n",pbuffer->idnumber_,pbuffer->booknumber);
			if(strcmp(Id,pbuffer->idnumber_)==0)
			{
				a=1;//�й��ﳵ��Ϣ
				fp=fopen("ͼ�������Ϣ.txt","r");
				if(fp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
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
				printf("\n	ѧ����         ͼ����            �鱾����\n");
				printf("\n---------------------------------------------------------------------\n");
				printf("\n	%-10s	%-12s%12s\n\n",Id,pbuffer->booknumber,bookname);
				printf("\n---------------------------------------------------------------------\n\n");
			}
		}
		fclose(fpbuffer);
		if(a==0)//û�и�ѧ��������Ϣ
		{
			system("cls");
			printf("\a\n δ�ҵ���ѧ���Ĺ��ﳵ��Ϣ,�������²��� \n\n");
			printf("\n=====================================================================\n");
			printf("			��1��������һ��      \n");
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
				default://�ݴ�
				{
					system("cls");
					fclose(fps);
					printf("\n\n�����������������ѡ��\n\n");
					break;
				}
			}
		}
		else//ѯ���Ƿ���ʽ���
		{
			do
			{
				printf("\n\n=====================================================================\n");
				printf("				�Ƿ���ͼ��             \n");
				printf("			��1����		��2����      \n");
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
					default://�ݴ�
					{
						system("cls");
						printf("\n\n�����������������ѡ��\n\n");
						break;
					}
				}
				do//�鿴��ѧ���Ƿ������������ ��3��������ʱ����
				{
					printf("������������ͼ���ͼ���ţ�\n");
					scanf("%s",booknum);
					if(count>=3)//�Ѿ�һ���Խ�������
					{
						e=1;
						system("cls");
						printf("\n����ֻ����ѧ��һ�������������������Ѵﵽ����\n");
						return 0;
					}
					else
					{
		 				fps=fopen("ѧ����Ϣ.txt","r");
						if(fps==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
						ps=(struct students*)malloc(LONGS);
						while(!feof(fps))//����Լ������Ѿ��ﵽ����
						{
							fscanf(fps,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,&ps->borrow_book_num,&ps->if_Frozen);
							if(strcmp(Id,ps->idnumber)==0)
							{
								if(ps->borrow_book_num>=3)
								{
									fclose(fps);
									e=1;
									system("cls");
									printf("\n����ֻ����ѧ������������ͼ�飬���Ѵﵽ����\n");
									return 0;
								}
								else//�ж��Ƿ���ڳ�ʱ
								{
									if(borrowtime(Id)==0)
									{
										fclose(fps);
										e=1;
										system("cls");
										printf("\n��������Ҫ���裬��ȥѧ���������������\n");
										return 0;
									}
									else////�ϸ��û� ������� (�޳����ﳵ�����Ϣ�����뵽������Ϣ�ļ����¼��ǰʱ��)
									{
										fclose(fps);
										borrow_borrow_load(Id,booknum);
										printf("�ɹ��������ף���Ķ����\n\n");
										printf("=====================================================================\n");
										printf("			�Ƿ�������������鼮             \n");
										printf("		��1����������		��2��������һ��      \n");
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
											default://�ݴ�
											{
												system("cls");
												printf("\n\n�����������������ѡ��\n\n");
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
void borrow_borrow_load(char idnum[50],char booknumber[50])//����_��ʽ���_�����ļ���Ϣ
{
	FILE *fp,*fps,*fpbuffer,*fpborrow;
	char bookname[50],name[50];
	int a,b,i=0,j=0;
	struct BOOK *p;
	struct students *ps;
	struct buffer *pbuffer;
	struct BorrowInfo *pborrow;
	fp=fopen("ͼ�������Ϣ.txt","r");//��ȡ�����Լ�ѧ������	///����
	if(fp==NULL){printf("1���ݿ�򿪴������顭��\n");exit(0);}
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
	fps=fopen("ѧ����Ϣ.txt","r");	///ѧ������
	if(fps==NULL){printf("2���ݿ�򿪴������顭��\n");exit(0);}
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
 	time_t timep;//��ȡ����ʱ��
  	struct tm *ptm;
   	time (&timep);
    ptm=gmtime(&timep); 	//¼���������Ϣ
	fpborrow=fopen("ͼ��軹��Ϣ.txt","a+");
	if(fpborrow==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
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
	borrow_borrow_change_lendtime(booknumber);//�鱾����������+1
	borrow_borrow_delet(idnum,booknumber);	//ɾ�����ﳵ�����Ϣ
	fclose(fps);
	borrow_borrow_change_borrow_book_num(idnum);//ѧ��������+1
}
int borrowtime(char idnumber[50])//1 ���� 0 ������
{
	FILE *fpborrow;
	struct BorrowInfo *pborrow;
	int a,resttime,borrow_year,borrow_month,borrow_day,borrow_hour,borrow_minute;
	fpborrow=fopen("ͼ��軹��Ϣ.txt","a+");
	if(fpborrow==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	pborrow=(struct BorrowInfo*)malloc(LONGBORROW);
	while(!feof(fpborrow))
	{
		a=1;
		fscanf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,&pborrow->borrow_year,&pborrow->borrow_month,&pborrow->borrow_day,&pborrow->borrow_hour,&pborrow->borrow_minute,&pborrow->return_year,&pborrow->return_month,&pborrow->return_day,&pborrow->return_hour,&pborrow->return_minute,&pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
		if(strcmp(idnumber,pborrow->borrow_student_idnum)==0)//��ȡ����ʱ��
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
				return 1;//δ����
			}
			else
			{
				fclose(fpborrow);
				return 0;//����
			}
		}
	}
	fclose(fpborrow);
}
void borrow_borrow_delet(char idnum[50],char booknum[50])//����_��ʽ���_ɾ�����ﳵ��¼
{
	FILE *fpbuffer,*fpbuffertemp;
	struct buffer *pbuffer;
	fpbuffer=fopen("���ﳵ.txt","r");
	if(fpbuffer==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	fpbuffertemp=fopen("��ʱ���ﳵ.txt","a+");
	if(fpbuffer==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	pbuffer=(struct buffer*)malloc(LONGBUFFER);
	while(!feof(fpbuffer))//studentnum:ѧ����,recordnum:buffer��Ĵ�����
	{

	    fscanf(fpbuffer,"%s %s\n",pbuffer->idnumber_,pbuffer->booknumber);
	    if(strcmp(pbuffer->idnumber_,idnum)!=0)//��������Ҫ������
   		fprintf(fpbuffertemp,"%s %s\n",pbuffer->idnumber_,pbuffer->booknumber);
	    else    //������Ҫ������,������֤enter�ı�����ǲ�����ȷ���������ȷ����Ҳ���뵽��ʱ�ļ���
	    {
			if(strcmp(pbuffer->booknumber,booknum)!=0)
			fprintf(fpbuffertemp,"%s %s\n",pbuffer->idnumber_,pbuffer->booknumber);
	    }
	}
    fclose(fpbuffer);fclose(fpbuffertemp);
    system("del ���ﳵ.txt");
    system("rename ��ʱ���ﳵ.txt ���ﳵ.txt");	//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
}
void borrow_buffer_change_lend(char booknumer[50])//����_���ﳵ_����ͼ��lend������״̬��
{
	FILE *fp,*fptemp;
	struct BOOK *p;
	fp=fopen("ͼ�������Ϣ.txt","r");
	if(fp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	fptemp=fopen("��ʱͼ�������Ϣ.txt","a+");
	if(fptemp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	p=(struct BOOK*)malloc(LONG);
	while(!feof(fp))
	{

	    fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
	    if(strcmp(p->booknum,booknumer)!=0)//��������Ҫ������
   		fprintf(fptemp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,p->price,p->publisher,p->publishtime,p->bookintroduction,p->booksum,p->booklocation,p->lend,p->borrow,p->lendtimes);
	    else    //������Ҫ�ĵ�����
	    {
			p->lend=1;
			fprintf(fptemp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,p->price,p->publisher,p->publishtime,p->bookintroduction,p->booksum,p->booklocation,p->lend,p->borrow,p->lendtimes);
	    }
	}
    fclose(fp);fclose(fptemp);
    system("del ͼ�������Ϣ.txt");
    system("rename ��ʱͼ�������Ϣ.txt ͼ�������Ϣ.txt");	//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
}
void borrow_borrow_change_lendtime(char booknumer[50])//����_��ʽ���_ ����ͼ�鱻�����
{
	FILE *fp,*fptemp;
	struct BOOK *p;
	fp=fopen("ͼ�������Ϣ.txt","r");
	if(fp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	fptemp=fopen("��ʱͼ�������Ϣ.txt","a+");
	if(fptemp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	p=(struct BOOK*)malloc(LONG);
	while(!feof(fp))
	{

	    fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
	    if(strcmp(p->booknum,booknumer)!=0)//��������Ҫ������
   		fprintf(fptemp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,p->price,p->publisher,p->publishtime,p->bookintroduction,p->booksum,p->booklocation,p->lend,p->borrow,p->lendtimes);
 	    else    //������Ҫ�ĵ�����
	    {
			p->lendtimes=p->lendtimes+1;
			fprintf(fptemp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,p->price,p->publisher,p->publishtime,p->bookintroduction,p->booksum,p->booklocation,p->lend,p->borrow,p->lendtimes);
	    }
	}
    fclose(fp);fclose(fptemp);
    system("del ͼ�������Ϣ.txt");
    system("rename ��ʱͼ�������Ϣ.txt ͼ�������Ϣ.txt");	//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
}
void borrow_borrow_change_borrow_book_num(char studentidnum[50])//����_ ��ʽ���_����ѧ�����ͼ������
{
	FILE *fps,*fpstemp;
	struct students *ps;
	fps=fopen("ѧ����Ϣ.txt","r");
	if(fps==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	fpstemp=fopen("��ʱѧ����Ϣ.txt","a+");
	if(fpstemp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	ps=(struct students*)malloc(LONGS);
	while(!feof(fps))
	{
	    fscanf(fps,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,&ps->borrow_book_num,&ps->if_Frozen);
	    if(strcmp(ps->idnumber,studentidnum)!=0)//��������Ҫ������
   		fprintf(fpstemp,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,ps->borrow_book_num,ps->if_Frozen);
	    else    //������Ҫ�ĵ�����
	    {
			ps->borrow_book_num=ps->borrow_book_num+1;
			fprintf(fpstemp,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,ps->borrow_book_num,ps->if_Frozen);
	    }
	}
    fclose(fps);fclose(fpstemp);
    system("del ѧ����Ϣ.txt");
    system("rename ��ʱѧ����Ϣ.txt ѧ����Ϣ.txt");		//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
}
int Return(char ID[20])//����
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
		a=0;c=0;d=0;e=0;f=0;//�Ƿ�������¼
		printf("--------------------------------------------------------------------------\n");
		printf("                            ��ӭʹ�û���ϵͳ                              \n");
		printf("                          					                              \n");
		printf("--------------------------------------------------------------------------\n");
		fpborrow=fopen("ͼ��軹��Ϣ.txt","r");
		if(fpborrow==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
		pborrow=(struct BorrowInfo*)malloc(LONGBORROW);
		while(!feof(fpborrow))
		{
			fscanf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,&pborrow->borrow_year,&pborrow->borrow_month,&pborrow->borrow_day,&pborrow->borrow_hour,&pborrow->borrow_minute,&pborrow->return_year,&pborrow->return_month,&pborrow->return_day,&pborrow->return_hour,&pborrow->return_minute,&pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
			if(strcmp(ID,pborrow->borrow_student_idnum)==0&&pborrow->return_year==0)//��ȡͼ����Ϣ
			{
				a=1;
				fp=fopen("ͼ�������Ϣ.txt","r");
				if(fp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
				p=(struct BOOK*)malloc(LONG);
				while(!feof(fp))
				{
					fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
					if(strcmp(pborrow->borrow_booknum,p->booknum)==0)
					strcpy(bookname,p->bookname);
				}
				fclose(fp);
				printf("\n================================================================================================\n");
				printf("\n	ѧ����         ͼ����            �鱾����                ����ʱ��\n");
				printf("\n------------------------------------------------------------------------------------------------\n");
				printf("\n	%-10s	%-12s%12s             %d��%d��%d��%dʱ%d��\n\n",ID,pborrow->borrow_booknum,pborrow->borrow_bookname,pborrow->borrow_year,pborrow->borrow_month,pborrow->borrow_day,pborrow->borrow_hour,pborrow->borrow_minute);
			}
		}
		if(a==0)//û�ҵ����ѧ��
		{
			fclose(fpborrow);
			system("cls");
			printf("\a\n δ�ҵ���ѧ���Ľ�����Ϣ,�������²��� \n\n");
			printf("\n=====================================================================\n");
			printf("			��1��������һ��      \n");
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
				default://�ݴ�
				{
					system("cls");
					fclose(fps);
					printf("\n\n�����������������ѡ��\n\n");
					break;
				}
			}
		}
		else//�Ƿ���ʽ����
		{
			fclose(fpborrow);
			do
			{
				printf("\n\n=====================================================================\n");
				printf("				�Ƿ�黹ͼ��             \n");
				printf("			��1����		��2����      \n");
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
					default://�ݴ�
					{
						system("cls");
						fclose(fps);
						printf("\n\n�����������������ѡ��\n\n");
						break;
					}
				}
				do
				{
					printf("��������黹��ͼ���ͼ���ţ�\n");
					scanf("%s",booknum);
					if(borrowtime(ID)==0)
					{
						printf("\n��������Ҫ���裬��ȥѧ���������������\n");
						system("pause");
						return 0;
					}
					else
					{
						fclose(fpborrow);
						Return_change_lend(booknum);//����ͼ����Ϣ lend��1��0
						Return_change_borrow_book_num(ID);//����ѧ���ѽ�����Ŀ borrow_book_num  -1
						Return_change_return_date(ID,booknum);//���Ľ�����Ϣ����������
						printf("�ɹ�������ף���Ķ����\n\n");
						printf("=====================================================================\n");
						printf("			�Ƿ�������������鼮             \n");
						printf("		��1����������		��2��������һ��      \n");
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
							default://�ݴ�
							{
								system("cls");
								printf("\n\n�����������������ѡ��\n\n");
								break;
							}
						}
					}
				}while(e!=0);
			}while(d!=2);
		}
	}while(c!=1);
}
void Return_change_lend(char booknumer[50])//����_����ͼ��lend������״̬��
{
	FILE *fp,*fptemp;
	struct BOOK *p;
	fp=fopen("ͼ�������Ϣ.txt","r");
	if(fp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	fptemp=fopen("��ʱͼ�������Ϣ.txt","a+");
	if(fptemp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	p=(struct BOOK*)malloc(LONG);
	while(!feof(fp))
	{

	    fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
	    if(strcmp(p->booknum,booknumer)!=0)//��������Ҫ������
   		fprintf(fptemp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,p->price,p->publisher,p->publishtime,p->bookintroduction,p->booksum,p->booklocation,p->lend,p->borrow,p->lendtimes);
	    else    //������Ҫ�ĵ�����
	    {
			p->lend=0;
			fprintf(fptemp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,p->price,p->publisher,p->publishtime,p->bookintroduction,p->booksum,p->booklocation,p->lend,p->borrow,p->lendtimes);
	    }
	}
    fclose(fp);fclose(fptemp);
    system("del ͼ�������Ϣ.txt");
    system("rename ��ʱͼ�������Ϣ.txt ͼ�������Ϣ.txt");//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
}
void Return_change_return_date(char id[50],char booknumber[50])//����_����_��������
{
	FILE *fpborrow,*fpborrowtemp;
	struct BorrowInfo *pborrow;
	int a=1;
	fpborrow=fopen("ͼ��軹��Ϣ.txt","r");
	if(fpborrow==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	fpborrowtemp=fopen("��ʱͼ��軹��Ϣ.txt","a+");
	if(fpborrowtemp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	pborrow=(struct BorrowInfo*)malloc(LONGBORROW);
	time_t timep;
  	struct tm *ptm;
   	time (&timep);
    ptm=gmtime(&timep);
	while(!feof(fpborrow))
	{
	    fscanf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,&pborrow->borrow_year,&pborrow->borrow_month,&pborrow->borrow_day,&pborrow->borrow_hour,&pborrow->borrow_minute,&pborrow->return_year,&pborrow->return_month,&pborrow->return_day,&pborrow->return_hour,&pborrow->return_minute,&pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
		//�������//����ѧ��//������ݵ���0
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
    system("del ͼ��軹��Ϣ.txt");
    system("rename ��ʱͼ��軹��Ϣ.txt ͼ��軹��Ϣ.txt");//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
}
void Return_change_borrow_book_num(char studentidnum[50])//����_����_ѧ�����ͼ������
{
	FILE *fps,*fpstemp;
	struct students *ps;
	fps=fopen("ѧ����Ϣ.txt","r");
	if(fps==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	fpstemp=fopen("��ʱѧ����Ϣ.txt","a+");
	if(fpstemp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	ps=(struct students*)malloc(LONGS);
	while(!feof(fps))
	{
	    fscanf(fps,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,&ps->borrow_book_num,&ps->if_Frozen);
	    if(strcmp(ps->idnumber,studentidnum)!=0)//��������Ҫ������
     	fprintf(fpstemp,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,ps->borrow_book_num,ps->if_Frozen);
	    else    //������Ҫ�ĵ�����
	    {
			ps->borrow_book_num=ps->borrow_book_num-1;
			fprintf(fpstemp,"%s %s %s %s %s %s %s %s %d %d\n",ps->idnumber,ps->school,ps->major,ps->name,ps->gender,ps->phonenumber,ps->password,ps->mailbox,ps->borrow_book_num,ps->if_Frozen);
	    }
	}
    fclose(fps);fclose(fpstemp);
    system("del ѧ����Ϣ.txt");
    system("rename ��ʱѧ����Ϣ.txt ѧ����Ϣ.txt");//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
}
//**********************************************************����
void student_enrolment()//ѧ��ע��
{
	char idnumber[30],school[30],major[30],name[30],gender[30],phonenumber[30],password[30],mailbox[30];
	FILE*fp;FILE*fp1;
	struct students temp;
	struct students temp1;
	struct students *pt;
	struct students *pt1;
	pt=&temp;
	pt1=&temp1;
	if((fp=fopen("ѧ����Ϣ.txt","r"))==NULL){printf("                            �ļ��򿪴���!                                   \n");exit(1);}
	if((fp1=fopen("ѧ����Ϣtemp_.txt","w+"))==NULL)//��ʱ�ļ���pt1Ϊָ�롣 {printf("                            �ļ��򿪴���!                                   \n");exit(1);}
   	printf("\n=====================================================================\n");
	printf("                        ��ӭ����ѧ��ע����棡                         \n");
	printf("                           ��������id���룺                            \n");
	printf("\n=====================================================================\n");
	scanf("%s",idnumber);
	while(idnumbervalidation(idnumber)==0)//�ж�id�����Ƿ���ϸ�ʽ
	{
		printf("                         ��ʽ��������������:                             \n");
		scanf("%s",idnumber);
	}
	while(!feof(fp))//��ԭ�ļ������ݶ�����ʱ�ļ���
    {
        fscanf(fp,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,&pt->borrow_book_num,&pt->if_Frozen);
	    fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,pt->borrow_book_num,pt->if_Frozen);//��ʱ
 	}
    rewind(fp);
	while(!feof(fp))//�����ļ��鿴���˺��Ƿ��Ѿ�ע���
    {
    	fscanf(fp,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,&pt->borrow_book_num,&pt->if_Frozen);
		if(strcmp(pt->idnumber,idnumber)==0)//������Ҫ������
    	{
    		printf("                          ���Ѿ�ע����ˣ�                                 \n");//
    		fclose(fp);
        	fclose(fp1);
  	  		system("del ѧ����Ϣtemp_.txt");//����Ѿ�ע���������ԭ�ļ���ɾ����ʱ�ļ�
    		return;
		}
    }
	printf("                           ��������ѧԺ��                              \n");
    scanf("%s",school);
	printf("                           ��������רҵ��                              \n");
	scanf("%s",major);
	printf("                           ��������������                              \n");
	scanf("%s",name);
	printf("                           ���������Ա�                              \n");
	scanf("%s",gender);
	printf("                          �������ĵ绰���룺                           \n");
	scanf("%s",phonenumber);
	while(phonenumbervalidation(phonenumber)==0)
	{
		printf("                        ��ʽ�������������룺                         \n");
		scanf("%s",phonenumber);
	}
	printf("                           �����������룺                              \n");
	scanf("%s",password);
	printf("                           �����������䣺                              \n");
	scanf("%s",mailbox);
	while(mailboxvalidation(mailbox)==0)
	{
		printf("                        ��ʽ�������������룺                         \n");
		scanf("%s",mailbox);
	}
	fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",idnumber,school,major,name,gender,phonenumber,password,mailbox,0,0);
    fclose(fp);
    fclose(fp1);
	system("del ѧ����Ϣ.txt");
    system("rename ѧ����Ϣtemp_.txt ѧ����Ϣ.txt");//��ԭ�ļ�ɾ������ʱ�ļ�����Ϊԭ�ļ�������
}
void teacher_enrolment()//ͼ�����Աע��
{
	char idnumber[30],name[30],password[30],mailbox[30];
	FILE*fp;FILE*fp1;
	struct teachers temp;
	struct teachers *pt;
	pt=&temp;
	if((fp=fopen("ͼ�����Ա��Ϣ.txt","r"))==NULL){printf("                            �ļ��򿪴���!                                   \n");exit(1);}
	if((fp1=fopen("ͼ�����Ա��Ϣtemp_.txt","w+"))==NULL){printf("                            �ļ��򿪴���!                                   \n");exit(1);}
 	printf("\n=====================================================================\n");
	printf("                        ��ӭ��������Աע����棡                         \n");
	printf("                           ��������id���룺                              \n");
	printf("\n=====================================================================\n");
	scanf("%s",idnumber);
	while(idnumbervalidation(idnumber)==0)//�ж������id�����Ƿ���ϸ�ʽ
	{
		printf("                         ��ʽ�������������룺                             \n");
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
		if(strcmp(pt->idnumber_t,idnumber)==0)//������Ҫ������
    	{
    		printf("                          ���Ѿ�ע����ˣ�                                 \n");
       		fclose(fp);
        	fclose(fp1);
	    	system("del ͼ�����Ա��Ϣtemp_.txt");
    		return;
		}
    }
	printf("                           ��������������                              \n");
	scanf("%s",name);
	printf("                           �����������룺                              \n");
	scanf("%s",password);
	printf("                           �����������䣺                              \n");
	scanf("%s",mailbox);
	while(mailboxvalidation(mailbox)==0)
	{
		printf("                         ��ʽ�������������룺                             \n");
		scanf("%s",mailbox);
	}
	fprintf(fp,"%s %s %s %s\n",idnumber,name,password,mailbox);
    fclose(fp);
    fclose(fp1);
	system("del ͼ�����Ա��Ϣ.txt");
    system("rename ͼ�����Ա��Ϣtemp_.txt ͼ�����Ա��Ϣ.txt");//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
}
int idnumbervalidation(char idnumber[20])//ѧ��/���Ÿ�ʽ�ж�//���Ϸ���1
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
int booknumbervalidation(char booknumber[20])//ͼ���Ÿ�ʽ�ж�//���Ϸ���1
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
int phonenumbervalidation(char phonenumber[20])//�绰��ʽ�ж�     //���Ϸ���1�������Ϸ���0
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
int mailboxvalidation(char mailbox[])//�����ʽ�ж�    //���Ϸ���1�������Ϸ���0
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

void studentinfo_management(char idnumber_[20])//��ѧ�������
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
	printf("                      ѡ������Ҫ�޸ĵ����ݣ�                           \n");
	printf("1.������                   2.������                        3.�ĵ绰����\n");
	printf("\n=====================================================================\n");
	scanf("%d",&choice);
	while(!(choice>=1&&choice<=3))//��������ַ��������ݴ�Χ��
	{
	    printf("                      ��ʽ�������������룺                           \n");
	    scanf("%d",&choice);
	}
	if((fp=fopen("ѧ����Ϣ.txt","r"))==NULL){printf("�޷��򿪸��ļ�!\n");exit(1);}
	if((fp1=fopen("ѧ����Ϣtemp.txt","w+"))==NULL){printf("�޷��򿪸��ļ�!\n");exit(1);}
	switch(choice)
	{
		case 1://������
		{
        	printf("                            ��������룺                         \n");
		   	scanf("%s",newpassword); //�����µ�����
			while(!feof(fp))
			{
   				fscanf(fp,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,&(pt->borrow_book_num),&pt->if_Frozen);
		   		if(strcmp(pt->idnumber,idnumber_)==0)//������Ҫ������
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
				else    //��������Ҫ������
	    		fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,pt->borrow_book_num,pt->if_Frozen);
		   	}
			fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt1->idnumber,pt1->school,pt1->major,pt1->name,pt1->gender,pt1->phonenumber,pt1->password,pt1->mailbox,pt1->borrow_book_num,pt1->if_Frozen);
			fclose(fp);
			fclose(fp1);
			system("del ѧ����Ϣ.txt");
            system("rename ѧ����Ϣtemp.txt ѧ����Ϣ.txt");//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
            break;
		}
		case 2://������
		{
			printf("                            ��������䣺                         \n");
		   	scanf("%s",newmailbox);
		   	while(mailboxvalidation(newmailbox)==0)
		   	{
		       	printf("                      ��ʽ�������������룺                           \n");
		   		scanf("%s",newmailbox);
			} //ʹ���Ƿ�Ϊ��ʽ��ȷ������ĺ���
 			while(!feof(fp))//studentnum:ѧ����
			{
		   		fscanf(fp,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,&(pt->borrow_book_num),&pt->if_Frozen);            //�޸��ļ�����
		   		if(strcmp(pt->idnumber,idnumber_)==0)//������Ҫ������
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
				else    //bu������Ҫ������
				fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,pt->borrow_book_num,pt->if_Frozen);
			}
			fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt1->idnumber,pt1->school,pt1->major,pt1->name,pt1->gender,pt1->phonenumber,pt1->password,pt1->mailbox,pt1->borrow_book_num,pt1->if_Frozen);
			fclose(fp);
			fclose(fp1);
			system("del ѧ����Ϣ.txt");
           	system("rename ѧ����Ϣtemp.txt ѧ����Ϣ.txt");//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
		 	break;
		}
		case 3://�ĵ绰
		{
			printf("                           ����µ绰���룺                         \n");
		   	scanf("%s",newphonenumber);
		   	while(phonenumbervalidation(newphonenumber)==0)
		   	{
		   		printf("                      ��ʽ�������������룺                           \n");
		   		fgets(newphonenumber,12,stdin);
		 	}
		   	while(!feof(fp))//studentnum:ѧ����
			{
		   		fscanf(fp,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,&(pt->borrow_book_num),&pt->if_Frozen);            //�޸��ļ�����
		   		if(strcmp(pt->idnumber,idnumber_)==0)//������Ҫ������
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
				else    //bu������Ҫ������
				fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,pt->borrow_book_num,pt->if_Frozen);

			}
			fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt1->idnumber,pt1->school,pt1->major,pt1->name,pt1->gender,pt1->phonenumber,pt1->password,pt1->mailbox,pt1->borrow_book_num,pt1->if_Frozen);
			fclose(fp);
			fclose(fp1);
			system("del ѧ����Ϣ.txt");
           	system("rename ѧ����Ϣtemp.txt ѧ����Ϣ.txt");//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
           	break;
		}
	}
}
void teacherinfo_management(char idnumber_[20])//��teacher�����
{
	struct teachers teacherinformation;
	struct teachers teacherinformation1;
	struct teachers *pt;
	struct teachers *pt1;
	pt=&teacherinformation;
	pt1=&teacherinformation1;
	FILE *fp;
	FILE *fp1;
	char newpassword[30],newmailbox[30],tempidnumber[30]; //�޸��ļ�ʱ�õ�
	int index1,index,choice;
	printf("\n=====================================================================\n");
	printf("                      ѡ������Ҫ�޸ĵ����ݣ�                           \n");
	printf("1.         ������                           2.������                   \n");
	printf("\n=====================================================================\n");
	scanf("%d",&choice);
	while(!(choice>=1&&choice<=2))//��������ַ��������ݴ�Χ��
	{
		printf("����������������룺");
	    scanf("%d",&choice);
	}
	if((fp=fopen("ͼ�����Ա��Ϣ.txt","r"))==NULL){printf("                            �ļ��򿪴���!                                   \n");exit(1);}
	if ((fp1=fopen("ͼ�����Ա��Ϣtemp.txt","w"))==NULL){printf("                            �ļ��򿪴���!                                   \n");exit(1); }
	switch(choice)
	{
		case 1://������
		{
			printf("                            ��������룺                         \n");
		    scanf("%s",newpassword); //�����µ�����
			while(!feof(fp))
			{
		    	fscanf(fp,"%s %s %s %s\n",pt->idnumber_t,pt->name_t,pt->password_t,pt->mailbox_t);
          		if(strcmp(pt->idnumber_t,idnumber_)==0)//������Ҫ������
           		{
	        	     strcpy(pt1->password_t,newpassword);
					 strcpy(pt1->idnumber_t,pt->idnumber_t);
					 strcpy(pt1->name_t,pt->name_t);
	        	     strcpy(pt1->mailbox_t,pt->mailbox_t);
				}
				else    //bu������Ҫ������
				{
		     		fprintf(fp1,"%s %s %s %s\n",pt->idnumber_t,pt->name_t,pt->password_t,pt->mailbox_t);
				}
				fprintf(fp1,"%s %s %s %s\n",pt1->idnumber_t,pt1->name_t,pt1->password_t,pt1->mailbox_t);
		    }
			fclose(fp);
			fclose(fp1);
			system("del ͼ�����Ա��Ϣ.txt");
            system("rename ͼ�����Ա��Ϣtemp.txt ͼ�����Ա��Ϣ.txt");//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
			break;
  		}
		case 2://������
		{
			printf("                            ��������䣺                         \n");
		    scanf("%s",newmailbox);
		    while(mailboxvalidation(newmailbox)==0)
		    {
		    	printf("                        ��ʽ�������������룺                   \n");
		    	scanf("%s",newmailbox);
		 	} //ʹ���Ƿ�Ϊ��ʽ��ȷ������ĺ���

   			while(!feof(fp))//studentnum:ѧ����
			{
		    	fscanf(fp,"%s %s %s %s\n",pt->idnumber_t,pt->name_t,pt->password_t,pt->mailbox_t);            //�޸��ļ�����
          		if(strcmp(pt->idnumber_t,idnumber_)==0)//������Ҫ������
           		{
	        	     strcpy(pt1->password_t,pt->password_t);
					 strcpy(pt1->idnumber_t,pt->idnumber_t);
					 strcpy(pt1->name_t,pt->name_t);
	        	     strcpy(pt1->mailbox_t,newmailbox);
				}
				else    //bu������Ҫ������
				{
		     		fprintf(fp1,"%s %s %s %s\n",pt->idnumber_t,pt->name_t,pt->password_t,pt->mailbox_t);
				}
			}
		    fprintf(fp1,"%s %s %s %s\n",pt1->idnumber_t,pt1->name_t,pt1->password_t,pt1->mailbox_t);
			fclose(fp);
			fclose(fp1);
			system("del ͼ�����Ա��Ϣ.txt");
            system("rename ͼ�����Ա��Ϣtemp.txt ͼ�����Ա��Ϣ.txt");//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
		 	break;
		}
	}
}
void deleteborrowinfo(char idnum[20])//ֻ����ɾ�����������жϹ��ﳵ�ļ���Ĵ�����
{
	FILE *fpbuffer,*fpbuffertemp,*fp;
	char booknum[20],bookname[20];
	struct buffer *pbuffer;
	struct BOOK *p;
	int status=0;
	fpbuffer=fopen("���ﳵ.txt","a+");
	if(fpbuffer==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	pbuffer=(struct buffer*)malloc(LONGBUFFER);
	while(!feof(fpbuffer))
	{
		fscanf(fpbuffer,"%s %s\n",pbuffer->idnumber_,pbuffer->booknumber);
		if(strcmp(idnum,pbuffer->idnumber_)==0)
		{
			fp=fopen("ͼ�������Ϣ.txt","r");
			if(fp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
			p=(struct BOOK*)malloc(LONG);
			while(!feof(fp))
			{
				fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
				if(strcmp(pbuffer->booknumber,p->booknum)==0)
				strcpy(bookname,p->bookname);
			}
			fclose(fp);
			printf("\n=====================================================================\n");
			printf("\n	ѧ����         ͼ����            �鱾����\n");
			printf("\n---------------------------------------------------------------------\n");
			printf("\n	%-10s	%-12s%12s\n\n",idnum,pbuffer->booknumber,bookname);
			printf("\n---------------------------------------------------------------------\n\n");
		}
	}
	fclose(fpbuffer);
	fclose(fp);
	printf("===============================================\n\n");
	printf("��������ɾ���ļ�¼��ͼ����\n");
	printf("===============================================\n\n");
	scanf("%s",booknum);
 	while(booknumbervalidation(booknum)==0)
  	{
	    printf("                         ��ʽ�������������룺                             \n");
	    scanf("%s",booknum);
	}
	fpbuffer=fopen("���ﳵ.txt","r");
	if(fpbuffer==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	fpbuffertemp=fopen("��ʱ���ﳵ.txt","a+");
	if(fpbuffer==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	pbuffer=(struct buffer*)malloc(LONGBUFFER);
	while(!feof(fpbuffer))//studentnum:ѧ����,recordnum:buffer��Ĵ�����
	{
	    fscanf(fpbuffer,"%s %s\n",pbuffer->idnumber_,pbuffer->booknumber);
	    if(strcmp(pbuffer->idnumber_,idnum)!=0)//��������Ҫ������
     	fprintf(fpbuffertemp,"%s %s\n",pbuffer->idnumber_,pbuffer->booknumber);
	    else    //������Ҫ������,������֤enter�ı�����ǲ�����ȷ���������ȷ����Ҳ���뵽��ʱ�ļ���
	    {
			if(strcmp(pbuffer->booknumber,booknum)!=0)
			fprintf(fpbuffertemp,"%s %s\n",pbuffer->idnumber_,pbuffer->booknumber);
	    	else status++;
		}
	}
    fclose(fpbuffer);
	fclose(fpbuffertemp);
    system("del ���ﳵ.txt");
    system("rename ��ʱ���ﳵ.txt ���ﳵ.txt");	//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
    Return_change_lend(booknum);//�޸�ͼ�����״̬Ϊ���ɽ衱
    system("pause");
}
int search_by_writername()//�������߲�ѯ
{
	int c;
	do
	{
		c=0;
		int i=0,a=0;
		char searchname[100];
		FILE *fp;
		struct BOOK *p;
		fp=fopen("ͼ�������Ϣ.txt","a+");
		if(fp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
		p=(struct BOOK*)malloc(LONG);
		printf("===================================\n");
		printf("�������ѯͼ�������\n");
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
				printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","��ţ�",p->booknum,"������",p->bookname,"���ۣ�",p->price);
				printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","���ߣ�",p->writer,"�����磺",p->publisher,"����ʱ��:",p->publishtime);
				printf("%-8s%s\n\n","ͼ��λ�ã�",p->booklocation);
				printf("\n\n");
			}
		}
		fclose(fp);
		if(a==0)
		{
			system("cls");
			printf("\a\n δ�ҵ������������ͼ��,�������²��� \n\n");
			printf("=====================================================================\n");
			printf("			�Ƿ�������������鼮             \n");
			printf("		��1����������		��2��������һ��      \n");
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
				default://�ݴ�
				{
					system("cls");
					printf("\n\n�����������������ѡ��\n\n");
					break;
				}
			}
		}
		if(a==1)
		{
			printf("=====================================================================\n");
			printf("			�Ƿ�������������鼮             \n");
			printf("		��1����������		��2��������һ��      \n");
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
				default://�ݴ�
				{
					system("cls");
					printf("\n\n�����������������ѡ��\n\n");
					break;
				}
			}
		}
	}while(c!=2);
}
int search_by_name()//����������ѯ
{
	int c;
	do
	{
		c=0;
		int i=0,a=0;
		char searchname[100];
		FILE *fp;
		struct BOOK *p;
		fp=fopen("ͼ�������Ϣ.txt","a+");
		if(fp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
		p=(struct BOOK*)malloc(LONG);
		printf("===================================\n");
		printf("�������ѯͼ�������\n");
		printf("===================================\n");
		scanf("%s",searchname);
		while(!feof(fp))
		{
			fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
			if(strcmp(searchname,p->bookname)==0)
			{
				a=1;
				printf("=================================================\n");
				printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","��ţ�",p->booknum,"������",p->bookname,"���ۣ�",p->price);
				printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","���ߣ�",p->writer,"�����磺",p->publisher,"����ʱ��:",p->publishtime);
				printf("%-8s%s\n\n","ͼ��λ�ã�",p->booklocation);
				printf("\n\n");
			}
		}
		fclose(fp);
		if(a==0)
		{
			system("cls");
			printf("\a\n δ�ҵ������������ͼ��,�������²��� \n\n");
			printf("=====================================================================\n");
			printf("			�Ƿ�������������鼮             \n");
			printf("		��1����������		��2��������һ��      \n");
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
				default://�ݴ�
				{
					system("cls");
					printf("\n\n�����������������ѡ��\n\n");
					break;
				}
			}
		}
		if(a==1)
		{
			printf("=====================================================================\n");
			printf("			�Ƿ�������������鼮             \n");
			printf("		��1����������		��2��������һ��      \n");
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
				default://�ݴ�
				{
					system("cls");
					printf("\n\n�����������������ѡ��\n\n");
					break;
				}
			}
		}
	}while(c!=2);
}
int search_by_press()//���ճ������ѯ
{
	int c;
	do
	{
		c=0;
		int i=0,a=0;
		char searchname[100];
		FILE *fp;
		struct BOOK *p;
		fp=fopen("ͼ�������Ϣ.txt","a+");
		if(fp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
		p=(struct BOOK*)malloc(LONG);
		printf("===================================\n");
		printf("�������ѯͼ��ĳ�����(*****������)\n");
		printf("===================================\n");
		scanf("%s",searchname);
		while(!feof(fp))
		{
			fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
			if(strcmp(searchname,p->publisher)==0)
			{
				a=1;
				printf("=================================================\n");
				printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","��ţ�",p->booknum,"������",p->bookname,"���ۣ�",p->price);
				printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","���ߣ�",p->writer,"�����磺",p->publisher,"����ʱ��:",p->publishtime);
				printf("%-8s%s\n\n","ͼ��λ�ã�",p->booklocation);
				printf("\n\n");
			}
		}
		fclose(fp);
		if(a==0)
		{
			system("cls");
			printf("\a\n δ�ҵ������������ͼ��,�������²��� \n\n");
			printf("=====================================================================\n");
			printf("			�Ƿ�������������鼮             \n");
			printf("		��1����������		��2��������һ��      \n");
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
				default://�ݴ�
				{
					system("cls");
					printf("\n\n�����������������ѡ��\n\n");
					break;
				}
			}
		}
		if(a==1)
		{
			printf("=====================================================================\n");
			printf("			�Ƿ�������������鼮             \n");
			printf("		��1����������		��2��������һ��      \n");
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
				default://�ݴ�
				{
					system("cls");
					printf("\n\n�����������������ѡ��\n\n");
					break;
				}
			}
		}
	}while(c!=2);
}
int book_add()//ͼ�����
{
	while(1)
	{
		FILE *fp;
		struct BOOK book[1000];
		struct BOOK *p1;
		p1=book;
		int a=100000,b,c=10100,m,n,p=0,i=0;
		char z;
		fp=fopen("ͼ�������Ϣ.txt","a+");
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
		printf("��������ͼ����Ϣ��\n");
		printf("============================================================================\n");
		printf(" ����  ����  �۸� ������  ������_��_��  ��� ����\n");
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
		printf("|        [1].����¼��    [2].����¼��        |\n");
		printf("----------------------------------------------\n");
		printf("��ѡ��");
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
	printf("ллʹ�ã�\n");
	return 1;
}
int update()//�޸�ͼ��
{
	int c;
	do
	{
		c=0;
		int i=0,a=2,b,d,e,f,g,z;//bΪѡ��
	    char bookintroduction[200],booklocation[50],updnum[10];///updnum���ַ�������
		struct BOOK *pb;//=mbook;///ָ���ʼ��
		struct BOOK *qb;//=ubook;
		FILE *fp,*fq;
		fp=fopen("ͼ�������Ϣ.txt","r");///Դ�ļ�
		pb=(struct BOOK*)malloc(LONG);
		qb=(struct BOOK*)malloc(LONG);
		while(!feof(fp))
		{
			fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,&pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,&pb->booksum,pb->booklocation,&pb->lend,&pb->borrow,&pb->lendtimes);
			printf("=================================================\n");
			printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","��ţ�",pb->booknum,"������",pb->bookname,"���ۣ�",pb->price);
			printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","���ߣ�",pb->writer,"�����磺",pb->publisher,"����ʱ��:",pb->publishtime);
			printf("%-8s%s\n\n","ͼ��λ�ã�",pb->booklocation);
			printf("%-6s%s\n\n","ͼ���飺",pb->bookintroduction);
			printf("\n\n");
		}
		fclose(fp);
		printf("���������޸ĵ�ͼ���ţ�\n") ;
		scanf("%s",updnum);
		system("cls");
		fp=fopen("ͼ�������Ϣ.txt","r");///Դ�ļ�
		while(!feof(fp))//�жϸ�ͼ���Ƿ񱻽��	��������޸�
		{
			fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,&pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,&pb->booksum,pb->booklocation,&pb->lend,&pb->borrow,&pb->lendtimes);
			if(strcmp(updnum,pb->booknum)==0)//��������
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
				printf("\n�Ȿ���Ѿ������ߣ��޷��޸�\n\n");////////
				printf("=====================================================================\n");
				printf("			�Ƿ�������������鼮             \n");
				printf("		��1����������		��2��������һ��      \n");
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
					default://�ݴ�
					{
						system("cls");
						printf("\n\n�����������������ѡ��\n\n");
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
					printf("			��ѡ����Ҫ�޸ĵ���Ϣ             \n");
					printf("		��1��ͼ����		��2�����λ��      \n");
					printf("=====================================================================\n");
					scanf("%d",&b);
					switch(b)
					{
						case 1://����ͼ����
						{
							fp=fopen("ͼ�������Ϣ.txt","r");///Դ�ļ�
							while(!feof(fp))
							{
								fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,&pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,&pb->booksum,pb->booklocation,&pb->lend,&pb->borrow,&pb->lendtimes);
								if(strcmp(updnum,pb->booknum)==0)
								{
									printf("=================================================\n");
									printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","��ţ�",pb->booknum,"������",pb->bookname,"���ۣ�",pb->price);
									printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","���ߣ�",pb->writer,"�����磺",pb->publisher,"����ʱ��:",pb->publishtime);
									printf("%-8s%s\n\n","ͼ��λ�ã�",pb->booklocation);
									printf("%-6s%s\n\n","ͼ���飺",pb->bookintroduction);
									printf("\n\n");
								}
							}
							fclose(fp);
							printf("�������޸ĺ��ͼ���飺");
							scanf("%s",bookintroduction);
							fp=fopen("ͼ�������Ϣ.txt","r");///Դ�ļ�
							fq=fopen("result.txt","a+");///Ŀ���ļ�
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
							printf("�޸ĳɹ�\n");
							fclose(fp);
							fclose(fq);
							system("del ͼ�������Ϣ.txt");
							system("rename result.txt ͼ�������Ϣ.txt");//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
							f=0;
							break;
						}
						case 2:
						{
							fp=fopen("ͼ�������Ϣ.txt","r");///Դ�ļ�
							while(!feof(fp))
							{
								fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,&pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,&pb->booksum,pb->booklocation,&pb->lend,&pb->borrow,&pb->lendtimes);
								if(strcmp(updnum,pb->booknum)==0)
								{
									printf("=================================================\n");
									printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","��ţ�",pb->booknum,"������",pb->bookname,"���ۣ�",pb->price);
									printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","���ߣ�",pb->writer,"�����磺",pb->publisher,"����ʱ��:",pb->publishtime);
									printf("%-8s%s\n\n","ͼ��λ�ã�",pb->booklocation);
									printf("%-6s%s\n\n","ͼ���飺",pb->bookintroduction);
									printf("\n\n");
								}
							}
							fclose(fp);
							printf("�������޸ĺ�����λ�ã�����1��1�㣩��");
							scanf("%s",booklocation);
							fp=fopen("ͼ�������Ϣ.txt","r");///Դ�ļ�
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
								fp=fopen("ͼ�������Ϣ.txt","r");///Դ�ļ�
								fq=fopen("result.txt","a+");///Ŀ���ļ�
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
								printf("�޸ĳɹ�\n");
								fclose(fp);
								fclose(fq);
								system("del ͼ�������Ϣ.txt");
								system("rename result.txt ͼ�������Ϣ.txt");//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
							}
							else//���λ���ظ���
							{
								printf("�����λ�ô����鱾������������\n");
								f=1;
							}
						break;
						}
					}
				}while(f!=0);
				fclose(fp);
				printf("=====================================================================\n");
				printf("			�Ƿ�������������鼮             \n");
				printf("		��1����������		��2��������һ��      \n");
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
					default://�ݴ�
					{
						system("cls");
						printf("\n\n�����������������ѡ��\n\n");
						break;
					}
				}
			}
		}
		else
		{
			system("cls");
			printf("\a\n δ�ҵ������������ͼ��,�������²��� \n\n");
			printf("=====================================================================\n");
			printf("			�Ƿ�������������鼮             \n");
			printf("		��1����������		��2��������һ��      \n");
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
				default://�ݴ�
				{
					system("cls");
					printf("\n\n�����������������ѡ��\n\n");
					break;
				}
			}
		}
	}while(c!=2);
}
int book_delete()//ɾ��ͼ��
{
    int c;
	do
    {
    	c=0;
    	int a=0,a1=0,a2=0;
		struct BOOK *pb;
		pb=(struct BOOK*)malloc(LONG);
		FILE *ff,*fp;
		char b[10];//�����û�����ı��
    	ff=fopen("ͼ�������Ϣ.txt","r");//����ԭ�ļ����ݿ�.txt
    	if(ff==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
		while(!feof(ff))
		{
			fscanf(ff,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,&pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,&pb->booksum,pb->booklocation,&pb->lend,&pb->borrow,&pb->lendtimes);
			printf("=================================================\n");
			printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","��ţ�",pb->booknum,"������",pb->bookname,"���ۣ�",pb->price);
			printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","���ߣ�",pb->writer,"�����磺",pb->publisher,"����ʱ��:",pb->publishtime);
			printf("%-8s%s\n\n","ͼ��λ�ã�",pb->booklocation);
			printf("%-6s%s\n\n","ͼ���飺",pb->bookintroduction);
			printf("\n\n");
		}
    	printf("������Ҫɾ����ͼ����:\n");
    	scanf("%s",b);
    	fclose(ff);
    	ff=fopen("ͼ�������Ϣ.txt","r");//����ԭ�ļ����ݿ�.txt
    	while(!feof(ff))//�鿴�Ƿ���������
    	{
			fscanf(ff,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,&pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,&pb->booksum,pb->booklocation,&pb->lend,&pb->borrow,&pb->lendtimes);
			if(strcmp(b,pb->booknum)==0)
			a=1;//��������
   		}
    	fclose(ff);
   		if(a==1)
   		{
  		  	ff=fopen("ͼ�������Ϣ.txt","r");//����ԭ�ļ����ݿ�.txt
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
  		 	 	ff=fopen("ͼ�������Ϣ.txt","r");//����ԭ�ļ����ݿ�.txt
				fp=fopen("��ʱͼ�������Ϣ.txt","a+");//д����ʱ�ļ�result.txt
				while(!feof(ff))
				{
					fscanf(ff,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,&pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,&pb->booksum,pb->booklocation,&pb->lend,&pb->borrow,&pb->lendtimes);
					if(strcmp(b,pb->booknum)!=0)
					fprintf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",pb->booknum,pb->bookname,pb->writer,pb->price,pb->publisher,pb->publishtime,pb->bookintroduction,pb->booksum,pb->booklocation,pb->lend,pb->borrow,pb->lendtimes);
				}
				fclose(ff);
				fclose(fp);
				system("del ͼ�������Ϣ.txt");
				system("rename ��ʱͼ�������Ϣ.txt ͼ�������Ϣ.txt");//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
				a=0;
				a2=1;
			}
   		}
  		if(a==0)
  		{
			system("cls");
			if(a1==1)
			printf("�Ȿ����������޷�ɾ��\n");
			else if(a2==1)
			printf("ɾ���ɹ�\n");
			else
			printf("\a\n δ�ҵ������������ͼ��,�������²��� \n\n");
			printf("=====================================================================\n");
			printf("			�Ƿ�������������鼮             \n");
			printf("		��1����������		��2��������һ��      \n");
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
				default://�ݴ�
				{
					system("cls");
					printf("\n\n�����������������ѡ��\n\n");
					break;
				}
			}
	  	}
    }while(c!=2);
}
int Borrow_Time_Overdue_Book_Situation()//��ʱδ��ͼ��
{
	FILE*fp1;
	int i,a;
	char booknum[10],name[10];
	fp1=fopen("ͼ��軹��Ϣ.txt","r");
	struct BorrowInfo *m;
	printf("--------------------------------------------------------------------------\n");
	printf("                                                                          \n");
	printf("����δ��ͼ�������\n");
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
        	printf("\n����ѧ��ѧ��   ѧ������  �������  ��Ŀ���        ����    ���ʱ��\n ");
        	printf("%s    %8s      %2d",m->borrow_student_idnum,m->borrow_student_name,m->renew_num);
			printf("    %s  %12s ",m->borrow_booknum,m->borrow_bookname);
			printf("   %d��%2d��%2d��%2dʱ%2d��\n\n",m->borrow_year,m->borrow_month,m->borrow_day,m->borrow_hour,m->borrow_minute);
			printf("--------------------------------------------------------------------------\n");
		}
	}
	fclose(fp1);
	system("pause");
	return 0;
}
int Borrow_Time_Overdue_Students_Situation()//��ʱδ����Ϊѧ��
{
	FILE*fp1;
	int i;
	char id[50],name[10];
	fp1=fopen("ѧ����Ϣ.txt","r");
	struct students *m;
	printf("--------------------------------------------------------------------------\n");
	printf("                                                                          \n");
	printf("����δ��ѧ��������\n");
	printf("\n");
	printf("         ѧ������              ѧ��ѧ��\n");
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
int Borrow_Time_Overdue_Frozen()//�˺Ŷ���
{
	FILE*fp1;
	int i,a,b=0,t;
	char id[50];
	struct students *m;
	struct students *p;
	do
    {
		system("cls");
		fp1=fopen("ѧ����Ϣ.txt","r");
	    printf("--------------------------------------------------------------------------\n");
	    printf("                                                                          \n");
		printf("                           ����δ����ѧ��������                           \n");
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
				printf("     ������%s ѧ��%s",m->name,m->idnumber);
	        	if(m->if_Frozen==1)//1�Ƕ���
	        	printf("      ��ѧ���˻��Ѿ�������");
	        	printf("\n");
			}
		}
		fclose(fp1);
		printf("                                                                          \n");
		printf("--------------------------------------------------------------------------\n");
	    printf("                                                                          \n");
		printf("                           �����루1~2����                                \n");
		printf("                           1.����ѧ���˻�                                 \n");
		printf("                           2.������һ����                                 \n");
		printf("                                                                          \n");
		printf("--------------------------------------------------------------------------\n");
		printf("�����룺");
		scanf("%d",&b);
		if(b==1)
		{
			printf("--------------------------------------------------------------------------\n");
			printf("���������붳���˻���ѧ��ѧ�ţ�");
			scanf("%s",id);
			a=1;
			fp1=fopen("ѧ����Ϣ.txt","r");
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
				printf("                          δ�ҵ���ѧ����Ϣ\n");
				printf("                                                                          \n");
	            printf("--------------------------------------------------------------------------\n");
			}
		    if(a==2)
			{
				printf("--------------------------------------------------------------------------\n");
			    printf("                                                                          \n");
				printf("                      ��ѧ��û�г���δ����ͼ��\n");
				printf("                                                                          \n");
	            printf("--------------------------------------------------------------------------\n");
			}
			fclose(fp1);
			if(a==0)
			{
			    Frozen_Account(id);
		        printf("--------------------------------------------------------------------------\n");
				printf("                                                                          \n");
			    printf("                  ѧ��Ϊ%s��ѧ���˺��ѱ�����\n",id);
			    printf("                                                                          \n");
		        printf("--------------------------------------------------------------------------\n");
		    }
	    }
	    if(b!=1&&b!=2)
	    {
		    printf("--------------------------------------------------------------------------\n");
	        printf("                                                                          \n");
			printf("                          �������������������                          \n");
		    printf("                                                                          \n");
		    printf("--------------------------------------------------------------------------\n");
		}
		system("pause");
    }while(b!=2);
	return 0;
}
int Borrow_Time_Overdue_Frozen1()//�˺Žⶳ
{
	FILE *fp1;
	int i,a,b=0,c;
	char id[50];
	struct students *m;
	struct students *p;
	do
	{
		system("cls");
		fp1=fopen("ѧ����Ϣ.txt","r");
	    printf("--------------------------------------------------------------------------\n");
	    printf("                                                                          \n");
		printf("                            �Ѿ��������ѧ��������                      \n\n");
		printf("                                                                          \n");
	    while(!feof(fp1))
		{
			m=(struct students*)malloc(LONGS);
			fscanf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",m->idnumber,m->school,m->major,m->name,m->gender,m->phonenumber,m->password,m->mailbox,&m->borrow_book_num,&m->if_Frozen);
		    strcpy(id,m->idnumber);
	        if(m->if_Frozen==1)//1�Ƕ���
	        {
	        	printf("%s %s\n",m->name,m->idnumber);
	        	printf("--------------------------------------------------------------------------\n");
	        }
		}
		fclose(fp1);
		printf("                               �����루1~2��\n");
		printf("                                                                          \n");
		printf("                              1.�ⶳѧ���˻�\n");
		printf("                                                                          \n");
		printf("                              2.������һ����\n");
		printf("                                                                          \n");
		printf("--------------------------------------------------------------------------\n");
		printf("�����룺");
		scanf("%d",&b);
		printf("\n");
		if(b==1)
		{
	    	printf("--------------------------------------------------------------------------\n");
	    	printf("                                                                          \n");
			printf("                         ����������ⶳ��ѧ��ѧ�ţ�                       \n");
			printf("                                                                          \n");
			printf("--------------------------------------------------------------------------\n");
			printf("�����룺");
			scanf("%s",id);
			printf("\n");
			a=1;
			fp1=fopen("ѧ����Ϣ.txt","r");
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
				printf("                             δ�ҵ���ѧ����Ϣ                             \n");
				printf("                                                                          \n");
				printf("--------------------------------------------------------------------------\n");
			}
			fclose(fp1);
			if(a==0)
			{
			    Frozen_Account1(id);
 	 			printf("--------------------------------------------------------------------------\n");
	       		printf("                                                                          \n");
		    	printf("                    ѧ��Ϊ%s��ѧ���˺��ѱ��ⶳ\n",id);
		    	printf("                                                                          \n");
		    	printf("--------------------------------------------------------------------------\n");
	    	}
		}
		if(b!=1&&b!=2)
		{
		    printf("--------------------------------------------------------------------------\n");
	        printf("                                                                          \n");
			printf("                          �������������������                          \n");
		    printf("                                                                          \n");
		    printf("--------------------------------------------------------------------------\n");
		system("pause");
		}
	}while(b!=2);
    printf("--------------------------------------------------------------------------\n");
	return 0;
}
void Frozen_Account(char idnumber[50])//�����˺�
{
	FILE *fp,*fp1;
	int a=1;
	fp=fopen("ѧ����Ϣ.txt","r");
	fp1=fopen("ѧ����Ϣtemp.txt","a+");
	if(fp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	struct students *pt;
	while(!feof(fp))
	{
        pt=(struct students*)malloc(LONGS);
		fscanf(fp,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,&pt->borrow_book_num,&pt->if_Frozen);
		if(strcmp(pt->idnumber,idnumber)==0)//������Ҫ������
	    {
			pt->if_Frozen=a;
			fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,pt->borrow_book_num,pt->if_Frozen);
	    }
		else    //��������Ҫ������
		fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,pt->borrow_book_num,pt->if_Frozen);
	}
	fclose(fp);
	fclose(fp1);
	system("del ѧ����Ϣ.txt");
    system("rename ѧ����Ϣtemp.txt ѧ����Ϣ.txt");//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
}
void Frozen_Account1(char idnumber[50])//�ⶳ�˺�
{
	FILE *fp,*fp1;
	int a=0;
	fp=fopen("ѧ����Ϣ.txt","r");
	fp1=fopen("ѧ����Ϣtemp.txt","a+");
	if(fp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	struct students *pt;
	pt=(struct students*)malloc(LONGS);
	while(!feof(fp))
	{
        pt=(struct students*)malloc(LONGS);
		fscanf(fp,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,&pt->borrow_book_num,&pt->if_Frozen);
		if(strcmp(pt->idnumber,idnumber)==0)//������Ҫ������
	    {
			pt->if_Frozen=a;
			fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,pt->borrow_book_num,pt->if_Frozen);
	    }
		else    //��������Ҫ������
  		fprintf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",pt->idnumber,pt->school,pt->major,pt->name,pt->gender,pt->phonenumber,pt->password,pt->mailbox,pt->borrow_book_num,pt->if_Frozen);
	}
	fclose(fp);
	fclose(fp1);
	system("del ѧ����Ϣ.txt");
    system("rename ѧ����Ϣtemp.txt ѧ����Ϣ.txt");//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
}
int BOOK_Borrow_situation()//ͼ����������ѯ
{
	int i=0,a=0,b,NotBorrowNum=0,BorrowNum=0;
	char name[100];
	FILE *fp1,*fp2;
	struct BOOK *p;
	struct BorrowInfo *m;
	fp1=fopen("ͼ�������Ϣ.txt","r");
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
		printf("                              �ѽ�������%d\n",BorrowNum);
	    printf("                              �ڹ�������%d\n\n",NotBorrowNum);
		printf("--------------------------------------------------------------------------\n");
	    printf("                                                                          \n");
		printf("                             �����루1~2��\n");
		printf("                            1.������Ŀ��ѯ\n");
		printf("                            2.�����ϼ��˵�\n");
		printf("                                                                          \n");
	    printf("--------------------------------------------------------------------------\n");
		printf("�����룺");
		scanf("%d",&a);
		if(a==1)
		{
		    printf("������������Ѱͼ�����֣�");//����ͼ���Ų�ѯͼ��������
			scanf("%s",name);
			b=0;
			fp2=fopen("ͼ��軹��Ϣ.txt","r");
			while(!feof(fp2))
		    {
				fscanf(fp2,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",m->borrow_booknum,m->borrow_bookname,&m->borrow_year,&m->borrow_month,&m->borrow_day,&m->borrow_hour,&m->borrow_minute,&m->return_year,&m->return_month,&m->return_day,&m->return_hour,&m->return_minute,&m->renew_num,m->borrow_student_idnum,m->borrow_student_name);
		        if(strcmp(name,m->borrow_bookname)==0)
		        {
		           	printf("--------------------------------------------------------------------------\n");
					printf("��Ŀ��ţ�%s\n",m->borrow_booknum);
		           	printf("����ʱ�䣺%d��%d��%d��%dʱ%d��\n",m->borrow_year,m->borrow_month,m->borrow_day,m->borrow_hour,m->borrow_minute);
		           	printf("����ʱ�䣺%d��%d��%d��%dʱ%d��\n",m->return_year,m->return_month,m->return_day,m->return_hour,m->return_minute);
		           	printf("���������%d\n",m->renew_num);
		           	printf("����ѧ��ѧ�ţ�%s\n",m->borrow_student_idnum);
				    printf("����ѧ��������%s\n\n",m->borrow_student_name);
				    b=1;
			    }
		    }
      		fclose(fp2);
		    if(b==0)
			printf("δ�ҵ������������ͼ�飡\n");
	    }
		if(a!=1&&a!=2)
		{
		    printf("--------------------------------------------------------------------------\n");
		    printf("                                                                          \n");
			printf("                         �������������������                          \n");
			printf("                                                                          \n");
			printf("--------------------------------------------------------------------------\n");
		}
		system("pause");
    }while(a!=2);
    return 0;
}
int Search_By_Student_Name_Or_Title()//ѧ�����������ѯ
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
    struct students information1;//ѧ����Ϣ
   	struct BorrowInfo information2;//ѧ��������Ϣ
	do
	{
		system("cls");
		printf("--------------------------------------------------------------------------\n");
	    printf("                                                                          \n");
		printf("                        �����루1~3��\n");
		printf("                      1.����ѧ��������ѯ\n");
		printf("                      2.����������ѯ\n");
		printf("                      3.�����ϼ��˵�\n");
		printf("                                                                          \n");
	    printf("--------------------------------------------------------------------------\n");
		printf("�����룺");
		scanf("%d",&a);
		b=0;
		if(a==1)
		{
			system("cls");
			b=0;
			fp1=fopen("ѧ����Ϣ.txt","r");
			printf("--------------------------------------------------------------------------\n");
	        printf("                                                                          \n");
			printf("           �����������ѯ��ѧ��������");//����ѧ��������ѯ����ͼ���ѧ����Ϣ
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
					printf("ѧ��������%s\n",name1);
			        printf("ѧ����Ϣ��\n");
					printf("  ѧ�ţ�%s Ժϵ��%s רҵ��%s �Ա�%s \n",m->idnumber,m->school,m->major,m->gender);
				    printf("  �绰��%s ���䣺%s \n",m->phonenumber,m->mailbox);
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
				printf("δ���ҵ���ѧ����Ϣ\n");
				c=1;
			}
			if(b==1)
			{
				c=0;
				fp2=fopen("ͼ��軹��Ϣ.txt","r");
				printf("--------------------------------------------------------------------------\n");
	            printf("                                                                          \n");
				printf("                   ��ѧ�������������");
				printf("                                                                          \n");
				printf("��Ŀ���       ����        ���ʱ��                �黹ʱ��             ������� \n");
				while(!feof(fp2))
				{
					fscanf(fp2,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",q->borrow_booknum,q->borrow_bookname,&q->borrow_year,&q->borrow_month,&q->borrow_day,&q->borrow_hour,&q->borrow_minute,&q->return_year,&q->return_month,&q->return_day,&q->return_hour,&q->return_minute,&q->renew_num,q->borrow_student_idnum,q->borrow_student_name);
				    if(strcmp(name1,q->borrow_student_name)==0)
				    {
						printf("%6s %12s   %4d��%2d��%2d��%2dʱ%2d��   %4d��%2d��%2d��%2dʱ%2d��     %3d \n",q->borrow_booknum,q->borrow_bookname,q->borrow_year,q->borrow_month,q->borrow_day,q->borrow_hour,q->borrow_minute,q->return_year,q->return_month,q->return_day,q->return_hour,q->return_minute,q->renew_num);
						b=1;
						c=1;
					}
				}
				fclose(fp2);
				printf("\n--------------------------------------------------------------------------\n");
				if(c==0)
				{
				    printf("δ�ҵ���ѧ��������Ϣ\n");
					c=1;
				}
			}
		}
		else if(a==2)
		{
			system("cls");
			fp2=fopen("ͼ��軹��Ϣ.txt","r");
			printf("--------------------------------------------------------------------------\n");
	        printf("                                                                          \n");
			printf("�����������ѯ������");//����������ѯ����ѧ������Ϣ
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
					printf("��Ŀ���   ����         ���ʱ��                   �黹ʱ��       �������      ѧ��ѧ��   ѧ������\n\n");
					printf("%6s   %6s   %4d��%2d��%2d��%2dʱ%2d��   %4d��%2d��%2d��%2dʱ%2d��    %2d           %s         %s\n\n",q->borrow_booknum,q->borrow_bookname,q->borrow_year,q->borrow_month,q->borrow_day,q->borrow_hour,q->borrow_minute,q->return_year,q->return_month,q->return_day,q->return_hour,q->return_minute,q->renew_num,q->borrow_student_idnum,q->borrow_student_name);
					b=1;
					c=1;
					fp1=fopen("ѧ����Ϣ.txt","r");
					while(!feof(fp1))
					{
						fscanf(fp1,"%s %s %s %s %s %s %s %s %d %d\n",m->idnumber,m->school,m->major,m->name,m->gender,m->phonenumber,m->password,m->mailbox,&m->borrow_book_num,&m->if_Frozen);
						if(strcmp(q->borrow_student_name,m->name)==0)
						{
							printf("        ѧ�ţ�%s    Ժϵ��%s     רҵ��%s    �Ա�%s \n\n",m->idnumber,m->school,m->major,m->gender);
							printf("        �绰��%s      ���䣺%20s \n\n",m->phonenumber,m->mailbox);
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
				printf("                   δ�ҵ������������ͼ�飡\n");
				printf("                                                                          \n");
    			printf("--------------------------------------------------------------------------\n");
				c=1;
			}
        }
		if(a!=1&&a!=2&&a!=3)
		{
		    printf("--------------------------------------------------------------------------\n");
	        printf("                                                                          \n");
			printf("                          �������������������                          \n");
		    printf("                                                                          \n");
		    printf("--------------------------------------------------------------------------\n");
		}
		system("pause");
    }while(a!=3);
    return 0;
}
int Sort_borrow_number()//ͨ�����Ĵ�������
{
	FILE *fp1;
	int i=0,j,a=0,t,x=0,lendtimes[100];
	char readed[100][100],y[100],name[10],id[50];
	fp1=fopen("ͼ�������Ϣ.txt","r");
	struct BOOK *p;
	system("cls");
	printf("--------------------------------------------------------------------------\n");
	printf("                                                                          \n");
	printf("                              ���Ĵ�������                              \n\n");
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
		fp1=fopen("ͼ�������Ϣ.txt","r");
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
		printf("       ��Ŀ:%20s       ",readed[j]);
		printf("���Ĵ�����%10d\n",lendtimes[j]);
		printf("                                                                          \n");
	}
    printf("\n--------------------------------------------------------------------------\n");
	system("pause");
	return 0;
}
int Sort_borrow_time()//ͨ������ʱ�䳤������
{
	FILE *fp1,*fp2;
	int i=0,j,a=0,t,x,readtime[100];
	char y[100],readed[100][100],name[10],id[50];
	fp1=fopen("ͼ��軹��Ϣ.txt","r");
	fp2=fopen("ͼ�������Ϣ.txt","r");
	struct BorrowInfo *m;
	struct BOOK *p;
	system("cls");
	printf("--------------------------------------------------------------------------\n");
	printf("                                                                          \n");
	printf("                            ����ʱ�䳤������                            \n");
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
		printf("       ��Ŀ:%20s       ",readed[j]);
		printf("����ʱ����%10d����\n",readtime[j]);
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
        printf("       ��Ŀ:%20s       ����ʱ��:          0����\n\n",p->bookname);
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
	fp1=fopen("ͼ�������Ϣ.txt","r");
	struct BOOK *p;
	printf("--------------------------------------------------------------------------\n");
	printf("                                                                          \n");
	printf("                              ͼ��۸�����                              \n");
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
		fp1=fopen("ͼ�������Ϣ.txt","r");
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
		printf("       ��Ŀ:%20s       ",readed[j]);
		printf("��Ŀ�۸�%3.2f\n\n",price[j]);
	}
    printf("\n--------------------------------------------------------------------------\n");
	system("pause");
	return 0;
}
int bookname_borrowtime(char bookname[100])//�����ÿһ����Ľ�����ʱ��
{
	int a;
	FILE *fpborrow;
	struct BorrowInfo *pborrow;
	int resttime1,resttime2,resttime3,resttime=0,borrow_year,borrow_month,borrow_day,borrow_hour,borrow_minute,return_year,return_month,return_day,return_hour,return_minute;
	fpborrow=fopen("ͼ��軹��Ϣ.txt","r");
	if(fpborrow==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	pborrow=(struct BorrowInfo*)malloc(LONGBORROW);
	while(!feof(fpborrow))
	{
		a=1;
		fscanf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,&pborrow->borrow_year,&pborrow->borrow_month,&pborrow->borrow_day,&pborrow->borrow_hour,&pborrow->borrow_minute,&pborrow->return_year,&pborrow->return_month,&pborrow->return_day,&pborrow->return_hour,&pborrow->return_minute,&pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
		if(strcmp(bookname,pborrow->borrow_bookname)==0)//��ȡ����ʱ��
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
  	 			resttime3=resttime1-resttime2;//���ν���ʱ��
            	resttime=resttime+resttime3;
            }
		}
	}
	fclose(fpborrow);
    return resttime;
}
int student_borrow_history(char studentid[20])//ѧ��������ʷ��ѯ
{
	int a=0;
	FILE *fpborrow;
	struct BorrowInfo *pborrow;
	FILE *fp;
	struct BOOK *p;
	char booknum[20];
	fpborrow=fopen("ͼ��軹��Ϣ.txt","r");
	if(fpborrow==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	pborrow=(struct BorrowInfo*)malloc(LONGBORROW);
	while(!feof(fpborrow))
	{
		fscanf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,&pborrow->borrow_year,&pborrow->borrow_month,&pborrow->borrow_day,&pborrow->borrow_hour,&pborrow->borrow_minute,&pborrow->return_year,&pborrow->return_month,&pborrow->return_day,&pborrow->return_hour,&pborrow->return_minute,&pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
		if(strcmp(studentid,pborrow->borrow_student_idnum)==0)
		{
			a=1;
			strcpy(booknum,pborrow->borrow_booknum);
			fp=fopen("ͼ�������Ϣ.txt","r");
			if(fp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
			p=(struct BOOK*)malloc(LONG);
			while(!feof(fp))
			{
				fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
				if(strcmp(booknum,p->booknum)==0)
				{
					printf("=================================================\n");
					printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","��ţ�",p->booknum,"������",p->bookname,"���ۣ�",p->price);
					printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","���ߣ�",p->writer,"�����磺",p->publisher,"����ʱ��:",p->publishtime);
					printf("%-8s%s\n\n","ͼ��λ�ã�",p->booklocation);
					printf("\n\n");
				}
			}
			fclose(fp);
		}
	}
	fclose(fpborrow);
	if(a==0)
	{
		printf("δ�ҵ���ѧ���Ľ�����ʷ��¼\n");
		return 0;
	}
	system("pause");
	return 1;
}
void renew_a_book(char stuID[20])//����
{
	int z,y,i;//zΪ1��ʱ���˳��ú���
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
	 	if(borrowtime(stuID)==0)//�г�ʱ
		{
			fpborrow=fopen("ͼ��軹��Ϣ.txt","r");
			if(fpborrow==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
			while(!feof(fpborrow))//��ȡ��ӡ�������Ϣ ����ӡ
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
					if(resttime>=43200)//���ͼ����Ϣ
					{
						strcpy(booknum1,pborrow->borrow_booknum);
						fp=fopen("ͼ�������Ϣ.txt","r");
						if(fp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
						while(!feof(fp))
						{
							fscanf(fp,"%s %s %s %f %s %s %s %d %s %d %d %d\n",p->booknum,p->bookname,p->writer,&p->price,p->publisher,p->publishtime,p->bookintroduction,&p->booksum,p->booklocation,&p->lend,&p->borrow,&p->lendtimes);
							if(strcmp(booknum1,p->booknum)==0)
							{
								printf("=================================================\n");
								printf("%-6s%-10s%-6s%-10s%-6s%-10.2f\n\n","��ţ�",p->booknum,"������",p->bookname,"���ۣ�",p->price);
								printf("%-6s%-10s%-6s%-12s %-6s%-14s\n\n","���ߣ�",p->writer,"�����磺",p->publisher,"����ʱ��:",p->publishtime);
								printf("%-8s%s\n\n\n\n","ͼ��λ�ã�",p->booklocation);
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
				printf("�������������ͼ����\n");
				scanf("%s",booknum);
				//�ж���������Ƿ�С�ڵ���2
				fpborrow=fopen("ͼ��軹��Ϣ.txt","r");
				if(fpborrow==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
				while(!feof(fpborrow))
				{
					fscanf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,&pborrow->borrow_year,&pborrow->borrow_month,&pborrow->borrow_day,&pborrow->borrow_hour,&pborrow->borrow_minute,&pborrow->return_year,&pborrow->return_month,&pborrow->return_day,&pborrow->return_hour,&pborrow->return_minute,&pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
					if(strcmp(booknum,pborrow->borrow_booknum)==0&&pborrow->return_year==0&&strcmp(stuID,pborrow->borrow_student_idnum)==0&&pborrow->renew_num<2)//��������
					i=1;
				}
				fclose(fpborrow);
				if(i==1)//������Ϣ������ʱ��->��Ϊ����ʱ�䣻���������һ
				{
					renew_a_book_change_borrowtime_and_renew_num(stuID,booknum);
					printf("\n����ɹ�\n");
				}
				if(i==0)
				{
					z=1;
					printf("\n\n�Ȿ���Ѿ��ﵽ��������\n����ϵͼ�����Ա�������˺ű�����\n");
					fpt=fopen("ͼ�����Ա��Ϣ.txt","a+");					//��ӡͼ�����Ա��Ϣ
					if(fpt==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
					while(!feof(fpt))
					{
						fscanf(fpt,"%s %s %s %s\n",pt->idnumber_t,pt->name_t,pt->password_t,pt->mailbox_t);
						printf("-------------------------------------------\n\n");
						printf("       ����          ����\n\n");
						printf("-------------------------------------------\n\n");
						printf("       %s             %s\n\n",pt->name_t,pt->mailbox_t);
					}
					fclose(fpt);
				}
				do
				{
					printf("\n=========================================================\n");
					printf("          ��1����������         ��2��������һ��\n");
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
						default://�ݴ�
						{
							system("cls");
							printf("�����������������\n");
							break;
						}
					}
				}while(y!=2);
			}while(z!=1);
		}
		else
		{
			printf("\n\n===========================================\n");
			printf("              �޳�ʱ��Ŀ�������������\n");
			printf("\n\n===========================================\n");
			do
			{
				printf("�����롾1��������һ��");
				scanf("%d",&z);
				switch(z)
				{
					case 1:
					{
						system("cls");
						break;
					}
					default://�ݴ�
					{
						printf("����������:\n");
						break;
					}
				}
			}while(z!=1);
		}
	}while(z!=1);
}
void renew_a_book_change_borrowtime_and_renew_num(char id[50],char booknumber[50])//����_����ͼ�����ʱ���Լ��������
{
	FILE *fpborrow,*fpborrowtemp;
	struct BorrowInfo *pborrow;
	int a=1;
	fpborrow=fopen("ͼ��軹��Ϣ.txt","r");
	if(fpborrow==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	fpborrowtemp=fopen("��ʱͼ��軹��Ϣ.txt","a+");
	if(fpborrowtemp==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	pborrow=(struct BorrowInfo*)malloc(LONGBORROW);
	time_t timep;
  	struct tm *ptm;
   	time (&timep);
    ptm=gmtime(&timep);
	while(!feof(fpborrow))
	{
	    fscanf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,&pborrow->borrow_year,&pborrow->borrow_month,&pborrow->borrow_day,&pborrow->borrow_hour,&pborrow->borrow_minute,&pborrow->return_year,&pborrow->return_month,&pborrow->return_day,&pborrow->return_hour,&pborrow->return_minute,&pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
		if(strcmp(booknumber,pborrow->borrow_booknum)!=0&&strcmp(id,pborrow->borrow_student_idnum)==0&&pborrow->return_year==0)//�������//����ѧ��//������ݵ���0
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
    system("del ͼ��軹��Ϣ.txt");
    system("rename ��ʱͼ��軹��Ϣ.txt ͼ��軹��Ϣ.txt");	//��ԭ�ļ�ɾ������ʱ�ļ��ĳ�ԭ�ļ�������
}
int borrowtime_booknumber(char idnumber[10])//����ͼ���Ų�ѯ��ͼ���Ƿ�ʱ
{
	int a;
	FILE *fpborrow;
	struct BorrowInfo *pborrow;
	int resttime,borrow_year,borrow_month,borrow_day,borrow_hour,borrow_minute;
	fpborrow=fopen("ͼ��軹��Ϣ.txt","r");
	if(fpborrow==NULL){printf("���ݿ�򿪴������顭��\n");exit(0);}
	pborrow=(struct BorrowInfo*)malloc(LONGBORROW);
	while(!feof(fpborrow))
	{
		a=1;
		fscanf(fpborrow,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",pborrow->borrow_booknum,pborrow->borrow_bookname,&pborrow->borrow_year,&pborrow->borrow_month,&pborrow->borrow_day,&pborrow->borrow_hour,&pborrow->borrow_minute,&pborrow->return_year,&pborrow->return_month,&pborrow->return_day,&pborrow->return_hour,&pborrow->return_minute,&pborrow->renew_num,pborrow->borrow_student_idnum,pborrow->borrow_student_name);
		if(strcmp(idnumber,pborrow->borrow_booknum)==0)//��ȡ����ʱ��
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
				return 1;//δ����
			}

			else
			{
				fclose(fpborrow);
				return 0;//����
			}

		}
	}
}
int Students_Favorite_Books_Each_Major()//��רҵͳ��ѧ����Ľ�����Ŀ
{
	FILE *fp1,*fp2,*fp3;
	int i=0,j=0,k=0,z=0,a=0,t=0,x=0,lendtimes[100];
	char bookname[100][100],major[100][100],y[100],name[10],id[50];
	struct BOOK *p;
	struct students *m;
	struct BorrowInfo *q;
	printf("--------------------------------------------------------------------------\n");
	printf("                                                                          \n");
	printf("                        ����רҵѧ������ĵ���Ŀ                        \n\n");
	fp1=fopen("ͼ�������Ϣ.txt","r");
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
	fp2=fopen("ѧ����Ϣ.txt","r");
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
		for(k=0;k<t;k++)//��ÿ�����ͳ�ƽ��Ĵ�������
		{
			lendtimes[k]=0;
		}
		fp2=fopen("ѧ����Ϣ.txt","r");
	    while(!feof(fp2))
		{
			m=(struct students*)malloc(LONGS);
			fscanf(fp2,"%s %s %s %s %s %s %s %s %d %d\n",m->idnumber,m->school,m->major,m->name,m->gender,m->phonenumber,m->password,m->mailbox,&m->borrow_book_num,&m->if_Frozen);
			if(strcmp(major[j],m->major)==0)//�����ѧ��רҵ��Ŀǰͳ�Ƶ�רҵһ��
			{
				fp3=fopen("ͼ��軹��Ϣ.txt","r");
				while(!feof(fp3))
			    {
					q=(struct BorrowInfo*)malloc(LONGBORROW);
				    fscanf(fp3,"%s %s %d %d %d %d %d %d %d %d %d %d %d %s %s\n",q->borrow_booknum,q->borrow_bookname,&q->borrow_year,&q->borrow_month,&q->borrow_day,&q->borrow_hour,&q->borrow_minute,&q->return_year,&q->return_month,&q->return_day,&q->return_hour,&q->return_minute,&q->renew_num,q->borrow_student_idnum,q->borrow_student_name);
					if(strcmp(m->name,q->borrow_student_name)==0)//ȥ������Ϣ�Ҹ�ѧ���������
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
		printf("��Ŀ����%8s     ���Ĵ���:%d\n\n",bookname[0],lendtimes[0]);
	}
	printf("\n--------------------------------------------------------------------------\n");
	system("pause");
	return 0;
}

