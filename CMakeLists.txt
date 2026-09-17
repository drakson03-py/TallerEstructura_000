cmake_minimum_required(VERSION 4.0.2)
project(TallerEstruct)
set(CMAKE_CXX_STANDARD 20)

add_executable(TallerEstruct main.cpp
        include/model/Paciente.h
        include/struct/List.h
        include/struct/Node.tpp
        include/struct/Queue.h
        include/struct/Queue.tpp
        include/struct/Stack.h
        include/struct/Stack.tpp
        include/struct/Struct.h
        src/model/Paciente.cpp
        src/services/HospitalMarmaja.cpp
        include/services/HospitalMarmaja.h
        include/services/System.h
        include/services/Services.h
)
target_compile_definitions(TallerEstruct PRIVATE
        DATA_DIR="${CMAKE_SOURCE_DIR}/data"
)
