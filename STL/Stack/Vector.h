//
// Created by NoCodeNoLife on 2021/7/11.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
#define DEFAULT_CAPACITY 3

#include <random>

using namespace std;

template<typename T>
class Vector {
protected:
    int _size, _capacity;/*规模、容量*/
    T *_elem;/*数据区*/

    /**
     * 复制数组区间A[lo,hi]
     * @param A
     * @param lo
     * @param hi
     */
    void copyFrom(T const *A, int lo, int hi);

    /**
     * 空间不足时扩容
     */
    void expand();

    /**
     * 装填因子过小时压缩
     */
    void shrink();

    /**
     * 扫描交换
     * @param lo
     * @param hi
     * @return
     */
    bool bubble(int lo, int hi);

    /**
     * 起泡排序算法
     * @param lo
     * @param hi
     */
    void bubbleSort(int lo, int hi);

    /**
     * 选取最大元素
     * @param lo
     * @param hi
     * @return
     */
    int max(int lo, int hi);

    /**
     * 选择排序算法
     * @param lo
     * @param hi
     */
    void selectionSort(int lo, int hi);

    /**
     * 归并算法
     * @param lo
     * @param hi
     */
    void merge(int lo, int mi, int hi);

    /**
     * 归并排序算法
     * @param lo
     * @param hi
     */
    void mergeSort(int lo, int hi);

    /**
     * 轴点构造算法
     * @param lo
     * @param hi
     */
    void partition(int lo, int hi);

    /**
     * 快速排序
     * @param lo
     * @param hi
     */
    void quickSort(int lo, int hi);

    /**
     * 堆排序
     * @param lo
     * @param hi
     */
    void heapSort(int lo, int hi);

public:
    /**
     * 构造函数
     * @param c 容量
     * @param s 规模
     * @param v 所有元素初始
     */
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) {
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _elem[_size++] = v);
    }

    /**
     * 数组区间复制
     * @param A
     * @param lo
     * @param hi
     */
    Vector(T const *A, int lo, int hi) {
        copyFrom(A, lo, hi);
    }

    /**
     * 数组整体复制
     * @param A
     * @param n
     */
    Vector(T const *A, int n) {
        copyFrom(A, 0, n);
    }

    /**
     * 向量区间复制
     * @param V
     * @param lo
     * @param hi
     */
    Vector(T const &V, int lo, int hi) {
        copyFrom(V._elem, lo, hi);
    }

    /**
     * 向量整体复制
     * @param V
     */
    Vector(Vector<T> const &V) {
        copyFrom(V._elem, 0, V._size);
    }

    /**
     * 析构函数
     */
    ~Vector() {
        delete[]_elem;
    }

    /**
     * 获得规模
     * @return _size
     */
    int size() const {
        return _size;
    }

    /**
     * 判空
     * @return
     */
    bool empty() const {
        return !_size;
    }

    /**
     * 判断向量是否已排序
     * @return
     */
    int disordered() const;

    /**
     * 无序向量整体查找
     * @param e
     * @return
     */
    int find(T const &e) const {
        return find(e, 0, _size);
    }

    /**
     * 无序向量区间查找
     * @param e
     * @param lo
     * @param hi
     * @return
     */
    int find(T const &e, int lo, int hi) const;

    /**
     * 有序向量整体查找
     * @param e
     * @return
     */
    int search(T const &e) const {
        return (0 >= _size) ? -1 : search(e, 0, _size);
    }

    /**
     * 有序向量区间查找
     * @param e
     * @param lo
     * @param hi
     * @return
     */
    int search(T const &e, int lo, int hi) const;

    /**
     * 重载下标操作符,可以类似于数组形式引用元素
     * @param r
     * @return
     */
    T &operator[](int r) const;

    /**
     * 重载赋值操作符,以便直接克隆向量
     * @return
     */
    Vector<T> &operator=(Vector<T> const &V);

    /**
     * 删除秩为r的元素
     * @param r
     * @return
     */
    T remove(int r);

    /**
     * 删除秩在区间[lo,hi)的元素
     * @param lo
     * @param hi
     * @return
     */
    int remove(int lo, int hi);

    /**
     * 插入元素
     * @param r
     * @param e
     * @return
     */
    int insert(int r, T const &e);

    /**
     * 默认作为末元素插入
     * @param e
     * @return
     */
    int insert(T const &e) {
        return insert(_size, e);
    }

    /**
     * 对[lo,hi)排序
     * @param lo
     * @param hi
     */
    void sort(int lo, int hi);

    /**
     * 整体排序
     */
    void sort() {
        sort(0, _size);
    }

    /**
     * 对[lo,hi)置乱
     * @param lo
     * @param hi
     */
    void unsort(int lo, int hi);

    /**
     * 整体置乱
     */
    void unsort() {
        unsort(0, _size);
    }

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
     * 遍历(使用函数指针,只读或局部性修改)
     */
    void traverse(void(*)(T &));

    /**
     * 遍历(使用函数对象,可全局性修改)
     * @tparam VST
     */
    template<typename VST>
    void traverse(VST &);
};

template<typename T>
void permute(Vector<T> &V);

template<typename T>
static bool lt(T *a, T *b);

template<typename T>
static bool lt(T &a, T &b);

template<typename T>
static bool eq(T *a, T *b);

template<typename T>
static bool eq(T &a, T &b);

template<typename T>
static int binSearchA(T *A, T const &e, int lo, int hi);

template<typename T>
static int binSearchB(T *A, T const &e, int lo, int hi);

template<typename T>
static int binSearchC(T *A, T const &e, int lo, int hi);

#endif //VECTOR_VECTOR_H
