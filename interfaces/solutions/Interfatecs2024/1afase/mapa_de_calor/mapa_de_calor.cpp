#include<iostream>
#include<array>
#include<numeric>

using namespace std;

int n;
array<int, 3> sup{{0, 0, 0}}, inf{{0, 0, 0}};
array<int, 4> esq{{0, 0, 0, 0}}, cen{{0, 0, 0, 0}}, dir{{0, 0, 0, 0}};

int main (int argc, char *argv[]) {
  int n, v1, v2, v3;

  cin >> n;
  for(int i = 0; i < n; i++)
    for(int l = 0; l < 6; l++) {
      cin >> v1 >> v2 >> v3;
      switch (l) {
        case 0: 
          sup[0] += v1;
          sup[1] += v2;
          sup[2] += v3;
          break;
        case 1: case 2: case 3: case 4:
          esq[l-1] += v1;
          cen[l-1] += v2;
          dir[l-1] += v3;
          break;
        case 5:
          inf[0] += v1;
          inf[1] += v2;
          inf[2] += v3;
          break;
      }
    }
  
  string regiao = "superior";
  int max = accumulate(sup.begin(), sup.end(), 0);
  int rg = accumulate(esq.begin(), esq.end(), 0);
  if (rg > max) {
    regiao = "esquerda";
    max = rg;
  }
  rg = accumulate(cen.begin(), cen.end(), 0);
  if (rg > max) {
    regiao = "centro";
    max = rg;
  } 
  rg = accumulate(dir.begin(), dir.end(), 0);
  if (rg > max) {
    regiao = "direita";
    max = rg;
  } 
  rg = accumulate(inf.begin(), inf.end(), 0);
  if (rg > max) {
    regiao = "inferior";
    max = rg;
  }
      
  cout << regiao << endl;
  return 0;
}
