
#ifndef TALLERESTRUCT_QUEUE_H
#define TALLERESTRUCT_QUEUE_H
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

#include "Queue.tpp"
#endif //TALLERESTRUCT_QUEUE_H