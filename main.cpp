#include <stdio.h>
#include <graphics.h>//ͼ�ν���ͷ�ļ�
#include <math.h>	//��ѧͷ�ļ�
#include <time.h>
#include <conio.h>
#include <mmsystem.h>//ý��ͷ�ļ�
#pragma comment (lib,"winmm.lib")//ý����ļ�

#define PI 3.1415926548
//�±��ṹ��
struct GET
{
	int x, y;//����
	int mx, my;//��͵�
	int height;
	bool down;
	DWORD t1, t2, dt;//���ƽ����ٶ�
	IMAGE img[1];//�±�ͼƬ
	byte n : 1;// λ��
}get [4];
//��ӭ����
void Welcome();
//��ʼ������
void Init(int i);
void Loadpic();
void choose(DWORD& t1);
void down();
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
		outtextxy(x, y, L"111");
		outtextxy(x+100, y+60, L"11111��");
		
		//outtextxy(x+50, y+100, L"ף��");
		Sleep (50);
	}
		getchar();
		cleardevice();
		settextstyle(50, 0, L"����");
		outtextxy(300, 400, L"111");
		outtextxy(400, 460, L"1111111��");


}

//��ʼ������
void Init(int i)
{
	//��ʼ���±�
	get[i].x = 0;
	get[i].y = 0;
	get[i].mx = 0;
	get[i].my = 0;
	get[i].height = 0;
	get[i].down = false;//�±���δ����
	get[i].n = 0;
	get[i].t1 = timeGetTime();//��ȡϵͳʱ��
	get[i].dt = 20;//ʱ���

}

void Loadpic()
{
	//�����±�
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
//ѡ���±�
void choose(DWORD &t1)
{
	DWORD t2 = timeGetTime();
	if (t2 - t1 > 100)
	{
		int n = rand() % 20;
		if (n < 4 && get[n].down == false)
		{
			//�����±�����
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
//�����±�
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