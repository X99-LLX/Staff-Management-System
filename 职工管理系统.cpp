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
		cout << "�������Ӧ���ѡ���ܣ�" << endl;
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

			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			cout << "��������ȷ�����!" << endl;
			m1.system1();
			break;
		}
	}
}