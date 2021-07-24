#include"Employee.h"

Employee::Employee(int i, string n, int di) {
	id = i; name = n; d_id = di;
}

string Employee::zhize() {
	return "完成经理下发的任务";
}

void Employee::showthis() {
	cout << id << "\t\t" << name << "\t\t" << getpost() << "\t\t" << zhize() << endl;
}

string Employee::getpost() {
	return "员工";
}