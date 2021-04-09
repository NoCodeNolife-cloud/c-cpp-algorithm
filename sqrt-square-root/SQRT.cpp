/*开平方算法
近似值:xn-1=(xn+a/xn)/2≈a的二次方根
1>选定一个迭代初始值x0,将其代入前述的迭代公式求解出x1
2>计算x1-x0的绝对值,如果其小于指定的精度,则退出,否则继续迭代
3>将xk代入前述的迭代公式,求解出xk-1,继续判断xk+1-xk的绝对值,如果其小于指定的精度,则退出,否则继续迭代*/
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
double SQRT(double x, double eps) {//算法
	double result, t;
	t = 0.0;
	result = x;
	while (fabs(result - t) > eps) {//迭代计算
		t = result;
		result = 0.5 * (t + x / t);
	}
	return result;//返回结果
}
void main() {
	char again;
	double x, eps, t;
	std::cout << "求解开平方算法演示:" << std::endl;
	std::cout << "输入一个数字:";
	std::cin >> x;
	std::cout << "输入精度:";
	std::cin >> eps;
	t = SQRT(x, eps);
	std::cout << "计算结果=" << t << std::endl;
	return;
}