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
	cout << "已退出管理器，欢迎下次使用！" << endl;
	exit(0);
}

void Manager::menu() {
	cout << "**************************************" << endl;
	cout << "**********  0.退出管理程序  **********" << endl;
	cout << "**********  1.增加职工信息  **********" << endl;
	cout << "**********  2.显示职工信息  **********" << endl;
	cout << "**********  3.删除离职职工  **********" << endl;
	cout << "**********  4.修改职工信息  **********" << endl;
	cout << "**********  5.查找职工信息  **********" << endl;
	cout << "**********  6.按照编号排序  **********" << endl;
	cout << "**********  7.删除所有文档  **********" << endl;
	cout << "**************************************" << endl;
}

void Manager::Add_information() {
	int add_num;
	cout << "请输入需要添加的人数!" << endl;
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
			cout << "输入第 " << i + 1 << " 个人的编号" << endl;
			cin >> id;
			cout << "输入第 " << i + 1 << " 个人的姓名" << endl;
			cin >> name;
			cout << "输入第 " << i + 1 << " 个人的岗位" << endl;
			cout << "1 : 员工 " << endl;
			cout << "2 : 经理 " << endl;
			cout << "3 : 老板 " << endl;
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
				cout << "输入错误，请重新输入" << endl;
				return;
				break;
			}
			newspace[this->em_num + i] = w1;
		}
		delete[]em_arr;
		this->em_arr = newspace;
		this->em_num = newnum;
		cout << "成功添加 " << add_num << " 个人" << endl;
		save();
		system1();
	}
	else {
		cout << "输入错误，请重新输入" << endl;
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