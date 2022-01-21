//A说：不是我
//B说：是C
//C说：是D
//D说：C在胡说
//已知三个人说了真话，一个人说了假话
#include <stdio.h>
int main()
{
	int killer = 0;//从凶手是a开始假设
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		if ((killer != 'A')//如果A说了真话，凶手不是A，则返回1
			+ (killer == 'C')//如果B说了真话，凶手是C，则返回1
			+ (killer == 'D')//如果C说了真话，凶手是D，则返回1
			+ (killer != 'D')//如果D说了真话，也就是C在胡说，即凶手不是D，则返回1
			== 3)//如果其中只有三个人说了真话，条件符号，输出凶手
			printf("killer is %c！", killer);
	}
	return 0;
}