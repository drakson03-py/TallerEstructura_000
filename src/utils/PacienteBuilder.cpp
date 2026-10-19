//
// Created by seba2 on 18-10-2026.
//

#include "../../include/utils/PacienteBuilder.h"

#include <sstream>

PacienteBuilder::PacienteBuilder()
    : id(0),nombre("Sin nombre"), edad(0), temperatura(0.0),
      presionArterial(0.0), dolor(0),
      trauma(false), sintomasNeurologicos(false),
      requiereCirugia(false), diasHospitalizacion(0){
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

PacienteBuilder& PacienteBuilder::setPresionArterial(float presionArterial) {
    this -> presionArterial = presionArterial;
    return *this;
}

PacienteBuilder& PacienteBuilder::setDolor(int dolor) {
    this -> dolor = dolor;
    return *this;
}

PacienteBuilder& PacienteBuilder::setTrauma(bool trauma) {
    this->trauma = trauma;
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

Paciente* PacienteBuilder::buildLine(stringstream& ss) {
    string str_id, nombre, str_edad, str_temperatura, str_presion, str_dolor, tipoDolor, str_trauma, str_sintomasNeuro, str_cirugia, str_dias;

    getline(ss, str_id, ';');
    getline(ss, nombre, ';');
    getline(ss, str_edad, ';');
    getline(ss, str_temperatura, ';');
    getline(ss, str_presion, ';');
    getline(ss, str_dolor, ';');
    getline(ss, tipoDolor, ';');
    getline(ss, str_trauma, ';');
    getline(ss, str_sintomasNeuro, ';');
    getline(ss, str_cirugia, ';');
    getline(ss, str_dias, ';');
    return PacienteBuilder()
        .setId(stoi(str_id))
        .setNombre(nombre)
        .setEdad(stoi(str_edad))
        .setTemperatura(stof(str_temperatura))
        .setPresionArterial(stof(str_presion))
        .setDolor(stoi(str_dolor))
        .setTipoDolor(tipoDolor)
        .setTrauma(str_trauma != "0")
        .setSintomasNeurologicos(str_sintomasNeuro != "0")
        .setRequiereCirugia(str_cirugia != "0")
        .setDiasHospitalizacion(stoi(str_dias))
        .build();
}
