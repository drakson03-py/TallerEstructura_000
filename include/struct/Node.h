
#ifndef TALLERESTRUCT_NODE_H
#define TALLERESTRUCT_NODE_H

/**
     * Clase "Node" representa un nodo individual para almacenar datos de forma enlazada
     */
/**
     * T tipo de dato que almacenara el nodo
     */
template <class T>

class Node {
private:
    /**
     * T Valor almacenado de tipo generico
     */
    T value;
    /**
     * Variable tipo Puntero hacia el siguiente nodo
     */
    Node<T>* next;
public:
    Node(T value);

    /**
     *
     * @return retorna el dato contenido en la variable tipo generico value.
     */
    T getValue();
    Node<T>* getNext();

    /**
     *
     * @param next variable tipo puntero que guarda la referencia a un nodo
     * Guarda el nodo insertado next en la variable next del nodo mismo.
     */
    void setNext(Node<T>* next);

    /**
     *
     * @param value Dato tipo generico para insertar.
     * Inserta la variable value en la variable value del nodo mismo.
     */
    void setValue(T value);

    /**
     * Destructor de la clase
     */
    ~Node();

};

#include "Node.tpp"
#endif //TALLERESTRUCT_NODE_H