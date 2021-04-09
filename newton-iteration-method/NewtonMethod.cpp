/*
牛顿迭代法
x_{n+1}=x_n-\frac{f(x_n)}{f'(x_n)}
*/
#include <iostream>
#include <cmath>
double func(double x) {
	return x * x * x * x - 3 * x * x * x + 1.5 * x * x - 4.0;
}
double dfunc(double x) {
	return 4 * x * x * x - 9 * x * x + 3 * x;
}
int NewtonMethod(double* x, int maxcyc, double precision) {
	double x0, x1;
	int i;
	x0 = *x;
	i = 0;
	while (i < maxcyc) {
		if (dfunc(x0) == 0.0) {
			std::cout << "迭代过程中导数为0!" << std::endl;
			return 0;
		}
		x1 = x0 - func(x0) / dfunc(x0);//x_{n+1}=x_n-\frac{f(x_n)}{f'(x_n)}
		if (fabs(x1 - x0) < precision || fabs(func(x1)) < precision) {
			*x = x1;
			return 1;
		}
		else {
			x0 = x1;
		}
		i++;
	}
	std::cout << "迭代次数超过预设值!仍没有达到精度!" << std::endl;
	return 0;
}
void main() {
	double x, precision;
	int maxcyc, result;
	x = 2.0;
	maxcyc = 1000;
	precision = 0.00001;
	result = NewtonMethod(&x, maxcyc, precision);
	if (result == 1) {
		std::cout << "方程x*x*x*x-3*x*x*x+1.5*x*x-4.0=0" << std::endl;
		std::cout.precision(10);
		std::cout << "在2.0附近的根为:" << x;
	}
	else {
		std::cout << "迭代失败!" << std::endl;
	}
	return;
}