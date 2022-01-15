#include<stdio.h>
int count(char* p, char ch, int i);
int main()
{
	printf("请输入一个字符串：(不超过100个字符）\n");
	char str_1[100] = { 0 };
	int i = -1;
	do //统计初始字符个数并输入
	{
		i++;
		str_1[i] = getchar();
	} while (str_1[i] != '\n');
	printf("请输入想要查找的字符：");
	char ch = '0';
	scanf("%c", &ch);
	printf("字符 %c 在该字符串中出现 %d 次", ch, count(str_1, ch, i));
	return 0;
}
int count(char* p, char ch, int i)
{
	int cou = 0, j = 0;
	for (; j <= i; j++)
	{
		if (*p == ch)
			cou++;
		p++;
	}
	return cou;
}