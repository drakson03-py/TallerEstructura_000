

#ifndef TALLERESTRUCT_STACK_H
#define TALLERESTRUCT_STACK_H
#include "Node.h"

/**
 * Implementación de una pila genérica de tipo LIFO
 * @tparam T
 */
template <class T>
class Stack {
private:
    /**
     * Puntero que almacena la dirección del ultimo nodo insertado
     */
    Node<T>* last;
public:
    /**
     * Constructor
     */
    Stack();

    /**
     * Constructor copia de la pila
     * @param s Pila que se quiere copiar
     */
    Stack(const Stack& s);

    /**
     * Verifica si la pila está vaia
     * @return true si la pila está vacía, false si tiene elementos
     */
    bool empty();

    /**
     * Inserta un elemento en la cabeza de la pila
     * @param value Elemento que se quiere insertar
     */
    void push(T value);

    /**
     * Elimina el elemento de la cabeza de la pila
     *
     * El siguiente pasa a ser la nueva cabeza
     */
    void pop();

    /**
     * Devuelve el elemento ubicado en la cabeza de la pila
     * @return Elemento de tipo generico T
     */
    T top();

    /**
     * Elimina todos los elementos de la pila
     */
    void clear();

    /**
     * Devuelve la cantidad de elementos almacenados en la pila
     * @return Cantidad de elementos
     */
    int size();

    /**
     * Destructor
     */
    ~Stack();
};

#include "Stack.tpp"
#endif //TALLERESTRUCT_STACK_H