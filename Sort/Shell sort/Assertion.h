#pragma once
#include <iostream>
#include <random>
class Array
{
protected:
	/// @brief 数组
	int* arr;
	/// @brief 长度
	int length;
public:
	/// @brief 构造函数
	Array();
	/// @brief 析构函数
	~Array();
	/// @brief 显示内容
	void Show();
	/// @brief 希尔排序算法
	void Sort();
};
