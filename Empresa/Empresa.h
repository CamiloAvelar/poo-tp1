#ifndef EMPRESA_H
#define EMPRESA_H

#include "../Endereco/Endereco.h"

class Empresa {
  Endereco endereco;
  string nome;
  int funcionarios;
public:
  Empresa(string, string, int, string, string, int);
  ~Empresa();
  string getNome();
  int getFuncionarios();
  Endereco getEndereco();
  string getBairro();
  void setNome(string);
  void setFuncionarios(int);
};

#endif