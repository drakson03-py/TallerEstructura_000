//
// Created by seba2 on 18-10-2026.
//

#ifndef TALLERESTRUCT_PACIENTEBUILDER_H
#define TALLERESTRUCT_PACIENTEBUILDER_H
#include <sstream>
#include "../model/Paciente.h"
using namespace std;

class PacienteBuilder {
private:
    int id;
    string nombre;
    int edad;
    float temperatura;
    float presionArterial;
    int dolor;
    string tipoDolor;
    bool trauma;
    bool sintomasNeurologicos;
    bool requiereCirugia;
    int diasHospitalizacion;

public:
    PacienteBuilder();
    PacienteBuilder& setId(int id);
    PacienteBuilder& setNombre(const string& nombre);
    PacienteBuilder& setEdad(int edad);
    PacienteBuilder& setTemperatura(float temperatura);
    PacienteBuilder& setPresionArterial(float presionArterial);
    PacienteBuilder& setDolor(int dolor);
    PacienteBuilder& setTipoDolor(const string& tipoDolor);
    PacienteBuilder& setTrauma(bool trauma);
    PacienteBuilder& setSintomasNeurologicos(bool sintomasNeurologicos);
    PacienteBuilder& setRequiereCirugia(bool requiereCirugia);
    PacienteBuilder& setDiasHospitalizacion(int diasHospitalizacion);
    Paciente* build();
    Paciente* buildLine(stringstream& ss);
};

#endif //TALLERESTRUCT_PACIENTEBUILDER_H