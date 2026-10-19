
#ifndef TALLERESTRUCT_PACIENTE_H
#define TALLERESTRUCT_PACIENTE_H

/**
     * Clase "Paciente" que modela y almacena la informacion de cada individuo extraido del archivo .txt
     */

#include <iostream>
using namespace std;

class Paciente1 {
private:
    int id;
    int edad;
    string nombre;
    string servicio;
public:
    /**
     * Constructor
     * @param id Variable tipo int que almacena su numero tipo unico identificador
     * @param nombre Variable tipo string que almacena el nombre del individuo
     * @param edad  Variable tipo int que almacena el nombre del individuo
     * @param servicio  Variable tipo string que almacena el tipo de especialidad a ser atendido del paciente
     */
    Paciente1(int id,string nombre,int edad,string servicio);

    /**
     * Devuelve el identificador del paciente
     * @return Id del paciente.
     */
    int getId();

    /**
     * Devuelve el nombre del paciente
     * @return Nombre afiliado al paciente
     */
    string getNombre();

    /**
     * Devuelve la edad del paciente
     * @return Edad afiliada al paciente
     */
    int getEdad();

    /**
     * Devuelve el servicio del paciente
     * @return Servicio del paciente
     */
    string getServicio();

    /**
     * Destructor
     */
    ~Paciente1();
};

#endif //TALLERESTRUCT_PACIENTE_H