//
// Created by seba2 on 19-10-2026.
//

#include "../../include/app/App.h"
#include "../../include/utils/Utils.h"
#include "../../include/struct/BTNode.h"
#include "../../include/model/ArbolDecision.h"

App::App(const string& archivo, System* system)
    : archivo(archivo),
      system(system),
      datos(nullptr),
      fila(nullptr) {
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
    ArbolDecision* arbolDecision = system->buildArbolDecision();

    PrintPaciente print;

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
            Paciente* p = fila->front();fila->pop();
            print.datos(p);
            string ruta = "";
            string servicio = arbolDecision->decision(p,&ruta);
            cout<<endl<<"Ruta: "<<ruta<<endl<<endl
            <<"Servicio asignado: "<<servicio<<endl;




        }else if (opcion == "2") {

        }else if (opcion == "3") {

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
}
