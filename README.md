## Integrantes

- Alan Galleguillos Castro / 21455933-1 / drakson03-py / ICCI
- Sebastián Miranda Maldonado / 21410044-4 / SebastianMirandaMaldonado / ICCI

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


### 3. Compilación y ejecución

Una vez creado el Codespace y configurado el archivo de pacientes, abre `Terminal` → `New Terminal` en VS Code.
1. Ejecutar:
   ```bash
   cmake --version
   ```
   Comprobar que la versión sea 4.0.2 o superior. Si no, ejecutar:
   ```bash
   python3 -m pip install --user cmake==4.0.2
   ```
2. Ejecutar:
   ```bash
   rm -rf build
   ```
   Eliminar los archivos de compilación anteriores.
3. Ejecutar:
   ```bash
   cmake -S . -B build
   ```
   Configurar el proyecto.
4. Ejecutar:
    ```bash
    cmake --build build -j2
    ```
    Compilar el proyecto.
5. Ejecutar:
    ```bash
    ./build/TallerEstruct
    ```
    Iniciar el programa desde la terminal.
