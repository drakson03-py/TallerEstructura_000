
//
// Created by seba2 on 19-10-2026.
//

#ifndef TALLERESTRUCT_SYSTEM_H
#define TALLERESTRUCT_SYSTEM_H

#include "../struct/List.h"
#include "../struct/Queue.h"
#include "../model/Paciente.h"
#include "../model/ArbolDecision.h"
#include "../model/DepartamentoaAVL.h"
#include "../model/ResultadoBusqueda.h"
#include <iostream>

using namespace std;

/**
 * @brief Interfaz que define las operaciones principales del sistema.
 *
 * Establece los metodos que deben implementar las clases derivadas para
 * gestionar la fila de pacientes, construir el arbol de decision, registrar
 * pacientes en servicios y realizar busquedas.
 */
class System {
public:
    /**
     * @brief Carga pacientes desde una lista hacia una fila.
     *
     * @param datos Lista que contiene los pacientes que se desean cargar.
     * @param fila Cola donde se incorporaran los pacientes.
     */
    virtual void cargarFila(List<Paciente*>* datos, Queue<Paciente*>* fila) = 0;

    /**
     * @brief Construye o configura el arbol de decision del sistema.
     *
     * @param arbol Puntero al arbol de decision que se debe construir.
     */
    virtual ArbolDecision *buildArbolDecision() = 0;


    virtual void registrarPacienteEnServicio(
        DepartamentoAVL* departamentos,
        Paciente* p,
        const string& servicio
    ) = 0;


    virtual ResultadoBusqueda buscarPaciente(
        DepartamentoAVL* departamentos,
        const string& query
    ) = 0;

    /**
     * @brief Destructor virtual por defecto.
     *
     * Permite destruir correctamente los objetos de clases derivadas
     * mediante un puntero a System.
     */
    virtual ~System() = default;
};

#endif // TALLERESTRUCT_SYSTEM_H
