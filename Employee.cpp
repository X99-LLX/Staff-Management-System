#include"Employee.h"

Employee::Employee(int i, string n, int di) {
	id = i; name = n; d_id = di;
}

string Employee::zhize() {
	return "��ɾ����·�������";
}

void Employee::showthis() {
	cout << id << "\t" << name << "\t" << getpost() << "\t" << zhize() << endl;
}

string Employee::getpost() {
	return "Ա��";
}