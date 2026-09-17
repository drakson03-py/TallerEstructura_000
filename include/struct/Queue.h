
#ifndef TALLERESTRUCT_QUEUE_H
#define TALLERESTRUCT_QUEUE_H
#include "Node.h"

/**
     * Clase "Queue" implementacion de la EDD cola(Queue) de tipo FIFO(First in first out)
     */

template <class T>
class Queue {
private:
    /**
     * Variable tipo Puntero hacia el primer elemento de la cola
     */
    Node<T>* first;
public:
    /**
     * Constructor
     */
    Queue();

    /**
     * Constructor copia
     */
    Queue(const Queue& q);

    /**
     *
     * @return Retorna True si la cola esta vacia y False si contiene algun dato
     */
    bool empty();

    /**
     *
     * Inserta el dato tipo T(Generico) al final de la fila.
     */
    void push(T value);

    /**
     * Elimina el primer dato de la cola y convierte el next en el primer dato.
     */
    void pop();

    /**
     *
     * @return retorna el primer dato de la cola
     */
    T front();

    /**
     * Elimina todas las referencias o datos de la cola
     */
    void clear();

    /**
     *
     * @return retorna la cantidad de datos almacenados en la cola
     */
    int size();

    /**
     * Destructor
     */
    ~Queue();
};

#include "Queue.tpp"
#endif //TALLERESTRUCT_QUEUE_H