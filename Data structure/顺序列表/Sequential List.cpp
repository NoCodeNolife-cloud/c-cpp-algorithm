#include "Declaration.h"
void main() {
	SLType sequentiallist;
	int select;
	do {
		cout << "添加结点\t1\n获取顺序表长度\t2\n插入结点\t3\n删除结点\t4\n查找结点\t5\n显示所有结点\t6\n退出\t\t7\n";
		cin >> select;
		switch (select) {
		case 1: {
			Data data;
			data.EnterData();
			sequentiallist.SLAdd(data);
			break;
		}
		case 2: {
			cout << "顺序表长度为:"
				<< sequentiallist.SLLength()
				<< endl;
			break;
		}
		case 3: {
			int n;
			cout << "当前列表长度为:"
				<< sequentiallist.SLLength()
				<< endl
				<< "插入列表序号为:";
			cin >> n;
			Data data;
			data.EnterData();
			sequentiallist.SLInsert(n, data);
			break;
		}
		case 4: {
			int n;
			cout << "当前列表长度为:"
				<< sequentiallist.SLLength()
				<< endl
				<< "删除列表序号为:";
			cin >> n;
			sequentiallist.SLDelete(n);
			break;
		}
		case 5: {
			int number;
			cout << "输入查询信息类型:"
				<< endl
				<< "关键字\t1\n信息\t\n";
			cin >> number;
			switch (number) {
			case 1: {
				int n;
				cout << "输入查找序号:";
				cin >> n;
				sequentiallist.SLfindByNum(n);
				break;
			}
			case 2: {
				string key;
				cout << "输入关键字:";
				cin >> key;
				sequentiallist.SLFindByCont(key);
				break;
			}
			}
			break;
		}
		case 6: {
			sequentiallist.SLAll();
			break;
		}
		case 7: {
			cout << "Good Bye!"
				<< endl;
			break;
		}
		}
		cin.clear();
	} while (select != 7);
	return;
}