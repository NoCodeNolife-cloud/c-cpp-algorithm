#include <iostream>
#include <random>
void sort(int para_a[], int para_maxsize) {
	for (int i = 0; i < para_maxsize; i++) {
		for (int j = 0; j < para_maxsize - 1 - i; j++) {
			if (para_a[j] > para_a[j + 1]) {
				int temp_a = para_a[j];
				para_a[j] = para_a[j + 1];
				para_a[j + 1] = temp_a;
			}
		}
	}
	return;
}//排序算法
void init_array(int para_a[], int para_maxsize) {
	srand(time(0));
	for (int i = 0; i < para_maxsize; i++) {
		para_a[i] = rand() % 1000;
	}
	return;
}//数组初始化
void show_array(int para_a[], int para_maxsize) {
	using namespace std;
	for (int i = 0; i < para_maxsize; i++) {
		cout << para_a[i] << " ";
	}
	return;
}//打印数据
void main() {
	using namespace std;
	const int maxsize = 10;
	int a[maxsize];
	init_array(a, maxsize);
	sort(a, maxsize);
	show_array(a, maxsize);
	return;
}