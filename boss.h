#pragma once
#include"worker.h"

class boss :public worker{
public:
	string zhize();
	void showthis();
	boss(int i, string n, int di);
	string getpost();
};