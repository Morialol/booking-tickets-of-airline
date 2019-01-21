#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

typedef struct Customer
{
    char Name[8];
    int Amount; //
    char Rank; //
    int Seatnum;
    int IDinfor;//???
    struct Customer *Next;
}Customer;

typedef struct Flight
{
    char Des_Name[10];
    char Star_Name[10];
    char Flight_No[6];
    char Plane_No[6];
    int Week_Day;
    int Customer_Amount;
    int Free_Amount;
    int Price[3];
    Customer *CustName;
    Customer *ReplName;
    struct Flight *Next;
}Flight,*PFlight;

extern int Customer_Count;
extern Flight *Head;
extern Flight *p2;
extern Customer *Custp1[20];
extern Customer *Replp1[20];
extern int IsEmpty;
extern int IsReplace;
extern Customer *prior;
extern int shouldsave;

char Continue();//是否继续
void ErrorMess();//操作出错提醒
int Find_Line(PFlight L,char *key);//航线查找
int Find_Line(PFlight L,char *key,PFlight &p2,int &Flight_No);
void Line_search();//查找是否有函数到达此地
void Line_Add();//航线添加
int Empty_Flight();//判断航线是否为空
void Line_See();//航线查看
void LinemanageMenu();//航线管理菜单
void bookingMenu();//订票办理菜单
void Display_Reserve();//订票乘客信息
void Display_Replace();//候补乘客信息
void RefundticketMenu();//退票办理
void CustomermagMenu();//乘客管理菜单



#endif // HEAD_H_INCLUDED
