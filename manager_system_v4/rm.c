/*
 * @Author: your name
 * @Date: 2020-01-04 11:11:55
 * @LastEditTime : 2020-01-09 15:28:54
 * @LastEditors  : Please set LastEditors
 * @Description: 先查找，后删除
 * @FilePath: \myshare\manager_system_v3\rm.c
 */
#include "rm.h" //头文件


void DelNode(stPeople *FoundNode)
{
    if (FoundNode == NULL)
    {
        return;
    }
    FoundNode->next->prev = FoundNode->prev;
    FoundNode->prev->next = FoundNode->next;
    FoundNode->next = FoundNode;
    FoundNode->prev = FoundNode;
    free(FoundNode);
}

//通过查找身份证id来删除节点
int RmById(stPeople *head, char *id)
{
    stPeople *p;      //通过p找到最后一个节点
    p = head;
    while (p->next != head) //遍历整个链表
    {
        if (strcmp(p->next->id, id) == 0) //判断p->next指向的节点里面的数据域保存的数据是否和number相等
        {
            DelNode(p->next);
            return 0;
        }
        p = p->next; //p往下一个节点移动
    }
    
    return -1;
}

//删除节点的入口函数
int rm(stPeople *head)
{
    char ch;
    char id[20];
    int flag = 1;
    int FoundNode;

    while (flag)
    {
        FoundNode = FindOne(head);
        if (FoundNode == 0)
        {
            printf("输入错误或查询条件不存在，请重新输入！！！\n");
            continue;
        }
        printf("请输入要删除记录的身份证：\n");
        scanf("%s", id);
        //只能通过身份证选择和删除信息，身份证是唯一的。
        RmById(head, id);
        
        printf("===============================删除完成==================================\n");
        printf("退出删除操作请按数字“1”，否则继续操作\n");
        scanf(" %c", &ch);
        if (ch == '1')
        {
            flag = 0;
        }
    }
    return 0;
}