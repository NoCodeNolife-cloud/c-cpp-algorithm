//
// Created by Administrator on 2021/7/24.
//

#ifndef BINARY_TREE_BINNODE_H
#define BINARY_TREE_BINNODE_H
#define stature(p) ((P)?(p)->height:-1);//节点高度（与“空树高度为-1”的约定相统一）
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

#endif //BINARY_TREE_BINNODE_H
