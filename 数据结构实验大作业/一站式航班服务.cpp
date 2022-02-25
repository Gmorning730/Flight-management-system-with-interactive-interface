#define _CRT_SECURE_NO_WARNINGS

#undef UNICODE
#undef _UNICODE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>//Easyxͼ�ο�
#include<iostream>
#include<ctype.h>//����ַ�

using namespace std;

typedef struct Time//ʱ����������
{
    int month;
    int day;
    int h;
    int m;
    int s;
}times;
typedef struct id peopleinfo;

/*struct weather//������������
{
    int weadata[7] = { 0,0,0,0,0,0,0 };//��ʼ����������Ϊ0�������ҷֱ�Ϊ
                                       //�����磬���ƣ��꣬ѩ���׵磬̨��
};*/
typedef struct pNum//�ɻ�װ������
{
    int Maxnum;
    int nownum;
    int remainnum;
}Num;
typedef struct Airmessage//������Ϣ
{
    char planename[10];
    char from_place[10];
    char to_place[10];
    times T_from;
    times T_to;
    double price;
    Num peopleNum;
}Airmes;

struct Peomessage
{
    char personname[5];		//����
    char sex[5];				//�Ա�
    char idcard[30];			//���֤��
    int planekey;				//�������
    char ticketnum[5];          //Ʊ��
    char sit[5];
    char date[8];
};
//�˿͵���Ϣ����
//typedef struct Peoplemessage
//{
//    char personname[10];		//����
//    char sex[2];				//�Ա�
//    char IDcard[30];			//���֤��
//    int planekey;				//�������
//    char ticketnum[5];          //����Ʊ��
//}Peomessage;
//typedef struct peoNode* PNode;
//typedef struct peoNode
//{
//    Peomessage man;			//ѧ����Ϣ
//    struct peoNode* pNext;	//ָ����һ����Ʊ��
//}Node;
//
//PNode g_pHead = NULL;			//�����һ��Ʊ��

//����meun��ť��С������
int R_st[] = { 150,25,650,125 };
int r1[] = { 200,200,600,300 };
int r2[] = { 200,350,600,450 };

//���庽��¼��ϵͳ���水ť������
int R_nd[] = { 150,10,650,100 };
int r3[] = { 200,100,600,175 };
int r4[] = { 200,200,600,275 };
int r5[] = { 200,300,600,374 };
int r6[] = { 200,400,600,475 };
int r7[] = { 200,500,600,575 };
//int r8[] = { 200,600,600,675 };

int nowman_num = 0;
int nowair_num = 0;
Airmessage Data[30];//��ʼ���ṹ��
Peomessage Mess[30];


/********���ܺ���������********/
void addingplane();
void modifyAirmesssage();
void ShowAirmessage();
void ReadAirmessageInfor();
void ReadPeomessageInfor();
void text();
int* timetypetrans(const char a[]);
void saveinputplane();
char* timesinttrans(int a, int b, int c);
int searchplane();
int searchplanetwo(char* input);
int searchpeople();
int searchpeopletwo(char * str);
void readperson();
void searchpeomessage();
void claimexpense();
void ticketout();
void ModifyAirplane();
void buyticket();
void refundticket();
void buyremaintext();


/********���溯��������********/
void menu();
void adminAirplane();
void BuyAirplane();
void loadingpage();
void printAirplaneUI();
void printfindUI(int k);
void printsearch();
void inputpeomessage();
void Buyretreat();
void saveinputplane2(int k);



/********���溯���Ķ���********/
void menu()
{
    //ReadAirmessageInfor(Data);
    initgraph(800, 620);//�����С


    ExMessage m1;//���������Ϣ
    cleardevice();//����

    //���ñ���ͼƬ
    IMAGE img;
    loadimage(&img, "E:\\Visual Studio\\���ݽṹʵ�����ҵ\\picture\\wolf.jpg", 1000, 600);
    putimage(0, 0, &img);
    //setbkcolor(BROWN);
   // cleardevice();

    setbkmode(TRANSPARENT);
    setfillcolor(WHITE);

    fillroundrect(r1[0], r1[1], r1[2], r1[3], 30, 30);//�����Σ�����ť
    fillroundrect(r2[0], r2[1], r2[2], r2[3], 30, 30);


    RECT Rone = { R_st[0],R_st[1],R_st[2],R_st[3] };//����ָ��R1���������������д�֣����ü����ֵ�λ��
    RECT R2 = { r1[0],r1[1],r1[2],r1[3] };
    RECT R3 = { r2[0],r2[1],r2[2],r2[3] };


    LOGFONT f;                          //������ʽָ��
    gettextstyle(&f);					//��ȡ������ʽ
    f.lfHeight = 60;
    _tcscpy(f.lfFaceName, _T("����"));	//��������
    f.lfQuality = ANTIALIASED_QUALITY;  // ����� 
    settextstyle(&f);                   // ����������ʽ
    setbkmode(TRANSPARENT);             //���屳��͸��
    settextcolor(WHITE);
    drawtext("һվʽ����ϵͳ", &Rone, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R1���������֣�ˮƽ���У���ֱ���У�������ʾ
    settextcolor(BLACK);
    drawtext("�������ϵͳ", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("���ඩƱϵͳ", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //getchar();
    while (TRUE)
    {
        m1 = getmessage();//��ȡ������
        if (m1.x > r1[0] && m1.x < r1[2] && m1.y>r1[1] && m1.y < r1[3])
        {
            setlinecolor(BLACK);
            //setlinestyle(0,0,1);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(r1[0], r1[1], r1[2], r1[3],30,30);
            drawtext("�������ϵͳ", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m1.message == WM_LBUTTONDOWN)
            {
                adminAirplane();
            }
        }
        else if(m1.x > r2[0] && m1.x < r2[2] && m1.y>r2[1] && m1.y < r2[3])
        {
            setlinecolor(BLACK);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(r2[0], r2[1], r2[2], r2[3],30,30);
            drawtext("���ඩƱϵͳ", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m1.message == WM_LBUTTONDOWN)
            {
                BuyAirplane();
            }
        }
        else
        {
            setlinecolor(WHITE);
            setfillcolor(WHITE);
            fillroundrect(r1[0], r1[1], r1[2], r1[3],30,30);
            drawtext("�������ϵͳ", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r2[0], r2[1], r2[2], r2[3],30,30);
            drawtext("���ඩƱϵͳ", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }

    }
}
void adminAirplane()
{
    initgraph(800, 620);//�����С


    ExMessage m2;//���������Ϣ
    cleardevice();//����

    //���ñ���ͼƬ
    IMAGE img;
    loadimage(&img, "E:\\Visual Studio\\���ݽṹʵ�����ҵ\\picture\\tree.jpg", 1000, 650);
    putimage(0, 0, &img);

    setbkmode(TRANSPARENT);
    setfillcolor(WHITE);

    fillroundrect(r3[0], r3[1], r3[2], r3[3], 30, 30);//�����Σ�����ť
    fillroundrect(r4[0], r4[1], r4[2], r4[3], 30, 30);
    fillroundrect(r5[0], r5[1], r5[2], r5[3], 30, 30);
    fillroundrect(r6[0], r6[1], r6[2], r6[3], 30, 30);
    fillroundrect(r7[0], r7[1], r7[2], r7[3], 30, 30);


    RECT Rtwo = { R_nd[0],R_nd[1],R_nd[2],R_nd[3] };//����ָ��R1���������������д�֣����ü����ֵ�λ��
    RECT R4 = { r3[0],r3[1],r3[2],r3[3] };
    RECT R5 = { r4[0],r4[1],r4[2],r4[3] };
    RECT R6 = { r5[0],r5[1],r5[2],r5[3] };
    RECT R7 = { r6[0],r6[1],r6[2],r6[3] };
    RECT R8 = { r7[0],r7[1],r7[2],r7[3] };


    LOGFONT f;                          //������ʽָ��
    gettextstyle(&f);					//��ȡ������ʽ
    f.lfHeight = 48;
    _tcscpy(f.lfFaceName, _T("����"));	//��������
    f.lfQuality = ANTIALIASED_QUALITY;  // ����� 
    settextstyle(&f);                   // ����������ʽ
    setbkmode(TRANSPARENT);             //���屳��͸��
    settextcolor(WHITE);
    drawtext("�������ϵͳ", &Rtwo, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R1���������֣�ˮƽ���У���ֱ���У�������ʾ
    settextcolor(BLACK);
    drawtext("����¼��", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("�����ѯ", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("�����޸�", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("�����ӡ", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("�����ϲ�", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    
    while (TRUE)
    {
        m2 = getmessage();//��ȡ������
        if (m2.x > r3[0] && m2.x < r3[2] && m2.y>r3[1] && m2.y < r3[3])
        {
            setlinecolor(BLACK);
            //setlinestyle(0,0,1);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(r3[0], r3[1], r3[2], r3[3], 30, 30);
            drawtext("����¼��", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m2.message == WM_LBUTTONDOWN)
            {
                //loadingpage();
                //adminAirplane();
                addingplane();
            }
            
        }
        else if (m2.x > r4[0] && m2.x < r4[2] && m2.y>r4[1] && m2.y < r4[3])
        {
            setlinecolor(BLACK);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(r4[0], r4[1], r4[2], r4[3], 30, 30);
            drawtext("�����ѯ", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m2.message == WM_LBUTTONDOWN)
            {
                printsearch();
            }
        }
        else if (m2.x > r5[0] && m2.x < r5[2] && m2.y>r5[1] && m2.y < r5[3])
        {
            setlinecolor(BLACK);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(r5[0], r5[1], r5[2], r5[3], 30, 30);
            drawtext("�����޸�", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m2.message == WM_LBUTTONDOWN)
            {
                ModifyAirplane();
            }
        }
        else if (m2.x > r6[0] && m2.x < r6[2] && m2.y>r6[1] && m2.y < r6[3])
        {
            setlinecolor(BLACK);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(r6[0], r6[1], r6[2], r6[3], 30, 30);
            drawtext("�����ӡ", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m2.message == WM_LBUTTONDOWN)
            {
                printAirplaneUI();
            }
        }
        else if (m2.x > r7[0] && m2.x < r7[2] && m2.y>r7[1] && m2.y < r7[3])
        {
            setlinecolor(BLACK);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(r7[0], r7[1], r7[2], r7[3], 30, 30);
            drawtext("�����ϲ�", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m2.message == WM_LBUTTONDOWN)
            {
                menu();
            }
        }
        else 
        {
            setlinecolor(WHITE);
            setfillcolor(WHITE);
            fillroundrect(r3[0], r3[1], r3[2], r3[3], 30, 30);
            drawtext("����¼��", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r4[0], r4[1], r4[2], r4[3], 30, 30);
            drawtext("�����ѯ", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r5[0], r5[1], r5[2], r5[3], 30, 30);
            drawtext("�����޸�", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r6[0], r6[1], r6[2], r6[3], 30, 30);
            drawtext("�����ӡ", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r7[0], r7[1], r7[2], r7[3], 30, 30);
            drawtext("�����ϲ�", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }
    }
    
}
void BuyAirplane()
{
    initgraph(800, 620);//�����С


    ExMessage m2;//���������Ϣ
    cleardevice();//����

    //���ñ���ͼƬ
    IMAGE img;
    loadimage(&img, "E:\\Visual Studio\\���ݽṹʵ�����ҵ\\picture\\maldives.jpg", 1000, 650,TRUE);
    putimage(0, 0, &img);

    setbkmode(TRANSPARENT);
    setfillcolor(WHITE);

    fillroundrect(r3[0], r3[1], r3[2], r3[3], 30, 30);//�����Σ�����ť
    fillroundrect(r4[0], r4[1], r4[2], r4[3], 30, 30);
    fillroundrect(r5[0], r5[1], r5[2], r5[3], 30, 30);
    fillroundrect(r6[0], r6[1], r6[2], r6[3], 30, 30);
    fillroundrect(r7[0], r7[1], r7[2], r7[3], 30, 30);


    RECT Rtwo = { R_nd[0],R_nd[1],R_nd[2],R_nd[3] };//����ָ��R1���������������д�֣����ü����ֵ�λ��
    RECT R4 = { r3[0],r3[1],r3[2],r3[3] };
    RECT R5 = { r4[0],r4[1],r4[2],r4[3] };
    RECT R6 = { r5[0],r5[1],r5[2],r5[3] };
    RECT R7 = { r6[0],r6[1],r6[2],r6[3] };
    RECT R8 = { r7[0],r7[1],r7[2],r7[3] };


    LOGFONT f;                          //������ʽָ��
    gettextstyle(&f);					//��ȡ������ʽ
    f.lfHeight = 48;
    _tcscpy(f.lfFaceName, _T("����"));	//��������
    f.lfQuality = ANTIALIASED_QUALITY;  // ����� 
    settextstyle(&f);                   // ����������ʽ
    setbkmode(TRANSPARENT);             //���屳��͸��
    settextcolor(WHITE);
    drawtext("���ඩ��ϵͳ", &Rtwo, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R1���������֣�ˮƽ���У���ֱ���У�������ʾ
    settextcolor(BLACK);
    drawtext("���ඩ��", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("��Ϣ��ѯ", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("��ӡ��Ʊ", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("����ƾ֤", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("�����ϲ�", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    while (TRUE)
    {
        m2 = getmessage();//��ȡ������
        if (m2.x > r3[0] && m2.x < r3[2] && m2.y>r3[1] && m2.y < r3[3])
        {
            setlinecolor(BLACK);
            //setlinestyle(0,0,1);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(r3[0], r3[1], r3[2], r3[3], 30, 30);
            drawtext("���ඩ��", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m2.message == WM_LBUTTONDOWN)
            {
                Buyretreat();
            }
        }
        else if (m2.x > r4[0] && m2.x < r4[2] && m2.y>r4[1] && m2.y < r4[3])
        {
            setlinecolor(BLACK);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(r4[0], r4[1], r4[2], r4[3], 30, 30);
            drawtext("��Ϣ��ѯ", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m2.message == WM_LBUTTONDOWN)
            {
                searchpeomessage();
            }

        }
        else if (m2.x > r5[0] && m2.x < r5[2] && m2.y>r5[1] && m2.y < r5[3])
        {
            setlinecolor(BLACK);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(r5[0], r5[1], r5[2], r5[3], 30, 30);
            drawtext("��ӡ��Ʊ", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m2.message == WM_LBUTTONDOWN)
            {
                ticketout();
            }
        }
        else if (m2.x > r6[0] && m2.x < r6[2] && m2.y>r6[1] && m2.y < r6[3])
        {
            setlinecolor(BLACK);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(r6[0], r6[1], r6[2], r6[3], 30, 30);
            drawtext("����ƾ֤", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m2.message == WM_LBUTTONDOWN)
            {
                claimexpense();
            }
        }
        else if (m2.x > r7[0] && m2.x < r7[2] && m2.y>r7[1] && m2.y < r7[3])
        {
            setlinecolor(BLACK);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(r7[0], r7[1], r7[2], r7[3], 30, 30);
            drawtext("�����ϲ�", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m2.message == WM_LBUTTONDOWN)
            {
                menu();
            }
        }
        else
        {
            setlinecolor(WHITE);
            setfillcolor(WHITE);
            fillroundrect(r3[0], r3[1], r3[2], r3[3], 30, 30);
            drawtext("���ඩ��", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r4[0], r4[1], r4[2], r4[3], 30, 30);
            drawtext("��Ϣ��ѯ", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r5[0], r5[1], r5[2], r5[3], 30, 30);
            drawtext("��ӡ��Ʊ", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r6[0], r6[1], r6[2], r6[3], 30, 30);
            drawtext("����ƾ֤", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r7[0], r7[1], r7[2], r7[3], 30, 30);
            drawtext("�����ϲ�", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }
    }

}
void loadingpage()
{
    initgraph(500, 300);
    int y1[] = { 50,125,450,150 };
    int y2[] = { 200, 175, 300, 200 };
    RECT Y1 = { y1[0],y1[1],y1[2],y1[3] };
    RECT Y2 = { y2[0],y2[1],y2[2],y2[3] };
    int m = 1;
    setlinecolor(RGB(194, 195, 201));
    fillroundrect(y1[0], y1[1], y1[2], y1[3], 15, 15);
    //getchar();
    for (int i = 0; i <= y1[2]-43; i = i + m)
    {
        m++;
        //printf("%d ", m);
        setfillcolor(GREEN);
        Sleep(40);
        fillroundrect(y1[0]-12, y1[1], y1[0] + i, y1[3], 20, 20);
        setfillcolor(BLACK);
        if (m==29)
        {
            for (int j = 0; j < 10; j++)
            {
                rectangle(y2[0], y2[1], y2[2], y2[3]);
                drawtext("success!", &Y2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                Sleep(10);
            }
        }
    }
}//
void printfindUI(int k)
{
    int q = k;
    ExMessage m4;
    initgraph(1280, 650, SHOWCONSOLE);
    IMAGE img3;
    loadimage(&img3, "E:\\Visual Studio\\���ݽṹʵ�����ҵ\\picture\\whitegrand.jpg", 1280, 800, TRUE);
    putimage(0, 0, &img3);
    setfillcolor(RGB(204, 206, 219));
    fillrectangle(580, 550, 680, 580);
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    RECT D1 = { 580, 550, 680, 580 };
    settextstyle(20, 0, "΢���ź�");
    outtextxy(40, 20, "�����");
    outtextxy(200, 20, "ʼ����");
    outtextxy(300, 20, "Ŀ�ĵ�");
    outtextxy(400, 20, "ʼ��ʱ��");
    outtextxy(550, 20, "����ʱ��");
    outtextxy(690, 20, "��ǰ����");
    outtextxy(780, 20, "��������");
    drawtext("����", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    outtextxy(38, 60  , Data[q].planename);
    outtextxy(205, 60 , Data[q].from_place);
    outtextxy(305, 60 , Data[q].to_place);
    char s1[10] = "";
    char s2[10] = "";
    char s3[10] = "";
    char m[] = " : ";
    _itoa(Data[q].T_from.h, s1, 10);
    _itoa(Data[q].T_from.m, s2, 10);
    _itoa(Data[q].T_from.s, s3, 10);
    strcat(s1, m);
    strcat(s1, s2);
    strcat(s1, m);
    strcat(s1, s3);
    char* str = s1;
    outtextxy(390, 60 , str);

    char s4[10] = "";
    char s5[10] = "";
    char s6[10] = "";
    char n[] = " : ";
    _itoa(Data[q].T_to.h, s4, 10);
    _itoa(Data[q].T_to.m, s5, 10);
    _itoa(Data[q].T_to.s, s6, 10);
    strcat(s4, n);
    strcat(s4, s5);
    strcat(s4, n);
    strcat(s4, s6);
    char* str2 = s4;
    outtextxy(550, 60 , str2);

    char s7[5] = "";
    char s8[5] = "";
    _itoa(Data[q].peopleNum.nownum, s7, 10);
    _itoa(Data[q].peopleNum.remainnum, s8, 10);
    strcat(s7, "��");
    strcat(s8, "��");
    outtextxy(700, 60 , s7);
    outtextxy(780, 60 , s8);

    
    while (1)
    {
        m4 = getmessage();
        if (m4.x > 580 && m4.x < 680 && m4.y>550 && m4.y < 580)
        {
            setlinecolor(WHITE);
            setfillcolor(RGB(205, 169, 146));
            fillrectangle(580, 550, 680, 580);

            drawtext("����", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m4.message == WM_LBUTTONDOWN)
            {
                adminAirplane();//�������˵�
            }
        }
        else
        {
            setlinecolor(BROWN);
            rectangle(580, 550, 680, 580);
            setfillcolor(RGB(194, 195, 201));
            fillrectangle(580, 550, 680, 580);
            drawtext("����", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }
    }

}
void printfindUI2(int k)
{
    int q = k;
    ExMessage m4;
    initgraph(1280, 650, SHOWCONSOLE);
    IMAGE img3;
    loadimage(&img3, "E:\\Visual Studio\\���ݽṹʵ�����ҵ\\picture\\whitegrand.jpg", 1280, 800, TRUE);
    putimage(0, 0, &img3);
    setfillcolor(RGB(204, 206, 219));
    fillrectangle(580, 550, 680, 580);
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    RECT D1 = { 580, 550, 680, 580 };
    settextstyle(20, 0, "΢���ź�");
    outtextxy(40, 20, "�����");
    outtextxy(200, 20, "ʼ����");
    outtextxy(300, 20, "Ŀ�ĵ�");
    outtextxy(400, 20, "ʼ��ʱ��");
    outtextxy(550, 20, "����ʱ��");
    outtextxy(690, 20, "��ǰ����");
    outtextxy(780, 20, "��������");
    drawtext("��Ʊ", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    outtextxy(38, 60, Data[q].planename);
    outtextxy(205, 60, Data[q].from_place);
    outtextxy(305, 60, Data[q].to_place);
    char s1[10] = "";
    char s2[10] = "";
    char s3[10] = "";
    char m[] = " : ";
    _itoa(Data[q].T_from.h, s1, 10);
    _itoa(Data[q].T_from.m, s2, 10);
    _itoa(Data[q].T_from.s, s3, 10);
    strcat(s1, m);
    strcat(s1, s2);
    strcat(s1, m);
    strcat(s1, s3);
    char* str = s1;
    outtextxy(390, 60, str);

    char s4[10] = "";
    char s5[10] = "";
    char s6[10] = "";
    char n[] = " : ";
    _itoa(Data[q].T_to.h, s4, 10);
    _itoa(Data[q].T_to.m, s5, 10);
    _itoa(Data[q].T_to.s, s6, 10);
    strcat(s4, n);
    strcat(s4, s5);
    strcat(s4, n);
    strcat(s4, s6);
    char* str2 = s4;
    outtextxy(550, 60, str2);

    char s7[5] = "";
    char s8[5] = "";
    _itoa(Data[q].peopleNum.nownum, s7, 10);
    _itoa(Data[q].peopleNum.remainnum, s8, 10);
    strcat(s7, "��");
    strcat(s8, "��");
    outtextxy(700, 60, s7);
    outtextxy(780, 60, s8);

    
    while (1)
    {
        m4 = getmessage();
        if (m4.x > 580 && m4.x < 680 && m4.y>550 && m4.y < 580)
        {
            setlinecolor(WHITE);
            setfillcolor(RGB(205, 169, 146));
            fillrectangle(580, 550, 680, 580);

            drawtext("��Ʊ", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m4.message == WM_LBUTTONDOWN)
            {
                //adminAirplane();//�������˵�
                buyremaintext();
            }
        }
        else
        {
            setlinecolor(BROWN);
            rectangle(580, 550, 680, 580);
            setfillcolor(RGB(194, 195, 201));
            fillrectangle(580, 550, 680, 580);
            drawtext("��Ʊ", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }
    }

}
void printsearch()
{
    int key = searchplane();
   // printf("%d", key);
    if (key == -1)
    {
        HWND hndtipsF = GetHWnd();
        int isok = MessageBox(hndtipsF, "�Ҳ�����Ӧ�ĺ���", "��ʾ", MB_OK);
    }
    else
    {
        printfindUI(key);
    }

}//
void printAirplaneUI()
{
    ReadAirmessageInfor();
    ExMessage m3;
    initgraph(1280, 650,SHOWCONSOLE);
    IMAGE img2;
    loadimage(&img2, "E:\\Visual Studio\\���ݽṹʵ�����ҵ\\picture\\whitegrand.jpg", 1280, 800, TRUE);
    putimage(0, 0, &img2);
    setfillcolor(RGB(204, 206, 219));
    fillrectangle(580, 550, 680, 580);
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    RECT D1 = { 580, 550, 680, 580 };
    settextstyle(20, 0, "΢���ź�");
    outtextxy(40, 20, "�����");
    outtextxy(200, 20, "ʼ����");
    outtextxy(300, 20, "Ŀ�ĵ�");
    outtextxy(400, 20, "ʼ��ʱ��");
    outtextxy(550, 20, "����ʱ��");
    outtextxy(690, 20, "��ǰ����");
    outtextxy(780, 20, "��������");
    drawtext("����", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //outtextxy(625, 435, "");//���ذ�ť

    for (int q = 0; q < nowair_num-1; q++)
    {
        outtextxy(38, 60 + q * 30, Data[q].planename);
        outtextxy(205, 60 + q * 30, Data[q].from_place);
        outtextxy(305, 60 + q * 30, Data[q].to_place);
        char s1[10] = "";
        char s2[10] = "";
        char s3[10] = "";
        char m[] = " : ";
        _itoa(Data[q].T_from.h, s1, 10);
        _itoa(Data[q].T_from.m, s2, 10);
        _itoa(Data[q].T_from.s, s3, 10);
        strcat(s1, m);
        strcat(s1, s2);
        strcat(s1, m);
        strcat(s1, s3);
        char* str = s1;
        outtextxy(395, 60 + q * 30, str);

        char s4[10] = "";
        char s5[10] = "";
        char s6[10] = "";
        char n[] = " : ";
        _itoa(Data[q].T_to.h, s4, 10);
        _itoa(Data[q].T_to.m, s5, 10);
        _itoa(Data[q].T_to.s, s6, 10);
        strcat(s4, n);
        strcat(s4, s5);
        strcat(s4, n);
        strcat(s4, s6);
        char* str2 = s4;
        outtextxy(549, 60 + q * 30, str2);

        char s7[5] = "";
        char s8[5] = "";
        _itoa(Data[q].peopleNum.nownum, s7, 10);
        _itoa(Data[q].peopleNum.remainnum, s8, 10);
        strcat(s7, "��");
        strcat(s8, "��");
        outtextxy(705, 60 + q * 30, s7);
        outtextxy(788, 60 + q * 30, s8);

    }

    while (1) 
    {
        m3 = getmessage();
        if (m3.x > 580 && m3.x < 680 && m3.y>550 && m3.y < 580) 
        {
            setlinecolor(WHITE);
            setfillcolor(RGB(205, 169, 146));
            fillrectangle(580, 550, 680, 580);

            drawtext("����", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m3.message == WM_LBUTTONDOWN)
            {
                adminAirplane();//�������˵�
            }
        }
        else 
        {
            setlinecolor(BROWN);
            rectangle(580, 550, 680, 580);
            setfillcolor(RGB(194, 195, 201));
            fillrectangle(580, 550, 680, 580);
            drawtext("����", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }
    }
}
void Buyretreat()
{
    //ReadAirmessageInfor(Data);
    initgraph(800, 620);//�����С


    ExMessage m1;//���������Ϣ
    cleardevice();//����

    //���ñ���ͼƬ
    IMAGE img;
    loadimage(&img, "E:\\Visual Studio\\���ݽṹʵ�����ҵ\\picture\\fall.jpg", 900, 620);
    putimage(0, 0, &img);
    //setbkcolor(BROWN);
   // cleardevice();

    setbkmode(TRANSPARENT);
    setfillcolor(WHITE);

    int Rt[] = { 355 - 20-15, 500 - 20, 445 + 20+15, 540 + 20 };
    fillroundrect(r1[0], r1[1], r1[2], r1[3], 30, 30);//�����Σ�����ť
    fillroundrect(r2[0], r2[1], r2[2], r2[3], 30, 30);
    fillroundrect(Rt[0], Rt[1], Rt[2], Rt[3], 20, 20);
    
    RECT Rone = { R_st[0],R_st[1],R_st[2],R_st[3] };//����ָ��R1���������������д�֣����ü����ֵ�λ��
    RECT R2 = { r1[0],r1[1],r1[2],r1[3] };
    RECT R3 = { r2[0],r2[1],r2[2],r2[3] };//200,350,600,450
    RECT R4 = { Rt[0],Rt[1],Rt[2],Rt[3] };


    LOGFONT f;                          //������ʽָ��
    gettextstyle(&f);					//��ȡ������ʽ
    f.lfHeight = 60;
    _tcscpy(f.lfFaceName, _T("����"));	//��������
    f.lfQuality = ANTIALIASED_QUALITY;  // ����� 
    settextstyle(&f);                   // ����������ʽ
    setbkmode(TRANSPARENT);             //���屳��͸��
    settextcolor(WHITE);
    drawtext("��ӭ", &Rone, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R1���������֣�ˮƽ���У���ֱ���У�������ʾ
    settextcolor(BLACK);
    drawtext("���ඩ��", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("�����˶�", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //getchar();
    while (TRUE)
    {
        m1 = getmessage();//��ȡ������
        if (m1.x > r1[0] && m1.x < r1[2] && m1.y>r1[1] && m1.y < r1[3])
        {
            setlinecolor(BLACK);
            //setlinestyle(0,0,1);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(r1[0], r1[1], r1[2], r1[3], 30, 30);
            drawtext("���ඩ��", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m1.message == WM_LBUTTONDOWN)
            {
                buyticket();
            }
        }
        else if (m1.x > r2[0] && m1.x < r2[2] && m1.y>r2[1] && m1.y < r2[3])
        {
            setlinecolor(BLACK);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(r2[0], r2[1], r2[2], r2[3], 30, 30);
            drawtext("�����˶�", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m1.message == WM_LBUTTONDOWN)
            {
                refundticket();
            }
        }
        else if (m1.x > Rt[0] && m1.x < Rt[2] && m1.y>Rt[1] && m1.y < Rt[3])
        {
            setlinecolor(BLACK);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(Rt[0], Rt[1], Rt[2], Rt[3], 20, 20);
            LOGFONT g;                          //������ʽָ��
            gettextstyle(&g);					//��ȡ������ʽ
            g.lfHeight = 40;
            settextstyle(&g);
            drawtext("����", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m1.message == WM_LBUTTONDOWN)
            {
                BuyAirplane();
            }
        } 
        else
        {
            setlinecolor(WHITE);
            setfillcolor(WHITE);
            fillroundrect(r1[0], r1[1], r1[2], r1[3], 30, 30);
            drawtext("���ඩ��", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r2[0], r2[1], r2[2], r2[3], 30, 30);
            drawtext("�����˶�", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(Rt[0], Rt[1], Rt[2], Rt[3], 20, 20);
            drawtext("����", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

        }
        LOGFONT f;                          //������ʽָ��
        gettextstyle(&f);					//��ȡ������ʽ
        f.lfHeight = 60;
        _tcscpy(f.lfFaceName, _T("����"));	//��������
        f.lfQuality = ANTIALIASED_QUALITY;  // ����� 
        settextstyle(&f);                   // ����������ʽ
        setbkmode(TRANSPARENT);             //���屳��͸��
       

    }
}
void claimexpense()
{
    char email[25];
    char name[10];
    InputBox(name, 8, "����������������");
    if (strlen(name) != 0)
    {
        if (searchpeopletwo(name) != -1)
        {
            InputBox(email, 20, "�������������䣺");
            HWND hndtipsM = GetHWnd();//��ȡ���ھ��
            int isok = MessageBox(hndtipsM, "����ƾ֤�Լ�ʱ��������ֻ����뼰ʱ����", "��ʾ", MB_OK);
        }
        else
        {
            HWND hndtipsM = GetHWnd();//��ȡ���ھ��
            int isok = MessageBox(hndtipsM, "����û�ж�Ʊ�����ȹ�Ʊ", "��ʾ", MB_OK);
        }
    }
    else
    {
        HWND hndtipsM = GetHWnd();//��ȡ���ھ��
        int isok = MessageBox(hndtipsM, "����û�ж�Ʊ�����ȹ�Ʊ", "��ʾ", MB_OK);
    }

}
void printfindticketUI(int k1)
{
    int q = k1;
    int p = Mess[q].planekey;
    if (q != -1)
    {
        ExMessage m4;
        initgraph(1280, 650);
        IMAGE img3;
        loadimage(&img3, "E:\\Visual Studio\\���ݽṹʵ�����ҵ\\picture\\paper.jpg", 1280, 800, TRUE);
        putimage(0, 0, &img3);
        setfillcolor(RGB(204, 206, 219));
        fillrectangle(580, 550, 680, 580);
        setbkmode(TRANSPARENT);
        settextcolor(BLACK);
        RECT D1 = { 580, 550, 680, 580 };
        settextstyle(20, 0, "΢���ź�");
        outtextxy(80, 20, "���֤��");
        outtextxy(215, 20, "����");
        outtextxy(300, 20, "�Ա�");
        outtextxy(400, 20, "�����");
        outtextxy(550, 20, "ʼ����");
        outtextxy(690, 20, "ʼ��ʱ��");
        outtextxy(788, 20, "��λ��");
        outtextxy(880, 20, "��������");
        drawtext("����", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

        outtextxy(38, 60, Mess[q].idcard);
        outtextxy(215, 60, Mess[q].personname);
        outtextxy(305, 60, Mess[q].sex);
        outtextxy(550, 60, Data[p].from_place);
        outtextxy(398, 60, Data[p].planename);
        char s1[10] = "";
        char s2[10] = "";
        char s3[10] = "";
        char m[] = " : ";
        _itoa(Data[p].T_from.h, s1, 10);
        _itoa(Data[p].T_from.m, s2, 10);
        _itoa(Data[p].T_from.s, s3, 10);
        strcat(s1, m);
        strcat(s1, s2);
        strcat(s1, m);
        strcat(s1, s3);
        char* str = s1;
        outtextxy(686, 60, str);
        outtextxy(793, 60, Mess[q].sit);
        outtextxy(880, 60, Mess[q].date);

        while (1)
        {
            m4 = getmessage();
            if (m4.x > 580 && m4.x < 680 && m4.y>550 && m4.y < 580)
            {
                setlinecolor(WHITE);
                setfillcolor(RGB(205, 169, 146));
                fillrectangle(580, 550, 680, 580);

                drawtext("����", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                if (m4.message == WM_LBUTTONDOWN)
                {
                    BuyAirplane();//�������˵�
                }
            }
            else
            {
                setlinecolor(BROWN);
                rectangle(580, 550, 680, 580);
                setfillcolor(RGB(194, 195, 201));
                fillrectangle(580, 550, 680, 580);
                drawtext("����", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            }
        }
    }
    //printf("%d", p);
    
}
void ticketout()
{
    ReadAirmessageInfor();
    ReadPeomessageInfor();
    char email[25];
    char name[10];
    InputBox(name, 8, "����������������");
    if (strlen(name) != 0)
    {
       
        int q= searchpeopletwo(name);
        int p = Mess[q].planekey;
        if (q != -1)
        {
            ExMessage m4;
            initgraph(1000, 500);
            LOGFONT k;                          //������ʽָ��
            gettextstyle(&k);					//��ȡ������ʽ
            k.lfHeight = 35;
            _tcscpy(k.lfFaceName, _T("����"));	//��������
            k.lfQuality = ANTIALIASED_QUALITY;  // ����� 
            settextstyle(&k);                   // ����������ʽ
            setbkmode(TRANSPARENT);
            setbkcolor(WHITE);
            cleardevice();
            setlinecolor(RED);
            setfillcolor(BLUE);
            fillrectangle(5, 80, 1000, 80);
            setlinecolor(BLUE);
            fillrectangle(5, 85, 1000, 85);
            setlinecolor(BLACK);
            line(785, 5, 785, 500);
            settextcolor(BLACK);
            outtextxy(40, 20, "      �� �� ��        BOARDING PASS       �ǻ���");
            outtextxy(80, 130, "�����");
            outtextxy(80, 200, Data[p].planename);
            outtextxy(260, 130, "����");
            outtextxy(250, 200, Mess[q].date);
            outtextxy(410, 130, "����ʱ��");
            char s1[10] = "";
            char s2[10] = "";
            char s3[10] = "";
            char m[] = ":";
            _itoa(Data[p].T_from.h, s1, 10);
            _itoa(Data[p].T_from.m, s2, 10);
            _itoa(Data[p].T_from.s, s3, 10);
            strcat(s1, m);
            strcat(s1, s2);
            strcat(s1, m);
            strcat(s1, s3);
            char* str = s1;
            outtextxy(410, 195, str);
            outtextxy(80, 300, "ʼ����");
            outtextxy(250, 300, Data[p].from_place);
            outtextxy(80, 400, "Ŀ�ĵ�");
            outtextxy(250, 400, Data[p].to_place);
            outtextxy(420, 300, "��λ��");
            outtextxy(440, 400, Mess[q].sit);

            outtextxy(800, 130, "��ӭ����");
            outtextxy(800, 200, Data[p].planename);
            outtextxy(800, 270, Mess[q].date);
            outtextxy(800, 340, Data[p].from_place);
            outtextxy(800, 410, Mess[q].sit);
            Sleep(100);
            HWND hndtipsM = GetHWnd();//��ȡ���ھ��
            int isok = MessageBox(hndtipsM, "������˶���Ϣ�Ƿ������ӡ", "��ʾ", MB_OKCANCEL);
            if (isok = IDOK)
            {
                loadingpage();
                Sleep(100);
                HWND hndtipsM2 = GetHWnd();//��ȡ���ھ��
                int isok = MessageBox(hndtipsM2, "��ӡ�ɹ���", "��ʾ", MB_OKCANCEL);
                BuyAirplane();
            }
        }
        else
        {
            HWND hndtipsM = GetHWnd();//��ȡ���ھ��
            int isok = MessageBox(hndtipsM, "û���ҵ������ع�Ʊ��Ϣ�����ȹ�Ʊ���Ժ�����", "��ʾ", MB_OK);
        }

    }
    else
    {
        HWND hndtipsM = GetHWnd();//��ȡ���ھ��
        int isok = MessageBox(hndtipsM, "����û�ж�Ʊ�����ȹ�Ʊ", "��ʾ", MB_OK);
    }
     
    //getchar();  //setfillcolor(RGB(204, 206, 219));
    //fillrectangle(580, 550, 680, 580);
    //setbkmode(TRANSPARENT);
    //settextcolor(BLACK);
    //RECT D1 = { 580, 550, 680, 580 };
    //settextstyle(20, 0, "΢���ź�");
    //outtextxy(80, 20, "���֤��");
    //outtextxy(215, 20, "����");
    //outtextxy(300, 20, "�Ա�");
    //outtextxy(400, 20, "�����");
    //outtextxy(550, 20, "ʼ����");
    //outtextxy(690, 20, "ʼ��ʱ��");
    //outtextxy(788, 20, "��λ��");
    //drawtext("����", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    //outtextxy(38, 60, Mess[q].idcard);
    //outtextxy(215, 60, Mess[q].personname);
    //outtextxy(305, 60, Mess[q].sex);
    //outtextxy(550, 60, Data[p].from_place);
    //outtextxy(398, 60, Data[p].planename);
    //char s1[10] = "";
    //char s2[10] = "";
    //char s3[10] = "";
    //char m[] = " : ";
    //_itoa(Data[p].T_from.h, s1, 10);
    //_itoa(Data[p].T_from.m, s2, 10);
    //_itoa(Data[p].T_from.s, s3, 10);
    //strcat(s1, m);
    //strcat(s1, s2);
    //strcat(s1, m);
    //strcat(s1, s3);
    //char* str = s1;
    //outtextxy(686, 60, str);
    //outtextxy(793, 60, Mess[q].sit);

    //while (1)
    //{
    //    m4 = getmessage();
    //    if (m4.x > 580 && m4.x < 680 && m4.y>550 && m4.y < 580)
    //    {
    //        setlinecolor(WHITE);
    //        setfillcolor(RGB(205, 169, 146));
    //        fillrectangle(580, 550, 680, 580);

    //        drawtext("����", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //        if (m4.message == WM_LBUTTONDOWN)
    //        {
    //            BuyAirplane();//�������˵�
    //        }
    //    }
    //    else
    //    {
    //        setlinecolor(BROWN);
    //        rectangle(580, 550, 680, 580);
    //        setfillcolor(RGB(194, 195, 201));
    //        fillrectangle(580, 550, 680, 580);
    //        drawtext("����", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //    }
    //}
}

/********���ܺ����Ķ���********/
void text()
{
    char Name[10];
    InputBox(Name, 10, "�������ѧ��������");
    printf("%s", Name);
}
void ReadAirmessageInfor()
{
    FILE* fp = fopen("Airmessage.txt", "r");
    if (fp == NULL)
    {
        printf("Eorro");
        return;
    }
    //���ļ��е����ݶ�ȡ����ǰ�Ľṹ��������
    int i = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s %d:%d:%d %d:%d:%d %lf %d %d %d",
            Data[i].planename,
            Data[i].from_place,
            Data[i].to_place,
            //&Data[i].T_from.month,
            //&Data[i].T_from.day,
            &Data[i].T_from.h,
            &Data[i].T_from.m,
            &Data[i].T_from.s,
            &Data[i].T_to.h,
            &Data[i].T_to.m,
            &Data[i].T_to.s,
            &Data[i].price,
            &Data[i].peopleNum.Maxnum,
            &Data[i].peopleNum.nownum,
            &Data[i].peopleNum.remainnum);
        i++;
    }
    nowair_num = i--;
    //printf("%d", i);
    fclose(fp);
}
void ShowAirmessage()
{
    for (int i = 0; i < nowair_num-1; i++)
    {
        printf("%s %s %s %d:%d:%d %d:%d:%d %.2lf %d %d %d\n",
            Data[i].planename,
            Data[i].from_place,
            Data[i].to_place,
            Data[i].T_from.h,
            Data[i].T_from.m,
            Data[i].T_from.s,
            Data[i].T_to.h,
            Data[i].T_to.m,
            Data[i].T_to.s,
            Data[i].price,
            Data[i].peopleNum.Maxnum,
            Data[i].peopleNum.nownum,
            Data[i].peopleNum.remainnum);
    }
}
void modifyAirmesssage()
{
    FILE* fp;
    fp = fopen("Airmessage.txt", "r+");
    char name[10];
    printf("��������Ҫ�޸ĵĺ����:");
    scanf("%s", name);
    int i = 0;
    Airmessage no_use[5];
    while (fscanf(fp, "%s %s %s %d��%d�� %d:%d:%d %d:%d:%d %.2lf %d %d %d",
        no_use[i].planename,
        no_use[i].from_place,
        no_use[i].to_place,
        &no_use[i].T_from.month,
        &no_use[i].T_from.day,
        &no_use[i].T_from.h,
        &no_use[i].T_from.m,
        &no_use[i].T_from.s,
        &no_use[i].T_to.h,
        &no_use[i].T_to.m,
        &no_use[i].T_to.s,
        &no_use[i].price,
        &no_use[i].peopleNum.Maxnum,
        &no_use[i].peopleNum.nownum,
        &no_use[i].peopleNum.remainnum) != EOF)
    {
        if (strcmp(no_use[i].planename, name) == 0)
            //if(no_use[i].price== money)         //�ҵ�Ŀ��
        {
            rewind(fp);//��дָ�뵽����
            //fseek(fp, 0, SEEK_CUR); //�ع�ָ�����޸ĺ���ǰ
            printf("�������µĺ�����Ϣ");
            scanf("%s", name);
            fprintf(fp, "%s", name); //����д��
            break;
        }
    }
    fclose(fp);
}
void addingplane()
{
    while (TRUE)
    {
        int bit = 0;//�ж������С
        InputBox(Data[nowair_num].planename, 7,"�����뺽���Σ�");
        bit = strlen(Data[nowair_num].planename);
        if (bit != 0)//�����벻Ϊ�յ�ʱ��
        {
            int key = 0;//���尴ť�����ж��Ƿ��ظ�
            for (int i = 0; i < nowair_num; i++)
                if (strcmp(Data[nowair_num].planename, Data[i].planename) == 0)
                {
                    //printf("%d", strcmp(Data[nowair_num].planename, Data[i].planename));
                    key = 1;
                }
            if (key == 1)
            {
                HWND hwndInput1 = GetHWnd();
                int isok = MessageBox(hwndInput1, "�ú����Ѵ��ڣ�������¼��", "��ʾ", MB_OK);
            }
            else
            {
                char timefrom[20];
                char timeto[20];
                char price[10];
                char num[5];
                InputBox(Data[nowair_num].from_place, 10, "�����뺽���ʼ���أ�", MB_OK);
                InputBox(Data[nowair_num].to_place, 10, "�����뺽���Ŀ�ĵأ�", MB_OK);
                InputBox(timefrom, 10, "�����뺽�������ʱ�䣺", MB_OK);
                int* arr1 = timetypetrans(timefrom);
             /* for (int i = 0; i < 3; i++)
                    printf("%d ", arr1[i]);���ݲ���*/
                Data[nowair_num].T_from.h = arr1[0];
                Data[nowair_num].T_from.m = arr1[1];
                Data[nowair_num].T_from.s = arr1[2];
                InputBox(timeto, 10, "�����뺽�ൽ���ʱ�䣺", MB_OK);
                int* brr = timetypetrans(timeto);
                /*printf("%s*", timeto);
                for (int i = 0; i < 3; i++)
                    printf("%d ^", brr[i]);*/
                Data[nowair_num].T_to.h = brr[0];
                Data[nowair_num].T_to.m = brr[1];
                Data[nowair_num].T_to.s = brr[2];
                InputBox(price, 5, "�����뺽��ļ۸�", MB_OK);
                Data[nowair_num].price = atoi(price);
                InputBox(num, 5, "�����뺽��������������", MB_OK);
                Data[nowair_num].peopleNum.Maxnum = atoi(num);
                InputBox(num, 5, "�����뺽�൱ǰ������", MB_OK);
                Data[nowair_num].peopleNum.nownum = atoi(num);
                Data[nowair_num].peopleNum.remainnum = Data[nowair_num].peopleNum.Maxnum -
                Data[nowair_num].peopleNum.nownum;
                break;
            }
                
        }
        else
            break;
    }
    saveinputplane();
}
int* timetypetrans( const char a[])//����Inputboxֻ������str���ͣ���Ҫ����Ҫ������ת����int�������
{
    int i = 0;
    char t1[5] = "";
    char t2[5] = "";
    char t3[5] = "";
    strncpy(t1, a, 2);
    strncpy(t2, a+3, 2);
    strncpy(t3, a+6, 2);
    //printf("%s", t1);
    //printf("%s", t2);
    //printf("%s", t3);
    int b[10] = { atoi(t1),atoi(t2),atoi(t3) };
    return b;
}
void printbill()
{
    initgraph(400, 300);
    
}
void saveinputplane()
{   
    if (
        strlen(Data[nowair_num].from_place) != 0  &&
        strlen(Data[nowair_num].to_place  ) != 0  &&
        strlen(Data[nowair_num].planename ) != 0  &&
        Data[nowair_num].price    > 0 &&
        Data[nowair_num].T_from.h >= 0 &&
        Data[nowair_num].T_from.s >= 0 &&
        Data[nowair_num].T_from.m >= 0 &&
        Data[nowair_num].T_to.h   >= 0 &&
        Data[nowair_num].T_to.s   >= 0 &&
        Data[nowair_num].T_to.m   >= 0 &&
        Data[nowair_num].peopleNum.Maxnum > 0 &&
        Data[nowair_num].peopleNum.nownum >= 0
        )
    {
        FILE* fp;
        fp = fopen("Airmessage.txt", "a");
        fprintf(fp,"%s %s %s %d:%d:%d %d:%d:%d %.2lf %d %d %d\n",
            Data[nowair_num].planename,
            Data[nowair_num].from_place,
            Data[nowair_num].to_place,
            Data[nowair_num].T_from.h,
            Data[nowair_num].T_from.m,
            Data[nowair_num].T_from.s,
            Data[nowair_num].T_to.h,
            Data[nowair_num].T_to.m,
            Data[nowair_num].T_to.s,
            Data[nowair_num].price,
            Data[nowair_num].peopleNum.Maxnum,
            Data[nowair_num].peopleNum.nownum,
            Data[nowair_num].peopleNum.remainnum);
        fclose(fp);
        nowair_num++;
        HWND hwndInput2 = GetHWnd();
        int isok = MessageBox(hwndInput2, "¼��ɹ���", "��ʾ", MB_OK);
    }
}
void saveinputplane2(int k)
{
    if (
        strlen(Data[k].from_place) != 0 &&
        strlen(Data[k].to_place) != 0 &&
        strlen(Data[k].planename) != 0 &&
        Data[k].price > 0 &&
        Data[k].T_from.h >= 0 &&
        Data[k].T_from.s >= 0 &&
        Data[k].T_from.m >= 0 &&
        Data[k].T_to.h >= 0 &&
        Data[k].T_to.s >= 0 &&
        Data[k].T_to.m >= 0 &&
        Data[k].peopleNum.Maxnum > 0 &&
        Data[k].peopleNum.nownum >= 0
        )
    {
        FILE* fp;
        fp = fopen("Airmessage.txt", "w");
        rewind(fp);
        for (int i = 0; i < nowair_num-1; i++)
        {
            fprintf(fp, "%s %s %s %d:%d:%d %d:%d:%d %.2lf %d %d %d\n",
                Data[i].planename,
                Data[i].from_place,
                Data[i].to_place,
                Data[i].T_from.h,
                Data[i].T_from.m,
                Data[i].T_from.s,
                Data[i].T_to.h,
                Data[i].T_to.m,
                Data[i].T_to.s,
                Data[i].price,
                Data[i].peopleNum.Maxnum,
                Data[i].peopleNum.nownum,
                Data[i].peopleNum.remainnum);
        }
        
        
        fclose(fp);
        HWND hwndInput2 = GetHWnd();
        int isok = MessageBox(hwndInput2, "�޸ĳɹ���", "��ʾ", MB_OK);
    }
}
void savepeoplebuy()
{
    int k = nowman_num;
    if (
        strlen(Mess[k].date) != 0 &&
        strlen(Mess[k].idcard) != 0 &&
        strlen(Mess[k].personname) != 0 &&
        strlen(Mess[k].sit) != 0 &&
        strlen(Mess[k].sex) != 0 &&
        strlen(Mess[k].ticketnum) != 0 &&
        Mess[k].planekey >= 0
        )
    {
        FILE* fp;
        fp = fopen("Peoplemessage.txt", "a");
        fprintf(fp, "%s %s %s %d %s %s %s\n",
            Mess[k].personname,
            Mess[k].sex,
            Mess[k].idcard,
            Mess[k].planekey,
            Mess[k].ticketnum,
            Mess[k].sit,
            Mess[k].date
        );
        fprintf(fp,"\n");
        fclose(fp);
        nowman_num++;
    }
    else
    {
        HWND hwndInput2 = GetHWnd();
        int isok = MessageBox(hwndInput2, "��Ϣ����������δ����", "��ʾ", MB_OK);
    }
}
int searchplane()
{
    int key = -1;
    char input[10];
    InputBox(input, 10, "��������Ҫ���ҵĺ����");
    for (int i = 0; i < nowair_num-1; i++)
    {
        if (strcmp(input,Data[i].planename) == 0)
        {
            key = i;
            break;
            //printf("%d", key);
        }   
    }
    return key;
}
int searchplanetwo(char* input)
{
    int key = -1;
    //char input[10];
    //InputBox(input, 10, "��������Ҫ���ҵĺ����");
    for (int i = 0; i < nowair_num - 1; i++)
    {
        if (strcmp(input, Data[i].planename) == 0)
        {
            key = i;
            break;
            //printf("%d", key);
        }
    }
    return key;
}
int searchpeople()
{
    int key = -1;
    char input[10];
    InputBox(input, 10, "�����������Ϣ��������");
    if (strlen(input) != 0)
    {
        for (int i = 0; i < nowman_num; i++)
        {
            if (strcmp(input, Mess[i].personname) == 0)
            {
                key = i;
                break;
                //printf("%d", key);
            }
        }
    }
    return key;
}
int searchpeopletwo(char* str)
{
        int key = -1;

        for (int i = 0; i < nowman_num - 1; i++) ///&*&//
        {
            if (strcmp(str, Mess[i].personname) == 0)
            {
                key = i;
                break;
                //printf("%d", key);
            }
        }
        return key;
}
int searchpeopleplace(char* str1, char* str2)
{
    int key = -1;

    for (int i = 0; i < nowair_num - 1; i++)
    {
        if (strcmp(str1, Data[i].from_place) == 0&&
            strcmp(str2, Data[i].to_place) == 0)
        {
            key = i;
            break;
            //printf("%d", key);
        }
    }
    return key;
}
char* timesinttrans(int a, int b, int c)
{
    
    char s1[10] = "";
    char s2[10] = "";
    char s3[10] = "";
    char m[] = ":";
    _itoa(a, s1, 10);
    _itoa(b, s2, 10);
    _itoa(c, s3, 10);
    strcat(s1, m);
    strcat(s1, s2);
    strcat(s1, m);
    strcat(s1, s3);
    char* str = s1;
    //char* timeword = s1;
    //printf("%s ", str);
    return str;
}
void ReadPeomessageInfor()
{
    FILE* fp = fopen("Peoplemessage.txt", "r");
    if (fp == NULL)
    {
        printf("Eorro");
        return;
    }
    //���ļ��е����ݶ�ȡ����ǰ�Ľṹ��������
    int i = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s %d %s %s %s",
            Mess[i].personname,
            Mess[i].sex,
            Mess[i].idcard,
            &Mess[i].planekey,
            Mess[i].ticketnum,
            Mess[i].sit,
            Mess[i].date
            );
        i++;
    }
    nowman_num = i--;
    //printf("%d", i);
    fclose(fp);
}
void ShowPeomessage()
{
    for (int i = 0; i < nowman_num-1; i++)
    {
        printf("%s %s %s %d %s %s %s\n",
            Mess[i].personname,
            Mess[i].sex,
            Mess[i].idcard,
            Mess[i].planekey,
            Mess[i].ticketnum,
            Mess[i].sit,
            Mess[i].date
        );
    }
}
void searchpeomessage()
{
    ReadPeomessageInfor();
    int key = searchpeople();
    //printf("%d", key);
    if (key == -1)
    {
        HWND hndtipsF = GetHWnd();
        int isok = MessageBox(hndtipsF, "�Ҳ�����Ӧ��Ϣ", "��ʾ", MB_OK);
    }
    else
    {
        printfindticketUI(key);
    }
}
void ModifyAirplane()
{
    int r1 = searchplane();//����ֵ
    if ( r1== -1)//û�ҵ�
    {
        HWND hndtipsM = GetHWnd();//��ȡ���ھ��
        int isok = MessageBox(hndtipsM, "�Ҳ���������Ϣ!", "��ʾ", MB_OK);
    }
    else//�ҵ�
    {
            char modi[30];
            char timefrom[20];
            char timeto[20];
            char price[10];
            char num[5];
            InputBox(Data[r1].planename, 10, "�������޸ĺ�ĺ���ţ�", MB_OK);
            InputBox(Data[r1].from_place, 10, "�����뺽���ʼ���أ�", MB_OK);
            InputBox(Data[r1].to_place, 10, "�����뺽���Ŀ�ĵأ�", MB_OK);
            InputBox(timefrom, 10, "�����뺽�������ʱ�䣺", MB_OK);
            int* arr1 = timetypetrans(timefrom);
            /* for (int i = 0; i < 3; i++)
                   printf("%d ", arr1[i]);���ݲ���*/
            Data[r1].T_from.h = arr1[0];
            Data[r1].T_from.m = arr1[1];
            Data[r1].T_from.s = arr1[2];
            InputBox(timeto, 10, "�����뺽�ൽ���ʱ�䣺", MB_OK);
            int* brr = timetypetrans(timeto);
            /*printf("%s*", timeto);
            for (int i = 0; i < 3; i++)
                printf("%d ^", brr[i]);*/
            Data[r1].T_to.h = brr[0];
            Data[r1].T_to.m = brr[1];
            Data[r1].T_to.s = brr[2];
            InputBox(price, 5, "�����뺽��ļ۸�", MB_OK);
            Data[r1].price = atoi(price);
            InputBox(num, 5, "�����뺽��������������", MB_OK);
            Data[r1].peopleNum.Maxnum = atoi(num);
            InputBox(num, 5, "�����뺽�൱ǰ������", MB_OK);
            Data[r1].peopleNum.nownum = atoi(num);
            Data[r1].peopleNum.remainnum = Data[r1].peopleNum.Maxnum -
            Data[r1].peopleNum.nownum;
            saveinputplane2(r1);
    }
    adminAirplane();
}
void savepeopleInfor()
{
    FILE* fp;
    fp = fopen("Peoplemessage.txt", "w");
    rewind(fp);
    for (int i = 0; i < nowman_num - 2; i++)
    {
        fprintf(fp, "%s %s %s %d %s %s %s\n",
        Mess[i].personname,
        Mess[i].sex,
        Mess[i].idcard,
        Mess[i].planekey,
        Mess[i].ticketnum,
        Mess[i].sit,
        Mess[i].date);
    }

    fclose(fp);
    
}
void buyticket()
{
    char name[10] = "";
    InputBox(name, 15, "���������ĵ�����");
    while (TRUE)
    {
        if (strlen(name) != 0)
        {
            strcpy(Mess[nowman_num].personname,name);
            char fromplace[10];
            char toplace[10];
            InputBox(Mess[nowman_num].idcard, 30, "�������������֤�ţ�", MB_OK);
            InputBox(Mess[nowman_num].sex, 5, "�����������Ա�", MB_OK);
            InputBox(fromplace, 10, "����������ʼ����");
            InputBox(toplace, 10, "����������Ŀ�ĵ�");
            HWND hwndInput3 = GetHWnd();
            int key = searchpeopleplace(fromplace, toplace);
            if (key != -1)
            {
                int isok = MessageBox(hwndInput3, "Ϊ�����������º���", "��ʾ", MB_OKCANCEL);
                if (isok == IDOK)
                {
                    printfindUI2(key);
                    buyremaintext();
                }

                break;
            }
            else
            {
                HWND hwndInput2 = GetHWnd();
                int isok = MessageBox(hwndInput2, "û���ҵ�����Ҫ��ĺ��࣡", "��ʾ", MB_OKCANCEL);
                break;
            }
        }
        else
        {
            HWND hwndInput2 = GetHWnd();
            int isok = MessageBox(hwndInput2, "����������,�������룡", "��ʾ", MB_OKCANCEL);

            if (isok == IDCANCEL)
            {
                break;
            }
            else
            {
                InputBox(name, 15, "���������ĵ�����");
            }
        }
    }
}
    
      //  }
      //      //savepeopleInfor();
      //      nowman_num++;
      //      HWND hwndInput2 = GetHWnd();
      //      int isok = MessageBox(hwndInput2, "��Ʊ�ɹ���", "��ʾ", MB_OK);
      //}
void refundticket()
{
    char name[10] = "";
    InputBox(name, 10, "���������ĵ�����");
    if (strlen(name) != 0)
    {
        if (searchpeopletwo(name) != -1)
        {
            int coordinate = searchpeopletwo(name);
            int n = nowman_num;
            for (int i = coordinate; i < n - 1; i++)
            {
                Mess[i] = Mess[i + 1];
            }
            savepeopleInfor();
            nowman_num--;
            HWND hwndInput2 = GetHWnd();
            int isok = MessageBox(hwndInput2, "��Ʊ�ɹ���", "��ʾ", MB_OK);
        }
        else
        {
            HWND hwndInput3 = GetHWnd();
            int isok = MessageBox(hwndInput3, "û���ҵ������Ϣ", "��ʾ", MB_OK);
        }
    }
    else
    {
        HWND hndtipsD = GetHWnd();
        int isok = MessageBox(hndtipsD, "û���ҵ������Ϣ", "��ʾ", MB_OK);
    }
}
void buyremaintext()
{
    char buystr[10];
    InputBox(buystr, 30, "�����뺽��Ŷ�����Ʊ��", MB_OK);
    int pkey = searchplanetwo(buystr);
    Mess[nowman_num].planekey = pkey;
    InputBox(Mess[nowman_num].ticketnum, 5, "�����붩����Ʊ��Ʊ����", MB_OK);
    InputBox(Mess[nowman_num].date, 10, "�����붩����Ʊ�����ڣ�", MB_OK);
    InputBox(Mess[nowman_num].sit, 5, "����������ѡ����λ�ţ�ʱ�����������Ūѡ���������ȣ���", MB_OK);
    HWND hwndInput2 = GetHWnd();
    int isok2 = MessageBox(hwndInput2, "�����ɹ�", "��ʾ", MB_OKCANCEL);
    savepeoplebuy();
    BuyAirplane();
    
}

/********������********/
int main()
{
    ReadAirmessageInfor();
    ReadPeomessageInfor();
    //ShowPeomessage();
    //ShowPeomessage();
    //searchplane();
    //ShowAirmessage();
   //addingplane();
   menu();
    //printfindUI(9);
    //adminAirplane();
    //BuyAirplane();
    //modifyAirmesssage();
    //loadingpage();
    //text();
    //printf("%d",nowair_num);
    //timetypetrans("16:45:45");
 /*   int a = atoi("123.444");
    printf("%d", a);*/
  /* int* arr1 = timetypetrans("12:77:99");
   for (int i = 0; i < 3; i++)
   {
       printf("%d ", arr1[i]);
   }*/
    //printAirplaneUI();
    //char str[10] = "";
    //timesinttrans(24,46,16,str);
    //printf("%s", str);
    //Buyretreat();
    //printfindticketUI(3);
    //searchpeomessage();
    //claimexpense();
    //ticketout();
   //ModifyAirplane();
    //refundticket();
    //buyticket();
    //ShowPeomessage();
    //savepeoplebuy();
    //buyremaintext();
    //printf("%d", nowman_num);
    return 0;
   
}
