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

	/// @brief ���캯��
	Array();

	/// @brief ��ʾ
	void Show();

	/// @brief ���������㷨
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
		std::cout << "��" << i + 1 << "������:" << std::endl;
		Show();
	}
}

template<typename T>
inline Array<T>::~Array()
{
	/// @brief Ϊ���캯��������ڴ�����ͷ�
	delete[] data;
	return;
}