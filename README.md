Alan Galleguillos Castro / 21455933-1 / drakson03-py / ICCI
Sebastián Miranda / 21410044-4 / SebastianMirandaMaldonado / ICCI

## Instrucciones de ejecución

1. Configuración del archivo de pacientes

El archivo de pacientes se encuentra en la carpeta data. Por defecto, el programa utiliza Pacientes.txt, definido en main.cpp mediante la variable:

string archivo = "Pacientes.txt";

Para utilizar otro archivo, sigue estos pasos en GitHub Codespaces:

En el explorador de archivos de VS Code, abre la carpeta data.

Abre Pacientes.txt para modificar los pacientes existentes, o crea un archivo nuevo mediante clic derecho → New File.

Si creas un archivo nuevo, asígnale un nombre, por ejemplo, datos.txt.

Si utilizas otro archivo, abre main.cpp y cambia el nombre en la variable correspondiente:

string archivo = "datos.txt";

Guarda los cambios con Ctrl + S.

El archivo debe estar dentro de data y respetar el formato de datos esperado por el programa.

### 2. Requisitos

- CMake 4.0.2 o superior.
- Un compilador compatible con C++20.
- GitHub Codespaces para seguir el procedimiento de ejecución indicado.

### 3. Compilación y ejecución

1. En GitHub, selecciona la rama `master` y crea un Codespace mediante `<> Code` → `Codespaces` → `Create codespace on master`.
2. Abre una terminal en VS Code.
3. Ejecutar:
   ```bash
   cmake --version
   ```
   Comprobar que la versión sea 4.0.2 o superior. Si no, ejecutar:
   ```bash
   python3 -m pip install --user cmake==4.0.2
   ```
4. Ejecutar:
   ```bash
   rm -rf build
   ```
   Eliminar los archivos de compilación anteriores.
5. Ejecutar:
   ```bash
   cmake -S . -B build
   ```
   Configurar el proyecto.
6. Ejecutar:
    ```bash
    cmake --build build -j2
    ```
    Compilar el proyecto.
7. Ejecutar:
    ```bash
    ./build/TallerEstruct
    ```
    Iniciar el programa desde la terminal.
