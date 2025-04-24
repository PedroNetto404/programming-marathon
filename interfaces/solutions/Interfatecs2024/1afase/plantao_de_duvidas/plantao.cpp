#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int n_vagas;

vector<string> nome_cat{"ALGORITMOS", "BOAS PRATICAS", "DESEMPENHO", "FLUXOGRAMAS", "INTERPRETACAO DE ENUNCIADOS", "SINTAXE DA LINGUAGEM"};
vector<vector<string>> atendimentos(6);
vector<string> fica_prox;

int main (int argc, char *argv[]) {
  string linha, v, delim(30, '-'), nome;
  int c, atend = 0;
  vector<string> cats;

  cin >> n_vagas;
  cin.ignore();
  while (getline(cin, linha)) {
    cats.clear();
    stringstream ss(linha);
    while (getline(ss, v, ' '))
      cats.push_back(v);
    nome = cats[0];
    if (atend < n_vagas) { 
      atend++;
      for (int i = 1; i < cats.size(); i++) {
        c = stoi(cats[i])-1;
        atendimentos[c].push_back(nome);
      }
    } 
    else
      fica_prox.push_back(nome);
  }
  for (int i = 0; i < nome_cat.size(); i++) {
    if (i > 0) cout << endl << endl;
    cout << delim;
    cout << endl << nome_cat[i];
    cout << endl << delim;
    sort(atendimentos[i].begin(), atendimentos[i].end());
    for (auto &nome_aluno : atendimentos[i])
      cout << endl << nome_aluno;
  }
  if (fica_prox.size()) {
    cout << endl << endl << delim;
    cout << endl << "FICA PARA A PROXIMA!";
    cout << endl << delim;
    for (auto &nome : fica_prox)
      cout << endl << nome;
  }
  
  return 0;
}
