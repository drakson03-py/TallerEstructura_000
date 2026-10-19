//
// Created by seba2 on 18-10-2026.
//

#ifndef TALLERESTRUCT_PACIENTE2_H
#define TALLERESTRUCT_PACIENTE2_H


#include <iostream>
using namespace std;

class Paciente {
private:
    int id;
    string nombre;
    int edad;
    float temperatura;
    float presionArterial;
    int dolor;
    string tipoDolor;
    bool trauma;
    bool sintomasNeurologicos;
    bool requiereCirugia;
    int diasHospitalizacion;

public:
    /**
     * aa
     * @param id aa
     * @param nombre
     * @param edad
     * @param temperatura
     * @param presionArterial
     * @param dolor
     * @param tipoDolor
     * @param trauma
     * @param sintomasNeurologicos
     * @param requiereCirugia
     * @param diasHospitalizacion
     */
    Paciente(int id, const string &nombre, int edad, float temperatura, float presionArterial, int dolor,
             const string &tipoDolor, bool trauma, bool sintomasNeurologicos, bool requiereCirugia,
             int diasHospitalizacion);


    int getId() const;
    void setId(int id);

    string getNombre() const;
    void setNombre(const string &nombre);

    int getEdad() const;
    void setEdad(int edad);

    float getTemperatura() const;
    void setTemperatura(float temperatura);

    float getPresionArterial() const;
    void setPresionArterial(float presionArterial);

    int getDolor() const;
    void setDolor(int dolor);

    string getTipoDolor() const;
    void setTipoDolor(const string &tipoDolor);

    bool isTrauma() const;
    void setTrauma(bool trauma);

    bool isSintomasNeurologicos() const;
    void setSintomasNeurologicos(bool sintomasNeurologicos);

    bool isRequiereCirugia() const;
    void setRequiereCirugia(bool requiereCirugia);

    int getDiasHospitalizacion() const;
    void setDiasHospitalizacion(int diasHospitalizacion);


    ~Paciente() = default;
};


#endif //TALLERESTRUCT_PACIENTE2_H