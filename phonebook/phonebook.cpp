#include<iostream>
#include<string>
#include "headfun.h"
using namespace std;

 int main()
{
	//person *a=NULL;
	PhoneBook Pb = { {},0 };
	int order;
	while (1)
	{		
		ShowMenu();
		cin >> order;

		switch (order)
		{
			case 1://添加联系人
			{
				addPerson(&Pb);
				break;
			}
			case 2://显示通讯录中全部联系人
			{
				printPb(&Pb);
				break;
			}
			case 3://删除联系人
			{
				string name;
				cout << "请输入你要删除的联系人的姓名："<<endl;
				cin >> name;
				deletePerson(&Pb, name);
				break;
			}
			case 4://查找联系人
			{
				string name;
				cout << "请输入你要查找的联系人的姓名：" << endl;
				cin >> name;
				findPerson(&Pb, name);
				break;
			}
			case 5://修改联系人
			{
				string name;
				cout << "请输入你要修改的联系人的姓名：" << endl;
				cin >> name;
				modifyPerson(&Pb, name);
				break;
			}
			case 6://清空通讯录
			{
				clearPerson(&Pb);
				break;
			}
			case 0://退出通讯录
			{
				cout << "系统正常退出" << endl;
				return 0;
				break;
			}
			default://输入异常
			{
				cout << "您的输入异常，请重新输入~" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
	}
	system("pause");
	return 0;
}