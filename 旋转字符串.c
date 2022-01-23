//左旋转字符串中的k个字符
#include <stdio.h>
#include <string.h>
#include <assert.h>
void LeftMove(char* p, int k);
void Reverse(char* left, int k);
int main()
{
	char arr[] = "abcdef";
	int k = 2;
	LeftMove(arr, k);
	printf("%s", arr);
	return 0;
}
void LeftMove(char* p, int k)
{   //三步翻转法
	assert(p != NULL);
	//第一步：先翻转前面的
	Reverse(p, k);
	//第二步：翻转后面的
	Reverse(p + k, strlen(p + k));
	//第三步：全部翻转
	Reverse(p, strlen(p));
}
void Reverse(char* left, int k)
{
	char* right = left + k - 1;
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}