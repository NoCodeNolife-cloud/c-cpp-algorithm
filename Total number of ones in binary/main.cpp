#include <iostream>

using namespace std;

/**
 * 统计整数n的二进制展开中位数位1的总数
 * @return
 */
int countOnes(unsigned int);

int main() {
    cout << "input:";
    int num;
    cin >> num;
    cout << countOnes(num) << endl;
    return 0;
}

int countOnes(unsigned int n) {
    int ones = 0;/*计数器复位*/
    while (n > 0) {/*在n缩减至0之前*/
        ones += (1 & n);/*检查最低位,若为1则计数*/
        n >>= 1;/*右移一位*/
    }
    return ones;/*返回计数*/
}
