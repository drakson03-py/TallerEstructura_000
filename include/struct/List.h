
#ifndef TALLERESTRUCT_LIST_H
#define TALLERESTRUCT_LIST_H

#include "Node.h"

/**
 * @brief Implementación de una lista enlazada genérica
 * para el manejo dinámico de datos.
 *
 * @tparam T Tipo de dato que almacena la lista.
 */
template <class T>
class List {
private:
    /**
     * @brief Variable de tipo puntero que almacena el inicio de la lista.
     */
    Node<T>* start;

    /**
     * @brief Cantidad de elementos almacenados en la lista.
     */
    int size;

public:
    /**
     * @brief Constructor.
     * Inicializa una lista vacía.
     */
    List();

    /**
     * @brief Verifica si la lista está vacía.
     *
     * @return true si la lista está vacía, false si no lo está.
     */
    bool isEmpty();

    /**
     * @brief Inserta un elemento en una posición.
     *
     * @param value Elemento que se quiere insertar.
     * @param index Posición en la que se quiere insertar.
     * Debe estar entre 0 y el tamaño actual de la lista.
     *
     * @throw nullptr Si el índice es menor que 0 o mayor que el tamaño.
     */
    void insert(T value, int index);

    /**
     * @brief Inserta un elemento en la primera posición de la lista.
     *
     * @param value Elemento que se quiere insertar.
     */
    void insertFirst(T value);

    /**
     * @brief Inserta un nuevo elemento en la última posición de la lista.
     *
     * @param value Elemento que se quiere insertar.
     */
    void insertLast(T value);

    /**
     * @brief Devuelve el elemento de la posición indicada.
     *
     * @param index Posición dentro de la lista.
     *
     * @return Elemento genérico T almacenado en la posición indicada.
     *
     * @throw nullptr Si el índice es menor que 0 o mayor o igual
     * que el tamaño de la lista.
     */
    T get(int index);

    /**
     * @brief Devuelve el primer elemento de la lista.
     *
     * @return Elemento genérico T almacenado al inicio de la lista.
     *
     * @throw nullptr Si la lista está vacía.
     */
    T getFirst();

    /**
     * @brief Devuelve el último elemento de la lista.
     *
     * @return Elemento genérico T almacenado al final de la lista.
     *
     * @throw nullptr Si la lista está vacía.
     */
    T getLast();

    /**
     * @brief Devuelve la cantidad de elementos de la lista.
     *
     * @return Número de elementos almacenados.
     */
    int getSize();

    /**
     * @brief Remueve de la lista el elemento en la posición indicada.
     *
     * @param index Posición dentro de la lista.
     *
     * @throw nullptr Si el índice es menor que 0 o mayor o igual
     * que el tamaño de la lista.
     */
    void remove(int index);

    /**
     * @brief Elimina todos los nodos de la lista.
     *
     * Libera la memoria de los nodos y establece el tamaño en 0.
     */
    void clear();

    /**
     * @brief Destructor.
     *
     * Libera los nodos restantes de la lista.
     */
    ~List();
};

#include "List.tpp"

#endif // TALLERESTRUCT_LIST_H