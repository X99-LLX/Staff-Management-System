#include"Employee.h"

Employee::Employee(int i, string n, int di) {
	id = i; name = n; d_id = di;
}

string Employee::zhize() {
	return "��ɾ����·�������";
}

void Employee::showthis() {
	cout << id << "\t\t" << name << "\t\t" << getpost() << "\t\t" << zhize() << endl;
}

string Employee::getpost() {
	return "Ա��";
}