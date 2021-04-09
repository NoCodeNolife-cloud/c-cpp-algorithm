#pragma once
#include <iostream>
#include <random>
template<typename T>
class Array
{
protected:
	T* data;
	int length;
public:

	/// @brief 构造函数
	Array();

	/// @brief 显示
	void Show();

	/// @brief 插入排序算法
	void InsertionSort();

	~Array();
};

template<typename T>
inline Array<T>::Array()
{
	std::cout << "Enter the length of the array : ";
	std::cin >> length;
	std::cout << "Enter the scope of the array : ";
	int max, min;
	std::cout << "min = ";
	std::cin >> min;
	std::cout << "max = ";
	std::cin >> max;
	data = new T[length];
	srand(time(0));
	for (int index = 0; index < length; index++) {
		*(data + index) = rand() % (max - min + 1) + min;
	}
	return;
}

template<typename T>
inline void Array<T>::Show()
{
	for (int index = 0; index < length; index++) {
		std::cout << *(data + index) << " ";
	}
	std::cout << std::endl;
	return;
}

template<typename T>
inline void Array<T>::InsertionSort()
{
	for (int i = 1; i < length; i++) {
		T temp = *(data + i);
		int j = i - 1;
		while (j >= 0 && temp < *(data + j)) {
			*(data + j + 1) = *(data + j);
			j--;
		}
		*(data + j + 1) = temp;
		std::cout << "第" << i + 1 << "轮排序:" << std::endl;
		Show();
	}
}

template<typename T>
inline Array<T>::~Array()
{
	/// @brief 为构造函数分配的内存进行释放
	delete[] data;
	return;
}