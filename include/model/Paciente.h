//
// Created by seba2 on 15-09-2026.
//

#ifndef TALLER_1_PACIENTE_H
#define TALLER_1_PACIENTE_H

#include <iostream>
using namespace std;

class Paciente {
private:
    int id;
    string nombre;
    int edad;
    string servicio;
public:
    Paciente(
        int id,
        string nombre,
        int edad,
        string servicio
        );

    int getId();
    string getNombre();
    int getEdad();
    string getServicio();
    ~Paciente();
};

#endif //TALLER_1_PACIENTE_H