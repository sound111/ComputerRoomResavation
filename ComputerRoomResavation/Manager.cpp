#include "Manager.h"
#include<fstream>
#include<string>

void Manager::interface()
{
	cout << "机房预约系统" << endl;
	cout << "管理员界面" << endl;
	cout << "1.添加账号" << endl;
	cout << "2.查看账号" << endl;
	cout << "3.查看机房" << endl;
	cout << "4.清空预约" << endl;
	cout << "5.退出" << endl;
	cout << "请输入您的选择：" << endl;
}

void Manager::addAccount()
{
	int flag;

	do {
		cout << "添加账号" << endl;
		cout << "1.添加学生账号" << endl;
		cout << "2.添加老师账号" << endl;
		cout << "请输入您的选择：" << endl;

		int choice;
		cin >> choice;

		string idType;
		string fileType;

		if (choice == 1)
		{
			idType = "学号";
			fileType = "student.txt";
		}
		else if (choice == 2)
		{
			idType = "职工号";
			fileType = "teacher.txt";
		}

		string id, name, pwd;
		cout << "请输入" << idType << ":" << endl;
		cin >> id;
		cout << "请输入姓名：" << endl;
		cin >> name;
		cout << "请输入密码：" << endl;
		cin >> pwd;

		ofstream ofs(fileType, ios::app);
		ofs << id << " ";
		ofs << name << " ";
		ofs << pwd << endl;

		ofs.close();

		cout << "添加成功！" << endl;
		cout << "是否继续添加？ 0.退出 1.继续添加" << endl;
		cin >> flag;

		system("pause");
		system("cls");
	} while (flag);
	
}

void Manager::showAccount()
{
	int flag;
	do {
		cout << "查看账号" << endl;
		cout << "1.查看学生账号" << endl;
		cout << "2.查看老师账号" << endl;
		cout << "请输入您的选择：" << endl;

		int choice;
		cin >> choice;

		string idType;
		string fileType;

		if (choice == 1)
		{
			idType = "学号";
			fileType = "student.txt";
		}
		else if (choice == 2)
		{
			idType = "职工号";
			fileType = "teacher.txt";
		}

		string id, name, pwd;


		ifstream ifs(fileType, ios::in);
		while (ifs >> id && ifs >> name && ifs >> pwd)
		{
			cout << "id:" << id << " "
				<< "name:" << name << " "
				<< "pwd:" << pwd << endl;
		}

		ifs.close();

		cout << "查看成功！" << endl;
		cout << "是否继续查看其他账号？ 0.退出 1.继续查看" << endl;
		cin >> flag;

		system("pause");
		system("cls");

	} while (flag);
	
}

void Manager::showRoom()
{
	cout << "机房信息如下：" << endl;
	string id, capacity;
	ifstream ifs("computerRoom.txt", ios::in);
	while (ifs >> id && ifs >> capacity)
	{
		cout << "机房序号：" << id << " ";
		cout << "容量：" << capacity << endl;
	}

	ifs.close();

	system("pause");
	system("cls");
}

void Manager::clearAllReservation()
{
	ifstream ifs("reserver.txt", ios::trunc);
	ifs.close();

	cout << "清空预约成功！" << endl;
	system("pause");
	system("cls");
}