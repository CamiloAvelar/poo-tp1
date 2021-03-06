#ifndef ENDERECO_H
#define ENDERECO_H

#include <string>

using namespace std;

class Endereco {
  string rua;
  string bairro;
  int numero;
  string cidade;
public:
  Endereco(string, string, int, string);
  ~Endereco();
  string getRua();
  string getBairro();
  int getNumero();
  string getCidade();
  void setRua(string);
  void setBairro(string);
  void setNumero(int);
  void setCidade(string);
};

#endif