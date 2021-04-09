#include "Function.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	fstream out("out.txt", ios::app);
	if (!out.is_open()) {
		return 1;
	}
	char ch;
	LinkList list, q;
	cout << "动态数组排序!" << endl;
	out << "动态数组排序!" << endl;
	cout << "输入一组字符串,以0结束!" << endl;
	q = list = CreatLinkList();
	cin >> ch;
	while (ch != '0') {
		insertList(&list, q, ch);
		q = q->next;
		cin >> ch;
	}
	DynamicSort(list);
	cout << endl;
	out << endl;
	cout << "对该数组排序之后,得到如下结果:" << endl;
	out << "对该数组排序之后,得到如下结果:" << endl;
	while (list) {
		out << list->data << "  ";
		list = list->next;
	}
	out << endl;
	return 0;
}