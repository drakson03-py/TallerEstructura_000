#include "include/services/Services.h"
#include <iostream>


using namespace std;
int main() {

    string archivo = "Pacientes.txt";

    System* hospital = new HospitalMarmaja(archivo);
    hospital->cargaDePacientes();
    while (true) {
        cout<<endl
        << "======= Hospital Marmaja ======="<<endl
        << "1. Atender pacientes" << endl
        << "2. Ver departamentos" << endl
        << "3. Revisar historial de atencion" << endl
        << "4. Salir" << endl;

        string opcion = "";
        cout << endl << "Seleccione una opcion: ";
        cin >> opcion;


        if (opcion == "1") {
            hospital -> atenderPacientes();

        }else if (opcion == "2") {
            hospital -> verDepartamento();


        }else if (opcion == "3") {
            hospital ->revisarHistorialDeAtencion();

        }else if (opcion == "4") {
            hospital -> finalizar();
            delete hospital;
            break;

        }else {
            cout << endl<< "ERROR: Seleccione una opcion valida" << endl;
        }
    }
    return 0;
}