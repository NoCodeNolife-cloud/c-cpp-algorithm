#include <iostream>
#include <stack>

using namespace std;

/**
 * 删除表达式exp[lo,hi]不含括号的最长前缀、后缀
 * @param exp
 * @param lo
 * @param hi
 */
void trim(const char exp[], int &lo, int &hi);

/**
 * 切分表达式exp[lo,hi],使exp匹配仅当它们匹配
 * @param exp
 * @param lo
 * @param hi
 * @return
 */
int divide(const char exp[], int lo, int hi);

/**
 * 检查表达式exp[lo,hi]是否括号匹配(递归版)
 * @param exp
 * @param lo
 * @param hi
 * @return
 */
bool paren(const char exp[], int lo, int hi);

int main() {
    char exp[] = {'(', '(', ')', '(', ')', ')'};
    cout << boolalpha << paren(exp, 0, 6);
    return 0;
}

void trim(const char *exp, int &lo, int &hi) {
    while ((lo <= hi) && (exp[lo] != '(') && (exp[lo] != ')')) {/*查找第一个括号*/
        lo++;
    }
    while ((lo <= hi) && (exp[hi] != '(') && (exp[hi] != ')')) {/*查找最后一个括号*/
        hi--;
    }
}

int divide(const char *exp, int lo, int hi) {
    int mi = lo;/*crc为[lo,mi]范围内左右括号数目之差*/
    int crc = 1;
    while ((0 < crc) && (++mi < hi)) {/*逐个检查各字符,直到左右括号数目相等,或者越界*/
        if (exp[mi] == ')') {/*左右括号分别计数*/
            crc--;
        }
        if (exp[mi] == '(') {
            crc++;
        }
    }
    return mi;/*若mi<=hi,则为合法切分点;否则,意味着局部不可能匹配*/
}

bool paren(const char *exp, int lo, int hi) {
    trim(exp, lo, hi);
    if (lo > hi) {/*首字符非左括号,则必不匹配*/
        return true;
    }
    if (exp[lo] != '(') {
        return false;
    }
    if (exp[hi] != ')') {
        return false;
    }
    int mi = divide(exp, lo, hi);/*确定适当的切分点*/
    if (mi > hi) {
        return false;
    }
    return paren(exp, lo + 1, mi - 1) && paren(exp, mi + 1, hi);/*分别检查左右子表达式*/
}
