#include "functions.h"

const string toLowerCase(const string& str) {
  string newString;
  newString.resize(str.size());
 
  transform(str.begin(), str.end(), newString.begin(), ::tolower);

  return newString;
}

const vector<string> explode(const string& testString, const char& explodeChar) {
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

void populate(vector<Vagas*> &vagas, vector<Desempregado*> &desempregados) {

  // LE E POPULA DESEMPREGADOS
  ifstream inputDesempregado("entradas/entradaDes.txt");
  int auxCountDes = 0;
  int qtdParamsDes = 4;
  int skillsLocationDes = 3;
  vector<string> paramsDes (qtdParamsDes);
  vector<string> skillsDes;
  int lines = 0;

  for( string line; getline(inputDesempregado, line); ) {

    if( auxCountDes < qtdParamsDes) {
      if (auxCountDes == skillsLocationDes - 1) {
        skillsDes = explode(line, ' ');
      } else {
        paramsDes[auxCountDes] = line;
      }

      if ( auxCountDes == qtdParamsDes - 1 ) {
        for ( int i = 0; i < paramsDes.size(); i++ ) {
          if( i == qtdParamsDes - 1 ) {
            desempregados[lines] = new Desempregado(paramsDes[0], stoi(paramsDes[1]), skillsDes, stoi(paramsDes[3])); 
            lines++;
          }
        }

        auxCountDes = 0;
      } else {
        auxCountDes++;
      }
    }
  }
  // END DESEMPREGADOS
  
  // LE E POPULA VAGAS
  ifstream inputVagas("entradas/entradaVagas.txt");
  int auxCountVagas = 0;
  int qtdParamsVagas = 10;
  int skillsLocationVagas = 2;
  vector<string> paramsVagas (qtdParamsVagas);
  vector<string> skillsVagas;

  for( string line; getline(inputVagas, line); ) {

    if( auxCountVagas < qtdParamsVagas) {
      if (auxCountVagas == skillsLocationVagas - 1) {
        skillsVagas = explode(line, ' ');
      } else {
        paramsVagas[auxCountVagas] = line;
      }

      if ( auxCountVagas == qtdParamsVagas - 1 ) {
        for ( int i = 0; i < paramsVagas.size(); i++ ) {
          if( i == qtdParamsVagas - 1 ) {
            vagas[stoi(paramsVagas[0]) - 1] = new Vagas(stoi(paramsVagas[0]), skillsVagas, stof(paramsVagas[2]),stof(paramsVagas[3]), paramsVagas[4], stoi(paramsVagas[5]), paramsVagas[6], paramsVagas[7], stoi(paramsVagas[8]), paramsVagas[9]);

            desempregados[stoi(paramsVagas[0]) - 1]->setEndereco(paramsVagas[6], paramsVagas[7], stoi(paramsVagas[8]), paramsVagas[9]); // POPULA ALGUNS ENDERECOS EM DESEMPREGADOS
          }
        }

        auxCountVagas = 0;
      } else {
        auxCountVagas++;
      }
    }
  }
  // END VAGAS
}

// OPERACAO 1
vector<Vagas*> operation1 (const vector<Vagas*> &vagas, const vector<Desempregado*> &desempregados){
  vector<Vagas*> result;
  string inNome;

  cout << "Digite um nome para a busca: ";
  
  cin.ignore();
  getline(cin, inNome);
  
  for(Desempregado *desempregado : desempregados) {
    if(toLowerCase(desempregado->getNome()) == toLowerCase(inNome)) {
      for(Vagas *vaga : vagas) {
        if(toLowerCase(vaga->getBairro()) == toLowerCase(desempregado->getBairro())) {
          result.push_back(vaga);
          // cout << vaga->getRemuneracao() << endl;
        }
      }
    }
  }

  sort( result.begin( ), result.end( ), [ ]( const auto& lhs, const auto& rhs )
  {
    return lhs->getRemuneracao() < rhs->getRemuneracao();
  });

  cout << "--------------------------------------" << endl;
  for (Vagas* vaga : result) {
    cout << vaga->getRemuneracao() << endl;
  }
  cout << "--------------------------------------" << endl;

  return result;
}
// FIM OPERACAO 1

// OPERACAO 2
vector<Vagas*> operation2 (const vector<Vagas*> &vagas, const vector<Desempregado*> &desempregados){
  vector<Vagas*> result;
  string nomeDesempregado;
  cout << "Digite o nome do desempregado: ";

  cin.ignore();
  getline(cin, nomeDesempregado);
  bool breakLoop = 0;

  for(Desempregado *desempregado : desempregados) {
    if(toLowerCase(desempregado->getNome()) == toLowerCase(nomeDesempregado)) {
      for(Vagas *vaga : vagas) {
        for(string skillDesempregado : desempregado->getSkill()) {
          for(string skillVaga : vaga->getSkill()) {
            if(skillVaga == skillDesempregado){
              result.push_back(vaga);
              // cout << vaga->getId() << endl;
              breakLoop = 1;
              break;
            }
          }
          if(breakLoop) {
            break;
          }
        }
      }
    }
  }

  sort( result.begin( ), result.end( ), [ ]( const auto& lhs, const auto& rhs )
  {
    return lhs->getRemuneracao() < rhs->getRemuneracao();
  });

  cout << "--------------------------------------" << endl;
  for (Vagas* vaga : result) {
    cout << vaga->getRemuneracao() << endl;
  }
  cout << "--------------------------------------" << endl;

  return result;
}
// FIM OPERACAO 2

// OPERACAO 3
vector<Vagas*> operation3 (const vector<Vagas*> &vagas, const vector<Desempregado*> &desempregados){
  vector<Vagas*> result;
  string skillName;
  cout << "Digite a skill: ";

  cin.ignore();
  getline(cin, skillName);

  for(Vagas *vaga : vagas) {
    for(string skillVaga : vaga->getSkill()) {
      if(skillVaga == skillName) {
        result.push_back(vaga);
        // cout << vaga->getId() << endl;
      }
    }
  }

  sort( result.begin( ), result.end( ), [ ]( const auto& lhs, const auto& rhs )
  {
    return lhs->getId() < rhs->getId();
  });

  cout << "--------------------------------------" << endl;
  for (Vagas* vaga : result) {
    cout << vaga->getId() << endl;
  }
  cout << "--------------------------------------" << endl;

  return result;
}
// FIM OPERACAO 3

// OPERACAO 4
vector<Desempregado*> operation4 (const vector<Vagas*> &vagas, const vector<Desempregado*> &desempregados){
  vector<Desempregado*> result;
  int idVaga;
  cout << "Digite o id da vaga para pesquisa: ";
  cin >> idVaga;
  
  for(Vagas *vaga : vagas) {
    if(vaga->getId() == idVaga){
      for(Desempregado *desempregado : desempregados) {
        if(toLowerCase(vaga->getBairro()) == toLowerCase(desempregado->getBairro())){
          result.push_back(desempregado);
          // cout << desempregado->getIdade() << endl;
        }
      }
    }
  }

  sort( result.begin( ), result.end( ), [ ]( const auto& lhs, const auto& rhs )
  {
    return lhs->getIdade() < rhs->getIdade();
  });

  cout << "--------------------------------------" << endl;
  for (Desempregado* desempregado : result) {
    cout << desempregado->getIdade() << endl;
  }
  cout << "--------------------------------------" << endl;

  return result;
}
// FIM OPERACAO 4

// OPERACAO 5
vector<Desempregado*> operation5 (const vector<Vagas*> &vagas, const vector<Desempregado*> &desempregados){
  vector<Desempregado*> result;
  int idVaga;
  cout << "Digite o id da vaga: ";
  cin >> idVaga;

  for(Vagas *vaga : vagas) {
    if(vaga->getId() == idVaga){
      for(Desempregado *desempregado : desempregados) {
        if (vaga->getSkill() == desempregado->getSkill()) {
          result.push_back(desempregado);
          // cout << desempregado->getTempo() << endl;
        }
      } 
    }
  }

  sort( result.begin( ), result.end( ), [ ]( const auto& lhs, const auto& rhs )
  {
    return lhs->getTempo() < rhs->getTempo();
  });

  cout << "--------------------------------------" << endl;
  for (Desempregado* desempregado : result) {
    cout << desempregado->getTempo() << endl;
  }
  cout << "--------------------------------------" << endl;

  return result;
}
// FIM OPERACAO 5

// OPERACAO 6 (TODO: ORDENAR)
void operation6 (const vector<Vagas*> &vagas, const vector<Desempregado*> &desempregados){
  vector<Vagas*> resultVagas;
  vector<Desempregado*> resultDesempregados;
  string skillName1;
  cout << "Digite o skill: ";

  cin.ignore();
  getline(cin, skillName1);

  for(Vagas *vaga : vagas) {
    for(string skillVaga : vaga->getSkill()) {
      if(skillVaga == skillName1) {
        resultVagas.push_back(vaga);
        // cout << vaga->getId() << endl;
      }
    }
  }

  for(Desempregado *desempregado : desempregados) {
    for(string skillDesempregado : desempregado->getSkill()) {
      if(skillDesempregado == skillName1) {
        resultDesempregados.push_back(desempregado);
        // cout << desempregado->getNome() << endl;
      }
    }
  }

  sort( resultDesempregados.begin( ), resultDesempregados.end( ), [ ]( const auto& lhs, const auto& rhs )
  {
    return lhs->getIdade() < rhs->getIdade();
  });

  cout << "----------------DESEMPREGADOS--------------" << endl;
  for (Desempregado* desempregado : resultDesempregados) {
    cout << desempregado->getNome() << endl;
  }
  cout << "--------------------------------------" << endl;

  sort( resultVagas.begin( ), resultVagas.end( ), [ ]( const auto& lhs, const auto& rhs )
  {
    return lhs->getId() < rhs->getId();
  });

  cout << "----------------VAGAS-----------------" << endl;
  for (Vagas* vaga : resultVagas) {
    cout << vaga->getId() << endl;
  }
  cout << "--------------------------------------" << endl;
}
// FIM OPERACAO 6

// OPERACAO 7
vector<Vagas*> operation7 (const vector<Vagas*> &vagas, const vector<Desempregado*> &desempregados){
  vector<Vagas*> result;
  string nomeEmpresa;
  cout << "Digite o nome da empresa: ";

  cin.ignore();
  getline(cin, nomeEmpresa);

  for(Vagas *vaga : vagas) {
    if(toLowerCase(vaga->getNome()) == toLowerCase(nomeEmpresa)) {
      result.push_back(vaga);
      // cout << vaga->getId() << endl;
    }
  }

  sort( result.begin( ), result.end( ), [ ]( const auto& lhs, const auto& rhs )
  {
    return lhs->getId() < rhs->getId();
  });

  cout << "--------------------------------------" << endl;
  for (Vagas* vaga : result) {
    cout << vaga->getId() << endl;
  }
  cout << "--------------------------------------" << endl;

  return result;
}
// FIM OPERACAO 7

void addDesempregado(vector<Desempregado*> &desempregado) {

  string nome, skill, rua, bairro, cidade;
  int idade, tempo, numero;
  vector<string> skills;

  cout << "Digite o nome: ";
  cin.ignore();
  getline(cin, nome);
  cout << "Digite a idade: ";
  cin >> idade;
  cout << "Digite as skills (separadas por virgula sem espaco): ";
  cin >> skill;
  cout << "Digite o tempo desempregado: ";
  cin >> tempo;
  cout << "Digite a rua: ";
  cin.ignore();
  getline(cin, rua);
  cout << "Digite o bairro: ";
  cin.ignore();
  getline(cin, bairro);
  cout << "Digite o numero da casa: ";
  cin >> numero;
  cout << "Digite a cidade : ";
  cin.ignore();
  getline(cin, cidade);

  skills = explode(skill, ',');

  Desempregado *d = new Desempregado(nome, idade, skills, tempo, rua, bairro, numero, cidade);

  cout << d->getNome() << " adicionado com sucesso!" << endl;

  desempregado.push_back(d);
}

void addVaga(vector<Vagas*> &vagas) {

  int id, funcionarios, numero;
  string nome, rua, bairro, cidade;
  float horas, remuneracao;
  string skill;
  vector<string> skills;

  cout << "Digite o nome: ";
  cin.ignore();
  getline(cin, nome);
  cout << "Digite a remuneracao: ";
  cin >> remuneracao;
  cout << "Digite as skills (separadas por virgula sem espaco): ";
  cin >> skill;
  cout << "Digite a quantidade de funcionarios: ";
  cin >> funcionarios;
  cout << "Digite as horas da vaga: ";
  cin >> horas;
  cout << "Digite o id da vaga (numero): ";
  cin >> id;
  cout << "Digite a rua: ";
  cin.ignore();
  getline(cin, rua);
  cout << "Digite o bairro: ";
  cin.ignore();
  getline(cin, bairro);
  cout << "Digite o numero da casa: ";
  cin >> numero;
  cout << "Digite a cidade : ";
  cin.ignore();
  getline(cin, cidade);

  skills = explode(skill, ',');

  Vagas *v = new Vagas(id, skills, horas, remuneracao, nome, funcionarios, rua, bairro, numero, cidade);

  cout << "Vaga " << v->getId() << " adicionada com sucesso!" << endl;

  vagas.push_back(v);
}