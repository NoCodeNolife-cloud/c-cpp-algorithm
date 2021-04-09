/*
自守数:如果一个正整数的平方的末尾几位数等于这个数本身,那么这个数便称为自守数
*/
#include <iostream>
int zishounum(long n) {
	long temp, m, k;
	int count;
	k = 1;
	count = 0;
	while (k > 0) {
		k = n - (long)pow(10, count);
		count++;
	}
	m = count - 1;
	temp = (n * n) % ((long)(pow(10, m)));
	if (temp == n) {
		return 1;
	}
	else {
		return 0;
	}
}
void main() {
	long i;
	std::cout << "自守数:" << std::endl;
	for (i = 2; i < 1000; i++) {
		if (zishounum(i) == 1) {
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}