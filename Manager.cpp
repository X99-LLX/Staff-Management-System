#include"manager.h"

Manager::Manager() {
	this->em_num = 0;
	this->em_arr = NULL;
	this->empty = 1;
}

Manager::~Manager() {
	if (this->em_arr!= NULL) {
		delete this->em_arr;
		this->em_arr = NULL;
	}
}

void Manager::system1() {
	system("pause");
	system("cls");
}

void Manager::Exit_system() {
	system1();
	cout << "���˳�����������ӭ�´�ʹ�ã�" << endl;
	exit(0);
}

void Manager::menu() {
	cout << "**************************************" << endl;
	cout << "**********  0.�˳��������  **********" << endl;
	cout << "**********  1.����ְ����Ϣ  **********" << endl;
	cout << "**********  2.��ʾְ����Ϣ  **********" << endl;
	cout << "**********  3.ɾ����ְְ��  **********" << endl;
	cout << "**********  4.�޸�ְ����Ϣ  **********" << endl;
	cout << "**********  5.����ְ����Ϣ  **********" << endl;
	cout << "**********  6.���ձ������  **********" << endl;
	cout << "**********  7.ɾ�������ĵ�  **********" << endl;
	cout << "**************************************" << endl;
}

void Manager::Add_information() {
	int add_num;
	cout << "��������Ҫ��ӵ�����!" << endl;
	cin >> add_num;
	if (add_num > 0) {
		int newnum = this->em_num + add_num;
		worker** newspace = new worker * [newnum];
		if (this->em_arr != NULL) {
			for (int j = 0; j < this->em_num; j++) {
				this->em_arr[j] = newspace[j];
			}
		}
		for (int i = 0; i < add_num; i++) {
			int id;
			string name;
			int did;
			cout << "����� " << i + 1 << " ���˵ı��" << endl;
			cin >> id;
			cout << "����� " << i + 1 << " ���˵�����" << endl;
			cin >> name;
			cout << "����� " << i + 1 << " ���˵ĸ�λ" << endl;
			cout << "1 : Ա�� " << endl;
			cout << "2 : ���� " << endl;
			cout << "3 : �ϰ� " << endl;
			cin >> did;
			worker* w1 = NULL;
			switch (did)
			{
			case 1:w1 = new Employee(id, name, did);
				break;
			case 2:w1 = new mana(id, name, did);
				break;
			case 3:w1 = new boss(id, name, did);
				break;
			default:
				cout << "�����������������" << endl;
				return;
				break;
			}
			newspace[this->em_num + i] = w1;
		}
		delete[]em_arr;
		this->em_arr = newspace;
		this->em_num = newnum;
		cout << "�ɹ���� " << add_num << " ����" << endl;
		save();
		system1();
	}
	else {
		cout << "�����������������" << endl;
		system1();
	}

}

void Manager::save() {
	ofstream ofs;
	ofs.open(filename, ios::out);
	for (int i = 0; i < em_num; i++) {
		ofs << this->em_arr[i]->id << " " 
			<< this->em_arr[i]->name << " " 
			<< this->em_arr[i]->d_id << endl;
	}
	ofs.close();
}