#include<stdio.h>
int Fun(int a, int b)
{
	if (a % b)
		return Fun(b, a % b);
	else
		return b;
}
int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	printf("%d", Fun(m > n ? m : n, m < n ? m : n));
	return 0;
}