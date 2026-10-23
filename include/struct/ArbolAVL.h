//
// Created by Alan Galleguillos on 23-10-2026.
//

#ifndef TALLERESTRUCT_ARBOLAVL_H
#define TALLERESTRUCT_ARBOLAVL_H

#include "NodeAVL.h"
#include <iostream>

template <typename T>
class ArbolAVL {
private:
    NodoAVL<T>* raiz;

    int obtenerAltura(NodoAVL<T>* nodo);
    int obtenerFactorBalance(NodoAVL<T>* nodo);
    int max(int a, int b);

    NodoAVL<T>* rotacionDerecha(NodoAVL<T>* y);
    NodoAVL<T>* rotacionIzquierda(NodoAVL<T>* x);

    NodoAVL<T>* insertarRecursivo(NodoAVL<T>* nodo, T valor);
    void destruirArbol(NodoAVL<T>* nodo);

    void inOrdenRecursivo(NodoAVL<T>* nodo);
    void preOrdenRecursivo(NodoAVL<T>* nodo);
    void postOrdenRecursivo(NodoAVL<T>* nodo);

public:
    ArbolAVL();
    ~ArbolAVL();

    NodoAVL<T>* getRaiz();
    void insertar(T valor);
    void mostrarInOrden();
    void mostrarPreOrden();
    void mostrarPostOrden();
};

#include "ArbolAVL.tpp"

#endif // ARBOLAVL_HPP
