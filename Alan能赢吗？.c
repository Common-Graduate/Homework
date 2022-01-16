/*假期属实无聊，不知道你们过得怎么样？
鉴于这无聊的情况，Alan想和小伙伴玩一个游戏，
于是他制定了游戏规则：给定一个表示分数的非负整数数组。 
玩家 1 从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任意一端拿取分数，
然后玩家 1 拿，…… 。每次一个玩家只能拿取一个分数，
分数被拿取之后不再可取。
直到没有剩余分数可取时游戏结束。
最终获得分数总和最多的玩家获胜。
请你预测玩家1：Alan是否会成为赢家。
你可以假设每个玩家的玩法都会使他的分数最大化，
平局算双赢。*/
#define N 10
#include<stdio.h>
long long Big(long long** left, long long** right)；
int Winner(long long* p_left, long long* p_right)；
int main()
{
	long long arr[N] = { 0 };
	int i = 0;
	do
	{
		scanf("%lld", &arr[i]);
		i++;
	} while (getchar() != '\n');
	if (Winner(&arr[0], &arr[i - 1]))
		printf("True");
	else
		printf("False");
	return 0;
}
long long Big(long long** left, long long** right)
{
	if (**left >= **right)
	{
		(*left)++;
		return *(*left - 1);
	}
	else
	{
		(*right)--;
		return *(*right + 1);
	}
}
int Winner(long long* p_left, long long* p_right)
{
	long long sum_A = 0, sum_B = 0;
	while (p_left < p_right)
	{
		sum_A += Big(&p_left, &p_right);
		sum_B += Big(&p_left, &p_right);
	}
	if (p_left == p_right)
		sum_A += *p_left;
	if (sum_A >= sum_B)
		return 1;
	else
		return 0;
}