
#include "BTNode.h"

template<class T>
BTNode<T>::BTNode(T value)
    : value(value), left(nullptr), right(nullptr) {}

template<class T>
T BTNode<T>::getValue() const{
    return this->value;
}

template<class T>
BTNode<T>* BTNode<T>::getLeft() const{
    return this->left;
}

template<class T>
BTNode<T>* BTNode<T>::getRight() const{
    return this->right;
}


template<class T>
void BTNode<T>::setLeft(BTNode<T>* left) {
    this->left = left;
}

template<class T>
void BTNode<T>::setRight(BTNode<T>* right) {
    this->right = right;
}

template<class T>
BTNode<T>::~BTNode() = default;


