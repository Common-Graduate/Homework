//输入在一行中依次给出 A 和 B，均为不超过 100 位的正整数，其间以空格分隔。
//在一行中输出加密后的结果。
#include<stdio.h>
int main()
{
	char arr1[100] = { 0 };
	char arr2[100] = { 0 };
	scanf("%s %s", arr1, arr2);
	int a = 0, b = 0;
	while (arr1[a] != '\0')
		a++;
	while (arr2[b] != '\0')
		b++;
	int x[100] = { 0 }, y[100] = { 0 }, i = 0, j = 0;
	for (j = a - 1; i < a; i++, j--)
		x[i] = arr1[j] - 48;
	for (i = 0, j = b - 1; i < b; i++, j--)
		y[i] = arr2[j] - 48;
	int arr3[100] = { 0 };
	for (i = 0; i < a || i < b; i++)
	{
		if (i % 2 == 0)
			arr3[i] = (x[i] + y[i]) % 13;
		else
			if (y[i] - x[i] < 0)
				arr3[i] = y[i] - x[i] + 10;
			else
				arr3[i] = y[i] - x[i];
	}
	for (i--; i >= 0; i--)
	{
		if (arr3[i] == 10)
			printf("J");
		else
			if (arr3[i] == 11)
				printf("Q");
			else
				if (arr3[i] == 12)
					printf("K");
				else
					printf("%d", arr3[i]);
	}
	return 0;
}