/*
高斯消元法:线性方程组求解

*/
#include <stdio.h>
#include <math.h>
#include <iostream>
#define  MaxNum 10
int array[MaxNum][MaxNum] = { {3,5,-4,0},{7,2,6,-4},{4,-1,5,-5} };
int unuse_result[MaxNum];
int GaussFun(int equ, int var, int result[]) {
	int i, j, k, col = 0, num1, num2, max_r, ta, tb, gcdtemp, lcmtemp, temp, unuse_x_num, unuse_index;
	for (k = 0; k < equ && col < var; k++, col++) {
		max_r = k;
		for (i = k + 1; i < equ; i++) {
			if (abs(array[i][col] > abs(array[max_r][col]))) {
				max_r = i;
			}
		}
		if (max_r != k) {
			for (j = k; j < var + 1; j++) {
				temp = array[k][j];
				array[k][j] = array[max_r][j];
				array[max_r][j] = temp;
			}
		}
		if (array[k][col] == 0) {
			k--;
			continue;
		}
		for (i = k + 1; i < equ; i++) {
			if (array[i][col] != 0) {
				num1 = abs(array[i][col]);
				num2 = abs(array[k][col]);
				while (num2 != 0) {
					temp = num2;
					num2 = num1 % num2;
					num1 = temp;
				}
				gcdtemp = num1;
				lcmtemp = (abs(array[i][col]) * abs(array[k][col]));
				ta = lcmtemp / abs(array[i][col]);
				tb = lcmtemp / abs(array[k][col]);
				if (array[i][col] * array[k][col] < 0) {
					tb = -tb;
				}
				for (j = col; j < var + 1; j++) {
					array[i][j] = array[i][j] * ta - array[k][j] * tb;
				}
			}
		}
	}
	for (i = k; i < equ; i++) {
		if (array[i][col] != 0) {
			return -1;
		}
	}
	if (k < var) {
		for (i = k - 1; i >= 0; i--) {
			unuse_x_num = 0;
			for (j = 0; j < var; j++) {
				if (array[i][j] != 0 && unuse_result[j]) {
					unuse_x_num++;
					unuse_index = j;
				}
			}
			if (unuse_x_num > 1) {
				continue;
			}
			temp = array[i][var];
			for (j = 0; j < var; j++) {
				if (array[i][j] != 0 && j != unuse_index) {
					temp -= array[i][j] * result[j];
				}
			}
			result[unuse_index] = temp / array[i][unuse_index];
			unuse_result[unuse_index] = 0;
		}
		return var - k;
	}
	for (i = var - 1; i >= 0; i--) {
		temp = array[i][var];
		for (j = i + 1; j < var; j++) {
			if (array[i][j] != 0) {
				temp -= array[i][j] * result[j];
			}
		}
		if (temp % array[i][i] != 0) {
			return -2;
		}
		result[i] = temp / array[i][i];
	}
	return 0;
}
void main() {
	int i, type;
	int equnum = 3, varnum = 3;
	int result[MaxNum];
	type = GaussFun(equnum, varnum, result);
	if (type == -1) {
		std::cout << "该方程无解!" << std::endl;
	}
	else if (type == -2) {
		std::cout << "该方程有浮点数解,无整数解!" << std::endl;
	}
	else if (type > 0) {
		std::cout << "该方程有无穷多解!自由变量数量为" << type << std::endl;
		for (i = 0; i < varnum; i++) {
			if (unuse_result[i]) {
				std::cout << "x" << i + 1 << "是不确定的" << std::endl;
			}
			else {
				std::cout << "x" << i + 1 << ": " << result[i] << std::endl;
			}
		}
	}
	else {
		std::cout << "该方程组的解为:" << std::endl;
		for (i = 0; i < varnum; i++) {
			std::cout << "x" << i + 1 << "=" << result[i] << std::endl;
		}
	}
}