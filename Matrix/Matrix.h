#pragma once
#include <iostream>
class Matrix
{
protected:
	double str[3][3];
public:
	/// @brief 默认构造函数
	Matrix();
	/// @brief 设置矩阵
	Matrix(double paramstr[3][3]);
	/// @brief 矩阵加法
	Matrix operator+(Matrix& paramMatrix);
	/// @brief 矩阵减法
	Matrix operator-(Matrix& paramMatrix);
	/// @brief 矩阵乘法
	Matrix operator*(Matrix& paramMatrix);
	/// @brief 显示矩阵
	void Show();
	~Matrix();
};
