#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
  int n, idx;
  string p;
  string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string   num = "22233344455566677778889999";

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p;
    for (char c : p) {
      for(idx = 0; alpha[idx] != c; idx++);
      cout << num[idx];
    }
    cout << "\n";
  }

  return 0;
}
