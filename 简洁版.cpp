//无落月饼功能


#include <stdio.h>
#include <graphics.h>//图形界面头文件
#include <math.h>	//数学头文件
#include <time.h>
#include <mmsystem.h>//媒体头文件
#pragma comment (lib,"winmm.lib")//媒体库文件

#define PI 3.1415926548
//月饼结构体

//欢迎界面
void Welcome();
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
	Welcome();



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
		outtextxy(x + 100, y + 60, L"快乐中秋节！");

		//outtextxy(x+50, y+100, L"祝！");
		Sleep(50);
	}
	getchar();
	cleardevice();
	IMAGE img;
	loadimage(&img, L"./mid/mid.png", 900, 600);

	putimage(0, 0, &img);
	settextstyle(50, 0, L"宋体");
	outtextxy(300, 400, L"祝**");
	outtextxy(400, 460, L"快乐中秋节！");


}
