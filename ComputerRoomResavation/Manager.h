#pragma once
#include"Person.h"

class Manager:public Person {
public:
	void addAccount();

	void showAccount();

	void showRoom();

	void clearAllReservation();

	void interface();

	//vector<Student> vs;

	//vector<Teacher> vt;
};