/*
最小公倍数
*/
#include <iostream>
/// @brief 最大公倍数
int gcd(int a, int b) {
	int m, n;
	if (a > b) {
		m = a;
		n = b;
	}
	else {
		m = b;
		n = a;
	}
	if (n == 0) {
		return m;
	}
	if (m % 2 == 0 && n % 2 == 0) {
		return 2 * gcd(m / 2, n / 2);
	}
	if (m % 2 == 0) {
		return gcd(m / 2, n);
	}
	if (n % 2 == 0) {
		return gcd(m, n / 2);
	}
	return gcd((m + n) / 2, (m - n) / 2);
}
/// @brief 最小公倍数
int lcm(int a, int b) {
	int c, d;
	c = gcd(a, b);
	d = (a * b) / c;
	return d;
}
void main() {
	int a, b, c, d;
	std::cout << "输入两个正整数:";
	std::cin >> a >> b;
	c = gcd(a, b);
	std::cout << a << "和" << b << "的最大公约数:" << c << std::endl;
	d = lcm(a, b);
	std::cout << a << "和" << b << "的最小公倍数:" << d << std::endl;
	return;
}