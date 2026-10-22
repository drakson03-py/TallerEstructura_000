#include "include/services/Services.h"
#include <iostream>


using namespace std;

#include "include/services/Services.h"
#include "include/app/App.h"
#include "include/utils/FilePaciente.h"

int main(){
    string archivo = "Test.txt";
    System* system = new SystemImpl();
    App* app = new App(archivo, system);
    app->run();
    delete app;
    delete system;
    return 0;
};