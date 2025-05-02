#include<iostream>
#include<vector>

using namespace std;

int main (int argc, char *argv[]) {
  int n, aux, r, ngrupos;
  vector<int> perfis;
  string nome_reg;

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> aux;
    perfis.push_back(aux);
  }

  cin >> r;
  for(int i = 0; i < r; i++) {
    ngrupos = INT_MAX;
    cin >> nome_reg;
    for(int j = 0; j < n; j++) {
      cin >> aux;
      aux /= perfis[j];
      if (aux < ngrupos)
        ngrupos = aux;
    }
    cout << nome_reg << " " << ngrupos << "\n";
  }

  return 0;
}
