#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * 十进制数n刡base进制的转换（递归版）
 * @param S
 * @param n
 * @param base
 */
void convert(stack<char> &S, __int64 n, int base);

/**
 * 十进制数n到base进制的转换（迭代版）
 * @param S
 * @param n
 * @param base
 */
void convert2(stack<char> &S, __int64 n, int base);

int main() {
    stack<char> S;
    __int64 n = 25;
    int base = 2;
    convert(S, n, base);
    string str;
    while (S.size() != 0) {
        str += S.top();
        S.pop();
    }
    reverse(str.begin(), str.end());
    cout << str << endl;
    return 0;
}

void convert(stack<char> &S, __int64 n, int base) {
    static char digit[] //0 < n, 1 < base <= 16，新迕刢下癿数位符号，可视base取值范围适当扩充
            = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    if (0 < n) { //在尚有余数之前，不断
        convert(S, n / base, base); //通过递归得到所有更高位
        S.push(digit[n % base]); //输出低位
    }
} //新进制下由高到低的各数位，自顶而下保存于栈S中

void convert2(stack<char> &S, __int64 n, int base) {
    static char digit[] //0 < n, 1 < base <= 16，新进制下的数位符号，可视base取值范围适当扩充
            = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (n > 0) { //由低到高，逐一计算出新进制下的各数位
        int remainder = (int) (n % base);
        S.push(digit[remainder]); //余数（当前位）入栈
        n /= base; //n更新为其对base的除商
    }
} //新进制下由高到低的各数位，自顶而下保存于栈S中
