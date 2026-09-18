
#ifndef TALLERESTRUCT_SYSTEM_H
#define TALLERESTRUCT_SYSTEM_H
#include <iostream>
using namespace std;

/**
 * Clase abstracta que define las operaciones principales del sistema
 */
class System {
protected:
    string archivo; /**< Nombre del archivo de texto utilizado por el sistema */
public:
    /**
     * Constructor de la clase
     * @param archivo Archivo de datos utilizado por el sistema
     */
    System(string archivo) {
        this -> archivo = archivo;
    }

    /**
     * Carga los pacientes desde el archivo de datos
     *
     * El archivo debe contener los datos en el formato
     * id;nombre;edad;servicio
     *
     * @return true si la lectura se completó correctamente, false en caso contrario
     */
    virtual bool cargaDePacientes() = 0;

    /**
     * Atiende a los pacientes segun su orden de llegada
     *
     * Los pacientes atendidos son derivados a sus departamentos correspondientes
     * y registrados en el historial de atenciones
     */
    virtual void atenderPacientes() = 0;

    /**
     * Muestra los departamentos y permite consultar los pacientes atendidos en un departamento
     */
    virtual void verDepartamento() = 0;

    /**
     * Muestra el historial de atenciones realizadas
     */
    virtual void revisarHistorialDeAtencion() = 0;

    /**
     * Permite buscar un paciente por su id y mostrarlo
     */
    virtual void buscarPaciente() = 0;

    /**
     * Destructor de la clase
     */
    virtual ~System() = default;

};

#endif //TALLERESTRUCT_SYSTEM_H