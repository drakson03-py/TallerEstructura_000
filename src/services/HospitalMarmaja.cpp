#include "../../include/services/HospitalMarmaja.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <filesystem>

using namespace std;

HospitalMarmaja::HospitalMarmaja(string archivo) : System(archivo)  {
    this-> datos = new List<Paciente*>();
    this -> fila = new Queue<Paciente*>();
    this -> historial = new Stack<Paciente*>();
    this -> departamentos = new List<List<Paciente*>*>();
    for (int i = 0; i<( 8 ); i++) {
        List<Paciente*>* value = new List<Paciente*>();
        departamentos->insertLast(value);
    }
}
const int n = 8;
const string lista[( n )] = {
    "Urgencias"
    ,"Medicina General"
    ,"Cardiologia"
    ,"Neurologia"
    ,"Traumatologia"
    ,"Cirugia"
    ,"Pediatria"
    ,"Hospitalizacion"
};
const string* ptr = lista;
const string separador= "------------------------------------------";

void HospitalMarmaja::cargaDePacientes() {
    filesystem::path data_dir = DATA_DIR;

    ifstream archivo(data_dir / this ->archivo);
    if (!archivo.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo" << endl;
        exit(0);
    }
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);

        string str_id;
        int id;
        string nombre;
        string str_edad;
        int edad;
        string servicio;

        string lineaNoValida;

        getline(ss, str_id, ';');
        getline(ss, nombre, ';');
        getline(ss, str_edad, ';');
        getline(ss, servicio, ';');
        getline(ss,lineaNoValida);
        if (lineaNoValida != "") {
            cout << "ERROR: El archivo contiene datos no validos";
            cout<<"  ->Linea con argumentos no validos  ";
            exit(0);
        }

        try {
            id = stoi(str_id);
            edad = stoi(str_edad);
            if (id < 0 || edad <=0) {
                cout << "ERROR: El archivo contiene datos no validos";
                cout<<"  ->Id o Edad no valida  ";
                exit(0);
            }
        }catch (...) {
            cout << "ERROR: El archivo contiene datos no validos";
            cout << "  ->Id o Edad no valida  ";
            exit(0);
        }

        bool noValido = true;
        for (int i = 0; i < n; i++ ) {
            if ( *ptr == servicio) {
                noValido = false;
                break;
            }
            ptr++;
        }
        ptr = lista;

        if (noValido) {
            cout << "ERROR: El archivo contiene datos no validos";
            cout<<"  -> Servicio  ";
            exit(0);
        }
        if (pacienteRepetido(id)) {
            cout << "ERROR: El archivo contiene mas de 1 paciente con el mismo ID";
            exit(0);
        }
        Paciente* p = new Paciente(id,nombre,edad,servicio);
        datos->insertLast(p);
        fila->push(p);
    }
    archivo.close();

}

void HospitalMarmaja::verDepartamento() {
    cout <<"====== Departamentos ======";
    int i = 1;
    ptr = lista;
    while (ptr < lista + n) {
        cout<<endl
        <<i<<". "<<*ptr;
        ptr++;
        i++;
    }

    string opcion = "";
    cout<<endl<<endl<<"Seleccione una opcion: ";
    cin>>opcion;
    ptr = lista;
    while (ptr < lista + n) {
        if (opcion == to_string(ptr-lista + 1)) {
            if (departamentos->get(ptr-lista)->isEmpty()) {
                cout<<"Aun no hay pacientes atendidos en este departamento.."<<endl;
                return;
            }
            int aux = 0;
            cout<<endl<<"====== Departamento de "<< *ptr<< " ======" << endl;
            while (true) {
                try {
                    imprimirPaciente(departamentos->get(ptr-lista)->get(aux),"departamentos");
                    cout<<endl;
                    aux++;
                }catch(...) {
                    cout<<endl<<"Pacientes atendidos: "<<aux<<endl;
                    cout<<separador<<endl;
                    return;
                }
            }

        }
        ptr++;
    }
    cout<<endl<<"ERROR: Seleccione una opcion valida"<<endl;
}

void HospitalMarmaja::atenderPacientes() {
    cout<<"======= Atendiendo Pacientes =======";
    if (fila->empty()) {
        cout <<endl<< "NO hay pacientes por atender..";
        return;
    }
    Queue<Paciente*>* aux = new Queue<Paciente*>();
    int i = 1;
    while (!fila->empty()) {
        cout << endl <<i << ".  "; imprimirPaciente(fila->front(), "atender");
        aux -> push(fila->front());
        fila->pop();
        i++;
    }
    delete fila;
    fila = aux;

    string str_cantidad = "";
    int cantidad;
    cout << endl << endl<<"Ingrese la cantidad de pacientes a atender: ";
    cin >> str_cantidad;
    try {
        cantidad = stoi(str_cantidad);
        if (cantidad <= 0) {
            cout<<"ERROR: Ingrese una cantidad valida"<<endl;
            return;
        }

    }catch (...) {
        cout<<"ERROR: Ingrese una cantidad valida"<<endl;
        return;
    }
    cout<<"Pacientes atendidos...";
    cout <<endl<< separador;
    for (int i = 0; i < cantidad; i++) {
        if (fila->empty()) {
            cout<<endl<<"Se han atendido todos los pacientes disponibles.."<<endl;
            return;
        }
        cout<<endl;
        imprimirPaciente(fila->front(),"atendido");
        cout << endl<<separador;

        historial->push(fila->front());
        ptr = lista;
        while (ptr < lista + n) {
            if (*ptr == fila->front()->getServicio()) {
                 departamentos->get(ptr - lista)->insertLast(fila->front());
                break;
            }
            ptr++;
        }
        ptr = lista;
        fila->pop();
    }
    cout<<endl;

}

void HospitalMarmaja::revisarHistorialDeAtencion() {
    if (historial->empty()) {
        cout<<"No hay pacientes atendidos todavia..."<<endl;
        return;
    }
    cout<<"====== Historial de pacientes atendidos ======"<<endl;
    Stack<Paciente*>* aux = new Stack<Paciente*>();
    while (!historial->empty()) {
        imprimirPaciente(historial->top(),"historial");
        cout<<endl;
        aux->push(historial->top());
        historial->pop();
    }
    while (!aux->empty()) {
        historial->push(aux->top());
        aux->pop();
    }
    delete aux;
    cout<<separador<<endl;
}

void HospitalMarmaja::finalizar() {
    int aux = 0;
    while (true) {
        try {
            delete datos->get(aux);
            aux++;
        }catch (...) {
            break;
        }
    }
    delete datos;
    cout<<"--> Cerrando programa...";
}

HospitalMarmaja::~HospitalMarmaja() {
    delete fila;
    delete historial;
    delete departamentos;
}
string HospitalMarmaja::idString(int id) {
    string cero = "";
    if (id - 10 < 0) {
        cero+= "00";
    }else if(id - 100 < 0) {
        cero+="0";
    }
    return cero + to_string(id);
}
void HospitalMarmaja::imprimirPaciente(Paciente* p, string forma) {
    string id = idString(p->getId());
    if (forma == "atender"){
        cout
        << id << " - "
        << p->getNombre();

    }else if (forma == "historial") {
        cout
        << "Nombre: " << p->getNombre() << " | "
        << "Edad: " << p->getEdad()<<" | "
        << "Servicio: " << p->getServicio();
    }else if (forma == "atendido") {
        cout
        << "ID: " <<id <<endl
        << "Nombre: " << p->getNombre() << endl
        << "Edad: " << p->getEdad()<<endl
        << "Servicio: " << p->getServicio() << endl
        << endl << "Paciente enviado a "<<p->getServicio()<<".";
    }else if (forma == "escribir") {

    }else if (forma == "departamentos") {
        cout
        << "Nombre: " << p->getNombre()
        <<" ("<<p->getEdad()<< ")";
    }
}

bool HospitalMarmaja::pacienteRepetido(int id) {
    int aux = 0;
    while (true) {
        try {
            if (datos->get(aux)->getId() == id) {
                return true;
            }
            aux++;

        }catch (...) {
            return false;
        }
    }
}