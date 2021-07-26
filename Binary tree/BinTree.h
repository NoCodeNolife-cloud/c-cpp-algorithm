//
// Created by Administrator on 2021/7/24.
//

#ifndef BINARY_TREE_BINTREE_H
#define BINARY_TREE_BINTREE_H
#define stature(p) ((P)?(p)->height:-1);//节点高度（与“空树高度为-1”的约定相统一）

#include <stack>

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


    /// 子树层次遍历
    template<typename VST>
    void travLevel(VST &);

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

#endif //BINARY_TREE_BINTREE_H
