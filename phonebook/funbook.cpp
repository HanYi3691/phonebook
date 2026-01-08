#include "headfun.h"
void ShowMenu()
{
	cout << R"(1.添加联系人
2.显示通讯录中全部联系人
3.删除联系人
4.查找联系人
5.修改联系人
6.清空通讯录
0.退出通讯录)" << endl;
}
void addPerson(PhoneBook* Pb)
{
	if (Pb->Len >= Ma)
	{
		cout << "通讯录储存已满，无法再次添加!" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入联系人姓名" << endl;
		cin >> name;
		string num;
		cout << "请输入联系人电话号码" << endl;
		cin >> num;
		int sex;
		cout << "请输入联系人性别（1--男 2--女,输入0视为未知）" << endl;
		cin >> sex;
		int age;
		cout << "请输入联系人年龄（输入0视为未知）" << endl;
		cin >> age;
		string add;
		cout << "请输入联系人住址（输入0视为未知）" << endl;
		cin >> add;
		Pb->PerArr[Pb->Len++] = { name,sex,age,num,add };
		cout << "联系人添加成功"<<endl;
		system("pause");
		system("cls");
	}
}
void printPb(PhoneBook* pb)
{
	if (pb->Len)
	{
		for (int i = 0; i < pb->Len; i++)
		{
			cout << "姓名：" << pb->PerArr[i].Name << '\t';
			cout << "电话号码：" << pb->PerArr[i].PhoNum << '\t';
			if (pb->PerArr[i].Sex)
			{
				cout << "性别："<< (pb->PerArr[i].Sex == 1 ? "男" : "女")<<'\t';
			}
			else
			{
				cout << "性别：未知" << '\t';
			}
			if (pb->PerArr[i].Age)
			{
				cout << "年龄：" << pb->PerArr[i].Sex << '\t';
			}
			else
			{
				cout << "年龄：未知" << '\t';
			}
			if (pb->PerArr[i].Add!="0")
			{
				cout << "住址：" << pb->PerArr[i].Add;
			}
			else
			{
				cout << "住址：未知";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "当前通讯录是空的~"<<endl;
	}
	system("pause");
	system("cls");
}
int isExist(PhoneBook* Pb, string name)
{
	for (int i = 0; i < Pb->Len; i++)
	{
		if (Pb->PerArr[i].Name == name)
		{
			return i;
		}
	}
	return -1;
}
void deletePerson(PhoneBook* Pb, string name)
{
	int e = isExist(Pb, name);
	if (e == -1)
	{
		cout << "通讯录中没有这个人~"<<endl;
	}
	else
	{
		for (int i = e; i < Pb->Len; i++)
		{
			Pb->PerArr[i] = Pb->PerArr[i + 1];
		}
		Pb->Len--;
		cout << "成功删除" << endl;
	}
	system("pause");
	system("cls");
}
void findPerson(PhoneBook* pb, string name)
{
	int e = isExist(pb, name);
	if (e == -1)
	{
		cout << "通讯录中没有这个人~"<<endl;
	}
	else
	{
		cout << "姓名：" << pb->PerArr[e].Name << '\t';
		cout << "电话号码：" << pb->PerArr[e].PhoNum << '\t';
		if (pb->PerArr[e].Sex)
		{
			cout << "性别：" << (pb->PerArr[e].Sex == 1 ? "男" : "女") << '\t';
		}
		else
		{
			cout << "性别：未知" << '\t';
		}
		if (pb->PerArr[e].Age)
		{
			cout << "年龄：" << pb->PerArr[e].Sex << '\t';
		}
		else
		{
			cout << "年龄：未知" << '\t';
		}
		if (pb->PerArr[e].Add != "0")
		{
			cout << "住址：" << pb->PerArr[e].Add;
		}
		else
		{
			cout << "住址：未知";
		}
		cout << endl;
	}
	system("pause");
	system("cls");
}
void modifyPerson(PhoneBook* pb, string name)
{
	int e = isExist(pb, name);
	if (e == -1)
	{
		cout << "通讯录中没有这个人~" << endl;
	}
	else
	{
		string name;
		cout << "请输入联系人姓名" << endl;
		cin >> name;
		string num;
		cout << "请输入联系人电话号码" << endl;
		cin >> num;
		int sex;
		cout << "请输入联系人性别（1--男 2--女,输入0视为未知）" << endl;
		cin >> sex;
		int age;
		cout << "请输入联系人年龄（输入0视为未知）" << endl;
		cin >> age;
		string add;
		cout << "请输入联系人住址（输入0视为未知）" << endl;
		cin >> add;
		pb->PerArr[e] = { name,sex,age,num,add };
		cout << "联系人信息修改成功" << endl;
	}
	system("pause");
	system("cls");
}
void clearPerson(PhoneBook* Pb)
{
	cout << "您确定要清空通讯录吗？（1是，0否）"<<endl;
	bool yes;
	cin >> yes;
	if (yes)
	{
		Pb->Len = 0;
		cout << "通讯录清空完成" << endl;
	}
	else
		cout << "清空终止" << endl;
	system("pause");
	system("cls");
}