#include <iostream>
#include <stdio.h>
#include <math.h>
double Chebxshev[11] = { 0.0000677106,-0.0003442342,0.0015397681,-0.0024467480,0.0109736958,-0.0002109075,0.0742379071,0.0815782188,0.4118402518,0.4227843370,1.0 };//Chebxshev多项式
double gamma(double x) {
	int i;
	double t, u;
	double result;
	if (x <= 0.0) {//输入错误,x的值不能小于0
		std::cout << "输入错误,x的值不能小于0!" << std::endl;
		return -1.0;
	}
	if (x <= 1.0) {
		t = 1.0 / (x * (x + 1.0));
		x += 2.0;
	}
	else if (x <= 2.0) {
		t = 1.0 / x;
		x += 1.0;
	}
	else if (x <= 3.0) {
		t = 1.0;
	}
	else {
		t = 1.0;
		while (x > 3.0) {
			x -= 1.0;
			t = t * x;
		}
	}
	result = Chebxshev[0];
	u = x - 2.0;
	for (i = 1; i <= 10; i++) {
		result = result * u + Chebxshev[i];
	}
	result *= t;
	return result;
}
void main() {
	double x, y;
	std::cout << "求伽马函数算法演示!" << std::endl;
	std::cout << "输入一个x值:";
	std::cin >> x;
	y = gamma(x);
	std::cout << "当x=" << x << "时,伽玛函数的值为" << y << std::endl;
	return;
}