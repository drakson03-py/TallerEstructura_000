//
// Created by seba2 on 19-10-2026.
//

#ifndef TALLERESTRUCT_SYSTEMIMPL_H
#define TALLERESTRUCT_SYSTEMIMPL_H

#include "System.h"

/**
 * @brief Implementa las operaciones de gestion y derivacion de pacientes.
 *
 * Proporciona la logica concreta para administrar la fila de pacientes,
 * construir el arbol de decision, registrar pacientes en departamentos
 * y realizar busquedas en los arboles AVL.
 */
class SystemImpl : public System {
private:

    int obtenerIndiceDepto(DepartamentoAVL* departamentos, const string& nombre);

    bool buscarEnArbolRecursivo(
        NodoAVL<Paciente*>* nodo,
        const string& query,
        string& ruta,
        Paciente*& pacienteEncontrado
    );

public:

    void cargarFila(List<Paciente*>* datos, Queue<Paciente*>* fila) override;
    void buildArbolDecision(ArbolDecision* arbol) override;

    void registrarPacienteEnServicio(
        DepartamentoAVL* departamentos,
        Paciente* p,
        const string& servicio
    ) override;

    ResultadoBusqueda buscarPaciente(
        DepartamentoAVL* departamentos,
        const string& query
    ) override;
};

#endif // TALLERESTRUCT_SYSTEMIMPL_H
