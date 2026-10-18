

#include "Stack.h"

template<class T>
Stack<T>::Stack(): last(nullptr){}
template <class T>
Stack<T>::Stack(const Stack& s):last(nullptr) {
    Node<T>* cur = s.last;
    if (!cur){return;}
    this ->last = new Node<T>(cur->getValue());
    Node<T>* curCopy = this -> last;

    while (cur->getNext()) {
        curCopy -> setNext(new Node(cur -> getNext()->getValue()));
        cur = cur ->getNext();
    }
}

template<class T>
bool Stack<T>::empty() {
    return !this->last;
}

template<class T>
void Stack<T>::push(T value) {
    if (this->empty()) {
        this->last = new Node<T>(value);
        return;
    }
    Node<T>* aux = this->last;
    this->last = new Node<T>(value);
    this->last->setNext(aux);
}

template<class T>
void Stack<T>::pop() {
    if (this->empty()) throw nullptr;

    Node<T>* targetPop = this->last;
    this->last = this->last ->getNext();
    delete targetPop;
}

template<class T>
T Stack<T>::top() {
    if (this->empty())throw nullptr;
    return this->last->getValue();
}

template<class T>
void Stack<T>::clear() {
    while (this->last) {
        Node<T>* targetDelete = this->last;
        this->last = this->last->getNext();
        delete targetDelete;
    }
}

template<class T>
int Stack<T>::size() {
    if (this->empty())return 0;
    int contador = 0;
    Node<T>* cur = this->last;
    while (cur) {
        contador++;
        cur = cur->getNext();
    }
    return contador;
}

template<class T>
Stack<T>::~Stack() {
    this->clear();
}
