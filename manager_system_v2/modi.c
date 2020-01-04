#include "modi.h"//头文件


int modi(PEOPLE *p)
{
	
	int num;
	char name[20];
	
	printf("请输入被修改人的名字:");
	scanf("%s",name);
	
	num = searchName(p,name);
	if(num==-1)
	{
		printf("查无此人\n");
		return -1;
	}
	else
	{
		printf("被修改人的信息如下：\n姓名：%s\t性别：%s\t身份证：%d\t身高/cm：%d\t体重/kg：%d\t年龄：%d\t地址：%s\n",p[num].name,p[num].gend,p[num].id,p[num].height,p[num].weight,p[num].age,p[num].addr);
		
		printf("请输入修改的名字：");
		scanf("%s",p[num].name);
		
		printf("请输入修改的年龄：");
		scanf("%d",&p[num].age);
		
		printf("请输入修改的性别：");
		scanf("%s",p[num].gend);
		
		printf("请输入修改的身份证：");
		scanf("%d",&p[num].id);
		
		printf("请输入修改的身高：");
		scanf("%d",&p[num].height);
		
		printf("请输入修改的体重：");
		scanf("%d",&p[num].weight);
		
		printf("请输入修改的地址：");
		scanf("%s",p[num].addr);
	}
	
	printf("修改信息完成！\n");
	
	
}