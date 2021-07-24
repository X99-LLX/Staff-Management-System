#pragma once
#include<iostream>
using namespace std;
#include<string>

class worker {
public:
	int id;
	string name;
	int d_id;
	virtual void showthis() = 0;

	virtual string zhize() = 0;
	virtual string getpost() = 0;
};