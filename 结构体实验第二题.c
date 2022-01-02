#include<stdio.h>
#define N 10
typedef struct Student
{
	char id[11];
	char name[5];
	double class_0;
	double class_1;
	double class_2;
	double average;
}Student;
void Input(struct Student* p_stu);
void Average(struct Student* p_stu);
int Max(struct Student* p_stu);
int main()
{
	Student stu[N];
	int i = 0;
	printf("请输入 10 名学生的学号、姓名、3门课程的成绩：\n");
	printf("例：6109121*** 二狗子 60.5 70 80\n");
	while (i < N)
	{
		Input(&stu[i]);//输入数据
		Average(&stu[i]);//每输入一个学生的信息，计算其平均成绩
		i++;
	}
	printf("每位学生的三门课的平均成绩如下：\n");//先输出每位学生的平均成绩
	for (i = 0; i < N; i++)
		printf("%s %lf\n", stu[i].name, stu[i].average);
	i = Max(&stu[0]);//再用函数求出最高分成绩同学对应的 i
	printf("最高分学生的数据如下：\n");
	printf("学号     %s\n", stu[i].id);
	printf("姓名     %s\n", stu[i].name);
	printf("课程1    %lf\n",stu[i].class_0);
	printf("课程2    %lf\n",stu[i].class_1);
	printf("课程3    %lf\n",stu[i].class_2);
	printf("平均分数 %lf\n",stu[i].average);
	return 0;
}
void Input(struct Student* p_stu)
{
	scanf("%s %s %lf %lf %lf", p_stu->id, p_stu->name, &p_stu->class_0, &p_stu->class_1, &p_stu->class_2);
}
void Average(struct Student* p_stu)
{
	p_stu->average = (p_stu->class_0 + p_stu->class_1 + p_stu->class_2) / 3;
}
int Max(struct Student* p_stu)
{
	int ret = 0;
	for (int i = 0; i + 1 < N; i++)
	{
		if (p_stu[i].average < p_stu[i + 1].average)
			ret = i + 1;
	}
	return ret;
}