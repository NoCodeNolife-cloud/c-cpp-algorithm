/*
二分法
*/
#include <iostream>
#include <stdio.h>
#include <math.h>
double func(double x) {
	return 2 * x * x * x - 5 * x - 1;
}
double erfen(double a, double b, double err) {
	double c = (a + b) / 2.0;
	while (fabs(func(c)) > err && func(a - b) > err) {
		if (func(c) * func(b) < 0) {
			a = c;
		}if (func(a) * func(c) < 0) {
			b = c;
		}
		c = (a + b) / 2;
	}
	return c;
}
void main() {
	double a = 1.0, b = 2.0;
	double err = 1e-5;
	double result;
	result = erfen(a, b, err);
	std::cout << "二分法解方程: 2 * x * x * x - 5 * x - 1" << std::endl;
	std::cout << "结果x=" << result << std::endl;
	return;
}