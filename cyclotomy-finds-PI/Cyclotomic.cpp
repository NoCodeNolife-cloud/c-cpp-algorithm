#include <iostream>
#include <cmath>
void cyclotomic(int n) {
	int i = 0, s = 6;;
	double k = 3.0, len = 1.0;
	while (i <= n) {
		std::cout << "第" << i << "次切割,为正" << s << "变形,PI = " << k * sqrt(len) << std::endl;
		s *= 2;
		len = 2 - sqrt(4 - len);
		i++;
		k *= 2.0;
	}
}
void main() {
	int n;
	std::cout << "输入切割次数:";
	std::cin >> n;
	cyclotomic(n);
}