/*
 * @Author: your name
 * @Date: 2020-01-04 11:11:55
 * @LastEditTime : 2020-01-09 15:56:53
 * @LastEditors  : Please set LastEditors
 * @Description: 假定数据域的四个变量存的数据是唯一的
                 注意字符串的比较，必须用函数strcmp（）
 * @FilePath: \myshare\manager_system_v3\show.c
 */
#include "show.h" //头文件

int show(stPeople *head)
{
    stPeople *p;      //通过p找到最后一个节点
    
    p = head;
    while (p->next != head) //如果记录下一个节点的地址不是头结点的地址
    {

        p = p->next; //将下一个节点的地址赋给p,即，p往下一个节点移动
        //将遍历的节点的顺序、地址好人数据打印显示
        printf("姓名：%s\t性别：%s\t身份证：%s\t年龄：%d\n", p->name, p->gend, p->id, p->age);
    } //直到遍历到的最后一个节点的指针域保存了头结点的地址，则循环结束

    return 0;
}

int SearchName(stPeople *head, char *name)
{
    stPeople *p;      //通过p找到最后一个节点
    int i = 0;
    p = head;
    while (p->next != head) //遍历整个链表
    {
        if (strcmp(p->next->name, name) == 0) //判断p->next指向的节点里面的数据域保存的数据是否和number相等
        {

            //相等即找到节点的前一个节点，返回该节点的地址
            //return p->next; 
            i++;
            printf("第%d条记录：\t", i);
            printf("姓名：%s\t性别：%s\t身份证：%s\t年龄：%d\n",\
            p->next->name, p->next->gend, p->next->id, p->next->age);
            
        }
        p = p->next; //p往下一个节点移动
    }
    
    //循环正常结束的时候表示在该链表里面找不到对应的节点,此时p指向最后一个节点
    return i;
}
int SearchGend(stPeople *head, char *gend)
{
    stPeople *p;      //通过p找到最后一个节点
    int i = 0;
    p = head;
    while (p->next != head) //遍历整个链表
    {
        if (strcmp(p->next->gend, gend) == 0) //判断p->next指向的节点里面的数据域保存的数据是否和number相等
        {

            i++;
            printf("第%d条记录：\t", i);
            printf("姓名：%s\t性别：%s\t身份证：%s\t年龄：%d\n",\
            p->next->name, p->next->gend, p->next->id, p->next->age);
            
        }
        p = p->next; //p往下一个节点移动
    }
    
    //循环正常结束的时候表示在该链表里面找不到对应的节点,此时p指向最后一个节点
    return i;
}

int SearchId(stPeople *head, char *id)
{
    stPeople *p;      //通过p找到最后一个节点
    p = head;
    while (p->next != head) //遍历整个链表
    {
        if (strcmp(p->next->id, id) == 0) //判断p->next指向的节点里面的数据域保存的数据是否和number相等
        {

            printf("姓名：%s\t性别：%s\t身份证：%s\t年龄：%d\n",\
            p->next->name, p->next->gend, p->next->id, p->next->age);
            return 1;
        }
        p = p->next; //p往下一个节点移动
    }
    
    return 0;
}

int SearchAge(stPeople *head, unsigned age)
{
    stPeople *p;      //通过p找到最后一个节点
    int i = 0;
    p = head;
    while (p->next != head) //遍历整个链表
    {
        if (p->next->age == age) //判断p->next指向的节点里面的数据域保存的数据是否和number相等
        {

            i++;
            printf("第%d条记录：\t", i);
            printf("姓名：%s\t性别：%s\t身份证：%s\t年龄：%d\n",\
            p->next->name, p->next->gend, p->next->id, p->next->age);
            
        }
        p = p->next; //p往下一个节点移动
    }
    
    return i;
}

//单次查找信息
int FindOne(stPeople *head)
{
    char ch;
    char name[32];
    char gend[8];
    char id[20];
    unsigned age;
    int FoundNode = 0;
    
    printf("=================================================================\n");
    printf("请选择查找方式:\n");
    printf("1-按姓名查找\t2-按性别查找\t3-按身份证查找\t4-按年龄查找\n");
    scanf(" %c", &ch);
    switch (ch)
    {
        case '1':
            printf("请输入要查找的姓名:");
            scanf("%s", name);
            FoundNode = SearchName(head, name);
            break;
        case '2':
            printf("请输入要查找的性别:");
            scanf("%s", gend);
            FoundNode = SearchGend(head, gend);
            break;
        case '3':
            printf("请输入要查找的身份证:");
            scanf("%s", id);
            FoundNode = SearchId(head, id);
            break;
        case '4':
            printf("请输入要查找的年龄:");
            scanf("%d", &age);
            FoundNode = SearchAge(head, age);
            break;
        default:
            printf("没有该选项！！！\n");
            return FoundNode;
    }
    printf("总共找到%d条记录！\n", FoundNode);
    return FoundNode;
}

//实现循环查找
int find(stPeople *head)
{
    int flag = 1;
    char ch;
    int FoundNode;

    while (flag)
    {
        FoundNode = FindOne(head);
        if (FoundNode == 0)
        {
            printf("输入错误或查询条件不存在，请重新输入！！！\n");
        }
        
        printf("=================================================================\n");
        printf("退出查找请按数字“1”，否则继续查找\n");
        scanf(" %c", &ch);
        if (ch == '1')
        {
            flag = 0;
        }
    }

    return 0;
}