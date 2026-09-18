
#ifndef TALLERESTRUCT_NODE_H
#define TALLERESTRUCT_NODE_H



/**
 * Implementacion de un nodo generico para almacenar datos
 * @tparam T Tipo de dato que almacena la lista
 */
template <class T>
class Node {
private:
    /**
     * Variable que almacena el dato de tipo genérico
     */
    T value;

    /**
     * Puntero que almacena la dirección del siguiente nodo
     */
    Node<T>* next;
public:
    /**
     * Constructor del nodo
     * @param value Dato que se quiere almacenar en el nodo
     */
    Node(T value);

    /**
     * Devuelve el dato almacenado en el nodo
     * @return Dato de tipo genérico T
     */
    T getValue();

    /**
     * Devuelve el siguiente nodo
     * @return Puntero al siguiente nodo
     */
    Node<T>* getNext();

    /**
     * Establece el siguiente nodo
     * @param next Puntero al nodo que se quiere enlazar
     */
    void setNext(Node<T>* next);

    /**
     * Modifica el elemento del nodo
     * @param value Nuevo elemento que se quiere almacenar
     */
    void setValue(T value);

    /**
     * Destructor de la clase
     */
    ~Node();
};

#include "Node.tpp"
#endif //TALLERESTRUCT_NODE_H