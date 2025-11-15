#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// 定义顾客结构体
typedef struct
{
    char tableType;     // 餐桌类型
    int num;            // 餐桌序号
    char contact[20];   // 联系方式
} Customer;

// 定义循环队列结构体
typedef struct
{
    Customer queue[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

// 初始化队列
void initQueue(CircularQueue* queue)
{
    queue->front = -1;
    queue->rear = -1;
}

// 判断队列是否为空
int isQueueEmpty(CircularQueue* queue)
{
    return queue->front == -1;
}

// 判断队列是否已满
int isQueueFull(CircularQueue* queue)
{
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// 入队操作
void enqueue(CircularQueue* queue, Customer customer)
{
    if (isQueueFull(queue))
    {
        printf("队列已满，无法入队\n");
        return;
    }
    if (isQueueEmpty(queue))
    {
        queue->front = 0;
        queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->queue[queue->rear] = customer;
}

// 出队操作
Customer dequeue(CircularQueue* queue)
{
    Customer customer = { '\0', 0, "" };
    if (isQueueEmpty(queue))
    {
        printf("队列已空，无法出队\n");
        return customer;
    }
    customer = queue->queue[queue->front];
    if (queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return customer;
}

// 获取队头顾客信息
Customer peek(CircularQueue* queue)
{
    Customer customer = { '\0', 0, "" };
    if (isQueueEmpty(queue))
    {
        printf("队列已空，没有队头顾客\n");
        return customer;
    }
    return queue->queue[queue->front];
}

// 显示队列所有顾客信息
void displayQueue(CircularQueue* queue)
{
    if (isQueueEmpty(queue))
    {
        printf("队列为空\n");
        return;
    }
    int i = queue->front;
    printf("队列中的顾客信息：\n");
    while (1)
    {
        printf("餐桌类型: %c, 餐桌序号: %d, 联系方式: %s\n",
            queue->queue[i].tableType, queue->queue[i].num, queue->queue[i].contact);
        if (i == queue->rear) break;
        i = (i + 1) % MAX_SIZE;
    }
}

int main()
{
    CircularQueue queue;
    initQueue(&queue);
    int choice;
    Customer customer;

    while (1)
    {
        printf("\n请选择操作：\n");
        printf("1. 客人入队\n");
        printf("2. 客人出队\n");
        printf("3. 查看队头客人信息\n");
        printf("4. 显示所有客人信息\n");
        printf("5. 退出\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("请输入餐桌类型 (A: 小桌, B: 中桌, C: 大桌): ");
            scanf(" %c", &customer.tableType);
            printf("请输入餐桌序号: ");
            scanf("%d", &customer.num);
            printf("请输入联系方式: ");
            scanf("%s", customer.contact);
            enqueue(&queue, customer);
            printf("取号成功！\n");
            break;
        case 2:
            customer = dequeue(&queue);
            if (customer.tableType != '\0')
            {
                printf("叫号：%c%d，联系方式：%s\n", customer.tableType, customer.num, customer.contact);
            }
            break;
        case 3:
            customer = peek(&queue);
            if (customer.tableType != '\0')
            {
                printf("当前队头客人 - 餐桌类型: %c, 餐桌序号: %d, 联系方式: %s\n",
                    customer.tableType, customer.num, customer.contact);
            }
            break;
        case 4:
            displayQueue(&queue);
            break;
        case 5:
            printf("退出系统\n");
            return 0;
        default:
            printf("无效的选择，请重新输入\n");
        }
    }
    return 0;
}
