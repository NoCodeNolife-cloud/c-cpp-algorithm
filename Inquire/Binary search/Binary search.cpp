#include <iostream>
#include <time.h>
#include <random>
using namespace std;

const int N = 15;

void QuickSort(int* arr, int left, int right) {
	int medium = arr[(left + right) / 2];
	int templeft = left;
	int tempright = right;
	while (templeft < tempright) {
		while (arr[templeft] < medium) {
			templeft++;
		}
		while (medium < arr[tempright]) {
			tempright--;
		}
		if (templeft < tempright) {
			int temp = arr[templeft];
			arr[templeft] = arr[tempright];
			arr[tempright] = temp;
			templeft++;
			tempright--;
		}
	}
	if (templeft == tempright) {
		templeft++;
	}
	if (left < tempright) {
		QuickSort(arr, left, templeft - 1);
	}
	if (templeft < right) {
		QuickSort(arr, tempright + 1, right);
	}
	return;
}

int SearchFun(int* a, int n, int x) {
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid] == x) {
			return mid;
		}
		else if (a[mid] > x) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
}

int main() {
	srand(time(NULL));
	int arr[N];
	for (int& x : arr) {
		x = rand() % 100;
	}
	QuickSort(arr, 0, N - 1);
	return 0;
}