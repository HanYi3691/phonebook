#pragma once
#include<iostream>
using namespace std;
//菜单
void ShowMenu();
const int Ma = 1005;
struct person
{
	string Name;
	int Sex=0;//1男，2女
	int Age=0;
	string PhoNum;
	string Add;

};
struct PhoneBook
{
	person PerArr[Ma];
	int Len=0;
	/*PhoneBook(person* P, int nu)
	{
		Len = nu;
		PerArr = P;
	}*/
};
void addPerson(PhoneBook* Pb);//添加联系人
void clearPerson(PhoneBook* Pb);//清空通讯录
void printPb(PhoneBook* Pb);//打印通讯录
void deletePerson(PhoneBook* Pb,string name);//删除指定姓名的联系人
void findPerson(PhoneBook* Pb, string name);//查找指定姓名的联系人
void modifyPerson(PhoneBook* Pb, string name);//修改指定姓名的联系人
int isExist(PhoneBook* Pb, string name);//查找该姓名的人是否存在，存在返回编号，否则是-1；  