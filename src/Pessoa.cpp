#include "../include/Pessoa.h"

Pessoa::Pessoa(string rua, string bairro, int numero, string cidade, string nome, int idade) : endereco(rua, bairro, numero, cidade), nome(nome), idade(idade) {}

Pessoa::~Pessoa() {}

void Pessoa::setNome(string nome) {
  this->nome = nome;
}

void Pessoa::setIdade(int idade) {
  this->idade = idade;
}

Endereco Pessoa::getEndereco() {
  return endereco;
}

string Pessoa::getRua() {
  return this->endereco.getRua();
} // TODO : getters de outras classes

string Pessoa::getBairro() {
  return this->endereco.getBairro();
}

string Pessoa::getNome() {
  return nome;
}

int Pessoa::getIdade() {
  return idade;
}

void Pessoa::setEndereco(string rua, string bairro, int numero, string cidade) {
  this->endereco.setRua(rua);
  this->endereco.setBairro(bairro);
  this->endereco.setNumero(numero);
  this->endereco.setCidade(cidade);
}