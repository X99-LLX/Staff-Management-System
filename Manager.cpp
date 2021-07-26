#include"manager.h"

Manager::Manager() {
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->em_num = 0;
		this->em_arr = NULL;
		this->empty = 1;
		ifs.close();
		return;
}

	char test = ifs.get();
	if (ifs.eof()) {
		//cout << "empty" << endl;
		this->em_num = 0;
		this->em_arr = NULL;
		this->empty = 1;
		ifs.close();
		return;
	}
	ifs.close();
	this->empty = 0;
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
	cout << "已退出管理器，欢迎下次使用！" << endl;
	system1();
	exit(0);
}

void Manager::menu() {
	cout << "**************************************" << endl;
	cout << "********** 欢迎使用管理系统 **********" << endl;
	cout << "**********  0.退出管理程序  **********" << endl;
	cout << "**********  1.增加职工信息  **********" << endl;
	cout << "**********  2.显示职工信息  **********" << endl;
	cout << "**********  3.删除离职职工  **********" << endl;
	cout << "**********  4.修改职工信息  **********" << endl;
	cout << "**********  5.查找职工信息  **********" << endl;
	cout << "**********  6.按照编号排序  **********" << endl;
	cout << "**********  7.删除所有信息  **********" << endl;
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
				newspace[j] = this->em_arr[j];
			}
		}

		for (int i = 0; i < add_num; i++) {
			int id;
			string name;
			int did;
			cout << "输入第 " << i + 1 << " 个人的编号" << endl;
			while (1) {
			cin >> id;
				int temp = 1;
				for (int i = 0; i < this->em_num; i++) {
					if (newspace[i]->id == id) {
						cout << "**错误**   已存在编号为 " << id << " 的员工！  请重新输入" << endl;
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
				cout << "输入错误!" << endl;
				return;
				break;
			}
			newspace[this->em_num] = w1;
			this->em_num++;
		}
		delete[]em_arr;
		this->em_arr = newspace;
//		this->em_num = newnum;
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
	for (int i = 0; i < this->em_num; i++) {
		ofs << this->em_arr[i]->id << " " 
			<< this->em_arr[i]->name << " " 
			<< this->em_arr[i]->d_id << endl;
	}
	ofs.close();
	if (this->empty) {
		this->empty = 0;
	}
	if (this->em_num == 0) {
		this->empty = 1;
	}
}

void Manager::Display_information() {
	if (this->empty) {
		cout << "文件不存在或者文件为空!" << endl;
		system1();
	}
	else {
		cout << "编号" << "\t\t" << "姓名" << "\t\t" << "部门" << "\t\t" << "职责" << endl;
		for (int i = 0; i < this->em_num; i++) {
			this->em_arr[i]->showthis();
		}
		system1();
	}
}

void Manager::Delete_information() {
	if (this->empty) {
		cout << "文件不存在或文件为空！" << endl;
		system1();
		return;
	}
	int id; //string name;
	cout << "请输入离职员工的编号" << endl;
	cin >> id;
	int ret = findworker(id);
	if (ret == -1) {
		cout << "查无此人！" << endl;
		system1();
		return;
	}
	else {
		for (int i = ret; i < this->em_num - 1; i++) {
			this->em_arr[i] = this->em_arr[i + 1];
		}
		this->em_num--;
	}
	cout << "成功删除 " << id << " 号员工" << endl;
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

int Manager::findworker(string id) {
	for (int i = 0; i < this->em_num; i++) {
		if (this->em_arr[i]->name == id) {
			return i;
		}
	}
	return -1;
}

void Manager::Modify_information() {
	if (this->empty) {
		cout << "文件不存在或文件为空！" << endl;
		system1();
		return;
	}
	int find;
	cout << "请输入要修改的职工编号" << endl;
	int id1;
	cin >> id1;
	find = findworker(id1);
	if (find == -1) {
		cout << "您输入的用户不存在!" << endl;
		system1();
	}
	else {
		worker* w1 = NULL;
		int id;
		string name;
		int did;
		cout << "输入第新的员工编号" << endl;
		delete em_arr[find];
		while (1) {
			cin >> id;
			int temp = 1;
			for (int i = 0; i < this->em_num; i++) {
				if (this->em_arr[i]->id == id) {
					cout << "**错误**   已存在编号为 " << id << " 的员工！  请重新输入" << endl;
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
		cout << "输入新的员工名称" << endl;
		cin >> name;
		cout << "输入新的员工岗位" << endl;
		cout << "1 : 员工 " << endl;
		cout << "2 : 经理 " << endl;
		cout << "3 : 老板 " << endl;
		cin >> did;
		switch (did)
		{
		case 1:w1 = new Employee(id, name, did);
			break;
		case 2:w1 = new mana(id, name, did);
			break;
		case 3:w1 = new boss(id, name, did);
			break;
		default:
			cout << "输入错误!" << endl;
			return;
			break;
		}
		em_arr[find] = w1;
		this->save();
		system1();
	}
}

void Manager::Find_information() {
	if (this->empty) {
		cout << "文件不存在或文件为空！" << endl;
		system1();
		return;
	}
	int id; string name; int ret; int sel;
	cout << "以姓名查找或者编号查找" << endl
		 << "1-----姓名查找" << endl
	     << "2-----编号查找" << endl;
	cin >> sel;
	switch (sel) {
	case 1:
		cout << "输入您要查找的员工姓名 " << endl;
		cin >> name;
		ret = findworker(name);
		break;
	case 2:
		cout << "输入您要查找的员工编号 " << endl;
		cin >> id;
		ret = findworker(id);
		break;
	default:
		cout << "输入错误！" << endl;
		system1();
		return;
	}
	if (ret == -1) {
		cout << "您查找的员工不存在!" << endl;
	}
	else {
		cout << "编号" << "\t\t" << "姓名" << "\t\t" << "部门" << "\t\t" << "职责" << endl;
		this->em_arr[ret]->showthis();
	}
	system1();
}

void Manager::Sort_ascending(worker** a,int begin, int end) {
	if (begin > end) {
		return;
	}
	int temp = this->em_arr[begin]->id;
	int i = begin;
	int j = end;
	while (i != j) {
		while (this->em_arr[j]->id >= temp && j > i) {
			j--;
		}
		while (this->em_arr[i]->id <= temp && j > i) {
			i++;
		}
		if (i < j) {
			worker* a = this->em_arr[i];
			this->em_arr[i] = this->em_arr[j];
			this->em_arr[j] = a;
		}
	}
	worker* b = this->em_arr[begin];
	this->em_arr[begin] = this->em_arr[i];
	this->em_arr[i] = b;
	Sort_ascending(this->em_arr, begin, i - 1);
	Sort_ascending(this->em_arr, i + 1, end);
}

void Manager::Sort_descending(worker** a, int begin, int end) {
	if (begin > end) {
		return;
	}
	int temp = this->em_arr[begin]->id;
	int i = begin;
	int j = end;
	while (i != j) {
		while (this->em_arr[j]->id <= temp && j > i) {
			j--;
		}
		while (this->em_arr[i]->id >= temp && j > i) {
			i++;
		}
		if (j < i) {
			worker* a = this->em_arr[i];
			this->em_arr[i] = this->em_arr[j];
			this->em_arr[j] = a;
		}
	}
	worker* b = this->em_arr[begin];
	this->em_arr[begin] = this->em_arr[i];
	this->em_arr[i] = b;
	Sort_descending(this->em_arr, begin, i - 1);
	Sort_descending(this->em_arr, i + 1, end);
}

void Manager::Information_sorting() {
	if (this->empty) {
		cout << "文件不存在或文件为空！" << endl;
		system1();
		return;
	}
	cout << "请选择排序方式！" << endl
		 << "1-----升序" << endl
		 << "2-----降序" << endl;
	int sel;
	cin >> sel;
	switch (sel)
	{
	case 1:
		Sort_ascending(this->em_arr,0,this->em_num-1);
		cout << "排序完成！" << endl;
		this->Display_information();
		break;
	case 2:
		Sort_descending(this->em_arr,0, this->em_num - 1);
		cout << "排序完成！" << endl;
		this->Display_information();
		break;
	default:
		break;
	}
	this->save();
}

void Manager::Delete() {
	for (int i = 0; i < this->em_num; i++) {
		if (this->em_arr[i] != NULL) {
			delete this->em_arr[i];
		}
	}
	delete[]this->em_arr;
	this->em_arr = NULL;
	this->empty = 1;
	this->em_num = 0;
	this->save();
	cout << "已删除所有信息！" << endl;
	system1();
}

void Manager::Delete_all() {
	if (this->empty) {
		cout << "文件不存在或文件为空！" << endl;
		system1();
		return;
	}
	cout << "确认删除所有员工信息吗！操作不可逆" << endl
		 << "输入1确认删除！" << endl
		 << "输入其他数取消操作! " << endl;
	int sel;
	cin >> sel;
	switch (sel)
	{
	case 1:
		Delete();
		break;
	default:
		cout << "取消！" << endl;
		system1();
		break;
	}
}