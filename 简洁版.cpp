//�����±�����


#include <stdio.h>
#include <graphics.h>//ͼ�ν���ͷ�ļ�
#include <math.h>	//��ѧͷ�ļ�
#include <time.h>
#include <mmsystem.h>//ý��ͷ�ļ�
#pragma comment (lib,"winmm.lib")//ý����ļ�

#define PI 3.1415926548
//�±��ṹ��

//��ӭ����
void Welcome();
int main()
{

	//��ʼ������
	initgraph(900, 600);
	srand((unsigned int)time(NULL));
	DWORD t1 = timeGetTime();//ѡ���±�ʱ��


	//����
	mciSendString(TEXT("open ./mid/mid.mp3 alias music"), 0, 0, 0);
	mciSendString(L"play music", 0, 0, 0);


	//���û�ӭ���溯��
	Welcome();



	while (true);
	return 0;
}
//��ӭ����
void Welcome()
{


	settextcolor(RGB(247, 68, 73));

	int x, y;
	for (int i = 0; i < 50; i++)
	{
		cleardevice();//����
		x = 400 + (180 * sin(PI * 2 * i / 60));
		y = 200 + (180 * cos(PI * 2 * i / 60));
		settextstyle(i, 0, L"����");
		outtextxy(x, y, L"ףС��");
		outtextxy(x + 100, y + 60, L"��������ڣ�");

		//outtextxy(x+50, y+100, L"ף��");
		Sleep(50);
	}
	getchar();
	cleardevice();
	IMAGE img;
	loadimage(&img, L"./mid/mid.png", 900, 600);

	putimage(0, 0, &img);
	settextstyle(50, 0, L"����");
	outtextxy(300, 400, L"ףС��");
	outtextxy(400, 460, L"��������ڣ�");


}