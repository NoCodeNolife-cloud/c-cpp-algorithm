#include "Assertion.h"

SelectionSort::SelectionSort()
{
	int n;
	std::cout << "输入长度:";
	std::cin >> n;
	length = n;
	arr = new int[n];
	int i, j;
	std::cout << "输入数组值的范围"
		<< std::endl
		<< "最小值: ";
	std::cin >> i;
	std::cout << "最大值: ";
	std::cin >> j;
	for (int index = 0; index < n; index++) {
		*(arr + index) = rand() % (j - i + 1) + i;
	}
	return;
}

SelectionSort::~SelectionSort()
{
	delete[]arr;
	return;
}

void SelectionSort::SortMaxToMin()
{
	int maxIndex, temp;
	for (int i = 0; i < length; i++) {
		maxIndex = i;
		for (int j = i + 1; j < length; j++) {
			if (arr[j] > arr[maxIndex]) {
				maxIndex = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[maxIndex];
		arr[maxIndex] = temp;
	}
	return;
}

void SelectionSort::SortMinToMax()
{
	int minIndex, temp;
	for (int i = 0; i < length - 1; i++) {
		minIndex = i;
		for (int j = i + 1; j < length; j++) {
			if (arr[j] < arr[minIndex]) {     // 寻找最小的数
				minIndex = j;                 // 将最小数的索引保存
			}
		}
		temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
	return;
}

void SelectionSort::ShowArr()
{
	for (int index = 0; index < length; index++) {
		std::cout << arr[index] << " ";
	}
	std::cout << std::endl;
	return;
}