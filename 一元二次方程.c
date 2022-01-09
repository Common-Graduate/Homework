#include<stdio.h>
#include<math.h>
void two(double a, double b, double derta);
void one(double a, double b);
void zero();
int main()
{
again:
	printf("请输入一元二次方程 ax^2 + bx + c = 0 的三个系数:\na = ");
	double a = 0, b = 0, c = 0;
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	printf("c = ");
	scanf("%lf", &c);
	if (a == 0)
		if (b == 0)
		{
			printf("非法输入！请重新输入！\n");
			goto again;
		}
		else
		{
			printf("该方程的根为 %lf\n", -c / b);
			goto again;
		}
	double derta = b * b - 4 * a * c;
	if (derta > 0)
		two(a, b, derta);
	else
		if (derta == 0)
			one(a, b);
		else
			zero();
	return 0;
}
void two(double a, double b, double derta)
{
	printf("该方程有两个不相等的实数根：\nX1 = %lf\nX2 = %lf\n", (sqrt(derta) - b) / (2 * a), -(sqrt(derta) + b) / (2 * a));
}
void one(double a, double b)
{
	printf("该方程有两个相等的实数根：X = %lf\n", -b / (2 * a));
}
void zero()
{
	printf("该方程无实数根。\n");
}