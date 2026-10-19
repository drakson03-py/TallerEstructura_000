#include "../../include/model/Paciente1.h"

Paciente1::Paciente1(int id,string nombre,int edad,string servicio) {
    this -> id = id;
    this -> nombre = nombre;
    this -> edad = edad;
    this -> servicio = servicio;
}

int Paciente1::getId() {
    return this->id;
}

string Paciente1::getNombre() {
    return this->nombre;
}

int Paciente1::getEdad() {
    return this->edad;
}

string Paciente1::getServicio() {
    return this->servicio;
}
Paciente1::~Paciente1() = default;