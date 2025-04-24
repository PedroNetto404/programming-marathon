#include<iostream>
#include<vector>
#include<cmath>

#define T_NOA (pow(2, camada-1) - 1)
#define T_NO (pow(2, camada) - 1)

using namespace std;

vector<int> estacoes;
int neutro = 0, conf1 = 0, conf2 = 0;

void processa_estacoes(int camada, int no) {
  if (no >= estacoes.size())
    return;

  int f = estacoes[no];
  int noe = (no - T_NOA) * 2 + T_NO;
  int nod = noe+1;

  processa_estacoes(camada+1, noe);
  processa_estacoes(camada+1, nod);

  if (noe < estacoes.size()) {
    if (f < estacoes[noe])
      conf1++;
    else if (f > estacoes[noe])
      conf2++;
  }
  if (nod < estacoes.size()) {
    if (f < estacoes[nod])
      conf1++;
    else if (f > estacoes[nod])
      conf2++;
  }
}

int main (int argc, char *argv[]) {
  int n, est;
 
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> est;
    estacoes.push_back(est);
  }
 
  int v = processa_estacoes(0, 0);
  if (conf1 > 0 and conf2 > 0)
    cout << 0 << endl;
  else if (conf1 > 0)
    cout << 1 << endl;
  else if (conf2 > 0)
    cout << 2 << endl;
  else
    cout << 0 << endl;
  return 0;
}
