﻿/*
n阶勒让德多项式
*/
#include <iostream>
#include <fstream>
using namespace std;
float p(int n, int x) {
	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return x;
	}
	else {
		return ((2 * n - 1) * x * p(n - 1, x) - (n - 1) * p(n - 2, x)) / n;
	}
}
int main() {
	fstream result("result.txt", ios::app);
	if (!result.is_open()) {
		cout << "not open" << endl;
		exit(EXIT_FAILURE);
	}
	cout << "输入正整数n:";
	int n;
	cin >> n;
	cout << "输入正整数x:";
	int x;
	cin >> x;
	result << "P" << n << "(" << x << ")=" << p(n, x) << endl;
	return 0;
}