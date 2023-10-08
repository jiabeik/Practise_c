#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

//struct Stu
//{
//	char name[20];
//	int age;
//	double NOIP;
//}st[5];
//int main()
//{
//	int i = 0;
//	int n = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%s", &st[i].name);
//		scanf("%d%lf", &st[i].age, &st[i].NOIP);
//		st[i].age++;
//		if (st[i].NOIP * 1.2 > 600)
//		{
//			st[i].NOIP = 600;
//		}
//		else
//		{
//			st[i].NOIP *= 1.2;
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf("%s ", st[i].name);
//		printf("%d %1.lf\n", st[i].age, st[i].NOIP);
//	}
//	return 0;
//}

//int main()
//{
//	int a, i, j = 0;
//	int arr[21][21] = { 0 };
//	scanf("%d", &a);
//	for (i = 1; i <= a; i++)
//	{
//		arr[i][1] = arr[i][i] = 1;
//	}
//	for (i = 1; i <= a; i++)
//	{
//		for (j = 2; j < i; j++)
//		{
//			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//	for (i = 1; i <= a; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

struct Stu
{
	int num;
	int study;
	int move;
}st[100000000];

//void IsExc(struct Stu s1)
//{
//	if (s1.study + s1.move > 140 && s1.study * 7 + s1.move * 3 >= 800) 
//	{
//		printf("Excellent\n");
//	}
//	else 
//	{
//		printf("Not excellent\n");
//	}
//}

int main()
{
	int i = 0;
	int n = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d", &st[i].num, &st[i].study, &st[i].move);
	}
	for (i = 0; i < n; i++)
	{
		//IsExc(st[i]);
		if ((st[i].study + st[i].move) > 140 && (st[i].study * 7 + st[i].move * 3) >= 800)
		{
			printf("Excellent\n");
		}
		else
		{
			printf("Not excellent\n");
		}
	}
	return 0;
}