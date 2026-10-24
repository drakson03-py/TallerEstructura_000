//
// Created by Alan Galleguillos on 23-10-2026.
//

#ifndef TALLERESTRUCT_RESULTADOBUSQUEDA_H
#define TALLERESTRUCT_RESULTADOBUSQUEDA_H

#include <string>
#include "Paciente.h"
using namespace std;

/**
 * @brief Resultado de buscar un paciente en los arboles AVL de los departamentos.
 *
 * Lo entrega System::buscarPaciente para que la capa de presentacion
 * muestre la informacion, sin que la busqueda imprima nada por si misma.
 */
struct ResultadoBusqueda {
    bool encontrado;      /**< Indica si se encontro al paciente. */
    Paciente* paciente;   /**< Paciente encontrado, o nullptr si no se encontro. */
    string departamento;  /**< Departamento donde se encontro; vacio si no se encontro. */
    string ruta;          /**< IDs de los nodos desde la raiz hasta el paciente, separados por espacio. */
};

#endif