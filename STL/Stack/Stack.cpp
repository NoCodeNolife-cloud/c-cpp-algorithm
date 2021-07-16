//
// Created by Administrator on 2021/7/16.
//

#include "Stack.h"

template<typename T>
void Stack<T>::push(const T &e) {
    Vector<T>::insert(Vector<T>::size(), e);
}

template<typename T>
T Stack<T>::pop() {
    return Vector<T>::remove(Vector<T>::size() - 1);
}

template<typename T>
T &Stack<T>::top() {
    return (*this)[Vector<T>::size() - 1];
}
