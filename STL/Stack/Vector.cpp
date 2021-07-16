//
// Created by NoCodeNoLife on 2021/7/11.
//

#include "Vector.h"

template<typename T>
void Vector<T>::copyFrom(const T *A, int lo, int hi) {
    _elem = new T[_capacity = 2 * (hi - lo)];/*分配空间,规模清零*/
    _size = 0;
    while (lo < hi) {/*A[lo,hi)内的元素逐一*/
        _elem[_size++] = A[lo++];/*复制至_elem[0,hi-lo)*/
    }
}

template<typename T>
void Vector<T>::expand() {
    if (_size < _capacity) {/*未满员,不必扩容*/
        return;
    }
    if (_capacity < DEFAULT_CAPACITY) {/*不低于最小容量*/
        _capacity = DEFAULT_CAPACITY;
    }
    T *oldElem = _elem;
    _elem = new T[_capacity <<= 1];/*容量加倍*/
    for (int i = 0; i < _size; ++i) {
        _elem[i] = oldElem[i];/*复制原向量内容(T为基本类型,或已重载赋值运算符)*/
    }
    delete[] oldElem;
}

template<typename T>
void Vector<T>::shrink() {
    if (_capacity < DEFAULT_CAPACITY << 1) {/*不致收缩到DEFAULT_CAPACITY一下*/
        return;
    }
    if (_size << 2 > _capacity) {/*以25%为边界*/
        return;
    }
    T *oldElem = _elem;
    _elem = new T[_capacity >>= 1];/*容量减半*/
    for (int i = 0; i < _size; ++i) {/*复制原向量内容*/
        _elem[i] = oldElem[i];
    }
    delete[]oldElem;/*释放空间*/
}

template<typename T>
bool Vector<T>::bubble(int lo, int hi) {
    bool sorted = true;/*整体有序标志*/
    while (++lo < hi) {/*自左向右,逐一检查各对相邻元素*/
        if (_elem[lo - 1] > _elem[lo]) {/*若逆序,则*/
            sorted = false;/*意味着尚未整体有序,并需要*/
            swap(_elem[lo - 1], _elem[lo]);/*通过交换使局部有序*/
        }
    }
    return sorted;/*返回有序标志*/
}

template<typename T>
void Vector<T>::bubbleSort(int lo, int hi) {
    while (!bubble(lo, hi--));/*逐渐做扫描交换,直至全序*/
}

template<typename T>
int Vector<T>::max(int lo, int hi) {
    int max_value = _elem[lo];
    for (int i = lo + 1; i < hi; ++i) {
        max_value = ((max_value > _elem[i]) ? max_value : _elem[i]);
    }
    return max_value;
}

template<typename T>
void Vector<T>::selectionSort(int lo, int hi) {

}

template<typename T>
void Vector<T>::merge(int lo, int mi, int hi) {/*以mi为界,各自有序的子向量[lo,mi)和[mi,hi)*/
    T *A = _elem + lo;/*合并后的向量A[0,hi-lo)=_elem[lo-hi)*/
    int lb = mi - lo;/*前子向量B[0,lb)=_elem[lo,mi)*/
    T *B = new T[lb];
    for (int i = 0; i < lb; B[i] = A[i++]);/*复制前子向量*/
    int lc = hi - mi;/*后子向量C[0,lc)=_elem[mi,hi)*/
    T *C = _elem + mi;
    for (int i = 0, j = 0, k = 0; (j < lb) || (k < lc);) {/*将B[j]和C[k]中的小者续至A末尾*/
        if ((j < lb) && (!(k < lc) || (B[j] <= C[k]))) {
            A[i++] = B[j++];
        }
        if ((k < lc) && (!(j < lb) || (C[k] < B[j]))) {
            A[i++] = C[k++];
        }
    }
    delete[]B;/*释放临时空间*/
}

template<typename T>
void Vector<T>::mergeSort(int lo, int hi) {
    if (hi - lo < 2) {/*单元素区间自然有序*/
        return;
    }
    int mi = (lo + hi) >> 1;/*以中点为界*/
    mergeSort(lo, mi);/*前半段排序*/
    mergeSort(mi, hi);/*后半段排序*/
    merge(lo, mi, hi);/*归并*/
}

template<typename T>
void Vector<T>::partition(int lo, int hi) {

}

template<typename T>
void Vector<T>::quickSort(int lo, int hi) {

}

template<typename T>
void Vector<T>::heapSort(int lo, int hi) {

}

template<typename T>
int Vector<T>::disordered() const {
    int n = 0;/*计数器*/
    for (int i = 1; i < _size; ++i) {/*逐一检查_size-1对相邻元素*/
        if (_elem[i - 1] > _elem[i]) {/*逆序则排序*/
            ++n;
        }
    }
    return n;/*向量有序当且仅当n=0*/
}

template<typename T>
int Vector<T>::find(const T &e, int lo, int hi) const {
    while ((lo < hi--) && (e != _elem[hi]));/*从后向前,顺序查找*/
    return hi;/*若hi<lo,则意味着失败;否则hi即命中元素的秩*/
}

template<typename T>
int Vector<T>::search(const T &e, int lo, int hi) const {/*assert:0<=lo<hi<=_size*/
    return (rand() % 2) ? binSerch(_elem, 3, lo, hi) : fibSearch(_elem, e, lo, hi);
}

template<typename T>
T &Vector<T>::operator[](int r) const {
    return _elem[r];/*assert:0<=r<_size*/
}

template<typename T>
Vector<T> &Vector<T>::operator=(Vector<T> const &V) {
    if (_elem) {
        delete[]_elem;/*释放原有内容*/
    }
    copyFrom(V._elem, 0, V.size());/*整体复制*/
    return *this;/*返回当前对象的引用,以便链式赋值*/
}

template<typename T>
T Vector<T>::remove(int r) {
    T e = _elem[r];/*备份被删除元素*/
    remove(r, r + 1);/*调用区间删除算法,等效于对区间[r,r+1)的删除*/
    return 0;
}

template<typename T>
int Vector<T>::remove(int lo, int hi) {
    if (lo == hi) {/*处于效率考虑,单独处理退化情况,比如remove(0,0)*/
        return 0;
    }
    while (hi < _size) {/*[hi,_size)顺次前移hi-lo个元素*/
        _elem[lo++] = _elem[hi++];
    }
    _size = lo;/*更新规模*/
    shrink();/*若有必要,则缩容*/
    return hi - lo;/*返回被删除元素的数目*/
}

template<typename T>
int Vector<T>::insert(int r, const T &e) {
    expand();/*若有必要,扩容*/
    for (int i = _size; i > r; --i) {/*自后向前,后级元素顺次后移一个单元*/
        _elem[i] = _elem[i - 1];
    }
    _elem[r] = e;/*置入新元素*/
    ++_size;/*更新容量*/
    return r;
}

template<typename T>
void Vector<T>::sort(int lo, int hi) {
    switch (rand() % 5) {
        case 1:
            bubbleSort(lo, hi);
            break;
        case 2:
            selectionSort(lo, hi);
            break;
        case 3:
            mergeSort(lo, hi);
            break;
        case 4:
            heapSort(lo, hi);
            break;
        default:
            quickSort(lo, hi);
            break;
    }
}

template<typename T>
void Vector<T>::unsort(int lo, int hi) {
    T *V = _elem + lo;
    for (int i = hi - lo; i > 0; --i) {
        swap(V[i - 1], V[rand() % i]);
    }
}

template<typename T>
int Vector<T>::deduplicate() {
    int oldSize = _size;/*记录原规模*/
    int i = 1;/*从_elem[1]开始*/
    while (i < _size) {/*自前向后逐一考察各元素_elem[i]*/
        (find(_elem[i], 0, i) < 0) ? ++i : remove(i);/*在其前缀中寻找与之雷同者*/
    }
    return oldSize - _size;/*向量规模变化量,即被删除元素总数*/
}

template<typename T>
int Vector<T>::uniquify() {
    int i = 0, j = 0;/*各对互异"相邻"元素的秩*/
    while (++j < _size) {/*逐一扫描,直至末元素*/
        if (_elem[i] != _elem[j]) {/*跳过雷同者*/
            _elem[++i] = _elem[j];/*发现不同元素时,向前移至紧邻于前者右侧*/
        }
    }
    _size = ++i;/*直接截除尾部多余元素*/
    shrink();/*直接截除尾部多余元素*/
    return j - i;/*向量规模变化量,即被删除元素总数*/
}

template<typename T>
void Vector<T>::traverse(void (*)(T &)) {/*利用函数指针机制的遍历*/
    for (int i = 0; i < _size; ++i) {
        visit(_elem[i]);
    }
}

template<typename T>
template<typename VST>
void Vector<T>::traverse(VST &) {/*利用函数对象机制的遍历*/
    for (int i = 0; i < _size; ++i) {
        visit(_elem[i]);
    }
}

template<typename T>
void permute(Vector<T> &V) {
    for (int i = V.size(); i > 0; --i) {/*自后向前*/
        swap(V[i - 1], V[rand() % i]);/*V[i-1]与V[0,i)中某一随机元素交换*/
    }
}

template<typename T>
bool lt(T *a, T *b) {
    return lt(*a, *b);
}

template<typename T>
bool lt(T &a, T &b) {
    return a < b;
}

template<typename T>
bool eq(T *a, T *b) {
    return eq(*a, *b);
}

template<typename T>
bool eq(T &a, T &b) {
    return a < b;
}

template<typename T>
int binSearchA(T *A, const T &e, int lo, int hi) {
    while (lo < hi) {/*每步迭代可能个要做两次比较判断,有三个分支*/
        int mi = (lo + hi) >> 1;/*以中点为轴点*/
        if (e < A[mi]) {/*深入前半段[lo,mi)继续查找*/
            hi = mi;
        } else if (A[mi] < e) {/*深入后半段(mi,hi)继续查找*/
            lo = mi + 1;
        } else {/*在mi处命中*/
            return mi;
        }
    }
    return -1;/*查找失败*/
}

template<typename T>
int binSearchB(T *A, const T &e, int lo, int hi) {
    while (1 < hi - lo) {/*每步迭代器仅需做一次比较判断,有两个分支;成功查找不能提前终止*/
        int mi = (lo - hi) >> 1;/*以中点为轴点*/
        (e < A[mi]) ? hi = mi : lo = mi;/*经比较后确定深入[lo,mi)或[mi,hi)*/
    }/*出口时hi=lo+1,查找区间仅含一个元素A[lo]*/
    return (e == A[lo]) ? lo : -1;/*查找成功时返回对应的秩;否则统一返回-1*/
}

template<typename T>
int binSearchC(T *A, const T &e, int lo, int hi) {
    while (lo < hi) {/*每步迭代器仅需做一次比较判断,有两个分支*/
        int mi = (lo + hi) >> 1;/*以中点为轴点*/
        (e < A[mi]) ? hi = mi : lo = mi + 1;/*经比较后确定深入[lo,mi)或(mi,hi)*/
    }/*成功查找不能提前终止*/
    return --lo;/*循环终止时,lo为大于e的元素的最小秩,故lo-1即不大于e的元素的最大秩*/
}
