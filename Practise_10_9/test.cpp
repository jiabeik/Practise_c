#include<stdio.h>
#include<easyx.h>
#include<conio.h>
#include<stdlib.h>
#define Max 200//��󳤶�
enum direction//ö�ٳ�������
{
	up,
	down,
	right,
	left,
};
struct snake
{
	int size;//�ߴ�С
	int dir;//�߷���
	int speed;//���ٶ�
	POINT a[Max];//�ߵ����꣬POINT��x��y��
}st;
//huizhishiwu
struct Food
{
	int x;
	int y;
	bool flag;
	DWORD color;
}food;
//��ʼ��
void init()
{
	initgraph(480, 500);//����߽�
	srand(GetTickCount());
	st.size = 3;
	st.speed = 10;
	st.dir = right;
	for (int i = 0; i < st.size; i++)//�ߵĳ���
	{
		st.a[i].x = st.size * 10 - 10 * i;//�ҵ�����x�����ȴ���1����ͷ���Ҷ�
		st.a[i].y = 10;//�ҵ�����y
	}
	food.x = rand() % 480;
	food.y = rand() % 500;
	food.flag = true;
}

void draw()
{
	BeginBatchDraw();//˫�����ͼ����������
	setbkcolor(RGB(155, 50, 60));
	cleardevice();//���屳������ɫ
	//������
	setfillcolor(GREEN);//�����ߵ���ɫ
	for (int i = 0; i < st.size; i++)//�����߱���
	{
		solidcircle(st.a[i].x, st.a[i].y, 5);
	}
	//huizhishiwu
	setfillcolor(BLUE);
	if (food.flag)
	{
		solidcircle(food.x, food.y, 10);
	}
	EndBatchDraw();
}
//�ߵ��ƶ�
void move()
{
	for (int i = st.size - 1; i > 0; i--)//����������ƶ�
	{
		st.a[i] = st.a[i - 1];
	}
	switch (st.dir)
	{
	case up:
		st.a[0].y -= st.speed;
		if (st.a[0].y + 5 <= 0)
		{
			st.a[0].y = 500;
		}
		break;
	case down:
		st.a[0].y += st.speed;
		if (st.a[0].y - 5 >= 500)
		{
			st.a[0].y = 0;
		}
		break;
	case left:
		st.a[0].x -= st.speed;
		if (st.a[0].x + 5 <= 0)
		{
			st.a[0].x = 480;
		}
		break;
	case right:
		st.a[0].x += st.speed;
		if (st.a[0].x - 5 >= 480)
		{
			st.a[0].x = 0;
		}
		break;
	}
}
//ͨ�������ı��ƶ�����
void keyboard()
{
	if (_kbhit())//�ж��Ƿ��а���
	{
		switch (_getch())
		{
		case 'w':
			if (st.dir != down)
			{
				st.dir = up;
			}
			break;
		case 's':
			if (st.dir != up)
			{
				st.dir = down;
			}
			break;
		case 'a':
			if (st.dir != right)
			{
				st.dir = left;
			}
			break;
		case 'd':
			if (st.dir != left)
			{
				st.dir = right;
			}
			break;
		}
	}
}
//eatfood
void eatfood()
{
	if ((st.a[0].x >= food.x - 10) && (st.a[0].x <= food.x + 10) && (st.a[0].y >= food.y - 10) && (st.a[0].y <= food.y + 10))
	{
		food.flag = false;
		st.size++;
	}
}
int main()
{
	init();
	while (1)
	{
		draw();
		move();
		keyboard();
		eatfood();
		Sleep(100);
	}
	return 0;
}