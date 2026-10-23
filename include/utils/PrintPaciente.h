//
// Created by seba2 on 19-10-2026.
//

#ifndef TALLERESTRUCT_PRINTPACIENTE_H
#define TALLERESTRUCT_PRINTPACIENTE_H
#include "../model/Paciente.h"
#include <iostream>
using namespace std;

class PrintPaciente {
private:

public:
    PrintPaciente();
    void datos(Paciente* p);
    string id(int id);
    ~PrintPaciente() = default;
};


#endif //TALLERESTRUCT_PRINTPACIENTE_H