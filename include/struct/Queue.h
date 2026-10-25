
#ifndef TALLERESTRUCT_QUEUE_H
#define TALLERESTRUCT_QUEUE_H

#include "Node.h"

/**
 * @brief Implementación de una cola genérica de tipo FIFO.
 *
 * Los elementos se insertan al final y se eliminan desde el principio.
 *
 * @tparam T Tipo de dato que almacena la cola.
 */
template <class T>
class Queue {
private:
    /**
     * @brief Puntero que almacena la dirección del primer nodo de la cola.
     */
    Node<T>* first;

public:
    /**
     * @brief Constructor.
     * Inicializa una cola vacía.
     */
    Queue();

    /**
     * @brief Constructor copia de la cola.
     *
     * Crea una copia de los nodos de la cola recibida.
     *
     * @param q Cola que se quiere copiar.
     */
    Queue(const Queue& q);

    /**
     * @brief Verifica si la cola está vacía.
     *
     * @return true si la cola está vacía y false si contiene algún dato.
     */
    bool empty();

    /**
     * @brief Inserta un elemento al final de la cola.
     *
     * @param value Elemento que se quiere insertar.
     */
    void push(T value);

    /**
     * @brief Elimina el primer elemento de la cola.
     *
     * El siguiente elemento pasa a ser el primero.
     *
     * @throw nullptr Si la cola está vacía.
     */
    void pop();

    /**
     * @brief Devuelve el primer elemento de la cola.
     *
     * @return Elemento de tipo genérico T almacenado al inicio.
     *
     * @throw nullptr Si la cola está vacía.
     */
    T front();

    /**
     * @brief Elimina todos los nodos de la cola.
     */
    void clear();

    /**
     * @brief Devuelve la cantidad de elementos almacenados en la cola.
     *
     * @return Cantidad de elementos.
     */
    int size();

    /**
     * @brief Destructor.
     *
     * Libera los nodos restantes de la cola.
     */
    ~Queue();
};

#include "Queue.tpp"

#endif // TALLERESTRUCT_QUEUE_H