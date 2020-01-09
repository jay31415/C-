/*
 * @Author: your name
 * @Date: 2020-01-07 18:45:58
 * @LastEditTime : 2020-01-07 19:45:38
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \myshare\manager_system_v4\inc\sign.h
 */
#ifndef __SIGN_H__
#define __SIGN_H__


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "main.h"

extern int sign(stUsr *UsrHead);
extern int login(stUsr *UsrHead);
extern stUsr *InitUsr();


#endif