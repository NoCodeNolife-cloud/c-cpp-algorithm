/*质因数*/
#include <iostream>
int isPrime(int a) {
	for (int i = 2; i < a; i++) {
		if (a % i == 0) {
			return 0;
		}
	}
	return 1;
}
void PrimeFactor(int n) {
	if (isPrime(n)) {
		std::cout << n << "*";
	}
	else {
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				std::cout << i << "*";/*第一个因数一定是质因数*/
				if (isPrime(n / i)) {
					std::cout << n / i;
					break;/*找到全部质因子*/
				}
				else {
					PrimeFactor(n / i);/*递归调用PrimeFactor分解n/i*/
				}
				break;
			}
		}
	}
}
void main() {
	int n;
	std::cout << "请首先输入一个数n:" << std::endl;
	std::cin >> n;
	std::cout << "n=" << n << "=";
	PrimeFactor(n);
	return;
}