#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <iterator>

namespace cod {
    void merge(std::vector<int> &paraVec, int paraLeft, int paraMiddle, int paraRight) {
        int left = paraLeft, right = paraMiddle;
        std::vector<int> tmpVector;
        while (left < paraMiddle && right < paraRight) {
            (paraVec[left] < paraVec[right]) ? tmpVector.push_back(paraVec[left++])
                                             : tmpVector.push_back(paraVec[right++]);
        }
        while (left < paraMiddle) {
            tmpVector.push_back(paraVec[left++]);
        }
        while (right < paraRight) {
            tmpVector.push_back(paraVec[right++]);
        }
        for (int i = 0; i < tmpVector.size(); i++) {
            paraVec[paraLeft + i] = tmpVector[i];
        }
    }

    void mergeSort(std::vector<int> &paraVec, int paraLeft, int paraRight) {
        if (paraLeft + 1 == paraRight) {
            return;
        }
        int middle = paraLeft + (paraRight - paraLeft) / 2;
        mergeSort(paraVec, paraLeft, middle);
        mergeSort(paraVec, middle, paraRight);
        merge(paraVec, paraLeft, middle, paraRight);
    }
}

class Gen {
public:
    int operator()() {
        std::seed_seq seedSeq{time(nullptr)};
        static std::default_random_engine defaultRandomEngine(seedSeq);
        std::uniform_int_distribution<int> uniformIntDistribution(0, 100);
        return uniformIntDistribution(defaultRandomEngine);
    }
};

int main() {
    std::vector<int> vec(10);
    std::generate(vec.begin(), vec.end(), Gen());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    cod::mergeSort(vec, 0, vec.size());

    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}