#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

//定义栈
typedef struct
{
	int data[MAX_SIZE];
	int top;
}Stack;

//初始化栈
void initStack(Stack* s)
{
	s->top = -1;
}
//判断栈是否为空
int isEmpty(Stack* s)
{
	return s->top == -1;
}

//判断栈是否满
int isFull(Stack* s)
{
	return s->top == MAX_SIZE - 1;
}

//入栈
void push(Stack* s, int value)
{
	if (isFull(s))
	{
		printf("栈已满，无法入栈\n");
		return;
	}
	s->data[++(s -> top)] = value;
}

//出栈
void pop(Stack* s,int value)
{
	if (isEmpty(s))
	{
		printf("栈已空，无法出栈\n");
		return;
	}
	s->data[(s->top)--] = value;
}

void decimalToBinary(int n)
{
	Stack s;
	initStack(&s);
	while (n > 0)
	{
		int remainder = n % 2;
		push(&s, remainder);
		n = n / 2;
	}
	printf("转换后的二进制数为：");
	while (!isEmpty(&s))
	{
		int binaryDigit = s.data[s.top];
		printf("%d", binaryDigit);
		pop(&s, binaryDigit);
	}
	printf("\n");
}

int main()
{
	int decimal;
	printf("请输入一个十进制整数：\n");
	scanf_s("%d", &decimal);
	decimalToBinary(decimal);
	return 0;

}
