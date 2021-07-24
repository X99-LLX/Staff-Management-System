#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"boss.h"
#include"Employee.h"
#include"mana.h"
#include<fstream>
#define filename "Employee_data.txt"

class Manager {
public:
	worker** em_arr;
	int em_num;
	bool empty;
	Manager();

	~Manager();

	void system1();

	void Exit_system();

	void Add_information();

	void save();

	int getnewnum();

	void innitworker();

	void Display_information();

	void Delete_information();

	int findworker(int id);

	void Modify_information();

	void Find_information();

	void Information_sorting();

	void Delete_all();

	void menu();
};
