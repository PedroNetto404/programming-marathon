#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>

using namespace std;

bool range_isdigit(string placa, int a, int b) {
    int i = a;
    if (a == b)
      return false;
    while(i < b and isdigit(placa[i])) 
      i++;
    return i == b;
}

bool range_isalpha(string placa, int a, int b) {
    int i = a;
    if (a == b)
      return false;
    while(i < b and isalpha(placa[i])) 
      i++;
    return i == b;
}

int main() {
  string placa;

  cin >> placa;
  if (placa.size() <= 6 and (placa[0] == 'A' or placa[0] == 'P') and range_isdigit(placa, 1, placa.size())) 
    cout << "Placa muito antiga\n";
  else if (placa.size() <= 7 and range_isdigit(placa, 0, placa.size())) 
    cout << "Placa numerica\n";
  else if (placa.size() == 6 and range_isalpha(placa, 0, 2) and range_isdigit(placa, 2, placa.size()))
    cout << "Placa AA-9999\n";
  else if (placa.size() == 7 and range_isalpha(placa, 0, 3) and range_isdigit(placa, 3, placa.size()))
    cout << "Placa AAA-9999\n";
  else if (placa.size() == 7 and range_isalpha(placa, 0, 3) and isdigit(placa[3]) 
      and isalpha(placa[4]) and range_isdigit(placa, 5, placa.size()))
    cout << "Placa Mercosul\n";
  else
    cout << "Placa invalida\n";

  return 0;
}
