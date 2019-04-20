#ifndef PESSOA_H
#define PESSOA_H

#include "Endereco.h"
#include <string>

class Pessoa {
  Endereco endereco;
  string nome;
  int idade;
public:
  Pessoa(string, string, int, string, string, int);
  ~Pessoa();
  void setNome(string);
  void setIdade(int);
  void setEndereco(string, string, int, string);
  Endereco getEndereco();
  string getNome();
  int getIdade();
  string getRua();
  string getBairro();
};

#endif