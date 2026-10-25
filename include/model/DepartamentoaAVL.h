//
// Created by Alan Galleguillos on 23-10-2026.
//

#ifndef TALLERESTRUCT_DEPARTAMENTOAVL_H
#define TALLERESTRUCT_DEPARTAMENTOAVL_H

#include <string>
#include "Paciente.h"
#include "../struct/ArbolAVL.h"
using namespace std;

/**
 * Cantidad de departamentos del hospital.
 *
 * Es el tamano del arreglo de DepartamentoAVL que administra App.
 */

const int NUM_DEPARTAMENTOS = 8;

/**
 * Compara dos pacientes por su ID.
 *
 * Esta funcion se entrega a ArbolAVL<Paciente*> para que ordene a los
 * pacientes por ID.
 *
 * @param a Primer paciente.
 * @param b Segundo paciente.
 * @return Un valor negativo si el ID de a es menor que el de b, 0 si son
 *         iguales y un valor positivo si es mayor.
 */

inline int compararPacientesPorId(Paciente* a, Paciente* b) {
    return a->getId() - b->getId();
}
/**
 * @brief Asocia un departamento del hospital con su arbol AVL de pacientes.
 *
 */
struct DepartamentoAVL {
    string nombre;  /**< Nombre del departamento (servicio de atencion). */
    ArbolAVL<Paciente*>* arbol; /**< Arbol AVL con los pacientes del departamento. */
};

#endif