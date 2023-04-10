#include "ComputerRoomReserver.h"
#include"Manager.h"
#include"Student.h"
#include"Teacher.h"
#include"Reserve.h"
#include<fstream>

void ComputerRoomReserver::interface()
{
	cout << "机房预约系统" << endl;
	cout << "登录界面" << endl;
	cout << "1.学生" << endl;
	cout << "2.老师" << endl;
	cout << "3.管理员" << endl;
	cout << "4.退出" << endl;
	cout << "请输入您的选择：" << endl;
}

void studentInterface(Student s)
{

	while (true)
	{
		s.interface();

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			s.reserve();
			break;
		case 2:
			s.showMyReservation();
			break;
		case 3:
			s.showAllReservation();
			break;
		case 4:
			s.cancalReservation();
			break;
		case 5:
			cout << "退出成功！" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			system("cls");
		}
	}

	system("cls");
}

void teacherInterface(Teacher t) 
{
	while (true)
	{
		t.interface();

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			t.showAllReserve();
			break;
		case 2:
			t.reviewReserve();
			break;
		case 3:
			cout << "退出成功！" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			system("cls");
		}
	}

	system("cls");

}

void managerInterface()
{
	Manager m;

	while (true)
	{
		m.interface();

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			m.addAccount();
			break;
		case 2:
			m.showAccount();
			break;
		case 3:
			m.showRoom();
			break;
		case 4:
			m.clearAllReservation();
			break;
		case 5:
			cout << "退出成功！" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			system("cls");
		}
	}

	system("pause");
	return;
}

void Login(int choice)
{
	string id, name, pwd;
	string fid, fname, fpwd;

	switch (choice)
	{
	case 1://学生	
	{
		cout << "请输入学号:" << endl;
		cin >> id;
		cout << "请输入姓名：" << endl;
		cin >> name;
		cout << "请输入密码：" << endl;
		cin >> pwd;
		ifstream ifs("student.txt", ios::in);
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "学生登录成功！" << endl;
				system("pause");
				system("cls");

				Student s(id, name, pwd);
				studentInterface(s);

				return;
			}
		}
		ifs.close();
		break;
	}
	case 2://老师
	{
		cout << "请输入职工号:" << endl;
		cin >> id;
		cout << "请输入姓名：" << endl;
		cin >> name;
		cout << "请输入密码：" << endl;
		cin >> pwd;
		ifstream ifs("teacher.txt", ios::in);
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "老师登录成功！" << endl;
				system("pause");
				system("cls");

				Teacher t(id, name, pwd);
				teacherInterface(t);

				return;
			}
		}
		ifs.close();
		break;
	}	
	case 3://管理员	
	{
		cout << "请输入姓名：" << endl;
		cin >> name;
		cout << "请输入密码：" << endl;
		cin >> pwd;
		ifstream ifs("manager.txt", ios::in);
		while ( ifs >> fname && ifs >> fpwd)
		{
			if ( fname == name && fpwd == pwd)
			{
				cout << "管理员登录成功！" << endl;
				system("pause");
				system("cls");

				managerInterface();

				return;
			}
		}
		ifs.close();
		break;
	}
	}
	cout << "登录失败!" << endl;
	system("pause");
	system("cls");
}

int main()
{
	Reserve r;
	r.updateReserve();
	ComputerRoomReserver c;

	while (true)
	{
		c.interface();

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			Login(1);
			break;
		case 2:
			system("cls");
			Login(2);
			break;
		case 3:
			system("cls");
			Login(3);
			break;
		case 4:
			cout << "退出成功，欢迎再次使用！" << endl;
			system("pause");
			system("cls");
			return 0;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
		}
	}

	return 0;
}


