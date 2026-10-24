## Integrantes

- Alan Galleguillos Castro / 21455933-1 / drakson03-py / ICCI
- Sebastián Miranda Maldonado / 21410044-4 / SebastianMirandaMaldonado / ICCI
- Paralelo C1

## 1. Requisitos

- CMake 4.0.2 o superior.
- Un compilador compatible con C++20.
- GitHub Codespaces.

## 2. Crear el Codespace

1. En GitHub, selecciona la rama `master`.
2. Pulsa `<> Code` → `Codespaces` → `Create codespace on master`.
3. Espera a que cargue VS Code.

## 3. Configurar el archivo de pacientes

Una vez creado el Codespace, puedes modificar los pacientes que procesará el programa.
El archivo se encuentra en la carpeta `data`. Por defecto, se utiliza `Pacientes.txt`, definido en `main.cpp` mediante la variable:
```cpp
string archivo = "Pacientes.txt";
```
Para modificar los pacientes o utilizar otro archivo:
1. Abre la carpeta `data` en el explorador de archivos de VS Code.
2. Abre `Pacientes.txt` para modificar los datos existentes, o crea un archivo nuevo mediante clic derecho → `New File`.
3. Si creas un archivo nuevo, asígnale un nombre, por ejemplo, `datos.txt`.
4. Si deseas utilizar el nuevo archivo, abre `main.cpp` y modifica la variable:
   ```cpp
   string archivo = "datos.txt";
   ```
5. Guarda los cambios con `Ctrl + S`.

**Importante:** el archivo debe estar dentro de `data` y respetar el formato esperado por el programa. Si el formato no es válido, el programa se detendrá sin procesar los datos.

### Campos del registro
| Campo | Tipo de dato | Descripción y restricciones |
|---|---|---|
| `ID` | `int` | Identificador único del paciente. Solo números enteros positivos. |
| `Edad` | `int` | Edad del paciente en años. Solo números enteros positivos. |
| `Temperatura` | `float` | Temperatura corporal. Número positivo con `.` como separador decimal. |
| `PresionArterial` | `string` | Presión arterial en formato `###.###`: presión sistólica antes del punto y presión diastólica después. |
| `Dolor` | `int` | Intensidad del dolor, en una escala de 0 a 10. |
| `TipoDolor` | `string` | Tipo de dolor: `pecho`, `cabeza`, `abdomen`, `extremidad` u `otro`. |
| `Trauma` | `bool` | `0` representa `false` (no existe) y `1` representa `true` (existe). |
| `SintomasNeurologicos` | `bool` | `0` representa `false` (no existen) y `1` representa `true` (existen). |
| `RequiereCirugia` | `bool` | `0` representa `false` (no requiere) y `1` representa `true` (requiere). |
| `DiasHospitalizacion` | `int` | Cantidad estimada de días de hospitalización. Solo números enteros positivos. |

**Reglas de formato**
- **Números enteros:** deben ingresarse sin decimales.
- **Números decimales:** deben utilizar el punto (`.`) como separador decimal.
- **Valores numéricos:** deben ser positivos.
- **Campos booleanos:** deben representarse exclusivamente con `0` o `1`.
- **Tipo de dolor:** debe coincidir con una de las opciones permitidas.
- **Presión arterial:** debe ingresarse los valores numericos en el formato `###.###`, respetando el punto como separador entre la presión sistólica y la diastólica.

## 4. Compilación y ejecución

Una vez creado el Codespace y configurado el archivo de pacientes, abre `Terminal` → `New Terminal` en VS Code.
1. Ejecutar:
   ```bash
   cmake --version
   ```
   Comprobar que la versión sea 4.0.2 o superior. Si no, ejecutar:
   ```bash
   python3 -m pip install --user cmake==4.0.2
   ```
   pip install --upgrade pip
   ```
3. Ejecutar:
   ```bash
   rm -rf build
   ```
   Eliminar los archivos de compilación anteriores.
4. Ejecutar:
   ```bash
   cmake -S . -B build
   ```
   Configurar el proyecto.
5. Ejecutar:
    ```bash
    cmake --build build -j2
    ```
    Compilar el proyecto.
6. Ejecutar:
    ```bash
    ./build/TallerEstruct
    ```
    Iniciar el programa desde la terminal.

## 5. Árbol de decisiones para la derivación de pacientes
### Manejo de datos inválidos o insuficientes

La clase `FilePaciente` valida el formato y la compatibilidad de los datos antes de permitir su procesamiento. Si una línea contiene campos vacíos obligatorios, tipos de datos incorrectos, valores fuera de las restricciones implementadas o identificadores duplicados, el archivo se rechaza y no se inicia el procesamiento de los pacientes.

Si el archivo no puede abrirse, también se impide su carga. Cuando los datos son válidos, pero no cumplen criterios específicos de derivación, el árbol de decisiones aplica las reglas correspondientes y utiliza Medicina General como servicio predeterminado cuando ninguna condición anterior determina otra derivación.

**Limitación:** actualmente, un archivo vacío se considera válido y algunos valores que podrían ser insuficientes o incoherentes se aceptan, ya que no todas las restricciones de rango están implementadas.

**Arbol de decision:**
```text
¿Dolor >= 8?
|-- Sí: Urgencias
|   // Un dolor muy intenso puede indicar un problema grave,
|   // por lo que se prioriza la atención de urgencia.
|
|-- No:
    ¿PresionSistolica >= 180?
    |-- Sí: Urgencias
    |   // Una presión sistólica muy elevada puede poner en riesgo
    |   // la salud del paciente y requiere atención prioritaria.
    |
    |-- No:
        ¿PresionDiastolica >= 120?
        |-- Sí: Urgencias
        |   // Una presión diastólica muy elevada también puede
        |   // representar un riesgo importante para el paciente.
        |
        |-- No:
            ¿Temperatura < 35?
            |-- Sí: Urgencias
            |   // Una temperatura inferior a 35 °C puede indicar
            |   // hipotermia, por lo que necesita atención prioritaria.
            |
            |-- No:
                ¿Temperatura > 40?
                |-- Sí: Urgencias
                |   // Una temperatura superior a 40 °C puede ser
                |   // peligrosa y requiere atención prioritaria.
                |
                |-- No:
                    ¿Edad < 18?
                    |-- Sí: Pediatría
                    |   // Los menores de 18 años se derivan a Pediatría,
                    |   // donde reciben atención adecuada a su edad.
                    |
                    |-- No:
                        ¿RequiereCirugia == true?
                        |-- Sí: Cirugía
                        |   // Si el paciente necesita una intervención
                        |   // quirúrgica, se deriva a Cirugía antes de
                        |   // evaluar los demás servicios especializados.
                        |
                        |-- No:
                            ¿TipoDolor == "pecho"?
                            |-- Sí: Cardiología
                            |   // El dolor de pecho puede estar relacionado
                            |   // con problemas cardíacos.
                            |
                            |-- No:
                                ¿TipoDolor == "cabeza"?
                                |-- Sí:
                                |   ¿SintomasNeurologicos == true?
                                |   |-- Sí: Neurología
                                |   |   // El dolor de cabeza acompañado de
                                |   |   // síntomas neurológicos se deriva
                                |   |   // a Neurología.
                                |   |
                                |   |-- No:
                                |       ¿DiasHospitalizacion >= 2?
                                |       |-- Sí: Hospitalización
                                |       |   // Se deriva a Hospitalización
                                |       |   // si se prevé una estadía de
                                |       |   // dos días o más.
                                |       |
                                |       |-- No: Medicina General
                                |           // Servicio predeterminado cuando
                                |           // no se cumplen otros criterios.
                                |
                                |-- No:
                                    ¿TipoDolor == "extremidad"?
                                    |-- Sí:
                                    |   ¿Trauma == true?
                                    |   |-- Sí: Traumatología
                                    |   |   // El dolor en una extremidad
                                    |   |   // relacionado con un golpe o
                                    |   |   // accidente se deriva a
                                    |   |   // Traumatología.
                                    |   |
                                    |   |-- No:
                                    |       ¿DiasHospitalizacion >= 2?
                                    |       |-- Sí: Hospitalización
                                    |       |   // Se deriva si se prevé una
                                    |       |   // estadía de dos días o más.
                                    |       |
                                    |       |-- No: Medicina General
                                    |           // Servicio predeterminado
                                    |           // cuando no se cumplen
                                    |           // otros criterios.
                                    |
                                    |-- No:
                                        ¿DiasHospitalizacion >= 2?
                                        |-- Sí: Hospitalización
                                        |   // Si no se cumplen los criterios
                                        |   // anteriores y se prevé una
                                        |   // estadía de dos días o más.
                                        |
                                        |-- No: Medicina General
                                            // Servicio por defecto cuando
                                            // no se cumplen los criterios
                                            // de las demás derivaciones.
```
