
#ifndef TALLERESTRUCT_LIST_H
#define TALLERESTRUCT_LIST_H
#include "Node.h"

/**
 * Implementación de una lista enlazada genérica
 * para el manejo dinámico de datos
 * @tparam T Tipo de dato que almacena la lista
 */
template <class T>
class List {
private:
    /**
     *Variable de tipo puntero que almacena el inicio de la lista
     */
    Node<T>* start;

public:
    /**
     * Constructor
     */
    List();

    /**
     *Verifica si la lista esta vacia
     *@return true si la lista esta vacia, false si no lo esta
     */
    bool isEmpty();

    /**
     * Inserta un elemento en una posicion
     * @param value Elemento que se quiere insertar
     * @param index Posicion que en la que se quiere insertar
     */
    void insert(T value, int index);

    /**
     * Inserta un elemento en la primera posición de la lista
     * @param value Elemento que se quiere insertar
     */
    void insertFirst(T value);

    /**
     * Inserta un nuevo elemento en la ultima posición de la lista
     * @param value Elemento que se quiere insertar
     */
    void insertLast(T value);

    /**
     * Devuelve el elemento de la posicion indicada
     * @param index Posicion dentro de la lista
     * @return Devuelve un elemento generico T
     */
    T get(int index);

    /**
     * Devuelve el primer elemento de la lista
     * @return Elemento generico T
     */
    T getFirst();

    /**
     * Devuelve el ultimo elemento de la lista
     * @return Elemento generico T
     */
    T getLast();

    /**
     * Remueve de la lista el elemento en la posicion indicada
     * @param index Posicion dentro de la lista
     */
    void remove(int index);

    /**
     * Elimina todos los elementos de la lista
     */
    void clear();

    /**
     * Destructor
     */
    ~List();
};

#include "List.tpp"
#endif //TALLERESTRUCT_LIST_H