/*数字积分算法
1)首先定义一个精度eps,将积分区间一等分,按照梯形规则计算结果
2)将每个求积分区间再进行二等分,再次按照梯形规则计算结果
3)比较二等分前后两次积分结果的差,如果差值小于精度eps,则输出最后结果*/
#include <iostream>
#include <stdio.h>
#include <math.h>
double func(double x) {//函数定义
	double y;
	y = x * exp(-x * x);//函数表达式
	return y;
}
double jifen(double x1, double x2, double eps) {//算法
	int i, n;
	double fx1, fx2, h, t1, p, s, x;
	double result;
	fx1 = func(x1);//上限
	fx2 = func(x2);//下限
	n = 1;
	h = x2 - x1;//一等分
	t1 = h * (fx1 + fx2) / 2.0;
	p = eps + 1.0;
	while (p >= eps) {//循环判断是否达到精度
		s = 0.0;
		for (i = 0; i < n; i++) {//n等分
			x = x1 + i * h + 0.5 * h;
			s += func(x);
		}
		result = (t1 + h * s) / 2.0;//计算结果
		n = 2 * n;//1等分,2等分,3等分,......,n等分
		t1 = result;
		h = h / 2.0;
		p = fabs(t1 - result);//差值
	}
	return result;
}
void main() {
	char again;
	double x1, x2, eps, t;
	std::cout << "求解定积分算法演示:" << std::endl;
	std::cout << "输入定积分的区间:";
	std::cin >> x1 >> x2;
	std::cout << "输入精度:";
	std::cin >> eps;
	t = jifen(x1, x2, eps);
	std::cout << "计算结果=" << t;
	return;
}