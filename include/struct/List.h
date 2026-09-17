
#ifndef TALLERESTRUCT_LIST_H
#define TALLERESTRUCT_LIST_H
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
#endif //TALLERESTRUCT_LIST_H