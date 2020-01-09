/*
 * @Author: your name
 * @Date: 2020-01-04 13:51:35
 * @LastEditTime : 2020-01-09 14:51:27
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \myshare\manager_system_v3\init.c
 */
#include "init.h"

stPeople *init(void)
{
    stPeople *node;
    node = (stPeople *)malloc(sizeof(stPeople));
    if (node == NULL) //若申请失败，malloc函数返回NULL
    {
        printf("节点创建失败！\n");
        return NULL;
    }
    //bzero(node, sizeof(stPeople));//内存空间清零
    memset(node, 0, sizeof(stPeople));//替代bzero
    node->prev = node;
    node->next = node;
    
    return node;
}