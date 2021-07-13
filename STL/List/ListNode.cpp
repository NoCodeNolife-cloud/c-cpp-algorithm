//
// Created by NoCodeNoLife on 2021/7/13.
//

#include "ListNode.h"

template<typename T>
ListNode<T>::ListNode() {

}

template<typename T>
ListNode<T>::ListNode(T e, ListNode<T> *p, ListNode<T> *s):data(e), pred(p), succ(s) {

}

template<typename T>
ListNode<T> *ListNode<T>::insertAsPred(const T &e) {
    return nullptr;
}

template<typename T>
ListNode<T> *ListNode<T>::insertAsSucc(const T &e) {
    return nullptr;
}
