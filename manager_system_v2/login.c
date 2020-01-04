#include "login.h"

/*输入指定的用户名和密码：登录成功跳转到管理界面，登录失败则返回界面重新输入，输入错误大于3次则结束程序，用一个结构体保存用户名和密码
分普通用户和管理员（可删除用户）
查看和修改普通用户账号和密码的函数
*/
typedef struct usr
{
	char c_username[10];
	char c_password[10];
} USR;

int login()
{
	USR user[2];
	char c_name[10];
	char c_code[10];
	int flag1, flag2;
	int tem;
	int k = 1;

	strcpy(user[0].c_username, "apple");
	strcpy(user[0].c_password, "123456");
	strcpy(user[1].c_username, "book");
	strcpy(user[1].c_password, "123456");

	while (k <= 3)
	{
		printf("请输入登录的用户名：");
		scanf("%s", c_name);
		printf("\n");
		printf("请输入登录的密码：");
		scanf("%s", c_code);

		for (int i = 0; i < 2; i++)
		{
			tem = 0;
			flag1 = strcmp(user[i].c_username, c_name);
			flag2 = strcmp(user[i].c_password, c_code);
			if ((flag1 == 0) && (flag2 == 0))
			{
				printf("登陆成功！！！\n");
				tem = 1;
				return tem;
			}
		}
		k++;
		printf("登陆失败：用户名或者密码不正确，请重新输入登录信息\n");
	}
	printf("登陆失败次数过多，系统自动退出\n");
	return tem;
}