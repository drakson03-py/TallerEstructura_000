#include "../../include/model/Paciente.h"

Paciente::Paciente(int id,string nombre,int edad,string servicio) {
    this -> id = id;
    this -> nombre = nombre;
    this -> edad = edad;
    this -> servicio = servicio;
}

int Paciente::getId() {
    return this->id;
}

string Paciente::getNombre() {
    return this->nombre;
}

int Paciente::getEdad() {
    return this->edad;
}

string Paciente::getServicio() {
    return this->servicio;
}
Paciente::~Paciente() = default;