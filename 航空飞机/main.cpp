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
        printf("\n\t航空客运订票系统主菜单\n");
        printf("\n**********************************\n");
        printf("\t1.航线管理菜单\n");
        printf("\t2.订票办理菜单\n");
        printf("\t3.退票办理菜单\n");
        printf("\t4.乘客管理菜单\n");
        printf("\t5.退出系统\n");
        printf("\n**********************************\n");
        printf("请选择你需要的服务：");
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
