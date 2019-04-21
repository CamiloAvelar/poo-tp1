#include "../include/Populate.h"

Populate::Populate() {
  vector<Desempregado*> desempregados (1000);
  vector<Vagas*> vagas (500);
  
  populateDesempregados();
  populateVagas();
};

void Populate::populate(const string &path, const uint &qtdParams, const uint &skillsLocation, const string &action) {
  ifstream input(path);
  uint auxCount = 0;
  vector<string> params (qtdParams);
  vector<string> skills;

  if(input) {
    for( string line; getline(input, line); ) {

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

        if ( auxCount == qtdParams - 1 ) {
          for ( uint i = 0; i < params.size(); i++ ) {
            if( i == qtdParams - 1 ) {
              if (action == "desempregados") {
                desempregados.push_back(new Desempregado(params[0], stoi(params[1]), skills, stoi(params[3]))); 
              } else if (action == "vagas") {
                vagas.push_back(new Vagas(stoi(params[0]), skills, stof(params[2]),stof(params[3]), params[4], stoi(params[5]), params[6], params[7], stoi(params[8]), params[9]));

                desempregados[stoi(params[0]) - 1]->setEndereco(params[6], params[7], stoi(params[8]), params[9]); // POPULA ALGUNS ENDERECOS EM DESEMPREGADOS
              }
            }
          }

          auxCount = 0;
        } else {
          auxCount++;
        }
      }
    }
  } else {
    cerr << "File could not be opened!\n"; // Report error
    cerr << "Error code: " << strerror(errno) << endl;
  }
}

void Populate::populateDesempregados() {
  populate("entradas/entradaDes.txt", 4, 3, "desempregados");
}

void Populate::populateVagas() {
  populate("entradas/entradaVagas.txt", 10, 2, "vagas");
}

vector<Vagas*> Populate::getVagas() {
  return this->vagas;
}

vector<Desempregado*> Populate::getDesempregados() {
  return this->desempregados;
}

void Populate::addVaga(Vagas* &vaga){
  this->vagas.push_back(vaga);
}

void Populate::addDesempregado(Desempregado* &desempregado) {
  this->desempregados.push_back(desempregado);
}