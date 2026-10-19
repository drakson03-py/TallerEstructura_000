//
// Created by seba2 on 19-10-2026.
//

#ifndef TALLERESTRUCT_FILEREADER_H
#define TALLERESTRUCT_FILEREADER_H

#include "../model/Paciente.h"
#include "../struct/List.h"
#include <iostream>
using namespace std;

class FilePaciente {
private:
    List<int>* ids;
    string file;
    bool archivoValido;
    bool isPacienteRepetido(int id);
    bool isLineaValida(stringstream& ss);
    bool isNumeroPositivo(string num);
    bool isNumeroEntero(string num);
    bool isAtributoVacio(string atributo);
    bool isBool(string b);
    bool isDolorValido(string dolor);

public:
    FilePaciente(const string& archivo);
    int leerArchivo();
    bool cargarArchivo(List<Paciente*>* datos);
    ~FilePaciente();
};


#endif //TALLERESTRUCT_FILEREADER_H