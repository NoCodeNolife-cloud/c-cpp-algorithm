//
// Created by Administrator on 2021/7/16.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
#define N_OPTR 9

#include "Vector.h"

using namespace std;

template<typename T>
class Stack : public Vector<T> {/*将向量的首/末端作为栈底/顶*/
public:
    /**
     * size()/empty()以及其他开放接口，均可使用
     * @param e
     */
    void push(T const &e);

    /**
     * 出栈：等效于删除向量的末元素插入
     * @return
     */
    T pop();

    /**
     * 取顶：直接返回向量的末元素
     * @return
     */
    T &top();
};


#endif //STACK_STACK_H
