#ifndef POPULATE_H
#define POPULATE_H

#include "Vagas.h"
#include "Desempregado.h"
#include "Util.h"
#include <fstream>
#include <cstring>

class Populate {
  static Populate* instance;
  vector<Vagas*> vagas;
  vector<Desempregado*> desempregados;
  Populate();
public:
  ~Populate();
  static Populate* getInstance();
  vector<Vagas*> getVagas();
  vector<Desempregado*> getDesempregados();
  void populate(const string &, const uint &, const uint &, const string &);
  void populateVagas();
  void populateDesempregados();
  void addVaga(Vagas* &);
  void addDesempregado(Desempregado* &);

  Populate(const Populate&) = delete;
  Populate& operator=(const Populate&) = delete;
};

#endif