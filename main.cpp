#include "include/services/Services.h"
#include <iostream>


using namespace std;

#include "include/services/Services.h"
#include "include/app/App.h"
#include "include/utils/FilePaciente.h"
#include "include/struct/ArbolAVL.h"

int main(){

    string archivo = "Test.txt";
    System* system = new SystemImpl();
    App* app = new App(archivo, system);
    app->run();
    delete app;
    delete system;
    return 0;

    /**ArbolAVL<int>* nodo = new ArbolAVL<int>();
    nodo->insertar(10);
    nodo->insertar(20);
    nodo->insertar(30);
    nodo->insertar(40);
    nodo->insertar(50);
    nodo->insertar(25);
    nodo->mostrarInOrden();
    /**/
};