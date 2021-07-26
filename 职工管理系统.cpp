#include<iostream>
using namespace std;
#include"manager.h"
#include<string>
#include<fstream>



int main() {
	int choose;
	Manager m1;
	while (1) {
		m1.menu();
		cout << "请输入对应序号选择功能！" << endl;
		cin >> choose;
		switch (choose)
		{
		case 0:
			m1.Exit_system();
			break;
		case 1:
			m1.Add_information();
			//m1.em_arr[0]->showthis();
			//m1.em_arr[1]->showthis();
			break;
		case 2:
			m1.Display_information();
			break;
		case 3:
			m1.Delete_information();
			break;
		case 4:
			m1.Modify_information();
			break;
		case 5:
			m1.Find_information();
			break;
		case 6:
			m1.Information_sorting();
			break;
		case 7:
			m1.Delete_all();
			break;
		default:
			cout << "请输入正确的序号!" << endl;
			m1.system1();
			break;
		}
	}
}