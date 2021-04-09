#pragma once

void QuickSort(int* arr, int left, int right);

void QuickSort(int* arr, int left, int right) {
	int f, t;
	int rtemp, ltemp;
	ltemp = left;
	rtemp = right;
	f = arr[(left + right) / 2];
	while (ltemp < rtemp) {
		while (arr[ltemp] < f) {
			++ltemp;
		}
		while (arr[rtemp] > f) {
			--rtemp;
		}
		if (ltemp <= rtemp) {
			t = arr[ltemp];
			arr[ltemp] = arr[rtemp];
			arr[rtemp] = t;
			--rtemp;
			++ltemp;
		}
	}
	if (ltemp == rtemp) {
		ltemp++;
	}
	if (left < rtemp) {
		QuickSort(arr, left, ltemp - 1);
	}
	if (ltemp < right) {
		QuickSort(arr, rtemp + 1, right);
	}
	return;
}