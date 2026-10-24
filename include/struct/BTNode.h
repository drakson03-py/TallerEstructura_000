
//
// Created by seba2 on 21-10-2026.
//

#ifndef TALLERESTRUCT_BTNODE_H
#define TALLERESTRUCT_BTNODE_H

/**
 * @brief Representa un nodo de un arbol binario.
 *
 * Cada nodo almacena un valor y punteros a sus hijos izquierdo y derecho.
 *
 * @tparam T Tipo de dato almacenado en el nodo.
 */
template <class T>
class BTNode {
private:
    T value;
    BTNode* left;
    BTNode* right;

public:
    /**
     * @brief Construye un nodo con el valor indicado.
     *
     * @param value Valor que se almacenara en el nodo.
     */
    BTNode(T value);

    /**
     * @brief Obtiene el valor almacenado en el nodo.
     *
     * @return Copia del valor almacenado.
     */
    T getValue();

    /**
     * @brief Obtiene el hijo izquierdo del nodo.
     *
     * @return Puntero al hijo izquierdo, o nullptr si no existe.
     */
    BTNode* getLeft();

    /**
     * @brief Obtiene el hijo derecho del nodo.
     *
     * @return Puntero al hijo derecho, o nullptr si no existe.
     */
    BTNode* getRight();

    /**
     * @brief Establece el hijo izquierdo del nodo.
     *
     * @param left Puntero al nodo que sera el hijo izquierdo.
     */
    void setLeft(BTNode* left);

    /**
     * @brief Establece el hijo derecho del nodo.
     *
     * @param right Puntero al nodo que sera el hijo derecho.
     */
    void setRight(BTNode* right);

    /**
     * @brief Destruye el nodo.
     */
    ~BTNode();
};

#include "BTNode.tpp"

#endif // TALLERESTRUCT_BTNODE_H
