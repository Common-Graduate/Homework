#include<stdio.h>
int main()
{
	char arr1[111] = { 0 }; char arr2[111] = { 0 };//定义两个char型数组来存放输入的数
	printf("请输入两个不超过110位的数字\n");
	scanf("%s", arr1); scanf("%s", arr2);
	int a = 0;                               //分别求出两个数是几位数
	for (;;)
	{
		if (arr1[a] != '\0') a++;
		else break;
	}
	int b = 0;
	for (;;)
	{
		if (arr2[b] != '\0') b++;
		else break;
	}
	int add1[111] = { 0 }, add2[111] = { 0 };//定义两个整型数组用来存放输入的数
	int i = 0;
	for (; i < a; i++)                    //将两个数由char型转变为int型
		add1[i] = arr1[a - i - 1] - 48;   //同时将两个数逆序排序，即个位放在最前面
	for (i = 0; i < b; i++)
		add2[i] = arr2[b - i - 1] - 48;
	int c = 0;
	int add3[112] = { 0 };                //定义第三个整型数组用来存放和
	if (a > b)
		c = a;
	else
		c = b;
	for (i = 0; i <= c; i++)            //将两个数的每位数相加
	{
		if (add1[i] + add2[i] + add3[i] > 9)//注意逢十进一
			add3[i + 1] = 1;
		add3[i] = (add1[i] + add2[i] + add3[i]) % 10;
	}
	if (add3[i] == 0) i--;//上面计算中，两位数最高为 c 位，但是两数相加后，有可能是 c+1 位
	if (add3[i] == 0) i--;//所以 for 循环之后 i=c+1 ，但是也有可能还是 c 位，这是为了去掉多余的0
	printf("两数相加得：\n");
	for (; i >= 0; i--)
	{
		printf("%d", add3[i]);
	}
	return 0;
}