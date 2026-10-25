//
// Created by seba2 on 19-10-2026.
//

#ifndef TALLERESTRUCT_APP_H
#define TALLERESTRUCT_APP_H
#include "../services/System.h"
#include <iostream>
#include "../utils/PrintPaciente.h"
using namespace std;

class App {
private:

    string archivo;  /**< Nombre del archivo con los datos de los pacientes. */
    System* system;
    DepartamentoAVL departamentos[NUM_DEPARTAMENTOS];/**< Departamentos, cada uno con su arbol AVL de pacientes. */
    PrintPaciente print;  /**< Utilidad para imprimir pacientes y dar formato a sus IDs. */


    /**
    * @brief Imprime en una sola linea de los pacientes de un subarbol AVL.
    *
    * Recorre el subarbol en in-orden (izquierdo, nodo, derecho).
    *
    * @param nodo Raiz del subarbol que se imprime (puede ser nullptr).
    * @param primero Indica si aun no se ha impreso ningun paciente en la linea.
    *        Debe ser true en la primera llamada; el metodo lo cambia a false al
    *        imprimir el primer paciente, para no anteponer una coma.
    */
    void imprimirPacientesInline(NodoAVL<Paciente*>* nodo, bool& primero);
    /**
    * @brief Muestra por consola el resultado de buscar un paciente.
    *
    * Si no se encontro, informa que el paciente no existe. En caso contrario
    * imprime los datos del paciente, el departamento donde esta registrado y la
    * ruta recorrida en el arbol AVL.
    *
    * @param resultado Resultado entregado por System::buscarPaciente.
    */
    void mostrarResultadoBusqueda(const ResultadoBusqueda& resultado);
    /**
     * @brief Muestra por consola el estado de todos los departamentos.
     *
     * Para cada departamento imprime su nombre y la lista de pacientes que
     * contiene su arbol AVL ordenados por ID, o "Sin pacientes" si esta vacio.
     */
    void mostrarEstadoDepartamentos();

public:
    App(const string& archivo, System* system);
    void run();
    ~App();
};

#endif //TALLERESTRUCT_APP_H