#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <process.h>
#include <string.h>
#include "head.h"

void bookingMenu()
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

    if(Empty_Flight()) {printf("����Ϊ�գ��޷���Ʊ��");return;}
    while(1)
    {
        printf("\n\t��������Զ�Ʊ!");
        flag = 0;
        Flight_No = 0;
        tag = 0;
        printf("\n\t�����뺽�ߺţ�"); scanf("%s",&answer);
        if(Find_Line(Head,answer,p1,Flight_No))
        {
            while(1)
            {
                printf("\n\t����������Ҫ������Ʊ��������");
                scanf("%d",&Ticket_Count);
                if(Ticket_Count<0)
                {
                    printf("\n\t���ٴ���������Ҫ������Ʊ��������"); getch();
                }
                else break;
            }
            if(p1->Free_Amount>=Ticket_Count)
            {
                Customer_Count++;
                flag = 1;
                IsRepl = 1;
                if(p1->CustName==NULL)
                {
                    Custp1[Flight_No] = p2 = new Customer;
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
                printf("\n\t����������������");
                scanf("%s",&Custp1[Flight_No]->Name);
                while(1)
                {
                    printf("\n\t�������λ�ȼ���"); scanf("%s",&Custp1[Flight_No]->Rank);
                    if(!(Custp1[Flight_No]->Rank>='1'&&Custp1[Flight_No]->Rank<='3'))
                    {
                        printf("\n\t�����������������룡"); getchar();getchar();
                    }
                    else break;
                }
                printf("\n\t���������ID��Ϣ��"); scanf("%d",&Custp1[Flight_No]->IDinfor);
                if(Ticket_Count<10) printf("\n\t");
                else printf("\n\t");
                printf("\n\t��Ʊ�ɹ���\n");
                for(i = 1;i<=Ticket_Count;i++)
                {
                    printf("\n\t����Ԥ������λ����%d",Seatnum++);
                    if(i%10==0) printf("\n\t");
                }
                printf("\n");
            }
            else if(p1->Free_Amount == 0)
            {
                printf("\n\t��Ǹ��Ʊ�����꣡\n"); IsRepl = 0;
            }
            else
            {
                printf("\n\t��Ǹ����ǰû���㹻�����Ʊ��"); IsRepl = 0;
            }
            if(!IsRepl)
            {
                printf("\n\t���Ƿ������Ϊ�򲹳˿ͣ���Y/N��"); scanf("%s",&temp);
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
                    printf("\n\t����������������"); scanf("%s",&Replp1[Flight_No]->Name);
                    Replp1[Flight_No]->Amount = Ticket_Count;
                    while(1)
                    {
                        printf("\n\t�������λ�ȼ���"); scanf("%s",&Replp1[Flight_No]->Rank);
                        printf("\n\t����������ID��Ϣ��"); scanf("%d",&Replp1[Flight_No]->IDinfor);
                        if(!(Replp1[Flight_No]->Rank>='1'&&Replp1[Flight_No]->Rank<='3'))
                        {
                            printf("\n\t�����������������룡"); getchar();getchar();
                        }
                        else break;
                    }
                    printf("\n\tû��ʣ�����λ��\n");
                    shouldsave = 1;
                }
            }
        }
        //else printf("\n\t�Բ��𣬺��߲����ڣ�\n");
        else
        {
            printf("\n\t�Բ��𣬺��߲����ڣ�\n");
            printf("\n\t�Ƿ��������·���Ƽ�ϵͳ��Y/N����\n"); scanf("%s",&b);
            if(b == 'y'||b == 'Y')
            {
                printf("\n\t������������վ����"); scanf("%s",&starn);
                printf("\n\t����������յ�վ����"); scanf("%s",&endn);
                printf("\n\t��ʼ��������ת���Ƽ�...\n");
                while(p4!=NULL)
                {
                    if(strcmp(p4->Star_Name,starn)==0&&strcmp(p4->Des_Name,endn)==0)
                    {
                        printf("\n\t���ɳ˴�˺��࣬����ת�˵���Ŀ�ĵأ�\n");
                        printf("\n����������������������������������������������������\n");
                        printf("���վ �յ�վ ����� �ɻ��� ����ܼ� �˿Ͷ��� ʣ��Ʊ�� 1�����۸� 2�����۸� 3�����۸�");
                        printf("\n%-9s%-9s%-9s%-10s%-9d%-9d%-9d%-8d%-8d%-8d",p4->Star_Name,p4->Des_Name,p4->Flight_No,p4->Plane_No,p4->Week_Day,p4->Customer_Amount,p4->Free_Amount,p4->Price[0],p4->Price[1],p1->Price[2]);
                        printf("\n����������������������������������������������������\n");
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
                                printf("\n\t���ɳ˴�������࣬��һ��ת�˵���Ŀ�ĵأ�\n");
                                printf("\n����������������������������������������������������\n");
                                printf("���վ �յ�վ ����� �ɻ��� ����ܼ� �˿Ͷ��� ʣ��Ʊ�� 1�����۸� 2�����۸� 3�����۸�");
                                printf("\n%-9s%-9s%-9s%-10s%-9d%-9d%-9d%-8d%-8d%-8d",p4->Star_Name,p4->Des_Name,p4->Flight_No,p4->Plane_No,p4->Week_Day,p4->Customer_Amount,p4->Free_Amount,p4->Price[0],p4->Price[1],p4->Price[2]);
                                printf("\n%-9s%-9s%-9s%-10s%-9d%-9d%-9d%-8d%-8d%-8d",p5->Star_Name,p5->Des_Name,p5->Flight_No,p5->Plane_No,p5->Week_Day,p5->Customer_Amount,p5->Free_Amount,p5->Price[0],p5->Price[1],p5->Price[2]);
                                printf("\n����������������������������������������������������\n"); point = 1;break;
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
            printf("\n\t���Ѿ��ɹ�����򲹶�Ʊ�����У�\n");
        }
        printf("\n\t�Ƿ��˳��˵�������Y/N��");
        scanf("%s",&c);
        if(c == 'y'||c=='Y') return;

    }
}
