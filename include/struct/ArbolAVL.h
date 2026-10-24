//
// Created by Alan Galleguillos on 23-10-2026.
//

#ifndef TALLERESTRUCT_ARBOLAVL_H
#define TALLERESTRUCT_ARBOLAVL_H

#include "NodeAVL.h"
#include <iostream>

/**
 * Implementa un arbol binario de busqueda AVL (auto-balanceado).
 *
 * En cada nodo, la diferencia de altura entre sus subarboles izquierdo y
 * derecho nunca supera 1. Este invariante se mantiene tras cada insercion
 * mediante rotaciones simples y dobles
 * @tparam T Tipo de dato almacenado en el arbol.
 */

template <typename T>
class ArbolAVL {
private:
    NodoAVL<T>* raiz;    /**< Raiz del arbol, o nullptr si esta vacio. */
    int (*comparador)(T, T); /**< Funcion de comparacion; nullptr para usar < y >. */

    /**
     * @brief Obtiene la altura de un nodo, tratando nullptr como altura 0.
     *
     * @param nodo Nodo cuya altura se desea conocer (puede ser nullptr).
     * @return 0 si nodo es nullptr; en otro caso, la altura almacenada en el nodo.
     */
    int obtenerAltura(NodoAVL<T>* nodo);
    /**
     * @brief Calcula el factor de balance de un nodo.
     *
     * la altura del subarbol izquierdo menos la del derecho. Un
     * valor mayor que 1 indica desbalance hacia la izquierda y uno menor que -1,
     * hacia la derecha; en un AVL valido siempre esta entre -1 y 1.
     *
     * @param nodo Nodo cuyo balance se desea calcular (puede ser nullptr).
     * @return Factor de balance del nodo, o 0 si nodo es nullptr.
     */
    int obtenerFactorBalance(NodoAVL<T>* nodo);
    /**
    * @brief Obtiene el mayor de dos enteros.
    *
    * @param a Primer valor.
    * @param b Segundo valor.
    * @return El mayor entre a y b.
    */
    int max(int a, int b);
    /**
   * @brief Compara dos elementos segun el criterio de orden del arbol.
   *
   *
   * @param a Primer elemento.
   * @param b Segundo elemento.
   * @return Un valor negativo si a va antes que b, 0 si son equivalentes y un
   *         valor positivo si a va despues que b.
   */
    int comparar(T a, T b);
    /**
    * @brief Realiza una rotacion simple a la derecha sobre el nodo indicado.
    *
    * El hijo izquierdo de y pasa a ser la nueva raiz del subarbol, y pasa a ser
    * su hijo derecho, y el antiguo subarbol derecho del hijo izquierdo se
    * convierte en el nuevo subarbol izquierdo de y. Luego recalcula las alturas
    * de y y del nuevo nodo raiz. Corrige el caso izquierda-izquierda y es el
    * segundo paso del caso izquierda-derecha.
    *
    * @param y Raiz del subarbol que se rota. Debe tener hijo izquierdo.
    * @return Nueva raiz del subarbol rotado.
    */
    NodoAVL<T>* rotacionDerecha(NodoAVL<T>* y);
    /**
    * @brief Realiza una rotacion simple a la izquierda sobre el nodo indicado.
    *
    * El hijo derecho de x pasa a ser la nueva raiz del subarbol, x pasa a ser su
    * hijo izquierdo, y el antiguo subarbol izquierdo del hijo derecho se
    * convierte en el nuevo subarbol derecho de x. Luego recalcula las alturas
    * de x y del nuevo nodo raiz. Corrige el caso derecha-derecha y es el
    * segundo paso del caso derecha-izquierda.
    *
    * @param x Raiz del subarbol que se rota. Debe tener hijo derecho.
    * @return Nueva raiz del subarbol rotado.
    */
    NodoAVL<T>* rotacionIzquierda(NodoAVL<T>* x);
    /**
   * @brief Inserta un valor en el subarbol indicado y lo rebalancea.
   *
   * Si nodo es nullptr crea un nuevo nodo. En otro caso desciende por el
   * subarbol izquierdo o derecho segun comparar(); si el valor ya existe, no
   * inserta nada. Al regresar de la recursion actualiza la altura del nodo,
   * calcula su factor de balance.
   * @param nodo Raiz del subarbol donde se inserta (puede ser nullptr).
   * @param valor Valor que se desea insertar.
   * @return Raiz del subarbol despues de insertar y rebalancear; puede ser
   *         distinta de nodo si hubo una rotacion.
   */

    NodoAVL<T>* insertarRecursivo(NodoAVL<T>* nodo, T valor);

    /**
    * @brief Libera todos los nodos de un subarbol.
    *
    * Recorre el subarbol en post-orden y elimina cada nodo. No libera los datos
    * almacenados en ellos.
    *
    * @param nodo Raiz del subarbol que se libera (puede ser nullptr).
    */
    void destruirArbol(NodoAVL<T>* nodo);
    /**
     * @brief Imprime un subarbol en in-orden (izquierdo, nodo, derecho).
     *
     * Cada nodo se imprime con el formato "dato (Altura: h)".
     *
     *
     * @param nodo Raiz del subarbol que se recorre (puede ser nullptr).
     */

    void inOrdenRecursivo(NodoAVL<T>* nodo);
    /**
    * @brief Imprime un subarbol en pre-orden (nodo, izquierdo, derecho).
    *
    * Cada nodo se imprime con el formato "dato (Altura: h)".
    *.
    *
    * @param nodo Raiz del subarbol que se recorre (puede ser nullptr).
    */
    void preOrdenRecursivo(NodoAVL<T>* nodo);
    /**
   * @brief Imprime un subarbol en post-orden (izquierdo, derecho, nodo).
   *
   * Cada nodo se imprime con el formato "dato (Altura: h)".
   *
   *
   * @param nodo Raiz del subarbol que se recorre (puede ser nullptr).
   */
    void postOrdenRecursivo(NodoAVL<T>* nodo);

public:
 /**
   * @brief Construye un arbol AVL vacio.
   *
   * @param comparador Funcion que recibe dos elementos y retorna un valor
   *        negativo si el primero va antes que el segundo, 0 si son equivalentes y
   *        un valor positivo si va despues. Si es nullptr, el orden se define con
   *        los operadores < y > de T.
   */
 ArbolAVL(int (*comparador)(T, T) = nullptr);
 /**
  * @brief Destruye el arbol y libera todos sus nodos.
  *
  * No libera los datos almacenados en los nodos.
  */
 ~ArbolAVL();

 /**
  * @brief Obtiene la raiz del arbol.
  *
  * @return Puntero al nodo raiz, o nullptr si el arbol esta vacio.
  */
 NodoAVL<T>* getRaiz();
 /**
  * @brief Inserta un valor en el arbol manteniendolo balanceado.
  *
  * Si el comparador considera que el valor ya existe, no se inserta.
  * Complejidad: O(log n).
  *
  * @param valor Valor que se desea insertar.
  */
 void insertar(T valor);
 /**
  * @brief Imprime por consola el arbol en in-orden.
  *
  * Con un comparador consistente, entrega los datos de menor a mayor. Cada
  * nodo se muestra con su altura: "dato (Altura: h)".
  *
  */
 void mostrarInOrden();
 /**
  * @brief Imprime por consola el arbol en pre-orden.
  *
  * Cada nodo se muestra con su altura: "dato (Altura: h)".
  *
  */
 void mostrarPreOrden();
 /**
  * @brief Imprime por consola el arbol en post-orden.
  *
  * Cada nodo se muestra con su altura: "dato (Altura: h)".
  *
  */
 void mostrarPostOrden();
};

#include "ArbolAVL.tpp"

#endif // ARBOLAVL_HPP
