//
// Created by seba2 on 18-10-2026.
//


//
// Created by seba2 on 18-10-2026.
//

#ifndef TALLERESTRUCT_PACIENTE2_H
#define TALLERESTRUCT_PACIENTE2_H

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Representa a un paciente registrado en el sistema.
 *
 * Almacena la informacion personal, los signos vitales, las caracteristicas
 * del dolor y los antecedentes utilizados para determinar su servicio
 * de atencion.
 */
class Paciente {
private:
    int id;
    string nombre;
    int edad;
    float temperatura;
    string presionArterial;
    int dolor;
    string tipoDolor;
    bool trauma;
    bool sintomasNeurologicos;
    bool requiereCirugia;
    int diasHospitalizacion;

public:
    /**
     * @brief Construye un paciente con sus datos iniciales.
     *
     * @param id Identificador numerico del paciente.
     * @param nombre Nombre completo del paciente.
     * @param edad Edad del paciente en anos.
     * @param temperatura Temperatura corporal del paciente.
     * @param presionArterial Presion arterial en formato ###.###.
     * @param dolor Intensidad del dolor en una escala de 0 a 10.
     * @param tipoDolor Tipo de dolor: pecho, cabeza, abdomen, extremidad u otro.
     * @param trauma Indica si el paciente presenta un trauma.
     * @param sintomasNeurologicos Indica si presenta sintomas neurologicos.
     * @param requiereCirugia Indica si necesita una intervencion quirurgica.
     * @param diasHospitalizacion Cantidad estimada de dias de hospitalizacion.
     *
     */
    Paciente(int id, const string &nombre, int edad, float temperatura,
             string presionArterial, int dolor, const string &tipoDolor,
             bool trauma, bool sintomasNeurologicos, bool requiereCirugia,
             int diasHospitalizacion);

    /**
     * @brief Obtiene el identificador del paciente.
     * @return Identificador del paciente.
     */
    int getId() const;

    /**
     * @brief Modifica el identificador del paciente.
     * @param id Nuevo identificador.
     */
    void setId(int id);

    /**
     * @brief Obtiene el nombre del paciente.
     * @return Nombre completo del paciente.
     */
    string getNombre() const;

    /**
     * @brief Modifica el nombre del paciente.
     * @param nombre Nuevo nombre completo.
     */
    void setNombre(const string &nombre);

    /**
     * @brief Obtiene la edad del paciente.
     * @return Edad en años.
     */
    int getEdad() const;

    /**
     * @brief Modifica la edad del paciente.
     * @param edad Nueva edad en años.
     */
    void setEdad(int edad);

    /**
     * @brief Obtiene la temperatura corporal.
     * @return Temperatura del paciente.
     */
    float getTemperatura() const;

    /**
     * @brief Modifica la temperatura corporal.
     * @param temperatura Nueva temperatura corporal.
     */
    void setTemperatura(float temperatura);

    /**
     * @brief Obtiene la presion arterial.
     * @return Presion arterial en formato ###.###.
     */
    string getPresionArterial() const;

    /**
     * @brief Modifica la presion arterial.
     * @param presionArterial Nueva presion arterial en formato ###.###.
     */
    void setPresionArterial(string presionArterial);

    /**
     * @brief Obtiene la intensidad del dolor.
     * @return Intensidad del dolor en una escala de 0 a 10.
     */
    int getDolor() const;

    /**
     * @brief Modifica la intensidad del dolor.
     * @param dolor Nueva intensidad del dolor.
     */
    void setDolor(int dolor);

    /**
     * @brief Obtiene el tipo de dolor.
     * @return Tipo de dolor registrado.
     */
    string getTipoDolor() const;

    /**
     * @brief Modifica el tipo de dolor.
     * @param tipoDolor Nuevo tipo de dolor.
     */
    void setTipoDolor(const string &tipoDolor);

    /**
     * @brief Comprueba si el paciente presenta un trauma.
     * @return true si presenta trauma; false en caso contrario.
     */
    bool isTrauma() const;

    /**
     * @brief Modifica el indicador de trauma.
     * @param trauma true si presenta trauma; false en caso contrario.
     */
    void setTrauma(bool trauma);

    /**
     * @brief Comprueba si el paciente presenta sintomas neurologicos.
     * @return true si presenta sintomas neurologicos; false en caso contrario.
     */
    bool isSintomasNeurologicos() const;

    /**
     * @brief Modifica el indicador de sintomas neurologicos.
     * @param sintomasNeurologicos true si presenta sintomas neurologicos;
     * false en caso contrario.
     */
    void setSintomasNeurologicos(bool sintomasNeurologicos);

    /**
     * @brief Comprueba si el paciente requiere cirugia.
     * @return true si requiere cirugia; false en caso contrario.
     */
    bool isRequiereCirugia() const;

    /**
     * @brief Modifica el indicador de necesidad de cirugia.
     * @param requiereCirugia true si requiere cirugia; false en caso contrario.
     */
    void setRequiereCirugia(bool requiereCirugia);

    /**
     * @brief Obtiene la cantidad estimada de dias de hospitalizacion.
     * @return Cantidad estimada de dias.
     */
    int getDiasHospitalizacion() const;

    /**
     * @brief Modifica la cantidad estimada de dias de hospitalizacion.
     * @param diasHospitalizacion Nueva cantidad estimada de dias.
     */
    void setDiasHospitalizacion(int diasHospitalizacion);

    /**
     * @brief Destructor por defecto del paciente.
     */
    ~Paciente() = default;
};

#endif // TALLERESTRUCT_PACIENTE2_H
