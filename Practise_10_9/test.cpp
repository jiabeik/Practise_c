#include<stdio.h>
#include<easyx.h>
#include<conio.h>
#include<stdlib.h>
#define Max 200//最大长度
enum direction//枚举常量方向
{
	up,
	down,
	right,
	left,
};
struct snake
{
	int size;//蛇大小
	int dir;//蛇方向
	int speed;//蛇速度
	POINT a[Max];//蛇的坐标，POINT（x，y）
}st;
//huizhishiwu
struct Food
{
	int x;
	int y;
	bool flag;
	DWORD color;
}food;
//初始化
void init()
{
	initgraph(480, 500);//定义边界
	srand(GetTickCount());
	st.size = 3;
	st.speed = 10;
	st.dir = right;
	for (int i = 0; i < st.size; i++)//蛇的长度
	{
		st.a[i].x = st.size * 10 - 10 * i;//找到属性x，长度大于1的蛇头在右端
		st.a[i].y = 10;//找到属性y
	}
	food.x = rand() % 480;
	food.y = rand() % 500;
	food.flag = true;
}

void draw()
{
	BeginBatchDraw();//双缓冲绘图——不闪屏
	setbkcolor(RGB(155, 50, 60));
	cleardevice();//定义背景板颜色
	//绘制蛇
	setfillcolor(GREEN);//定义蛇的颜色
	for (int i = 0; i < st.size; i++)//绘制蛇本体
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
//蛇的移动
void move()
{
	for (int i = st.size - 1; i > 0; i--)//让蛇身跟着移动
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
//通过按键改变移动方向
void keyboard()
{
	if (_kbhit())//判断是否有按键
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