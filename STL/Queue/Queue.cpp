//
// Created by Administrator on 2021/7/20.
//

#include "Queue.h"

using namespace std;

template<typename T>
void Queue<T>::enqueue(const T &e) {
    insertAsLast(e);
}

template<typename T>
T Queue<T>::dequeue() {
    remove(List<T>::first());
}

template<typename T>
T &Queue<T>::front() {
    return List<T>::first()->data;
}
