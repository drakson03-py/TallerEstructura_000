//
// Created by seba2 on 18-10-2026.
//

#include "../../include/model/PacienteBuilder.h"

PacienteBuilder::PacienteBuilder()
    : id(0),nombre("Sin nombre"), edad(0), temperatura(0.0f),
      presionArterial(0.0f), dolor(0),
      trauma(false), sintomasNeurologicos(false),
      requiereCirugia(false), diasHospitalizacion(0) {
}

PacienteBuilder& PacienteBuilder::setId(int id) {
    this->id = id;
    return *this;
}

PacienteBuilder& PacienteBuilder::setNombre(const string& nombre) {
    this->nombre = nombre;
    return *this;
}

PacienteBuilder& PacienteBuilder::setEdad(int edad) {
    this->edad = edad;
    return *this;
}

PacienteBuilder& PacienteBuilder::setTemperatura(float temperatura) {
    this -> temperatura = temperatura;
    return *this;
}

PacienteBuilder& PacienteBuilder::setDolor(int dolor) {
    this -> dolor = dolor;
    return *this;
}

PacienteBuilder& PacienteBuilder::setTipoDolor(const string& tipoDolor) {
    this -> tipoDolor = tipoDolor;
    return *this;
}

PacienteBuilder& PacienteBuilder::setSintomasNeurologicos(bool sintomasNeurologicos) {
    this -> sintomasNeurologicos = sintomasNeurologicos;
    return *this;
}

PacienteBuilder& PacienteBuilder::setRequiereCirugia(bool requiereCirugia) {
    this -> requiereCirugia = requiereCirugia;
    return *this;
}

PacienteBuilder& PacienteBuilder::setDiasHospitalizacion(int diasHospitalizacion) {
    this -> diasHospitalizacion = diasHospitalizacion;
    return *this;
}

Paciente* PacienteBuilder::build() {
    return new Paciente(
        id,
        nombre,
        edad,
        temperatura,
        presionArterial,
        dolor,
        tipoDolor,
        trauma,
        sintomasNeurologicos,
        requiereCirugia,
        diasHospitalizacion
        );
}
