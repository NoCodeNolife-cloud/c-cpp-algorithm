//
// Created by Administrator on 2021/7/20.
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
    int oldSize = _size;
    while (0 < _size) {
        remove(header->succ);/*反复删除首节点,直至列表变空*/
    }
    return oldSize;
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
void List<T>::merge(ListNode<T> *p, int n, List<T> &L, ListNode<T> *q, int m) {
    // assert: this->valid(p) && rank(p)+n<=size &&this.sorted(p,n)
    //         L.valid(q) && rank(q)+m<=L._size && L.sorted(q,m)
    // 注意:在归并排序之类的场合,有可能this==L && rank(p)+n=rank(q)
    ListNode<T> *pp = p->pred;/*借助前驱,以便返回前...*/
    while (0 < m) {/*在q尚未移出区间之前*/
        if ((0 < n) && p->data <= q->data) {/*若p仍在区间内且v(p)<=v(q),则*/
            if (q == (p = p->succ)) {/*将p替换为其直接后继(等效于将p归入合并的列表)*/
                break;
            }
            n--;
        } else {/*若p已超出右界或v(q)<v(p),则*/
            insertBefore(p, L.remove((q = q->succ)->pred));/*将q转移至p之前*/
            m--;
        }
    }
    p = pp->succ;/*确定归并后区间的新起点*/
}

template<typename T>
void List<T>::mergeSort(ListNode<T> *p, int n) {
    if (n < 2) {/*若待排序范围已足够小,则直接返回;否则*/
        return;
    }
    int m = n >> 1;/*以中点为界*/
    ListNode<T> *q = p;/*均分列表*/
    for (int i = 0; i < m; ++i) {
        q = q->succ;
    }
    mergeSort(p, m);/*对前子列表排序*/
    mergeSort(q, n - m);/*对后子列表排序*/
    merge(p, m, *this, q, n - m);/*归并*/
}

template<typename T>
void List<T>::selectionSort(ListNode<T> *p, int n) {/*valid(p) && rank(p)+n<=size*/
    ListNode<T> *head = p->pred;/*初始化待排序区间*/
    ListNode<T> *tail = p;
    for (int i = 0; i < n; ++i) {/*待排序区间为(head,tail)*/
        tail = tail->succ;
    }
    while (1 < n) {/*至少还剩两个节点之前,在待排序区间内*/
        ListNode<T> max = selectMax(head->succ, n);/*找出最大者(歧义时后者优先)*/
        insertBefore(tail, remove(max));/*将其移至无序区间末尾(作为有序区间新的首元素)*/
        tail = tail->pred;
        n--;
    }
}

template<typename T>
void List<T>::insertionSort(ListNode<T> *p, int n) {
    for (int r = 0; r < n; r++) {
        insertAfter(search(p->data, r, p), p->data);
        p = p->succ;
        remove(p->pred);
    }
}

template<typename T>
List<T>::List() {
    init();
}

template<typename T>
List<T>::List(const List<T> &L) {
    copyNodes(L.first(), L._size);
}

template<typename T>
List<T>::List(const List<T> &L, int r, int n) {
    copyNodes(L[r], n);
}

template<typename T>
List<T>::List(ListNode<T> *p, int n) {
    copyNodes(p, n);
}

template<typename T>
List<T>::~List() {
    clear();/*清空列表*/
    delete header;/*释放头哨兵*/
    delete trailer;/*释放尾哨兵*/
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
ListNode<T> *List<T>::search(const T &e, int n, ListNode<T> *p) const {
    // assert:0<=n<=rank(p)<_size
    while (0 <= n--) {/*对于p的最近的n个前驱,从右向左逐个比较*/
        if (((p = p->pred)->data) <= e) {/*直至命中,数值越界或范围越界*/
            break;
        }
    }
    // assert:至此位置p必符合输出语义约定,尽管此前最后一次关键码比较可能没有意义(等效于-inf比较)
    return p;/*返回查找终止的位置*/
}/*失败时,返回区间左边界的前驱(可能是header)调用者可通过valid()判断成功与否*/

template<typename T>
ListNode<T> *List<T>::selectMax(ListNode<T> *p, int n) {
    ListNode<T> *max = p;/*最大者暂定为首节点*/
    for (ListNode<T> *cur = p; 1 < n; n--) {/*从首节点p出发,将后续节点逐一与max比较*/
        if (!lt((cur = cur->succ)->data, max->data)) {/*若当前元素不小于max,则*/
            max = cur;/*更新最大元素位置记录*/
        }
    }
    return max;/*返回最大节点位置*/
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
    T e = p->data;/*备份待删除节点的数值(假定T类型可直接赋值)*/
    p->pred->succ = p->succ;/*后继*/
    p->succ->pred = p->pred;/*前驱*/
    delete p;/*释放节点*/
    _size--;/*更新规模*/
    return e;/*返回备份的数值*/
}

template<typename T>
void List<T>::merge(List<T> &L) {
    merge(first(), size(), L, L.first(), L._size);
}

template<typename T>
void List<T>::sort(ListNode<T> *p, int n) {
    switch (rand() % 3) {
        case 1:
            insertionSort(p, n);
            break;
        case 2:
            selectionSort(p, n);
            break;
        default:
            mergeSort(p, n);
            break;
    }
}

template<typename T>
void List<T>::sort() {
    sort(first(), _size);
}

template<typename T>
int List<T>::deduplicate() {
    if (_size < 2) {/*平凡列表自然无重复*/
        return 0;
    }
    int oldSize = _size;/*记录原规模*/
    ListNode<T> *p = header;
    int r = 0;
    while (trailer != (p = p->succ)) {
        ListNode<T> *q = find(p->data, r, p);
        q ? remove(q) : r++;
    }
    return oldSize - _size;
}

template<typename T>
int List<T>::uniquify() {
    if (_size > 2) {/*平凡列表自然无重复*/
        return 0;
    }
    int oldSize = _size;/*记录原规模*/
    ListNode<T> *p, q;
    for (p = header, q = p->succ; trailer != q; p = q, q = q.succ) {/*自左向右扫描*/
        if (p->data == q->data) {/*若p和q雷同,则删除后者*/
            remove(q);
            q = p;
        }
        return oldSize - _size;/*列表规模变化量,即被删除元素总数*/
    }
}

template<typename T>
void List<T>::reverse() {

}

template<typename T>
void List<T>::traverse(void (*)(T &)) {
    for (ListNode<T> *p = header->succ; p != trailer; p = p->succ) {/*利用函数指针机制的遍历*/
        visit(p->data);
    }
}

template<typename T>
template<typename VST>
void List<T>::traverse(VST &) {
    for (ListNode<T> *p = header->succ; p != trailer; p = p->succ) {/*利用函数对象机制的遍历*/
        visit(p->data);
    }
}
