
#ifndef TALLERESTRUCT_PACIENTE_H
#define TALLERESTRUCT_PACIENTE_H

/**
     * Clase "Paciente" que modela y almacena la informacion de cada individuo extraido del archivo .txt
     */

#include <iostream>
using namespace std;

class Paciente {
private:
    int id;
    string nombre;
    int edad;
    string servicio;
public:
    /**
     *
     * @param id Variable tipo int que almacena su numero tipo unico identificador
     * @param nombre Variable tipo string que almacena el nombre del individuo
     * @param edad  Variable tipo int que almacena el nombre del individuo
     * @param servicio  Variable tipo string que almacena el tipo de especialidad a ser atendido del paciente
     */
    Paciente(int id,string nombre,int edad,string servicio);

    /**
     *
     * @return retorna el id del paciente.
     */
    int getId();

    /**
     *
     * @return retorna el nombre afiliado al paciente
     */
    string getNombre();

    /**
     *
     * @return retorna la edad afiliada al paciente
     */
    int getEdad();

    /**
     *
     * @return retorna la especialidad a donde se debe o fue derivado el paciente.
     */
    string getServicio();
    /**
     * Destructor de la clase
     */
    ~Paciente();
};

#endif //TALLERESTRUCT_PACIENTE_H