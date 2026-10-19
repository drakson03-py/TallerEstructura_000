
#include "../../include/services/SystemImpl.h"

void SystemImpl::cargarFila(List<Paciente *>* datos, Queue<Paciente *>* fila) {
    int aux = 0;
    while (true) {
        try {
            fila->push(datos->get(aux));
            aux++;
        }catch (...){break;}
    }
}


