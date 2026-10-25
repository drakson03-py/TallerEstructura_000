//
// Created by seba2 on 19-10-2026.
//

#ifndef TALLERESTRUCT_SYSTEMIMPL_H
#define TALLERESTRUCT_SYSTEMIMPL_H

#include "System.h"
#include "../struct/List.h"
#include "../struct/Queue.h"

/**
 * @brief Implementa las operaciones de gestion y derivacion de pacientes.
 *
 * Proporciona la logica concreta para administrar la fila de pacientes,
 * construir el arbol de decision, registrar pacientes en departamentos
 * y realizar busquedas en los arboles AVL.
 */
class SystemImpl : public System {
private:
    /**
 * @brief Obtiene la posicion de un departamento dentro del arreglo.
 *
 * @param departamentos Arreglo de NUM_DEPARTAMENTOS departamentos.
 * @param nombre Nombre del departamento que se busca.
 * @return Indice del departamento, o -1 si no existe ninguno con ese nombre.
 */
    int obtenerIndiceDepto(DepartamentoAVL* departamentos, const string& nombre);

    /**
 * @brief Busca un paciente en un subarbol AVL y construye la ruta hasta el.
 *
 * Recorre el subarbol en pre-orden (nodo, izquierdo, derecho) y compara cada
 * paciente con la consulta por ID (sin ceros o con dos digitos) o por nombre
 * exacto.
 *
 * @param nodo Raiz del subarbol donde se busca (puede ser nullptr).
 * @param query ID o nombre del paciente que se busca.
 * @param ruta Entrada: ruta acumulada hasta los ancestros del nodo. Salida: si
 *        se encuentra al paciente, ruta desde la raiz hasta el; en caso
 *        contrario no se modifica.
 * @param pacienteEncontrado Salida: paciente encontrado. Solo se asigna si el
 *        metodo retorna true.
 * @return true si el paciente se encontro en el subarbol, false en caso contrario.
 */

    bool buscarEnArbolRecursivo(
        NodoAVL<Paciente*>* nodo,
        const string& query,
        string& ruta,
        Paciente*& pacienteEncontrado
    );

public:

    void cargarFila(List<Paciente*>* datos, Queue<Paciente*>* fila) override;

    ArbolDecision *buildArbolDecision() override;

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
