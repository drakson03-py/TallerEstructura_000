//
// Created by seba2 on 19-10-2026.
//
#include <fstream>
#include <sstream>
#include <filesystem>
#include "../../include/utils/FilePaciente.h"
#include "../../include/utils/PacienteBuilder.h"

FilePaciente::FilePaciente(const string& archivo) : archivo(archivo),datos(new List<Paciente*>){}

int FilePaciente::cargarDatos() {
    filesystem::path data_dir = DATA_DIR;
    ifstream archivo(data_dir / this ->archivo);//Accede al archivo de la carpeta data
    if (!archivo.is_open()) {
        return 1;
    }

    string linea;
    while (getline(archivo, linea)) {
        //Lee el archivo
        stringstream ss(linea);//Lee una linea
        if (!this->isLineaValida(ss)) {
            archivo.close();
            return 2;
        }

        Paciente* p = PacienteBuilder().buildLine(ss);

        if (this->isPacienteRepetido(p->getId())) {
            delete p;
            archivo.close();
            return 3;
        }
        datos->insertLast(p);
    }
    archivo.close();
    return 0;
}

List<Paciente*>* FilePaciente::getDatos() {
    return this->datos;
}

bool FilePaciente::isPacienteRepetido(int id) {
    int aux = 0;
    while (true) {
        try {
            if (datos->get(aux)->getId() == id){return true;}
            aux++;
        }catch (...) {
            return false;
        }
    }
}

bool FilePaciente::isLineaValida(stringstream& ss) {

    string str_id, nombre, str_edad, str_temperatura, str_presion,
    str_dolor, tipoDolor, str_trauma, str_sintomasNeuro, str_cirugia, str_dias;

    stringstream copy(ss.str());
    string recolector;

    getline(copy, str_id, ';'); if (!isNumeroEntero(str_id)){return false;}
    getline(copy, nombre, ';'); if (isAtributoVacio(nombre)){return false;}
    getline(copy, str_edad, ';'); if (!isNumeroEntero(str_edad)){return false;}
    getline(copy, str_temperatura, ';'); if (!isNumeroPositivo(str_temperatura)){return false;}
    getline(copy, str_presion, ';'); if (!isNumeroPositivo(str_presion)){return false;}
    getline(copy, str_dolor, ';'); if (!isNumeroEntero(str_dolor)){return false;}
    getline(copy, tipoDolor, ';'); if (!isDolorValido(tipoDolor)){return false;}
    getline(copy, str_trauma, ';'); if (!isBool(str_trauma)){return false;}
    getline(copy, str_sintomasNeuro, ';'); if (!isBool(str_sintomasNeuro)){return false;}
    getline(copy, str_cirugia, ';'); if (!isBool(str_cirugia)){return false;}
    getline(copy, str_dias, ';'); if (!isNumeroEntero(str_dias)){return false;}
    getline(copy,recolector,'\n'); if (!recolector.empty()){return false;}

    return true;
}

bool FilePaciente::isDolorValido(string dolor) {
    string dolores[5] = {"pecho","cabeza","abdomen","extremidad","otro"};

    for (string tipo : dolores) {
        if (dolor == tipo){return true;}
    }

    return false;
}


bool FilePaciente::isBool(string b) {
    if (b == "0" || b == "1"){ return true;}
    return false;
}

bool FilePaciente::isAtributoVacio(string atributo) {
    if (atributo == ""){return true;}
    int espacio = 0, size = 0;
    for (char c :atributo) {
        if (c == ' ') {
            espacio++;
        }
        size++;
    }
    return espacio == size;
}

bool FilePaciente::isNumeroPositivo(string num) {
    if (num == ""){return false;}
    if (!isdigit(num[0])){return false;}

    bool decimal = false;
    for (char c : num) {

        if (decimal) {
            if (!(c>='0' && c <= '9')) {
                return false;
            }
        }else if(c == '.') {
            decimal = true;
        }else if (!(c>='0' && c <= '9')){
            return false;
        }
    }
    return true;
}

bool FilePaciente::isNumeroEntero(string num) {
    if (num == ""){return false;}
    for (char c : num) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

FilePaciente::~FilePaciente() {
    int aux = 0;
    while (true) {
        try {
            delete datos->get(aux);
            aux++;
        }catch (...) {break;}
    }
    delete datos;
}