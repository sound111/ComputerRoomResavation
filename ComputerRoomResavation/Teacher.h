#pragma once
#include"Person.h"
using namespace std;

class Teacher:public Person
{
public:
	string Id;

	Teacher(string id, string name, string pwd);

	void interface();

	void showAllReserve();

	void reviewReserve();

};