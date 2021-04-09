#include <iostream>
#include <fstream>
#include "Function.h"
#define N 15
using namespace std;

int main() {
	fstream out("out.txt", ios::app);
	if (!out.is_open()) {
		exit(EXIT_FAILURE);
	}
	int x, n, i;
	int shuzu[N];
	srand(time(NULL));
	for (i = 0; i < N; i++) {
		shuzu[i] = rand() / 1000 + 100;
	}
	cout << "顺序查找算法演示!" << endl;
	cout << "数据数列:" << endl;
	out << "顺序查找算法演示!" << endl;
	out << "数据数列:" << endl;
	for (i = 0; i < N; i++) {
		cout << shuzu[i] << "  ";
		out << shuzu[i] << "  ";
	}
	cout << endl << endl;
	out << endl << endl;
	cout << "输入要查找的数:";
	cin >> x;
	n = SearchFun(shuzu, N, x);
	if (n < 0) {
		cout << "没找到数组" << endl;
		out << "没找到数组" << endl;
	}
	else {
		cout << "数据:" << x << "位于数组的第" << n + 1 << "个元素处." << endl << endl;
		out << "数据:" << x << "位于数组的第" << n + 1 << "个元素处." << endl << endl;
	}
	return 0;
}