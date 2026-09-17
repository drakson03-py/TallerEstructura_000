//
// Created by seba2 on 04-09-2026.
//

#ifndef TALLER_1_LIST_H
#define TALLER_1_LIST_H
#include "Node.h"

template <class T>
class List {
private:
    Node<T>* start;
public:
    List();
    bool isEmpty();
    void insert(T value, int index);
    void insertFirst(T value);
    void insertLast(T value);
    T get(int index);
    T getFirst();
    T getLast();
    void remove(int index);
    void clear();
    ~ List();
};

#include "List.tpp"
#endif //TALLER_1_LIST_H