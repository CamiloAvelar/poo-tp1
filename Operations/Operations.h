#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "../Vagas/Vagas.h"
#include "../Pessoa/Desempregado/Desempregado.h"
#include "../Populate/Populate.h"
#include <iomanip>
#include <algorithm>

class Operations {
  Populate populate;
public:
  Operations();
  const vector<Vagas*> operation1();
  const vector<Vagas*> operation3();
  const vector<Vagas*> operation2();
  const vector<Desempregado*> operation4();
  const vector<Desempregado*> operation5();
  const void operation6();
  const vector<Vagas*> operation7();
  const void createVaga();
  const void createDesempregado();
  const void operation8();
  const string toLowerCase(const string&);
};

#endif