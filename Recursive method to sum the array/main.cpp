#include <iostream>

using namespace std;

/**
 * 数组求和算法
 * @return
 */
int sum(int[], int);

int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << sum(A, 9) << std::endl;
    return 0;
}

int sum(int A[], int n) {
    if (1 > n) {/*平凡情况,递归基*/
        return 0;/*直接计算*/
    } else {/*一般情况*/
        return sum(A, n - 1) + A[n - 1];/*递归:前n-1项之和,再累计第n-1项*/
    }/*递归深度=O(1)*(n+1)+A[n-1]*/
}