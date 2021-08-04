//
// Created by Administrator on 2021/7/24.
//

#ifndef BINARY_TREE_BINTREE_H
#define BINARY_TREE_BINTREE_H
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lChild))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rChild))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lChild)
#define HasRChild(x) ((x).rChild)
#define HasChild(x) (HasLChild(x) || HasRChild(x)) //至少拥有一个孩子
#define HasBothChild(x) (HasLChild(x) && HasRChild(x)) //同时拥有两个孩子
#define IsLeaf(x) (!HasChild(x))
#define sibling(p) (IsLChild(*(p)) ?(p)->parent->rChild :(p)->parent->lChild)//兄弟
#define uncle(x) ( IsLChild(*((x)->parent)) ?(x)->parent->parent->rChild :(x)->parent->parent->lChild) //叔叔
#define FromParentTo(x) (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lChild : (x).parent->rChild)) //来自父亲癿指针
#define stature(p) ((p)?(p)->height:-1)//节点高度（与“空树高度为-1”的约定相统一）
#define Balanced(x) (stature((x).lChild)==stature((x).rChild))
#define BalFac(x) (stature((x).lChild)-stature((x).rChild))
#define AvlBalanced(x) ((-2<BalFac(x))&&(BalFac(x)<2))
#define tallerChild(x) (stature((x)->lChild)>stature((x)->rChild)?(x)->lChild:(stature((x)->?rChild)>stature((x)->lChild)?(x)->rChild:(IsLChild(*(x))?(x)->lChild:(x)->rChild)))
#include <stack>
#include <queue>

using namespace std;

typedef enum {
    RB_RED, RB_BLACK
} RBColor;//节点颜色

template<typename T>
struct BinNode {
    // 成员（为简化描述起见统一开放，读者可根据需要迕一步封装）
    T data;//数值
    BinNode<T> *parent; //父节点及左、右孩子
    BinNode<T> *lChild;
    BinNode<T> *rChild;
    int height; //高度（通用）
    int npl; //Null Path Length（左式堆，也可直接用height代替）
    RBColor color; //颜色（红黑树）
    // 构造函数
    BinNode() : parent(NULL), lChild(NULL), rChild(NULL), height(0), npl(1), color(RB_RED) {

    }

    BinNode(T e, BinNode<T> *p = NULL, BinNode<T> *lc = NULL, BinNode<T> *rc = NULL, int h = 0, int l = 1,
            RBColor c = RB_RED) : data(e), parent(p), lChild(lc), rChild(rc), height(h), npl(l), color(c) {

    }

    /// 操作接口
    int size(); //统计当前节点后代总数，亦即以其为根的子树的规模

    /// 作为当前节点的左孩子插入新节点
    BinNode<T> *insertAsLC(T const &e) {/*将e作为当前节点的左孩子插入二叉树*/
        return lChild = new BinNode(e, this);
    }

    /// 作为当前节点的右孩子插入新节点
    BinNode<T> *insertAsRC(T const &e) {/*将e作为当前节点癿右孩子插入二叉树*/
        return rChild = new BinNode(e, this);
    }

    /// 取当前节点的直接后继
    BinNode<T> *succ() {
        BinNode<T> *s = this;
        if (rChild) {
            s = rChild;
            while (s->lChild) {
                s = s->lChild;
            }
        } else {
            while (s->parent && s == s->parent->lChild) {
                s = s->parent;
            }
            s = s->parent;
        }
        return s;
    }


    /// 二叉树层次遍历
    template<typename VST>
    void travLevel(VST &) {
        queue<BinNode<T> *> Q;/*辅助队列*/
        Q.push(this);/*根节点入队*/
        while (!Q.empty()) {/*在队列再次变空之前,反复迭代*/
            BinNode<T> *x = Q.front();/*去除队首节点并访问之*/
            Q.pop();
            visit(x->data);
            if (x->lChild) {/*左孩子入队*/
                Q.push(x->lChild);
            }
            if (x->rChild) {/*右孩子入队*/
                Q.push(x->rChild);
            }
        }
    }

    /// 子树先序遍历
    template<typename VST>
    void travPre(VST &);

    /// 子树中序遍历
    template<typename VST>
    void travIn(VST &visit) {/*二叉树中序遍历算法统一入口*/
        switch (rand() % 5) { //此处暂随机选择以做测试，共五种选择
            case 1:
                travIn_I1(this, visit);
                break; //迭代版#1
            case 2:
                travIn_I2(this, visit);
                break; //迭代版#2
            case 3:
                travIn_I3(this, visit);
                break; //迭代版#3
            case 4:
                travIn_I4(this, visit);
                break; //迭代版#4
            default:
                travIn_R(this, visit);
                break; //递归版
        }
    }

    /// 子树后序遍历
    template<typename VST>
    void travPost(VST &);

    /// 小于
    bool operator<(BinNode const &bn) {
        return data < bn.data;
    }

    /// 等于
    bool operator==(BinNode const &bn) {
        return data == bn.data;
    }
};


template<typename T>
class BinTree {
protected:
    int _size;/*规模*/
    BinNode<T> *_root;/*根节点*/

    /// 更新节点x的高度
    /// \param x
    /// \return
    virtual int updateHeight(BinNode<T> *x);

    /// 更新节点x及其祖先的高度
    /// \param x
    void updateHeightAbove(BinNode<T> *x);

public:
    /// 构造函数
    BinTree() : _size(0), _root(NULL) {};

    /// 析构函数
    ~BinTree() {
        if (0 < _size) {
            remove(_root);
        }
    }

    /// 规模
    /// \return
    int size() const {
        return _size;
    }

    /// 判空
    /// \return
    bool empty() const {
        return !_root;
    }

    /// 树根
    /// \return
    BinNode<T> *root() const {
        return _root;
    }

    /// 插入根节点
    /// \param e
    /// \return
    BinNode<T> *insertAsRoot(T const &e);

    /// e作为x的左孩子（原无）插入
    /// \param x
    /// \param e
    /// \return
    BinNode<T> *insertAsLC(BinNode<T> *x, T const &e);

    /// e作为x的右孩子（原无）插入
    /// \param x
    /// \param e
    /// \return
    BinNode<T> *insertAsRC(BinNode<T> *x, T const &e);

    /// S作为x的左子树接入
    /// \param x
    /// \param S
    /// \return
    BinNode<T> *attachAsLC(BinNode<T> *x, BinNode<T> *&S) {
        if (x->lChild = S->_root) {/*接入*/
            x->lChild->parent = x;
        }
        _size += S->_size;/*更新全树规模*/
        updateHeightAbove(x);/*更新与x所有祖先的高度*/
        S->_root = NULL;/*释放原树*/
        S->_size = 0;
        release(S);
        S = NULL;
        return x;/*返回接入位置*/
    }

    /// S作为x的右子树接入
    /// \param x
    /// \param S
    /// \return
    BinNode<T> *attachAsRC(BinNode<T> *x, BinNode<T> *&S) {
        if (x->rChild = S->_root) {/*接入*/
            x->rChild->parent = x;
        }
        _size += S->_size;/*更新全树规模*/
        updateHeightAbove(x);/*更新与x所有祖先的高度*/
        S->_root = NULL;/*释放原树*/
        S->_size = 0;
        release(S);
        S = NULL;
        return x;/*返回接入位置*/
    }

    /// 删除以位置x处节点为根的子树，返回该子树原先的规模
    /// \param x
    /// \return
    int remove(BinNode<T> *x) {/*assert: x为二叉树中的合法位置*/
        fromParentTo(*x) = NULL;/*切断来自父节点的指针*/
        updateHeightAbove(x->parent);/*更新祖先高度*/
        int n = removeAt(x);/*删除子树x*/
        _size -= n;/*更新规模*/
        return n;/*返回删除节点总数*/
    }

    /// 将子树x从当前树中摘除，并将其转换为一颗独立子树
    /// \param x
    /// \return
    BinNode<T> *secede(BinNode<T> *x) {/*assert:x为二叉树中的合法位置*/
        FromParentTo(*x) = NULL;/*切断来自父节点的指针*/
        updateHeightAbove(x->parent);/*更新原树中所有祖先的高度*/
        BinNode<T> *S = new BinTree<T>;/*新树以x为根*/
        S->_root = x;
        x->parent = NULL;
        S->_size = x->size();/*更新规模*/
        _size -= S->_size;
        return S;/*返回分离出来的子树*/
    }

    /// 层次遍历
    /// \tparam VST 操作器
    /// \param visit
    template<typename VST>
    void travLevel(VST &visit) {
        if (_root) {
            _root->travLevel(visit);
        }
    }

    /// 先序遍历
    /// \tparamVST 操作器
    /// \param visit
    template<typename VST>
    void travPre(VST &visit) {
        if (_root) {
            _root->traPrev(visit);
        }
    }

    /// 中序遍历
    /// \tparam VST 操作器
    /// \param visit
    template<typename VST>
    void travIn(VST &visit) {
        if (_root) {
            _root->travIn(visit);
        }
    }

    /// 后序遍历
    /// \tparam VST 操作器
    /// \param visit
    template<typename VST>
    void travPost(VST &visit) {
        if (_root) {
            _root->travPost(visit);
        }
    }

    /// 比较器
    /// \param t
    /// \return
    bool operator<(BinTree<T> const &t) {
        return _root && t._root && lt(_root, t._root);
    }

    /// 判等器
    /// \param t
    /// \return
    bool operator==(BinTree<T> const &t) {
        return _root && t._root && (_root == t._root);
    }
};/*BinTree*/

template<typename T>
static int removeAt(BinNode<T> *x) {
    if (!x) {/*递归基：空树*/
        return 0;
    }
    int n = 1 + removeAt(x->lChild) + removeAt(x->rChild);/*递归释放左、右子树*/
    release(x->data);/*释放被摘除节点*/
    release(x);
    return n;/*返回删除节点总数*/
}

/// 二叉树先序遍历算法
/// \tparam T
/// \tparam VST
/// \param x
/// \param visit
template<typename T, typename VST>
void travPre_R(BinNode<T> *x, VST &visit) {
    if (!x) {
        return;
    }
    visit(x->data);
    travPre_R(x->lChild, visit);
    travPre_R(x->rChild, visit);
}

/// 后序遍历
/// \tparam T
/// \tparam VST
/// \param x
/// \param visit
template<typename T, typename VST>
void travPost_R(BinNode<T> *x, VST &visit) {
    if (!x) {
        return;
    }
    travPost_R(x->lChild, visit);
    travPost_R(x->rChild, visit);
    visit(x->data);
}

/// 中序遍历
/// \tparam T
/// \tparam VST
/// \param x
/// \param visit
template<typename T, typename VST>
void travIn_R(BinNode<T> *x, VST &visit) {
    if (!x) {
        return;
    }
    travIn_R(x->lChild, visit);
    visit(x->data);
    travIn_R(x->rChild, visit);
}

/// 从当前节点出发，沿左分支不断深入，直至没有左分子的节点；沿途节点遇到后立即访问
/// \tparam T
/// \tparam VST
/// \param x
/// \param visit
/// \param S
template<typename T, typename VST>
static void visitAlongLeftBranch(BinNode<T> *x, VST &visit, stack<BinNode<T> *> &S) {
    while (x) {
        visit(x->data);/*访问当前节点*/
        S.push(x->rChild);/*右孩子入栈暂存*/
        x = x->lChild;/*沿左分支深入一层*/
    }
}

/// 二叉树先序遍历算法,迭代版
/// \tparam T
/// \tparam VST
/// \param x
/// \param visit
template<typename T, typename VST>
void travPre_I2(BinNode<T> *x, VST &visit) {
    stack<BinNode<T> *> S;/*辅助线*/
    while (true) {
        visitAlongLeftBranck(x, visit, S);/*从当前节点出发,逐批访问*/
        if (S.empty()) {/*直到栈空*/
            break;
        }
        x = S.pop();/*弹出下一批的起点*/
    }
}

/// 从当前节点出发,沿左分支不断深入,直至没有左分支的节点
/// \tparam T
/// \param x
/// \param S
template<typename T>
static void goAlongleftBranch(BinNode<T> *x, stack<BinNode<T> *> &S) {
    while (x) {/*当前节点入栈后随即向左侧分支深入,迭代直到无左孩子*/
        S.push(x);
        x = x->lChild;
    }
}

/// 二叉树中序遍历算法
/// \tparam T
/// \tparam VST
/// \param x
/// \param visit
template<typename T, typename VST>
void travIn_I1(BinNode<T> *x, VST &visit) {
    stack<BinNode<T> *> S;/*辅助线*/
    while (true) {
        goAlongleftBranch(x, S);/*从当前节点出发,逐批入栈*/
        if (S.empty()) {/*直至所有节点处理完毕*/
            break;
        }
        x = S.pop();/*弹出栈顶结点并访问之*/
        visit(x->data);
        x = x->rChild;/*转向右子树*/
    }
}

/// 二叉树中序遍历算法
/// \tparam T
/// \tparam VST
/// \param x
/// \param visit
template<typename T, typename VST>
void travIn_I2(BinNode<T> *x, VST &visit) {
    stack<BinNode<T> *> S;/*辅助线*/
    while (true) {
        if (x) {
            S.push(x);/*根节点进栈*/
            x = x->lChild;/*深入遍历左子树*/
        } else if (!S.empty()) {
            x = S.pop();/*尚未访问的是最低祖先节点退栈*/
            visit(x->data);/*访问该祖先节点*/
            x = x->rChild;/*遍历祖先的右子树*/
        } else {
            break;/*遍历完成*/
        }
    }
}

/// 二叉树中序遍历算法,无需辅助线
/// \tparam T
/// \tparam VST
/// \param x
/// \param visit
template<typename T, typename VST>
void travIn_I3(BinNode<T> *x, VST &visit) {
    bool backtrack = false;/*前一步是否刚从右子树回溯(省去栈,经o(1)辅助空间*/
    while (true) {
        if (!backtrack && x->lChild) {/*若有左子树且不是刚刚回溯,则*/
            x = x->lChild;/*深入遍历左子树*/
        } else {/*否则*/
            visit(x->data);/*访问该节点*/
            if (x->rChild) {/*若其右节点非空,则*/
                x = x->rChild;/*深入右子树继续遍历*/
                backtrack = false;/*并关闭回溯标志*/
            } else {/*若右子树空,则*/
                if (!(x = x->succ())) {/*回溯*/
                    break;
                }
                backtrack = true;/*并设置回溯标志*/
            }
        }
    }
}

/// 在以S栈顶节点为根的子树中,找到最高左侧可见叶节点
/// \tparam T
/// \param S
template<typename T>
static void gotoHLVFL(stack<BinNode<T> *> &S) {
    while (BinNode<T> *x = S.top()) {/*自顶向下,反复检查当前节点(即栈顶)*/
        if (x->lChild) {/*尽可能向左*/
            if (x->rChild) {/*若有右孩子,优先入栈*/
                S.push(x->rChild);
            }
            S.push(x->lChild);/*然后才转至左孩子*/
        } else {/*实不得已*/
            S.push(x->rChild);/*才向右*/
        }
    }
    S.pop();/*返回之前,弹出栈顶的空节点*/
}

/// 二叉树的后序遍历
/// \tparam T
/// \tparam VST
/// \param x
/// \param visit
template<typename T, typename VST>
void travPost_T(BinNode<T> *x, VST &visit) {
    stack<BinNode<T> *> S;/*辅助栈*/
    if (x) {/*根节点入栈*/
        S.push(x);
    }
    while (!S.empty()) {
        if (S.top() != x->parent) {/*若栈顶非当前节点之父(则必为其右兄),此时需*/
            gotoHLVFL(S);/*在以其右兄为根之子树中,找到HLVFL(相当于递归深入其中)*/
        }
        x = S.pop();/*弹出栈顶*/
        visit(x->data);/*访问*/
    }
}

template<typename K, typename V>
struct Entry {
    K key;/*关键码*/
    V value;/*数值*/

    /**
     * 默认构造函数
     * @param k
     * @param v
     */
    Entry(K k = K(), V v = V()) : key(k), value(v) {};

    /**
     * 基于克隆的构造函数
     * @param e
     */
    Entry(Entry<K, V> const &e) : key(e.key), value(e.value) {};

    /**
     * 比较器：小于
     * @param e
     * @return
     */
    bool operator<(Entry<K, V> const &e) {
        return key < e.key;
    }

    /**
     * 比较器：大于
     * @param e
     * @return
     */
    bool operator>(Entry<K, V> const &e) {
        return key > e.key;
    }

    /**
     * 比较器：等于
     * @param e
     * @return
     */
    bool operator==(Entry<K, V> const &e) {
        return key == e.key;
    }

    /**
     * 比较器：不等于
     * @param e
     * @return
     */
    bool operator!=(Entry<K, V> const &e) {
        return key != e.key;
    }
};

template<typename T>
class BST : public BinTree<T> {
protected:
    BinNode<T> *_hot;/*BST::search()最后访问的非空的节点位置*/

    /**
     * 按照“3+4”结构，联接3个节点及四棵子树
     * @return
     */
    BinNode<T> *
    connect34(BinNode<T> *, BinNode<T> *, BinNode<T> *, BinNode<T> *, BinNode<T> *, BinNode<T> *, BinNode<T> *);

    /**
     * 对x及其父亲、祖父做统一旋转调整
     * @param x
     * @return
     */
    BinNode<T> *rotateAt(BinNode<T> *x);

public:
    /**
     * 查找
     * @param e
     * @return
     */
    virtual BinNode<T> *&search(const T &e) {
        return searchIn(BinTree<T>::_root, e, _hot = NULL);
    }

    /**
     * 插入
     * @param e
     * @return
     */
    virtual BinNode<T> *insert(const T &e) {
        BinNode<T> *&x = search(e);/*确认目标节点不存在*/
        if (x) {
            return x;
        }
        x = new BinNode<T>(e, _hot);/*创建新节点：以e为关键字，以_hot为父*/
        BinTree<T>::_size++;/*更新x及其历代祖先的高度*/
        updateHeightAbove(x);
        return x;/*新插入的节点，必为叶子*/
    }

    /**
     * 删除
     * @param e
     * @return
     */
    virtual bool remove(const T &e) {
        BinNode<T> *&x = search(e);/*确认目标节点存在*/
        if (!x) {
            return false;
        }
        removeAt(x, _hot);/*实施删除*/
        updateHeightAbove(_hot);/*更新_hot及其历代祖先的高度*/
        return true;
    }
};

/**
 * 在以v为根的（AVL，SPLAY，rbTree等）BST子树中直接查找关键码
 * @tparam T
 * @param v
 * @param e
 * @param hot
 * @return
 */
template<typename T>
static BinNode<T> *&searchIn(BinNode<T> *&v, const T &e, BinNode<T> *&hot) {
    if (!v || (e == v->data)) {/*递归基：在节点v（或假想的通配节点）处命中*/
        return v;
    }
    hot = v;/*一般情况：先记下当前节点*/
    return searchIn(((e < v->data) ? v->lChild : v->rChild), e, hot);/*深入一层，递归查找*/
}

template<typename T>
static BinNode<T> *removeAt(BinNode<T> *&x, BinNode<T> *&hot) {
    BinNode<T> *w = x;/*实际被摘除的节点，初值同x*/
    BinNode<T> *succ = NULL;/*实际被删除节点的接替者*/
    if (!x->rChild) {/*若左子树为空*/
        succ - x - x->rChild;/*直接将*x的左子树替换为右子树*/
    } else if (!x->rChild) {/*若右子树为空*/
        succ = x = x->lChild;/*对称地处理*/
    } else {/*若左右子树均存在，则选择x的直接后继作为实际被摘除节点*/
        w = w->succ();/*在右子树中再到*x的直接后继*/
        swap(x->data, w->data);/*交换*x和*w的数据元素*/
        BinNode<T> *u = w->parent;
        ((u == x) ? u->rChild : u->lChild) = succ = w->rChild;/*隔离节点*w*/
    };
    hot = w->parent;/*记录实际被删除节点的父亲*/
    if (succ) {/*将被删除节点的接替者与hot相联*/
        succ->parent = hot;
    }
    release(w->data);/*释放被摘除节点，返回接替者*/
    release(w);
    return succ;
}



template<typename T>
class AVL : public BST<T> {
public:
    /**
     * 插入（重写）
     * @param e
     * @return
     */
    BinNode<T> *insert(const T &e) {
        BinNode<T> *&x = search(e);
        if (x) {
            return x;
        }
        x = new BinNode<T>(e, BST<T>::_hot);
        BinNode<T>::_size++;
        for (BinNode<T> *g = BST<T>::_hot; g; g = g->parent) {
            if (!AvlBalanced(*g)) {
                FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
                break;
            } else {

            }
        }
    }

    /**
     * 删除（重写）
     * @param e
     * @return
     */
    bool remove(const T &e);
};

#endif //BINARY_TREE_BINTREE_H
