# Relatório Trabalho Prático - Programação Orientada à Objetos

***Aluno***: *Camilo Esteves Mendes de Avelar*

## Diagrama UML

![UML-Classes image]
(images/UML-Classes.png)

## Classes auxiliares

### Populate

Classe cuja responsabilidade é ler os arquivos de entradas e popular os vetores com as respectivas classes (Vagas e Desempregados), esta função é responsável por popular os vetores:

```c++
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
```
