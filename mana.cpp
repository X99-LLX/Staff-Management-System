#include"mana.h"

mana::mana(int i, string n, int di) {
	id = i; name = n; d_id = di;
}

string mana::zhize() {
	return "�����ϰ��·������񲢷����Ա��";
}

void mana::showthis() {
	cout << id << "\t" << name << "\t" << getpost() << "\t" << zhize() << endl;
}

string mana::getpost() {
	return "����";
}