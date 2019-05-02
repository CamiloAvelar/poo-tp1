/* 
É a classe responsável pelas implementações dos exercícios propostos, é uma classe Singleton, só pode ser instanciada uma vez por execução.
Nela se encontram as implementações de cada operação.
*/
#include "../include/Operations.h"

// Inicia o parâmetro instance (classe Singleton)
Operations* Operations::instance = 0;

// Métoco para instanciar a classe (garante que só uma instancia exista)
Operations* Operations::getInstance() {
  if(instance == 0) {
    instance = new Operations();
  }

  return instance;
}

Operations::Operations() {};

Operations::~Operations() {
  delete instance;
}

const vector<Vagas*> Operations::operation1() {
  vector<Vagas*> result;
  string inNome;

  cout << "Digite um nome para a busca: ";
  
  cin.ignore();
  getline(cin, inNome); // Recebe o nome.
  
  for(Desempregado *desempregado : populate->getDesempregados()) { // Percorre o vetor de desempregados
    if(Util::toLowerCase(desempregado->getNome()) == Util::toLowerCase(inNome)) { // Acha o desempregado com o nome digitado
      for(Vagas *vaga : populate->getVagas()) { // Percorre o vetor de vagas
        if(Util::toLowerCase(vaga->getBairro()) == Util::toLowerCase(desempregado->getBairro())) { // Compara o bairro do desempregado com o bairro da vaga
          result.push_back(vaga); // Caso o bairro for o mesmo, adiciona ao vetor de resultados.
        }
      }
    }
  }

  sort( result.begin( ), result.end( ), [ ]( const auto& lhs, const auto& rhs )
  {
    return lhs->getRemuneracao() < rhs->getRemuneracao(); // Ordena o vetor de resultados por remuneracao da vaga.
  });

  cout << "--------------------------------------" << endl;
  for (Vagas* vaga : result) { // Percorre o vetor de resultados
    cout << vaga->getId() << endl; // Imprime o id da vaga cujo bairro seja o mesmo do desempregado.
  }
  cout << "--------------------------------------" << endl;

  return result;
};

const vector<Vagas*> Operations::operation2() {
  vector<Vagas*> result;
  string nomeDesempregado;
  cout << "Digite o nome do desempregado: ";

  cin.ignore();
  getline(cin, nomeDesempregado); // Recebe o nome do desempregado
  for(Desempregado *desempregado : populate->getDesempregados()) { // Percorre o vetor de desempregados
    if(Util::toLowerCase(desempregado->getNome()) == Util::toLowerCase(nomeDesempregado)) { // Compara o nome do desempregado com o nome digitado
      vector<string> skillDesempregado = desempregado->getSkill(); // Recebe o vetor de skill do desempregado encontrado.
      uint sizeDesemp = skillDesempregado.size(); // Pega o tamanho do vetor de skill do desempregado
      bool hasSkill;
      for(Vagas *vaga : populate->getVagas()) { // Percorre o vetor de vagas
        vector<string> skillVaga = vaga->getSkill(); // Recebe o vetor de skill da vaga
        uint sizeVaga = skillVaga.size(); // Pega o tamanho do vetor de skill da vaga
        sort(skillVaga.begin(), skillVaga.end());                 //Ordena o vetor de skill de vagas e desempregados
        sort(skillDesempregado.begin(), skillDesempregado.end()); 
        uint auxSearch = 0; // contador auxiliar
        if(sizeVaga <= sizeDesemp) { // Faz a verificação se o tamanho do vetor de skill de desempregados é maior que o de vagas (garante que o desempregado possa ter todas as skills).
          for(string skill : skillDesempregado) { // Percorre o vetor de skill de desempregados
            hasSkill = binary_search(skillVaga.begin(), skillVaga.end(), skill); // Procura no vetor de skill de vagas a skill do desempregado
            if(hasSkill) { // Caso a skill exista no vetor, aumenta o contador auxiliar.
              auxSearch++;
            }
          }
          if(auxSearch == sizeVaga) { // Compara o contador auxiliar com o tamanho do vetor de skill de vagas, caso for igual (significa que o desempregado tem todas as skills da vaga)
            result.push_back(vaga); // Adiciona a vaga ao vetor de resultados.
            // cout << vaga->getId() << endl;
          }
        }
      }
    }
  }

// Esta parte de ordenação e impressão dos resultados é similar em todas as operações, já explicada anteriormente.
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
  getline(cin, skillName); // Recebe o nome da skill

  for(Vagas *vaga : populate->getVagas()) { // Percorre o vetor de vagas
    for(string skillVaga : vaga->getSkill()) { // Percorre o vetor de skill da vaga
      if(skillVaga == skillName) { // Verifica se o nome do skill digitado está no vetor de skill de vagas.
        result.push_back(vaga); // Case esteja, adiciona ao vetor de resultados
        // cout << vaga->getId() << endl;
      }
    }
  }

// Esta parte de ordenação e impressão dos resultados é similar em todas as operações, já explicada anteriormente.
  sort( result.begin( ), result.end( ), [ ]( const auto& lhs, const auto& rhs )
  {
    return lhs->getId() < rhs->getId(); // Ordena por id
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
  cin >> idVaga; // Recebe o id da vaga.
  
  for(Vagas *vaga : populate->getVagas()) { // Percorre o vetor de vagas.
    if(vaga->getId() == idVaga){ // Verifica se o id da vaga é o id digitado
      for(Desempregado *desempregado : populate->getDesempregados()) { // Percorre o vetor de desempregados
        if(Util::toLowerCase(vaga->getBairro()) == Util::toLowerCase(desempregado->getBairro())){ // Compara o bairro do desempregado com o bairro da vaga
          result.push_back(desempregado); // Caso for igual, adiciona ao vetor de resultados
          // cout << desempregado->getIdade() << endl;
        }
      }
    }
  }

// Esta parte de ordenação e impressão dos resultados é similar em todas as operações, já explicada anteriormente.
  sort( result.begin( ), result.end( ), [ ]( const auto& lhs, const auto& rhs )
  {
    return lhs->getIdade() < rhs->getIdade(); // Ordena por idade.
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
  cin >> idVaga; // Recebe o id da vaga

  for(Vagas *vaga : populate->getVagas()) { // Percorre o vetor de vagas
    if(vaga->getId() == idVaga){ // Verifica se o id da vaga é igual ao id digitado
      for(Desempregado *desempregado : populate->getDesempregados()) { // Percorre o vetor de desempregados
        vector<string> skillVaga = vaga->getSkill(); // Recebe o vetor de skill da vaga
        vector<string> skillDesempregado = desempregado->getSkill(); // Recebe o vetor de skill do desempregado
        sort(skillVaga.begin(), skillVaga.end()); // Ordena o vetor de skill da vaga e desempregado(proxima linha)
        sort(skillDesempregado.begin(), skillDesempregado.end());
        if (skillVaga == skillDesempregado) { // Compara o vetor skill da vaga com o vetor de skill do desempregado
          result.push_back(desempregado); // Caso os vetores forem iguais, adiciona ao vetor de resultados
          // cout << desempregado->getTempo() << endl;
        }
      } 
    }
  }

// Esta parte de ordenação e impressão dos resultados é similar em todas as operações, já explicada anteriormente.
  sort( result.begin( ), result.end( ), [ ]( const auto& lhs, const auto& rhs )
  {
    return lhs->getTempo() < rhs->getTempo(); // Ordena por tempo
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
  getline(cin, skillName1); // Recebe o nome do skill

  for(Vagas *vaga : populate->getVagas()) { // Percorre o vetor de vagas
    for(string skillVaga : vaga->getSkill()) { // Percorre o vetor de skill da vaga
      if(skillVaga == skillName1) { // Caso o skill da vaga tiver o skill digitado, adiciona a vaga ao vetor de resultados de vagas.
        resultVagas.push_back(vaga);
        // cout << vaga->getId() << endl;
      }
    }
  }

  for(Desempregado *desempregado : populate->getDesempregados()) { // Percorre o vetor de desempregados
    for(string skillDesempregado : desempregado->getSkill()) { // Percorre o vetor de skill do desempregado
      if(skillDesempregado == skillName1) { // Caso o skill digitado estiver no vetor de skill do desempregado, adiciona ao vetor de resultados de desempregados.
        resultDesempregados.push_back(desempregado);
        // cout << desempregado->getNome() << endl;
      }
    }
  }

// Esta parte de ordenação e impressão dos resultados é similar em todas as operações, já explicada anteriormente.
  sort( resultDesempregados.begin( ), resultDesempregados.end( ), [ ]( const auto& lhs, const auto& rhs )
  {
    return lhs->getIdade() < rhs->getIdade(); // Ordena por idade
  });

  sort( resultVagas.begin( ), resultVagas.end( ), [ ]( const auto& lhs, const auto& rhs )
  {
    return lhs->getId() < rhs->getId(); // Ordena por id da vaga
  });

  cout << "----------------DESEMPREGADOS--------------" << endl;
  for (Desempregado* desempregado : resultDesempregados) {
    cout << desempregado->getNome() << endl;
  }
  cout << "--------------------------------------" << endl;

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
  getline(cin, nomeEmpresa); // Recebe o nome da empresa

  for(Vagas *vaga : populate->getVagas()) { // Percorre o vetor de vagas
    if(Util::toLowerCase(vaga->getNome()) == Util::toLowerCase(nomeEmpresa)) { // Compara o nome digitado com o nome da empresa da vaga
      result.push_back(vaga); // Caso for igual, adiciona ao vetor de resultados
      // cout << vaga->getId() << endl;
    }
  }

// Esta parte de ordenação e impressão dos resultados é similar em todas as operações, já explicada anteriormente.
  sort( result.begin( ), result.end( ), [ ]( const auto& lhs, const auto& rhs )
  {
    return lhs->getId() < rhs->getId(); // Ordena por id da vaga
  });

  cout << "--------------------------------------" << endl;
  for (Vagas* vaga : result) {
    cout << vaga->getId() << endl;
  }
  cout << "--------------------------------------" << endl;

  return result;
}

const void Operations::operation8 (){
  vector<Desempregado*> desempregados = populate->getDesempregados(); // Recebe uma copia do vetor de desempregados para manipulação.
  bool result;
  cout << setw(23) << "Nome do desempregado" << setw(5) << " Id da vaga" << endl;
  for(Vagas *vaga : populate->getVagas()) { // Percorre o vetor de vagas
    vector<string> skillVaga = vaga->getSkill(); // Recebe o vetor de skills da vaga
    uint sizeVaga = vaga->getSkill().size(); // Recebe o tamanho do vetor de skills da vaga
    uint index = 0; // Auxiliar contador
    for(Desempregado *desempregado : desempregados) { // Percore o vetor de desempregados
      vector<string> skillDesemp = desempregado->getSkill(); // Recebe o vetor de skills do desempregado
      uint sizeDesempregado = desempregado->getSkill().size(); // Recebe o tamanho do vetor de skills do desempregado
      if(sizeVaga <= sizeDesempregado) { // Compara o tamanho do vetor de skills da vaga com o de desempregado (garante que o desempregado possa ter todas as skills antes da verificação, se o tamanho do vetor de skills for maior que o de skill do desempregado, o desempregado nao tem todas as skills necessarias).
        sort(skillVaga.begin(), skillVaga.end());     // Ordena os vetores de skills da vaga e de desempregado
        sort(skillDesemp.begin(), skillDesemp.end());
        uint auxSearch = 0; // auxiliar contador
        for (string skill : skillDesemp) { // Percorre o vetor de skills do desempregado
          result = binary_search(skillVaga.begin(), skillVaga.end(), skill); // Procura o skill do desempregado no vetor de skills da vaga
          if(result) { // caso encontrado, aumenta o contador auxilar
            auxSearch++;
          }
        }
        if(auxSearch == sizeVaga) { // Caso o contador seja do mesmo tamanho do vetor de skill da vaga (significa que o desemprago tem todas as skills da vaga)
          cout << setw(23) << desempregado->getNome() << setw(5) << vaga->getId() << endl; // Imprime o nome do desempregado com o id da vaga.
          desempregados.erase(desempregados.begin() + index); // Remove o desempregado do vetor de desempregado (para garantir que uma mesma vaga nao seja atribuido a mais de um desempregado)
          break; // caso encontre o desempregado sai do loop de desempregado.
        }
      }
      index++; // aumenta o contador auxilar de index;
    } 
  }
}

// Método para criar um desempregado e adicionar ao vetor de desempregados.
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

  skills = Util::explode(skill, ','); // Separa as skills digitadas separadas por virgula, em um vetor de skills

  Desempregado *d = new Desempregado(nome, idade, skills, tempo, rua, bairro, numero, cidade); // Cria o objeto desempregado com as propriedades digitadas.

  populate->addDesempregado(d); // Adiciona o desempregado ao vetor de desempregados

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

  skills = Util::explode(skill, ','); // Separa as skills digitadas separadas por virgula, em um vetor de skills

  Vagas *v = new Vagas(id, skills, horas, remuneracao, nome, funcionarios, rua, bairro, numero, cidade); // Cria o objeto vagas com as propriedades digitadas

  populate->addVaga(v); // Adiciona a vaga ao vetor de vagas.

  cout << "Vaga " << v->getId() << " adicionada com sucesso!" << endl;
}
