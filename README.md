Alan Galleguillos Castro / 21455933-1 / drakson03-py / ICCI
Sebastián Miranda / 21410044-4 / SebastianMirandaMaldonado / ICCI

Instrucciones de ejecución
- El archivo utilizado para cargar los pacientes está en main.cpp, se usa la variable:
string archivo = "Pacientes.txt";
- Para utilizar otro archivo se debe modificar el nombre del archivo, ejemplo:
string archivo = "datos.txt";
- El archivo debe encontrarse dentro de los datos de la alfombra

Aclaraciones
- Se requiere CMake 4.0.2 o superior
- Se requiere un compilador compatible con C++20

Otro
- cd /workspaces/TallerEstructura_000
- python3 -m pip install --user cmake==4.0.2
- rm -rf build
- cmake -S . -B build
- cmake --build build -j2
- ./build/TallerEstruct

# Ejecución de TallerEstructura_000 en GitHub Codespaces

1. Entrar al repositorio [https://github.com/drakson03-py/TallerEstructura_000](https://github.com/drakson03-py/TallerEstructura_000).
2. Seleccionar la rama `master`.
3. Pulsar `<> Code` → `Codespaces` → `Create codespace on master`.
4. Esperar a que cargue VS Code.
5. Abrir `Terminal` → `New Terminal`.
6. Ejecutar:
   ```
   pwd
   ```
   Comprobar que la ruta sea `/workspaces/TallerEstructura_000`. Si no, ejecutar:
   ```
   cd /workspaces/TallerEstructura_000
   ```
7. Ejecutar:
   ```
   cmake --version
   ```
   Comprobar que la versión sea 4.0.2 o superior. Si no, ejecutar:
   ```
   python3 -m pip install --user cmake==4.0.2
   ```
   Si aparece un error por restricciones de Python, configurar un entorno virtual para instalar CMake y comprobar nuevamente la versión.
8. Ejecutar:
   ```
   ls
   ```
   Comprobar que existan `CMakeLists.txt`, `README.md`, `data`, `include`, `main.cpp` y `src`. Si falta alguno, comprobar la ruta actual y que se haya seleccionado el repositorio y la rama correctos.
9. Ejecutar:
   ```
   rm -rf build
   ```
   Eliminar los archivos de compilación anteriores.
10. Ejecutar:
    ```
    cmake -S . -B build
    ```
    Configurar el proyecto.
11. Ejecutar:
    ```
    cmake --build build -j2
    ```
    Compilar el proyecto.
12. Ejecutar:
    ```
    ./build/TallerEstruct
    ```
    Iniciar el programa desde la terminal.
