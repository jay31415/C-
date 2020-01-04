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
	char gend[4];
	int id;
	int height;
	int weight;
	int age;
	char addr[100];
} PEOPLE;

#endif