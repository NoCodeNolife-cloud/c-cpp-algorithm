#pragma once
#include <iostream>
class Matrix
{
protected:
	double str[3][3];
public:
	/// @brief Ĭ�Ϲ��캯��
	Matrix();
	/// @brief ���þ���
	Matrix(double paramstr[3][3]);
	/// @brief ����ӷ�
	Matrix operator+(Matrix& paramMatrix);
	/// @brief �������
	Matrix operator-(Matrix& paramMatrix);
	/// @brief ����˷�
	Matrix operator*(Matrix& paramMatrix);
	/// @brief ��ʾ����
	void Show();
	~Matrix();
};
