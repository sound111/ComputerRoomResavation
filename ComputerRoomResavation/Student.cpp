#include "Student.h"
#include"Reserve.h"
#include<fstream>

Student::Student(string id,string name,string pwd)
{
	Id = id;
	Name = name;
	Pwd = pwd;

	ComputerRoom c;
	ifstream ifs("computerRoom.txt", ios::in);

	while (ifs>>c.roomId&&ifs>>c.Capacity)
	{
		vc.push_back(c);
	}
	ifs.close();
}

void Student::interface()
{
	cout << "����ԤԼϵͳ" << endl;
	cout << "ѧ������" << endl;
	cout << "1.����ԤԼ" << endl;
	cout << "2.�鿴����ԤԼ" << endl;
	cout << "3.�鿴����ԤԼ" << endl;
	cout << "4.ȡ��ԤԼ" << endl;
	cout << "5.�˳�" << endl;
	cout << "����������ѡ��" << endl;
}

void Student::reserve()
{
	cout << "ѧ��ԤԼ��������" << endl;
	cout << "������ԤԼʱ�䣺" << endl;
	cout<< "1.��һ 2.�ܶ� 3.���� 4.���� 5.����" << endl;
	int day;
	cin >> day;

	cout << "���������ʱ�䣺" << endl;
	cout << "1.���� 2.����" << endl;
	int noon;
	cin >> noon;

	cout << "�����������ţ�" << endl;
	cout << "1.һ�Ż��� 2.���Ż��� 3.���Ż���" << endl;
	int roomId;
	cin >> roomId;

	//1����� 2��˳ɹ� 3���ʧ�� 4��ȡ��
	string status = "1";
	ofstream ofs("reserver.txt", ios::app);
	ofs << Id << " " << Name << " " << Pwd << " "
		<< day << " " << noon << " " << roomId<<" "
		<<status << endl;
	ofs.close();

	cout << "ԤԼ�ɹ���" << endl;
	system("pause");
	system("cls");
}

void Student::showMyReservation()
{
	Reserve r;

	cout << "�ҵ�ԤԼΪ��" << endl;

	for (map<int, map<string, string>>::iterator it = r.data.begin(); it != r.data.end(); it++)
	{
		if (it->second.begin()->second == Id)
		{
			cout << it->first << ":" << endl;

			for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
			{
				cout << mit->first << ":" << mit->second << " ";
			}

			cout << endl;
		}
		
	}

	system("pause");
	system("cls");
}

void Student::showAllReservation()
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

//1����� 2��˳ɹ� 3���ʧ�� 4��ȡ��
void Student::cancalReservation()
{

	Reserve r;

	cout << "��ȡ����ԤԼ�У�" << endl;

	for (map<int, map<string, string>>::iterator it = r.data.begin(); it != r.data.end(); it++)
	{
		if (it->second.begin()->second == Id&&(it->second["status"] == "2" ||it->second["status"]=="1"))
		{
			cout << it->first << ":" << endl;

			for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
			{
				cout << mit->first << ":" << mit->second << " ";
			}

			cout << endl;
		}
	}

	cout << "������Ҫȡ����ԤԼ��ţ�" << endl;

	int choice;
	cin >> choice;

	r.data[choice]["status"] = "4";
	r.updateReserve();

	cout << "�޸ĳɹ���" << endl;

	system("pause");
	system("cls");
}
