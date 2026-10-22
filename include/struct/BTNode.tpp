//
// Created by seba2 on 21-10-2026.
//

#include "BTNode.h"

template<class T>
BTNode<T>::BTNode(T value):value(value),left(nullptr),right(nullptr) {}

template<class T>
T BTNode<T>::getValue()  {
    return this->value;
}

template<class T>
BTNode<T>* BTNode<T>::getLeft() {
    return this->left;
}

template<class T>
BTNode<T>* BTNode<T>::getRight()  {
    return this->right;
}

template<class T>
void BTNode<T>::setLeft(BTNode* left) {
    this->left = left;
}

template<class T>
void BTNode<T>::setRight(BTNode* right) {
    this->right = right;
}

template<class T>
BTNode<T>::~BTNode()=default;