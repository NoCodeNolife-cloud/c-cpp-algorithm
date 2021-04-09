/*
水仙花数指一个n位正整数,它的每个位上的数字的n次方幂之和等于它本身
*/
#include <iostream>
#include <cmath>
/// @brief 生成水仙花数算法
/// @param n 位数
void NarcissusNum(int n) {
	long i, start, end, temp, num, sum;
	int j;
	start = (long)pow(10, n - 1);//起始数据
	end = (long)pow(10, n) - 1;//终止数据
	for (i = start; i <= end; i++) {
		temp = 0;
		num = i;
		sum = 0;
		for (j = 0; j < n; j++) {
			temp = num % 10;
			sum = sum + (long)pow(temp, n);
			num = (num - temp) / 10;
		}
		if (sum == i) {
			std::cout << i << std::endl;
		}
	}
}
void main() {
	int n;
	/// @brief 3位的水仙花数
	n = 3;
	std::cout << "列举" << n << "位的水仙花数: " << std::endl;
	NarcissusNum(n);
	std::cout << std::endl;
	/// @brief 4位的水仙花数
	n = 4;
	std::cout << "列举" << n << "位的水仙花数: " << std::endl;
	NarcissusNum(n);
	std::cout << std::endl;
	return;
}