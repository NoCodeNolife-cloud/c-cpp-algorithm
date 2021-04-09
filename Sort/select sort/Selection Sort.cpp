#include "Assertion.h"
int main() {
	SelectionSort selectionsort;
	selectionsort.ShowArr();
	selectionsort.SortMaxToMin();
	selectionsort.ShowArr();
	selectionsort.SortMinToMax();
	selectionsort.ShowArr();
	return 0;
}