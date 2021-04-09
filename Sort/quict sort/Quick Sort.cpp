#include <iostream>
#include <fstream>
#include <time.h>
#include "Function.h"
#define SIZE 18
using namespace std;

int main() {
	fstream out("out.txt", ios::app);
	if (!out.is_open()) {
		exit(EXIT_FAILURE);
	}
	int i;
	int shuzu[SIZE];
	srand(time(NULL));
	for (i = 0; i < SIZE; i++) {
		shuzu[i] = rand() / 1000 + 100;
	}
	out << "排序前:" << endl;
	for (i = 0; i < SIZE; i++) {
		out << shuzu[i] << "  ";
	}
	out << endl;
	QuickSort(shuzu, 0, SIZE - 1);
	out << "排序后:" << endl;
	for (i = 0; i < SIZE; i++) {
		out << shuzu[i] << "  ";
	}
	out << endl;
	return 0;
}