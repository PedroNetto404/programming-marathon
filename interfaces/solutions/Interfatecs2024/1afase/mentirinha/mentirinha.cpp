#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
  int n, d;

  cin >> n;
  if (n <= 2)
    cout << "nao\n";
  else {
    d = 0;
    for (int i = 2; i <= n/2; i++) {
      if (n % i == 0) {
        d++;
        if (d > 1) {
          cout << "nao\n";
          return 0;
        }
      }
    }
    if (d == 1)
      cout << "sim\n";
    else 
      cout << "nao\n";
  }

  return 0;
}
