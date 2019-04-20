#ifndef DESEMPREGADO_H
#define DESEMPREGADO_H

#include <vector>
#include <string>
#include "Pessoa.h"

class Desempregado
  :public Pessoa {
    int tempo;
    vector<string> skill;
  public:
    Desempregado(string, int, vector<string>, int, string = "", string = "", int = 0, string = "");
    ~Desempregado();
    void setTempo(int);
    void setSkill(vector<string>);
    int getTempo();
    vector<string> getSkill();
  };

#endif