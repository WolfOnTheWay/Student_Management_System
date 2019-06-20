#pragma once
# include <iostream>
# include<string>
# include "StuInfo.h"
# include<stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <vector>
# include <windows.h>
# include<conio.h>
#include<fstream>
# include<iomanip>
# define FileName "D:\\student.txt"

using namespace std;
class Controller
{
public:
	void ShowCopy();//显示版权
	bool Login();//用户登录
	void menu();//主菜单
	void initData();//初始化数据
	void addStuinfo();//添加学生信息
	void showStuinfo(StuInfo stu);//显示单个学生信息
	void SearchStuinfo();//显示多个学生信息
	bool Save(StuInfo stu);//保存到文件
	void ViewInfo();//浏览学生信息
	void UpdateStuinfo();//修改学生信息
	void DeleteStuinfo();//删除学生信息
	bool reWrite();//重新写数文件
};