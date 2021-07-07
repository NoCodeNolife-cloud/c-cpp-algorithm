#include <iostream>
#include <algorithm>
#include <iomanip>

const int LENGTH = 10;

using namespace std;

void bubblesort1A(int[], int);

int main() {
    srand(time(NULL));
    int B[LENGTH];/*declare the array*/
    for (int i = 0; i < LENGTH; ++i) {/*random the array*/
        B[i] = rand() % 100;
    }
    bubblesort1A(B, LENGTH);/*bubble sort*/

//    print the item of B
    for (int item:B) {
        cout << setw(5) << left << item;
    }

    return 0;
}

void bubblesort1A(int A[], int n) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 1; i < n; ++i) {
            if (A[i - 1] > A[i]) {
                swap(A[i - 1], A[i]);
                sorted = false;
            }
        }
        n--;
    }
}
