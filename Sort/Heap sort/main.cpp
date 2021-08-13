
#include <iostream>
#include <vector>

using namespace std;

void printkk(vector<int> &invec, int &len){
    for(int i = 0; i < len; ++i)
        cout << invec[i] << " ";
}

void swap(int &a, int &b){
    int temp;
    temp = b;
    b = a;
    a = temp;
}

// heap sorting
void Heapify(vector<int> &invec, int &s, int &len){
    int fa = s;
    int child = 2*fa+1;
    cout << "fa1 = " << fa <<" " << "child1 = " << child << endl;
    while(child < len){
        if(child+1 < len && invec[child] < invec[child+1]){
            ++child;
        }
        if(invec[fa]<invec[child]){
            swap(invec[fa], invec[child]);
            fa = child;
            child = 2*fa+1;
            cout << "fa2 = " << fa <<" " << "child2 = " << child << endl;
        }
        else{
            break;
        }
    }
    printkk(invec,len);
    cout << endl;
}

int start = 0;

void HeapSort(vector<int> &invec, int &len){
    // initial building heap
    for(int i = (len-1)/2; i>=0;--i){
        Heapify(invec, i, len);
    }
    for(int i = len-1; i>0;--i){
        swap(invec[i],invec[start]);
        Heapify(invec, start, i);
    }
}

int main() {
    vector<int> invec{1, 2, 3, 7, 5, 9, 0, 11, 15, 8, 30, 20, 19};
    int len = invec.size();
    HeapSort(invec, len);
    printkk(invec, len);
    cout << endl;
}