

#include "Node.h"
template <class T>
Node<T>::Node(T value):value(value) {
    this -> next = nullptr;
}
template <class T>
T Node<T>::getValue() {return this -> value;}

template <class T>
Node<T>* Node<T>::getNext() {
    return this ->next;
}

template <class T>
void Node<T>::setNext(Node<T>* next) {
    this -> next = next;
}

template <class T>
void Node<T>:: setValue(T value) {
    this -> value = value;
}

template<class T>
Node<T>::~Node() = default;





