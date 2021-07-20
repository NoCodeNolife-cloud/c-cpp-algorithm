//
// Created by Administrator on 2021/7/20.
//

#ifndef QUEUE_LISTNODE_H
#define QUEUE_LISTNODE_H


template<typename T>
class ListNode {
public:
    T data;/*数值*/
    ListNode<T> *pred;/*前驱*/
    ListNode<T> *succ;/*后继*/

    /**
    * 针对header和trailer的构造
    */
    ListNode();

    /**
    * 默认构造器
    */
    ListNode(T e, ListNode<T> *p = nullptr, ListNode<T> *s = nullptr);

    /**
    * 紧靠当前节点之前插入新节点
    * @return
    */
    ListNode<T> *insertAsPred(T const &e);

    /**
    * 紧随当前节点之后插入新节点
    * @return
    */
    ListNode<T> *insertAsSucc(T const &e);
};


#endif //QUEUE_LISTNODE_H
