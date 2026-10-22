//
// Created by seba2 on 19-10-2026.
//

#include "../../include/utils/PrintPaciente.h"
using namespace std;
PrintPaciente::PrintPaciente() {
}

void PrintPaciente::datos(Paciente* p) {
    if (p == nullptr) {
        cout << "No hay paciente" << endl;
        return;
    }
    string presion = p->getPresionArterial();
    string mostrarPresion = "";
    for (char c : presion) {
        if (c == '.') {
            mostrarPresion = mostrarPresion + "/";
        }else {
            mostrarPresion = mostrarPresion + c;
        }
    }

    cout << "ID: " << id(p->getId()) << endl
         << "Nombre: " << p->getNombre() << endl
         << "Edad: " << p->getEdad() << endl
         << "Temperatura: " << p->getTemperatura() << endl
         << "Presion arterial: " <<  mostrarPresion<< endl
         << "Nivel de dolor: " << p->getDolor() << endl
         << "Tipo de dolor: " << p->getTipoDolor() << endl
         << "Trauma: " << (p->isTrauma() ? "Si" : "No") << endl
         << "Sintomas neurologicos: "<< (p->isSintomasNeurologicos() ? "Si" : "No") << endl
         << "Requiere cirugia: " << (p->isRequiereCirugia() ? "Si" : "No") << endl
         << "Dias de hospitalizacion: "<< p->getDiasHospitalizacion() << endl;
}

string PrintPaciente::id(int id) {
    string cero = "";
    if (id - 10 < 0) {
        cero+= "00";
    }else if(id - 100 < 0) {
        cero+="0";
    }
    return cero + to_string(id);

}