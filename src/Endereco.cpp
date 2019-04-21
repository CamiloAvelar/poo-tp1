#include "../include/Endereco.h"

Endereco::Endereco(string rua, string bairro, int numero, string cidade) : rua(rua), bairro(bairro), numero(numero), cidade(cidade) {};

Endereco::~Endereco() {};

string Endereco::getRua() {
  return this->rua;
};

string Endereco::getBairro() {
  return this->bairro;
};

int Endereco::getNumero() {
  return this->numero;
};

string Endereco::getCidade() {
  return this->cidade;
};

void Endereco::setRua(string rua) {
  this->rua = rua;
};

void Endereco::setBairro(string bairro) {
  this->bairro = bairro;
};

void Endereco::setNumero(int numero) {
  this->numero = numero;
};

void Endereco::setCidade(string cidade) {
  this->cidade = cidade;
};