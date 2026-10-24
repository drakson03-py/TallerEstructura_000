
//
// Created by seba2 on 19-10-2026.
//

#ifndef TALLERESTRUCT_PRINTPACIENTE_H
#define TALLERESTRUCT_PRINTPACIENTE_H

#include "../model/Paciente.h"

/**
 * @brief Presenta informacion de los pacientes en formato de texto.
 *
 * Proporciona metodos para mostrar los datos de un paciente.
 */
class PrintPaciente {

public:
    /**
     * @brief Construye un objeto para presentar datos de pacientes.
     */
    PrintPaciente();

    /**
     * @brief Muestra los datos de un paciente.
     *
     * @param p Puntero al paciente cuyos datos se desean mostrar.
     */
    void datos(Paciente* p);

    /**
     * @brief Convierte un identificador a una cadena de texto.
     *
     * @param id Identificador numerico del paciente.
     * @return Representacion textual del identificador.
     */
    string id(int id);

    /**
     * @brief Destructor por defecto.
     */
    ~PrintPaciente() = default;
};

#endif // TALLERESTRUCT_PRINTPACIENTE_H
