#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100];
int n, m;
int main()
{
	int i, j, k;
	double f = 0, ans = 0, max = 0;
	scanf_s("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf_s("%d", &a[j]);
			sort(a + 0, a + m);
		}
		for (k = 1; k < m - 1; k++)
		{
			ans += a[k];
		}
		f = (ans / (m - 2));
		if (f > max)
		{
			max = f;
		}

	}
	printf("%.2lf", max);

	return 0;
}