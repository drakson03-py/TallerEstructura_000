cmake_minimum_required(VERSION 4.0.2)
project(TallerEstruct)
set(CMAKE_CXX_STANDARD 20)

add_executable(TallerEstruct main.cpp
        include/struct/List.h
        include/struct/Node.tpp
        include/struct/Queue.h
        include/struct/Queue.tpp
        include/struct/Stack.h
        include/struct/Stack.tpp
        src/model/Paciente.cpp
        include/model/Paciente.h
        include/services/System.h
        src/services/SystemImpl.cpp
        include/services/SystemImpl.h
        src/app/App.cpp
        include/app/App.h
        src/utils/FilePaciente.cpp
        include/utils/FilePaciente.h
        src/utils/PrintPaciente.cpp
        include/utils/PrintPaciente.h
        include/struct/NodeAVL.h
        include/struct/NodeAVL.tpp
        include/struct/BTNode.h
        include/struct/BTNode.tpp
        src/model/ArbolDecision.cpp
        include/model/ArbolDecision.h
        include/struct/ArbolAVL.h
        include/struct/ArbolAVL.tpp
        include/model/DepartamentoaAVL.h
        include/model/ResultadoBusqueda.h
        include/model/DepartamentoaAVL.h
)

#Se crea una variable que guarda la ruta relativa de la carpeta data
target_compile_definitions(TallerEstruct PRIVATE
        DATA_DIR="${CMAKE_SOURCE_DIR}/data"
)
