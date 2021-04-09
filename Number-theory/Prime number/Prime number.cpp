/*
判断素数
*/
#include <iostream>
#include <iomanip>
/// @brief 素数
int isPrime(int a) {
	int i;
	for (i = 2; i < a; i++) {
		if (a % i == 0) {
			return 0;
		}
	}
	return 1;
}
void main() {
	int i, n, count;
	n = 1000;
	count = 0;
	std::cout << "列举1~1000之间所有的素数:" << std::endl;
	for (i = 1; i < 1000; i++) {
		if (isPrime(i) == 1) {
			std::cout << std::left << std::setw(10) << i;
			count++;
			if (count % 10 == 0) {
				std::cout << std::endl;
			}
		}
	}
	std::cout << std::endl;
}