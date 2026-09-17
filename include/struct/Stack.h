

#ifndef TALLERESTRUCT_STACK_H
#define TALLERESTRUCT_STACK_H
#include "Node.h"

template <class T>
class Stack {
private:
    Node<T>* last;
public:
    Stack();
    bool empty();
    void push(T value);
    void pop();
    T top();
    void clear();
    int size();
    ~Stack();
};

#include "Stack.tpp"
#endif //TALLERESTRUCT_STACK_H