#ifndef POPULATE_H
#define POPULATE_H

#include "../Vagas/Vagas.h"
#include "../Pessoa/Desempregado/Desempregado.h"
#include "../Util/Util.h"
#include <fstream>


class Populate {
  vector<Vagas*> vagas;
  vector<Desempregado*> desempregados;
public:
  Populate();
  vector<Vagas*> getVagas();
  vector<Desempregado*> getDesempregados();
  void populate(string, uint, uint, string);
  void populateVagas();
  void populateDesempregados();
  void addVaga(Vagas* &);
  void addDesempregado(Desempregado* &);
};

#endif