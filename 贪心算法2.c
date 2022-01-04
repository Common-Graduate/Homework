#define N 10
#include<stdio.h>
void sort(double* ps, double* pe, int k);
int greedy(double* ps, double* pe, int k);

int main()
{
	int n = 0;// n 门课可以选择
	scanf("%d", &n);
	int i = 0;
	char cou[N][10] = { 0 };//课程名称
	double start[N] = { 0 };//开始时间
	double end[N] = { 0 };//结束时间
	while (i < n)
	{
		scanf("%s%lf%lf", cou[i], &start[i], &end[i]);
		i++;
	}
	sort(start, end, n);//按上课结束时间排序
	i = greedy(start, end, n);//贪心核心
	printf("%d", i);//输出最多选几门
	return 0;
}
void sort(double* ps, double* pe, int k)
{
	int i = 0;
	int j = 0;
	for (i = k; i > 0; i--)
	{
		for (j = 0; j + 1 < i; j++)
		{
			if (*(pe + j) > *(pe + j + 1))
			{
				double temp = *(pe + j);
				*(pe + j) = *(pe + j + 1);
				*(pe + j + 1) = temp;
				temp = *(ps + j);
				*(ps + j) = *(ps + j + 1);
				*(ps + j + 1) = temp;
			}
		}
	}
}
int greedy(double* ps, double* pe, int k)
{
	double end = 0;//用来存、放更新结束时间
	end = *pe;//结束最早的课程必上
	int i = 1, count = 1;// count 用来计算上了几门课
	for (; i < k; i++)
	{
		if (*(ps + i) >= end)//下一门课程的开始时间如果大于上一门课程的结束时间，就可以选择
		{                    //因为我们已经将课程结束时间排序
			end = *(pe + i);
			count++;
		}
	}
	return count;
}