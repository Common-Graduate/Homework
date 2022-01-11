#define N 10
#include<stdio.h>
int Greedy(int n, int k, int* p)；

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int arr[N] = { 0 };
	int i = 0;
	while (i <= k)
	{
		scanf("%d", &arr[i]);
		i++;
	}
	i = Greedy(n, k, arr);
	if (i)
		printf("%d", i);
	else
		printf("No Solution!");
	return 0;
}
int Greedy(int n, int k, int* p)
{
	int i = 0, km = 0, sum = 0;
	while (i <= k)
	{
		if (*(p + i) > n)//一旦有一个加油站距离上一个超过了汽车的最大行驶路程，就无法到达
			return 0;
		km += *(p + i);
		if (km > n)//不加油一直走看看能走到哪
		{//如果走的超过了，就在上一个加油站计一次加油
			km = *(p + i);
			sum++;
		}
		i++;
	}
	return sum;
}