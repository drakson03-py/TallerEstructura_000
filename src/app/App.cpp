//
// Created by seba2 on 19-10-2026.
//

#include "../../include/app/App.h"
#include "../../include/utils/Utils.h"
#include "../../include/model/ArbolDecision.h"

App::App(const string& archivo, System* system)
    : archivo(archivo),
      system(system),
      datos(nullptr),
      fila(nullptr) {
    const string nombres[NUM_DEPARTAMENTOS] = {
                "Urgencia", "Cirugia", "Pediatria", "Cardiologia",
                "Neurologia", "Traumatologia", "Hospitalizacion", "Medicina General"
           };
        for (int i = 0; i < NUM_DEPARTAMENTOS; i++) {
                departamentos[i].nombre = nombres[i];
                departamentos[i].arbol = new ArbolAVL<Paciente*>(compararPacientesPorId);            }
}


void App::run() {

    string separador = "--------------------------------------------\n";
    if (system == nullptr) {
        cout<<"ERROR: Fallo del sistema"<<endl
        <<separador;
        return;
    }

    FilePaciente* file = new FilePaciente(this->archivo);
    int lectura = file->leerArchivo();
    if (lectura != 0) {
        if (lectura == 1) {
            cout<<"ERROR: Archivo no encontrado"<<endl
            <<separador;
        }else if (lectura == 2) {
            cout<<"ERROR: Archivo no valido -> Linea no valida"<<endl
            <<separador;
        }else if (lectura == 3) {
            cout<<"ERROR: Archivo no valido -> Paciente duplicado"<<endl
            <<separador;
        }
        delete file;
        return;
    }
    cout<<"Lectura del archivo realizada con exito.."<<endl;

    datos = new List<Paciente*>();
    bool cargaValida = file->cargarArchivo(datos);
    delete file;
    if (!cargaValida) {
        cout<<"ERROR: Fallo en la carga de datos"<<endl
        <<separador;
        return;
    }
    cout<<"Cargando datos.."<<endl;


    fila = new Queue<Paciente*>();
    system->cargarFila(datos,fila);
    ArbolDecision* arbolDecision = new ArbolDecision();
    system->buildArbolDecision(arbolDecision);

    string opcion = "";
    while (opcion != "4") {
        cout<<endl
        << "======= Hospital Marmaja ======="<<endl
        << "1. Atender pacientes" << endl
        << "2. Ver departamentos" << endl
        << "3. Buscar paciente" << endl
        << "4. Salir" << endl;

        cout << endl << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == "1") {
            cout<< "======= Atender Pacientes ======="<<endl;
            if (fila->empty()) {
                cout<<"No hay pacientes por atender.."<<endl;
                cout<<separador;
                continue;
            }
            Paciente* p = fila->front();
            fila->pop();
            print.datos(p);
            string ruta = "";
            string servicio = arbolDecision->decision(p,&ruta);
            system->registrarPacienteEnServicio(departamentos, p, servicio);
            cout<<endl<<"Ruta: "<<ruta<<endl<<endl
            <<"Servicio asignado: "<<servicio<<endl;

        } else if (opcion == "2") {
            cout << "=== ESTADO DE LOS DEPARTAMENTOS ===" << endl << endl;
            mostrarEstadoDepartamentos();
            cout << separador;

        } else if (opcion == "3") {
            cout << "=== BUSCAR PACIENTE ===" << endl;
            cout << "Indique el ID o Nombre del paciente: ";
            cin.ignore();
            string query;
            getline(cin, query);

            cout << "Buscando en AVL..." << endl;
            ResultadoBusqueda resultado = system->buscarPaciente(departamentos, query);
            mostrarResultadoBusqueda(resultado);
            cout << separador;
        }
    }
    delete arbolDecision;
    cout<<endl<<"Finalizando programa...";
}

App::~App() {
    if (datos != nullptr) {
        for (int i = 0; i < datos->getSize(); i++) {
            delete datos->get(i);
        }
    }
    delete datos;
    delete fila;
    for (int i = 0; i < NUM_DEPARTAMENTOS; i++) {
        delete departamentos[i].arbol;
           }
}
void App::mostrarResultadoBusqueda(const ResultadoBusqueda& resultado) {
    if (!resultado.encontrado) {
        cout << "Paciente no encontrado." << endl;
        return;
    }

    Paciente* p = resultado.paciente;
    PrintPaciente print;
    cout << "Paciente encontrado:" << endl;
    cout << "-------" << endl;
    print.datos(p);
    cout << "Departamento: " << resultado.departamento << endl;
    cout << "-------" << endl;
    cout << "Ruta de busqueda:" << endl;
    cout << resultado.ruta << endl;
}

void App::imprimirPacientesInline(NodoAVL<Paciente*>* nodo, bool& primero) {
    if (nodo != nullptr) {
        imprimirPacientesInline(nodo->getIzquierdo(), primero);

        if (!primero) cout << ", ";
        cout << nodo->getDato()->getNombre() << " (" << print.id(nodo->getDato()->getId()) << ")";
        primero = false;

        imprimirPacientesInline(nodo->getDerecho(), primero);
    }
}

void App::mostrarEstadoDepartamentos() {
    for (int i = 0; i < NUM_DEPARTAMENTOS; i++) {
        cout << departamentos[i].nombre << endl;
        if (departamentos[i].arbol->getRaiz() == nullptr) {
            cout << "Sin pacientes" << endl;
        } else {
            cout << "Pacientes: ";
            bool primero = true;
            imprimirPacientesInline(departamentos[i].arbol->getRaiz(), primero);
            cout << endl;
        }
        cout << endl;
    }
}

