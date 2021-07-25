#include"manager.h"

Manager::Manager() {
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
	this->em_num = 0;
	this->em_arr = NULL;
	this->empty = 1;
		ifs.close();
		return;
}

	char test = ifs.get();
	if (ifs.eof()) {
		cout << "empty" << endl;
		this->em_num = 0;
		this->em_arr = NULL;
		this->empty = 1;
		ifs.close();
		return;
	}
	ifs.close();
	this->em_num = getnewnum();
	this->innitworker();
}

int Manager::getnewnum() {
	ifstream ifs;
	ifs.open(filename, ios::in);
	int id; string name; int did; int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		num++;
	}
	ifs.close();
	return num;
}

void Manager::innitworker() {
	ifstream ifs;
	int id; string name; int did;
	ifs.open(filename, ios::in);
	em_arr = new worker * [this->em_num];
	for (int i = 0; i < this->em_num; i++) {
		ifs >> id;
		ifs >> name;
		ifs >> did;
		switch (did) {
		case 1:
			em_arr[i] = new Employee(id, name, did);
			break;
		case 2:
			em_arr[i] = new mana(id, name, did);
			break;
		case 3:
			em_arr[i] = new boss(id, name, did);
			break;
		}
	}
	ifs.close();
	this->empty = 0;
	//cout << "not empty " << endl;
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
	system1();
	exit(0);
}

void Manager::menu() {
	cout << "**************************************" << endl;
	cout << "********** ��ӭʹ�ù���ϵͳ **********" << endl;
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
				newspace[j] = this->em_arr[j];
			}
		}

		for (int i = 0; i < add_num; i++) {
			int id;
			string name;
			int did;
			cout << "����� " << i + 1 << " ���˵ı��" << endl;
			while (1) {
			cin >> id;
				int temp = 1;
				for (int i = 0; i < this->em_num; i++) {
					if (newspace[i]->id == id) {
						cout << "**����**   �Ѵ��ڱ��Ϊ " << id << " ��Ա����  ����������" << endl;
						temp = 0;
						break;
					}
				}
				if (temp == 0) {
					continue;
				}
				else {
					break;
				}
			}
	
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
				cout << "�������!" << endl;
				return;
				break;
			}
			newspace[this->em_num] = w1;
			this->em_num++;
		}
		delete[]em_arr;
		this->em_arr = newspace;
//		this->em_num = newnum;
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
	for (int i = 0; i < this->em_num; i++) {
		ofs << this->em_arr[i]->id << " " 
			<< this->em_arr[i]->name << " " 
			<< this->em_arr[i]->d_id << endl;
	}
	ofs.close();
}

void Manager::Display_information() {
	if (this->empty) {
		cout << "�ļ������ڻ����ļ�Ϊ��!" << endl;
		system1();
	}
	else {
		cout << "���" << "\t\t" << "����" << "\t\t" << "����" << "\t\t" << "ְ��" << endl;
		for (int i = 0; i < this->em_num; i++) {
			this->em_arr[i]->showthis();
		}
		system1();
	}
}

void Manager::Delete_information() {
	int id; //string name;
	cout << "��������ְԱ���ı��" << endl;
	cin >> id;
	int ret = findworker(id);
	if (ret == -1) {
		cout << "���޴��ˣ�" << endl;
		system1();
		return;
	}
	else {
		for (int i = ret; i < this->em_num - 1; i++) {
			this->em_arr[i] = this->em_arr[i + 1];
		}
		this->em_num--;
	}
	cout << "�ɹ�ɾ�� " << id << " ��Ա��" << endl;
	save();
	system1();
}

int Manager::findworker(int id) {
	for (int i = 0; i < this->em_num; i++) {
		if (this->em_arr[i]->id == id) {
			return i;
		}
	}
	return -1;
}

