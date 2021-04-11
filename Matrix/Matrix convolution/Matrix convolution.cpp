#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(char argc, char* argv[]) {
	srand(time(0));
	vector<vector<int>> matrixshell(3, vector<int>(3, 0));
	cout << "matrixshell\n";
	for (vector<int>& x : matrixshell) {
		for (int& y : x) {
			y = rand() % 100 - 50;
			cout << setw(7) << left << y;
		}
		cout << endl;
	}
	int length, width;
	cout << "length = ";
	cin >> length;
	cout << "width = ";
	cin >> width;
	vector<vector<int>>matirx(length + 2, vector<int>(width + 2, 0));
	cout << "matirx\n";
	for (int i = 1; i < length + 1; i++) {
		for (int j = 1; j < width + 1; j++) {
			matirx[i][j] = rand() % 100 - 50;
			cout << setw(7) << left << matirx[i][j];
		}
		cout << endl;
	}
	cout << "result\n";
	vector<vector<int>>res(length, vector<int>(width, 0));
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			res[i][j] = matrixshell[0][0] * matirx[i][j] + matrixshell[1][0] * matirx[i + 1][j] + matrixshell[2][0] * matirx[i + 2][j] + matrixshell[0][1] * matirx[i][j + 1] + matrixshell[1][1] * matirx[i + 1][j + 1] + matrixshell[2][1] * matirx[i + 2][j + 1] + matrixshell[0][2] * matirx[i][j + 2] + matrixshell[1][2] * matirx[i + 1][j + 2] + matrixshell[2][2] * matirx[i + 2][j + 2];
			cout << setw(7) << left << res[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}