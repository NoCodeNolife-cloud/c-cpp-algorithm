//
// Created by NoCodeNoLife on 2021/7/13.
//

#include "List.h"

template<typename T>
void List<T>::init() {

}

template<typename T>
int List<T>::clear() {
    return 0;
}

template<typename T>
void List<T>::copyNodes(ListNode<T> *, int) {

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
    return <#initializer#>;
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
    return nullptr;
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
    return nullptr;
}

template<typename T>
ListNode<T> *List<T>::insertAsLast(const T &e) {
    return nullptr;
}

template<typename T>
ListNode<T> *List<T>::insertBefore(ListNode<T> *p, const T &e) {
    return nullptr;
}

template<typename T>
ListNode<T> *List<T>::insertAfter(ListNode<T> *p, const T &e) {
    return nullptr;
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
