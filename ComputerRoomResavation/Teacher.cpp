#include "Teacher.h"
#include"Reserve.h"
#include<vector>

void Teacher::interface()
{
	cout << "机房预约系统" << endl;
	cout << "老师界面" << endl;
	cout << "1.查看所有预约" << endl;
	cout << "2.审核预约" << endl;
	cout << "3.退出" << endl;
	cout << "请输入您的选择：" << endl;
}

Teacher::Teacher(string id, string name, string pwd)
{
	Id = id;
	Name = name;
	Pwd = pwd;

}

void Teacher::showAllReserve()
{

	Reserve r;

	cout << "所有预约为：" << endl;

	for (map<int, map<string, string>>::iterator it = r.data.begin(); it != r.data.end(); it++)
	{
		cout << it->first << ":" << endl;

		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
		{
			cout << mit->first << ":" << mit->second << " ";
		}

		cout << endl;
	}

	system("pause");
	system("cls");
}

void Teacher::reviewReserve()
{
	Reserve r;

	cout << "所有预约如下所示：" << endl;

	vector<int> v;

	for (map<int, map<string, string>>::iterator it = r.data.begin(); it != r.data.end(); it++)
	{
		if (it->second["status"] == "1")
		{
			cout << v.size() << endl;
			v.push_back(it->first);
			
			for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
			{
				cout << mit->first << ":" << mit->second << " ";
			}

			cout << endl;
		}

	}

	cout << "请输入要审核的预约序号：" << endl;

	int choice;
	cin >> choice;

	if (choice > v.size()||choice<0)
	{
		cout << "输入错误，请重新输入！" << endl;
	}
	
	cout << "请输入选项：1.审核成功 2.审核失败 3. 退出审核" << endl;

	int choice2;
	cin >> choice2;

	switch (choice2)
	{
	case 1:
		r.data[v[choice]]["status"] = "2";
		r.updateReserve();
		cout << "修改成功！" << endl;
		system("pause");
		system("cls");
		break;
	case 2:
		r.data[v[choice]]["status"] = "3";
		r.updateReserve();
		cout << "修改成功！" << endl;
		system("pause");
		system("cls");
		break;
	case 3:
		cout << "退出成功！" << endl;
		system("pause");
		system("cls");
		break;
	}
	system("cls");
}
