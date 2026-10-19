//
// Created by seba2 on 19-10-2026.
//

#ifndef TALLERESTRUCT_SYSTEM_H
#define TALLERESTRUCT_SYSTEM_H

#include "../struct/Struct.h"
#include "../model/Paciente.h"
#include <iostream>
using namespace std;

class System {
public:
    virtual void cargarFila(List<Paciente*>* datos, Queue<Paciente*>* fila) = 0;

    virtual ~System() = default;

};



#endif //TALLERESTRUCT_SYSTEM_H