//
// Created by Alan Galleguillos on 19-10-2026.
//

#ifndef TALLERESTRUCT_NODEAVL_H
#define TALLERESTRUCT_NODEAVL_H

/**
 * @brief Representa un nodo de un arbol AVL.
 *
 * Cada nodo almacena un dato, punteros a sus hijos izquierdo y derecho y la
 * altura del subarbol que cuelga de el. El balanceo del arbol y la liberacion
 * de los nodos son responsabilidad de ArbolAVL.
 *
 * @tparam T Tipo de dato almacenado en el nodo.
 */
template <typename T>
class NodoAVL {
private:
    T dato;                 /**< Dato almacenado en el nodo. */
    NodoAVL<T>* izquierdo;  /**< Hijo izquierdo, o nullptr si no existe. */
    NodoAVL<T>* derecho;    /**< Hijo derecho, o nullptr si no existe. */
    int altura;             /**< Altura del subarbol del nodo (hoja = 1). */

public:
    // Constructor
    /**
     * @brief Construye un nodo hoja con el valor indicado.
     *
     * Los hijos izquierdo y derecho se inicializan en nullptr y la altura en 1.
     *
     * @param valor Dato que se almacenara en el nodo.
     */
    explicit NodoAVL(T valor);

    /**
     * @brief Destruye el nodo.
     *
     * No libera los hijos ni el dato almacenado; la liberacion de los nodos la
     * realiza el destructor de ArbolAVL.
     */
    ~NodoAVL() = default;

    /**
     * @brief Obtiene el dato almacenado en el nodo.
     *
     * @return Copia del dato almacenado.
     */
    T getDato() const;
    /**
     * @brief Obtiene el hijo izquierdo del nodo.
     *
     * @return Puntero al hijo izquierdo, o nullptr si no existe.
     */
    NodoAVL<T>* getIzquierdo() const;
    /**
     * @brief Obtiene el hijo derecho del nodo.
     *
     * @return Puntero al hijo derecho, o nullptr si no existe.
     */
    NodoAVL<T>* getDerecho() const;
    /**
     * @brief Obtiene la altura del nodo.
     *
     * @return Altura del subarbol cuya raiz es este nodo (una hoja tiene altura 1).
     */
    int getAltura() const;

    /**
     * @brief Establece el dato almacenado en el nodo.
     *
     * @param valor Nuevo dato del nodo.
     */
    void setDato(T valor);
    /**
     * @brief Establece el hijo izquierdo del nodo.
     *
     * @param nodo Puntero al nodo que sera el hijo izquierdo (puede ser nullptr).
     */
    void setIzquierdo(NodoAVL<T>* nodo);
    /**
     * @brief Establece el hijo derecho del nodo.
     *
     * @param nodo Puntero al nodo que sera el hijo derecho (puede ser nullptr).
     */
    void setDerecho(NodoAVL<T>* nodo);
    /**
     * @brief Establece la altura del nodo.
     *
     * ArbolAVL recalcula la altura tras cada insercion y rotacion; este metodo
     * no valida que el valor sea coherente con la estructura real del subarbol.
     *
     * @param alt Nueva altura del nodo.
     */
    void setAltura(int alt);
};

#include "NodeAVL.tpp"
#endif //NODOAVL_HPP