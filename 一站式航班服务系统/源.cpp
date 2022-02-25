#undef UNICODE
#undef _UNICODE
#define _CRT_SECURE_NO_WARNINGS //一些老函数报错
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h> //Easyx的图形库头文件
#include<string.h>
#include<ctype.h>//检测字符

void menu();

typedef struct Student
{
	char s_Num[30];//学号
	char s_Name[30];//姓名
	char s_computer[30]; //计
	char s_Math[30];//数
}Student;

int R[] = { 150,50,650,150 };
int r1[] = { 200,200,600,250 };
int r2[] = { 200,270,600,320 };
int r3[] = { 200,340,600,390 };
int r4[] = { 200,410,600,460 };
int r5[] = { 200,480,600,530 };
int r6[] = { 200,550,600,600 };
int nowstu_num = 0;
Student s[30];
void ReadInfor()
{
	FILE* fp = fopen("StudentInfo.txt", "r");
	if (fp == NULL)
	{
		return;
	}
	//将文件中的数据读取到当前的结构体数组中
	for (int i = 0; i < 15; i++)
	{

		fscanf(fp, "%s\t%s\t%s\t%s\t\n",
			s[i].s_Num,
			s[i].s_Name,
			s[i].s_computer,
			s[i].s_Math);
	}

	int FileStudentNums = 0;
	//读取出文件中数据的人数个数
	for (int j = 0; j < 15; j++)
	{
		if (strlen(s[j].s_Name) != 0)
		{
			nowstu_num = ++FileStudentNums;
		}
	}
	fclose(fp);
}


//保存数据到文件中
void SaveInfor()
{
	//如果学号和姓名都不是空的才写入文件
	if (strlen(s[nowstu_num].s_Num) != 0 && strlen(s[nowstu_num].s_Name) != 0)
	{
		FILE* fp = fopen("StudentInfo.txt", "a");//追加
		if (fp == NULL)
		{
			return;
		}
		fprintf(fp, "%s\t%s\t%s\t%s\n",
			s[nowstu_num].s_Num,
			s[nowstu_num].s_Name,
			s[nowstu_num].s_Math,
			s[nowstu_num].s_computer);
		fclose(fp);
		//保存完毕人数++
		nowstu_num++;
	}
}


void InputInfor()
{
	//通过循环来检查是否有重复的

	//输入学号
	while (1)
	{
		InputBox(s[nowstu_num].s_Num, 9, "请输入该学生的学号");

		int FlagInput2 = 0;
		//计算输入的字符串长度
		int nums = strlen(s[nowstu_num].s_Num);

		if (FlagInput2 == 0)
		{
			//判断是否输入重复
			int FlagInput1 = 0;
			for (int i = 0; i < nowstu_num; i++)
			{
				if (strcmp(s[nowstu_num].s_Num, s[i].s_Num) == 0)
				{
					FlagInput1 = 1;
				}
			}
			if (FlagInput1 == 1)
			{
				HWND hwndInput1 = GetHWnd();
				int isok = MessageBox(hwndInput1, "该学生已经存在，请重新输入", "提示", MB_OK);
			}
			if (FlagInput1 == 0)
			{
				break;
			}
		}
	}

	InputBox(s[nowstu_num].s_Name, 10, "请输入该学生的姓名");
	InputBox(s[nowstu_num].s_Math, 4, "请输入该学生的数学成绩");
	InputBox(s[nowstu_num].s_computer, 4, "请输入该学生的计算机成绩");

	SaveInfor();//保存数据
}



int cha()//查找
{
	char Input[30];
	InputBox(Input, 10, "请输入学生的姓名或学号");
	for (int k = 0; k < nowstu_num; k++)
	{
		if (strcmp(s[k].s_Name, Input) == 0 || strcmp(s[k].s_Num, Input) == 0)//两个字符串相等
		{
			return k;
		}
	}

	return -1;
}

void PrintUI(int q)//输出成绩界面
{
	ExMessage m2;
	initgraph(640, 480);
	IMAGE img1;
	loadimage(&img1, "C:\\Users\\HONOR\\Desktop\\表情包\\meme.jpg", 800, 620, TRUE);
	//clear;
	putimage(0, 0, &img1);
	setfillcolor(WHITE);
	fillrectangle(300, 380, 380, 410);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);

	settextstyle(20, 0, "黑体");
	outtextxy(40, 100, "学号");
	outtextxy(200, 100, "姓名");
	outtextxy(300, 100, "计算机");
	outtextxy(380, 100, "数学");
	outtextxy(320, 380, "返回");

	outtextxy(40, 140, s[q].s_Num);
	outtextxy(200, 140, s[q].s_Name);
	outtextxy(300, 140, s[q].s_computer);
	outtextxy(380, 140, s[q].s_Math);
	while (1) {
		m2 = getmessage();
		if (m2.x > 300 && m2.x < 380 && m2.y>380 && m2.y < 410) {
			setlinecolor(RED);
			rectangle(300, 380, 380, 410);
		}
		else {
			setlinecolor(WHITE);
			rectangle(300, 380, 380, 410);
		}
		if (m2.message == WM_LBUTTONDOWN) {
			menu();//返回到主菜单
		}
	}
}


void SaveInforModi()
{
	//先删掉
	remove("StudentInfo.txt");
	FILE* fp = fopen("StudentInfo.txt", "a");
	if (fp == NULL)
	{
		return;
	}
	//再重写
	for (int i = 0; i < nowstu_num; i++)
	{
		if (strlen(s[i].s_Num) != 0 && strlen(s[i].s_Name) != 0)
		{
			fprintf(fp, "%s\t%s\t%s\t%s\n",
				s[i].s_Num,
				s[i].s_Name,
				s[i].s_computer,
				s[i].s_Math);
		}
	}

	fclose(fp);
}

void Printfind()//调用cha()
{
	int fan1 = cha();//返回值
	if (fan1 == -1)//没找到
	{
		//获取窗口句柄
		HWND hndtipsF = GetHWnd();
		int isok = MessageBox(hndtipsF, "查无此人!", "提示", MB_OK);
	}
	else
	{
		PrintUI(fan1);
	}
}

void ModiInfor()
{
	int fan2 = cha();//返回值
	if (fan2 == -1)//没找到
	{
		HWND hndtipsM = GetHWnd();//获取窗口句柄
		int isok = MessageBox(hndtipsM, "查无此人!", "提示", MB_OK);
	}
	else//找到
	{
		while (1)
		{
			char modi[30];
			InputBox(modi, 9, "请输入需要修改的学生的学号");

			if (strcmp(modi, s[fan2].s_Num) == 0)//输入的学号与原来的学号相同
			{
				break;
			}
			else//不同
			{
				int flag = 0;
				int nums = strlen(modi);
				for (int i = 0; i < nowstu_num; i++)
				{
					if (strcmp(modi, s[i].s_Num) == 0)
					{
						flag = 1;
						break;
					}
				}
				if (flag == 1)
				{
					HWND hwndInput4 = GetHWnd();
					int isok = MessageBox(hwndInput4, "该学生已经存在，请重新输入", "提示", MB_OK);
				}
				else if (flag == 0)
				{
					memcpy(s[fan2].s_Num, modi, nums);//把新输入的学号复制到学生信息数组
					break;
				}
			}

		}
		InputBox(s[fan2].s_Name, 8, "请输入该学生的姓名");
		InputBox(s[fan2].s_computer, 10, "请输入该学生的计算机成绩");
		InputBox(s[fan2].s_Math, 10, "请输入该学生的数学成绩");
	}

	SaveInforModi();
}

void Dele()
{
	int dele = cha();
	if (dele == -1)//没找到
	{
		HWND hndtipsD = GetHWnd();
		int isok = MessageBox(hndtipsD, "查无此人!", "提示", MB_OK);
	}
	else
	{
		HWND hndtipsDS = GetHWnd();
		int isok = MessageBox(hndtipsDS, "确定删除？", "提示", MB_OKCANCEL);
		if (isok == IDOK)
		{
			//确定删除操作
			//将这个元素的后一个依次迁移
			for (int n = dele; n < nowstu_num; n++)
			{
				s[n] = s[n + 1];
			}
			nowstu_num--;
			//更新到文件中
			SaveInforModi();//对文件进重写
		}
		else if (isok == IDCANCEL)
		{

		}
	}
}



void Showall() //打印所以成绩
{
	ExMessage m3;
	initgraph(640, 480);
	IMAGE img2;
	loadimage(&img2, "C:\\Users\\HONOR\\Desktop\\表情包\\meme.jpg", 800, 620, TRUE);
	putimage(0, 0, &img2);
	setfillcolor(WHITE);
	fillrectangle(300, 430, 380, 460);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);

	settextstyle(20, 0, "黑体");
	outtextxy(40, 20, "学号");
	outtextxy(200, 20, "姓名");
	outtextxy(300, 20, "计算机");
	outtextxy(380, 20, "数学");
	outtextxy(320, 440, "返回");//返回按钮

	for (int q = 0; q <= nowstu_num; q++) {
		outtextxy(40, 60 + q * 20, s[q].s_Num);
		outtextxy(200, 60 + q * 20, s[q].s_Name);
		outtextxy(300, 60 + q * 20, s[q].s_computer);
		outtextxy(380, 60 + q * 20, s[q].s_Math);
	}


	while (1) {
		m3 = getmessage();
		if (m3.x > 300 && m3.x < 430 && m3.y>380 && m3.y < 460) {
			setlinecolor(RED);
			rectangle(300, 430, 380, 460);
		}
		else {
			setlinecolor(WHITE);
			rectangle(300, 430, 380, 460);
		}
		if (m3.message == WM_LBUTTONDOWN) {
			menu();//返回主菜单
		}
	}

}


void menu()
{
	//进入程序就读取数据，获取当前nowstu_num
	ReadInfor();
	initgraph(800, 620);//界面大小

	//鼠标操作1
	ExMessage m1;
	cleardevice();

	//背景图
	IMAGE img;
	loadimage(&img, "C:\\Users\\HONOR\\Desktop\\表情包\\meme.jpg", 800, 620, TRUE);
	//loadimage(&img, "C:\\Users\\86182\\source\\repos\\学生成绩管理系统2.0\\Camera Roll\\file.jpg", 800, 620);
	putimage(0, 0, &img);


	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	fillrectangle(r1[0], r1[1], r1[2], r1[3]);//画矩形，即按钮
	fillrectangle(r2[0], r2[1], r2[2], r2[3]);
	fillrectangle(r3[0], r3[1], r3[2], r3[3]);
	fillrectangle(r4[0], r4[1], r4[2], r4[3]);
	fillrectangle(r5[0], r5[1], r5[2], r5[3]);
	fillrectangle(r6[0], r6[1], r6[2], r6[3]);

	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	fillrectangle(r1[0], r1[1], r1[2], r1[3]);//画矩形，即按钮
	fillrectangle(r2[0], r2[1], r2[2], r2[3]);
	fillrectangle(r3[0], r3[1], r3[2], r3[3]);
	fillrectangle(r4[0], r4[1], r4[2], r4[3]);
	fillrectangle(r5[0], r5[1], r5[2], r5[3]);
	fillrectangle(r6[0], r6[1], r6[2], r6[3]);

	RECT R1 = { R[0],R[1],R[2],R[3] };//矩形指针R1，方便后面在里面写字，不用计算字的位置
	RECT R2 = { r1[0],r1[1],r1[2],r1[3] };
	RECT R3 = { r2[0],r2[1],r2[2],r2[3] };
	RECT R4 = { r3[0],r3[1],r3[2],r3[3] };
	RECT R5 = { r4[0],r4[1],r4[2],r4[3] };
	RECT R6 = { r5[0],r5[1],r5[2],r5[3] };
	RECT R7 = { r6[0],r6[1],r6[2],r6[3] };

	LOGFONT f;                          //字体样式指针
	gettextstyle(&f);					//获取字体样式
	f.lfHeight = 60;
	_tcscpy(f.lfFaceName, _T("隶书"));	//宋体
	f.lfQuality = ANTIALIASED_QUALITY;  // 抗锯齿 
	settextstyle(&f);                   // 设置字体样式
	setbkmode(TRANSPARENT);             //字体背景透明
	settextcolor(BLACK);
	drawtext("学生成绩管理系统", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R1内输入文字，水平居中，垂直居中，单行显示
	drawtext("成绩录入", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("成绩查询", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("成绩修改", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("成绩删除", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("成绩打印", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("退出系统", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//进入主界面选项操作界面
	while (1)
	{
		m1 = getmessage();//获取鼠标操作
		if (m1.x > r1[0] && m1.x < r1[2] && m1.y>r1[1] && m1.y < r1[3]) {
			setlinecolor(RED);
			rectangle(r1[0], r1[1], r1[2], r1[3]);
			if (m1.message == WM_LBUTTONDOWN)
			{
				InputInfor();//录入
			}
		}
		else if (m1.x >= r2[0] && m1.x <= r2[2] && m1.y >= r2[1] && m1.y <= r2[3]) {
			setlinecolor(RED);
			rectangle(r2[0], r2[1], r2[2], r2[3]);
			if (m1.message == WM_LBUTTONDOWN)
			{
				Printfind();//查询
			}
		}
		else if (m1.x >= r3[0] && m1.x <= r3[2] && m1.y >= r3[1] && m1.y <= r3[3]) {
			setlinecolor(RED);
			rectangle(r3[0], r3[1], r3[2], r3[3]);
			if (m1.message == WM_LBUTTONDOWN)
			{
				ModiInfor();//修改
			}
		}

		else if (m1.x >= r4[0] && m1.x <= r4[2] && m1.y >= r4[1] && m1.y <= r4[3]) {
			setlinecolor(RED);
			rectangle(r4[0], r4[1], r4[2], r4[3]);
			if (m1.message == WM_LBUTTONDOWN) {
				Dele();//删除

			}
		}
		else if (m1.x >= r5[0] && m1.x <= r5[2] && m1.y >= r5[1] && m1.y <= r5[3]) {
			setlinecolor(RED);
			rectangle(r5[0], r5[1], r5[2], r5[3]);
			if (m1.message == WM_LBUTTONDOWN) {
				Showall();//打印
			}
		}
		else if (m1.x >= r6[0] && m1.x <= r6[2] && m1.y >= r6[1] && m1.y <= r6[3]) {
			setlinecolor(RED);
			rectangle(r6[0], r6[1], r6[2], r6[3]);
			if (m1.message == WM_LBUTTONDOWN) {
				closegraph();//退出
			}
		}
		else {
			setlinecolor(WHITE);
			rectangle(r1[0], r1[1], r1[2], r1[3]);
			rectangle(r2[0], r2[1], r2[2], r2[3]);
			rectangle(r3[0], r3[1], r3[2], r3[3]);
			rectangle(r4[0], r4[1], r4[2], r4[3]);
			rectangle(r5[0], r5[1], r5[2], r5[3]);
			rectangle(r6[0], r6[1], r6[2], r6[3]);
		}
	}

}
int main()
{
	menu();
	return 0;
}
