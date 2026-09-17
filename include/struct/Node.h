
#ifndef TALLERESTRUCT_NODE_H
#define TALLERESTRUCT_NODE_H
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

#include "Node.tpp"
#endif //TALLERESTRUCT_NODE_H