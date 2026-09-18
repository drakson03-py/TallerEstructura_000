
#include "List.h"

template<class T>
List<T>::List() {
    this -> start = nullptr;//Reserva memoria
}

template<class T>
bool List<T>::isEmpty() {
    return !start;
}

template<class T>
void List<T>::insert(T value, int index) {
    if (index < 0 || this -> isEmpty()) throw nullptr;
    if (index - 1 < 0) {
        this->insertFirst(value);
        return;
    }
    Node<T>* cur = start;
    for (int i = 0; i<index - 1;i++) {
        if (cur ->getNext() == nullptr) throw nullptr;
        cur = cur->getNext();
    }
    Node<T>* n = new Node<T>(value);
    n->setNext(cur->getNext());
    cur->setNext(n);
}

template<class T>
void List<T>::insertFirst(T value) {
    Node<T>* n = new Node<T>(value);
    if (this -> isEmpty()) {
        this -> start = n;
        return;
    }
    n->setNext(start);
    this -> start = n;
}

template<class T>
void List<T>::insertLast(T value) {
    Node<T>* n = new Node<T>(value);
    if (this->isEmpty()) {
        this->start = n;
        return;
    }
    Node<T>* cur = start;
    while (cur->getNext()) {
        cur = cur->getNext();
    }
    cur -> setNext(n);
}

template<class T>
T List<T>::get(int index) {
    if (index < 0 || this->isEmpty())throw nullptr;
    Node<T>* cur = this-> start;
    for (int i=0 ; i < index ; i++) {
        if (cur->getNext() == nullptr) throw nullptr;
        cur = cur->getNext();
    }
    return cur->getValue();
}

template<class T>
T List<T>::getFirst() {
    if (this -> isEmpty()) throw nullptr;

    return this -> start -> getValue();
}

template<class T>
T List<T>::getLast() {
    if (this -> isEmpty()) throw nullptr;

    Node<T>* cur = this -> start;
    while (cur -> getNext()) {
        cur = cur -> getNext();
    }
    return cur -> getValue();
}

template<class T>
void List<T>::remove(int index) {
    if (index < 0 || this -> isEmpty()) throw nullptr;

   if (index - 1 < 0) {
        Node<T>* targetRemove = this->start;
        this -> start = this -> start -> getNext();
        delete targetRemove;
        return;
    }
    Node<T>* cur = start;
    for (int i=0; i<index-1 ; i++) {
        if (cur->getNext() == nullptr) throw nullptr;
        cur = cur->getNext();
    }
    Node<T>* targetRemove = cur ->getNext();
    cur -> setNext(targetRemove -> getNext());
    delete targetRemove;

}

template<class T>
void List<T>::clear() {
    while (start) {
        Node<T>* cur = this->start;
        start = start->getNext();
        delete cur;
    }
}


template<class T>
List<T>::~List() {
    this -> clear();
}