#include"mana.h"

mana::mana(int i, string n, int di) {
	id = i; name = n; d_id = di;
}

string mana::zhize() {
	return "接收老板下发的任务并分配给员工";
}

void mana::showthis() {
	cout << id << "\t" << name << "\t" << getpost() << "\t" << zhize() << endl;
}

string mana::getpost() {
	return "经理";
}