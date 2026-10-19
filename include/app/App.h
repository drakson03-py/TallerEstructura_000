//
// Created by seba2 on 19-10-2026.
//

#ifndef TALLERESTRUCT_APP_H
#define TALLERESTRUCT_APP_H
#include "../services/System.h"
#include <iostream>
using namespace std;

class App {
private:
    System* system;
    List<Paciente*>* datos; /**< Lista que almacena los punteros a los pacientes  */
    Queue<Paciente*>* fila; /**< Cola que almacena los pacientes pendientes en atender */

public:
    App(List<Paciente*>* datos,System* system);
    void run();
    ~App();
};


#endif //TALLERESTRUCT_APP_H