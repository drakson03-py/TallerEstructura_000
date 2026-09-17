//
// Created by seba2 on 05-09-2026.
//

#include "Queue.h"

template<class T>
Queue<T>::Queue() {
    this -> first = nullptr;
}

template<class T>
bool Queue<T>::empty() {
    return !this -> first;
}

template<class T>
void Queue<T>::push(T value) {
    if (this -> empty()) {
        this -> first = new Node<T>(value);
        return;
    }

    Node<T>* cur = this->first;

    while (cur->getNext()) {
        cur = cur->getNext();
    }

    cur -> setNext(new Node<T>(value));
}



template<class T>
void Queue<T>::pop() {
    if (this->empty()) {
        throw nullptr;
    }

    Node<T>* targetPop = this->first;
    this ->first = this->first-> getNext();
    delete targetPop;
}

template<class T>
T Queue<T>::front() {
    if (this->empty()) throw nullptr;
    return this->first->getValue();
}

template<class T>
void Queue<T>::clear() {
    while (this->first) {
        Node<T>* targetDelete = this->first;
        this->first = this->first -> getNext();
        delete targetDelete;
    }
}

template<class T>
int Queue<T>::size() {
    if (this->empty()) return 0;
    int contador = 0;
    Node<T>* cur = this->first;
    while (cur) {
        contador++;
        cur = cur->getNext();
    }
    return contador;
}

template<class T>
Queue<T>::~Queue() {
    this->clear();
}


