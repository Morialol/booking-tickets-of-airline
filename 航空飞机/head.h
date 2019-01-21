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

char Continue();//�Ƿ����
void ErrorMess();//������������
int Find_Line(PFlight L,char *key);//���߲���
int Find_Line(PFlight L,char *key,PFlight &p2,int &Flight_No);
void Line_search();//�����Ƿ��к�������˵�
void Line_Add();//�������
int Empty_Flight();//�жϺ����Ƿ�Ϊ��
void Line_See();//���߲鿴
void LinemanageMenu();//���߹���˵�
void bookingMenu();//��Ʊ����˵�
void Display_Reserve();//��Ʊ�˿���Ϣ
void Display_Replace();//�򲹳˿���Ϣ
void RefundticketMenu();//��Ʊ����
void CustomermagMenu();//�˿͹���˵�



#endif // HEAD_H_INCLUDED
