//
// Created by Administrator on 2021/7/20.
//

#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H


#include <cstdlib>
#include "ListNode.h"

template<typename T>
class List {
private:
    int _size;/*规模*/
    ListNode<T> *header;/*头哨兵*/
    ListNode<T> *trailer;/*尾哨兵*/
protected:
    /**
     * 列表创建时初始化
     */
    void init();

    /**
     * 清除所有节点
     * @return
     */
    int clear();

    /**
     * 复制列表中自位置p起的项
     */
    void copyNodes(ListNode<T> *, int);

    /**
     * 有序列表区间归并
     */
    void merge(ListNode<T> *, int, List<T> &, ListNode<T> *, int);

    void mergeSort(ListNode<T> *, int);

    /**
     * 对从p开始连续的n各节点选择排序
     */
    void selectionSort(ListNode<T> *, int);

    /**
     * 对从p开始连续的n个节点插入排序
     */
    void insertionSort(ListNode<T> *, int);

public:
    /**
     * 默认构造函数
     */
    List();

    /**
     * 整体复制列表L
     */
    List(List<T> const &L);

    /**
     * 复制列表L中自第r项起的n项
     */
    List(List<T> const &L, int r, int n);

    /**
     * 复制列表中自位置p起的n项
     */
    List(ListNode<T> *p, int n);

    /**
     * 释放(包含头/尾哨兵在内的)所有节点
     */
    ~List();

    /**
     * 规模
     * @return
     */
    int size() const;

    /**
     * 判空
     * @return
     */
    bool empty() const;

    /**
     * 重载,支持循秩访问(效率低)
     * @return
     */
    T &operator[](int r) const;

    /**
     * 首节点位置
     * @return
     */
    ListNode<T> *first() const;

    /**
     * 末节点位置
     * @return
     */
    ListNode<T> *last() const;

    /**
     * 判断位置p是否对外合法
     * @return
     */
    bool valid(ListNode<T> *p);

    /**
     * 判断列表是否已排序
     * @return
     */
    int disorderd() const;

    /**
     * 无序列表查找
     * @return
     */
    ListNode<T> *find(T const &e) const;

    /**
     * 无序区间查找
     * @return
     */
    ListNode<T> *find(T const &e, int n, ListNode<T> *p) const;

    /**
     * 有序列表查找
     * @return
     */
    ListNode<T> *search(T const &e) const;

    /**
     * 有序区间查找
     * @return
     */
    ListNode<T> *search(T const &, int, ListNode<T> *) const;

    /**
     * 在p及其前n-1个后继中选出最大者
     * @return
     */
    ListNode<T> *selectMax(ListNode<T> *p, int n);

    /**
     * 整体最大者
     * @return
     */
    ListNode<T> *selectMax();

    /**
     * 将e当做首节点插入
     * @return
     */
    ListNode<T> *insertAsFirst(T const &e);

    /**
     * 将e当做末节点插入
     * @return
     */
    ListNode<T> *insertAsLast(T const &e);

    /**
     * 将e当做p的前驱插入
     * @return
     */
    ListNode<T> *insertBefore(ListNode<T> *p, T const &e);

    /**
     * 将e当做p的后驱插入
     * @return
     */
    ListNode<T> *insertAfter(ListNode<T> *p, T const &e);

    /**
     * 删除核发位置p处的节点,返回被删除节点
     * @return
     */
    T remove(ListNode<T> *p);

    /**
     * 全列表归并
     */
    void merge(List<T> &L);

    /**
     * 列表区间排序
     */
    void sort(ListNode<T> *p, int n);

    /**
     * 列表整体排序
     */
    void sort();

    /**
     * 无序去重
     * @return
     */
    int deduplicate();

    /**
     * 有序去重
     * @return
     */
    int uniquify();

    /**
     * 前后倒置
     */
    void reverse();

    /**
     * 遍历,依次实施visit操作(函数指针,只读或局部性修改)
     */
    void traverse(void(*)(T &));

    /**
     * 遍历,依次实施visit操作(函数对象,可全局性修改)
     * @tparam VST
     * @return
     */
    template<typename VST>
    void traverse(VST &);
};


#endif //QUEUE_LIST_H
