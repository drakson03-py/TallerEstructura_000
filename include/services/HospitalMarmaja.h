

#ifndef TALLERESTRUCT_HOSPITALMARMAJA_H
#define TALLERESTRUCT_HOSPITALMARMAJA_H


#include "System.h"
#include "../struct/Struct.h"
#include "../model/Paciente.h"
#include <iostream>
using namespace std;

class HospitalMarmaja: public System {
private:
    List<Paciente*>* datos;
    Queue<Paciente*>* fila;
    Stack<Paciente*>* historial;
    List<List<Paciente*>*>* departamentos;

public:
    HospitalMarmaja(string archivo);

    void leerArchivo();//s
    void escribirArchivo();

    void cargaDePacientes() override;//s

    void verDepartamento() override;//s

    void imprimirPaciente(Paciente* p, string forma);//s

    bool pacienteRepetido(int id);//s

    void atenderPacientes() override;//a

    void revisarHistorialDeAtencion() override;//a

    void finalizar() override;//a

    ~HospitalMarmaja() override;//a

    string idString(int id);//s
};


#endif //TALLERESTRUCT_HOSPITALMARMAJA_H