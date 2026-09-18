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
    for (int i = 0; i<( 8 ); i++) {//Se crean y agregan 8 listas vacías para almacenar punteros a pacientes
        List<Paciente*>* value = new List<Paciente*>();
        departamentos->insertLast(value);
    }
}
const int n = ( 8 ) ;
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

bool HospitalMarmaja::cargaDePacientes() {
    filesystem::path data_dir = DATA_DIR;//Direccion de la carpeta data

    ifstream archivo(data_dir / this ->archivo);//Accede al archivo de la carpeta data
    if (!archivo.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo" << endl;
        return false;
    }
    string linea;
    while (getline(archivo, linea)) {//Lee el archivo
        stringstream ss(linea);//Lee una linea

        //Atributos del paciente
        string str_id;
        int id;
        string nombre;
        string str_edad;
        int edad;
        string servicio;

        string lineaNoValida;//Recoge el resto de la linea

        getline(ss, str_id, ';');
        getline(ss, nombre, ';');
        getline(ss, str_edad, ';');
        getline(ss, servicio, ';');
        getline(ss,lineaNoValida);

        //Validacion de los datos de la linea del archivo

        int espacio = 0;
        int size = 0;
        for (char c :nombre) {
            if (c == ' ') {
                espacio++;
            }
            size++;
        }
        if (espacio == size|| nombre.empty()) {
            cout << "ERROR: El archivo contiene datos no validos";
            cout<<"  ->Nombre vacio";
            return false;
        }

        if (lineaNoValida != "") {
            cout << "ERROR: El archivo contiene datos no validos";
            cout<<"  ->Linea con argumentos no validos  ";
            return false;
        }

        for (char c : str_id) {//Validacion de id
            if (!isdigit(c)) {
                cout << "ERROR: El archivo contiene datos no validos";
                cout<<"  ->Id No valido  ";
                return false;
            }
        }

        for (char c : str_edad) {//Validacion de edad
            if (!isdigit(c)) {
                cout << "ERROR: El archivo contiene datos no validos";
                cout<<"  ->Edad No valido  ";
                return false;
            }
        }

        try {
            id = stoi(str_id);
            edad = stoi(str_edad);
        }catch (...) {
            cout << "ERROR: El archivo contiene datos no validos";
            cout<<"  ->Edad o id no valido ";
            return false;
        }

        if (edad == 0) {
            cout << "ERROR: El archivo contiene datos no validos";
            cout<<"  ->Edad No valido  ";
            return false;
        }

        bool noValido = true;
        for (int i = 0; i < n; i++ ) {//Validacion del servicio
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
            return false;
        }
        if (pacienteRepetido(id)) {//Validacion de paciente unico
            cout << "ERROR: El archivo contiene mas de 1 paciente con el mismo ID";
            return false;
        }
        Paciente* p = new Paciente(id,nombre,edad,servicio);//Se construye el paciente
        datos->insertLast(p);//Se inserta en la lista de pacientes
        fila->push(p);//Se agrega a la fila
    }
    archivo.close();
    return true;

}

void HospitalMarmaja::verDepartamento() {
    cout <<"====== Departamentos ======";
    int i = 1;
    ptr = lista;
    while (ptr < lista + n) {//Muestra los departamentos
        cout<<endl
        <<i<<". "<<*ptr;
        ptr++;
        i++;
    }

    string opcion = "";
    cout<<endl<<endl<<"Seleccione una opcion: ";
    cin>>opcion;//Pide al usuario una entrada
    ptr = lista;
    while (ptr < lista + n) {//Valida si la entrada es valida
        if (opcion == to_string(ptr-lista + 1)) {//Compara la entrada con la posicion en la lista + 1

            if (departamentos->get(ptr-lista)->isEmpty()) {//Pregunta si la lista enlazada tiene pacientes en la posicion paralela a la lista
                cout<<"Aun no hay pacientes atendidos en este departamento.."<<endl;
                return;
            }
            int aux = 0;
            cout<<endl<<"====== Departamento de "<< *ptr<< " ======" << endl;
            while (true) {//Muestra los pacientes correspondientes al departamento seleccionado
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
    if (fila->empty()) {//Pregunta si la fila esta vacia
        cout <<endl<< "NO hay pacientes por atender..";
        return;
    }
    Queue<Paciente*>* copy = new Queue<Paciente*>( *fila);//Se crea una copia de la fila
    int i = 1;
    while (!copy->empty()) {
        cout << endl <<i << ".  "; imprimirPaciente(copy->front(), "atender");
        copy->pop();
        i++;
    }
    delete copy;


    string str_cantidad = "";
    int cantidad;
    cout << endl << endl<<"Ingrese la cantidad de pacientes a atender: ";
    cin >> str_cantidad;//Pide al usuario una entrada

    for (char c:str_cantidad) {//Valida la entrada
        if (!isdigit(c)) {
            cout<<"ERROR: Ingrese una cantidad valida"<<endl;
            return;
        }
    }
    cantidad = stoi(str_cantidad);
    if (cantidad == 0) {
        cout<< endl<<"No se han atendido pacientes..."<<endl;
        return;
    }

    cout<<"Pacientes atendidos...";
    cout <<endl<< separador;
    for (int i = 0; i < cantidad; i++) {//Atiende los pacientes
        if (fila->empty()) {//Pregunta si la fila esta vacia
            cout<<endl<<"Se han atendido todos los pacientes disponibles.."<<endl;
            return;
        }
        cout<<endl;
        imprimirPaciente(fila->front(),"atendido");
        cout << endl<<separador;

        historial->push(fila->front());//Se guarda el paciente en el historial
        ptr = lista;
        while (ptr < lista + n) {//Se deriva al departamento correspondiente
            if (*ptr == fila->front()->getServicio()) {//Compara el servicio con los departamentos
                 departamentos->get(ptr - lista)->insertLast(fila->front());//Inserta el paciente en el departamento correspondiente
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
    if (historial->empty()) {//Pregunta si el historial esta vacio
        cout<<"No hay pacientes atendidos todavia..."<<endl;
        return;
    }
    cout<<"====== Historial de pacientes atendidos ======"<<endl;
    Stack<Paciente*>* copy = new Stack(*historial);
    while (!copy->empty()) {//Muestra el historial de pacientes atendidos
        imprimirPaciente(copy->top(),"historial");
        cout<<endl;
        copy->pop();
    }

    delete copy;
    cout<<separador<<endl;
}

HospitalMarmaja::~HospitalMarmaja() {
    int aux = 0;
    while (true) {//Recorre toda la lista de pacientes
        try {
            delete datos->get(aux);//Destruye los pacientes
            aux++;
        }catch (...) {
            break;
        }
    }
    delete datos;
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
    else if (forma == "todo") {
        cout
        << "ID: " <<id <<endl
        << "Nombre: " << p->getNombre() << endl
        << "Edad: " << p->getEdad()<<endl
        << "Servicio: " << p->getServicio() << endl
       ;
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

void HospitalMarmaja::buscarPaciente() {
    string id_str = "";
    int id;
    try {
        cin>>id_str;
        id = stoi(id_str);
    }catch (...) {
        cout<< "ERROR: Paciente no encontrado o ID invalido"<<endl;
        return;
    }
    int contador= 0;
    try{
    while (true) {
        Paciente* paciente = datos->get(contador);
        if (paciente->getId() == id) {
            imprimirPaciente(paciente,"todo");
            return;
        }
        contador++;
    }
}catch (...){}
    cout<<"Error: Paciente no encontrado"<<endl;
}