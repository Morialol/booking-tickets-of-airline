#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <process.h>
#include <string.h>
#include "head.h"
using namespace std;

int main()
{
    Flight *p1;
    p1 = Head;
    char c;
    do{
        system("cls");
        printf("\n\t���տ��˶�Ʊϵͳ���˵�\n");
        printf("\n**********************************\n");
        printf("\t1.���߹���˵�\n");
        printf("\t2.��Ʊ����˵�\n");
        printf("\t3.��Ʊ����˵�\n");
        printf("\t4.�˿͹���˵�\n");
        printf("\t5.�˳�ϵͳ\n");
        printf("\n**********************************\n");
        printf("��ѡ������Ҫ�ķ���");
        scanf("%s",&c);
        switch(c)
        {
            case '1':LinemanageMenu();break;
            case '2':bookingMenu(); break;
            case '3':RefundticketMenu(); break;
            case '4':CustomermagMenu(); break;

            case '5':exit(0);
            default:break;
        }
    }while(c!='5');
    return 0;
}
