#include "ComputerRoomReserver.h"
#include"Manager.h"
#include"Student.h"
#include"Teacher.h"
#include"Reserve.h"
#include<fstream>

void ComputerRoomReserver::interface()
{
	cout << "����ԤԼϵͳ" << endl;
	cout << "��¼����" << endl;
	cout << "1.ѧ��" << endl;
	cout << "2.��ʦ" << endl;
	cout << "3.����Ա" << endl;
	cout << "4.�˳�" << endl;
	cout << "����������ѡ��" << endl;
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
			cout << "�˳��ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "����������������룡" << endl;
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
			cout << "�˳��ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "����������������룡" << endl;
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
			cout << "�˳��ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "����������������룡" << endl;
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
	case 1://ѧ��	
	{
		cout << "������ѧ��:" << endl;
		cin >> id;
		cout << "������������" << endl;
		cin >> name;
		cout << "���������룺" << endl;
		cin >> pwd;
		ifstream ifs("student.txt", ios::in);
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "ѧ����¼�ɹ���" << endl;
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
	case 2://��ʦ
	{
		cout << "������ְ����:" << endl;
		cin >> id;
		cout << "������������" << endl;
		cin >> name;
		cout << "���������룺" << endl;
		cin >> pwd;
		ifstream ifs("teacher.txt", ios::in);
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "��ʦ��¼�ɹ���" << endl;
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
	case 3://����Ա	
	{
		cout << "������������" << endl;
		cin >> name;
		cout << "���������룺" << endl;
		cin >> pwd;
		ifstream ifs("manager.txt", ios::in);
		while ( ifs >> fname && ifs >> fpwd)
		{
			if ( fname == name && fpwd == pwd)
			{
				cout << "����Ա��¼�ɹ���" << endl;
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
	cout << "��¼ʧ��!" << endl;
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
			cout << "�˳��ɹ�����ӭ�ٴ�ʹ�ã�" << endl;
			system("pause");
			system("cls");
			return 0;
		default:
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
		}
	}

	return 0;
}


