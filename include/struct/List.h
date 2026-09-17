
#ifndef TALLERESTRUCT_LIST_H
#define TALLERESTRUCT_LIST_H
#include "Node.h"

template <class T>

/**
     * Clase "List" implementacion de la EDD Lista enlazada generica para el manejo dinamico de datos.
     * T Tipo de dato que almacena la lista.
     */
class List {
private:
    /**
     *Variable de tipo puntero que almacena el inicio de la lista de tipo generico.
     */
    Node<T>* start;
public:
    ///
    List();
    /**
     * Metodo que devuelve un booleano para saber si la lista esta vacia o no (True si, False no)
     */

    bool isEmpty();
    /**
    * Metodo que inserta un elemento en la posicion (index) especifica de la lista
    */
    void insert(T value, int index);
    /**
     * Inserta un nuevo elemento en la primera posición de la lista (cabeza o índice 0).
     * Si ya existe un elemento en dicha posición, los elementos actuales se desplazan una posición hacia adelante para ceder el lugar al nuevo nodo.
     */
    void insertFirst(T value);
    /**
     *Inserta un nuevo elemento en la ULTIMA posición de la lista.
     */
    void insertLast(T value);

    /**
     *
     * @param index variable tipo int que representa la posicion dentro de la lista.
     * @return Devuelve el nodo que esta contenida en la lista en la posicion INDEX.
     */
    T get(int index);

    /**
     *
     * @return Retorna el nodo situado en la primera lista
     */
    T getFirst();

    /**
     *
     * @return Retorna el ultimo nodo situado en la lista.
     */
    T getLast();

    /**
     *
     * Elimina el nodo situado en la posicion INDEX y reconecta sus nodos adyacentes
     *
     */
    void remove(int index);
    /**
     * Elimina todos los punteros dentro de la lista dejandola vacia.
     */
    void clear();

    /**
     * Desestructor
     */
    ~ List();
};

#include "List.tpp"
#endif //TALLERESTRUCT_LIST_H