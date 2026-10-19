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
    string archivo;
    System* system;
    List<Paciente*>* datos;
    Queue<Paciente*>* fila;

public:
    App(const string& archivo, System* system);
    void run();
    ~App();
};


#endif //TALLERESTRUCT_APP_H