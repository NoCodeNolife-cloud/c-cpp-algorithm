//
// Created by NoCodeNoLife on 2021/7/13.
//

#include "List.h"

template<typename T>
void List<T>::init() {
    header = new ListNode<T>;/*头哨兵节点*/
    trailer = new ListNode<T>;/*尾哨兵节点*/
    header->succ = trailer;
    header->pred = nullptr;
    trailer->pred = header;
    trailer->succ = nullptr;
    _size = 0;/*记录规模*/
}

template<typename T>
int List<T>::clear() {
    return 0;
}

template<typename T>
void List<T>::copyNodes(ListNode<T> *p, int n) {
    init();/*创建头/尾哨兵节点并做初始化*/
    while (n--) {
        insertAsLast(p->data);/*将起自p的n项依次作为末节点插入*/
        p = p->succ;
    }
}

template<typename T>
void List<T>::merge(ListNode<T> *, int, List<T> &, ListNode<T> *, int) {

}

template<typename T>
void List<T>::selectionSort(ListNode<T> *, int) {

}

template<typename T>
void List<T>::insertionSort(ListNode<T> *, int) {

}

template<typename T>
List<T>::List() {
    init();
}

template<typename T>
List<T>::List(const List<T> &L) {

}

template<typename T>
List<T>::List(const List<T> &L, int r, int n) {

}

template<typename T>
List<T>::List(ListNode<T> *p, int n) {

}

template<typename T>
List<T>::~List() {

}

template<typename T>
int List<T>::size() const {
    return _size;
}

template<typename T>
bool List<T>::empty() const {
    return _size <= 0;
}

template<typename T>
T &List<T>::operator[](int r) const {
    ListNode<T> *p = first();/*从首节点出发*/
    while (0 < r--) {/*顺数第r个节点即是*/
        p = p->succ;
    }
    return p->data;/*目标节点,返回其中的元素*/
}

template<typename T>
ListNode<T> *List<T>::first() const {
    return header->succ;
}

template<typename T>
ListNode<T> *List<T>::last() const {
    return trailer->pred;
}

template<typename T>
bool List<T>::valid(ListNode<T> *p) {
    return p && (trailer != p) && (header != p);
}

template<typename T>
int List<T>::disorderd() const {
    return 0;
}

template<typename T>
ListNode<T> *List<T>::find(const T &e) const {
    return find(e, _size, trailer);
}

template<typename T>
ListNode<T> *List<T>::find(const T &e, int n, ListNode<T> *p) const {
    while (0 < n--) {/*对于p的最近的n个前驱,从右向左*/
        if (e == (p = p->pred)->data) {/*逐个比对,直至命中或范围越界*/
            return p;
        }
    }
    return nullptr;/*p越界意味着区间内不含e,查找失败*/
}

template<typename T>
ListNode<T> *List<T>::search(const T &e) const {
    return search(e, _size, trailer);
}

template<typename T>
ListNode<T> *List<T>::search(const T &, int, ListNode<T> *) const {
    return nullptr;
}

template<typename T>
ListNode<T> *List<T>::selectMax(ListNode<T> *p, int n) {
    return nullptr;
}

template<typename T>
ListNode<T> *List<T>::selectMax() {
    return selectMax(header->succ, _size);
}

template<typename T>
ListNode<T> *List<T>::insertAsFirst(const T &e) {
    _size++;
    return header->insertAsSucc(e);/*e当做首节点插入*/
}

template<typename T>
ListNode<T> *List<T>::insertAsLast(const T &e) {
    _size++;
    return trailer->insertAsPred(e);/*e当做末节点插入*/
}

template<typename T>
ListNode<T> *List<T>::insertBefore(ListNode<T> *p, const T &e) {
    _size++;
    return p->insertAsPred(e);/*e当做p的前驱插入*/
}

template<typename T>
ListNode<T> *List<T>::insertAfter(ListNode<T> *p, const T &e) {
    _size++;
    return p->insertAsSucc(e);/*e当做p的后驱插入*/
}

template<typename T>
T List<T>::remove(ListNode<T> *p) {
    return nullptr;
}

template<typename T>
void List<T>::merge(List<T> &L) {
    merge(first(), size(), L, L.first(), L._size);
}

template<typename T>
void List<T>::sort(ListNode<T> *p, int n) {

}

template<typename T>
void List<T>::sort() {
    sort(first(), _size);
}

template<typename T>
int List<T>::deduplicate() {
    return 0;
}

template<typename T>
int List<T>::uniquify() {
    return 0;
}

template<typename T>
void List<T>::reverse() {

}

template<typename T>
void List<T>::traverse(void (*)(T &)) {

}

template<typename T>
template<typename VST>
void List<T>::traverse(VST &) {

}
