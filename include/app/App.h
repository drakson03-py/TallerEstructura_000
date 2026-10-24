//
// Created by seba2 on 19-10-2026.
//

#ifndef TALLERESTRUCT_APP_H
#define TALLERESTRUCT_APP_H
#include "../services/System.h"
#include <iostream>
#include "../utils/PrintPaciente.h"
using namespace std;

class App {
private:
    string archivo;
    System* system;
    List<Paciente*>* datos;
    Queue<Paciente*>* fila;

    DepartamentoAVL departamentos[NUM_DEPARTAMENTOS];
    PrintPaciente print;
    void imprimirPacientesInline(NodoAVL<Paciente*>* nodo, bool& primero);
    void mostrarResultadoBusqueda(const ResultadoBusqueda& resultado);
    void mostrarEstadoDepartamentos();

public:
    App(const string& archivo, System* system);
    void run();
    ~App();
};


#endif //TALLERESTRUCT_APP_H