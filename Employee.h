#pragma once
#include"worker.h"

class Employee :public worker {
public:
	string zhize();
	void showthis();
	Employee(int i, string n, int di);
	string getpost();
};