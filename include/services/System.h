//
// Created by seba2 on 19-10-2026.
//

#ifndef TALLERESTRUCT_SYSTEM_H
#define TALLERESTRUCT_SYSTEM_H

#include "../struct/Struct.h"
#include "../model/Paciente.h"
#include "../model/ArbolDecision.h"
#include "../../include/struct/NodeAVL.h"
#include <iostream>

using namespace std;

class System {
public:
    virtual void cargarFila(List<Paciente*>* datos, Queue<Paciente*>* fila) = 0;
    virtual ArbolDecision* buildArbolDecision() = 0;
    virtual void registrarPacienteEnServicio(Paciente* p, const string& servicio) = 0;
    virtual void mostrarPacientesPorServicio(const string& servicio) = 0;
    virtual void buscarPaciente(const string& query) = 0;
    virtual void mostrarEstadoDepartamentos() = 0;
    virtual ~System() = default;



};



#endif //TALLERESTRUCT_SYSTEM_H