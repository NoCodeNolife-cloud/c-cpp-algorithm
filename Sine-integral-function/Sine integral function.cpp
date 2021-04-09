#include <iostream>
#include <stdio.h>
#include <cmath>
double t[5] = { -0.9061798459,-0.5384693101,0.0,0.5384693101,0.9061798459 };
double c[5] = { 0.2369268851,0.4786286705,0.5688888889,0.4786286705,0.2369268851 };
double SIFunc(double x, double eps) {
	int i, j;
	double s, h, w;
	double atemp, btemp, xtemp;
	double result;
	double p = 1.0e35;
	double temp = 0.1;
	int m = 1;
	if (x == 0) {
		result = 0.0;
		return result;
	}
	h = fabs(x);
	s = fabs(0.0001 * h);
	while ((temp >= eps) && (fabs(h) > s)) {
		result = 0.0;
		for (i = 1; i <= m; i++) {
			atemp = (i - 1.0) * h;
			btemp = i * h;
			w = 0.0;
			for (j = 0; j < 5; j++) {
				xtemp = ((btemp - atemp) * t[j] + (btemp + atemp)) / 2.0;
				w += sin(xtemp) / xtemp * c[j];
			}
			result += w;
		}
		result = result * h / 2.0;
		temp = fabs(result - p) / (1.0 + fabs(result));
		p = result;
		m++;
		h = fabs(x) / m;
	}
	return result;
}
void main() {
	using namespace std;
	std::cout << "求正弦积分函数算法示例:" << std::endl;
	std::cout << "输入x值:";
	double x;
	cin >> x;
	cout << "输入精度:";
	double eps;
	cin >> eps;
	double y;
	y = SIFunc(x, eps);
	cout << "当x=" << x << "的时候,正弦积分函数的值为" << y << endl;
	return;
}