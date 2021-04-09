#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <random>
#include <time.h>
#include <iomanip>
using namespace std;
class Function {
public:
	void bubbleSort(vector<int>& vec) {
		int size = vec.size();
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size - 1 - i; ++j) {
				if (vec[j] < vec[j + 1]) {
					swap(vec[j], vec[j + 1]);
				}
			}
		}
		return;
	}
	void insertSort(vector<int>& vec) {
		int size = vec.size();
		for (int i = 1; i < size; i++) {
			int temp = vec[i];
			int j = i - 1;
			while (j >= 0 and vec[j] > temp) {
				vec[j + 1] = vec[j];
				j--;
			}
			vec[j + 1] = temp;
		}
		return;
	}
	void selectSort(vector<int>& vec) {
		int size = vec.size();
		for (int i = 0; i < size; i++) {
			int maxindex = i;
			for (int j = i + 1; j < size; j++) {
				if (vec[maxindex] < vec[j]) {
					maxindex = j;
				}
			}
			swap(vec[maxindex], vec[i]);
		}
		return;
	}
	void quickSort(vector<int>& vec) {
		quickSort(vec, 0, vec.size() - 1);
	}
	void showData(vector<int>& vec) {
		vector<int>::iterator iter;
		for (iter = vec.begin(); iter != vec.end(); iter++) {
			cout << setw(4) << left << *iter;
		}
		return;
	}
	void initialVector(vector<int>& vec) {
		vector<int>::iterator iter;
		for (iter = vec.begin(); iter != vec.end(); iter++) {
			*iter = rand() % 100;
		}
		return;
	}
private:
	void quickSort(vector<int>& vec, int a, int b) {
		int middle = vec[(a + b) / 2];
		int ta = a, tb = b;
		while (ta < tb) {
			while (vec[ta] < middle) {
				ta++;
			}
			while (middle < vec[tb]) {
				tb--;
			}
			if (ta < tb) {
				swap(vec[ta], vec[tb]);
				ta++;
				tb--;
			}
		}
		if (ta == tb) {
			ta++;
		}
		if (ta < b) {
			quickSort(vec, tb + 1, b);
		}
		if (a < tb) {
			quickSort(vec, a, ta - 1);
		}
		return;
	}
};
int main()
{
	srand(time(NULL));
	vector<int>vec(10);
	Function function;
	function.initialVector(vec);
	function.quickSort(vec);
	function.showData(vec);
	cout << "\ntime: " << double(clock()) / CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
}