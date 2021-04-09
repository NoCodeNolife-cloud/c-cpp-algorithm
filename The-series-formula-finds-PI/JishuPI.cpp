#include <stdio.h>
#include <stdlib.h>
#include <iostream>
double JishuPI() {
	double PI = 2, temp = 2;
	int n = 1, m = 3;
	while (temp > 1e-15) {
		temp = temp * n / m;
		PI += temp;
		n++;
		m += 2;
	}
	return PI;
}
void main() {
	std::cout << "PI = " << JishuPI();
	return;
}