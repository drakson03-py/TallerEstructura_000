//
// Created by seba2 on 21-10-2026.
//

#ifndef TALLERESTRUCT_ARBOLDECISION_H
#define TALLERESTRUCT_ARBOLDECISION_H
#include "../struct/BTNode.h"
#include "../model/Paciente.h"
#include <iostream>

enum class Operador {
    MAYOR,
    MENOR,
    IGUAL,
    DISTINTO,
    MAYOR_IGUAL,
    MENOR_IGUAL
};
enum class Atributo {
    ID,
    NOMBRE,
    EDAD,
    TEMPERATURA,
    PRESION_SISTOLE,
    PRESION_DIASTOLE,
    DOLOR,
    TIPO_DOLOR,
    TRAUMA,
    SINTOMAS_NEUROLOGICOS,
    REQUIERE_CIRUGIA,
    DIAS_HOSPITALIZACION
};
struct Condicion {
    Atributo atributo;
    string valor;
    string ruta;
    Operador operador;
    bool isNumero;
    string servicio;

    bool cumple(const string dato)const {
        if (isNumero) {
            float nDato;
            float nValor;
            try {
                nDato = stof(dato);
                nValor = stof(valor);
            }catch (...) {
                return false;
            }

            if (operador == Operador::MAYOR){return nDato >nValor;}
            if (operador == Operador::MENOR){return nDato <nValor;}
            if (operador == Operador::MAYOR_IGUAL){return nDato >= nValor;}
            if (operador == Operador::MENOR_IGUAL){return nDato <= nValor;}
            if (operador == Operador::IGUAL){return nDato == nValor;}
            if (operador == Operador::DISTINTO){return nDato != nValor;}
            return false;
        }

        if (operador == Operador::IGUAL){return dato == valor;}
        if (operador == Operador::DISTINTO){return dato != valor;}

        return false;
    }
};

class ArbolDecision {
private:
    BTNode<Condicion>* raiz;
    bool cumpleCondicion(Paciente* p,BTNode<Condicion>* node, string* ruta);
    void liberar();
public:
    ArbolDecision();
    ArbolDecision(BTNode<Condicion>* raiz);

    void setRaiz(BTNode<Condicion>* raiz);
    int altura();

    ~ArbolDecision();

    string decision(Paciente *paciente,string* ruta = nullptr);

};


#endif //TALLERESTRUCT_ARBOLDECISION_H