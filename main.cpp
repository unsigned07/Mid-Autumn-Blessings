#include <stdio.h>
#include <graphics.h>//图形界面头文件
#include <math.h>	//数学头文件
#include <time.h>
#include <conio.h>
#include <mmsystem.h>//媒体头文件
#pragma comment (lib,"winmm.lib")//媒体库文件

#define PI 3.1415926548
//月饼结构体
struct GET
{
	int x, y;//坐标
	int mx, my;//最低点
	int height;
	bool down;
	DWORD t1, t2, dt;//控制降落速度
	IMAGE img[1];//月饼图片
	byte n : 1;// 位段
}get [4];
//欢迎界面
void Welcome();
//初始化函数
void Init(int i);
void Loadpic();
void choose(DWORD& t1);
void down();
int main()
{

	//初始化窗口
	initgraph(900, 600);
	srand((unsigned int)time(NULL));
	DWORD t1 = timeGetTime();//选择月饼时间


	//音乐
	mciSendString(TEXT("open ./mid/mid.mp3 alias music"), 0, 0, 0);
	mciSendString(L"play music", 0, 0, 0);


	//调用欢迎界面函数
	//Welcome();
	for (int  i = 0; i < 4; i++)
	{
		Init(i);

	}
	Loadpic();

	while (1)
	{

		choose(t1);
		down();
	}

	while (true);
	return 0;
}
//欢迎界面
void Welcome()
{


	settextcolor(RGB(247, 68, 73));

	int x, y;
	for (int i = 0; i < 50; i++)
	{
		cleardevice();//清屏
		x = 400 + (180 * sin(PI * 2 * i / 60));
		y = 200 + (180 * cos(PI * 2 * i / 60));
		settextstyle(i, 0, L"宋体");
		outtextxy(x, y, L"祝**");
		outtextxy(x+100, y+60, L"快乐中秋节！");
		
		//outtextxy(x+50, y+100, L"祝！");
		Sleep (50);
	}
		getchar();
		cleardevice();
		settextstyle(50, 0, L"宋体");
		outtextxy(300, 400, L"祝**");
		outtextxy(400, 460, L"快乐中秋节！");


}

//初始化函数
void Init(int i)
{
	//初始化月饼
	get[i].x = 0;
	get[i].y = 0;
	get[i].mx = 0;
	get[i].my = 0;
	get[i].height = 0;
	get[i].down = false;//月饼还未掉落
	get[i].n = 0;
	get[i].t1 = timeGetTime();//获取系统时间
	get[i].dt = 20;//时间差

}

void Loadpic()
{
	//加载月饼
	IMAGE getimg;
	loadimage(&getimg, L"./mid/all.png", 160, 40);
	SetWorkingImage(&getimg);
	for (int i = 0; i < 4; i++)
	{
		int n = rand() % 4;
		getimage(&get[i].img[0],n*40,0,40,40);

	}
	SetWorkingImage(NULL);

}
//选择月饼
void choose(DWORD &t1)
{
	DWORD t2 = timeGetTime();
	if (t2 - t1 > 100)
	{
		int n = rand() % 20;
		if (n < 4 && get[n].down == false)
		{
			//重置月饼数据
			get[n].x =rand()%860 ;
			get[n].y =0;
			get[n].mx = get[n].x;
			get[n].my =600 ;
			get[n].height = get[n].my-get[n].y;
			get[n].down = true;
			putimage(get[n].x, get[n].y, &get[n].img[0]);
		}
		t1 = t2;
	}
}
//掉落月饼
void down()
{
	for (int i = 0; i < 4; i++)
	{
		get[i].t2 = timeGetTime();
		if (get[i].t2 - get[i].t1>get[i].dt && get[i].down == true)
		{
			putimage(get[i].x, get[i].y, &get[i].img[get[i].n],SRCINVERT);
			if (get[i].y <= get[i].my)
			{
				get[i].y += 5;
			}
			putimage(get[i].x, get[i].y, &get[i].img[get[i].n], SRCINVERT);
			get[i].t1 = get[i].t2;
		}
	}
}
