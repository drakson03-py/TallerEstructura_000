//
// Created by seba2 on 19-10-2026.
//

#include "../../include/app/App.h"
#include "../../include/utils/PrintPaciente.h"

App::App(List<Paciente*>* datos,System* system):datos(datos), system(system) {
    fila = new Queue<Paciente*>();

}

void App::run() {
    system->cargarFila(datos,fila);
    PrintPaciente* print;
    string separador = "--------------------------------------------";

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
            Queue<Paciente*>* copy(this->fila);
            while (!copy->empty()) {
                print->datos(copy->front());
                cout<<separador<<endl;
                copy->pop();
            }


        }else if (opcion == "2") {


        }else if (opcion == "3") {


        }
    }
    cout<<endl<<"Finalizando programa...";
}

App::~App() {
    delete fila;
}
