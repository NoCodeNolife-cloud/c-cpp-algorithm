#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int right_bound(vector<int> vec, int target) {
    int left = 0, right = vec.size() - 1;
    // 搜索区间为 [left, right]
    while (left <= right) {
        int mid = (right + left) / 2;
        if (vec[mid] < target) {
            // 搜索区间变为 [mid+1, right]
            left = mid + 1;
        } else if (vec[mid] > target) {
            // 搜索区间变为 [left, mid-1]
            right = mid - 1;
        } else if (vec[mid] == target) {
            // 收缩右侧边界
            left = mid + 1;
        }
    }
    // 检查出界情况
    if (right < 0 || vec[right] != target)
        return -1;
    return right;
}

ostream &operator<<(ostream &os, vector<int> vec) {
    for (int item: vec) {
        os << item << " ";
    }
    return os;
}

int main() {
    vector<int> vec = {9, 1, 7, 3, 5, 2, 8, 4, 6, 5, 5};
    sort(vec.begin(), vec.end());
    cout << vec << endl;
    cout << right_bound(vec, 5);
    return 0;
}
