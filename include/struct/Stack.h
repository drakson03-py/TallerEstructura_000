
#ifndef TALLERESTRUCT_STACK_H
#define TALLERESTRUCT_STACK_H

#include "Node.h"

/**
 * @brief Implementación de una pila genérica de tipo LIFO.
 *
 * El último elemento insertado es el primero en eliminarse.
 *
 * @tparam T Tipo de dato que almacena la pila.
 */
template <class T>
class Stack {
private:
    /**
     * @brief Puntero que almacena la dirección del último nodo insertado.
     */
    Node<T>* last;

public:
    /**
     * @brief Constructor.
     * Inicializa una pila vacía.
     */
    Stack();

    /**
     * @brief Constructor copia de la pila.
     *
     * Crea una copia de los nodos de la pila recibida.
     *
     * @param s Pila que se quiere copiar.
     */
    Stack(const Stack& s);

    /**
     * @brief Verifica si la pila está vacía.
     *
     * @return true si la pila está vacía, false si tiene elementos.
     */
    bool empty();

    /**
     * @brief Inserta un elemento en la cabeza de la pila.
     *
     * @param value Elemento que se quiere insertar.
     */
    void push(T value);

    /**
     * @brief Elimina el elemento de la cabeza de la pila.
     *
     * El siguiente elemento pasa a ser la nueva cabeza.
     *
     * @throw nullptr Si la pila está vacía.
     */
    void pop();

    /**
     * @brief Devuelve el elemento ubicado en la cabeza de la pila.
     *
     * @return Elemento de tipo genérico T.
     *
     * @throw nullptr Si la pila está vacía.
     */
    T top();

    /**
     * @brief Elimina todos los elementos de la pila.
     *
     * Libera los nodos almacenados y deja la pila vacía.
     */
    void clear();

    /**
     * @brief Devuelve la cantidad de elementos almacenados en la pila.
     *
     * @return Cantidad de elementos.
     */
    int size();

    /**
     * @brief Destructor.
     *
     * Libera los nodos restantes de la pila.
     */
    ~Stack();
};

#include "Stack.tpp"

#endif // TALLERESTRUCT_STACK_H
