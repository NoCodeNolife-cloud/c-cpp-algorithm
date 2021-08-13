#include <bits/stdc++.h>

using namespace std;

void Merge(vector<int> &vec, int left, int middle, int right) {
    vector<int> temp;
    int i = left;
    int j = middle + 1;
    while (i <= middle && j <= right) {
        if (vec[i] < vec[j]) {
            temp.push_back(vec[i++]);
        } else {
            temp.push_back(vec[j++]);
        }
    }
    while (i <= middle) {
        temp.push_back(vec[i++]);
    }
    while (j <= right) {
        temp.push_back(vec[j++]);
    }
    for (int k = 0; k < temp.size(); k++) {
        vec[left + k] = temp[k];
    }
}

void MergeSort(vector<int> &vec, int left, int right) {
    if (left == right) {
        return;
    }
    int middle = (left + right) / 2;
    MergeSort(vec, left, middle);
    MergeSort(vec, middle + 1, right);
    Merge(vec, left, middle, right);
}

int main() {
    vector<int> vec = {89, 64, 30, 92, 36, 62, 35, 18, 65, 9};
    MergeSort(vec, 0, vec.size() - 1);
    for (int item:vec) {
        cout << item << endl;
    }
}
