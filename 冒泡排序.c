#include<stdio.h>
void bubble_sort(int* p, int i);
int main()
{
	int arr[100] = { 0 };
	printf("请输入不超过100个整数：\n");//数据输入
	int i = 0;
	do
	{
		scanf("%d", &arr[i]);
		i++;
	} while (getchar() != '\n');
	bubble_sort(arr, i - 1);  //冒泡排序法将数从大到小排序
	printf("从大到小排列如下：\n");
	for (int j = 0; j < i; j++)
		printf("%d ", arr[j]);
	return 0;
}
void bubble_sort(int* p, int i)
{
	int* P = p;//放置第一个数据的内存
	int j = 0, temp = 0;
	for (; i > 0; i--)
	{
		for (j = 0; j < i; j++)//每次从第一个数开始与后面的数比较
		{                      //若后面的数大，则交换两个数的位置
			if (*p < *(p + 1))//第一轮把最小的数放到最后
			{                 //第二轮循环执行时 i-- 即不考虑最后一个最小的数
				temp = *p;
				*p = *(p + 1);
				*(p + 1) = temp;
			}
			p++;
		}
		p = P;//每轮循环后都要将地址重新换为首个数据的地址
	}
}