#define N 100//表示最大能容纳的活动数
#include<stdio.h>

void sort(int* ps, int* pe, int k)；
int min(int* p, int* pa, int* pb)；
int greedy(int* ps, int* pe, int k)；

int main()
{
	int k = 0;//表示有几场活动
	scanf("%d", &k);
	int i = 0;
	int start[N] = { 0 };//每场活动的开始和结束时间分别放在两个数组中
	int end[N] = { 0 };
	while (i < k)
	{
		scanf("%d %d", &start[i], &end[i]);
		i++;
	}
	sort(start, end, k);//将活动按开始时间从低到高排序
	i = greedy(start, end, k);//贪心算法核心
	printf("%d", i);//输出需要几间教室
	return 0;
}
void sort(int* ps, int* pe, int k)//冒泡排序
{
	int i = 0;
	int j = 0;
	for (i = k; i > 0; i--)
	{
		for (j = 0; j + 1 < i; j++)
		{
			if (*(ps + j) > *(ps + j + 1))
			{
				int temp = *(ps + j);
				*(ps + j) = *(ps + j + 1);
				*(ps + j + 1) = temp;
				temp = *(pe + j);
				*(pe + j) = *(pe + j + 1);
				*(pe + j + 1) = temp;
			}
		}
	}
}
int min(int* p, int* pa, int* pb)
{
	int a = 0, b = *p;
	for (; *pa < *pb; (*pa)++)
	{
		if (*(p + *pa) < b)
		{
			b = *(p + *pa);
			a = *pa;
		}
	}
	*pa = a;
	return b;
}
int greedy(int* ps, int* pe, int k)
{
	int ret[N] = { 0 };//用来存放每个活动结束时间
	ret[0] = *pe;//首先将第一个活动的结束时间存入
	int a = 0, b = 1;
	int i = 0;
	for (i = 1; i < k; i++)//除去已经把第一场活动结束时间放进 ret 中
	{                      //还剩下 k-1 场活动需要安排
		a = 0;
		if (*(ps + i) >= min(ret, &a, &b))//判断下一场活动的开始时间是否大于 ret 中的最小的结束时间
			ret[a] = *(pe + i);//如果大于，说明该教室可用，不必占用新的教室
		else                  //否则再申请一个新的教室
		{
			ret[b] = *(pe + i);
			b++;
		}
	}
	return b;
}