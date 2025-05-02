# C++ STL para Maratonas de Programação - Referência Rápida

## Sumário
1. [Strings](#strings)
2. [Algoritmos](#algoritmos)
3. [Estruturas de Dados](#estruturas-de-dados)
4. [Utilitários](#utilitários)

## Strings

### std::string
```cpp
#include <string>
`
#### Operações Básicas
| Operação | Descrição | Complexidade |
|----------|-----------|--------------|
| `s.size()` ou `s.length()` | Retorna o tamanho da string | O(1) |
| `s.empty()` | Verifica se a string está vazia | O(1) |
| `s.clear()` | Limpa a string | O(1) |
| `s.substr(pos, len)` | Retorna uma substring começando em `pos` com tamanho `len` | O(len) |
| `s.find(str, pos)` | Encontra a primeira ocorrência de `str` a partir da posição `pos` | O(n*m) |
| `s.rfind(str, pos)` | Encontra a última ocorrência de `str` antes da posição `pos` | O(n*m) |
| `s.replace(pos, len, str)` | Substitui `len` caracteres a partir de `pos` por `str` | O(n) |
| `s.insert(pos, str)` | Insere `str` na posição `pos` | O(n) |
| `s.erase(pos, len)` | Remove `len` caracteres a partir de `pos` | O(n) |
| `s.push_back(c)` | Adiciona o caractere `c` ao final | Amortizado O(1) |
| `s.pop_back()` | Remove o último caractere | O(1) |
| `s + t` | Concatena as strings `s` e `t` | O(n+m) |
| `s == t`, `s != t`, `s < t`, etc. | Comparações lexicográficas | O(min(n,m)) |

#### Conversões
```cpp
// String para número
int i = stoi(s);       // string para int
long l = stol(s);      // string para long
long long ll = stoll(s); // string para long long
float f = stof(s);     // string para float
double d = stod(s);    // string para double

// Número para string
string s = to_string(42);  // int para string
string s = to_string(3.14); // double para string
```

#### Exemplo
```cpp
string s = "maratona";
string t = "de programação";
string u = s + " " + t;  // "maratona de programação"

if (s < t) {  // Comparação lexicográfica
    // s vem antes de t no dicionário
}

string sub = u.substr(0, 8);  // "maratona"
size_t pos = u.find("de");    // 9
u.replace(9, 2, "DE");        // "maratona DE programação"
```

### Manipulação de Caracteres
```cpp
#include <cctype>
```

| Função | Descrição |
|--------|-----------|
| `isalpha(c)` | Verifica se `c` é uma letra |
| `isdigit(c)` | Verifica se `c` é um dígito |
| `isalnum(c)` | Verifica se `c` é alfanumérico |
| `islower(c)` | Verifica se `c` é minúsculo |
| `isupper(c)` | Verifica se `c` é maiúsculo |
| `isspace(c)` | Verifica se `c` é um espaço em branco |
| `tolower(c)` | Converte `c` para minúsculo |
| `toupper(c)` | Converte `c` para maiúsculo |

## Algoritmos

```cpp
#include <algorithm>
```

### Ordenação e Busca
| Algoritmo | Descrição | Complexidade |
|-----------|-----------|--------------|
| `sort(begin, end)` | Ordena o intervalo [begin, end) | O(n log n) |
| `sort(begin, end, comp)` | Ordena usando o comparador `comp` | O(n log n) |
| `stable_sort(begin, end)` | Ordenação estável | O(n log n) |
| `partial_sort(begin, middle, end)` | Ordena parcialmente até `middle` | O(n log m) |
| `binary_search(begin, end, value)` | Verifica se `value` existe no intervalo ordenado | O(log n) |
| `lower_bound(begin, end, value)` | Retorna iterator para o primeiro elemento >= `value` | O(log n) |
| `upper_bound(begin, end, value)` | Retorna iterator para o primeiro elemento > `value` | O(log n) |
| `equal_range(begin, end, value)` | Retorna par de iterators [lower_bound, upper_bound] | O(log n) |

### Operações em Intervalos
| Algoritmo | Descrição | Complexidade |
|-----------|-----------|--------------|
| `min_element(begin, end)` | Retorna iterator para o menor elemento | O(n) |
| `max_element(begin, end)` | Retorna iterator para o maior elemento | O(n) |
| `minmax_element(begin, end)` | Retorna par de iterators para o menor e maior elementos | O(n) |
| `count(begin, end, value)` | Conta ocorrências de `value` | O(n) |
| `count_if(begin, end, pred)` | Conta elementos que satisfazem o predicado `pred` | O(n) |
| `find(begin, end, value)` | Encontra a primeira ocorrência de `value` | O(n) |
| `find_if(begin, end, pred)` | Encontra o primeiro elemento que satisfaz o predicado `pred` | O(n) |
| `all_of(begin, end, pred)` | Verifica se todos os elementos satisfazem o predicado `pred` | O(n) |
| `any_of(begin, end, pred)` | Verifica se algum elemento satisfaz o predicado `pred` | O(n) |
| `none_of(begin, end, pred)` | Verifica se nenhum elemento satisfaz o predicado `pred` | O(n) |
| `for_each(begin, end, func)` | Aplica a função `func` a cada elemento | O(n) |
| `transform(begin, end, out, func)` | Aplica `func` a cada elemento e armazena em `out` | O(n) |
| `copy(begin, end, out)` | Copia elementos para `out` | O(n) |
| `move(begin, end, out)` | Move elementos para `out` | O(n) |
| `fill(begin, end, value)` | Preenche o intervalo com `value` | O(n) |
| `generate(begin, end, gen)` | Preenche o intervalo com valores gerados por `gen` | O(n) |
| `remove(begin, end, value)` | Remove ocorrências de `value` | O(n) |
| `remove_if(begin, end, pred)` | Remove elementos que satisfazem o predicado `pred` | O(n) |
| `replace(begin, end, old, new)` | Substitui `old` por `new` | O(n) |
| `replace_if(begin, end, pred, new)` | Substitui elementos que satisfazem `pred` por `new` | O(n) |
| `reverse(begin, end)` | Inverte a ordem dos elementos | O(n) |
| `rotate(begin, middle, end)` | Rotaciona os elementos (coloca `middle` no início) | O(n) |
| `shuffle(begin, end, g)` | Embaralha os elementos usando o gerador `g` | O(n) |
| `unique(begin, end)` | Remove elementos duplicados consecutivos | O(n) |

### Operações em Conjuntos Ordenados
| Algoritmo | Descrição | Complexidade |
|-----------|-----------|--------------|
| `merge(begin1, end1, begin2, end2, out)` | Mescla dois intervalos ordenados | O(n+m) |
| `set_union(begin1, end1, begin2, end2, out)` | União de conjuntos ordenados | O(n+m) |
| `set_intersection(begin1, end1, begin2, end2, out)` | Interseção de conjuntos ordenados | O(n+m) |
| `set_difference(begin1, end1, begin2, end2, out)` | Diferença de conjuntos ordenados | O(n+m) |
| `set_symmetric_difference(begin1, end1, begin2, end2, out)` | Diferença simétrica | O(n+m) |
| `includes(begin1, end1, begin2, end2)` | Verifica se o primeiro conjunto inclui o segundo | O(n+m) |

### Heaps
| Algoritmo | Descrição | Complexidade |
|-----------|-----------|--------------|
| `make_heap(begin, end)` | Transforma o intervalo em um heap | O(n) |
| `push_heap(begin, end)` | Adiciona o último elemento ao heap | O(log n) |
| `pop_heap(begin, end)` | Move o maior elemento para o final | O(log n) |
| `sort_heap(begin, end)` | Ordena um heap | O(n log n) |
| `is_heap(begin, end)` | Verifica se o intervalo é um heap | O(n) |

### Exemplo
```cpp
vector<int> v = {5, 2, 8, 1, 9, 3};

// Ordenação
sort(v.begin(), v.end());  // {1, 2, 3, 5, 8, 9}

// Ordenação personalizada
sort(v.begin(), v.end(), greater<int>());  // {9, 8, 5, 3, 2, 1}

// Busca binária
bool found = binary_search(v.begin(), v.end(), 5);  // true

// Encontrar elementos
auto min_it = min_element(v.begin(), v.end());  // Aponta para 1
auto max_it = max_element(v.begin(), v.end());  // Aponta para 9

// Contagem
int count_greater_than_5 = count_if(v.begin(), v.end(), [](int x) { return x > 5; });  // 2

// Transformação
vector<int> squared(v.size());
transform(v.begin(), v.end(), squared.begin(), [](int x) { return x * x; });
```

## Estruturas de Dados

### std::vector
```cpp
#include <vector>
```

#### Operações
| Operação | Descrição | Complexidade |
|----------|-----------|--------------|
| `v.push_back(x)` | Adiciona `x` ao final | Amortizado O(1) |
| `v.pop_back()` | Remove o último elemento | O(1) |
| `v.size()` | Retorna o tamanho | O(1) |
| `v.empty()` | Verifica se está vazio | O(1) |
| `v.clear()` | Remove todos os elementos | O(n) |
| `v.resize(n)` | Redimensiona para tamanho `n` | O(n) |
| `v.reserve(n)` | Reserva espaço para `n` elementos | O(n) |
| `v.front()` | Retorna o primeiro elemento | O(1) |
| `v.back()` | Retorna o último elemento | O(1) |
| `v[i]` | Acessa o elemento no índice `i` | O(1) |
| `v.at(i)` | Acessa o elemento no índice `i` com verificação de limites | O(1) |
| `v.insert(pos, x)` | Insere `x` na posição `pos` | O(n) |
| `v.erase(pos)` | Remove o elemento na posição `pos` | O(n) |
| `v.assign(n, x)` | Atribui `n` cópias de `x` | O(n) |

#### Exemplo
```cpp
vector<int> v;
v.push_back(10);  // {10}
v.push_back(20);  // {10, 20}
v.push_back(30);  // {10, 20, 30}

int x = v[1];     // x = 20
v[0] = 5;         // {5, 20, 30}

v.pop_back();     // {5, 20}
v.insert(v.begin() + 1, 15);  // {5, 15, 20}
v.erase(v.begin());  // {15, 20}

// Inicialização
vector<int> v1 = {1, 2, 3, 4, 5};
vector<int> v2(10, 0);  // 10 zeros
vector<int> v3(v1.begin() + 1, v1.end() - 1);  // {2, 3, 4}
```

### std::pair e std::tuple
```cpp
#include <utility>  // para pair
#include <tuple>    // para tuple
```

#### Operações
| Operação | Descrição |
|----------|-----------|
| `make_pair(a, b)` | Cria um par com valores `a` e `b` |
| `p.first` | Acessa o primeiro elemento do par |
| `p.second` | Acessa o segundo elemento do par |
| `make_tuple(a, b, c, ...)` | Cria uma tupla |
| `get<i>(t)` | Acessa o i-ésimo elemento da tupla |
| `tie(a, b, c, ...) = t` | Desempacota a tupla em variáveis |

#### Exemplo
```cpp
pair<int, string> p = make_pair(42, "resposta");
int x = p.first;      // 42
string s = p.second;  // "resposta"

// Inicialização com chaves
pair<int, double> p2 = {1, 3.14};

// Comparação lexicográfica
pair<int, int> p3 = {1, 2};
pair<int, int> p4 = {1, 3};
bool b = p3 < p4;  // true

// Tuplas
tuple<int, string, double> t = make_tuple(42, "resposta", 3.14);
int a = get<0>(t);       // 42
string b = get<1>(t);    // "resposta"
double c = get<2>(t);    // 3.14

// Desempacotando
int x;
string y;
double z;
tie(x, y, z) = t;
```

### std::array
```cpp
#include <array>
```

#### Operações
| Operação | Descrição | Complexidade |
|----------|-----------|--------------|
| `a.size()` | Retorna o tamanho | O(1) |
| `a.empty()` | Verifica se está vazio | O(1) |
| `a.front()` | Retorna o primeiro elemento | O(1) |
| `a.back()` | Retorna o último elemento | O(1) |
| `a[i]` | Acessa o elemento no índice `i` | O(1) |
| `a.at(i)` | Acessa o elemento no índice `i` com verificação de limites | O(1) |
| `a.fill(x)` | Preenche o array com `x` | O(n) |
| `a.swap(b)` | Troca o conteúdo com `b` | O(n) |

#### Exemplo
```cpp
array<int, 5> a = {1, 2, 3, 4, 5};
int x = a[2];  // 3
a[0] = 10;     // {10, 2, 3, 4, 5}

a.fill(0);     // {0, 0, 0, 0, 0}
```

### std::deque
```cpp
#include <deque>
```

#### Operações
| Operação | Descrição | Complexidade |
|----------|-----------|--------------|
| `d.push_back(x)` | Adiciona `x` ao final | Amortizado O(1) |
| `d.push_front(x)` | Adiciona `x` ao início | Amortizado O(1) |
| `d.pop_back()` | Remove o último elemento | O(1) |
| `d.pop_front()` | Remove o primeiro elemento | O(1) |
| `d.size()` | Retorna o tamanho | O(1) |
| `d.empty()` | Verifica se está vazio | O(1) |
| `d.clear()` | Remove todos os elementos | O(n) |
| `d.front()` | Retorna o primeiro elemento | O(1) |
| `d.back()` | Retorna o último elemento | O(1) |
| `d[i]` | Acessa o elemento no índice `i` | O(1) |
| `d.at(i)` | Acessa o elemento no índice `i` com verificação de limites | O(1) |
| `d.insert(pos, x)` | Insere `x` na posição `pos` | O(n) |
| `d.erase(pos)` | Remove o elemento na posição `pos` | O(n) |

#### Exemplo
```cpp
deque<int> d;
d.push_back(10);   // {10}
d.push_front(5);   // {5, 10}
d.push_back(15);   // {5, 10, 15}

int x = d[1];      // x = 10
d.pop_front();     // {10, 15}
d.pop_back();      // {10}
```

### std::list e std::forward_list
```cpp
#include <list>         // lista duplamente ligada
#include <forward_list> // lista simplesmente ligada
```

#### Operações de std::list
| Operação | Descrição | Complexidade |
|----------|-----------|--------------|
| `l.push_back(x)` | Adiciona `x` ao final | O(1) |
| `l.push_front(x)` | Adiciona `x` ao início | O(1) |
| `l.pop_back()` | Remove o último elemento | O(1) |
| `l.pop_front()` | Remove o primeiro elemento | O(1) |
| `l.size()` | Retorna o tamanho | O(1) |
| `l.empty()` | Verifica se está vazio | O(1) |
| `l.clear()` | Remove todos os elementos | O(n) |
| `l.front()` | Retorna o primeiro elemento | O(1) |
| `l.back()` | Retorna o último elemento | O(1) |
| `l.insert(pos, x)` | Insere `x` na posição `pos` | O(1) |
| `l.erase(pos)` | Remove o elemento na posição `pos` | O(1) |
| `l.splice(pos, l2)` | Move elementos de `l2` para `l` na posição `pos` | O(1) |
| `l.remove(val)` | Remove todos os elementos com valor `val` | O(n) |
| `l.remove_if(pred)` | Remove elementos que satisfazem o predicado `pred` | O(n) |
| `l.unique()` | Remove elementos duplicados consecutivos | O(n) |
| `l.merge(l2)` | Mescla duas listas ordenadas | O(n) |
| `l.sort()` | Ordena a lista | O(n log n) |
| `l.reverse()` | Inverte a ordem dos elementos | O(n) |

#### Exemplo
```cpp
list<int> l = {1, 2, 3};
l.push_back(4);    // {1, 2, 3, 4}
l.push_front(0);   // {0, 1, 2, 3, 4}

auto it = next(l.begin(), 2);  // Aponta para o elemento 2
l.insert(it, 10);  // {0, 1, 10, 2, 3, 4}
l.erase(it);       // {0, 1, 10, 3, 4}

l.remove(10);      // {0, 1, 3, 4}
l.sort(greater<int>());  // {4, 3, 1, 0}
```

### std::set e std::multiset
```cpp
#include <set>
```

#### Operações
| Operação | Descrição | Complexidade |
|----------|-----------|--------------|
| `s.insert(x)` | Insere `x` | O(log n) |
| `s.erase(x)` | Remove `x` | O(log n) |
| `s.erase(it)` | Remove o elemento apontado por `it` | O(1) |
| `s.find(x)` | Retorna iterator para `x` ou `s.end()` se não encontrado | O(log n) |
| `s.count(x)` | Conta ocorrências de `x` | O(log n) + O(count) |
| `s.lower_bound(x)` | Retorna iterator para o primeiro elemento >= `x` | O(log n) |
| `s.upper_bound(x)` | Retorna iterator para o primeiro elemento > `x` | O(log n) |
| `s.equal_range(x)` | Retorna par de iterators [lower_bound, upper_bound] | O(log n) |
| `s.size()` | Retorna o tamanho | O(1) |
| `s.empty()` | Verifica se está vazio | O(1) |
| `s.clear()` | Remove todos os elementos | O(n) |

#### Exemplo
```cpp
set<int> s = {5, 2, 8, 1, 9, 3};  // Armazenado como {1, 2, 3, 5, 8, 9}

s.insert(4);  // {1, 2, 3, 4, 5, 8, 9}
s.erase(2);   // {1, 3, 4, 5, 8, 9}

auto it = s.find(5);  // Aponta para 5
if (it != s.end()) {
    // 5 está no conjunto
}

bool contains = s.count(7) > 0;  // false

auto it_lower = s.lower_bound(4);  // Aponta para 4
auto it_upper = s.upper_bound(4);  // Aponta para 5

// multiset permite elementos duplicados
multiset<int> ms = {1, 3, 3, 7, 7, 7, 9};
int count_7 = ms.count(7);  // 3
```

### std::map e std::multimap
```cpp
#include <map>
```

#### Operações
| Operação | Descrição | Complexidade |
|----------|-----------|--------------|
| `m[key] = value` | Insere ou atualiza o valor associado à chave | O(log n) |
| `m.at(key)` | Acessa o valor associado à chave (lança exceção se não existir) | O(log n) |
| `m.insert({key, value})` | Insere um par chave-valor | O(log n) |
| `m.erase(key)` | Remove o par com a chave especificada | O(log n) |
| `m.erase(it)` | Remove o par apontado por `it` | O(1) |
| `m.find(key)` | Retorna iterator para o par com a chave ou `m.end()` se não encontrado | O(log n) |
| `m.count(key)` | Conta ocorrências da chave | O(log n) + O(count) |
| `m.lower_bound(key)` | Retorna iterator para o primeiro par com chave >= `key` | O(log n) |
| `m.upper_bound(key)` | Retorna iterator para o primeiro par com chave > `key` | O(log n) |
| `m.equal_range(key)` | Retorna par de iterators [lower_bound, upper_bound] | O(log n) |
| `m.size()` | Retorna o tamanho | O(1) |
| `m.empty()` | Verifica se está vazio | O(1) |
| `m.clear()` | Remove todos os elementos | O(n) |

#### Exemplo
```cpp
map<string, int> m;
m["um"] = 1;
m["dois"] = 2;
m["três"] = 3;

int x = m["dois"];  // x = 2

// Verificar se uma chave existe
if (m.find("quatro") != m.end()) {
    // A chave "quatro" existe
}

// Iterando sobre um map
for (const auto& [key, value] : m) {
    cout << key << ": " << value << endl;
}

// multimap permite chaves duplicadas
multimap<string, int> mm;
mm.insert({"a", 1});
mm.insert({"a", 2});
mm.insert({"b", 3});

// Encontrando todos os valores para uma chave
auto [begin, end] = mm.equal_range("a");
for (auto it = begin; it != end; ++it) {
    cout << it->second << endl;  // Imprime 1, 2
}
```

### std::unordered_set e std::unordered_multiset
```cpp
#include <unordered_set>
```

#### Operações
| Operação | Descrição | Complexidade |
|----------|-----------|--------------|
| `s.insert(x)` | Insere `x` | Média O(1), pior O(n) |
| `s.erase(x)` | Remove `x` | Média O(1), pior O(n) |
| `s.erase(it)` | Remove o elemento apontado por `it` | Média O(1) |
| `s.find(x)` | Retorna iterator para `x` ou `s.end()` se não encontrado | Média O(1), pior O(n) |
| `s.count(x)` | Conta ocorrências de `x` | Média O(1), pior O(n) |
| `s.size()` | Retorna o tamanho | O(1) |
| `s.empty()` | Verifica se está vazio | O(1) |
| `s.clear()` | Remove todos os elementos | O(n) |
| `s.bucket_count()` | Retorna o número de buckets | O(1) |
| `s.load_factor()` | Retorna o fator de carga | O(1) |
| `s.rehash(n)` | Define o número mínimo de buckets como `n` | O(n) |
| `s.reserve(n)` | Reserva espaço para `n` elementos | O(n) |

#### Exemplo
```cpp
unordered_set<int> s = {5, 2, 8, 1, 9, 3};  // Ordem não garantida

s.insert(4);
s.erase(2);

auto it = s.find(5);
if (it != s.end()) {
    // 5 está no conjunto
}

bool contains = s.count(7) > 0;  // false

// unordered_multiset permite elementos duplicados
unordered_multiset<int> ms = {1, 3, 3, 7, 7, 7, 9};
int count_7 = ms.count(7);  // 3
```

### std::unordered_map e std::unordered_multimap
```cpp
#include <unordered_map>
```

#### Operações
| Operação | Descrição | Complexidade |
|----------|-----------|--------------|
| `m[key] = value` | Insere ou atualiza o valor associado à chave | Média O(1), pior O(n) |
| `m.at(key)` | Acessa o valor associado à chave (lança exceção se não existir) | Média O(1), pior O(n) |
| `m.insert({key, value})` | Insere um par chave-valor | Média O(1), pior O(n) |
| `m.erase(key)` | Remove o par com a chave especificada | Média O(1), pior O(n) |
| `m.erase(it)` | Remove o par apontado por `it` | Média O(1) |
| `m.find(key)` | Retorna iterator para o par com a chave ou `m.end()` se não encontrado | Média O(1), pior O(n) |
| `m.count(key)` | Conta ocorrências da chave | Média O(1), pior O(n) |
| `m.size()` | Retorna o tamanho | O(1) |
| `m.empty()` | Verifica se está vazio | O(1) |
| `m.clear()` | Remove todos os elementos | O(n) |
| `m.bucket_count()` | Retorna o número de buckets | O(1) |
| `m.load_factor()` | Retorna o fator de carga | O(1) |
| `m.rehash(n)` | Define o número mínimo de buckets como `n` | O(n) |
| `m.reserve(n)` | Reserva espaço para `n` elementos | O(n) |

#### Exemplo
```cpp
unordered_map<string, int> m;
m["um"] = 1;
m["dois"] = 2;
m["três"] = 3;

int x = m["dois"];  // x = 2

// Verificar se uma chave existe
if (m.find("quatro") != m.end()) {
    // A chave "quatro" existe
}

// Iterando sobre um map
for (const auto& [key, value] : m) {
    cout << key << ": " << value << endl;
}

// unordered_multimap permite chaves duplicadas
unordered_multimap<string, int> mm;
mm.insert({"a", 1});
mm.insert({"a", 2});
mm.insert({"b", 3});

// Encontrando todos os valores para uma chave
auto [begin, end] = mm.equal_range("a");
for (auto it = begin; it != end; ++it) {
    cout << it->second << endl;  // Imprime 1, 2
}
```

### std::stack
```cpp
#include <stack>
```

#### Operações
| Operação | Descrição | Complexidade |
|----------|-----------|--------------|
| `s.push(x)` | Adiciona `x` ao topo | O(1) |
| `s.pop()` | Remove o elemento do topo | O(1) |
| `s.top()` | Acessa o elemento do topo | O(1) |
| `s.size()` | Retorna o tamanho | O(1) |
| `s.empty()` | Verifica se está vazio | O(1) |

#### Exemplo
```cpp
stack<int> s;
s.push(1);  // [1]
s.push(2);  // [1, 2]
s.push(3);  // [1, 2, 3]

int x = s.top();  // x = 3
s.pop();          // [1, 2]
```

### std::queue
```cpp
#include <queue>
```

#### Operações
| Operação | Descrição | Complexidade |
|----------|-----------|--------------|
| `q.push(x)` | Adiciona `x` ao final | O(1) |
| `q.pop()` | Remove o elemento do início | O(1) |
| `q.front()` | Acessa o elemento do início | O(1) |
| `q.back()` | Acessa o elemento do final | O(1) |
| `q.size()` | Retorna o tamanho | O(1) |
| `q.empty()` | Verifica se está vazio | O(1) |

#### Exemplo
```cpp
queue<int> q;
q.push(1);  // [1]
q.push(2);  // [1, 2]
q.push(3);  // [1, 2, 3]

int x = q.front();  // x = 1
q.pop();            // [2, 3]
```

### std::priority_queue
```cpp
#include <queue>
```

#### Operações
| Operação | Descrição | Complexidade |
|----------|-----------|--------------|
| `pq.push(x)` | Adiciona `x` | O(log n) |
| `pq.pop()` | Remove o elemento de maior prioridade | O(log n) |
| `pq.top()` | Acessa o elemento de maior prioridade | O(1) |
| `pq.size()` | Retorna o tamanho | O(1) |
| `pq.empty()` | Verifica se está vazio | O(1) |

#### Exemplo
```cpp
// Max heap (padrão)
priority_queue<int> pq;
pq.push(3);  // [3]
pq.push(1);  // [3, 1]
pq.push(4);  // [4, 3, 1]

int x = pq.top();  // x = 4
pq.pop();          // [3, 1]

// Min heap
priority_queue<int, vector<int>, greater<int>> min_pq;
min_pq.push(3);  // [3]
min_pq.push(1);  // [1, 3]
min_pq.push(4);  // [1, 3, 4]

int y = min_pq.top();  // y = 1
```

### std::bitset
```cpp
#include <bitset>
```

#### Operações
| Operação | Descrição | Complexidade |
|----------|-----------|--------------|
| `b.set()` | Define todos os bits como 1 | O(n) |
| `b.set(pos)` | Define o bit na posição `pos` como 1 | O(1) |
| `b.reset()` | Define todos os bits como 0 | O(n) |
| `b.reset(pos)` | Define o bit na posição `pos` como 0 | O(1) |
| `b.flip()` | Inverte todos os bits | O(n) |
| `b.flip(pos)` | Inverte o bit na posição `pos` | O(1) |
| `b.test(pos)` | Verifica se o bit na posição `pos` é 1 | O(1) |
| `b.any()` | Verifica se algum bit é 1 | O(n) |
| `b.all()` | Verifica se todos os bits são 1 | O(n) |
| `b.none()` | Verifica se nenhum bit é 1 | O(n) |
| `b.count()` | Conta o número de bits 1 | O(n) |
| `b.size()` | Retorna o tamanho | O(1) |
| `b[pos]` | Acessa o bit na posição `pos` | O(1) |
| `b.to_ulong()` | Converte para unsigned long | O(n) |
| `b.to_string()` | Converte para string | O(n) |

#### Exemplo
```cpp
bitset<8> b("10101010");  // 10101010
bitset<8> c(42);          // 00101010

b.set(1);      // 10101110
c.reset(5);    // 00001010
b.flip();      // 01010001

bool bit = b.test(3);  // bit = 0
int count = c.count(); // count = 3

// Operações bit a bit
bitset<8> d = b & c;   // AND
bitset<8> e = b | c;   // OR
bitset<8> f = b ^ c;   // XOR
bitset<8> g = ~b;      // NOT
bitset<8> h = b << 2;  // Shift left
bitset<8> i = c >> 1;  // Shift right
```

## Utilitários

### Entrada e Saída
```cpp
#include <iostream>
#include <iomanip>
```

#### Operações Básicas
```cpp
// Entrada
int a;
double b;
string s;
cin >> a >> b >> s;

// Saída
cout << "a = " << a << ", b = " << b << ", s = " << s << endl;

// Formatação
cout << fixed << setprecision(2) << 3.14159;  // 3.14
cout << scientific << 3.14159;                // 3.141590e+00
cout << hex << 42;                            // 2a
cout << oct << 42;                            // 52
cout << dec << 42;                            // 42
cout << setw(10) << setfill('0') << 42;       // 0000000042
cout << boolalpha << true;                    // true
```

### Leitura de Arquivos
```cpp
#include <fstream>
```

#### Exemplo
```cpp
// Leitura
ifstream fin("input.txt");
int a;
string s;
fin >> a >> s;
fin.close();

// Escrita
ofstream fout("output.txt");
fout << "Resultado: " << 42 << endl;
fout.close();
```

### Manipulação de Strings Avançada
```cpp
#include <sstream>
#include <regex>
```

#### Exemplo com stringstream
```cpp
// Conversão de string para números
string s = "42 3.14 hello";
istringstream iss(s);
int i;
double d;
string word;
iss >> i >> d >> word;  // i = 42, d = 3.14, word = "hello"

// Construção de string
ostringstream oss;
oss << "i = " << i << ", d = " << d << ", word = " << word;
string result = oss.str();  // "i = 42, d = 3.14, word = hello"
```

#### Exemplo com regex
```cpp
string text = "Email: user@example.com e outro: test@test.org";
regex pattern(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}\b)");

// Encontrar todas as correspondências
sregex_iterator it(text.begin(), text.end(), pattern);
sregex_iterator end;
while (it != end) {
    cout << it->str() << endl;  // Imprime "user@example.com", "test@test.org"
    ++it;
}

// Substituição
string result = regex_replace(text, pattern, "[EMAIL]");
// result = "Email: [EMAIL] e outro: [EMAIL]"
```

### Números Aleatórios
```cpp
#include <random>
```

#### Exemplo
```cpp
// Gerador de números aleatórios
random_device rd;  // Fonte de entropia
mt19937 gen(rd()); // Gerador Mersenne Twister

// Distribuição uniforme de inteiros
uniform_int_distribution<int> dist_int(1, 6);  // Números de 1 a 6
int dice_roll = dist_int(gen);

// Distribuição uniforme de reais
uniform_real_distribution<double> dist_real(0.0, 1.0);  // Números de 0.0 a 1.0
double random_prob = dist_real(gen);

// Distribuição normal
normal_distribution<double> dist_normal(0.0, 1.0);  // Média 0.0, desvio padrão 1.0
double normal_value = dist_normal(gen);
```

### Manipulação de Data e Hora
```cpp
#include <chrono>
```

#### Exemplo
```cpp
using namespace std::chrono;

// Obter o tempo atual
auto now = system_clock::now();

// Medir o tempo de execução
auto start = high_resolution_clock::now();
// ... código a ser medido ...
auto end = high_resolution_clock::now();
auto duration = duration_cast<milliseconds>(end - start);
cout << "Tempo de execução: " << duration.count() << " ms" << endl;

// Conversão para time_t
time_t current_time = system_clock::to_time_t(now);
cout << "Data e hora atual: " << ctime(&current_time);
```

### Matemática
```cpp
#include <cmath>
#include <numeric>
```

#### Funções Matemáticas Comuns
| Função | Descrição |
|--------|-----------|
| `abs(x)` | Valor absoluto |
| `sqrt(x)` | Raiz quadrada |
| `pow(x, y)` | x elevado a y |
| `exp(x)` | e elevado a x |
| `log(x)` | Logaritmo natural |
| `log10(x)` | Logaritmo na base 10 |
| `sin(x)`, `cos(x)`, `tan(x)` | Funções trigonométricas |
| `asin(x)`, `acos(x)`, `atan(x)` | Funções trigonométricas inversas |
| `floor(x)` | Arredonda para baixo |
| `ceil(x)` | Arredonda para cima |
| `round(x)` | Arredonda para o inteiro mais próximo |
| `max(a, b)` | Retorna o maior valor |
| `min(a, b)` | Retorna o menor valor |

#### Funções Numéricas
| Função | Descrição |
|--------|-----------|
| `gcd(a, b)` | Máximo divisor comum |
| `lcm(a, b)` | Mínimo múltiplo comum |
| `accumulate(begin, end, init)` | Soma os elementos |
| `accumulate(begin, end, init, op)` | Combina os elementos usando a operação `op` |
| `iota(begin, end, value)` | Preenche com valores incrementais a partir de `value` |
| `partial_sum(begin, end, out)` | Calcula as somas parciais |
| `adjacent_difference(begin, end, out)` | Calcula as diferenças entre elementos adjacentes |

#### Exemplo
```cpp
// Funções matemáticas
double x = abs(-3.14);       // 3.14
double y = sqrt(16);         // 4.0
double z = pow(2, 3);        // 8.0
double w = log(exp(1.0));    // 1.0

// Funções numéricas
int a = gcd(12, 18);         // 6
int b = lcm(12, 18);         // 36

vector<int> v = {1, 2, 3, 4, 5};
int sum = accumulate(v.begin(), v.end(), 0);  // 15

// Produto de todos os elementos
int product = accumulate(v.begin(), v.end(), 1, multiplies<int>());  // 120

// Preenchimento com valores incrementais
vector<int> seq(5);
iota(seq.begin(), seq.end(), 10);  // {10, 11, 12, 13, 14}

// Somas parciais
vector<int> partial(5);
partial_sum(v.begin(), v.end(), partial.begin());  // {1, 3, 6, 10, 15}
```

### Limites Numéricos
```cpp
#include <limits>
```

#### Exemplo
```cpp
// Valores mínimos e máximos para tipos numéricos
int min_int = numeric_limits<int>::min();          // -2147483648
int max_int = numeric_limits<int>::max();          // 2147483647
double min_double = numeric_limits<double>::min(); // Menor valor positivo
double max_double = numeric_limits<double>::max(); // Maior valor finito
double inf = numeric_limits<double>::infinity();   // Infinito

// Constantes especiais
double epsilon = numeric_limits<double>::epsilon(); // Menor diferença representável
bool is_signed = numeric_limits<int>::is_signed;    // true
int digits = numeric_limits<int>::digits;           // Número de dígitos binários
```
