/*
 * @Author: Shelby
 * @Date: 2020-01-04 11:11:55
 * @LastEditTime : 2020-01-09 15:37:39
 * @LastEditors  : Please set LastEditors
 * @Description: main函数
 * @FilePath: \myshare\manager_system_v3\main.c
 */
#include "main.h"
#include "add.h"
#include "show.h"
#include "rm.h"
#include "modi.h"
#include "init.h"
#include "sign.h"

int start(int login_flag);

int main(void)
{

    char index; //用于注册和登录
    int login_flag;
    int sign_flag;
    int flag = 1;
    stUsr *UsrHead;//用于注册信息记录的链表头结点

    UsrHead = InitUsr(); //头节点初始化
    if (UsrHead == NULL)
    {
        return 0;
    }

    printf("***************欢迎来到信息管理系统***************\n");
    while (flag)
    {
        printf("请输入你要执行的操作：\n1-注册\t2-登录\t3-退出\n");
        scanf(" %c", &index); // 百分号前面加空格，避免下一次输入，自动读取了换行符
        switch (index)
        {
        case '1':
        {
            /* 注册 ,注册成功需跳转到登录界面*/
            sign_flag = sign(UsrHead);
            if (sign_flag == 0)
            {
                printf("注册失败，请重新操作！！！\n");
            }
            break;
        }

        case '2':
            /* 登录 :login_flag的 0 表示登录失败，1 表示登陆成功*/
            login_flag = login(UsrHead);
            if (login_flag == 0)
            {
                continue;
            }
            start(login_flag);
            break;
        case '3':
            //直接退出系统
            return 0;

        default:
            printf("输入错误，请重新选择！！！\n");
            break;
        }
    }
    return 1;
}

int start(int login_flag)
{
    stPeople *head;//用于信息记录的链表头结点
    char ch;

    head = init();
    if (head == NULL)
    {
        printf("头结点申请内存空间失败！！！\n");
        return 0;
    }

    while (login_flag)
    {
        printf("请输入你要执行的操作：\n");
        printf("1-录入信息\t2-查看信息\t3-查找信息\t4-修改信息\t5-删除信息\t6-返回登录界面\n");
        scanf(" %c", &ch);
        printf("\n");

        switch (ch)
        {
        case '1':
            //信息录入
            add(head);
            break;
        case '2':
            //查询所有信息
            show(head);
            break;
        case '3':
            //查找
            find(head);
            break;
        case '4':
            //修改信息
            modi(head);
            break;
        case '5':
            //删除信息
            rm(head);
            break;
        case '6':
            login_flag = 0;
            break;

        default:
            printf("输入错误，请重新选择！！！\n");
            break;
        }
    }

    return 1;
}
