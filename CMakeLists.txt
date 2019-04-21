cmake_minimum_required(VERSION 3.0)

project(main)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(main)

include_directories( 
  include
  entradas
 )

set( MY_CPP_FILES 
  src/Empresa.cpp
  src/Endereco.cpp
  src/Pessoa.cpp
  src/Desempregado.cpp
  src/Vagas.cpp
  src/Operations.cpp
  src/Util.cpp
  src/Populate.cpp
  src/main.cpp
)

set(EXECUTABLE_OUTPUT_PATH "bin")

add_executable( main ${MY_CPP_FILES})