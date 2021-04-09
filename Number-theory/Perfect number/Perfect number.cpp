/*
完全数:
1.当一个自然数的所有真因子的和小于该自然数,那么该自然数便是亏数
2.当一个自然数的所有真因子的和大于该自然数,那么该自然数便是盈数
3.当一个自然数的所有真因子的和大于该自然数,那么该自然数便是完全数
*/
#include <iostream>
void Perfectnum(long fanwei) {
	long p[300];
	long i, j, k, sum, num, count;
	for (i = 1; i < fanwei; i++) {
		count = 0;
		num = i;
		sum = num;
		for (j = 1; j < num; j++) {
			if (num % j == 0) {
				p[count++] = j;
				sum = sum - j;
			}
		}
		if (sum == 0) {
			std::cout << num << "是一个完全数,因子是" << num << "=" << p[0];
			for (k = 1; k < count; k++) {
				std::cout << "+" << p[k];
			}
			std::cout << std::endl;
		}
	}
}
void main() {
	long fanwei;
	fanwei = 10000;
	std::cout << "查找" << fanwei << "之内的完全数:" << std::endl;
	Perfectnum(fanwei);
	return;
}