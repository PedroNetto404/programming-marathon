# Guia de Estruturas de Dados em C++ para Maratonas de Programação

## Sumário
1. [Introdução](#introdução)
2. [Estruturas de Dados Fundamentais](#estruturas-de-dados-fundamentais)
3. [Estruturas de Dados Avançadas](#estruturas-de-dados-avançadas)
4. [Estruturas de Dados Especializadas](#estruturas-de-dados-especializadas)
5. [Técnicas de Otimização](#técnicas-de-otimização)
6. [Aplicações em Problemas Comuns](#aplicações-em-problemas-comuns)
7. [Considerações de Desempenho](#considerações-de-desempenho)
8. [Dicas e Truques](#dicas-e-truques)
9. [Referências](#referências)

## Introdução

As estruturas de dados são componentes fundamentais para a resolução eficiente de problemas em maratonas de programação. A escolha da estrutura de dados correta pode ser a diferença entre uma solução que excede o limite de tempo e uma que resolve o problema rapidamente.

Este guia apresenta as principais estruturas de dados disponíveis na biblioteca padrão do C++ (STL), bem como implementações personalizadas úteis para competições como a InterFatecs. Para cada estrutura, discutiremos suas características, operações principais, complexidade de tempo, e situações em que são mais adequadas.

## Estruturas de Dados Fundamentais

### Arrays e Vetores

#### std::vector

O `vector` é uma das estruturas de dados mais versáteis e frequentemente utilizadas em competições de programação. Ele funciona como um array dinâmico que pode crescer automaticamente.

```cpp
#include <vector>
using namespace std;

// Inicialização
vector<int> v1;                    // Vetor vazio
vector<int> v2(5);                 // Vetor com 5 elementos inicializados com 0
vector<int> v3(5, 10);             // Vetor com 5 elementos inicializados com 10
vector<int> v4 = {1, 2, 3, 4, 5};  // Inicialização com lista

// Acesso e modificação
v4[0] = 10;                        // Acesso direto (sem verificação de limites)
v4.at(1) = 20;                     // Acesso com verificação de limites
int primeiro = v4.front();         // Primeiro elemento
int ultimo = v4.back();            // Último elemento

// Tamanho e capacidade
size_t tamanho = v4.size();        // Número de elementos
bool vazio = v4.empty();           // Verifica se está vazio
v4.resize(10);                     // Redimensiona para 10 elementos
v4.reserve(20);                    // Reserva espaço para 20 elementos

// Adição e remoção
v4.push_back(6);                   // Adiciona elemento ao final
v4.pop_back();                     // Remove o último elemento
v4.insert(v4.begin() + 2, 15);     // Insere 15 na posição 2
v4.erase(v4.begin() + 3);          // Remove elemento na posição 3
v4.clear();                        // Remove todos os elementos
```

**Complexidade de Tempo:**
- Acesso: O(1)
- Inserção/remoção no final: Amortizado O(1)
- Inserção/remoção no meio: O(n)
- Busca: O(n) para busca linear

**Quando Usar:**
- Quando você precisa de um array dinâmico que pode crescer
- Quando o acesso aleatório é frequente
- Quando as operações principais são no final do array

#### std::array

Para arrays de tamanho fixo, o `std::array` oferece uma alternativa mais segura aos arrays C tradicionais.

```cpp
#include <array>
using namespace std;

// Inicialização
array<int, 5> arr = {1, 2, 3, 4, 5};

// Acesso e modificação
arr[0] = 10;                       // Acesso direto
arr.at(1) = 20;                    // Acesso com verificação de limites
int primeiro = arr.front();        // Primeiro elemento
int ultimo = arr.back();           // Último elemento

// Tamanho
size_t tamanho = arr.size();       // Número de elementos (sempre 5 neste caso)
bool vazio = arr.empty();          // Verifica se está vazio

// Outras operações
arr.fill(0);                       // Preenche todo o array com 0
```

**Complexidade de Tempo:**
- Acesso: O(1)
- Tamanho: O(1)
- Preenchimento: O(n)

**Quando Usar:**
- Quando o tamanho do array é conhecido em tempo de compilação
- Quando você precisa de garantias de desempenho
- Quando deseja evitar alocação dinâmica de memória

### Listas Encadeadas

#### std::list

A `std::list` implementa uma lista duplamente encadeada, permitindo inserções e remoções eficientes em qualquer posição.

```cpp
#include <list>
using namespace std;

// Inicialização
list<int> lst;                     // Lista vazia
list<int> lst2 = {1, 2, 3, 4, 5};  // Inicialização com lista

// Acesso
int primeiro = lst2.front();       // Primeiro elemento
int ultimo = lst2.back();          // Último elemento

// Tamanho
size_t tamanho = lst2.size();      // Número de elementos
bool vazio = lst2.empty();         // Verifica se está vazia

// Adição e remoção
lst2.push_back(6);                 // Adiciona ao final
lst2.push_front(0);                // Adiciona ao início
lst2.pop_back();                   // Remove do final
lst2.pop_front();                  // Remove do início

// Inserção e remoção no meio
auto it = lst2.begin();
advance(it, 2);                    // Move o iterador para a posição 2
lst2.insert(it, 10);               // Insere 10 na posição 2
lst2.erase(it);                    // Remove o elemento na posição 2

// Operações específicas de lista
lst2.sort();                       // Ordena a lista
lst2.unique();                     // Remove elementos duplicados consecutivos
lst2.reverse();                    // Inverte a ordem dos elementos

// Splice (transferir elementos de outra lista)
list<int> lst3 = {100, 200, 300};
lst2.splice(lst2.begin(), lst3);   // Insere lst3 no início de lst2
```

**Complexidade de Tempo:**
- Acesso ao primeiro/último elemento: O(1)
- Acesso a um elemento no meio: O(n)
- Inserção/remoção em qualquer posição (com iterador): O(1)
- Busca: O(n)

**Quando Usar:**
- Quando você precisa de inserções e remoções frequentes em qualquer posição
- Quando não precisa de acesso aleatório
- Quando precisa de operações específicas como splice, sort, unique

#### std::forward_list

A `std::forward_list` implementa uma lista simplesmente encadeada, economizando memória em relação à `std::list`.

```cpp
#include <forward_list>
using namespace std;

// Inicialização
forward_list<int> flist = {1, 2, 3, 4, 5};

// Acesso
int primeiro = flist.front();      // Primeiro elemento

// Adição e remoção
flist.push_front(0);               // Adiciona ao início
flist.pop_front();                 // Remove do início

// Inserção após uma posição
auto it = flist.begin();
flist.insert_after(it, 10);        // Insere 10 após o primeiro elemento
flist.erase_after(it);             // Remove o elemento após o primeiro

// Operações específicas
flist.sort();                      // Ordena a lista
flist.unique();                    // Remove elementos duplicados consecutivos
flist.reverse();                   // Inverte a ordem dos elementos
```

**Complexidade de Tempo:**
- Acesso ao primeiro elemento: O(1)
- Inserção/remoção no início: O(1)
- Inserção/remoção após uma posição (com iterador): O(1)
- Busca: O(n)

**Quando Usar:**
- Quando você precisa economizar memória
- Quando só precisa inserir/remover no início ou após posições conhecidas
- Quando não precisa acessar o último elemento diretamente

### Pilhas e Filas

#### std::stack

A `std::stack` implementa uma estrutura LIFO (Last-In-First-Out), onde o último elemento adicionado é o primeiro a ser removido.

```cpp
#include <stack>
using namespace std;

// Inicialização
stack<int> pilha;

// Operações básicas
pilha.push(1);                     // Adiciona elemento ao topo
pilha.push(2);
pilha.push(3);

int topo = pilha.top();            // Acessa o elemento do topo (3)
pilha.pop();                       // Remove o elemento do topo

size_t tamanho = pilha.size();     // Número de elementos
bool vazia = pilha.empty();        // Verifica se está vazia
```

**Complexidade de Tempo:**
- Todas as operações: O(1)

**Quando Usar:**
- Para problemas que seguem a lógica LIFO
- Verificação de expressões balanceadas (parênteses, colchetes)
- Implementação de algoritmos como DFS (busca em profundidade)
- Avaliação de expressões pós-fixadas

#### std::queue

A `std::queue` implementa uma estrutura FIFO (First-In-First-Out), onde o primeiro elemento adicionado é o primeiro a ser removido.

```cpp
#include <queue>
using namespace std;

// Inicialização
queue<int> fila;

// Operações básicas
fila.push(1);                      // Adiciona elemento ao final
fila.push(2);
fila.push(3);

int frente = fila.front();         // Acessa o primeiro elemento (1)
int tras = fila.back();            // Acessa o último elemento (3)
fila.pop();                        // Remove o primeiro elemento

size_t tamanho = fila.size();      // Número de elementos
bool vazia = fila.empty();         // Verifica se está vazia
```

**Complexidade de Tempo:**
- Todas as operações: O(1)

**Quando Usar:**
- Para problemas que seguem a lógica FIFO
- Implementação de algoritmos como BFS (busca em largura)
- Simulação de processos em ordem de chegada
- Problemas de nível por nível em árvores

#### std::deque

A `std::deque` (double-ended queue) permite inserções e remoções eficientes em ambas as extremidades.

```cpp
#include <deque>
using namespace std;

// Inicialização
deque<int> dq = {1, 2, 3, 4, 5};

// Acesso
int primeiro = dq.front();         // Primeiro elemento
int ultimo = dq.back();            // Último elemento
int meio = dq[2];                  // Acesso direto (como em um vetor)

// Adição e remoção
dq.push_back(6);                   // Adiciona ao final
dq.push_front(0);                  // Adiciona ao início
dq.pop_back();                     // Remove do final
dq.pop_front();                    // Remove do início

// Inserção e remoção no meio
dq.insert(dq.begin() + 2, 10);     // Insere 10 na posição 2
dq.erase(dq.begin() + 3);          // Remove o elemento na posição 3
```

**Complexidade de Tempo:**
- Acesso: O(1)
- Inserção/remoção nas extremidades: O(1)
- Inserção/remoção no meio: O(n)

**Quando Usar:**
- Quando você precisa de inserções e remoções eficientes em ambas as extremidades
- Quando também precisa de acesso aleatório
- Como alternativa a `vector` quando há muitas operações no início

#### std::priority_queue

A `std::priority_queue` implementa uma fila de prioridade, onde os elementos são ordenados automaticamente.

```cpp
#include <queue>
using namespace std;

// Inicialização (max heap por padrão)
priority_queue<int> pq;

// Inicialização como min heap
priority_queue<int, vector<int>, greater<int>> min_pq;

// Operações básicas
pq.push(3);                        // Adiciona elementos
pq.push(1);
pq.push(4);
pq.push(2);

int maior = pq.top();              // Acessa o elemento de maior prioridade (4)
pq.pop();                          // Remove o elemento de maior prioridade

size_t tamanho = pq.size();        // Número de elementos
bool vazia = pq.empty();           // Verifica se está vazia

// Usando com tipos personalizados
struct Tarefa {
    int id;
    int prioridade;
    
    // Operador de comparação para a fila de prioridade
    bool operator<(const Tarefa& outra) const {
        return prioridade < outra.prioridade; // Para max heap
    }
};

priority_queue<Tarefa> tarefas;
tarefas.push({1, 5});
tarefas.push({2, 10});
Tarefa proxima = tarefas.top();    // Tarefa com maior prioridade
```

**Complexidade de Tempo:**
- Inserção: O(log n)
- Remoção do elemento de maior prioridade: O(log n)
- Acesso ao elemento de maior prioridade: O(1)

**Quando Usar:**
- Quando você precisa sempre acessar o elemento de maior (ou menor) valor
- Implementação de algoritmos como Dijkstra (caminho mais curto)
- Problemas de agendamento ou simulação com prioridades
- Quando precisa manter um conjunto ordenado com inserções frequentes

### Conjuntos e Mapas

#### std::set e std::multiset

O `std::set` mantém uma coleção ordenada de elementos únicos, enquanto o `std::multiset` permite elementos duplicados.

```cpp
#include <set>
using namespace std;

// Inicialização
set<int> conjunto = {5, 2, 8, 1, 3};  // Armazenado como {1, 2, 3, 5, 8}
multiset<int> multiconjunto = {5, 2, 5, 1, 3};  // Permite duplicatas

// Inserção
conjunto.insert(4);                // Insere um elemento
auto [it, inserido] = conjunto.insert(2);  // it aponta para o 2, inserido = false (já existe)

// Remoção
conjunto.erase(3);                 // Remove o elemento 3
auto it = conjunto.find(5);
if (it != conjunto.end()) {
    conjunto.erase(it);            // Remove usando iterador
}

// Busca
bool existe = conjunto.count(4) > 0;  // Verifica se 4 existe
it = conjunto.find(4);             // Retorna iterador para o elemento ou end()

// Operações de conjunto
auto lower = conjunto.lower_bound(3);  // Primeiro elemento >= 3
auto upper = conjunto.upper_bound(3);  // Primeiro elemento > 3
auto range = conjunto.equal_range(3);  // Par de iteradores [lower_bound, upper_bound]

// Iteração
for (const auto& elem : conjunto) {
    cout << elem << " ";
}

// Usando comparador personalizado
struct Comparador {
    bool operator()(const string& a, const string& b) const {
        return a.length() < b.length();  // Ordena por tamanho
    }
};

set<string, Comparador> palavras = {"abc", "a", "abcd", "ab"};
// Armazenado como {"a", "ab", "abc", "abcd"}
```

**Complexidade de Tempo:**
- Inserção: O(log n)
- Remoção: O(log n)
- Busca: O(log n)

**Quando Usar:**
- Quando você precisa manter elementos ordenados
- Quando precisa verificar rapidamente se um elemento existe
- Quando precisa de operações como lower_bound e upper_bound
- Para implementar conjuntos matemáticos

#### std::map e std::multimap

O `std::map` mantém pares chave-valor ordenados pela chave, com chaves únicas, enquanto o `std::multimap` permite chaves duplicadas.

```cpp
#include <map>
using namespace std;

// Inicialização
map<string, int> pontuacao = {{"Alice", 100}, {"Bob", 85}, {"Carol", 92}};
multimap<string, int> multiplas;

// Inserção
pontuacao["David"] = 78;           // Inserção com operador []
pontuacao.insert({"Eve", 95});     // Inserção com método insert
pontuacao.insert(make_pair("Frank", 88));  // Outra forma de inserção

// Acesso
int alice_pontos = pontuacao["Alice"];  // Acesso com operador []
// Se a chave não existir, cria com valor padrão (0 para int)
int nao_existe = pontuacao["Ninguém"];  // Cria entrada com valor 0

// Acesso seguro (não insere se não existir)
auto it = pontuacao.find("Alice");
if (it != pontuacao.end()) {
    int pontos = it->second;       // Acesso seguro
}

// Verificação de existência
bool existe = pontuacao.count("Bob") > 0;

// Remoção
pontuacao.erase("Bob");            // Remove por chave
it = pontuacao.find("Carol");
if (it != pontuacao.end()) {
    pontuacao.erase(it);           // Remove por iterador
}

// Iteração
for (const auto& [nome, pontos] : pontuacao) {
    cout << nome << ": " << pontos << endl;
}

// Usando comparador personalizado
struct ComparadorInverso {
    bool operator()(const string& a, const string& b) const {
        return a > b;  // Ordem decrescente
    }
};

map<string, int, ComparadorInverso> ordem_inversa = {
    {"Alice", 100}, {"Bob", 85}, {"Carol", 92}
};
// Armazenado em ordem decrescente de chaves
```

**Complexidade de Tempo:**
- Inserção: O(log n)
- Remoção: O(log n)
- Busca: O(log n)
- Acesso com operador []: O(log n)

**Quando Usar:**
- Quando você precisa associar valores a chaves
- Quando as chaves precisam estar ordenadas
- Para implementar dicionários ou tabelas de símbolos
- Quando precisa de operações como lower_bound e upper_bound nas chaves

#### std::unordered_set e std::unordered_multiset

Versões não ordenadas de `set` e `multiset`, implementadas como tabelas hash.

```cpp
#include <unordered_set>
using namespace std;

// Inicialização
unordered_set<int> conjunto = {5, 2, 8, 1, 3};  // Sem ordem garantida
unordered_multiset<int> multiconjunto = {5, 2, 5, 1, 3};  // Permite duplicatas

// Operações (mesma interface que set/multiset)
conjunto.insert(4);
conjunto.erase(3);
bool existe = conjunto.count(4) > 0;
auto it = conjunto.find(4);

// Informações da tabela hash
size_t buckets = conjunto.bucket_count();  // Número de buckets
float load_factor = conjunto.load_factor();  // Fator de carga
conjunto.rehash(20);               // Define número mínimo de buckets
conjunto.reserve(100);             // Reserva espaço para 100 elementos

// Usando tipos personalizados
struct Pessoa {
    string nome;
    int idade;
    
    bool operator==(const Pessoa& outra) const {
        return nome == outra.nome && idade == outra.idade;
    }
};

// Definindo uma função de hash para o tipo personalizado
namespace std {
    template<>
    struct hash<Pessoa> {
        size_t operator()(const Pessoa& p) const {
            return hash<string>()(p.nome) ^ hash<int>()(p.idade);
        }
    };
}

unordered_set<Pessoa> pessoas;
pessoas.insert({"Alice", 30});
```

**Complexidade de Tempo:**
- Inserção: O(1) média, O(n) pior caso
- Remoção: O(1) média, O(n) pior caso
- Busca: O(1) média, O(n) pior caso

**Quando Usar:**
- Quando a ordem dos elementos não importa
- Quando você precisa de operações de inserção e busca muito rápidas
- Para verificar pertinência em conjuntos grandes
- Quando não precisa de operações como lower_bound e upper_bound

#### std::unordered_map e std::unordered_multimap

Versões não ordenadas de `map` e `multimap`, implementadas como tabelas hash.

```cpp
#include <unordered_map>
using namespace std;

// Inicialização
unordered_map<string, int> pontuacao = {{"Alice", 100}, {"Bob", 85}, {"Carol", 92}};
unordered_multimap<string, int> multiplas;

// Operações (mesma interface que map/multimap)
pontuacao["David"] = 78;
pontuacao.insert({"Eve", 95});
int alice_pontos = pontuacao["Alice"];
pontuacao.erase("Bob");

// Informações da tabela hash
size_t buckets = pontuacao.bucket_count();
float load_factor = pontuacao.load_factor();
pontuacao.rehash(20);
pontuacao.reserve(100);

// Usando tipos personalizados como chaves
// (requer definição de hash e operador == como no exemplo de unordered_set)
```

**Complexidade de Tempo:**
- Inserção: O(1) média, O(n) pior caso
- Remoção: O(1) média, O(n) pior caso
- Busca: O(1) média, O(n) pior caso
- Acesso com operador []: O(1) média, O(n) pior caso

**Quando Usar:**
- Quando a ordem das chaves não importa
- Quando você precisa de operações de inserção e busca muito rápidas
- Para implementar dicionários ou tabelas de símbolos eficientes
- Quando o desempenho é mais importante que a ordem

## Estruturas de Dados Avançadas

### Árvores

#### Árvore Binária de Busca (BST)

Embora a STL não forneça uma implementação direta de BST, `std::set` e `std::map` são geralmente implementados como árvores rubro-negras (um tipo de BST balanceada).

```cpp
// Implementação básica de uma BST
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;
    
    // Métodos auxiliares recursivos
    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        
        return node;
    }
    
    Node* search(Node* node, int val) {
        if (node == nullptr || node->data == val) {
            return node;
        }
        
        if (val < node->data) {
            return search(node->left, val);
        } else {
            return search(node->right, val);
        }
    }
    
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    
    // Método para encontrar o nó com valor mínimo
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    
    // Método para remover um nó
    Node* remove(Node* node, int val) {
        if (node == nullptr) return nullptr;
        
        if (val < node->data) {
            node->left = remove(node->left, val);
        } else if (val > node->data) {
            node->right = remove(node->right, val);
        } else {
            // Nó com apenas um filho ou sem filhos
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            
            // Nó com dois filhos
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        
        return node;
    }
    
    void deleteTree(Node* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
    
public:
    BST() : root(nullptr) {}
    
    ~BST() {
        deleteTree(root);
    }
    
    void insert(int val) {
        root = insert(root, val);
    }
    
    bool search(int val) {
        return search(root, val) != nullptr;
    }
    
    void remove(int val) {
        root = remove(root, val);
    }
    
    void inorderTraversal() {
        inorder(root);
        cout << endl;
    }
};
```

**Complexidade de Tempo:**
- Inserção: O(log n) média, O(n) pior caso (árvore desbalanceada)
- Remoção: O(log n) média, O(n) pior caso
- Busca: O(log n) média, O(n) pior caso

**Quando Usar:**
- Quando você precisa manter elementos ordenados
- Quando precisa de operações de inserção, remoção e busca eficientes
- Quando a implementação de `std::set` ou `std::map` não é adequada para o problema

#### Trie (Árvore de Prefixos)

A Trie é uma estrutura especializada para armazenar strings, otimizada para buscas de prefixos.

```cpp
#include <unordered_map>
#include <string>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        clear(root);
    }
    
    void clear(TrieNode* node) {
        for (auto& pair : node->children) {
            clear(pair.second);
        }
        delete node;
    }
    
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }
    
    bool search(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }
    
    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};
```

**Complexidade de Tempo:**
- Inserção: O(m), onde m é o comprimento da string
- Busca: O(m)
- Verificação de prefixo: O(m)

**Quando Usar:**
- Para problemas envolvendo dicionários de palavras
- Quando você precisa verificar prefixos rapidamente
- Para implementar recursos como autocompletar
- Em problemas de correspondência de padrões

#### Árvore de Segmentos (Segment Tree)

A Árvore de Segmentos é uma estrutura eficiente para consultas de interv