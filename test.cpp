# include <iostream>
using namespace std;
# include <stdlib.h>
# include <assert.h>
# include"Account.h"
#include"StuInfo.h"
# include "Controller.h"
int main()
{
	Controller col;
	if (col.Login())

	{
		col.menu();
	}
	else
	{
		cout << "您没有访问权限，系统即将退出！！！！" << endl;
		exit(0);
	}

	system("pause");
	return 0;

}