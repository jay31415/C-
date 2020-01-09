/*
 * @Author: your name
 * @Date: 2020-01-04 11:11:55
 * @LastEditTime : 2020-01-09 15:38:39
 * @LastEditors  : Please set LastEditors
 * @Description: 从链表尾部插入带数据节点，身份证id唯一
 * @FilePath: \myshare\manager_system_v3\add.c
 */
#include "add.h"


//检查id是否唯一
int CheckId(stPeople *head, char *id)
{
    stPeople *p; //通过p找到最后一个节点
    p = head;
    while (p->next != head) //遍历整个链表
    {
        if (strcmp(p->next->id, id) == 0) 
        {

            return 0;
        }
        p = p->next; //p往下一个节点移动
    }

    return 1;
}

//输入信息函数入口
int add(stPeople *head)
{
    int i;
    stPeople *p;
    stPeople *new;
    char id[20];
    int flag;

    for (i = 0; i < N; i++)
    {
        new = init();
        if (head == NULL || new == NULL)
        {
            return -1;
        }
        printf("请输入第%d个人的信息：", i + 1);
        printf("名字：");
        scanf("%s", new->name);

        printf("性别：");
        scanf("%s", new->gend);

        //保证id唯一
        printf("身份证：");
        while (1)
        {
            scanf("%s", id);
            flag = CheckId(head, id);
            if(flag == 1)
            {
                strcpy(new->id, id);//字符串赋值
                break;
            }
            else
            {
                printf("身份证重复输入，请重新输入！\n");
                continue;
            }
        }
        
        printf("年龄：");
        scanf("%d", &(new->age));

        p = head->prev; //p指向尾节点的地址

        p->next = new;
        new->prev = p;
        new->next = head;
        head->prev = new;

    }

    return 0;
}