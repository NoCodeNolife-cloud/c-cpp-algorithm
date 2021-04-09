#pragma once
#include <iostream>

class SelectionSort
{
protected:
	int* arr;
	int length;
public:

	/// <summary>
	/// 构造函数
	/// </summary>
	SelectionSort();
	~SelectionSort();

	/// <summary>
	/// 从大到小排序
	/// </summary>
	void SortMaxToMin();

	/// <summary>
	/// 从小到大排序
	/// </summary>
	void SortMinToMax();

	/// <summary>
	/// 显示数组
	/// </summary>
	void ShowArr();
};
