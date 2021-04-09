#include "Assertion.h"

Array::Array()
{
	std::cout << "Enter the length of the array : ";
	std::cin >> length;
	arr = new int[length];
	srand(time(0));
	for (int i = 0; i < length; i++) {
		*(arr + i) = rand() % 101;
	}
	return;
}

Array::~Array()
{
	delete[]arr;
	return;
}

void Array::Show()
{
	for (int i = 0; i < length; i++) {
		std::cout << *(arr + i) << " ";
	}
	std::cout << std::endl;
	return;
}

void Array::Sort()
{
	for (int r = length / 2; r >= 1; r /= 2) {
		for (int i = r; i < length; i++) {
			int temp = *(arr + i);
			int j = i - r;
			while (j >= 0 && temp < *(arr + j)) {
				*(arr + j + r) = *(arr + j);
				j -= r;
			}
			*(arr + j + r) = temp;
		}
	}
	return;
}