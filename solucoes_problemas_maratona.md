# Soluções de Problemas de Maratona de Programação

Este documento contém soluções para problemas de maratona de programação, organizadas por ano e competição.

## Sumário

- [2021 - InterFatecs](#2021---interfatecs)
- [2022 - InterFatecs](#2022---interfatecs)
- [2023 - InterFatecs](#2023---interfatecs)
- [2024 - InterFatecs](#2024---interfatecs)

## 2021 - InterFatecs

### Anagramas

```cpp
#include<iostream>
#include<map>
using namespace std;
bool Verifica(string subS, string S){
        map <char, int> m;
        map <char, int>::iterator it;
        int i;
        for (i = 0; i < S.length(); i++)
                m[S[i]]++;
        for (i = 0; i < subS.length(); i++)
                m[subS[i]]--;
        for (it = m.begin(); it != m.end(); it++)
                if (it->second != 0)
                        return false;
        return true;
}
int ContaAnagramas(string subS, string S) {
        int cont = 0, i;
        for (i = 0; i < S.length()-subS.length()+1; i++) {
                if (Verifica(S.substr(i, subS.length()), subS))
                        cont++;
        }
        return cont;
}
int main() {
        string S1, S2;
        int NCasos, i;

        cin >> NCasos;
        for (i = 0; i < NCasos; i++) {
    cin >> S1 >> S2;
    if (S2.length() > S1.length())
      cout << "ERRO" << endl;
    else
      cout << ContaAnagramas(S2, S1) << endl;
  }

        return 0;
}
```

## 2022 - InterFatecs

### Movies or Series

```cpp
#include <iostream>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int helenAge = 26;
    int ianAge   = 29;
    int code;
    while (std::cin >> code && code != 0) {
        if (code == 98) {
            std::cout << "IAN BIRTHDAY, GO OUT FOR DINNER\n";
            ++ianAge;
            continue;
        }
        if (code == 99) {
            std::cout << "HELLEN BIRTHDAY, GO OUT FOR DANCING\n";
            ++helenAge;
            continue;
        }
        // aqui code é o 'day'
        int day = code;
        int month;
        std::cin >> month;
        int sum = day + month + helenAge + ianAge;
        if (sum % 2 == 0) {
            std::cout << "WATCH SERIES\n";
        } else {
            std::cout << "WATCH MOVIE\n";
        }
    }
    return 0;
}
```

#### Entrada
```
2
2
5
2
9
2
16
2
25
2
98
1
3
8
3
10
3
19
3
24
3
26
3
2
4
10
4
15
4
99
18
4
23
4
0
```

#### Saída Esperada
```
WATCH MOVIE
WATCH SERIES
WATCH SERIES
WATCH MOVIE
WATCH SERIES
IAN BIRTHDAY, GO OUT FOR DINNER
WATCH SERIES
WATCH MOVIE
WATCH MOVIE
WATCH SERIES
WATCH MOVIE
WATCH MOVIE
WATCH SERIES
WATCH SERIES
WATCH MOVIE
HELLEN BIRTHDAY, GO OUT FOR DANCING
WATCH MOVIE
WATCH SERIES
```

### Golden Number

```cpp
#include <iostream>
#include <iomanip>
double calc(int cur, int max_deep)
{
    if (cur >= max_deep)
        return 1.0;

    return 1.0 + 1.0 / calc(cur + 1, max_deep);
}
void setup_fast_io()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
int main()
{
    setup_fast_io();
    int maxDeep;
    std::cin >> maxDeep;
    if (maxDeep < 0 || maxDeep > 100)
    {
        return 1;
    }
    double result = calc(0, maxDeep);
    std::cout << std::fixed << std::setprecision(15) << result;
}
```

#### Entrada 1
```
1
```

#### Saída Esperada 1
```
2.000000000000000
```

#### Entrada 2
```
2
```

#### Saída Esperada 2
```
1.500000000000000
```

## 2023 - InterFatecs

### Blaittland

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, r, d;
    size_t p;
    string livros, lv_org;
    cin >> n;
    cin >> livros;
    lv_org = livros;
    sort(lv_org.begin(), lv_org.end());
    r = 0;
    for (int i = 0; i < n; i++) {
        if (livros[i] != lv_org[i]) {
            p = lv_org.find(livros[i]);
            d = (p - i);
            if (d > 5) {
                cout << "A Database Systems student read a book." << endl;
                return 0;
            }
            r += d;
            lv_org = lv_org.substr(0, i) + livros[i] + lv_org.substr(i, d) + lv_org.substr(p + 1);
        }
    }
    cout << r << endl;
    return 0;
}
```

#### Entrada 1
```
6
ABCDEF
```

#### Saída Esperada 1
```
0
```

#### Entrada 2
```
12
DFGNMHRQSYVZ
```

#### Saída Esperada 2
```
5
```
