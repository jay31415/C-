/*
 * @Author: your name
 * @Date: 2020-01-04 11:11:55
 * @LastEditTime : 2020-01-09 15:29:20
 * @LastEditors  : Please set LastEditors
 * @Description: 先查找，后修改
 * @FilePath: \myshare\manager_system_v3\modi.c
 */
#include "modi.h" //头文件

//检查身份证是否与其他身份证相同，同时保证当前的身份证可以保持不变
int CheckId1(stPeople *head, stPeople *FoundNode, char *id)
{
    stPeople *p; //通过p找到最后一个节点
    p = head;
    while (p->next != head) //遍历整个链表
    {
        if (p->next != FoundNode)//忽略节点本身的身份证
        {
            if (strcmp(p->next->id, id) == 0) //判断p->next指向的节点里面的数据域保存的数据是否和number相等
            {
    
                return -1;
            }
        }
        p = p->next; //p往下一个节点移动
    }

    return 0;
}

//修改传入节点的数据
void ModiNode(stPeople *head, stPeople *FoundNode)
{
    char id[20];
    int flag;
    if (head == NULL || FoundNode == NULL)
    {
        return;
    }
    //修改信息
    printf("请输入修改的信息：\n");
    printf("名字：");
    scanf("%s", FoundNode->name);

    printf("性别：");
    scanf("%s", FoundNode->gend);

    //保证id唯一
    printf("身份证：");
    while (1)
    {
        scanf("%s", id);
        flag = CheckId1(head, FoundNode, id);
        if (flag == 0)
        {
            strcpy(FoundNode->id, id); //字符串赋值
            break;
        }

        printf("身份证重复输入，请重新输入！\n");
    }

    printf("年龄：");
    scanf("%d", &(FoundNode->age));
}

//通过查找id修改节点数据
int ModiById(stPeople *head, char *id)
{
    stPeople *p; //通过p找到最后一个节点
    p = head;
    while (p->next != head) //遍历整个链表
    {
        if (strcmp(p->next->id, id) == 0) //判断p->next指向的节点里面的数据域保存的数据是否和number相等
        {
            ModiNode(head, p->next);
            printf("修改后的信息如下：\n");
            printf("姓名：%s\t性别：%s\t身份证：%s\t年龄：%d\n",
                   p->next->name, p->next->gend, p->next->id, p->next->age);
            return 0;
        }
        p = p->next; //p往下一个节点移动
    }

    return -1;
}

//修改数据的入口函数
int modi(stPeople *head)
{

    char ch;
    int flag = 1;
    int FoundNode;
    char id[20];

    while (flag)
    {
        FoundNode = FindOne(head);
        if (FoundNode == 0)
        {
            printf("查询条件不存在，请重新输入！！！\n");
            continue;
        }

        printf("请输入要修改记录的身份证：\n");
        scanf("%s", id);
        //只能通过身份证选择和修改信息，身份证是唯一的。
        ModiById(head, id);

        printf("=================================================================\n");
        printf("退出修改操作请按“1”，否则继续操作\n");
        scanf(" %c", &ch);
        if (ch == '1')
        {
            flag = 0;
        }
    }

    return 0;
}