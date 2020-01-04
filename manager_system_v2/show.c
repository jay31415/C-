#include "show.h"//头文件


int show(PEOPLE *p)
{
	int i=0;
	for(i=0;i<N;i++)
	{
		printf("姓名：%s\t性别：%s\t身份证：%d\t身高/cm：%d\t体重/kg：%d\t年龄：%d\t地址：%s\n",p[i].name,p[i].gend,p[i].id,p[i].height,p[i].weight,p[i].age,p[i].addr);
	}
	printf("\n");
	
}

int display(PEOPLE *p)
{
	int num;
	char name[20];
	
	printf("请输入你要查看的人的名字:");
	scanf("%s",name);
	
	num = searchName(p,name);
	if(num==-1)
	{
		printf("查无此人\n");
		return -1;
	}
	else
	{
		printf("姓名：%s\t性别：%s\t身份证：%d\t身高/cm：%d\t体重/kg：%d\t年龄：%d\t地址：%s\n",p[num].name,p[num].gend,p[num].id,p[num].height,p[num].weight,p[num].age,p[num].addr);
	}
}

int searchName(PEOPLE *p,char *Name)
{

	int i;
	int tem;
	for(i=0;i<N;i++)
	{
		tem = -1;
		if(strcmp((p[i].name),Name)==0)
		{
			tem = i;
			break;
		}

	}
	printf("\n");
	return tem;
	
	
}