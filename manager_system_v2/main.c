#include "main.h"
#include "record.h"
#include "show.h"
#include "rm.h"
#include "modi.h"
#include "login.h"

//还需要设计一个功能选择函数，用1,2,3分别来对应不同功能来选择，用switch--case；系统登录（注册和登录）；注销和退出系统；全部都是死循环

int main()
{
	PEOPLE People[N];
	int ch;
	int index; //用于注册和登录
	int login_flag, sign_flag;

	printf("***************欢迎来到信息管理系统***************\n");
	printf("请输入你要执行的操作：\n1-注册\t2-登录\t3-退出\n");
	scanf("%d", &index);
	printf("\n");
	switch (index)
	{
	case 1:
	{
		/* 注册 。注册成功需跳转到登录界面*/
		// sign_flag = sign();
		// if (sign_flag)
		// {
		// 	login_flag = login();
		// 	break;
		// }
		

		break;
	}

	case 2:
		/* 登录 */
		login_flag = login();
		break;
	case 3:
		/* code */
		login_flag = 0;
		break;

	default:
		break;
	}

	while (login_flag)
	{
		printf("请输入你要执行的操作：\n1-录入信息\t2-查看信息\t3-显示信息\n4-修改信息\t5-删除信息\t6-退出\n");
		scanf("%d", &ch);
		printf("\n");

		switch (ch)
		{
		case 1:
			//信息录入
			record(People);
			break;
		case 2:
			//查询所有信息
			show(People);
			break;
		case 3:
			//根据姓名查询
			display(People);
			break;
		case 4:
			//根据修改人的姓名修改信息
			modi(People);
			break;
		case 5:
			////根据修改人的姓名删除信息
			rm(People);
			break;
		case 6:
			login_flag = 0;
			break;
		}
	}

	return 0;
}
