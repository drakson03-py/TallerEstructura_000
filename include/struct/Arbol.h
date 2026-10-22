//
// Created by seba2 on 22-10-2026.
//

#ifndef TALLERESTRUCT_ARBOL_H
#define TALLERESTRUCT_ARBOL_H
template <class T>
class Arbol {
private:
    BTNode<T> raiz;
public:
    int altura();
};
#endif //TALLERESTRUCT_ARBOL_H