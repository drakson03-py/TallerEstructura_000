//
// Created by seba2 on 16-09-2026.
//

#ifndef TALLERESTRUCT_SYSTEM_H
#define TALLERESTRUCT_SYSTEM_H
#include <iostream>
using namespace std;

class System {
protected:
    string archivo;
public:
    System(string archivo) {
        this -> archivo = archivo;
    }
    virtual void cargaDePacientes() = 0;
    virtual void atenderPacientes() = 0;
    virtual void verDepartamento() = 0;
    virtual void revisarHistorialDeAtencion() = 0;
    virtual void finalizar() = 0;
    virtual ~System() = default;
};




#endif //TALLERESTRUCT_SYSTEM_H