#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<unordered_set>
#include <fstream>

using namespace std;

int carrinho, n, falta, nt = 0;
vector<int> prods;

bool calc_carrinho() {
  for(int i = 0; i < nt - 2; i++) {
    unordered_set<int> s;
    int ainda_falta = falta - prods[i];
    if (ainda_falta <= 0) continue;
    for(int j = i + 1; j < prods.size(); j++) {
      int sobra = ainda_falta - prods[j];
      if(sobra <= 0) continue;
      if(s.find(sobra) != s.end())
        return true;
      s.insert(prods[j]);
    }
  }
  return false;
}

int main () {
  int p;
  bool visto[205] = {false};

  //ifstream fileIn("/Users/lucasbf/Documents/Aulas/Maratona de Programação/Interfatecs2024/1afase/calcetis/input/Calcetis2");
  //cin.rdbuf(fileIn.rdbuf());
  
  cin >> carrinho >> n;
  falta = 200 - carrinho;

  for (int i = 0; i < n; i++) {
    cin >> p;
    if (p <= falta && !visto[p]) {
      prods.push_back(p);
      visto[p] = true;
        nt++;
    }
  }
  
  if (calc_carrinho())
    cout << "fretegratis\n";
  else
    cout << "fretepago\n";

  return 0;
}
