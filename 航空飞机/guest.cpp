#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <process.h>
#include <string.h>
#include "head.h"

void bookingMenu()//订票
{
    int Ticket_Count,IDinfor,i,flag = 0,Seatnum;
    int Flight_No = 0;
    Flight *p1;
    Customer *p2;
    Customer *p3;
    char answer[7];
    char temp,c;
    int tag = 0;
    int IsRepl = 0;

    char b;
    int num = 0;
    Flight *fstar[10];
    Flight *fend[10];
    char starn[7];
    char endn[7];
    Flight *p4 = Head;

    if(Empty_Flight()) {printf("航线为空，无法订票！");return;}//没有航线
    while(1)
    {
        printf("\n\t现在你可以订票!");
        flag = 0;
        Flight_No = 0;
        tag = 0;
        printf("\n\t请输入航线号："); scanf("%s",&answer);
        if(Find_Line(Head,answer,p1,Flight_No))//查找航线
        {
            while(1)
            {
                printf("\n\t请输入你想要订购的票的数量：");
                scanf("%d",&Ticket_Count);
                if(Ticket_Count<0)
                {
                    printf("\n\t请再次输入你想要订购的票的数量："); getch();
                }
                else break;
            }
            if(p1->Free_Amount>=Ticket_Count)//若票源充足
            {
                Customer_Count++;//总乘客加1
                flag = 1;
                IsRepl = 1;
                if(p1->CustName==NULL)//第一个乘客
                {
                    Custp1[Flight_No] = p2 = new Customer;//创建新的乘客结点
                    p1->CustName = Custp1[Flight_No];
                }
                else
                {
                    p2 = new Customer;
                    Custp1[Flight_No]->Next = p2;
                    Custp1[Flight_No] = p2;
                }
                IsEmpty = 0;
                Custp1[Flight_No]->Amount = Ticket_Count;
                //IDinfor = p1->Customer_Amount-p1->Free_Amount+1;
                Seatnum = p1->Customer_Amount - p1->Free_Amount +1;
                //Custp1[Flight_No]->IDinfor = IDinfor;
                Custp1[Flight_No]->Seatnum = Seatnum;
                p1->Free_Amount-=Ticket_Count;
                printf("\n\t请输入您的姓名：");
                scanf("%s",&Custp1[Flight_No]->Name);
                while(1)
                {
                    printf("\n\t请输入舱位等级："); scanf("%s",&Custp1[Flight_No]->Rank);
                    if(!(Custp1[Flight_No]->Rank>='1'&&Custp1[Flight_No]->Rank<='3'))
                    {
                        printf("\n\t输入有误，请重新输入！"); getchar();getchar();
                    }
                    else break;
                }
                printf("\n\t请输入你的ID信息："); scanf("%d",&Custp1[Flight_No]->IDinfor);
                if(Ticket_Count<10) printf("\n\t");
                else printf("\n\t");
                printf("\n\t订票成功！\n");
                for(i = 1;i<=Ticket_Count;i++)
                {
                    printf("\n\t您所预定的座位号是%d",Seatnum++);
                    if(i%10==0) printf("\n\t");
                }
                printf("\n");
            }
            else if(p1->Free_Amount == 0)
            {
                printf("\n\t抱歉，票已售完！\n"); IsRepl = 0;
            }
            else
            {
                printf("\n\t抱歉，当前没有足够多余的票！"); IsRepl = 0;
            }
            if(!IsRepl)
            {
                printf("\n\t您是否申请成为候补乘客？（Y/N）"); scanf("%s",&temp);
                if(temp == 'y'||temp == 'Y')
                {
                    if(p1->ReplName == NULL)
                    {
                        Replp1[Flight_No] = p3 = new Customer;
                        p1->ReplName = Replp1[Flight_No];
                    }
                    else
                    {
                        p3 = new Customer;
                        Replp1[Flight_No]->Next = p3;
                        Replp1[Flight_No] = p3;
                    }
                    IsReplace = 0;
                    tag = 1;
                    Replp1[Flight_No]->Amount = Ticket_Count;
                    printf("\n\t请输入您的姓名："); scanf("%s",&Replp1[Flight_No]->Name);
                    Replp1[Flight_No]->Amount = Ticket_Count;
                    while(1)
                    {
                        printf("\n\t请输入舱位等级："); scanf("%s",&Replp1[Flight_No]->Rank);
                        printf("\n\t请输入您的ID信息："); scanf("%d",&Replp1[Flight_No]->IDinfor);
                        if(!(Replp1[Flight_No]->Rank>='1'&&Replp1[Flight_No]->Rank<='3'))
                        {
                            printf("\n\t输入有误，请重新输入！"); getchar();getchar();
                        }
                        else break;
                    }
                    printf("\n\t没有剩余的座位！\n");
                    shouldsave = 1;
                }
            }
        }
        //else printf("\n\t对不起，航线不存在！\n");
        else
        {
            printf("\n\t对不起，航线不存在！\n");
            printf("\n\t是否进入智能路线推荐系统（Y/N）？"); scanf("%s",&b);
            if(b == 'y'||b == 'Y')
            {
                printf("\n\t请输入你的起飞站名："); scanf("%s",&starn);
                printf("\n\t请输入你的终点站名："); scanf("%s",&endn);
                printf("\n\t开始进行智能转乘推荐...\n");
                while(p4!=NULL)
                {
                    if(strcmp(p4->Star_Name,starn)==0&&strcmp(p4->Des_Name,endn)==0)
                    {
                        printf("\n\t您可乘搭此航班，无需转乘到达目的地：\n");
                        printf("\n——————————————————————————\n");
                        printf("起点站 终点站 航班号 飞机号 起飞周几 乘客定额 剩余票数 1等座价格 2等座价格 3等座价格");
                        printf("\n%-8s%-7s%-8s%-9s%-8d%-9d%-9d%-10d%-10d%-9d",p4->Star_Name,p4->Des_Name,p4->Flight_No,p4->Plane_No,p4->Week_Day,p4->Customer_Amount,p4->Free_Amount,p4->Price[0],p4->Price[1],p4->Price[2]);
                        printf("\n——————————————————————————\n");
                    }
                    else if(strcmp(p4->Star_Name,starn)==0) {fstar[num] = p4;num++;}
                    else if(strcmp(p4->Des_Name,endn)==0) {fend[num] = p4;num++;}
                    p4 = p4->Next;
                }
                if(fstar!=NULL&&fend!=NULL)
                {
                    int j=0;p4 = fstar[0];int point = 0;
                    while(p4!=NULL)
                    {
                        //p4->Des_Name
                        int k = 0; Flight *p5 = fend[0];
                        while(p5!=NULL)
                        {
                            if(strcmp(p4->Des_Name,p5->Star_Name)==0)
                            {
                                printf("\n\t您可乘搭此两航班，经一次转乘到达目的地：\n");
                                printf("\n——————————————————————————\n");
                                printf("起点站 终点站 航班号 飞机号 起飞周几 乘客定额 剩余票数 1等座价格 2等座价格 3等座价格");
                                printf("\n%-8s%-7s%-8s%-9s%-8d%-9d%-9d%-10d%-10d%-9d",p4->Star_Name,p4->Des_Name,p4->Flight_No,p4->Plane_No,p4->Week_Day,p4->Customer_Amount,p4->Free_Amount,p4->Price[0],p4->Price[1],p4->Price[2]);
                                printf("\n%-8s%-7s%-8s%-9s%-8d%-9d%-9d%-10d%-10d%-9d",p5->Star_Name,p5->Des_Name,p5->Flight_No,p5->Plane_No,p5->Week_Day,p5->Customer_Amount,p5->Free_Amount,p5->Price[0],p5->Price[1],p5->Price[2]);
                                printf("\n——————————————————————————\n"); point = 1;break;
                            }
                            k++;
                            p5 = fend[k];
                        }
                        if(point == 1) break;
                        j++; p4 = fstar[j];
                    }
                }
            }

        }
        if(flag) Custp1[Flight_No]->Next = NULL;
        if(tag)
        {
            Replp1[Flight_No]->Next = NULL;
            printf("\n\t您已经成功排入候补订票队列中！\n");
        }
        printf("\n\t是否退出菜单？：（Y/N）");
        scanf("%s",&c);
        if(c == 'y'||c=='Y') return;

    }
}

void Display_Reserve()
{
    system("cls");
    Flight *p1;
    Customer *p2;
    p1 = Head;
    if(IsEmpty)
    {
        printf("\n\t对不起，没有订票乘客信息！\n"); getchar();getchar();
        return ;
    }
    printf("\n——————————————————————————————————————\n");
    printf("姓名 航班号 飞机号 购票数 起点站名 终点站名 舱位等级  座位号 id信息\n");
    while(p1!=NULL)
    {
        if(p1->CustName!=NULL)
        {
            p2=p1->CustName;
            while(p2!=NULL)
            {
                printf("\n%-6s%-8s%-8s%-6d%-9s%-9s%-9c%-8d%-6d",p2->Name,p1->Flight_No,p1->Plane_No,p2->Amount,p1->Star_Name,p1->Des_Name,p2->Rank,p2->Seatnum,p2->IDinfor);
                if(p1->Free_Amount>=1) printf("\n\n\t还有多余的票！\n");
                else printf("\n\n\t票已售完！\n");
                p2=p2->Next;
            }
        }
        p1=p1->Next;
        printf("\n\n————————————————————————————————————————————\n");
    }
    printf("\n\t按任意键返回！"); getchar();getchar();//getch();
    return ;
}

void Display_Replace()
{
    system("cls");
    Flight * p1;
    Customer *p2;
    p1 = Head;
    if(Empty_Flight()) return;
    printf("\n\t候补乘客信息！");
    if(IsReplace)
    {
        printf("\n\t抱歉，没有候补乘客！\n"); getchar();getchar();
        return ;
    }
        printf("\n——————————————————————————————————————————————\n");
        printf("姓名 航班号 飞机号 购票数 起点站名 终点站名 舱位等级 id信息\n");
        while(p1!=NULL)
        {
            if(p1->ReplName!=NULL)
            {
                p2=p1->ReplName;
                while(p2!=NULL)
                {
                    printf("\n%-6s%-8s%-8s%-6d%-9s%-9s%-9c%-8d%-6d",p2->Name,p1->Flight_No,p1->Plane_No,p2->Amount,p1->Star_Name,p1->Des_Name,p2->Rank,p2->IDinfor);
                    if(p1->Free_Amount>=1) printf("\n\t还有多余的票！\n");
                    else printf("\n\t票已售完！\n");
                    p2=p2->Next;
                }
            }
            p1=p1->Next;
        }
        printf("\n\n————————————————————————————————————————\n");
        printf("\n\n按任意键返回！"); getchar();getchar();
        return ;

}

void RefundticketMenu()//退票
{
    int Flight_No = 0,flag = 0;
    Flight *p1;
    Customer *p2,*p4,*p3,*p5;
    char answer[7],name[7];
    int id;
    int tag = 0;
    int Seatnum;
    if(Empty_Flight()) return;
    printf("\n\t现在开始进行退票手续");
    if(IsEmpty)
    {
        printf("\n\t对不起，乘客不存在！"); getchar();getchar();
        return ;
    }
    while(1)
    {
        flag = 0; tag = 0; Flight_No = 0;
        printf("\n\t请输入航线："); scanf("%s",&answer);
        if(Find_Line(Head,answer,p1,Flight_No))
        {
            p2=p1->CustName;
            printf("\n\t请输入您的姓名："); scanf("%s",&name);
            printf("\n\t请输入您的ID信息："); scanf("%d",&id);
            if(p2==NULL)
            {
                printf("\n\t抱歉，乘客不存在！");
                if(Continue()=='n') return;
            }
            else
                while(p2!=NULL)
            {
                if(strcmp(p2->Name,name)==0&&(p2->IDinfor==id))
                {
                    if(p2==p1->CustName)//若为首位乘客
                    {
                        prior = p1->CustName;//记录指针
                        Seatnum = p2->Seatnum;//记录被删乘客的座位号
                        flag = 1;break;
                    }
                }
                else if(p2->Next!=NULL)//记录满足航线的前结点地址
                {
                    if(strcmp(p2->Next->Name,name)==0)
                    {
                        tag = 1;
                        prior = p2;//记录满足订票乘客的前一地址
                        Seatnum = p2->Next->Seatnum;
                        flag = 1;break;
                    }
                }
                p2=p2->Next;
                shouldsave = 1;
            }
            if(!flag) printf("\n\t抱歉，乘客不存在！\n");
        }
        else printf("\n\t对不起，航线不存在！\n");
        if(flag)
        {
            if(prior == p1->CustName&&!tag)//首结点满足
            {
                if(prior->Next==NULL)//只有一个乘客
                {
                    p1->Free_Amount+=prior->Amount;
                    p1->CustName = NULL;
                }
                else//后面还有人
                {
                    p1->Free_Amount+=prior->Next->Amount;
                    p1->CustName = prior->Next;
                }
            }
            else//不是首结点
            {
                p1->Free_Amount+=prior->Next->Amount;
                prior->Next=prior->Next->Next;
            }

        Customer_Count--;
        if(Customer_Count==0) IsEmpty = 1;
        shouldsave = 1;
    }
    if(flag)//存在退票操作
    {
        p3=p1->ReplName;
        while(p3!=NULL)
        {
            if(p3->Amount<=p1->Free_Amount)//候补乘客的订票数小于或等于剩余票数
            {
                printf("\n\t候补乘客存在！\n");
                p4 = Custp1[Flight_No]->Next = new Customer;
                p4->Next = NULL;
                IsEmpty = 0;
                if(p1->CustName==NULL) p1->CustName = p4;
                strcpy(p4->Name,p3->Name);
                p4->Rank = p3->Rank;
                p4->Amount = p3->Amount;
                p4->IDinfor = p3->IDinfor;
                p4->Seatnum = Seatnum;
                p1->Free_Amount-=p3->Amount;
                Customer_Count++;
                if(p3->Next==NULL) IsReplace = 1;
                if(p1->ReplName == p3)
                {
                    if(p1->ReplName->Next == NULL) p1->ReplName = NULL;
                    else p1->ReplName = p3->Next;
                }
                else p5->Next = p3->Next->Next;
                break;
            }
            if(p3->Next!=NULL)
                if(p3->Next->Amount<=p1->Free_Amount)
                p5 = p3;
            p3=p3->Next;
            shouldsave = 1;
        }
        printf("\n\t退票成功！"); getchar();getchar();//getch();
        return ;
    }
    shouldsave = 1;
    if(Continue() == 'n') return ;
}
}

void CustomermagMenu()
{
    char c;
    system("cls");
    while(1)
    {
        printf("\n\t\t乘客管理菜单：\n");
        printf("\n————————————————————————————————————\n\n");
        printf("\t1.乘客信息\n");
        printf("\t2.候补乘客信息\n");
        printf("\t3.返回主菜单\n");
        printf("\n—————————————————————————————————————\n");
        printf("请选择您想要的服务："); scanf("%s",&c);
        switch(c)
        {
            case '1':Display_Reserve();break;
            case '2':Display_Replace(); break;
            case '3':return ;
            default :ErrorMess();
        }
    }
}
