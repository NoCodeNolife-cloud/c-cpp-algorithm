#pragma once
#include <iostream>
#include <random>
class Array
{
protected:
	/// @brief ����
	int* arr;
	/// @brief ����
	int length;
public:
	/// @brief ���캯��
	Array();
	/// @brief ��������
	~Array();
	/// @brief ��ʾ����
	void Show();
	/// @brief ϣ�������㷨
	void Sort();
};
