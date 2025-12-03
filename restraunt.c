#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUES 100

typedef struct{
    char tableType;     // 餐桌类型
    int num;            // 餐桌序号
    char contact[20];   // 联系方式
} Customer;

// 定义循环队列结构体
typedef struct{
    Customer queue[MAX_QUEUES];
    int front;
    int rear;
} CircularQueue;

// 初始化队列
void initQueue(CircularQueue* queue){
    queue->front = -1;
    queue->rear = -1;
}

// 判断队列是否为空
int isEmpty(CircularQueue* queue){
    return queue->front == -1;
}

// 判断队列是否已满
int isFull(CircularQueue* queue){
    return((queue->rear +1) % MAX_QUEUES == queue->front);
}

// 入队操作
void takeNum(CircularQueue* queue){
    if (isFull(queue)){
        printf("用餐人数已满，无法取号\n");
        return;
    }
    Customer customer;
    printf("请输入餐桌类型(A大桌/B中桌/C小桌):\n");
    scanf(" %c",&customer.tableType);
    printf("请输入餐桌序号:\n");
    scanf("%d", &customer.num);
    printf("请输入您的联系方式:\n");
    scanf("%19s", customer.contact);
    if (isEmpty(queue)){
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_QUEUES;
    }
    queue->queue[queue->rear] = customer;
    printf("取号成功！您的餐桌序号是 %d\n", customer.num);
    }

// 出队操作
Customer callNum(CircularQueue* queue){
    if (isEmpty(queue)){
        printf("当前队伍没有顾客\n");
        Customer empty = {0, -1, ""};
        return empty;
    } 
    Customer customer = queue->queue[queue->front];
    printf("顾客 %d 准备用餐啦\n", customer.num);

    if(queue->front ==queue->rear){
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUES;
    }
    return customer;
}

// 查看队列
void viewQueue(CircularQueue* queue){
    if(isEmpty(queue)){
        printf("当前无人排队\n");
        return;
    }
    int i = queue->front;
    while (1){
        Customer customer = queue -> queue[i];
        printf("当前排队餐桌序号: %d\n",customer.num);
        if (i == queue->rear) break;
        i = (i + 1) % MAX_QUEUES;
    }
    return;
}

// 主菜单
int main()
{
    CircularQueue queue;
    initQueue(&queue);
    int choice;
    while(1){
        printf("\n欢迎使用取号系统,请选择以下操作\n");
        printf("1.取号\n");
        printf("2.叫号\n");
        printf("3.查看当前排队情况\n");
        printf("4.退出系统\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                takeNum(&queue);
                break;
            case 2:
                callNum(&queue);
                break;
            case 3:
                viewQueue(&queue);
                break;
            case 4:
                printf("感谢使用取号系统，再见！\n");
                exit(0);
            default:
                printf("无效选择，请重新输入\n");
        }
    }
    return 0;
}