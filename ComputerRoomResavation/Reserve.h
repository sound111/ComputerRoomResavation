#pragma once
#include<map>
#include<iostream>
using namespace std;

class Reserve
{
public:
	Reserve();

	void updateReserve();

	map<int, map<string, string>> data;

	int Size;
};