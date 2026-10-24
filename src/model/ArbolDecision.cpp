//
// Created by seba2 on 21-10-2026.
//

#include "../../include/model/ArbolDecision.h"
#include "../../include/struct/Stack.h"
ArbolDecision::ArbolDecision():raiz(nullptr) {}
ArbolDecision::ArbolDecision(BTNode<Condicion>* raiz):raiz(raiz){}


bool ArbolDecision::cumpleCondicion(Paciente *p, BTNode<Condicion> *node, string* ruta) {
    Condicion condicion = node->getValue();
    string atributo = "";
    switch (condicion.atributo) {
        case Atributo::EDAD:
            atributo = to_string(p->getEdad());
            break;
        case Atributo::TEMPERATURA:
            atributo = to_string(p->getTemperatura());
            break;
        case Atributo::PRESION_SISTOLE:
            for (int i = 0; i<3;i++) {
                atributo = atributo + p->getPresionArterial()[i];
            }
            break;
        case Atributo::PRESION_DIASTOLE:
            for (int i = 4; i < 7; i++) {
                atributo = atributo + p->getPresionArterial()[i];
            }
            break;
        case Atributo::DOLOR:
            atributo = to_string(p->getDolor());
            break;
        case Atributo::TIPO_DOLOR:
            atributo = p->getTipoDolor();
            break;
        case Atributo::TRAUMA:
            atributo = (p->isTrauma()? "true":"false");
            break;
        case Atributo::SINTOMAS_NEUROLOGICOS:
            atributo = (p->isSintomasNeurologicos()? "true":"false");
            break;
        case Atributo::REQUIERE_CIRUGIA:
            atributo = (p->isRequiereCirugia()? "true":"false");
            break;
        case Atributo::DIAS_HOSPITALIZACION:
            atributo = to_string(p->getDiasHospitalizacion());
            break;
        default:
            break;
    }
    bool cumple =  condicion.cumple(atributo);
    if (ruta) {
        *ruta= *ruta + " -> "+"["+atributo+"]"+ condicion.ruta +(cumple? ":Si":":No");
    }
    return cumple;
}

string ArbolDecision::decision(Paciente *paciente,string* ruta) {
    if (!this->raiz) {
        return "Sin Arbol de deciciones";
    }

    BTNode<Condicion>* cur = this->raiz;

    while (cur->getLeft()||cur->getRight()) {
        if (cumpleCondicion(paciente,cur,ruta)) {
            cur = cur->getLeft();
        }else {
            cur = cur->getRight();
        }
    }
    string servicio = cur->getValue().servicio;
    if (ruta) {
        *ruta = *ruta + " |Decision: "+servicio;
    }
    return servicio;
}


void ArbolDecision::liberar() {
    if (raiz == nullptr) {
        return;
    }
    Stack<BTNode<Condicion>*> pila;
    Stack<BTNode<Condicion>*> pilaAux;

    pila.push(raiz);

    while (!pila.empty()) {
        BTNode<Condicion>* actual = pila.top();
        pila.pop();

        pilaAux.push(actual);

        if (actual->getLeft() != nullptr) {
            pila.push(actual->getLeft());
        }

        if (actual->getRight() != nullptr) {
            pila.push(actual->getRight());
        }
    }

    while (!pilaAux.empty()) {
        BTNode<Condicion>* actual = pilaAux.top();
        pilaAux.pop();

        delete actual;
    }

    raiz = nullptr;

}
void ArbolDecision::setRaiz(BTNode<Condicion>* raiz) {
    if (this->raiz == nullptr) {
        this->raiz = raiz;
        return;
    }
    this->liberar();
    this->raiz = raiz;
}

ArbolDecision::~ArbolDecision() {
    if (raiz == nullptr) {
        return;
    }
    this->liberar();
}



