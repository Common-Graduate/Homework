#define N 10
#include<stdio.h>
void sort(int* pw, int* pp, int n, int m);
int total(int* pp, int m);
int main()
{
	int n = 0, m = 0;// n 块矿石，只卖 m 块
	scanf("%d%d", &n, &m);
	int weight[N] = { 0 };
	int price[N] = { 0 };
	int i = 0;
	while (i < n)
	{
		scanf("%d%d", &weight[i], &price[i]);
		i++;
	}
	sort(weight, price, n, m);//算法核心
	i = total(price, m);
	printf("%d", i);
	return 0;
}
void sort(int* pw, int* pp, int n, int m)
{
	int i = 0, j = 0, temp = 0;
	for (i = 0; i < n; i++)//做一个冒泡的循环将矿石按质量由低到高排序
	{//需要注意的是先排好最小的
		for (j = n - 1; j - 1 >= i; j--)
		{
			if (*(pw + j) < *(pw + j - 1))
			{
				temp = *(pw + j);
				*(pw + j) = *(pw + j - 1);
				*(pw + j - 1) = temp;
				temp = *(pp + j);//质量排序时跟着的价格也排序
				*(pp + j) = *(pp + j - 1);
				*(pp + j - 1) = temp;
			}
		}
		if (i >= m)//如果排了 m 块矿石，基本不用排序了
		{//因为只卖 m 块；这时还要考虑以下排到 m 块时是否有相同质量的矿石
			if (*(pw + i) != *(pw + i - 1))//如果有就需要继续排序
				break;
		}
	}
	if (i >= m)//如果最后的矿石是质量相同的，则需要把这些矿石按价格
	{//从大到小排序
		i--;
		int count = 0;//先判断最后有几块质量相同的
		while (*(pw + i) == *(pw + i - 1))
		{
			count++;
			i--;
		}
		int a = 0;
		for (;a <= m - i; a++)
		{
			for (j = count; j > a; j--)
			{
				if (*(pp + i + j) > *(pp + i + j - 1))
				{
					temp = *(pp + i + j);
					*(pp + i + j) = *(pp + i + j - 1);
					*(pp + i + j - 1) = temp;
				}
			}
		}
	}
}
int total(int* pp, int m)
{
	int i = 0, sum = 0;
	for (; i < m; i++)
	{
		sum += *(pp + i);
	}
	return sum;
}