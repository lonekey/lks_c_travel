#define _CRT_NO_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_TEACHERS 100

typedef struct {
    char account[20];
    char password[20];
    char permission[20];
} Teacher;

typedef struct {
    Teacher teachers[MAX_TEACHERS];
    int length;
} TeacherList;

void InitList(TeacherList* list) {
    list->length = 2;

    strcpy_s(list->teachers[0].account, sizeof(list->teachers[0].account), "teacher1");
    strcpy_s(list->teachers[0].password, sizeof(list->teachers[0].password), "123456");
    strcpy_s(list->teachers[0].permission, sizeof(list->teachers[0].permission), "教学督导");

    strcpy_s(list->teachers[1].account, sizeof(list->teachers[1].account), "teacher2");
    strcpy_s(list->teachers[1].password, sizeof(list->teachers[1].password), "654321");
    strcpy_s(list->teachers[1].permission, sizeof(list->teachers[1].permission), "普通教师");
}

int Login(TeacherList* list) {
    char Account[20], Password[20];
    int logins = 0;

    while (logins < 2) {
        printf("请输入账号: ");
        scanf_s("%s", Account, (unsigned)sizeof(Account));
        printf("请输入密码: ");
        scanf_s("%s", Password, (unsigned)sizeof(Password));

        for (int i = 0; i < list->length; i++) {
            if (strcmp(Account, list->teachers[i].account) == 0 &&
                strcmp(Password, list->teachers[i].password) == 0) {
                printf("你好%s！您的权限是%s\n", Account, list->teachers[i].permission);
                return 1;
            }
        }

        logins++;
        if (logins < 2) {
            printf("账号或密码错误还有%d次机会\n", 2 - logins);
        }
        else {
            printf("登入失败，超过最大登入次数！\n");
        }
    }
    return 0;
}

void AddTeacher(TeacherList* list) {
    if (list->length >= MAX_TEACHERS) {
        printf("教师数量已达上限！\n");
        return;
    }

    printf("请输入账号: ");
    scanf_s("%s", list->teachers[list->length].account, (unsigned)sizeof(list->teachers[list->length].account));
    printf("请输入密码: ");
    scanf_s("%s", list->teachers[list->length].password, (unsigned)sizeof(list->teachers[list->length].password));
    printf("请输入权限: ");
    scanf_s("%s", list->teachers[list->length].permission, (unsigned)sizeof(list->teachers[list->length].permission));

    list->length++;
    printf("新教师添加成功！\n");
}

void DeleteTeacher(TeacherList* list) {
    char deleteaccount[20];
    int found = 0;

    printf("请输入要删除的教师账号: ");
    scanf_s("%s", deleteaccount, (unsigned)sizeof(deleteaccount));

    for (int i = 0; i < list->length; i++) {
        if (strcmp(deleteaccount, list->teachers[i].account) == 0) {
            // 将后面的教师前移
            for (int j = i; j < list->length - 1; j++) {
                list->teachers[j] = list->teachers[j + 1];
            }
            list->length--;
            found = 1;
            printf("教师账号%s已删除！\n", deleteaccount);
            break;
        }
    }

    if (!found) {
        printf("未找到该教师账号：%s\n", deleteaccount);
    }
}

void Menu() {
    printf("\n教学质量评价系统\n");
    printf("1. 添加教师\n");
    printf("2. 删除教师\n");
    printf("0. 退出系统\n");
    printf("请选择操作: ");
}

int main() {
    TeacherList list;
    InitList(&list);

    printf("欢迎登入教学质量评价系统\n");

    if (Login(&list)) {
        int choice;
        do {
            Menu();
            scanf_s("%d", &choice);

            switch (choice) {
            case 1:
                AddTeacher(&list);
                break;
            case 2:
                DeleteTeacher(&list);
                break;
            case 0:
                printf("退出系统，感谢使用！\n");
                break;
            default:
                printf("无效操作，请重新输入！\n");
                break;
            }
        } while (choice != 0);
    }

    return 0;
}
