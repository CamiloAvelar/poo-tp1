cmake_minimum_required(VERSION 3.0)

project(main)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(main)

include_directories( 
  Empresa
  Endereco
  functions
  Pessoa
  Vagas
 )

add_executable(
  main
  Empresa/Empresa.cpp
  Endereco/Endereco.cpp
  functions/functions.cpp
  Pessoa/Pessoa.cpp
  Pessoa/Desempregado/Desempregado.cpp
  Vagas/Vagas.cpp
  main.cpp
)