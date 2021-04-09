/*
用递归的方法编写函数求Fibonacci级数,公式为
	F(n)=F(n-1)+F(n-2)(n>2),F(1)=F(2)=1
*/
#include <iostream>
#include <fstream>
using namespace std;
int F(int n) {
	if (n == 1 || n == 2) {//终止条件
		return 1;
	}
	else {//递归调用
		return F(n - 1) + F(n - 2);
	}
}
int main() {
	fstream result("result.txt", ios::app);
	if (!result.is_open()) {
		cout << "not open" << endl;
		exit(EXIT_FAILURE);
	}
	cout << "enter the number ";
	int num;
	cin >> num;
	result << "F(" << num << ")=" << F(num) << endl;
}