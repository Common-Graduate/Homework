#include<stdio.h>
void hex(int dec, char arr[]);
int main()
{
	int dec = 0;
	printf("请输入一个十进制整数：");
	scanf("%d", &dec);
	printf("该数的十六进制表示是：");
	if (dec < 0)//是负数的话先输出负号
	{
		printf("-");
		dec = -dec;
	}
	char arr[10] = { 0 };
	hex(dec, arr);
	printf("%s", arr);
	return 0;
}
void hex(int dec, char arr[])
{
	int i = 0;
	while (1)//求出十六进制的字符串
	{
		arr[i] = dec % 16;
		i++;
		if (dec <= 16)
			break;
		dec = dec / 16;
	}
	int j = i;
	for (i--; i >= 0; i--)//将十六进制的整型转换为 char 型
	{
		if (arr[i] < 10)
			arr[i] += 48;
		else
			arr[i] += 55;
	}
	char temp[10] = { 0 };
	for (i = 0, j--; j >= 0; i++, j--)
		temp[i] = arr[j];
	for (i--; i >= 0; i--)
		arr[i] = temp[i];
}