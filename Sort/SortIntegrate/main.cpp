#include <iostream>
#include <vector>
#include <random>
#include <iterator>

class RAND {
public:
    int operator()() const {
        std::seed_seq seedSeq{time(nullptr)};
        static std::default_random_engine defaultRandomEngine(seedSeq);
        std::uniform_int_distribution<int> uniformIntDistribution(0, 100);
        return uniformIntDistribution(defaultRandomEngine);
    }
};

template<typename T>
class Sort {
private:
    static void merge(std::vector<T> &vec, int begin, int mid, int end) {
        int left = begin, right = mid;
        std::vector<T> temp;
        temp.reserve(end - begin + 1);
        while (left < mid && right < end) {
            (vec.at(left) < vec.at(right)) ? temp.push_back(vec.at(left++)) : temp.push_back(vec.at(right++));
        }
        while (left < mid) {
            temp.push_back(vec.at(left++));
        }
        while (right < end) {
            temp.push_back(vec.at(right++));
        }
        size_t len = temp.size();
        for (int i = 0; i < len; i++) {
            vec.at(begin + i) = temp.at(i);
        }
    }

    static void quickSort(std::vector<T> &vec, int left, int right) {
        int tLeft = left, tRight = right;
        int middle = vec[(left + right) / 2];
        while (tLeft <= tRight) {
            while (vec[tLeft] < middle) {
                tLeft++;
            }
            while (middle < vec[tRight]) {
                tRight--;
            }
            if (tLeft <= tRight) {
                std::swap(vec[tLeft], vec[tRight]);
                tLeft++;
                tRight--;
            }
        }
        if (tLeft < right) {
            quickSort(vec, tRight + 1, right);
        }
        if (left < tRight) {
            quickSort(vec, left, tLeft - 1);
        }
    }

public:
    static void selectSort(std::vector<T> &vec) {
        size_t len = vec.size();
        for (int i = 0; i < len; i++) {
            int min_index = i;
            for (int j = i + 1; j < len; j++) {
                if (vec.at(min_index) > vec.at(j)) {
                    min_index = j;
                }
            }
            if (min_index != i) {
                std::swap(vec.at(min_index), vec.at(i));
            }
        }
    }

    static void bubbleSort(std::vector<T> &vec) {
        size_t len = vec.size();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len - i - 1; j++) {
                if (vec.at(j) > vec.at(j + 1)) {
                    std::swap(vec.at(j), vec.at(j + 1));
                }
            }
        }
    }

    static void insertSort_v1(std::vector<T> &vec) {
        size_t len = vec.size();
        for (int i = 1; i < len; i++) {
            int temp = vec.at(i);
            int j;
            for (j = i; j > 0 && vec.at(j - 1) > temp; j--) {
                vec.at(j) = vec.at(j - 1);
            }
            vec.at(j) = temp;
        }
    }

    static void insertSort_v2(std::vector<T> &vec) {
        size_t len = vec.size();
        for (int i = 0; i < len; i++) {
            int temp = vec.at(i);
            int j;
            for (j = i - 1; j >= 0 && vec.at(j) > temp; j--) {
                vec.at(j + 1) = vec.at(j);
            }
            vec.at(j + 1) = temp;
        }
    }

    static void shellSort(std::vector<T> &vec) {
        size_t len = vec.size();
        for (int step = len / 2; step > 0; step /= 2) {
            for (int i = step; i < len; i++) {
                int temp = vec.at(i);
                int j;
                for (j = i - step; j >= 0 && vec.at(j) > temp; j -= step) {
                    vec.at(j + step) = vec.at(j);
                }
                vec.at(j + step) = temp;
            }
        }
    }

    static void quickSort(T begin, T end) {
        if (begin + 1 == end) {
            return;
        }
        auto mid = *std::next(begin, std::distance(begin, end) / 2);
        T left = std::partition(begin, end, [mid](const auto &i) { return i < mid; });
        T right = std::partition(left, end, [mid](const auto &i) { return i <= mid; });
        quickSort(begin, left);
        quickSort(right, end);
    }

    static void mergeSort(std::vector<T> &vec, int begin, int end) {
        if (begin + 1 == end) {
            return;
        }
        int mid = begin + (end - begin) / 2;
        mergeSort(vec, begin, mid);
        mergeSort(vec, mid, end);
        merge(vec, begin, mid, end);
    }

    static void quickSort(std::vector<T> &vec) {
        quickSort(vec, 0, vec.size()-1);
    }
};

template<typename T>
int binarySearch(std::vector<T> &vec, int target) {
    int left = 0, right = vec.size();
    while (left < right) {
        int midIndex = left + (right - left) / 2;
        T mid = vec.at(midIndex);
        if (target < mid) {
            right = midIndex - 1;
        } else if (mid < target) {
            left = midIndex + 1;
        } else {
            return midIndex;
        }
    }
    return -1;
}

int main() {
    std::vector<int> vec(50);
    auto item = vec.begin();
    std::generate(vec.begin(), vec.end(), RAND());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    Sort<int>::quickSort(vec);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}