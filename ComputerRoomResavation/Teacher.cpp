#include "Teacher.h"
#include"Reserve.h"
#include<vector>

void Teacher::interface()
{
	cout << "����ԤԼϵͳ" << endl;
	cout << "��ʦ����" << endl;
	cout << "1.�鿴����ԤԼ" << endl;
	cout << "2.���ԤԼ" << endl;
	cout << "3.�˳�" << endl;
	cout << "����������ѡ��" << endl;
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

	cout << "����ԤԼΪ��" << endl;

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

	cout << "����ԤԼ������ʾ��" << endl;

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

	cout << "������Ҫ��˵�ԤԼ��ţ�" << endl;

	int choice;
	cin >> choice;

	if (choice > v.size()||choice<0)
	{
		cout << "����������������룡" << endl;
	}
	
	cout << "������ѡ�1.��˳ɹ� 2.���ʧ�� 3. �˳����" << endl;

	int choice2;
	cin >> choice2;

	switch (choice2)
	{
	case 1:
		r.data[v[choice]]["status"] = "2";
		r.updateReserve();
		cout << "�޸ĳɹ���" << endl;
		system("pause");
		system("cls");
		break;
	case 2:
		r.data[v[choice]]["status"] = "3";
		r.updateReserve();
		cout << "�޸ĳɹ���" << endl;
		system("pause");
		system("cls");
		break;
	case 3:
		cout << "�˳��ɹ���" << endl;
		system("pause");
		system("cls");
		break;
	}
	system("cls");
}
