#include"boss.h"

boss::boss(int i,string n,int di) {
	id = i; name = n; d_id = di;
}

string boss::zhize() {
	return "����˾��������";
}

void boss::showthis() {
	cout << id << "\t\t" << name << "\t\t" << getpost() << "\t\t" << zhize() << endl;
}

string boss::getpost() {
	return "�ܲ�";
}