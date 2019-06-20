# include"Controller.h"
vector<StuInfo>stuinfos;

void Controller::ShowCopy()//显示版权
{
	cout << "\n\n\t*******************欢迎使学生系统******************";
	cout << "\n\n\t******************WolfOnTheWay所有******************";

}


bool Controller::Login()//用户登录
{
	system("cls");
	int index = 0;
	int count = 0;
	char account[20];
	char pw[20];
	char ch;
	ShowCopy();
	do 
	{
		index = 0;
		count++;
		cout << "\n\n\t请输入您的账号：";
		cin.getline(account,20, '\n');
		cin.clear();
		cout << "\n\n\t请输入您的密码：";

		//obtain password
	
		while ((ch =getchar()) != '\n')//13为回车的键值
		{	
			if (ch == 8)//8为撤销的键值
			{
				if (index <= 0)
				{
					index = 0;
				}
				else 
				{
					cout << "\b\b";
					--index;
				}
			}
			else
			{
				pw[index++] = ch;
				cout << '*';
			}
		
		}
		pw[index] = '\0';


		//判断用户输入的账号和密码是否正确
		if (strcmp(account,"yc")==0 && (strcmp(pw, "123") == 0))
		{
			initData();//数据初始化；

			return true;
		}
		else
		{
			if (count == 3)
			{
				cout << "\n\n对不起，您无访问权限，系统将自动退出";
				exit(0);

			}
			else
			{
				cout << "\n\n账号或密码错误，请确认后重新输入<您还有" << (3 - count) << "次输入机会，回车后继续>!!!" << endl;
			}
		}


	} while (count > 0);
	return false;

}	


void Controller::menu()//主菜单
{
	int option = 0, count = 0;
	
	while (count<1000)
	{
		system("cls");
		count = 0;
		ShowCopy();
		cout << "\n\n\t*******************主菜单******************";
		cout << "\n\n\t******************1.浏览学生信息******************";
		cout << "\n\n\t******************2.查询学生信息******************";
		cout << "\n\n\t******************3.添加学生信息******************";
		cout << "\n\n\t******************4.修改学生信息******************";
		cout << "\n\n\t******************5.删除学生信息******************";
		cout << "\n\n\t******************6.推出系统******************";
		do
		{
			if (count != 0)
			{
				cout << "\n\n对不起，没有该选项，请重新选择(1-6)";
			}
			else
			{
				cout << "\n\n请选择你的选项（1-6）：";
			}
			cin >> option;
			count++;
		} while (option <= 0 || option > 6);
		switch (option)
		{
		case 1:ViewInfo();
			break;
		case 2:SearchStuinfo();
			break;
		case 3:addStuinfo();
			break;
		case 4:UpdateStuinfo();
			break;
		case 5: DeleteStuinfo();
			break;
		case 6:exit(0);
			break;
		}
	}

}


void Controller::initData()//初始化数据
{
	
	FILE *file = NULL;
	fopen_s(&file, FileName, "rb");
	assert(file != NULL);
	StuInfo stu;
	fread(&stu, 1, sizeof(StuInfo), file);
	if (!fread(&stu, 1, sizeof(StuInfo), file))
	{
		fclose(file);
		return;
	}
	stuinfos.push_back(stu);//将所读到的信息压入容器之中。

	fclose(file);

}



void Controller::addStuinfo()//添加学生信息
{
	system("cls");
	char sno[20] ="";//学号
	char sname[20]="";//姓名
	char cname[20]="";//班级
	char sex[4]="";//性别
	int age = 0;
	char tel[15]="";//电话

	cout << "\n\n\t******************添加学生信息******************";
	cout << "\n\n\t***************请输入以下学生信息******************\n";
	cout << "请输入学生学号：";
	cin >> sno;
	cout << endl;
	cout << "请输入学生姓名：";
	cin >> sname;
	cout << endl;
	cout << "请输入学生班级：";
	cin >> cname;
	cout << endl;
	cout << "请输入学生性别：";
	cin >> sex;
	cout << endl;
	cout << "请输入学生年龄：";
	cin >> age;
	cout << endl;
	cout << "请输入学生电话：";
	cin >> tel;
	cout << endl;
	StuInfo stu(sno, sname, cname, sex, age, tel);
	printf("%s", stu.getSno());
	cout << "您要添加的学生信息如下,请确认\n";
	showStuinfo(stu);
	int result = MessageBox(NULL,"是否确认添加该学生信息","学生信息添加",MB_OKCANCEL|MB_ICONEXCLAMATION);
	if (result = IDOK)
	{
		if (Save(stu))
		{
			stuinfos.push_back(stu);
			
			cout << "添加成功"<<endl;
		}
		else
		{
			cout << "添加失败"<<endl;
		}
	}
	cout<<"按回车返回"<<endl;
}


void Controller::showStuinfo(StuInfo stu)//显示单个学生信息
{
	cout.flags(ios::internal); //两端对齐
	cout << setw(30) << "\n\t学号" << "\t 姓名" << "\t   班级" << "\t       性别" << "\t年龄" << "\t    电话" << endl;
	stu.Show();

}


void Controller::SearchStuinfo()//显示多个学生信息
{
	system("cls");
	ShowCopy();
	cout << "\n\n\t***************查询学生信息******************\n";
	if (stuinfos.size() == 0)
	{
		cout << "暂无学生信息" << endl;
	}
	else
	{
		char sno[20];
		cout << "\n\n\t请输入你要查询的学号：";
		cin >> sno;
		cout << setw(30) << "\n\t学号" << "\t 姓名" << "\t   班级" << "\t       性别" << "\t年龄" << "\t    电话" << endl;


		int count = 0;
		int length = strlen(sno);
		int temp = 0, j = 0;
		char arr[20];
		for (int i = 0, len = stuinfos.size(); i < len; ++i) 
		{
			strcpy_s(arr, stuinfos[i].getSno());
			temp = strlen(arr);
			length = length > temp ? temp : length;//防越界处理
			for (j = 0; j < length; ++j)
			{
				if (arr[j] != (stuinfos[i].getSno())[j])
				{
					break;
				}
			}
			if (j >= length)
			{
				count++;
				stuinfos[i].Show();

			}
		}
		if (count > 0)
		{
			cout << "\n\n\t**********共有" << count << "个满足条件*********"<<endl;
		}
		else
		{
			cout << "\n没有要查找的学生信息" << endl;
		}
		system("pause");
		
	}
}

bool Controller::Save(StuInfo stu)//保存到文件
{
	fstream out(FileName, ios::out | ios::app | ios::binary);
	if (out.is_open())
	{
		out.write((char*)&stu, sizeof(StuInfo));
		out.close();
		return true;
	}

	return true;
}



void Controller::ViewInfo()//浏览学生信息
{
	system("cls");
	
	
	ShowCopy();
	cout << "\n\n\t******************浏览学生信息******************";
	cout <<setw(20)<< "\n\t学号" << "\t 姓名" << "\t   班级" << "\t      性别" << "\t年龄" << "\t    电话" << endl;
	for (int i = 0; i < stuinfos.size(); ++i)
	{
		stuinfos[i].Show();
	}
	system("pause");

}


void Controller::UpdateStuinfo()//修改学生信息
{
	system("cls");
	ShowCopy();
	cout << "\n\n\t***************修改学生信息******************\n";
	if (stuinfos.empty())
	{
		cout << "暂无学生信息" << endl;
	}
	else
	{
		char sno[20];
		cout << "\n\n\t请输入你要修改的学生的学号：";
		cin >> sno;
		int i, len = stuinfos.size();
		for (i = 0; i < len; ++i)
		{
			if (strcmp(sno, stuinfos[i].getSno()) == 0)
			{
				cout << "您要修改的学生信息如下：" << endl;
				cout << setw(30) << "\n\t学号" << "\t 姓名" << "\t   班级" << "\t       性别" << "\t年龄" << "\t    电话" << endl;
				stuinfos[i].Show();
				break;

			}
		}
		if (i >= len) 
		{
			cout << "对不起，您没有需要修改的学生信息。" << endl;
		}
		else
		{
			char sname[20] = "";//姓名
			char cname[20] = "";//班级
			char sex[4] = "";//性别
			int age = 0;
			char tel[15] = "";//电话


			cout << "请输入学生姓名：";
			cin >> sname;
			cout << endl;
			cout << "请输入学生班级：";
			cin >> cname;
			cout << endl;
			cout << "请输入学生性别：";
			cin >> sex;
			cout << endl;
			cout << "请输入学生年龄：";
			cin >> age;
			cout << endl;
			cout << "请输入学生电话：";
			cin >> tel;
			cout << endl;
			int result = MessageBox(NULL, "确定修改此学生的信息？", "学生信息修改", MB_OKCANCEL | MB_ICONEXCLAMATION);
			if (result == IDOK)
			{
				stuinfos[i].setCname(sname);
				stuinfos[i].setCname(cname);
				stuinfos[i].setSex(sex);
				stuinfos[i].setAge(age);
				stuinfos[i].setTel(tel);
				if(reWrite())
				{
					cout << "信息修改成功" << endl;
				}
				else
				{
					cout << "信息修改失败" << endl;
				}

			}

		}

	}
	system("pause");

}



void Controller::DeleteStuinfo()//删除学生信息
{

	system("cls");
	ShowCopy();
	cout << "\n\n\t***************删除学生信息******************\n";
	if (stuinfos.empty())
	{
		cout << "暂无学生信息" << endl;
	}
	else
	{
		char sno[20];
		cout << "\n\n\t请输入需要删除学生的学号：" << endl;
		cin >> sno;
		int i = 0, len = stuinfos.size();
		for ( ; i < len; ++i)
		{
			if (strcmp(sno, stuinfos[i].getSno()) == 0)
			{
				cout << setw(30) << "\n\t学号" << "\t 姓名" << "\t   班级" << "\t       性别" << "\t年龄" << "\t    电话" << endl;
				stuinfos[i].Show();
				break;
			}
		}
		if (i >= len)
		{

			cout << "没有需要删除的学生信息" << endl;
		}
		else
		{
			stuinfos.erase(stuinfos.begin() + i);
			int result = MessageBox(NULL, "确定删除此学生的信息？", "学生信息删除", MB_OKCANCEL | MB_ICONEXCLAMATION);
			if (result == IDOK)
			{
				if (reWrite())
				{
					cout << "学生信息删除成功" << endl;
				}
				else
				{
					cout << "学生信息删除失败" << endl;
				}

			}

		}
		
	}
	system("pause");
}


bool Controller::reWrite()//重新写数文件
{

	int len = stuinfos.size();
	if (len <= 0)
	{
		fstream out(FileName, ios::out | ios::trunc);
		out.close();
	}
	else
	{

		fstream out(FileName, ios::out | ios::binary);
		if (out.is_open())
		{
			for (int i = 0; i < stuinfos.size(); ++i)
			{
				out.write((char*)&stuinfos[i], sizeof(StuInfo));
			}
			out.close();
			return true;
		}
		else
		{
			return false;
		}

	}
	return false;

}