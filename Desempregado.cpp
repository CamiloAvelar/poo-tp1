#include "Desempregado.h"

Desempregado::Desempregado(string nome, int idade, vector<string> skill, int tempo, string rua, string bairro, int numero, string cidade): Pessoa(rua, bairro, numero, cidade, nome, idade) {
  setTempo(tempo);
  setSkill(skill);
}

Desempregado::~Desempregado(){};

void Desempregado::setTempo(int tempo) {
  this->tempo = tempo;
}

void Desempregado::setSkill(vector<string> skill) {
  this->skill = skill;
}

int Desempregado::getTempo() {
  return tempo;
}

vector<string> Desempregado::getSkill() {
  return skill;
}