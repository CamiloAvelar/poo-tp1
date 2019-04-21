#ifndef VAGAS_H
#define VAGAS_H

#include "Empresa.h"
#include <vector>

class Vagas {
  Empresa empresa;
  int id;
  vector<string> skill;
  float horas, remuneracao;
public:
  Vagas(int, vector<string>, float, float, string, int, string, string, int, string);
  ~Vagas();
  void setId(int);
  void setSkill(vector<string>);
  void setHoras(float);
  void setRemuneracao(float);
  Empresa getEmpresa();
  int getId();
  vector<string> getSkill();
  float getHoras();
  float getRemuneracao();
  string getBairro();
  string getNome();
};

#endif