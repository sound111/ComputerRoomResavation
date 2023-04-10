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
	cout << "机房预约系统" << endl;
	cout << "学生界面" << endl;
	cout << "1.申请预约" << endl;
	cout << "2.查看自身预约" << endl;
	cout << "3.查看所有预约" << endl;
	cout << "4.取消预约" << endl;
	cout << "5.退出" << endl;
	cout << "请输入您的选择：" << endl;
}

void Student::reserve()
{
	cout << "学生预约机房界面" << endl;
	cout << "请输入预约时间：" << endl;
	cout<< "1.周一 2.周二 3.周三 4.周四 5.周五" << endl;
	int day;
	cin >> day;

	cout << "请输入具体时间：" << endl;
	cout << "1.上午 2.下午" << endl;
	int noon;
	cin >> noon;

	cout << "请输入机房序号：" << endl;
	cout << "1.一号机房 2.二号机房 3.三号机房" << endl;
	int roomId;
	cin >> roomId;

	//1待审核 2审核成功 3审核失败 4已取消
	string status = "1";
	ofstream ofs("reserver.txt", ios::app);
	ofs << Id << " " << Name << " " << Pwd << " "
		<< day << " " << noon << " " << roomId<<" "
		<<status << endl;
	ofs.close();

	cout << "预约成功！" << endl;
	system("pause");
	system("cls");
}

void Student::showMyReservation()
{
	Reserve r;

	cout << "我的预约为：" << endl;

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

//1待审核 2审核成功 3审核失败 4已取消
void Student::cancalReservation()
{

	Reserve r;

	cout << "可取消的预约有：" << endl;

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

	cout << "请输入要取消的预约序号：" << endl;

	int choice;
	cin >> choice;

	r.data[choice]["status"] = "4";
	r.updateReserve();

	cout << "修改成功！" << endl;

	system("pause");
	system("cls");
}
