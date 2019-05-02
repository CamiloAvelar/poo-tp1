// Classe responsável por popular os vetores de Vagas e Desempregados, é a única responsável por fazer as operação nestes vetores, como adicionar elementos.
#include "../include/Populate.h"

// Inicia o parâmetro instance (classe Singleton)
Populate* Populate::instance = 0;

// Métoco para instanciar a classe (garante que só uma instancia exista)
Populate* Populate::getInstance() {
  if(instance == 0) {
    instance = new Populate();
  }

  return instance;
}

Populate::Populate() { // Construtor de Populate, ao ser instanciada inicia e popula os vetores de vagas e desempregados.
  vector<Desempregado*> desempregados (1000);
  vector<Vagas*> vagas (500);
  
  populateDesempregados(); // Método para popular o vetor de desempregados
  populateVagas(); // Método para popular o vetor de vagas
};

Populate::~Populate() {
  delete instance;
}

// Método que lê os arquivos de vagas e desempregados e popula dois vetores, um de Vagas o outro de Desempregados;
void Populate::populate(const string &path, const uint &qtdParams, const uint &skillsLocation, const string &action) {
  ifstream input(path);
  uint auxCount = 0; // auxilar para contagem das linhas.
  vector<string> params (qtdParams);
  vector<string> skills;

  if(input) {
    for( string line; getline(input, line); ) { // Lê linha por linha do arquivo passado pelo parâmetro 'path'

      if( auxCount < qtdParams) {
        if (auxCount == skillsLocation - 1) {
          skills = Util::explode(line, ' ');
          sort(skills.begin(), skills.end());
          string lastSkill;
          int indexSkill = 0;
          for(string skill : skills) { // NÃO PERMITE INCLUSÃO DE SKILLS IGUAIS
            if(lastSkill == skill) {
              skills.erase(skills.begin() + indexSkill);
            }
            lastSkill = skill;
            indexSkill++;
          }
        } else {
          params[auxCount] = line;
        }

        if ( auxCount == qtdParams - 1 ) { // Verifica se é o último parâmetro a ser lido para a criação dos Objetos.
          for ( uint i = 0; i < params.size(); i++ ) {
            if( i == qtdParams - 1 ) {
              if (action == "desempregados") {
                desempregados.push_back(new Desempregado(params[0], stoi(params[1]), skills, stoi(params[3]))); // Cria o objeto Desempregado e o adiciona ao vetro de desempregados.
              } else if (action == "vagas") {
                vagas.push_back(new Vagas(stoi(params[0]), skills, stof(params[2]),stof(params[3]), params[4], stoi(params[5]), params[6], params[7], stoi(params[8]), params[9])); // Cria o objeto Vaga e popula o vetor de vagas.

                desempregados[stoi(params[0]) - 1]->setEndereco(params[6], params[7], stoi(params[8]), params[9]); // POPULA ALGUNS ENDERECOS EM DESEMPREGADOS
              }
            }
          }

          auxCount = 0; // Zera a contagem, a contagem é feita apenas até a quantidade máxima de parâmetros, para garantir a criação correta dos objetos.
        } else {
          auxCount++; // Caso a contagem ainda não tenha chegado ao fim da quantidade máxima de parâmetros, ela é incrementada.
        }
      }
    }
  } else {
    cerr << "File could not be opened!\n"; // Report error
    cerr << "Error code: " << strerror(errno) << endl;
  }
}

void Populate::populateDesempregados() {
  populate("entradas/entradaDes.txt", 4, 3, "desempregados"); // Chama o método populate com os parâmetros para popular os desempregados
}

void Populate::populateVagas() {
  populate("entradas/entradaVagas.txt", 10, 2, "vagas"); // Chama o método populate com os parâmetros para popular os desempregados
}

vector<Vagas*> Populate::getVagas() { // Retorna o vetor de vagas
  return this->vagas;
}

vector<Desempregado*> Populate::getDesempregados() { // Retorna o vetor de desempregados
  return this->desempregados;
}

void Populate::addVaga(Vagas* &vaga){ // Adiciona uma vaga ao vetor de vagas
  this->vagas.push_back(vaga);
}

void Populate::addDesempregado(Desempregado* &desempregado) { // Adiciona um desempregado ao vetor de desempregados
  this->desempregados.push_back(desempregado);
}