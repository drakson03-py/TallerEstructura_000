
#include "../../include/services/SystemImpl.h"

void SystemImpl::cargarFila(List<Paciente *>* datos, Queue<Paciente *>* fila) {
    if (datos == nullptr || fila == nullptr) {
        return;
    }

    for (int i = 0; i < datos->getSize(); i++) {
        fila->push(datos->get(i));
    }

}


