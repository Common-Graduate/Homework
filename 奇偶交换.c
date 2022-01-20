#include <stdio.h>
void Move(int* p, int sz);
int main()
{
	//交换一个数组中的奇数和偶数，使得奇数在前，偶数在后
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Move(arr, sz);
	int i = 0;
	for (; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
void Move(int* p, int sz)
{
	int* left = p;
	int* right = p + sz - 1;
	while (left < right)
	{
		//从左边找偶数
		while ((left < right) && (*left % 2 == 1))
		{
			left++;
		}
		//从右边找奇数
		while ((left < right) && (*right % 2 == 0))
		{
			right--;
		}
		//将找到的数交换
		if (left < right)
		{
			int temp = *left;
			*left = *right;
			*right = temp;
		}
	}
}