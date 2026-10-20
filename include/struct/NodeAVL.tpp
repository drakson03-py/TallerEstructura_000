//
// Created by Alan Galleguillos on 19-10-2026.
//

#include "NodeAVL.h"


template <typename T>
NodoAVL<T>::NodoAVL(T valor) {
    this->dato = valor;
    this->izquierdo = nullptr;
    this->derecho = nullptr;
    this->altura = 1;
}

// Getters
template <typename T>
T NodoAVL<T>::getDato() const {
    return dato;
}

template <typename T>
NodoAVL<T>* NodoAVL<T>::getIzquierdo() const {
    return izquierdo;
}

template <typename T>
NodoAVL<T>* NodoAVL<T>::getDerecho() const {
    return derecho;
}

template <typename T>
int NodoAVL<T>::getAltura() const {
    return altura;
}

// Setters
template <typename T>
void NodoAVL<T>::setDato(T valor) {
    dato = valor;
}

template <typename T>
void NodoAVL<T>::setIzquierdo(NodoAVL<T>* nodo) {
    izquierdo = nodo;
}

template <typename T>
void NodoAVL<T>::setDerecho(NodoAVL<T>* nodo) {
    derecho = nodo;
}

template <typename T>
void NodoAVL<T>::setAltura(int alt) {
    altura = alt;
}


