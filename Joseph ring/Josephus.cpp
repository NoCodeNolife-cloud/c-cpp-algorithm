#include <iostream>
#include <fstream>
#include "Function.h"
using namespace std;

int main()
{
	fstream out("out.txt", ios::app);
	if (!out.is_open()) {
		exit(EXIT_FAILURE);
	}
	int alive;
	cout << "约瑟夫环问题求解!" << endl;
	out << "约瑟夫环问题求解!" << endl;
	cout << "输入需要留存的人的数量:";
	cin >> alive;
	Josephus(alive);
	return 0;
}