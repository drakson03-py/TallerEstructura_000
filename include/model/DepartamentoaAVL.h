//
// Created by Alan Galleguillos on 23-10-2026.
//

#ifndef TALLERESTRUCT_DEPARTAMENTOAVL_H
#define TALLERESTRUCT_DEPARTAMENTOAVL_H

#include <string>
#include "Paciente.h"
#include "../struct/ArbolAVL.h"
using namespace std;

const int NUM_DEPARTAMENTOS = 8;

inline int compararPacientesPorId(Paciente* a, Paciente* b) {
    return a->getId() - b->getId();
}

struct DepartamentoAVL {
    string nombre;
    ArbolAVL<Paciente*>* arbol;
};

#endif