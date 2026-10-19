//
// Created by seba2 on 19-10-2026.
//
#include <fstream>
#include <sstream>
#include <filesystem>
#include "../../include/utils/FilePaciente.h"

FilePaciente::FilePaciente(const string& file):file(file),ids(new List<int>()),archivoValido(false){}

int FilePaciente::leerArchivo() {
    delete ids;
    ids = new List<int>();
    archivoValido = false;

    filesystem::path data_dir = DATA_DIR;
    ifstream archivo(data_dir / this->file);//Accede al archivo de la carpeta data
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
        string id_str;
        getline(ss,id_str,';' );
        int id = stoi(id_str);

        if (isPacienteRepetido(id)) {
            archivo.close();
            return 3;
        }
        ids->insertLast(id);
    }
    archivo.close();
    archivoValido = true;
    return 0;
}

bool FilePaciente::cargarArchivo(List<Paciente *> *datos) {
    if (!archivoValido || datos == nullptr) {
        return false;
    }

    filesystem::path data_dir = DATA_DIR;
    ifstream archivo(data_dir / file);

    if (!archivo.is_open()) {
        archivoValido = false;
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        //Lee el archivo
        stringstream ss(linea);//Lee una linea
        string str_id, nombre, str_edad, str_temperatura, str_presion, str_dolor, tipoDolor, str_trauma, str_sintomasNeuro, str_cirugia, str_dias;

        getline(ss, str_id, ';');
        getline(ss, nombre, ';');
        getline(ss, str_edad, ';');
        getline(ss, str_temperatura, ';');
        getline(ss, str_presion, ';');
        getline(ss, str_dolor, ';');
        getline(ss, tipoDolor, ';');
        getline(ss, str_trauma, ';');
        getline(ss, str_sintomasNeuro, ';');
        getline(ss, str_cirugia, ';');
        getline(ss, str_dias, ';');

        Paciente* p = new Paciente(
        stoi(str_id),
        nombre,
        stoi(str_edad),
        stof(str_temperatura),
        stof(str_presion),
        stoi(str_dolor),
        tipoDolor,
        str_trauma != "0",
        str_sintomasNeuro != "0",
        str_cirugia != "0",
        stoi(str_dias)
        );

        datos->insertLast(p);
    }
    archivo.close();
    return true;
}


bool FilePaciente::isPacienteRepetido(int id) {
    for (int i = 0; i < ids->getSize(); i++) {
        if (ids->get(i) == id){return true;}
    }
    return false;

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
    delete ids;
}