//
// Created by seba2 on 18-10-2026.
//

#include "../../include/model/Paciente.h"


Paciente::Paciente(
    int id,
    const string &nombre,
    int edad,
    float temperatura,
    string presionArterial,
    int dolor,
    const string &tipoDolor,
    bool trauma,
    bool sintomasNeurologicos,
    bool requiereCirugia,
    int diasHospitalizacion
    )
    : id(id),
      nombre(nombre),
      edad(edad),
      temperatura(temperatura),
      presionArterial(presionArterial),
      dolor(dolor),
      tipoDolor(tipoDolor),
      trauma(trauma),
      sintomasNeurologicos(sintomasNeurologicos),
      requiereCirugia(requiereCirugia),
      diasHospitalizacion(diasHospitalizacion) {
}

int Paciente::getId() const {
    return id;
}

void Paciente::setId(int id) {
    this->id = id;
}

string Paciente::getNombre() const {
    return nombre;
}

void Paciente::setNombre(const string &nombre) {
    this->nombre = nombre;
}

int Paciente::getEdad() const {
    return edad;
}

void Paciente::setEdad(int edad) {
    this->edad = edad;
}

float Paciente::getTemperatura() const {
    return temperatura;
}

void Paciente::setTemperatura(float temperatura) {
    this->temperatura = temperatura;
}

string Paciente::getPresionArterial() const {
    return presionArterial;
}

void Paciente::setPresionArterial(string presionArterial) {
    this->presionArterial = presionArterial;
}

int Paciente::getDolor() const {
    return dolor;
}

void Paciente::setDolor(int dolor) {
    this->dolor = dolor;
}

string Paciente::getTipoDolor() const {
    return tipoDolor;
}

void Paciente::setTipoDolor(const string &tipoDolor) {
    this->tipoDolor = tipoDolor;
}

bool Paciente::isTrauma() const {
    return trauma;
}

void Paciente::setTrauma(bool trauma) {
    this->trauma = trauma;
}

bool Paciente::isSintomasNeurologicos() const {
    return sintomasNeurologicos;
}

void Paciente::setSintomasNeurologicos(bool sintomasNeurologicos) {
    this->sintomasNeurologicos = sintomasNeurologicos;
}

bool Paciente::isRequiereCirugia() const {
    return requiereCirugia;
}

void Paciente::setRequiereCirugia(bool requiereCirugia) {
    this->requiereCirugia = requiereCirugia;
}

int Paciente::getDiasHospitalizacion() const {
    return diasHospitalizacion;
}

void Paciente::setDiasHospitalizacion(int diasHospitalizacion) {
    this->diasHospitalizacion = diasHospitalizacion;
}

