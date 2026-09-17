
#ifndef TALLERESTRUCT_PACIENTE_H
#define TALLERESTRUCT_PACIENTE_H

#include <iostream>
using namespace std;

class Paciente {
private:
    int id;
    string nombre;
    int edad;
    string servicio;
public:
    Paciente(int id,string nombre,int edad,string servicio);

    int getId();
    string getNombre();
    int getEdad();
    string getServicio();
    ~Paciente();
};

#endif //TALLERESTRUCT_PACIENTE_H