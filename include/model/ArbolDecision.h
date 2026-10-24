
//
// Created by seba2 on 21-10-2026.
//

#ifndef TALLERESTRUCT_ARBOLDECISION_H
#define TALLERESTRUCT_ARBOLDECISION_H

#include "../struct/BTNode.h"
#include "../model/Paciente.h"

/**
 * @brief Define los operadores de comparacion disponibles para las condiciones.
 */
enum class Operador {
    MAYOR,          /**< Mayor que (>). */
    MENOR,          /**< Menor que (<). */
    IGUAL,          /**< Igual a (==). */
    DISTINTO,       /**< Distinto de (!=). */
    MAYOR_IGUAL,    /**< Mayor o igual que (>=). */
    MENOR_IGUAL     /**< Menor o igual que (<=). */
};

/**
 * @brief Identifica los atributos del paciente que pueden evaluarse.
 */
enum class Atributo {
    ID,                     /**< Identificador del paciente. */
    NOMBRE,                 /**< Nombre del paciente. */
    EDAD,                   /**< Edad del paciente. */
    TEMPERATURA,            /**< Temperatura corporal. */
    PRESION_SISTOLE,        /**< Presion arterial sistolica. */
    PRESION_DIASTOLE,       /**< Presion arterial diastolica. */
    DOLOR,                  /**< Intensidad del dolor. */
    TIPO_DOLOR,             /**< Tipo de dolor. */
    TRAUMA,                 /**< Presencia de trauma. */
    SINTOMAS_NEUROLOGICOS,  /**< Presencia de sintomas neurologicos. */
    REQUIERE_CIRUGIA,       /**< Necesidad de cirugia. */
    DIAS_HOSPITALIZACION    /**< Dias estimados de hospitalizacion. */
};

/**
 * @brief Representa una condicion que puede evaluarse sobre un paciente.
 *
 * Contiene el atributo que se evalua, el valor de referencia, el operador
 * de comparacion y la informacion asociada a la ruta y al servicio.
 */
struct Condicion {
    Atributo atributo;
    string valor;
    string ruta;
    Operador operador;
    bool isNumero;
    string servicio;

    /**
     * @brief Comprueba si un dato satisface la condicion.
     *
     * Si isNumero es true, convierte el dato y el valor de referencia
     * a numeros y realiza una comparacion numerica. En caso contrario,
     * permite comparar cadenas mediante igualdad o desigualdad.
     *
     * @param dato Dato del paciente que se desea evaluar.
     * @return true si se cumple la condicion; false en caso contrario.
     *
     * @throw Las excepciones producidas por stof se capturan dentro del
     * metodo y provocan que se retorne false.
     */
    bool cumple(const string dato) const {
        if (isNumero) {
            float nDato;
            float nValor;
            try {
                nDato = stof(dato);
                nValor = stof(valor);
            } catch (...) {
                return false;
            }

            if (operador == Operador::MAYOR) {
                return nDato > nValor;
            }
            if (operador == Operador::MENOR) {
                return nDato < nValor;
            }
            if (operador == Operador::MAYOR_IGUAL) {
                return nDato >= nValor;
            }
            if (operador == Operador::MENOR_IGUAL) {
                return nDato <= nValor;
            }
            if (operador == Operador::IGUAL) {
                return nDato == nValor;
            }
            if (operador == Operador::DISTINTO) {
                return nDato != nValor;
            }
            return false;
        }

        if (operador == Operador::IGUAL) {
            return dato == valor;
        }
        if (operador == Operador::DISTINTO) {
            return dato != valor;
        }

        return false;
    }
};

/**
 * @brief Arbol binario de decision para determinar el servicio de un paciente.
 *
 * Cada nodo contiene una condicion. La evaluacion de las condiciones permite
 * recorrer el arbol hasta alcanzar una hoja que representa el resultado
 * de la derivacion.
 */
class ArbolDecision {
private:
    BTNode<Condicion>* raiz;

    /**
     * @brief Evalua la condicion de un nodo utilizando los datos del paciente.
     *
     * @param p Puntero al paciente que se esta evaluando.
     * @param node Nodo cuya condicion se debe comprobar.
     * @param ruta Puntero a la cadena donde se registra la ruta de decision.
     * @return true si se cumple la condicion; false en caso contrario.
     */
    bool cumpleCondicion(Paciente* p, BTNode<Condicion>* node, string* ruta);

    /**
     * @brief Libera la memoria dinamica utilizada por los nodos del arbol.
     *
     * Deja la raiz en nullptr despues de liberar la estructura.
     */
    void liberar();

public:
    /**
     * @brief Construye un arbol de decision vacio.
     */
    ArbolDecision();

    /**
     * @brief Construye un arbol de decision con una raiz inicial.
     *
     * @param raiz Puntero al nodo que sera la raiz del arbol.
     */
    ArbolDecision(BTNode<Condicion>* raiz);

    /**
     * @brief Reemplaza la raiz del arbol.
     *
     * @param raiz Puntero al nuevo nodo raiz.
     */
    void setRaiz(BTNode<Condicion>* raiz);


    /**
     * @brief Destruye el arbol y libera sus nodos.
     */
    ~ArbolDecision();

    /**
     * @brief Determina el servicio al que debe derivarse un paciente.
     *
     * Recorre el arbol evaluando las condiciones hasta alcanzar una hoja.
     *
     * @param paciente Puntero al paciente que se desea clasificar.
     * @param ruta Puntero opcional a una cadena donde se registra el recorrido.
     * Si es nullptr, no se solicita almacenar la ruta.
     * @return Nombre del servicio determinado por el arbol.
     */
    string decision(Paciente* paciente, string* ruta = nullptr);
};

#endif // TALLERESTRUCT_ARBOLDECISION_H
