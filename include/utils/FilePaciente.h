
//
// Created by seba2 on 19-10-2026.
//

#ifndef TALLERESTRUCT_FILEREADER_H
#define TALLERESTRUCT_FILEREADER_H

#include "../model/Paciente.h"
#include "../struct/List.h"

/**
 * @brief Lee y valida registros de pacientes desde un archivo.
 *
 * Permite verificar la estructura de las lineas, validar los atributos
 * de los pacientes y cargar los registros validos en una lista.
 * Tambien mantiene un registro de los identificadores para detectar
 * pacientes repetidos.
 */
class FilePaciente {
private:
    List<int>* ids;
    string file;
    bool archivoValido;

    /**
     * @brief Comprueba si un identificador ya fue registrado.
     *
     * @param id Identificador del paciente que se desea comprobar.
     * @return true si el identificador esta repetido; false en caso contrario.
     */
    bool isPacienteRepetido(int id);

    /**
     * @brief Valida la estructura y el contenido de una linea del archivo.
     *
     * @param ss Flujo de texto que contiene la linea que se desea validar.
     * @return true si la linea cumple las validaciones; false en caso contrario.
     */
    bool isLineaValida(stringstream& ss);

    /**
     * @brief Comprueba si la intensidad del dolor es valida.
     *
     * @param dolor Texto que representa la intensidad del dolor.
     * @return true si el valor cumple las restricciones (0 a 10);
     * false en caso contrario.
     */
    bool isDolorValido(string dolor);

    /**
     * @brief Comprueba si una cadena representa un numero positivo.
     *
     * @param num Cadena que contiene el valor que se desea validar.
     * @return true si representa un numero positivo (incluye el 0); false en caso contrario.
     */
    bool isNumeroPositivo(string num);

    /**
     * @brief Comprueba si una cadena representa un numero entero.
     *
     * @param num Cadena que contiene el valor que se desea validar.
     * @return true si representa un numero entero (incluye el 0); false en caso contrario.
     */
    bool isNumeroEntero(string num);

    /**
     * @brief Comprueba si un atributo esta vacio.
     *
     * @param atributo Cadena que se desea comprobar.
     * @return true si el atributo esta vacio; false en caso contrario.
     */
    bool isAtributoVacio(string atributo);

    /**
     * @brief Comprueba si una cadena representa un valor booleano valido.
     *
     * @param b Cadena que contiene el valor booleano.
     * @return true si el valor es valido; false en caso contrario.
     */
    bool isBool(string b);

    /**
     * @brief Comprueba si el tipo de dolor pertenece a los permitidos.
     *
     * @param dolor Cadena que representa el tipo de dolor.
     * @return true si el tipo de dolor esta permitido; false en caso contrario.
     */
    bool isTipoDolorValido(string dolor);

    /**
     * @brief Comprueba si una presion arterial tiene un formato valido.
     *
     * @param presion Cadena con la presion arterial.
     * @return true si la presion cumple el formato requerido;
     * false en caso contrario.
     */
    bool isPresionValida(string presion);

public:
    /**
     * @brief Construye un lector para el archivo especificado.
     *
     * @param archivo Ruta o nombre del archivo que contiene los registros.
     */
    FilePaciente(const string& archivo);

    /**
     * @brief Lee y valida el archivo de pacientes.
     *
     * Reinicia la lista de identificadores, abre el archivo indicado y valida
     * cada registro. Durante la lectura, comprueba que las lineas sean validas
     * y que no existan identificadores repetidos.
     *
     * @return Codigo del resultado de la operacion:
     *         - 0: El archivo se leyo correctamente y todos sus registros son validos.
     *         - 1: No se pudo abrir el archivo.
     *         - 2: Se encontro una linea con formato o datos invalidos.
     *         - 3: Se encontro un identificador de paciente repetido.
     */
    int leerArchivo();

    /**
     * @brief Carga los pacientes del archivo en una lista.
     *
     * Comprueba que el archivo haya sido validado previamente y que la lista
     * de destino no sea nula. Luego abre el archivo, lee los datos de cada
     * paciente, crea sus objetos y los inserta en la lista.
     *
     * @param datos Lista donde se almacenaran los pacientes leidos.
     *
     * @return true si todos los registros se cargan correctamente en la lista;
     *         false si el archivo no fue validado previamente, la lista es nula
     *         o no se puede abrir el archivo.
     */
    bool cargarArchivo(List<Paciente*>* datos);

    /**
     * @brief Libera los recursos administrados por el lector de archivos.
     */
    ~FilePaciente();
};

#endif // TALLERESTRUCT_FILEREADER_H
