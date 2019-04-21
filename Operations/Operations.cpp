#include "Operations.h"

Operations::Operations() {};

const vector<Vagas*> Operations::operation1() {
  vector<Vagas*> result;
  string inNome;

  cout << "Digite um nome para a busca: ";
  
  cin.ignore();
  getline(cin, inNome);
  
  for(Desempregado *desempregado : populate.getDesempregados()) {
    if(Util::toLowerCase(desempregado->getNome()) == Util::toLowerCase(inNome)) {
      for(Vagas *vaga : populate.getVagas()) {
        if(Util::toLowerCase(vaga->getBairro()) == Util::toLowerCase(desempregado->getBairro())) {
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
    cout << vaga->getId() << endl;
  }
  cout << "--------------------------------------" << endl;

  return result;
};

const vector<Vagas*> Operations::operation2() {
  vector<Vagas*> result;
  string nomeDesempregado;
  cout << "Digite o nome do desempregado: ";

  cin.ignore();
  getline(cin, nomeDesempregado);
  bool breakLoop = 0;

  for(Desempregado *desempregado : populate.getDesempregados()) {
    if(Util::toLowerCase(desempregado->getNome()) == Util::toLowerCase(nomeDesempregado)) {
      for(Vagas *vaga : populate.getVagas()) {
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
    cout << vaga->getId() << endl;
  }
  cout << "--------------------------------------" << endl;

  return result;
}

const vector<Vagas*> Operations::operation3 (){
  vector<Vagas*> result;
  string skillName;
  cout << "Digite a skill: ";

  cin.ignore();
  getline(cin, skillName);

  for(Vagas *vaga : populate.getVagas()) {
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

const vector<Desempregado*> Operations::operation4 (){
  vector<Desempregado*> result;
  int idVaga;
  cout << "Digite o id da vaga para pesquisa: ";
  cin >> idVaga;
  
  for(Vagas *vaga : populate.getVagas()) {
    if(vaga->getId() == idVaga){
      for(Desempregado *desempregado : populate.getDesempregados()) {
        if(Util::toLowerCase(vaga->getBairro()) == Util::toLowerCase(desempregado->getBairro())){
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
    cout << desempregado->getNome() << endl;
  }
  cout << "--------------------------------------" << endl;

  return result;
}

const vector<Desempregado*> Operations::operation5 (){
  vector<Desempregado*> result;
  int idVaga;
  cout << "Digite o id da vaga: ";
  cin >> idVaga;

  for(Vagas *vaga : populate.getVagas()) {
    if(vaga->getId() == idVaga){
      for(Desempregado *desempregado : populate.getDesempregados()) {
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
    cout << desempregado->getNome() << endl;
  }
  cout << "--------------------------------------" << endl;

  return result;
}

const void Operations::operation6 (){
  vector<Vagas*> resultVagas;
  vector<Desempregado*> resultDesempregados;
  string skillName1;
  cout << "Digite o skill: ";

  cin.ignore();
  getline(cin, skillName1);

  for(Vagas *vaga : populate.getVagas()) {
    for(string skillVaga : vaga->getSkill()) {
      if(skillVaga == skillName1) {
        resultVagas.push_back(vaga);
        // cout << vaga->getId() << endl;
      }
    }
  }

  for(Desempregado *desempregado : populate.getDesempregados()) {
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

const vector<Vagas*> Operations::operation7 (){
  vector<Vagas*> result;
  string nomeEmpresa;
  cout << "Digite o nome da empresa: ";

  cin.ignore();
  getline(cin, nomeEmpresa);

  for(Vagas *vaga : populate.getVagas()) {
    if(Util::toLowerCase(vaga->getNome()) == Util::toLowerCase(nomeEmpresa)) {
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

const void Operations::operation8 (){
  vector<Desempregado*> desempregados = populate.getDesempregados();
  bool result;
  cout << setw(23) << "Nome do desempregado" << setw(5) << " Id da vaga" << endl;
  for(Vagas *vaga : populate.getVagas()) {
    vector<string> skillVaga = vaga->getSkill();
    uint sizeVaga = vaga->getSkill().size();
    uint index = 0;
    for(Desempregado *desempregado : desempregados) {
      vector<string> skillDesemp = desempregado->getSkill();
      uint sizeDesempregado = desempregado->getSkill().size();
      if(sizeVaga <= sizeDesempregado) {
        sort(skillVaga.begin(), skillVaga.end());
        sort(skillDesemp.begin(), skillDesemp.end());
        uint auxSearch = 0;
        for (string skill : skillDesemp) {
          result = binary_search(skillVaga.begin(), skillVaga.end(), skill);
          if(result) {
            auxSearch++;
          }
        }
        if(auxSearch == sizeVaga) {
          cout << setw(23) << desempregado->getNome() << setw(5) << vaga->getId() << endl;
          desempregados.erase(desempregados.begin() + index);
          break;
        }
      }
      index++;
    } 
  }

  // sort( result.begin( ), result.end( ), [ ]( const auto& lhs, const auto& rhs )
  // {
  //   return lhs->getTempo() < rhs->getTempo();
  // });

  // cout << "--------------------------------------" << endl;
  // for (Desempregado* desempregado : result) {
  //   cout << desempregado->getTempo() << endl;
  // }f (vaga->getSkill() == desempregado->getSkill()) {
  //             // cout << desempregado->getTempo() << endl;
  //           }
  // cout << "--------------------------------------" << endl;
}

const void Operations::createDesempregado() {

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

  skills = Util::explode(skill, ',');

  Desempregado *d = new Desempregado(nome, idade, skills, tempo, rua, bairro, numero, cidade);

  populate.addDesempregado(d);

  cout << d->getNome() << " adicionado com sucesso!" << endl;
}

const void Operations::createVaga() {
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

  skills = Util::explode(skill, ',');

  Vagas *v = new Vagas(id, skills, horas, remuneracao, nome, funcionarios, rua, bairro, numero, cidade);

  populate.addVaga(v);

  cout << "Vaga " << v->getId() << " adicionada com sucesso!" << endl;
}
