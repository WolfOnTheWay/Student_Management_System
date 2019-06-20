# include "StuInfo.h"

StuInfo::StuInfo(char *sno1, char *sname, char *cname, char *sex, int age, char *tel)
	

{
	 setSno(sno1);
	 setSname(sname);
	 setCname(cname);
	 setSex(sex);
	 setAge(age);
	 setTel(tel);
}

void StuInfo::setSno(char *sno)
{
	strcpy_s(this->sno, sno);
}

void StuInfo::setSname(char * sname)
{
	strcpy_s(this->sname, sname);
}
void StuInfo::setCname(char * cname)
{
	strcpy_s(this->cname, cname);
}
void StuInfo::setSex(char *sex)
{
	strcpy_s(this->sex, sex);
}
void StuInfo::setAge(int age)
{
	this->age = age;
}
void StuInfo::setTel(char *tel)
{
	strcpy_s(this->tel, tel);
}


void StuInfo::Show()
{
	cout.flags(ios::internal); //Á½¶Ë¶ÔÆë
	cout<<setw(30)<<"\n\t" << sno <<"\t"<<sname<<"\t"<<cname<<"\t"<<sex<<"\t"<<age<<"\t"<<"\t"<<tel<< endl;
}
char* StuInfo::getSno()
{
	return sno;
}
