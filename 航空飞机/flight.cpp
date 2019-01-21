
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
        printf("\n\t�Ƿ������Y/N��?");
        scanf("%s",&answer);
        system("cls");
        if(answer=='y'||answer=='Y') return 'y';
        else if(answer=='N'||answer=='n') return 'n';
        else printf("\n\t���������������룡");
    }
}

void ErrorMess()
{
    printf("\n\t��������");
    getch();
}

int Find_Line(PFlight L,char *key)//���ݺ��ߺŲ��Һ���
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

int Find_Line(PFlight L,char *key,PFlight &p2,int &Flight_No)//���Ҳ��õ�ָ��ú����ָ�����������λ��
{
    int flag = 0;
    Flight *p1;
    p1 = L;
    while(p1!=NULL)
    {
        if(strcmp(p1->Flight_No,key)==0)
        {
            flag = 1;
            p2 = p1;//��ֵ��p2
            break;
        }
        p1 = p1->Next;
        if(p1!=NULL) Flight_No++;
    }
    return flag;
}

void Line_search()//������������
{
    Flight *p1=Head;
    char Desname[50];
    char Starname[50];
    if(Head==NULL)
    {
        printf("\n\tû���������ҵĺ��࣡"); getchar();getchar();
        return ;
    }
    printf("\n\t���������վ����"); scanf("%s",Starname);
    printf("\n\t�������յ�վ����"); scanf("%s",Desname);
    printf("\n������������������������������������������������������������������������\n");
    while(p1!=NULL)
    {
        if(strcmp(p1->Star_Name,Starname)==0&&strcmp(p1->Des_Name,Desname)==0)
        {
            printf("���վ �յ�վ ����� �ɻ��� ����ܼ� �˿Ͷ��� ʣ��Ʊ�� 1�����۸� 2�����۸� 3�����۸�");
            printf("\n%-8s%-7s%-8s%-9s%-8d%-9d%-9d%-10d%-10d%-9d",p1->Star_Name,p1->Des_Name,p1->Flight_No,p1->Plane_No,p1->Week_Day,p1->Customer_Amount,p1->Free_Amount,p1->Price[0],p1->Price[1],p1->Price[2]);
        }
        p1 = p1->Next;
    }
    printf("\n����������������������������������������������������������������������\n");
    Continue();
}

void Line_Add()//�������
{
    Flight *p1;
    while(1)
    {
        if(Head == NULL)//���߲�����
        {
            p1 = (Flight*)malloc(sizeof(Flight));//���׸����
            p2 = p1;
            Head = p2;
        }else
        {
            p1 = (Flight*)malloc(sizeof(Flight));
            p2->Next = p1;
            p2 = p1;
        }
        printf("\n\t����µĺ��ߣ�\n");
        printf("\n\t���������վ����");
        scanf("%s",&p2->Star_Name);
        printf("\n\t�������յ�վ����");
        scanf("%s",&p2->Des_Name);
        while(1)
        {
            printf("\n\t�����뺽��ţ������ظ���:"); scanf("%s",&p2->Flight_No);

            if(Find_Line(Head,p2->Flight_No)) printf("������Ѵ��ڣ�\n");
            else break;
        }
        printf("\n\t������ɻ��ţ�"); scanf("%s",&p2->Plane_No);
        while(1)
        {

            printf("\n\t�����뺽������ڣ�1-7����"); scanf("%d",&p2->Week_Day);
            if(p2->Week_Day<1||p2->Week_Day>7) printf("\n\t���������������������룡\n");
            else break;
        }
        printf("\n\t��������λ������"); scanf("%d",&p2->Customer_Amount);
        printf("\n\t������һ�����۸�"); scanf("%d",&p2->Price[0]);
        printf("\n\t������������۸�"); scanf("%d",&p2->Price[1]);
        printf("\n\t�������������۸�"); scanf("%d",&p2->Price[2]);
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


int Empty_Flight()//�ж��Ƿ���ں���
{
    if(Head == NULL)
    {
        system("cls");
        printf("\n\t���߲����ڣ�����������أ�"); getchar();getchar();
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
    printf("\n����������������������������������������������������\n");
    printf("���վ �յ�վ ����� �ɻ��� ����ܼ� �˿Ͷ��� ʣ��Ʊ�� 1�����۸� 2�����۸� 3�����۸�");
    while(p1!=NULL)
    {
      printf("\n%-8s%-7s%-8s%-9s%-8d%-9d%-9d%-10d%-10d%-9d",p1->Star_Name,p1->Des_Name,p1->Flight_No,p1->Plane_No,p1->Week_Day,p1->Customer_Amount,p1->Free_Amount,p1->Price[0],p1->Price[1],p1->Price[2]);
      p1 = p1->Next;
    }
    printf("\n����������������������������������������������������\n");
    printf("\n\t����������أ�\n"); getchar();getchar();
}

void LinemanageMenu()
{
    char c;
    system("cls");
    while(1)
    {
        printf("\n\t\t���߹���˵���");
        printf("\n��������������������������������������������������������\n\n");
        printf("\t1.����µĺ���\n");
        printf("\t2.��ѯ����\n");
        printf("\t3.�鿴���к���\n");
        printf("\t4.�������˵�\n");
        printf("\n��������������������������������������������������������\n");
        printf("\t��ѡ����Ҫ�ķ���");
        scanf("%s",&c);
        switch(c)
        {
            case '1':Line_Add(); break;
            case '2':Line_search(); break;
            case '3':Line_See(); break;
            case '4':return;        }
    }
}
