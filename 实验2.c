#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义包裹结构体
typedef struct Parcel
{
	char num[30];
	struct Parcel* next;
}Parcel;

//链表初始化
Parcel* initParcelList()
{
	return NULL;
}

//快递入库
Parcel* addParcel(Parcel* head, char* num) {
    Parcel* newParcel = (Parcel*)malloc(sizeof(Parcel));
    strcpy(newParcel->num, num);
    newParcel->next = head;
    return newParcel;
}

//快递出库
Parcel* deleteParcel(Parcel* head, char* num)
{
	if (head == NULL)
	{
		printf("当前库中没有快递\n");
		return NULL;
	}

	if (strcmp(head->num, num) == 0)
	{
		Parcel* temp = head;
		head = head->next;
		free(temp);
		printf("已出库请取走\n");
		return head;
	}

	Parcel* current = head;
	while (current->next != NULL && strcmp(current->next->num, num) != 0)
	{
		current = current->next;
	}

	if (current->next == NULL)
	{
		printf("未找到该快递，请重试\n");
		return head;
	}
	Parcel* temp = current->next;
    current->next = current->next->next;
	free(temp);
	return head;
}

//快递查找
Parcel* searchParcel(Parcel* head, char* num)
{
	Parcel* current = head;
	while (current != NULL)
	{
		if (strcmp(current->num, num) == 0) // 修复了字符串比较问题
		{
			printf("找到了该快递\n");
			return current;
		}
		current = current->next;
	}
	printf("未找到该快递\n");
	return NULL;
}

//打印链表
void printParcel(Parcel* head)
{
	Parcel* current = head;
	while (current!= NULL)
	{
		printf("快递单号：%s\n", current->num);
		current = current->next;
	}
}

//主函数部分
int main()
{
	Parcel* parcelList = initParcelList();
	
	int choice;
	char inputNum[30];

	printf("欢迎使用快递管理系统！\n");

	while (1) {
		printf("\n功能菜单\n");
		printf("1. 快递入库\n");
		printf("2. 快递出库\n");
		printf("3. 查找快递\n");
		printf("4. 查看库中快递\n");
		printf("5. 退出系统\n");
		printf("请输入你的选择（1-5）: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("请输入要入库的快递单号: ");
			scanf_s("%s", inputNum,(unsigned)sizeof(inputNum));
			parcelList = addParcel(parcelList, inputNum);
			printf("快递单号 %s 已入库！\n", inputNum);
			break;

		case 2:
			printf("请输入要出库的快递单号: ");
			scanf_s("%s", inputNum,(unsigned)sizeof(inputNum));
			parcelList = deleteParcel(parcelList, inputNum);
			break;

		case 3:
			printf("请输入要查找的快递单号: ");
			scanf_s("%s", inputNum, (unsigned)sizeof(inputNum));
			searchParcel(parcelList, inputNum);
			break;

		case 4:
			printf("当前快递列表为：\n");
			printParcel(parcelList);
			break;

		case 5:
			printf("感谢使用，再见！\n");
			return 0;

		default:
			printf("输入无效，请输入 1-5 之间的数字！\n");
		}
	}
	
	return 0;
}