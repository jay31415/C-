/*
 * @Author: your name
 * @Date: 2020-01-04 11:11:55
 * @LastEditTime : 2020-01-09 16:11:53
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \myshare\manager_system_v3\login.c
 */
#include "sign.h"

/*输入指定的用户名和密码：登录成功跳转到管理界面，登录失败则返回界面重新输入，输入错误大于3次则结束程序，用一个结构体保存用户名和密码
分普通用户和管理员（可删除用户）
查看和修改普通用户账号和密码的函数
*/

//结构体初始化
stUsr *InitUsr(void)
{
    stUsr *p;
    p = (stUsr *)malloc(sizeof(stUsr));
    if (p == NULL) //若申请失败，malloc函数返回NULL
    {
        printf("节点创建失败！\n");
        return NULL;
    }
    //bzero(node, sizeof(stPeople));//内存空间清零
    memset(p, 0, sizeof(stUsr)); //替代bzero
    p->prev = p;
    p->next = p;

    return p;
}

//检查用户名是不是唯一
int CheckUsername(stUsr *UsrHead, char *username)
{
    stUsr *p; //通过p找到最后一个节点
    p = UsrHead;
    while (p->next != UsrHead) //遍历整个链表
    {
        if (strcmp(p->next->username, username) == 0) //判断p->next指向的节点里面的数据域保存的数据是否和number相等
        {

            return 0;
        }
        p = p->next; //p往下一个节点移动
    }

    return 1;
}

//在链表尾部新增用户节点，只增加一个
int AddUsr(stUsr *UsrHead)
{

    stUsr *p;
    stUsr *new;
    char username[10];
    int flag;

    new = InitUsr();
    if (UsrHead == NULL || new == NULL)
    {
        return 0;
    }

    //保证id唯一
    printf("请输入用户名：");
    while (1)
    {
        scanf("%s", username);
        flag = CheckUsername(UsrHead, username);
        if (flag == 1)
        {
            strcpy(new->username, username); //字符串赋值
            break;
        }
        else
        {
            printf("该用户已存在，请重新输入！\n");
            continue;
        }
    }

    printf("密码：");
    scanf("%s", new->password);
    
    printf("用户名：%s\t密码：%s\n", new->username, new->password);
    printf("账号注册成功,页面跳转回首页！！！\n");

    p = UsrHead->prev; //p指向尾节点的地址

    p->next = new;
    new->prev = p;
    new->next = UsrHead;
    UsrHead->prev = new;

    return 1;
}


int SearchUsr(stUsr *UsrHead, char *username, char *password)
{
    stUsr *p;
    
    p = UsrHead;
    while (p->next != UsrHead) //遍历整个链表
    {
        if (strcmp(p->next->username, username) == 0) 
        {
            if (strcmp(p->next->password, password) == 0)
            {
                return 1;
            }
        }
        p = p->next; //p往下一个节点移动
    }
    
    return 0;
}


//注册函数入口
int sign(stUsr *UsrHead)
{
    int flag;

    flag = AddUsr(UsrHead);
    if (flag == 0)
    {
        return 0;
    }

    return 1;
}

//登录函数入口
int login(stUsr *UsrHead)
{
    char username[10];
    char password[10];
    char rootname[10] = {"root"};
    char rootpassword[10] = {"123456"};
    int flag;
    unsigned i = 1;

    while (i <= 3)
    {

        printf("请输入登录信息：\n");
        printf("用户名：");
        scanf("%s", username);
        printf("密码：");
        scanf("%s", password);
        printf("==============================================\n");
        
        //超级用户登录
        if (strcmp(rootname, username) == 0) 
        {
            if (strcmp(rootpassword, password) == 0)
            {
                printf("登录成功！！！\n");
                return 1;
            }
        }

        flag = SearchUsr(UsrHead, username, password);
        if (flag == 1)
        {
            printf("登录成功！！！\n");
            return 1;
        }
        i++;
        printf("用户名或者密码不正确，请重新输入！！！\n");
    }
    printf("登陆失败次数过多，系统自动退出\n");

    return 0;
}