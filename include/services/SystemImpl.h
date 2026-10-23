//
// Created by seba2 on 19-10-2026.
//

#ifndef TALLERESTRUCT_SYSTEMIMPL_H
#define TALLERESTRUCT_SYSTEMIMPL_H
#include "System.h"
#include "../../include/struct/ArbolAVL.h"

struct DepartamentoAVL {
    string nombre;
    ArbolAVL<Paciente*>* arbol;
};

class SystemImpl : public System {
private:
    DepartamentoAVL departamentos[8];
    int obtenerIndiceDepto(const string& nombre);
    void imprimirPacientesInline(NodoAVL<Paciente*>* nodo, bool& primero);
public:
    SystemImpl();
    ~SystemImpl();
    void cargarFila(List<Paciente *>* datos, Queue<Paciente *>* fila) override;

    ArbolDecision* buildArbolDecision() override;

    void registrarPacienteEnServicio(Paciente* p, const string& servicio);
    void mostrarPacientesPorServicio(const string& servicio);
    void buscarPacientePorID(int id);
    bool buscarEnArbolRecursivo(NodoAVL<Paciente*>* nodo, const string& query, string& ruta, Paciente*& pacienteEncontrado);
    void buscarPaciente(const string &query);
    void mostrarEstadoDepartamentos();
};


#endif //TALLERESTRUCT_SYSTEMIMPL_H