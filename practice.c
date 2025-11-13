#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//4.5编写一个计算下载时间的程序
//int main()
//{
//	float spend, size;
//	float time;
//	printf("请输入以兆每秒为单位的下载速度和以兆为单位的文件大小：\n");
//	scanf_s("%f %f", &spend, &size);
//	time = size / spend;
//	printf("At %f megabits per second, a file of %f megabytes downloads in %f seconds.\n", spend, size, time);
//	return 0;
//}

//5.7求立方数
//int main()
//{
//	printf("请输入需要求立法的数：\n");
//	double num, x;
//	scanf_s("%lf", &num);
//	x = num * num * num;
//	printf("该数的立方为：%lf\n", x);
//	return 0;
//}

//6.3嵌套循环打印字母
//int main()
//{
//	char let = 'F';
//	char start;
//	char end;
//	for (end = let; end >= 'A'; end--)
//	{
//		for (start = let; start >= end; start--)
//			printf("%c", start);
//		printf("\n");
//	}
//	return 0;
//}

//6.5输入字母打印金字塔
// 步骤：
//1.计算行数（打印空格数=总行数-当前行数-1）
//2.外循环（控制行数）
//3.内循环1打印空格，2打印升序字母，3打印降序字母
//4.换行
int main()
{
	char ch;

	printf("请输入一个大写字母：\n");
	scanf_s("%c", &ch);

	int i, j, k;
	int rows = ch - 'A' + 1;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < rows - i - 1; j++)
			printf("  ");
		for (k = 0; k <= i; k++)
			printf("%c ", 'A' + k);
		for (k = i - 1; k >= 0; k--)
			printf("%c ", 'A' + k);
		printf("\n");
	}
	return 0;
}