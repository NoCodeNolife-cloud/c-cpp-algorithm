#pragma once
#include <iostream>

class SelectionSort
{
protected:
	int* arr;
	int length;
public:

	/// <summary>
	/// ���캯��
	/// </summary>
	SelectionSort();
	~SelectionSort();

	/// <summary>
	/// �Ӵ�С����
	/// </summary>
	void SortMaxToMin();

	/// <summary>
	/// ��С��������
	/// </summary>
	void SortMinToMax();

	/// <summary>
	/// ��ʾ����
	/// </summary>
	void ShowArr();
};
