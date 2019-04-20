#include "Empresa.h"

Empresa::Empresa(string rua, string bairro, int numero, string cidade, string nome, int funcionarios) : endereco(rua, bairro, numero, cidade), nome(nome), funcionarios(funcionarios) {};

Empresa::~Empresa() {};

string Empresa::getNome() {
  return nome;
}

int Empresa::getFuncionarios() {
  return funcionarios;
}

void Empresa::setNome(string nome) {
  this->nome = nome;
}

void Empresa::setFuncionarios(int funcionarios) {
  this->funcionarios = funcionarios;
}

Endereco Empresa::getEndereco() {
  return endereco;
}

string Empresa::getBairro() {
  return this->endereco.getBairro();
}