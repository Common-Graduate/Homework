#include<stdio.h>
int main()
{
	int N;
	scanf("%d", &N);
	int n = 0;
	int aH, ah, bH, bh;// a 喊，a划，b 喊，b 划
	static int a = 0;
	static int b = 0;
	while (n < N)
	{
		
		scanf("%d %d %d %d", &aH, &ah, &bH, &bh);
		if (ah != aH + bH)
		{
			if (bh != aH + bH)
				;
			else
				a++;
		}
		else
		{
			if (bh != aH + bH)
				b++;
			else
				;
		}
		n++;
	}
	printf("%d %d", a, b);
	return 0;
}