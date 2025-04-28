#include <iostream>

// argc tem pra gente a quantidade de argumentos que foram passados na criação
// do processo.
// Já o argv é um array de ponteiros para o primeiro caractere de cada argumento
// (strings)
int main(int argc, char *argv[]) {
  int line;
  int ian_age = 29, hellen_age = 26;
  while (std::cin >> line) {
    if (line == 0)
      break;

    if (line == 98) {
      std::cout << "IAN BIRTHDAY, GO OUT FOR DINNER\n";
      ian_age++;
      continue;
    }

    if (line == 99) {
      std::cout << "HELLEN BIRTHDAY, GO OUT FOR DANCING\n";
      hellen_age++;
      continue;
    }

    int day = line, month;
    std::cin >> month;

    int sum = day + month + ian_age + hellen_age;
    bool is_odd = sum % 2 == 0;

    std::cout << "WATCH ";
    if (is_odd) {
      std::cout << "SERIES";
    } else {
      std::cout << "MOVIE";
    }

    std::cout << '\n';
  }

  return 0;
}
