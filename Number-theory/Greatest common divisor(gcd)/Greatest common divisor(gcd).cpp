/*
最大公约数:辗转相除法
*/
#include <iostream>
int gcd(int a, int b) {
	int m, n, r;
	if (a > b) {
		m = a;
		n = b;
	}
	else {
		m = b;
		n = a;
	}
	r = m % n;
	while (r != 0) {
		m = n;
		n = r;
		r = m % n;
	}
	return n;
}
void main() {
	int a, b;
	std::cout << "输入两个正整数:";
	std::cin >> a >> b;
	std::cout << a << "和" << b << "的最大公约数:" << gcd(a, b);
	return;
}