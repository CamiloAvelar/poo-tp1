#include "Vagas.h"

Vagas::Vagas(int id, vector<string> skill, float horas, float remuneracao, string nome, int funcionarios, string rua, string bairro, int numero, string cidade) : empresa(rua, bairro, numero, cidade, nome, funcionarios), id(id), skill(skill), horas(horas), remuneracao(remuneracao) {};

Vagas::~Vagas() {}

void Vagas::setId(int id) {
  this -> id = id;
}

void Vagas::setSkill(vector<string> skill) {
  this->skill = skill;
}

void Vagas::setHoras(float horas) {
  this->horas = horas;
}

void Vagas::setRemuneracao(float remuneracao) {
  this->remuneracao = remuneracao;
}

Empresa Vagas::getEmpresa() {
  return empresa;
}

int Vagas::getId() {
  return id;
}

vector<string> Vagas::getSkill() {
  return skill;
}

float Vagas::getHoras() {
  return horas;
}

float Vagas::getRemuneracao() {
  return remuneracao;
}

string Vagas::getBairro() {
  return this->empresa.getBairro();
}

string Vagas::getNome() {
  return this->empresa.getNome();
}