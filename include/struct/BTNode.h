//
// Created by seba2 on 21-10-2026.
//

#ifndef TALLERESTRUCT_BTNODE_H
#define TALLERESTRUCT_BTNODE_H
template <class T>
class BTNode {
private:
    T value;
    BTNode* left;
    BTNode* right;
public:
    BTNode(T value);
    T getValue() ;
    BTNode* getLeft() ;
    BTNode* getRight() ;
    void setLeft(BTNode* left);
    void setRight(BTNode* right);
    ~BTNode();
};


#include "BTNode.tpp"
#endif //TALLERESTRUCT_BTNODE_H