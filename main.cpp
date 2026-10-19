#include "include/services/Services.h"
#include <iostream>


using namespace std;

#include "include/services/Services.h"
#include "include/app/App.h"
#include "include/utils/FilePaciente.h"

int main(){
    string archivo = "Pacientes.txt";

    FilePaciente* file = new FilePaciente(archivo);
    int carga = file->cargarDatos();
    if (carga != 0) {
        if (carga == 1) {
            cout<<"ERROR: Archivo no encontrado"<<endl;
        }else if (carga == 2) {
            cout<<"ERROR: Archivo no valido -> Linea del archivo no valida"<<endl;
        }else if (carga == 3) {
            cout<<"ERROR: Archivo no valido -> Paciente repetido"<<endl;
        }
        return 1;
    }

    System* system = new SystemImpl();
    App* app = new App(file->getDatos(), system);
    app->run();

    delete app;
    delete file;
    delete system;

    return 0;
};