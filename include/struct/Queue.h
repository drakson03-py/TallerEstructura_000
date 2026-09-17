//
// Created by seba2 on 05-09-2026.
//

#ifndef TALLER_1_QUEUE_H
#define TALLER_1_QUEUE_H
#include "Node.h"

template <class T>
class Queue {
private:
    Node<T>* first;
public:
    Queue();
    bool empty();
    void push(T value);
    void pop();
    T front();
    void clear();
    int size();
    ~Queue();
};

#include "struct/Queue.tpp"
#endif //TALLER_1_QUEUE_H