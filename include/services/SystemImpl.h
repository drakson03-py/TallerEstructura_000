//
// Created by seba2 on 19-10-2026.
//

#ifndef TALLERESTRUCT_SYSTEMIMPL_H
#define TALLERESTRUCT_SYSTEMIMPL_H
#include "System.h"

class SystemImpl : public System {
public:
    void cargarFila(List<Paciente *>* datos, Queue<Paciente *>* fila) override;

    ~SystemImpl() = default;

};


#endif //TALLERESTRUCT_SYSTEMIMPL_H