/*
 * @Author: your name
 * @Date: 2020-01-04 11:11:55
 * @LastEditTime : 2020-01-07 19:37:51
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \myshare\manager_system_v3\inc\main.h
 */
#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//人员数量
#define N 2

typedef struct people
{
    char name[32];
    char gend[8];
    char id[20];
    unsigned age;
    struct people *prev;
    struct people *next;
} stPeople;

//用于用户名和密码存储的结构体
typedef struct usr
{
    char username[10];
    char password[10];
    struct usr *prev;
    struct usr *next;
    
} stUsr;

#endif