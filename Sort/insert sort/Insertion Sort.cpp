#include "Assertion.h"
int main() {
	Array<int> array;
	std::cout << "初始值为:" << std::endl;
	array.Show();
	array.InsertionSort();
	std::cout << "最终值为:" << std::endl;
	array.Show();
	return 0;
}