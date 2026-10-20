//
// Created by Alan Galleguillos on 19-10-2026.
//

#ifndef TALLERESTRUCT_NODEAVL_H
#define TALLERESTRUCT_NODEAVL_H

template <typename T>
class NodoAVL {
private:
    T dato;
    NodoAVL<T>* izquierdo;
    NodoAVL<T>* derecho;
    int altura;

public:
    // Constructor
    explicit NodoAVL(T valor);

    ~NodoAVL() = default;

    T getDato() const;
    NodoAVL<T>* getIzquierdo() const;
    NodoAVL<T>* getDerecho() const;
    int getAltura() const;

    void setDato(T valor);
    void setIzquierdo(NodoAVL<T>* nodo);
    void setDerecho(NodoAVL<T>* nodo);
    void setAltura(int alt);
};

#include "NodeAVL.tpp"
#endif //NODOAVL_HPP