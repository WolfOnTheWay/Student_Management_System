#pragma once
# include <iostream>
# include<string>
using namespace std;
class Account
{
private:
	string count;
	string password;
public:
	Account();
	Account(string newCount, string newPw);
	void Show();
	void Login(string log_count,string log_pw);
	


};