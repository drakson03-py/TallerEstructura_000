

#ifndef TALLERESTRUCT_STACK_H
#define TALLERESTRUCT_STACK_H
#include "Node.h"

/**
     * Clase "Stack" implementacion de la EDD pila(Stack) de tipo LIFO(Last in first out)
     */

template <class T>
class Stack {
private:
    /**
     * Variable tipo Puntero hacia la base de la pila
     */
    Node<T>* last;
public:
    /**
     * Constructor
     */
    Stack();
    Stack(const Stack& s);

    /**
     *
     * @return
     */
    bool empty();

    /**
     *
     * Agrega a value al cabezal de la pila .
     */
    void push(T value);

    /**
     * Elimina el cabezal de la pila, en caso de haber mas datos el dato last se convertira en el nuevo cabezal
     */
    void pop();

    /**
     *
     * @return retorna el dato T que esta almacenado al final del stack
     */
    T top();

    /**
     * Elimina todos los datos almacenados en la pila.
     */
    void clear();

    /**
     *
     * @return retorna la cantidad de datos almacenados en la pila.
     */
    int size();
    ~Stack();
};

#include "Stack.tpp"
#endif //TALLERESTRUCT_STACK_H