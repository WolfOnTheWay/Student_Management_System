# include "Account.h"


Account::Account()
{
	count = "new person";
	password = "123";
}
Account::Account(string newCount, string newPw)
{
	count = newCount;
	password = newPw;
}
void inline Account::Show()
{
	cout << count << "\t" << password << endl;
}
void Account::Login(string log_count, string log_pw)
{

}
