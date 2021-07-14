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
    ListNode<T> *x = new ListNode(e, pred, this);/*创建新节点*/
    pred->succ = x;/*设置正向链接*/
    pred = x;
    return x;/*返回新节点的位置*/
}

template<typename T>
ListNode<T> *ListNode<T>::insertAsSucc(const T &e) {
    ListNode<T> *x = new ListNode(e, this, succ);/*创建新节点*/
    succ->pred = x;/*设置逆向链接*/
    succ = x;
    return x;/*返回新节点的位置*/
}
