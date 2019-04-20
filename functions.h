#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

#include "Pessoa/Desempregado/Desempregado.h"
#include "Vagas/Vagas.h"

using namespace std;

const string toLowerCase(const string&);
const vector<string> explode(const string& s, const char& c);
void populate(vector<Vagas*> &, vector<Desempregado*> &);

vector<Vagas*> operation1(const vector<Vagas*> &, const vector<Desempregado*> &);
vector<Vagas*> operation2(const vector<Vagas*> &, const vector<Desempregado*> &);
vector<Vagas*> operation3(const vector<Vagas*> &, const vector<Desempregado*> &);
vector<Desempregado*> operation4(const vector<Vagas*> &, const vector<Desempregado*> &);
vector<Desempregado*> operation5(const vector<Vagas*> &, const vector<Desempregado*> &);
void operation6(const vector<Vagas*> &, const vector<Desempregado*> &);
vector<Vagas*> operation7(const vector<Vagas*> &, const vector<Desempregado*> &);

void addDesempregado(vector<Desempregado*> &);
void addVaga(vector<Vagas*> &);

#endif