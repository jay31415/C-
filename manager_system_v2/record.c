#include "record.h"//头文件


int record(PEOPLE *p)
{
	int i=0;
	for(i=0;i<N;i++)
	{
		printf("请输入第%d人的名字：",i+1);
		scanf("%s",p[i].name);
		
		printf("请输入第%d人的年龄：",i+1);
		scanf("%d",&p[i].age);
		
		printf("请输入第%d人的性别：",i+1);
		scanf("%s",p[i].gend);
		
		printf("请输入第%d人的身份证：",i+1);
		scanf("%d",&p[i].id);
		
		printf("请输入第%d人的身高/cm：",i+1);
		scanf("%d",&p[i].height);
		
		printf("请输入第%d人的体重/kg：",i+1);
		scanf("%d",&p[i].weight);
		
		printf("请输入第%d人的地址：",i+1);
		scanf("%s",p[i].addr);
	}
	printf("\n");
	
	
}