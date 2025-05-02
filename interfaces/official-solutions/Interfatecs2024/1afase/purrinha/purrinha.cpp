#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main (int argc, char *argv[]) {
  int qj, nr;
  int soma_maos, mao, advinha;
  string nome;

  cin >> qj;
  vector<string> nomes;
  vector<int> pontos;
  for(int i = 0; i < qj; i++) {
    cin >> nome;
    nomes.push_back(nome);
    pontos.push_back(0);
  }
  cin >> nr;
  for(int i = 0; i < nr; i++) {
    soma_maos = 0;
    for(int j = 0; j < qj; j++) {
      cin >> mao;
      soma_maos += mao;
    }
    for(int j = 0; j < qj; j++) {
      cin >> advinha;
      if(advinha == soma_maos)
        pontos[j]++;
    }
  }
  auto max = max_element(pontos.begin(), pontos.end());
  int cj = 0;
  for_each(pontos.begin(), pontos.end(), [&](int i) {
    if(i == *max)
      cj++;
  });
  if(cj == 1)
    cout << nomes[distance(pontos.begin(), max)] << " GANHOU\n";
  else
    cout << "EMPATE\n";

  return 0;
}
