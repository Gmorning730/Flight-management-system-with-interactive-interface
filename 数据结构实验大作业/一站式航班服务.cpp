#define _CRT_SECURE_NO_WARNINGS

#undef UNICODE
#undef _UNICODE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>//Easyx图形库
#include<iostream>
#include<ctype.h>//检测字符

using namespace std;

typedef struct Time//时间数据类型
{
    int month;
    int day;
    int h;
    int m;
    int s;
}times;
typedef struct id peopleinfo;

/*struct weather//气候数据类型
{
    int weadata[7] = { 0,0,0,0,0,0,0 };//初始化天气类型为0，从左到右分别为
                                       //阴，晴，多云，雨，雪，雷电，台风
};*/
typedef struct pNum//飞机装载数量
{
    int Maxnum;
    int nownum;
    int remainnum;
}Num;
typedef struct Airmessage//航班信息
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
    char personname[5];		//姓名
    char sex[5];				//性别
    char idcard[30];			//身份证号
    int planekey;				//航班序号
    char ticketnum[5];          //票数
    char sit[5];
    char date[8];
};
//顾客的信息链表
//typedef struct Peoplemessage
//{
//    char personname[10];		//姓名
//    char sex[2];				//性别
//    char IDcard[30];			//身份证号
//    int planekey;				//航班序号
//    char ticketnum[5];          //订购票数
//}Peomessage;
//typedef struct peoNode* PNode;
//typedef struct peoNode
//{
//    Peomessage man;			//学生信息
//    struct peoNode* pNext;	//指向下一个购票者
//}Node;
//
//PNode g_pHead = NULL;			//定义第一购票者

//定义meun按钮大小的数组
int R_st[] = { 150,25,650,125 };
int r1[] = { 200,200,600,300 };
int r2[] = { 200,350,600,450 };

//定义航班录入系统界面按钮的数组
int R_nd[] = { 150,10,650,100 };
int r3[] = { 200,100,600,175 };
int r4[] = { 200,200,600,275 };
int r5[] = { 200,300,600,374 };
int r6[] = { 200,400,600,475 };
int r7[] = { 200,500,600,575 };
//int r8[] = { 200,600,600,675 };

int nowman_num = 0;
int nowair_num = 0;
Airmessage Data[30];//初始化结构体
Peomessage Mess[30];


/********功能函数的声明********/
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


/********界面函数的声明********/
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



/********界面函数的定义********/
void menu()
{
    //ReadAirmessageInfor(Data);
    initgraph(800, 620);//界面大小


    ExMessage m1;//定义鼠标信息
    cleardevice();//清屏

    //设置背景图片
    IMAGE img;
    loadimage(&img, "E:\\Visual Studio\\数据结构实验大作业\\picture\\wolf.jpg", 1000, 600);
    putimage(0, 0, &img);
    //setbkcolor(BROWN);
   // cleardevice();

    setbkmode(TRANSPARENT);
    setfillcolor(WHITE);

    fillroundrect(r1[0], r1[1], r1[2], r1[3], 30, 30);//画矩形，即按钮
    fillroundrect(r2[0], r2[1], r2[2], r2[3], 30, 30);


    RECT Rone = { R_st[0],R_st[1],R_st[2],R_st[3] };//矩形指针R1，方便后面在里面写字，不用计算字的位置
    RECT R2 = { r1[0],r1[1],r1[2],r1[3] };
    RECT R3 = { r2[0],r2[1],r2[2],r2[3] };


    LOGFONT f;                          //字体样式指针
    gettextstyle(&f);					//获取字体样式
    f.lfHeight = 60;
    _tcscpy(f.lfFaceName, _T("隶书"));	//设置字体
    f.lfQuality = ANTIALIASED_QUALITY;  // 抗锯齿 
    settextstyle(&f);                   // 设置字体样式
    setbkmode(TRANSPARENT);             //字体背景透明
    settextcolor(WHITE);
    drawtext("一站式航班系统", &Rone, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R1内输入文字，水平居中，垂直居中，单行显示
    settextcolor(BLACK);
    drawtext("航班管理系统", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("航班订票系统", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //getchar();
    while (TRUE)
    {
        m1 = getmessage();//获取鼠标操作
        if (m1.x > r1[0] && m1.x < r1[2] && m1.y>r1[1] && m1.y < r1[3])
        {
            setlinecolor(BLACK);
            //setlinestyle(0,0,1);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(r1[0], r1[1], r1[2], r1[3],30,30);
            drawtext("航班管理系统", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
            drawtext("航班订票系统", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
            drawtext("航班管理系统", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r2[0], r2[1], r2[2], r2[3],30,30);
            drawtext("航班订票系统", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }

    }
}
void adminAirplane()
{
    initgraph(800, 620);//界面大小


    ExMessage m2;//定义鼠标信息
    cleardevice();//清屏

    //设置背景图片
    IMAGE img;
    loadimage(&img, "E:\\Visual Studio\\数据结构实验大作业\\picture\\tree.jpg", 1000, 650);
    putimage(0, 0, &img);

    setbkmode(TRANSPARENT);
    setfillcolor(WHITE);

    fillroundrect(r3[0], r3[1], r3[2], r3[3], 30, 30);//画矩形，即按钮
    fillroundrect(r4[0], r4[1], r4[2], r4[3], 30, 30);
    fillroundrect(r5[0], r5[1], r5[2], r5[3], 30, 30);
    fillroundrect(r6[0], r6[1], r6[2], r6[3], 30, 30);
    fillroundrect(r7[0], r7[1], r7[2], r7[3], 30, 30);


    RECT Rtwo = { R_nd[0],R_nd[1],R_nd[2],R_nd[3] };//矩形指针R1，方便后面在里面写字，不用计算字的位置
    RECT R4 = { r3[0],r3[1],r3[2],r3[3] };
    RECT R5 = { r4[0],r4[1],r4[2],r4[3] };
    RECT R6 = { r5[0],r5[1],r5[2],r5[3] };
    RECT R7 = { r6[0],r6[1],r6[2],r6[3] };
    RECT R8 = { r7[0],r7[1],r7[2],r7[3] };


    LOGFONT f;                          //字体样式指针
    gettextstyle(&f);					//获取字体样式
    f.lfHeight = 48;
    _tcscpy(f.lfFaceName, _T("隶书"));	//设置字体
    f.lfQuality = ANTIALIASED_QUALITY;  // 抗锯齿 
    settextstyle(&f);                   // 设置字体样式
    setbkmode(TRANSPARENT);             //字体背景透明
    settextcolor(WHITE);
    drawtext("航班管理系统", &Rtwo, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R1内输入文字，水平居中，垂直居中，单行显示
    settextcolor(BLACK);
    drawtext("航班录入", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("航班查询", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("航班修改", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("航班打印", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("返回上层", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    
    while (TRUE)
    {
        m2 = getmessage();//获取鼠标操作
        if (m2.x > r3[0] && m2.x < r3[2] && m2.y>r3[1] && m2.y < r3[3])
        {
            setlinecolor(BLACK);
            //setlinestyle(0,0,1);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(r3[0], r3[1], r3[2], r3[3], 30, 30);
            drawtext("航班录入", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
            drawtext("航班查询", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
            drawtext("航班修改", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
            drawtext("航班打印", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
            drawtext("返回上层", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
            drawtext("航班录入", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r4[0], r4[1], r4[2], r4[3], 30, 30);
            drawtext("航班查询", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r5[0], r5[1], r5[2], r5[3], 30, 30);
            drawtext("航班修改", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r6[0], r6[1], r6[2], r6[3], 30, 30);
            drawtext("航班打印", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r7[0], r7[1], r7[2], r7[3], 30, 30);
            drawtext("返回上层", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }
    }
    
}
void BuyAirplane()
{
    initgraph(800, 620);//界面大小


    ExMessage m2;//定义鼠标信息
    cleardevice();//清屏

    //设置背景图片
    IMAGE img;
    loadimage(&img, "E:\\Visual Studio\\数据结构实验大作业\\picture\\maldives.jpg", 1000, 650,TRUE);
    putimage(0, 0, &img);

    setbkmode(TRANSPARENT);
    setfillcolor(WHITE);

    fillroundrect(r3[0], r3[1], r3[2], r3[3], 30, 30);//画矩形，即按钮
    fillroundrect(r4[0], r4[1], r4[2], r4[3], 30, 30);
    fillroundrect(r5[0], r5[1], r5[2], r5[3], 30, 30);
    fillroundrect(r6[0], r6[1], r6[2], r6[3], 30, 30);
    fillroundrect(r7[0], r7[1], r7[2], r7[3], 30, 30);


    RECT Rtwo = { R_nd[0],R_nd[1],R_nd[2],R_nd[3] };//矩形指针R1，方便后面在里面写字，不用计算字的位置
    RECT R4 = { r3[0],r3[1],r3[2],r3[3] };
    RECT R5 = { r4[0],r4[1],r4[2],r4[3] };
    RECT R6 = { r5[0],r5[1],r5[2],r5[3] };
    RECT R7 = { r6[0],r6[1],r6[2],r6[3] };
    RECT R8 = { r7[0],r7[1],r7[2],r7[3] };


    LOGFONT f;                          //字体样式指针
    gettextstyle(&f);					//获取字体样式
    f.lfHeight = 48;
    _tcscpy(f.lfFaceName, _T("隶书"));	//设置字体
    f.lfQuality = ANTIALIASED_QUALITY;  // 抗锯齿 
    settextstyle(&f);                   // 设置字体样式
    setbkmode(TRANSPARENT);             //字体背景透明
    settextcolor(WHITE);
    drawtext("航班订购系统", &Rtwo, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R1内输入文字，水平居中，垂直居中，单行显示
    settextcolor(BLACK);
    drawtext("航班订改", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("信息查询", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("打印机票", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("报销凭证", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("返回上层", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    while (TRUE)
    {
        m2 = getmessage();//获取鼠标操作
        if (m2.x > r3[0] && m2.x < r3[2] && m2.y>r3[1] && m2.y < r3[3])
        {
            setlinecolor(BLACK);
            //setlinestyle(0,0,1);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(r3[0], r3[1], r3[2], r3[3], 30, 30);
            drawtext("航班订改", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
            drawtext("信息查询", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
            drawtext("打印机票", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
            drawtext("报销凭证", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
            drawtext("返回上层", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
            drawtext("航班订改", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r4[0], r4[1], r4[2], r4[3], 30, 30);
            drawtext("信息查询", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r5[0], r5[1], r5[2], r5[3], 30, 30);
            drawtext("打印机票", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r6[0], r6[1], r6[2], r6[3], 30, 30);
            drawtext("报销凭证", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r7[0], r7[1], r7[2], r7[3], 30, 30);
            drawtext("返回上层", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
    loadimage(&img3, "E:\\Visual Studio\\数据结构实验大作业\\picture\\whitegrand.jpg", 1280, 800, TRUE);
    putimage(0, 0, &img3);
    setfillcolor(RGB(204, 206, 219));
    fillrectangle(580, 550, 680, 580);
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    RECT D1 = { 580, 550, 680, 580 };
    settextstyle(20, 0, "微软雅黑");
    outtextxy(40, 20, "航班号");
    outtextxy(200, 20, "始发地");
    outtextxy(300, 20, "目的地");
    outtextxy(400, 20, "始发时间");
    outtextxy(550, 20, "到达时间");
    outtextxy(690, 20, "当前人数");
    outtextxy(780, 20, "可载余量");
    drawtext("返回", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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
    strcat(s7, "人");
    strcat(s8, "人");
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

            drawtext("返回", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m4.message == WM_LBUTTONDOWN)
            {
                adminAirplane();//返回主菜单
            }
        }
        else
        {
            setlinecolor(BROWN);
            rectangle(580, 550, 680, 580);
            setfillcolor(RGB(194, 195, 201));
            fillrectangle(580, 550, 680, 580);
            drawtext("返回", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }
    }

}
void printfindUI2(int k)
{
    int q = k;
    ExMessage m4;
    initgraph(1280, 650, SHOWCONSOLE);
    IMAGE img3;
    loadimage(&img3, "E:\\Visual Studio\\数据结构实验大作业\\picture\\whitegrand.jpg", 1280, 800, TRUE);
    putimage(0, 0, &img3);
    setfillcolor(RGB(204, 206, 219));
    fillrectangle(580, 550, 680, 580);
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    RECT D1 = { 580, 550, 680, 580 };
    settextstyle(20, 0, "微软雅黑");
    outtextxy(40, 20, "航班号");
    outtextxy(200, 20, "始发地");
    outtextxy(300, 20, "目的地");
    outtextxy(400, 20, "始发时间");
    outtextxy(550, 20, "到达时间");
    outtextxy(690, 20, "当前人数");
    outtextxy(780, 20, "可载余量");
    drawtext("购票", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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
    strcat(s7, "人");
    strcat(s8, "人");
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

            drawtext("购票", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m4.message == WM_LBUTTONDOWN)
            {
                //adminAirplane();//返回主菜单
                buyremaintext();
            }
        }
        else
        {
            setlinecolor(BROWN);
            rectangle(580, 550, 680, 580);
            setfillcolor(RGB(194, 195, 201));
            fillrectangle(580, 550, 680, 580);
            drawtext("购票", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
        int isok = MessageBox(hndtipsF, "找不到相应的航班", "提示", MB_OK);
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
    loadimage(&img2, "E:\\Visual Studio\\数据结构实验大作业\\picture\\whitegrand.jpg", 1280, 800, TRUE);
    putimage(0, 0, &img2);
    setfillcolor(RGB(204, 206, 219));
    fillrectangle(580, 550, 680, 580);
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    RECT D1 = { 580, 550, 680, 580 };
    settextstyle(20, 0, "微软雅黑");
    outtextxy(40, 20, "航班号");
    outtextxy(200, 20, "始发地");
    outtextxy(300, 20, "目的地");
    outtextxy(400, 20, "始发时间");
    outtextxy(550, 20, "到达时间");
    outtextxy(690, 20, "当前人数");
    outtextxy(780, 20, "可载余量");
    drawtext("返回", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //outtextxy(625, 435, "");//返回按钮

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
        strcat(s7, "人");
        strcat(s8, "人");
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

            drawtext("返回", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            if (m3.message == WM_LBUTTONDOWN)
            {
                adminAirplane();//返回主菜单
            }
        }
        else 
        {
            setlinecolor(BROWN);
            rectangle(580, 550, 680, 580);
            setfillcolor(RGB(194, 195, 201));
            fillrectangle(580, 550, 680, 580);
            drawtext("返回", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }
    }
}
void Buyretreat()
{
    //ReadAirmessageInfor(Data);
    initgraph(800, 620);//界面大小


    ExMessage m1;//定义鼠标信息
    cleardevice();//清屏

    //设置背景图片
    IMAGE img;
    loadimage(&img, "E:\\Visual Studio\\数据结构实验大作业\\picture\\fall.jpg", 900, 620);
    putimage(0, 0, &img);
    //setbkcolor(BROWN);
   // cleardevice();

    setbkmode(TRANSPARENT);
    setfillcolor(WHITE);

    int Rt[] = { 355 - 20-15, 500 - 20, 445 + 20+15, 540 + 20 };
    fillroundrect(r1[0], r1[1], r1[2], r1[3], 30, 30);//画矩形，即按钮
    fillroundrect(r2[0], r2[1], r2[2], r2[3], 30, 30);
    fillroundrect(Rt[0], Rt[1], Rt[2], Rt[3], 20, 20);
    
    RECT Rone = { R_st[0],R_st[1],R_st[2],R_st[3] };//矩形指针R1，方便后面在里面写字，不用计算字的位置
    RECT R2 = { r1[0],r1[1],r1[2],r1[3] };
    RECT R3 = { r2[0],r2[1],r2[2],r2[3] };//200,350,600,450
    RECT R4 = { Rt[0],Rt[1],Rt[2],Rt[3] };


    LOGFONT f;                          //字体样式指针
    gettextstyle(&f);					//获取字体样式
    f.lfHeight = 60;
    _tcscpy(f.lfFaceName, _T("隶书"));	//设置字体
    f.lfQuality = ANTIALIASED_QUALITY;  // 抗锯齿 
    settextstyle(&f);                   // 设置字体样式
    setbkmode(TRANSPARENT);             //字体背景透明
    settextcolor(WHITE);
    drawtext("欢迎", &Rone, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R1内输入文字，水平居中，垂直居中，单行显示
    settextcolor(BLACK);
    drawtext("航班订购", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("航班退订", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //getchar();
    while (TRUE)
    {
        m1 = getmessage();//获取鼠标操作
        if (m1.x > r1[0] && m1.x < r1[2] && m1.y>r1[1] && m1.y < r1[3])
        {
            setlinecolor(BLACK);
            //setlinestyle(0,0,1);
            setfillcolor(RGB(194, 195, 201));
            fillroundrect(r1[0], r1[1], r1[2], r1[3], 30, 30);
            drawtext("航班订购", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
            drawtext("航班退订", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
            LOGFONT g;                          //字体样式指针
            gettextstyle(&g);					//获取字体样式
            g.lfHeight = 40;
            settextstyle(&g);
            drawtext("返回", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
            drawtext("航班订购", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(r2[0], r2[1], r2[2], r2[3], 30, 30);
            drawtext("航班退订", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            fillroundrect(Rt[0], Rt[1], Rt[2], Rt[3], 20, 20);
            drawtext("返回", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

        }
        LOGFONT f;                          //字体样式指针
        gettextstyle(&f);					//获取字体样式
        f.lfHeight = 60;
        _tcscpy(f.lfFaceName, _T("隶书"));	//设置字体
        f.lfQuality = ANTIALIASED_QUALITY;  // 抗锯齿 
        settextstyle(&f);                   // 设置字体样式
        setbkmode(TRANSPARENT);             //字体背景透明
       

    }
}
void claimexpense()
{
    char email[25];
    char name[10];
    InputBox(name, 8, "请输入您的姓名：");
    if (strlen(name) != 0)
    {
        if (searchpeopletwo(name) != -1)
        {
            InputBox(email, 20, "请输入您的邮箱：");
            HWND hndtipsM = GetHWnd();//获取窗口句柄
            int isok = MessageBox(hndtipsM, "报销凭证以及时发送你的手机，请及时查收", "提示", MB_OK);
        }
        else
        {
            HWND hndtipsM = GetHWnd();//获取窗口句柄
            int isok = MessageBox(hndtipsM, "您还没有订票，请先购票", "提示", MB_OK);
        }
    }
    else
    {
        HWND hndtipsM = GetHWnd();//获取窗口句柄
        int isok = MessageBox(hndtipsM, "您还没有订票，请先购票", "提示", MB_OK);
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
        loadimage(&img3, "E:\\Visual Studio\\数据结构实验大作业\\picture\\paper.jpg", 1280, 800, TRUE);
        putimage(0, 0, &img3);
        setfillcolor(RGB(204, 206, 219));
        fillrectangle(580, 550, 680, 580);
        setbkmode(TRANSPARENT);
        settextcolor(BLACK);
        RECT D1 = { 580, 550, 680, 580 };
        settextstyle(20, 0, "微软雅黑");
        outtextxy(80, 20, "身份证号");
        outtextxy(215, 20, "姓名");
        outtextxy(300, 20, "性别");
        outtextxy(400, 20, "航班号");
        outtextxy(550, 20, "始发地");
        outtextxy(690, 20, "始发时间");
        outtextxy(788, 20, "座位号");
        outtextxy(880, 20, "出发日期");
        drawtext("返回", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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

                drawtext("返回", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                if (m4.message == WM_LBUTTONDOWN)
                {
                    BuyAirplane();//返回主菜单
                }
            }
            else
            {
                setlinecolor(BROWN);
                rectangle(580, 550, 680, 580);
                setfillcolor(RGB(194, 195, 201));
                fillrectangle(580, 550, 680, 580);
                drawtext("返回", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
    InputBox(name, 8, "请输入您的姓名：");
    if (strlen(name) != 0)
    {
       
        int q= searchpeopletwo(name);
        int p = Mess[q].planekey;
        if (q != -1)
        {
            ExMessage m4;
            initgraph(1000, 500);
            LOGFONT k;                          //字体样式指针
            gettextstyle(&k);					//获取字体样式
            k.lfHeight = 35;
            _tcscpy(k.lfFaceName, _T("楷体"));	//设置字体
            k.lfQuality = ANTIALIASED_QUALITY;  // 抗锯齿 
            settextstyle(&k);                   // 设置字体样式
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
            outtextxy(40, 20, "      登 机 牌        BOARDING PASS       登机牌");
            outtextxy(80, 130, "航班号");
            outtextxy(80, 200, Data[p].planename);
            outtextxy(260, 130, "日期");
            outtextxy(250, 200, Mess[q].date);
            outtextxy(410, 130, "发机时间");
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
            outtextxy(80, 300, "始发地");
            outtextxy(250, 300, Data[p].from_place);
            outtextxy(80, 400, "目的地");
            outtextxy(250, 400, Data[p].to_place);
            outtextxy(420, 300, "座位号");
            outtextxy(440, 400, Mess[q].sit);

            outtextxy(800, 130, "欢迎乘坐");
            outtextxy(800, 200, Data[p].planename);
            outtextxy(800, 270, Mess[q].date);
            outtextxy(800, 340, Data[p].from_place);
            outtextxy(800, 410, Mess[q].sit);
            Sleep(100);
            HWND hndtipsM = GetHWnd();//获取窗口句柄
            int isok = MessageBox(hndtipsM, "请认真核对信息是否继续打印", "提示", MB_OKCANCEL);
            if (isok = IDOK)
            {
                loadingpage();
                Sleep(100);
                HWND hndtipsM2 = GetHWnd();//获取窗口句柄
                int isok = MessageBox(hndtipsM2, "打印成功！", "提示", MB_OKCANCEL);
                BuyAirplane();
            }
        }
        else
        {
            HWND hndtipsM = GetHWnd();//获取窗口句柄
            int isok = MessageBox(hndtipsM, "没有找到你的相关购票信息，请先购票或稍后重试", "提示", MB_OK);
        }

    }
    else
    {
        HWND hndtipsM = GetHWnd();//获取窗口句柄
        int isok = MessageBox(hndtipsM, "您还没有订票，请先购票", "提示", MB_OK);
    }
     
    //getchar();  //setfillcolor(RGB(204, 206, 219));
    //fillrectangle(580, 550, 680, 580);
    //setbkmode(TRANSPARENT);
    //settextcolor(BLACK);
    //RECT D1 = { 580, 550, 680, 580 };
    //settextstyle(20, 0, "微软雅黑");
    //outtextxy(80, 20, "身份证号");
    //outtextxy(215, 20, "姓名");
    //outtextxy(300, 20, "性别");
    //outtextxy(400, 20, "航班号");
    //outtextxy(550, 20, "始发地");
    //outtextxy(690, 20, "始发时间");
    //outtextxy(788, 20, "座位号");
    //drawtext("返回", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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

    //        drawtext("返回", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //        if (m4.message == WM_LBUTTONDOWN)
    //        {
    //            BuyAirplane();//返回主菜单
    //        }
    //    }
    //    else
    //    {
    //        setlinecolor(BROWN);
    //        rectangle(580, 550, 680, 580);
    //        setfillcolor(RGB(194, 195, 201));
    //        fillrectangle(580, 550, 680, 580);
    //        drawtext("返回", &D1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //    }
    //}
}

/********功能函数的定义********/
void text()
{
    char Name[10];
    InputBox(Name, 10, "请输入该学生的姓名");
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
    //将文件中的数据读取到当前的结构体数组中
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
    printf("请输入需要修改的航班号:");
    scanf("%s", name);
    int i = 0;
    Airmessage no_use[5];
    while (fscanf(fp, "%s %s %s %d月%d日 %d:%d:%d %d:%d:%d %.2lf %d %d %d",
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
            //if(no_use[i].price== money)         //找到目标
        {
            rewind(fp);//重写指针到行首
            //fseek(fp, 0, SEEK_CUR); //回滚指针至修改航班前
            printf("请输入新的航班信息");
            scanf("%s", name);
            fprintf(fp, "%s", name); //覆盖写入
            break;
        }
    }
    fclose(fp);
}
void addingplane()
{
    while (TRUE)
    {
        int bit = 0;//判断输入大小
        InputBox(Data[nowair_num].planename, 7,"请输入航班班次：");
        bit = strlen(Data[nowair_num].planename);
        if (bit != 0)//当输入不为空的时候
        {
            int key = 0;//定义按钮用来判断是否重复
            for (int i = 0; i < nowair_num; i++)
                if (strcmp(Data[nowair_num].planename, Data[i].planename) == 0)
                {
                    //printf("%d", strcmp(Data[nowair_num].planename, Data[i].planename));
                    key = 1;
                }
            if (key == 1)
            {
                HWND hwndInput1 = GetHWnd();
                int isok = MessageBox(hwndInput1, "该航班已存在，请重新录入", "提示", MB_OK);
            }
            else
            {
                char timefrom[20];
                char timeto[20];
                char price[10];
                char num[5];
                InputBox(Data[nowair_num].from_place, 10, "请输入航班的始发地：", MB_OK);
                InputBox(Data[nowair_num].to_place, 10, "请输入航班的目的地：", MB_OK);
                InputBox(timefrom, 10, "请输入航班的启程时间：", MB_OK);
                int* arr1 = timetypetrans(timefrom);
             /* for (int i = 0; i < 3; i++)
                    printf("%d ", arr1[i]);数据测试*/
                Data[nowair_num].T_from.h = arr1[0];
                Data[nowair_num].T_from.m = arr1[1];
                Data[nowair_num].T_from.s = arr1[2];
                InputBox(timeto, 10, "请输入航班到达的时间：", MB_OK);
                int* brr = timetypetrans(timeto);
                /*printf("%s*", timeto);
                for (int i = 0; i < 3; i++)
                    printf("%d ^", brr[i]);*/
                Data[nowair_num].T_to.h = brr[0];
                Data[nowair_num].T_to.m = brr[1];
                Data[nowair_num].T_to.s = brr[2];
                InputBox(price, 5, "请输入航班的价格：", MB_OK);
                Data[nowair_num].price = atoi(price);
                InputBox(num, 5, "请输入航班最大承载人数：", MB_OK);
                Data[nowair_num].peopleNum.Maxnum = atoi(num);
                InputBox(num, 5, "请输入航班当前人数：", MB_OK);
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
int* timetypetrans( const char a[])//由于Inputbox只能输入str类型，需要将需要的数据转换城int方便计算
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
        int isok = MessageBox(hwndInput2, "录入成功！", "提示", MB_OK);
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
        int isok = MessageBox(hwndInput2, "修改成功！", "提示", MB_OK);
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
        int isok = MessageBox(hwndInput2, "信息不完整，尚未保存", "提示", MB_OK);
    }
}
int searchplane()
{
    int key = -1;
    char input[10];
    InputBox(input, 10, "请输入需要查找的航班号");
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
    //InputBox(input, 10, "请输入需要查找的航班号");
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
    InputBox(input, 10, "请输入查找信息的姓名：");
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
    //将文件中的数据读取到当前的结构体数组中
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
        int isok = MessageBox(hndtipsF, "找不到相应信息", "提示", MB_OK);
    }
    else
    {
        printfindticketUI(key);
    }
}
void ModifyAirplane()
{
    int r1 = searchplane();//返回值
    if ( r1== -1)//没找到
    {
        HWND hndtipsM = GetHWnd();//获取窗口句柄
        int isok = MessageBox(hndtipsM, "找不到航班信息!", "提示", MB_OK);
    }
    else//找到
    {
            char modi[30];
            char timefrom[20];
            char timeto[20];
            char price[10];
            char num[5];
            InputBox(Data[r1].planename, 10, "请输入修改后的航班号：", MB_OK);
            InputBox(Data[r1].from_place, 10, "请输入航班的始发地：", MB_OK);
            InputBox(Data[r1].to_place, 10, "请输入航班的目的地：", MB_OK);
            InputBox(timefrom, 10, "请输入航班的启程时间：", MB_OK);
            int* arr1 = timetypetrans(timefrom);
            /* for (int i = 0; i < 3; i++)
                   printf("%d ", arr1[i]);数据测试*/
            Data[r1].T_from.h = arr1[0];
            Data[r1].T_from.m = arr1[1];
            Data[r1].T_from.s = arr1[2];
            InputBox(timeto, 10, "请输入航班到达的时间：", MB_OK);
            int* brr = timetypetrans(timeto);
            /*printf("%s*", timeto);
            for (int i = 0; i < 3; i++)
                printf("%d ^", brr[i]);*/
            Data[r1].T_to.h = brr[0];
            Data[r1].T_to.m = brr[1];
            Data[r1].T_to.s = brr[2];
            InputBox(price, 5, "请输入航班的价格：", MB_OK);
            Data[r1].price = atoi(price);
            InputBox(num, 5, "请输入航班最大承载人数：", MB_OK);
            Data[r1].peopleNum.Maxnum = atoi(num);
            InputBox(num, 5, "请输入航班当前人数：", MB_OK);
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
    InputBox(name, 15, "请输入您的的姓名");
    while (TRUE)
    {
        if (strlen(name) != 0)
        {
            strcpy(Mess[nowman_num].personname,name);
            char fromplace[10];
            char toplace[10];
            InputBox(Mess[nowman_num].idcard, 30, "请输入您的身份证号：", MB_OK);
            InputBox(Mess[nowman_num].sex, 5, "请输入您的性别：", MB_OK);
            InputBox(fromplace, 10, "请输入您的始发地");
            InputBox(toplace, 10, "请输入您的目的地");
            HWND hwndInput3 = GetHWnd();
            int key = searchpeopleplace(fromplace, toplace);
            if (key != -1)
            {
                int isok = MessageBox(hwndInput3, "为您搜索到如下航班", "提示", MB_OKCANCEL);
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
                int isok = MessageBox(hwndInput2, "没有找到符合要求的航班！", "提示", MB_OKCANCEL);
                break;
            }
        }
        else
        {
            HWND hwndInput2 = GetHWnd();
            int isok = MessageBox(hwndInput2, "输入有误请,重新输入！", "提示", MB_OKCANCEL);

            if (isok == IDCANCEL)
            {
                break;
            }
            else
            {
                InputBox(name, 15, "请输入您的的姓名");
            }
        }
    }
}
    
      //  }
      //      //savepeopleInfor();
      //      nowman_num++;
      //      HWND hwndInput2 = GetHWnd();
      //      int isok = MessageBox(hwndInput2, "订票成功！", "提示", MB_OK);
      //}
void refundticket()
{
    char name[10] = "";
    InputBox(name, 10, "请输入您的的姓名");
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
            int isok = MessageBox(hwndInput2, "退票成功！", "提示", MB_OK);
        }
        else
        {
            HWND hwndInput3 = GetHWnd();
            int isok = MessageBox(hwndInput3, "没有找到相关信息", "提示", MB_OK);
        }
    }
    else
    {
        HWND hndtipsD = GetHWnd();
        int isok = MessageBox(hndtipsD, "没有找到相关信息", "提示", MB_OK);
    }
}
void buyremaintext()
{
    char buystr[10];
    InputBox(buystr, 30, "请输入航班号订购机票：", MB_OK);
    int pkey = searchplanetwo(buystr);
    Mess[nowman_num].planekey = pkey;
    InputBox(Mess[nowman_num].ticketnum, 5, "请输入订购机票的票数：", MB_OK);
    InputBox(Mess[nowman_num].date, 10, "请输入订购机票的日期：", MB_OK);
    InputBox(Mess[nowman_num].sit, 5, "请输入您想选择座位号（时间紧急来不及弄选项，随便坐哇先）：", MB_OK);
    HWND hwndInput2 = GetHWnd();
    int isok2 = MessageBox(hwndInput2, "订购成功", "提示", MB_OKCANCEL);
    savepeoplebuy();
    BuyAirplane();
    
}

/********主函数********/
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
