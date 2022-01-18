//输入第一行给出一个正整数 N，即所有参赛队员总数。
//后 N 行，每行给出一位队员的成绩，格式为：队伍编号-队员编号 成绩
//其中队伍编号为 1 到 1000 的正整数，队员编号为 1 到 10 的正整数，成绩为 0 到 100 的整数。
#include <stdio.h>
int main()
{
	int N, n, a, b, c, i;
	scanf("%d", &N);
	int arr1[10000];
	int arr2[10000];
	int arr3[10000];
	n = 0;
	while (n < N)
	{
		scanf("%d-%d %d", &a, &b, &c);
		arr1[n] = a;
		arr2[n] = b;
		arr3[n] = c;
		n++;
	}
	int zcj=0;
	int d = 0;
	int t = 0;
	int bh[10000];
	int ZCJ[10000];
	for (n = 0; n < N; n++)
	{
		if (arr1[n] != 0)
		{
			bh[d] = arr1[n];
			d++;
		}
		for (i = n; i < N; i++)
		{
			if (arr1[n] == arr1[i])
			{
				zcj = zcj + arr3[i];
			}
		}
		t = d - 1;
		ZCJ[t] = zcj;
		zcj = 0;
	}
	int e, f = 0;
	for (e = 0; e < d; e++)
	{
		if (ZCJ[f] < ZCJ[e])f = e;
	}
	printf("%d %d", bh[f], ZCJ[f]);
	return 0;
}