#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>

#define T_NOA (pow(2, camada-1) - 1)
#define T_NO (pow(2, camada) - 1)

using namespace std;

vector<int> estacoes;

int processa_estacoes(int camada, int no) {
  if (no >= estacoes.size())
    return 0;

  int e = 0, d = 0, f = estacoes[no];

  int noe = (no - T_NOA) * 2 + T_NO;
  int nod = noe+1;

  e = processa_estacoes(camada+1, noe);
  d = processa_estacoes(camada+1, nod);

  if (noe < estacoes.size())
    if (f < estacoes[noe])
      e++;
    else if (f > estacoes[noe])
      e--;
  if (nod < estacoes.size())
    if (f < estacoes[nod])
      d++;
    else if (f > estacoes[nod])
      d--;

  return e + d;
}

int main (int argc, char *argv[]) {
  int n, est;
 
  //ifstream fileIn("/Users/lucasbf/Documents/Aulas/Maratona_de_Programacao/Interfatecs2024/1afase/enchendo_linguica/2.in");
  ifstream fileIn("/Users/lucasbf/Documents/Aulas/Maratona_de_Programacao/Interfatecs2024/1afase/enchendo_linguica/input/linguica2");
  cin.rdbuf(fileIn.rdbuf());
    
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> est;
    estacoes.push_back(est);
  }
 
  int v = processa_estacoes(0, 0);
  if (v == estacoes.size()-1)
    cout << 1 << endl;
  else if (-v == estacoes.size()-1)
    cout << 2 << endl;
  else
    cout << 0 << endl;

  return 0;
}
