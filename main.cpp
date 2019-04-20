#include <iostream>

#include "functions/functions.h"
#define OFF 0

using namespace std;

int main() {

  vector<Vagas*> vagas (500);
  vector<Desempregado*> desempregados (1000);
  populate(vagas, desempregados);

  int option = -1;

  while (option != OFF) {

    switch(option) {
      case 1:
        operation1(vagas, desempregados);
        option = -1;
        break;
      case 2:
        operation2(vagas, desempregados);
        option = -1;
        break;
      case 3:
        operation3(vagas, desempregados);
        option = -1;
        break;
      case 4:
        operation4(vagas, desempregados);
        option = -1;
        break;
      case 5:
        operation5(vagas, desempregados);
        option = -1;
        break;
      case 6:
        operation6(vagas, desempregados);
        option = -1;
        break;
      case 7:
        operation7(vagas, desempregados);
        option = -1;
        break;
      case 8:
        addDesempregado(desempregados);
        option = -1;
        break;
      case 9:
        addVaga(vagas);
        option = -1;
        break;
      default:
        cout << "--------------------------------------" << endl;
        cout << "Digite 0 para sair do programa." << endl;
        cout << "Digite 1 para dado o nome de um desempregado, exibir todas as vagas localizadas no mesmo bairro do desempregado" << endl;
        cout << "Digite 2 para dado o nome de um desempregado, exibir todas as vagas em que o desempregado supri os requisitos de skill." << endl;
        cout << "Digite 3 para dado um skill, exibir todas as vagas que requer o dado skill" << endl;
        cout << "Digite 4 para dado o id de uma vaga, exibir todos os desempregados que moram no mesmo bairro," << endl;
        cout << "Digite 5 para dado o id de uma vaga, exibir todos os desempregados que possuem os skills requeridos pela vaga." << endl;
        cout << "Digite 6 para dado um skill, exibir todas as vagas e os desempregados que possuem o dado skill." << endl;
        cout << "Digite 7 para dado o nome de uma empresa, exibir todas as vagas referentes a empresa" << endl;
        cout << "Digite 8 para adicionar um Desempregado" << endl;
        cout << "Digite 9 para adicionar uma Vaga" << endl;
        cout << "--------------------------------------" << endl;
        cout << "(digite o numero): ";
        cin >> option;
        break;
    }
  }

  return 0;
}