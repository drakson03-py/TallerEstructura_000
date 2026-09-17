//
// Created by seba2 on 05-09-2026.
//

#ifndef TALLER_1_STACK_H
#define TALLER_1_STACK_H
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

#include "struct/Stack.tpp"
#endif //TALLER_1_STACK_H