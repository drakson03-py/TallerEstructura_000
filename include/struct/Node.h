//
// Created by seba2 on 04-09-2026.
//

#ifndef TALLER_1_NODE_H
#define TALLER_1_NODE_H
template <class T>

class Node {
private:
    T value;
    Node<T>* next;
public:
    Node(T value);
    T getValue();
    Node<T>* getNext();

    void setNext(Node<T>* next);

    void setValue(T value);
    ~Node();

};

#include "struct/Node.tpp"
#endif //TALLER_1_NODE_H