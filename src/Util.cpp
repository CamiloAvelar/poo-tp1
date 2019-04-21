#include "../include/Util.h"


const string Util::toLowerCase(const string& str) {
  string newString;
  newString.resize(str.size());
 
  transform(str.begin(), str.end(), newString.begin(), ::tolower);

  return newString;
}

const vector<string> Util::explode(const string& testString, const char& explodeChar) {
    string buff{""};
    vector<string> stringVector;

    for (auto character : testString) {
        if (character != explodeChar) {
          buff+=character;
        } else if (character == explodeChar && buff != "") {
          stringVector.push_back(buff);
          buff = "";
        }
    }
    if(buff != "") stringVector.push_back(buff);

    return stringVector;
}

const int Util::waitForAction(const int key) {
  cout << "aperte enter para continuar" << endl;
  if (key == 8 || key == 4 || key == 5) {
    cin.ignore();
  }
  cin.get();
  return -1;
}

const int Util::displayAction() {
  cout << "--------------------------------------" << endl;
  cout << "Digite 0 para sair do programa." << endl;
  cout << "Digite 1 para dado o nome de um desempregado, exibir todas as vagas localizadas no mesmo bairro do desempregado" << endl;
  cout << "Digite 2 para dado o nome de um desempregado, exibir todas as vagas em que o desempregado supri os requisitos de skill." << endl;
  cout << "Digite 3 para dado um skill, exibir todas as vagas que requer o dado skill" << endl;
  cout << "Digite 4 para dado o id de uma vaga, exibir todos os desempregados que moram no mesmo bairro," << endl;
  cout << "Digite 5 para dado o id de uma vaga, exibir todos os desempregados que possuem os skills requeridos pela vaga." << endl;
  cout << "Digite 6 para dado um skill, exibir todas as vagas e os desempregados que possuem o dado skill." << endl;
  cout << "Digite 7 para dado o nome de uma empresa, exibir todas as vagas referentes a empresa" << endl;
  cout << "Digite 8 para atribuir vagas à Desempregados" << endl;
  cout << "Digite 9 para adicionar um Desempregado" << endl;
  cout << "Digite 10 para adicionar uma Vaga" << endl;
  cout << "--------------------------------------" << endl;
  cout << "(digite o numero): ";

  return getAction();
}

const int Util::getAction() {
  int option = 0;

  cin >> option;

  return option;
}