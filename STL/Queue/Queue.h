//
// Created by Administrator on 2021/7/20.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include "List.h"

using namespace std;

template<typename T>
class Queue:public List<T>{
public:
    /// 入队：尾部插入
    /// \param e
    void enqueue(T const &e);

    /// 出队：首部删除
    /// \return
    T dequeue();

    /// 队首
    /// \return
    T &front();
};


#endif //QUEUE_QUEUE_H
