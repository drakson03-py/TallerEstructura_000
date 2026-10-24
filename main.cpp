
/**
 * @file main.cpp
 * @brief Punto de entrada de la aplicacion de gestion de pacientes.
 *
 * Inicializa la implementacion del sistema, crea la aplicacion, ejecuta
 * su flujo principal y libera la memoria utilizada.
 */

#include "include/services/Services.h"
#include "include/app/App.h"

/**
 * @brief Inicia y ejecuta la aplicacion.
 *
 * Crea el sistema y la aplicacion, ejecuta el metodo principal de esta
 * y libera los objetos dinamicos antes de finalizar.
 *
 * @return 0 si la ejecucion finaliza correctamente.
 */
int main() {
    string archivo = "Pacientes.txt";

    System* system = new SystemImpl();
    App* app = new App(archivo, system);

    app->run();

    delete app;
    delete system;

    return 0;
}
