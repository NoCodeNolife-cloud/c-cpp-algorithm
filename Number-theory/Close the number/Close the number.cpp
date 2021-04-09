/*
整数a的因子和等于整数b,整数b的因子和等于整数a,因子包括1但不包括其本身
*/
#include <iostream>
int ga[100], gb[100];
int friendnum(int a) {
	int i, b1, b2, count;
	/// @brief 清空数组
	for (i = 0; i < 100; i++) {
		ga[i] = gb[i] = 0;
	}
	count = 0;
	b1 = 0;
	/// @brief 求数a的因子
	for (i = 1; i < a / 2 + 1; i++) {
		if (a % i == 0) {
			ga[count++] = i;
			b1 += i;
		}
	}
	count = 0;
	b2 = 0;
	/// @brief 将a的因子之和再进行因式分解
	for (i = 1; i < b1 / 2 + 1; i++) {
		if (b1 % i == 0) {
			gb[count++] = i;
			b2 = b2 + i;
		}
	}
	/// @brief 判断a,b的输出条件
	if (b2 == a && a < b1) {
		return b1;
	}
	else {
		return 0;
	}
}
void main() {
	int i, b, fanwei, count;
	fanwei = 5000;
	std::cout << "列举1~" << fanwei << "之间的所有亲密数对!" << std::endl;
	for (i = 1; i < fanwei; i++) {
		b = friendnum(i);
		if (b != 0) {
			std::cout << std::endl << i << "的各个因子之和为:1";
			count = 1;
			while (ga[count] > 0) {
				std::cout << "+" << ga[count];
				count++;
			}
			std::cout << "=" << b << std::endl;
			std::cout << b << "的各个因子之和为:1";
			count = 1;
			while (gb[count] > 0) {
				std::cout << "+" << gb[count];
				count++;
			}
			std::cout << "=" << i << std::endl;
		}
	}
}