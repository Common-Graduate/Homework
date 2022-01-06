#define N 10
#include<stdio.h>
void Sort_down(int* p, int k)；
int Fun(int* p, int sum);
void Sort_up(int* p, int right)；

int main()
{
	int k = 0;// k 个数列
	scanf("%d", &k);
	int i = 0;
	int arr[N] = { 0 };
	while (i < k)//每个数列的元素个数
	{
		scanf("%d", &arr[i++]);
	}
	Sort_down(arr, k);//冒泡排序降序排列
	printf("%d ", Fun(&arr[1], arr[0]));
	Sort_up(arr, k - 1);
	printf("%d", Fun(&arr[1], arr[0]));
	return 0;
}
void Sort_down(int* p, int k)
{
	int i = 0, j = 0, temp = 0;
	for (i = k - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (*(p + j) < *(p + j + 1))
			{
				temp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = temp;
			}
		}
	}
}
int Fun(int* p, int sum)
{
	sum += *p - 1;
	if (*(p + 1) != 0)
	{
		sum += Min(p + 1, sum + 1);
	}
	return sum;
}
void Sort_up(int* p, int right)
{
	int left = 0, temp = 0;
	while (left <= right)
	{
		temp = *(p + left);
		*(p + left) = *(p + right);
		*(p + right) = temp;
		left++;
		right--;
	}
}
