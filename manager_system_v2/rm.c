#include "rm.h"//头文件


int rm(PEOPLE *p)
{
		
	int num;
	char name[20];
	
	printf("请输入被删除人的名字:");
	scanf("%s",name);
	
	num = searchName(p,name);
	if(num==-1)
	{
		printf("查无此人\n");
		return -1;
	}
	else
	{
		printf("被删除人的信息如下：\n姓名：%s\t性别：%s\t身份证：%d\t身高/cm：%d\t体重/kg：%d\t年龄：%d\t地址：%s\n",p[num].name,p[num].gend,p[num].id,p[num].height,p[num].weight,p[num].age,p[num].addr);
		
		strcpy((p[num].name),"\0");
		strcpy((p[num].gend),"\0");
		p[num].id=0;
		p[num].height=0;
		p[num].weight=0;
		p[num].age=0;
		strcpy((p[num].addr),"\0");

		printf("信息删除成功！！！\n");
		printf("删除后的信息如下：\n姓名：%s\t性别：%s\t身份证：%d\t身高/cm：%d\t体重/kg：%d\t年龄：%d\t地址：%s\n",p[num].name,p[num].gend,p[num].id,p[num].height,p[num].weight,p[num].age,p[num].addr);
	}
	
	

		

	
}