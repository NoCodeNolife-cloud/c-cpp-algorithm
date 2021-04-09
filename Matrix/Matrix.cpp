/*
矩阵加减法
*/
#include "Matrix.h"
int main()
{
	double A[3][3] = { {1.0,2.0,3.0},{4.0,5.0,6.0},{7.0,8.0,9.0} };
	double B[3][3] = { {2.0,-2.0,1.0},{1.0,3.0,9.0},{17.0,-3.0,7.0} };
	Matrix matrix_one(A);
	Matrix matrix_two(B);
	/// @brief 加法测试
	/// @return
	std::cout << "加法" << std::endl;
	double C[3][3];
	Matrix matrix_three(C);
	matrix_three = matrix_one + matrix_two;
	matrix_one.Show();
	matrix_two.Show();
	matrix_three.Show();
	/// @brief 减法测试
	/// @return
	std::cout << "减法" << std::endl;
	matrix_three = matrix_one - matrix_two;
	matrix_one.Show();
	matrix_two.Show();
	matrix_three.Show();
	/// @brief 乘法测试
	/// @return
	std::cout << "乘法" << std::endl;
	matrix_three = matrix_one * matrix_two;
	matrix_one.Show();
	matrix_two.Show();
	matrix_three.Show();
	return 0;
}

Matrix::Matrix()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			str[i][j] = 0;
		}
	}
	return;
}

Matrix::Matrix(double paramstr[3][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			str[i][j] = paramstr[i][j];
		}
	}
	return;
}

Matrix Matrix::operator+(Matrix& paramMatrix)
{
	Matrix tempMatrix;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			tempMatrix.str[i][j] = this->str[i][j] + paramMatrix.str[i][j];
		}
	}
	return Matrix(tempMatrix);
}

Matrix Matrix::operator-(Matrix& paramMatrix)
{
	Matrix tempMatrix;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			tempMatrix.str[i][j] = this->str[i][j] - paramMatrix.str[i][j];
		}
	}
	return Matrix(tempMatrix);
}

Matrix Matrix::operator*(Matrix& paramMatrix)
{
	Matrix tempMatrix;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int t = 0; t < 3; t++) {
				tempMatrix.str[i][j] += this->str[i][t] * paramMatrix.str[t][j];
			}
		}
	}
	return Matrix(tempMatrix);
}

void Matrix::Show()
{
	std::cout.setf(std::ios_base::showpoint);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << str[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "---------------" << std::endl;
}

Matrix::~Matrix()
{
	return;
}