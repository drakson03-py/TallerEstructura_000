#include "include/services/Services.h"
#include <iostream>


using namespace std;
/**
 * Crea una instancia del Hospital Marmaja, carga los pacientes
 * y muestra un menú para acceder a las distintas funciones del sistema
 *
 * @return 0 si el programa finaliza correctamente, 1 en caso contrario
 */
int main() {

    string archivo = "Pacientes.txt";

    System* hospital = new HospitalMarmaja(archivo);

    bool valido = hospital->cargaDePacientes();

    while (valido) {
        cout<<endl
        << "======= Hospital Marmaja ======="<<endl
        << "0. Buscar paciente" << endl
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
            cout<<endl<<"Finalizando programa...";
            break;

        }
        else if (opcion == "0"){
            hospital -> buscarPaciente();
        }
        else {
            cout << endl<< "ERROR: Seleccione una opcion valida" << endl;
        }
    }
    delete hospital;
    return (valido ? 0:1);
}