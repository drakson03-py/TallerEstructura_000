//
// Created by Alan Galleguillos on 23-10-2026.
//

#ifndef TALLERESTRUCT_RESULTADOBUSQUEDA_H
#define TALLERESTRUCT_RESULTADOBUSQUEDA_H

#include <string>
#include "Paciente.h"
using namespace std;

struct ResultadoBusqueda {
    bool encontrado;
    Paciente* paciente;
    string departamento;
    string ruta;
};

#endif