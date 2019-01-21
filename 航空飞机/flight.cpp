
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <process.h>
#include <string.h>
#include "head.h"

char Continue()
{
    char answer;
    while(1)
    {
        printf("\n\t是否继续（Y/N）?");
        scanf("%s",&answer);
        system("cls");
        if(answer=='y'||answer=='Y') return 'y';
        else if(answer=='N'||answer=='n') return 'n';
        else printf("\n\t输入有误，请重输入！");
    }
}

void ErrorMess()
{
    printf("\n\t操作有误！");
    getch();
}

int Find_Line(PFlight L,char *key)//根据航线号查找航班
{
    int flag = 0;
    Flight *p1;
    p1 = L;
    if(p1==p2) return flag;
    while(p1!=p2&&p1!=NULL)
    {
        if(strcmp(p1->Flight_No,key)==0)
        {
            flag = 1;break;
        }
        p1 = p1->Next;
    }
    return flag;

}

int Find_Line(PFlight L,char *key,PFlight &p2,int &Flight_No)//查找并得到指向该航班的指针与在链表的位置
{
    int flag = 0;
    Flight *p1;
    p1 = L;
    while(p1!=NULL)
    {
        if(strcmp(p1->Flight_No,key)==0)
        {
            flag = 1;
            p2 = p1;//赋值给p2
            break;
        }
        p1 = p1->Next;
        if(p1!=NULL) Flight_No++;
    }
    return flag;
}

void Line_search()//航线搜索界面
{
    Flight *p1=Head;
    char Desname[50];
    char Starname[50];
    if(Head==NULL)
    {
        printf("\n\t没有你所查找的航班！"); getchar();getchar();
        return ;
    }
    printf("\n\t请输入起点站名："); scanf("%s",Starname);
    printf("\n\t请输入终点站名："); scanf("%s",Desname);
    printf("\n————————————————————————————————————\n");
    while(p1!=NULL)
    {
        if(strcmp(p1->Star_Name,Starname)==0&&strcmp(p1->Des_Name,Desname)==0)
        {
            printf("起点站 终点站 航班号 飞机号 起飞周几 乘客定额 剩余票数 1等座价格 2等座价格 3等座价格");
            printf("\n%-8s%-7s%-8s%-9s%-8d%-9d%-9d%-10d%-10d%-9d",p1->Star_Name,p1->Des_Name,p1->Flight_No,p1->Plane_No,p1->Week_Day,p1->Customer_Amount,p1->Free_Amount,p1->Price[0],p1->Price[1],p1->Price[2]);
        }
        p1 = p1->Next;
    }
    printf("\n———————————————————————————————————\n");
    Continue();
}

void Line_Add()//航线添加
{
    Flight *p1;
    while(1)
    {
        if(Head == NULL)//航线不存在
        {
            p1 = (Flight*)malloc(sizeof(Flight));//建首个结点
            p2 = p1;
            Head = p2;
        }else
        {
            p1 = (Flight*)malloc(sizeof(Flight));
            p2->Next = p1;
            p2 = p1;
        }
        printf("\n\t添加新的航线！\n");
        printf("\n\t请输入起点站名：");
        scanf("%s",&p2->Star_Name);
        printf("\n\t请输入终点站名：");
        scanf("%s",&p2->Des_Name);
        while(1)
        {
            printf("\n\t请输入航班号（不能重复）:"); scanf("%s",&p2->Flight_No);

            if(Find_Line(Head,p2->Flight_No)) printf("航班号已存在！\n");
            else break;
        }
        printf("\n\t请输入飞机号："); scanf("%s",&p2->Plane_No);
        while(1)
        {

            printf("\n\t请输入航班的日期（1-7）："); scanf("%d",&p2->Week_Day);
            if(p2->Week_Day<1||p2->Week_Day>7) printf("\n\t输入日期有误，请重新输入！\n");
            else break;
        }
        printf("\n\t请输入座位数量："); scanf("%d",&p2->Customer_Amount);
        printf("\n\t请输入一等座价格："); scanf("%d",&p2->Price[0]);
        printf("\n\t请输入二等座价格："); scanf("%d",&p2->Price[1]);
        printf("\n\t请输入三等座价格："); scanf("%d",&p2->Price[2]);
        p2->Free_Amount = p2->Customer_Amount;
        p2->CustName = NULL;
        p2->ReplName = NULL;
        shouldsave = 1;
        if(Continue()=='n')
        {
            p2->Next = NULL;
            return;
        }
    }
}


int Empty_Flight()//判断是否存在航线
{
    if(Head == NULL)
    {
        system("cls");
        printf("\n\t航线不存在，按任意键返回！"); getchar();getchar();
        return 1;
    }
    else return 0;
}


void Line_See()
{
    system("cls");
    Flight *p1;
    p1 = Head;
    if(Empty_Flight()) return;
    printf("\n——————————————————————————\n");
    printf("起点站 终点站 航班号 飞机号 起飞周几 乘客定额 剩余票数 1等座价格 2等座价格 3等座价格");
    while(p1!=NULL)
    {
      printf("\n%-8s%-7s%-8s%-9s%-8d%-9d%-9d%-10d%-10d%-9d",p1->Star_Name,p1->Des_Name,p1->Flight_No,p1->Plane_No,p1->Week_Day,p1->Customer_Amount,p1->Free_Amount,p1->Price[0],p1->Price[1],p1->Price[2]);
      p1 = p1->Next;
    }
    printf("\n——————————————————————————\n");
    printf("\n\t按任意键返回！\n"); getchar();getchar();
}

void LinemanageMenu()
{
    char c;
    system("cls");
    while(1)
    {
        printf("\n\t\t航线管理菜单：");
        printf("\n————————————————————————————\n\n");
        printf("\t1.添加新的航线\n");
        printf("\t2.查询航线\n");
        printf("\t3.查看所有航线\n");
        printf("\t4.返回主菜单\n");
        printf("\n————————————————————————————\n");
        printf("\t请选择你要的服务：");
        scanf("%s",&c);
        switch(c)
        {
            case '1':Line_Add(); break;
            case '2':Line_search(); break;
            case '3':Line_See(); break;
            case '4':return;        }
    }
}
