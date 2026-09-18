
#ifndef TALLERESTRUCT_QUEUE_H
#define TALLERESTRUCT_QUEUE_H
#include "Node.h"


/**
 * Implementación de una cola genérica de tipo FIFO
 * @tparam T Tipo de dato que almacena la lista
 */
template <class T>
class Queue {
private:
    /**
     * Puntero que almacena la dirección del primer nodo de la cola
     */
    Node<T>* first;

public:
    /**
     * Constructor
     */
    Queue();

    /**
     * Constructor copia de la cola
     * @param q Cola que se quiere copiar
     */
    Queue(const Queue& q);

    /**
     * Verifica si la cola está vacia
     * @return true si la cola esta vacia y false si contiene algun dato
     */
    bool empty();

    /**
     * Inserta un elemento al final de la cola
     * @param value Elemento que se quiere insertar
     */
    void push(T value);

    /**
     * Elimina el primer elemento de la cola
     *
     * El siguiente elemento pasa a ser el primero
     */
    void pop();

    /**
     * Devuelve el primer elemento de la cola
     * @return Elemento de tipo genérico T
     */
    T front();

    /**
     * Elimina todos los elementos de la cola
     */
    void clear();

    /**
     * Devuelve la cantidad de elementos almacenados en la cola
     * @return Cantidad de elementos
     */
    int size();

    /**
     * Destructor
     */
    ~Queue();
};

#include "Queue.tpp"
#endif //TALLERESTRUCT_QUEUE_H