
#ifndef TALLERESTRUCT_HOSPITALMARMAJA_H
#define TALLERESTRUCT_HOSPITALMARMAJA_H


#include "System.h"
#include "../struct/Struct.h"
#include "../model/Paciente.h"
#include <iostream>
using namespace std;

/**
 * Representa el sistema de gestion del Hospital Marmaja
 * Administra los pacientes, su atención, los departamentos
 * y el historial de atenciones
 */
class HospitalMarmaja: public System {
private:
    List<Paciente*>* datos; /**< Lista que almacena los punteros a los pacientes  */
    Queue<Paciente*>* fila; /**< Cola que almacena los pacientes pendientes en atender */
    Stack<Paciente*>* historial; /**< Pila que almacena los pacientes atendidos */
    List<List<Paciente*>*>* departamentos; /**< Lista que contiene los pacientes atendidos en cada departamento */
public:

    /**
     * Constructor de la clase
     * @param archivo Nombre del archivo que contiene los datos de los pacientes
     */
    HospitalMarmaja(string archivo);

    bool cargaDePacientes() override;//s
    void verDepartamento() override;//s
    void atenderPacientes() override;//a
    void revisarHistorialDeAtencion() override;//a

    /**
     * Destructor de la clase
     */
    ~HospitalMarmaja() override;//a

    /**
     * Convierte el id de un paciente a un texto en formato "000"
     *
     * @param id Id del paciente
     * @return Id en formato "000"
     */
    string idString(int id);//s

    /**
     * Muestra un paciente según el formato seleccionado
     *
     * @param p Puntero al paciente que se desea mostrar
     * @param forma Formato utilizado para mostrar el paciente
     */
    void imprimirPaciente(Paciente* p, string forma);//s

    /**
     * Verifica si un id de un paciente ya se encuentra registrado
     *
     * @param id Id que se desea verificar
     * @return true si el identificador está repetido, false en caso contrario
     */
    bool pacienteRepetido(int id);//s
};


#endif //TALLERESTRUCT_HOSPITALMARMAJA_H