#include "Manager.h"
#include<fstream>
#include<string>

void Manager::interface()
{
	cout << "����ԤԼϵͳ" << endl;
	cout << "����Ա����" << endl;
	cout << "1.����˺�" << endl;
	cout << "2.�鿴�˺�" << endl;
	cout << "3.�鿴����" << endl;
	cout << "4.���ԤԼ" << endl;
	cout << "5.�˳�" << endl;
	cout << "����������ѡ��" << endl;
}

void Manager::addAccount()
{
	int flag;

	do {
		cout << "����˺�" << endl;
		cout << "1.���ѧ���˺�" << endl;
		cout << "2.�����ʦ�˺�" << endl;
		cout << "����������ѡ��" << endl;

		int choice;
		cin >> choice;

		string idType;
		string fileType;

		if (choice == 1)
		{
			idType = "ѧ��";
			fileType = "student.txt";
		}
		else if (choice == 2)
		{
			idType = "ְ����";
			fileType = "teacher.txt";
		}

		string id, name, pwd;
		cout << "������" << idType << ":" << endl;
		cin >> id;
		cout << "������������" << endl;
		cin >> name;
		cout << "���������룺" << endl;
		cin >> pwd;

		ofstream ofs(fileType, ios::app);
		ofs << id << " ";
		ofs << name << " ";
		ofs << pwd << endl;

		ofs.close();

		cout << "��ӳɹ���" << endl;
		cout << "�Ƿ������ӣ� 0.�˳� 1.�������" << endl;
		cin >> flag;

		system("pause");
		system("cls");
	} while (flag);
	
}

void Manager::showAccount()
{
	int flag;
	do {
		cout << "�鿴�˺�" << endl;
		cout << "1.�鿴ѧ���˺�" << endl;
		cout << "2.�鿴��ʦ�˺�" << endl;
		cout << "����������ѡ��" << endl;

		int choice;
		cin >> choice;

		string idType;
		string fileType;

		if (choice == 1)
		{
			idType = "ѧ��";
			fileType = "student.txt";
		}
		else if (choice == 2)
		{
			idType = "ְ����";
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

		cout << "�鿴�ɹ���" << endl;
		cout << "�Ƿ�����鿴�����˺ţ� 0.�˳� 1.�����鿴" << endl;
		cin >> flag;

		system("pause");
		system("cls");

	} while (flag);
	
}

void Manager::showRoom()
{
	cout << "������Ϣ���£�" << endl;
	string id, capacity;
	ifstream ifs("computerRoom.txt", ios::in);
	while (ifs >> id && ifs >> capacity)
	{
		cout << "������ţ�" << id << " ";
		cout << "������" << capacity << endl;
	}

	ifs.close();

	system("pause");
	system("cls");
}

void Manager::clearAllReservation()
{
	ifstream ifs("reserver.txt", ios::trunc);
	ifs.close();

	cout << "���ԤԼ�ɹ���" << endl;
	system("pause");
	system("cls");
}