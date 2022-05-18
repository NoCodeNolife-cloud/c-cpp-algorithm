#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void prev_permutation(std::vector<int> &vec) {
    int left = vec.size() - 1;
    while (left > 0 && vec[left - 1] < vec[left]) {
        --left;
    }
    if (left != 0) {
        --left;
        int right = vec.size() - 1;
        while (vec[left] <= vec[right]) {
            --right;
        }
        std::swap(*(vec.begin() + left), *(vec.begin() + right));
        std::reverse(vec.begin() + left + 1, vec.end());
    } else {
        std::reverse(vec.begin(), vec.end());
    }
}

int main() {
    std::vector<int> vec = {6, 8, 7, 4, 3, 2};
    prev_permutation(vec);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}
