#ifndef POPULATE_H
#define POPULATE_H

#include "Vagas.h"
#include "Desempregado.h"
#include "Util.h"
#include <fstream>
#include <cstring>

class Populate {
  vector<Vagas*> vagas;
  vector<Desempregado*> desempregados;
public:
  Populate();
  vector<Vagas*> getVagas();
  vector<Desempregado*> getDesempregados();
  void populate(const string &, const uint &, const uint &, const string &);
  void populateVagas();
  void populateDesempregados();
  void addVaga(Vagas* &);
  void addDesempregado(Desempregado* &);
};

#endif