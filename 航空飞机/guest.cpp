#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <process.h>
#include <string.h>
#include "head.h"

void bookingMenu()//��Ʊ
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

    if(Empty_Flight()) {printf("����Ϊ�գ��޷���Ʊ��");return;}//û�к���
    while(1)
    {
        printf("\n\t��������Զ�Ʊ!");
        flag = 0;
        Flight_No = 0;
        tag = 0;
        printf("\n\t�����뺽�ߺţ�"); scanf("%s",&answer);
        if(Find_Line(Head,answer,p1,Flight_No))//���Һ���
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
            if(p1->Free_Amount>=Ticket_Count)//��ƱԴ����
            {
                Customer_Count++;//�ܳ˿ͼ�1
                flag = 1;
                IsRepl = 1;
                if(p1->CustName==NULL)//��һ���˿�
                {
                    Custp1[Flight_No] = p2 = new Customer;//�����µĳ˿ͽ��
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
            printf("\n\t�Ƿ��������·���Ƽ�ϵͳ��Y/N����"); scanf("%s",&b);
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
                        printf("\n%-8s%-7s%-8s%-9s%-8d%-9d%-9d%-10d%-10d%-9d",p4->Star_Name,p4->Des_Name,p4->Flight_No,p4->Plane_No,p4->Week_Day,p4->Customer_Amount,p4->Free_Amount,p4->Price[0],p4->Price[1],p4->Price[2]);
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
                                printf("\n%-8s%-7s%-8s%-9s%-8d%-9d%-9d%-10d%-10d%-9d",p4->Star_Name,p4->Des_Name,p4->Flight_No,p4->Plane_No,p4->Week_Day,p4->Customer_Amount,p4->Free_Amount,p4->Price[0],p4->Price[1],p4->Price[2]);
                                printf("\n%-8s%-7s%-8s%-9s%-8d%-9d%-9d%-10d%-10d%-9d",p5->Star_Name,p5->Des_Name,p5->Flight_No,p5->Plane_No,p5->Week_Day,p5->Customer_Amount,p5->Free_Amount,p5->Price[0],p5->Price[1],p5->Price[2]);
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

void Display_Reserve()
{
    system("cls");
    Flight *p1;
    Customer *p2;
    p1 = Head;
    if(IsEmpty)
    {
        printf("\n\t�Բ���û�ж�Ʊ�˿���Ϣ��\n"); getchar();getchar();
        return ;
    }
    printf("\n����������������������������������������������������������������������������\n");
    printf("���� ����� �ɻ��� ��Ʊ�� ���վ�� �յ�վ�� ��λ�ȼ�  ��λ�� id��Ϣ\n");
    while(p1!=NULL)
    {
        if(p1->CustName!=NULL)
        {
            p2=p1->CustName;
            while(p2!=NULL)
            {
                printf("\n%-6s%-8s%-8s%-6d%-9s%-9s%-9c%-8d%-6d",p2->Name,p1->Flight_No,p1->Plane_No,p2->Amount,p1->Star_Name,p1->Des_Name,p2->Rank,p2->Seatnum,p2->IDinfor);
                if(p1->Free_Amount>=1) printf("\n\n\t���ж����Ʊ��\n");
                else printf("\n\n\tƱ�����꣡\n");
                p2=p2->Next;
            }
        }
        p1=p1->Next;
        printf("\n\n����������������������������������������������������������������������������������������\n");
    }
    printf("\n\t����������أ�"); getchar();getchar();//getch();
    return ;
}

void Display_Replace()
{
    system("cls");
    Flight * p1;
    Customer *p2;
    p1 = Head;
    if(Empty_Flight()) return;
    printf("\n\t�򲹳˿���Ϣ��");
    if(IsReplace)
    {
        printf("\n\t��Ǹ��û�к򲹳˿ͣ�\n"); getchar();getchar();
        return ;
    }
        printf("\n��������������������������������������������������������������������������������������������\n");
        printf("���� ����� �ɻ��� ��Ʊ�� ���վ�� �յ�վ�� ��λ�ȼ� id��Ϣ\n");
        while(p1!=NULL)
        {
            if(p1->ReplName!=NULL)
            {
                p2=p1->ReplName;
                while(p2!=NULL)
                {
                    printf("\n%-6s%-8s%-8s%-6d%-9s%-9s%-9c%-8d%-6d",p2->Name,p1->Flight_No,p1->Plane_No,p2->Amount,p1->Star_Name,p1->Des_Name,p2->Rank,p2->IDinfor);
                    if(p1->Free_Amount>=1) printf("\n\t���ж����Ʊ��\n");
                    else printf("\n\tƱ�����꣡\n");
                    p2=p2->Next;
                }
            }
            p1=p1->Next;
        }
        printf("\n\n��������������������������������������������������������������������������������\n");
        printf("\n\n����������أ�"); getchar();getchar();
        return ;

}

void RefundticketMenu()//��Ʊ
{
    int Flight_No = 0,flag = 0;
    Flight *p1;
    Customer *p2,*p4,*p3,*p5;
    char answer[7],name[7];
    int id;
    int tag = 0;
    int Seatnum;
    if(Empty_Flight()) return;
    printf("\n\t���ڿ�ʼ������Ʊ����");
    if(IsEmpty)
    {
        printf("\n\t�Բ��𣬳˿Ͳ����ڣ�"); getchar();getchar();
        return ;
    }
    while(1)
    {
        flag = 0; tag = 0; Flight_No = 0;
        printf("\n\t�����뺽�ߣ�"); scanf("%s",&answer);
        if(Find_Line(Head,answer,p1,Flight_No))
        {
            p2=p1->CustName;
            printf("\n\t����������������"); scanf("%s",&name);
            printf("\n\t����������ID��Ϣ��"); scanf("%d",&id);
            if(p2==NULL)
            {
                printf("\n\t��Ǹ���˿Ͳ����ڣ�");
                if(Continue()=='n') return;
            }
            else
                while(p2!=NULL)
            {
                if(strcmp(p2->Name,name)==0&&(p2->IDinfor==id))
                {
                    if(p2==p1->CustName)//��Ϊ��λ�˿�
                    {
                        prior = p1->CustName;//��¼ָ��
                        Seatnum = p2->Seatnum;//��¼��ɾ�˿͵���λ��
                        flag = 1;break;
                    }
                }
                else if(p2->Next!=NULL)//��¼���㺽�ߵ�ǰ����ַ
                {
                    if(strcmp(p2->Next->Name,name)==0)
                    {
                        tag = 1;
                        prior = p2;//��¼���㶩Ʊ�˿͵�ǰһ��ַ
                        Seatnum = p2->Next->Seatnum;
                        flag = 1;break;
                    }
                }
                p2=p2->Next;
                shouldsave = 1;
            }
            if(!flag) printf("\n\t��Ǹ���˿Ͳ����ڣ�\n");
        }
        else printf("\n\t�Բ��𣬺��߲����ڣ�\n");
        if(flag)
        {
            if(prior == p1->CustName&&!tag)//�׽������
            {
                if(prior->Next==NULL)//ֻ��һ���˿�
                {
                    p1->Free_Amount+=prior->Amount;
                    p1->CustName = NULL;
                }
                else//���滹����
                {
                    p1->Free_Amount+=prior->Next->Amount;
                    p1->CustName = prior->Next;
                }
            }
            else//�����׽��
            {
                p1->Free_Amount+=prior->Next->Amount;
                prior->Next=prior->Next->Next;
            }

        Customer_Count--;
        if(Customer_Count==0) IsEmpty = 1;
        shouldsave = 1;
    }
    if(flag)//������Ʊ����
    {
        p3=p1->ReplName;
        while(p3!=NULL)
        {
            if(p3->Amount<=p1->Free_Amount)//�򲹳˿͵Ķ�Ʊ��С�ڻ����ʣ��Ʊ��
            {
                printf("\n\t�򲹳˿ʹ��ڣ�\n");
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
        printf("\n\t��Ʊ�ɹ���"); getchar();getchar();//getch();
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
        printf("\n\t\t�˿͹���˵���\n");
        printf("\n������������������������������������������������������������������������\n\n");
        printf("\t1.�˿���Ϣ\n");
        printf("\t2.�򲹳˿���Ϣ\n");
        printf("\t3.�������˵�\n");
        printf("\n��������������������������������������������������������������������������\n");
        printf("��ѡ������Ҫ�ķ���"); scanf("%s",&c);
        switch(c)
        {
            case '1':Display_Reserve();break;
            case '2':Display_Replace(); break;
            case '3':return ;
            default :ErrorMess();
        }
    }
}
