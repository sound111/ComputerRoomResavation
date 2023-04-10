#pragma once
#include<vector>
#include"Person.h"
#include"ComputerRoom.h"

class Student :public Person
{
public:
	string Id;

	vector<ComputerRoom> vc;

	Student(string id, string name, string pwd);

	void interface();

	void reserve();

	void showMyReservation();

	void showAllReservation();

	void cancalReservation();
};