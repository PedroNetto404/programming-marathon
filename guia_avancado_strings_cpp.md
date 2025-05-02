# Guia avançado de manipulação de strings em c++ usando stdlib para maratonas de programação

## Sumário
1. [Introdução](#introdução)
2. [Operações Básicas com Strings](#operações-básicas-com-strings)
3. [Transformações de Strings](#transformações-de-strings)
4. [Busca e Correspondência de Padrões](#busca-e-correspondência-de-padrões)
5. [Parsing e Tokenização](#parsing-e-tokenização)
6. [Algoritmos de Strings](#algoritmos-de-strings)
7. [Estruturas de Dados para Strings](#estruturas-de-dados-para-strings)
8. [Problemas Comuns em Competições](#problemas-comuns-em-competições)
9. [Considerações de Desempenho](#considerações-de-desempenho)
10. [Dicas e Truques](#dicas-e-truques)
11. [Referências](#referências)

## Introdução

A manipulação eficiente de strings é uma habilidade fundamental para maratonas de programação. Muitos problemas envolvem processamento de texto, validação de formatos, busca por padrões ou transformações de strings. Este guia apresenta técnicas avançadas de manipulação de strings em C++ usando a biblioteca padrão (STL), com foco em aplicações para competições de programação.

A biblioteca padrão do C++ oferece um conjunto robusto de ferramentas para trabalhar com strings, desde operações básicas até algoritmos complexos. Dominar essas ferramentas pode economizar tempo valioso durante as competições e permitir soluções mais elegantes e eficientes.

## Operações Básicas com Strings

### Inicialização e Declaração

```cpp
#include <string>
using namespace std;

// Diferentes formas de inicializar strings
string s1;                    // String vazia
string s2 = "texto";          // Inicialização com literal
string s3("outro texto");     // Construtor com literal
string s4(10, 'a');           // String com 10 caracteres 'a': "aaaaaaaaaa"
string s5(s2, 2, 3);          // Substring de s2 começando na posição 2 com tamanho 3: "xto"
string s6(s2.begin(), s2.begin() + 2); // Usando iteradores: "te"
```

### Acesso e Modificação

```cpp
string s = "maratona";

// Acesso a caracteres
char primeiro = s[0];         // 'm'
char ultimo = s[s.size()-1];  // 'a'
char seguro = s.at(1);        // 'a' (com verificação de limites)

// Modificação
s[0] = 'M';                   // "Maratona"
s.at(4) = 'T';                // "MaraTona" (com verificação de limites)

// Adição e remoção
s.push_back('!');             // "MaraTona!"
s.pop_back();                 // "MaraTona"
s.append(" de programação");  // "MaraTona de programação"
s += " 2024";                 // "MaraTona de programação 2024"

// Inserção e remoção em posições específicas
s.insert(0, "IFSP ");         // "IFSP MaraTona de programação 2024"
s.erase(0, 5);                // "MaraTona de programação 2024"
s.replace(0, 8, "Competição"); // "Competição de programação 2024"
```

### Propriedades e Informações

```cpp
string s = "maratona de programação";

// Tamanho e capacidade
size_t tamanho = s.size();      // 24 (ou s.length())
size_t capacidade = s.capacity(); // Geralmente >= tamanho
bool vazia = s.empty();         // false

// Comparação
bool igual = (s == "maratona");  // false
bool maior = (s > "competição"); // true (comparação lexicográfica)
int comp = s.compare("maratona"); // > 0 (s vem depois de "maratona")

// Substrings
string sub = s.substr(0, 8);     // "maratona"
string resto = s.substr(12);     // "programação"
```

## Transformações de Strings

### Conversão de Caso

```cpp
#include <algorithm>
#include <cctype>

string s = "Maratona de Programação";

// Conversão para minúsculas
string lower = s;
transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
// "maratona de programação"

// Conversão para maiúsculas
string upper = s;
transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
// "MARATONA DE PROGRAMAÇÃO"

// Conversão de apenas um caractere
char c = 'a';
char maiusculo = toupper(c);  // 'A'
```

### Remoção de Espaços e Caracteres Específicos

```cpp
string s = "  texto com espaços  ";

// Remover espaços do início
s.erase(0, s.find_first_not_of(" \t\n\r\f\v"));
// "texto com espaços  "

// Remover espaços do final
s.erase(s.find_last_not_of(" \t\n\r\f\v") + 1);
// "texto com espaços"

// Função para remover espaços do início e do final (trim)
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(first, last - first + 1);
}

// Remover todos os espaços
string removeSpaces(string str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}
// removeSpaces("a b c") -> "abc"

// Remover caracteres específicos
string removeChars(string str, string chars) {
    for (char c : chars) {
        str.erase(remove(str.begin(), str.end(), c), str.end());
    }
    return str;
}
// removeChars("a,b.c", ",.") -> "abc"
```

### Substituição de Caracteres

```cpp
string s = "maratona de programação";

// Substituir todas as ocorrências de um caractere
replace(s.begin(), s.end(), 'a', 'A');
// "mArAtonA de progrAmAção"

// Substituir todas as ocorrências de uma substring
size_t pos = 0;
string from = "de";
string to = "DE";
while ((pos = s.find(from, pos)) != string::npos) {
    s.replace(pos, from.length(), to);
    pos += to.length();
}
// "mArAtonA DE progrAmAção"

// Substituição usando regex
#include <regex>
string result = regex_replace(s, regex("a"), "A");
// "mArAtonA DE progrAmAção"
```

### Normalização de Strings

```cpp
// Função para normalizar uma string (remover acentos, pontuação, etc.)
string normalizeString(string s) {
    // Converter para minúsculas
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    // Remover caracteres não-alfanuméricos
    string result;
    for (char c : s) {
        if (isalnum(c)) {
            result += c;
        }
    }

    return result;
}

// Exemplo de uso para verificar palíndromo
bool isPalindrome(string s) {
    string normalized = normalizeString(s);
    string reversed = normalized;
    reverse(reversed.begin(), reversed.end());
    return normalized == reversed;
}

// isPalindrome("A man, a plan, a canal: Panama") -> true
```

## Busca e Correspondência de Padrões

### Busca Básica

```cpp
string texto = "maratona de programação é divertido";

// Encontrar a primeira ocorrência
size_t pos1 = texto.find("de");           // 9
size_t pos2 = texto.find("código");       // string::npos (não encontrado)

// Encontrar a última ocorrência
size_t pos3 = texto.rfind("a");           // 30 (último 'a')

// Verificar se uma string contém uma substring
bool contem = texto.find("programa") != string::npos;  // true

// Encontrar a primeira ocorrência de qualquer caractere de um conjunto
size_t pos4 = texto.find_first_of("aeiou");  // 1 (primeiro 'a')

// Encontrar a primeira ocorrência que não seja de um conjunto
size_t pos5 = texto.find_first_not_of("maratona ");  // 9 (primeiro 'd')
```

### Expressões Regulares

```cpp
#include <regex>

string texto = "Email: user@example.com e outro: test@test.org";

// Definir um padrão de regex
regex padrao_email(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}\b)");

// Verificar se o texto corresponde ao padrão
bool match = regex_search(texto, padrao_email);  // true

// Encontrar todas as correspondências
sregex_iterator it(texto.begin(), texto.end(), padrao_email);
sregex_iterator end;
vector<string> emails;
while (it != end) {
    emails.push_back(it->str());
    ++it;
}
// emails = {"user@example.com", "test@test.org"}

// Substituir usando regex
string resultado = regex_replace(texto, padrao_email, "[EMAIL]");
// "Email: [EMAIL] e outro: [EMAIL]"

// Validar formato específico (ex: placa de carro brasileira)
regex padrao_placa_antiga(R"([A-Z]{3}-\d{4})");
regex padrao_placa_mercosul(R"([A-Z]{3}\d[A-Z]\d{2})");

bool validar_placa(string placa) {
    return regex_match(placa, padrao_placa_antiga) || 
           regex_match(placa, padrao_placa_mercosul);
}
// validar_placa("ABC-1234") -> true
// validar_placa("ABC1D23") -> true
// validar_placa("ABC-123") -> false
```

### Algoritmo KMP (Knuth-Morris-Pratt)

```cpp
// Implementação do algoritmo KMP para busca de padrões
vector<int> computeLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

vector<int> KMPSearch(string text, string pattern) {
    vector<int> result;
    int n = text.length();
    int m = pattern.length();

    if (m == 0) return result;

    vector<int> lps = computeLPS(pattern);

    int i = 0;  // índice para text
    int j = 0;  // índice para pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return result;
}

// Exemplo de uso
string texto = "ABABDABACDABABCABAB";
string padrao = "ABABCABAB";
vector<int> posicoes = KMPSearch(texto, padrao);
// posicoes = {10}  (o padrão começa na posição 10)
```

## Parsing e Tokenização

### Tokenização Básica

```cpp
#include <sstream>

string texto = "maratona de programação 2024";

// Usando stringstream
stringstream ss(texto);
string token;
vector<string> tokens;

while (ss >> token) {
    tokens.push_back(token);
}
// tokens = {"maratona", "de", "programação", "2024"}

// Tokenização com delimitador específico
string csv = "valor1,valor2,valor3,valor4";
stringstream ss2(csv);
string item;
vector<string> itens;

while (getline(ss2, item, ',')) {
    itens.push_back(item);
}
// itens = {"valor1", "valor2", "valor3", "valor4"}
```

### Função de Tokenização Personalizada

```cpp
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);

    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

// Exemplo de uso
string texto = "maratona,de,programação,2024";
vector<string> tokens = split(texto, ',');
// tokens = {"maratona", "de", "programação", "2024"}
```

### Parsing de Números

```cpp
#include <string>

// String para número
string s1 = "42";
int i = stoi(s1);           // 42
string s2 = "3.14159";
double d = stod(s2);        // 3.14159
string s3 = "123456789012";
long long ll = stoll(s3);   // 123456789012

// Número para string
int num = 42;
string str1 = to_string(num);  // "42"
double pi = 3.14159;
string str2 = to_string(pi);   // "3.14159"

// Parsing com verificação de erro
try {
    int x = stoi("abc");  // Lança exceção std::invalid_argument
} catch (const invalid_argument& e) {
    cout << "Erro de conversão: " << e.what() << endl;
}

// Parsing com base numérica
int hex = stoi("1A", nullptr, 16);  // 26 (0x1A em decimal)
int bin = stoi("1010", nullptr, 2); // 10 (1010 em binário)
int oct = stoi("52", nullptr, 8);   // 42 (52 em octal)
```

### Leitura de Entrada Formatada

```cpp
#include <iostream>
#include <sstream>

// Leitura de linha inteira
string linha;
getline(cin, linha);

// Parsing de múltiplos valores em uma linha
istringstream iss(linha);
int a, b;
string s;
iss >> a >> b >> s;

// Leitura até o final do arquivo (EOF)
string linha;
while (getline(cin, linha)) {
    // Processar cada linha
}

// Leitura de número específico de casos
int t;
cin >> t;
cin.ignore();  // Ignorar o \n após o número
while (t--) {
    string linha;
    getline(cin, linha);
    // Processar cada caso
}
```

## Algoritmos de Strings

### Z-Algorithm

```cpp
// Implementação do Z-Algorithm
vector<int> zFunction(string s) {
    int n = s.length();
    vector<int> z(n, 0);

    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

// Busca de padrão usando Z-Algorithm
vector<int> zSearch(string text, string pattern) {
    string concat = pattern + "$" + text;
    vector<int> z = zFunction(concat);
    vector<int> result;

    for (int i = pattern.length() + 1; i < concat.length(); i++) {
        if (z[i] == pattern.length()) {
            result.push_back(i - pattern.length() - 1);
        }
    }

    return result;
}

// Exemplo de uso
string texto = "ABABDABACDABABCABAB";
string padrao = "ABABCABAB";
vector<int> posicoes = zSearch(texto, padrao);
// posicoes = {10}  (o padrão começa na posição 10)
```

### Algoritmo de Manacher (Palíndromos)

```cpp
// Implementação do algoritmo de Manacher para encontrar palíndromos
vector<int> manacher(string s) {
    // Pré-processamento: inserir caracteres especiais
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }

    int n = t.length();
    vector<int> p(n, 0);  // p[i] = raio do palíndromo centrado em i

    int c = 0, r = 0;  // centro e raio do palíndromo mais à direita
    for (int i = 1; i < n; i++) {
        // Espelhar i em relação a c
        if (r > i) {
            p[i] = min(r - i, p[2 * c - i]);
        }

        // Expandir palíndromo centrado em i
        while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && 
               t[i + p[i] + 1] == t[i - p[i] - 1]) {
            p[i]++;
        }

        // Atualizar c e r se necessário
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }

    return p;
}

// Encontrar o maior palíndromo em uma string
pair<int, int> longestPalindrome(string s) {
    vector<int> p = manacher(s);

    // Encontrar o centro com o maior raio
    int maxLen = 0;
    int centerIndex = 0;

    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }

    for (int i = 0; i < t.length(); i++) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }

    // Converter para índices na string original
    int start = (centerIndex - maxLen) / 2;
    int length = maxLen;

    return {start, length};
}

// Exemplo de uso
string s = "babad";
auto [start, length] = longestPalindrome(s);
string palindromo = s.substr(start, length);
// palindromo = "bab" ou "aba" (ambos são válidos)
```

### Algoritmo de Rabin-Karp (Hashing de Strings)

```cpp
// Implementação do algoritmo de Rabin-Karp
vector<int> rabinKarp(string text, string pattern) {
    const int p = 31;  // primo para hashing (bom para letras)
    const int m = 1e9 + 9;  // módulo para evitar overflow

    int n = text.length();
    int m_pattern = pattern.length();
    vector<int> result;

    if (m_pattern > n) return result;

    // Calcular potências de p
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i-1] * p) % m;
    }

    // Calcular hashes de prefixos do texto
    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++) {
        h[i+1] = (h[i] + (text[i] - 'a' + 1) * p_pow[i]) % m;
    }

    // Calcular hash do padrão
    long long h_pattern = 0;
    for (int i = 0; i < m_pattern; i++) {
        h_pattern = (h_pattern + (pattern[i] - 'a' + 1) * p_pow[i]) % m;
    }

    // Buscar ocorrências do padrão
    for (int i = 0; i <= n - m_pattern; i++) {
        long long curr_h = (h[i + m_pattern] - h[i] + m) % m;
        if (curr_h == (h_pattern * p_pow[i]) % m) {
            // Verificar se é uma correspondência real (para evitar colisões)
            bool match = true;
            for (int j = 0; j < m_pattern; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result.push_back(i);
            }
        }
    }

    return result;
}

// Exemplo de uso
string texto = "ABABDABACDABABCABAB";
string padrao = "ABABCABAB";
vector<int> posicoes = rabinKarp(texto, padrao);
// posicoes = {10}  (o padrão começa na posição 10)
```

## Estruturas de Dados para Strings

### Trie (Árvore de Prefixos)

```cpp
// Implementação de uma Trie
class TrieNode {
public:
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;

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

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }

    bool startsWith(string prefix) {
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

// Exemplo de uso
Trie trie;
trie.insert("maratona");
trie.insert("programacao");
trie.insert("algoritmo");

bool existe1 = trie.search("maratona");      // true
bool existe2 = trie.search("programa");       // false
bool prefixo = trie.startsWith("progra");     // true
```

### Suffix Array

```cpp
// Implementação simplificada de Suffix Array
vector<int> buildSuffixArray(string s) {
    s += "$";  // Adicionar um caractere menor que todos os outros
    int n = s.length();

    // Inicializar os arrays
    vector<int> p(n), c(n);
    vector<pair<char, int>> a(n);

    // Classificação inicial (k = 0)
    for (int i = 0; i < n; i++) a[i] = {s[i], i};
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) p[i] = a[i].second;
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
        c[p[i]] = c[p[i-1]];
        if (a[i].first != a[i-1].first) c[p[i]]++;
    }

    // Classificação para k > 0
    vector<int> pn(n), cn(n);
    for (int k = 0; (1 << k) < n; k++) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << k);
            if (pn[i] < 0) pn[i] += n;
        }

        vector<int> cnt(n, 0);
        for (int i = 0; i < n; i++) cnt[c[i]]++;
        for (int i = 1; i < n; i++) cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];

        cn[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << k)) % n]};
            cn[p[i]] = cn[p[i-1]];
            if (cur != prev) cn[p[i]]++;
        }
        c.swap(cn);
    }

    // Remover o sufixo que começa com '$'
    vector<int> result;
    for (int i = 1; i < n; i++) {
        result.push_back(p[i]);
    }

    return result;
}

// Exemplo de uso
string s = "banana";
vector<int> sa = buildSuffixArray(s);
// sa = {5, 3, 1, 0, 4, 2}
// Sufixos: "a", "ana", "anana", "banana", "na", "nana"
```

### Árvore de Sufixos (Ukkonen's Algorithm)

```cpp
// Implementação simplificada da árvore de sufixos usando o algoritmo de Ukkonen
// Nota: Esta é uma implementação complexa e geralmente não é necessária em competições
// A maioria dos problemas pode ser resolvida com Suffix Array ou outras técnicas
class SuffixTree {
    // Implementação omitida devido à complexidade
    // Para problemas de competição, geralmente é mais prático usar Suffix Array
};
```

## Problemas Comuns em Competições

### Verificação de Palíndromos

```cpp
// Verificar se uma string é um palíndromo
bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

// Verificar se uma string é um palíndromo com normalização
bool isPalindromeWithNormalization(string s) {
    // Normalizar a string (remover espaços, pontuação, converter para minúsculas)
    string normalized;
    for (char c : s) {
        if (isalnum(c)) {
            normalized += tolower(c);
        }
    }

    return isPalindrome(normalized);
}

// Verificar se uma string pode se tornar um palíndromo removendo no máximo um caractere
bool canBePalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            // Tentar remover o caractere da esquerda
            if (isPalindrome(s.substr(0, left) + s.substr(left + 1))) {
                return true;
            }

            // Tentar remover o caractere da direita
            if (isPalindrome(s.substr(0, right) + s.substr(right + 1))) {
                return true;
            }

            return false;
        }

        left++;
        right--;
    }

    return true;  // Já é um palíndromo
}
```

### Validação de Formatos

```cpp
#include <regex>

// Validar endereço de e-mail
bool isValidEmail(const string& email) {
    regex pattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return regex_match(email, pattern);
}

// Validar número de telefone brasileiro
bool isValidPhoneNumber(const string& phone) {
    regex pattern(R"(^\(?(\d{2})\)?\s?(\d{4,5})-?(\d{4})$)");
    return regex_match(phone, pattern);
}

// Validar CPF (formato xxx.xxx.xxx-xx)
bool isValidCPF(const string& cpf) {
    // Verificar formato
    regex pattern(R"(^(\d{3})\.(\d{3})\.(\d{3})-(\d{2})$)");
    if (!regex_match(cpf, pattern)) {
        return false;
    }

    // Remover pontuação para verificar dígitos
    string digits;
    for (char c : cpf) {
        if (isdigit(c)) {
            digits += c;
        }
    }

    // Verificar se todos os dígitos são iguais (caso inválido)
    bool allSame = true;
    for (int i = 1; i < digits.length(); i++) {
        if (digits[i] != digits[0]) {
            allSame = false;
            break;
        }
    }
    if (allSame) return false;

    // Verificar dígitos verificadores (algoritmo do CPF)
    // Implementação omitida por brevidade

    return true;  // Simplificado para o exemplo
}
```

### Contagem de Substrings

```cpp
// Contar ocorrências de uma substring
int countSubstring(const string& str, const string& sub) {
    if (sub.empty()) return 0;

    int count = 0;
    size_t pos = 0;
    while ((pos = str.find(sub, pos)) != string::npos) {
        count++;
        pos += sub.length();
    }

    return count;
}

// Contar ocorrências de cada caractere
map<char, int> countCharacters(const string& str) {
    map<char, int> counts;
    for (char c : str) {
        counts[c]++;
    }
    return counts;
}

// Encontrar a substring mais frequente de tamanho k
string mostFrequentSubstring(const string& str, int k) {
    if (str.length() < k) return "";

    unordered_map<string, int> counts;
    string mostFrequent;
    int maxCount = 0;

    for (int i = 0; i <= str.length() - k; i++) {
        string sub = str.substr(i, k);
        counts[sub]++;

        if (counts[sub] > maxCount) {
            maxCount = counts[sub];
            mostFrequent = sub;
        }
    }

    return mostFrequent;
}
```

### Anagramas

```cpp
// Verificar se duas strings são anagramas
bool areAnagrams(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
}

// Verificar se duas strings são anagramas (método mais eficiente)
bool areAnagramsEfficient(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) return false;

    vector<int> count(26, 0);

    for (int i = 0; i < s1.length(); i++) {
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }

    for (int c : count) {
        if (c != 0) return false;
    }

    return true;
}

// Agrupar anagramas em uma lista de strings
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;

    for (const string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }

    vector<vector<string>> result;
    for (const auto& pair : groups) {
        result.push_back(pair.second);
    }

    return result;
}
```

### Subsequências e Substrings

```cpp
// Verificar se uma string é subsequência de outra
bool isSubsequence(const string& s, const string& t) {
    int i = 0, j = 0;

    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }

    return i == s.length();
}

// Encontrar a maior subsequência comum entre duas strings
string longestCommonSubsequence(const string& text1, const string& text2) {
    int m = text1.length();
    int n = text2.length();

    // dp[i][j] = tamanho da LCS de text1[0...i-1] e text2[0...j-1]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // Reconstruir a LCS
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (text1[i-1] == text2[j-1]) {
            lcs = text1[i-1] + lcs;
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

// Encontrar a maior substring comum entre duas strings
pair<int, int> longestCommonSubstring(const string& text1, const string& text2) {
    int m = text1.length();
    int n = text2.length();

    // dp[i][j] = tamanho da maior substring comum terminando em i-1 e j-1
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int maxLength = 0;
    int endIndex = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;

                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }

    return {endIndex - maxLength + 1, maxLength};
}
```

## Considerações de Desempenho

### Complexidade de Tempo das Operações com Strings

| Operação | Complexidade | Observações |
|----------|--------------|-------------|
| `s.length()`, `s.size()` | O(1) | Acesso direto ao tamanho armazenado |
| `s[i]`, `s.at(i)` | O(1) | Acesso direto a um caractere |
| `s += t`, `s.append(t)` | O(n) | n = tamanho de t |
| `s.find(t)` | O(n*m) | n = tamanho de s, m = tamanho de t |
| `s.substr(pos, len)` | O(len) | Copia len caracteres |
| `s.replace(pos, len, t)` | O(n) | n = tamanho de s |
| `s.insert(pos, t)` | O(n + m) | n = tamanho de s, m = tamanho de t |
| `s.erase(pos, len)` | O(n) | n = tamanho de s |
| `s.compare(t)` | O(min(n, m)) | n = tamanho de s, m = tamanho de t |

### Otimizações Importantes

```cpp
// Evitar cópias desnecessárias usando referências
void processString(const string& s) {  // Use const reference
    // Processar s sem modificá-la
}

// Reservar espaço para evitar realocações
string buildLargeString(int n) {
    string result;
    result.reserve(n);  // Reserva espaço para n caracteres

    for (int i = 0; i < n; i++) {
        result += 'a';  // Não causa realocações frequentes
    }

    return result;
}

// Usar string_view para visualizar partes de strings sem copiar
#include <string_view>

void processSubstring(string_view sv) {
    // Processar sv sem copiar a substring
}

void example() {
    string s = "maratona de programação";
    processSubstring(s.substr(0, 8));  // Cria uma cópia
    processSubstring(string_view(s).substr(0, 8));  // Não cria cópia
}

// Evitar concatenação repetitiva
string badConcatenation(vector<string>& words) {
    string result;
    for (const string& word : words) {
        result = result + word + " ";  // Ineficiente: cria uma nova string a cada iteração
    }
    return result;
}

string goodConcatenation(vector<string>& words) {
    string result;
    // Estimar o tamanho final
    size_t totalLength = 0;
    for (const string& word : words) {
        totalLength += word.length() + 1;  // +1 para o espaço
    }
    result.reserve(totalLength);

    // Concatenar
    for (const string& word : words) {
        result += word + " ";  // Melhor, mas ainda não ideal
    }
    return result;
}

string bestConcatenation(vector<string>& words) {
    // Usar stringstream para concatenação eficiente
    ostringstream oss;
    for (size_t i = 0; i < words.size(); i++) {
        oss << words[i];
        if (i < words.size() - 1) {
            oss << " ";
        }
    }
    return oss.str();
}
```

### Comparação de Algoritmos de Busca

| Algoritmo | Complexidade | Melhor Caso | Pior Caso | Uso Recomendado |
|-----------|--------------|-------------|-----------|-----------------|
| Busca Ingênua | O(n*m) | O(n) | O(n*m) | Strings pequenas ou quando a simplicidade é importante |
| KMP | O(n+m) | O(n+m) | O(n+m) | Busca de padrão único em texto grande |
| Z-Algorithm | O(n+m) | O(n+m) | O(n+m) | Similar ao KMP, bom para múltiplas buscas |
| Rabin-Karp | O(n+m) | O(n+m) | O(n*m) | Busca de múltiplos padrões |
| Suffix Array | O(n log n) construção, O(m log n) busca | - | - | Múltiplas buscas no mesmo texto |
| Trie | O(m) inserção/busca | - | - | Dicionários, autocompletar |

## Dicas e Truques

### Técnicas para Competições

1. **Pré-processamento de Strings**
   ```cpp
   // Normalizar uma string para comparações
   string normalize(string s) {
       // Converter para minúsculas
       transform(s.begin(), s.end(), s.begin(), ::tolower);

       // Remover espaços e pontuação
       s.erase(remove_if(s.begin(), s.end(), 
           [](char c) { return !isalnum(c); }), s.end());

       return s;
   }
   ```

2. **Uso de Hashing para Comparações Rápidas**
   ```cpp
   // Função de hash para strings
   long long computeHash(const string& s) {
       const int p = 31; // primo bom para letras
       const int m = 1e9 + 9; // módulo grande
       long long hash_value = 0;
       long long p_pow = 1;

       for (char c : s) {
           hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
           p_pow = (p_pow * p) % m;
       }

       return hash_value;
   }
   ```

3. **Templates para Problemas Comuns**
   ```cpp
   // Template para verificar se uma string é um palíndromo
   bool isPalindrome(const string& s, int left, int right) {
       while (left < right) {
           if (s[left] != s[right]) return false;
           left++;
           right--;
       }
       return true;
   }

   // Template para encontrar todos os palíndromos em uma string
   vector<pair<int, int>> findAllPalindromes(const string& s) {
       vector<pair<int, int>> result;
       int n = s.length();

       // Palíndromos de tamanho ímpar
       for (int center = 0; center < n; center++) {
           int left = center, right = center;
           while (left >= 0 && right < n && s[left] == s[right]) {
               result.push_back({left, right});
               left--;
               right++;
           }
       }

       // Palíndromos de tamanho par
       for (int center = 0; center < n - 1; center++) {
           int left = center, right = center + 1;
           while (left >= 0 && right < n && s[left] == s[right]) {
               result.push_back({left, right});
               left--;
               right++;
           }
       }

       return result;
   }
   ```

4. **Uso de Bitsets para Operações Eficientes**
   ```cpp
   #include <bitset>

   // Representar um conjunto de caracteres presentes em uma string
   bitset<26> getCharacterSet(const string& s) {
       bitset<26> result;
       for (char c : s) {
           if (isalpha(c)) {
               result.set(tolower(c) - 'a');
           }
       }
       return result;
   }

   // Verificar se duas strings têm caracteres em comum
   bool haveCommonCharacters(const string& s1, const string& s2) {
       bitset<26> set1 = getCharacterSet(s1);
       bitset<26> set2 = getCharacterSet(s2);

       return (set1 & set2).any();
   }
   ```

5. **Leitura Eficiente de Entrada**
   ```cpp
   // Acelerar a entrada/saída
   void optimizeIO() {
       ios_base::sync_with_stdio(false);
       cin.tie(nullptr);
   }

   // Ler uma linha e processar tokens
   void processLine() {
       string line;
       getline(cin, line);

       istringstream iss(line);
       string token;
       vector<string> tokens;

       while (iss >> token) {
           tokens.push_back(token);
       }

       // Processar tokens
   }
   ```

### Erros Comuns a Evitar

1. **Esquecer de Verificar Limites**
   ```cpp
   // Errado: Pode causar acesso fora dos limites
   char c = s[s.length()];  // Erro: índice inválido

   // Correto: Verificar limites
   if (!s.empty()) {
       char c = s[s.length() - 1];
   }

   // Alternativa: Usar at() que faz verificação de limites
   try {
       char c = s.at(s.length() - 1);
   } catch (const out_of_range& e) {
       // Tratar erro
   }
   ```

2. **Modificar Strings Durante Iteração**
   ```cpp
   // Errado: Modificar a string enquanto itera sobre ela
   for (size_t i = 0; i < s.length(); i++) {
       if (s[i] == ' ') {
           s.erase(i, 1);  // Isso altera os índices!
       }
   }

   // Correto: Usar uma abordagem que não altera índices durante a iteração
   string result;
   for (char c : s) {
       if (c != ' ') {
           result += c;
       }
   }
   s = result;
   ```

3. **Ignorar Casos Especiais**
   ```cpp
   // Errado: Não considerar strings vazias
   bool isPalindrome(const string& s) {
       // Se s for vazia, o loop não executa e retorna true
       // (o que pode ou não ser o comportamento desejado)
       int left = 0, right = s.length() - 1;
       while (left < right) {
           if (s[left] != s[right]) return false;
           left++;
           right--;
       }
       return true;
   }

   // Correto: Tratar explicitamente o caso da string vazia
   bool isPalindrome(const string& s) {
       if (s.empty()) {
           return true;  // Decisão explícita: string vazia é palíndromo
       }

       int left = 0, right = s.length() - 1;
       while (left < right) {
           if (s[left] != s[right]) return false;
           left++;
           right--;
       }
       return true;
   }
   ```

4. **Não Considerar Caracteres Unicode**
   ```cpp
   // Errado: Assumir que cada caractere ocupa 1 byte
   int countCharacters(const string& s) {
       return s.length();  // Pode estar errado para strings com caracteres Unicode
   }

   // Correto: Para C++20, usar std::u8string para UTF-8
   // Para versões anteriores, considerar bibliotecas como ICU ou UTF8-CPP
   ```

## Referências

### Bibliotecas e Documentação

- [C++ Reference - std::string](https://en.cppreference.com/w/cpp/string/basic_string)
- [C++ Reference - std::regex](https://en.cppreference.com/w/cpp/regex)
- [C++ Reference - Algoritmos](https://en.cppreference.com/w/cpp/algorithm)

### Livros Recomendados

- "Competitive Programming 3" por Steven Halim e Felix Halim
- "Algorithms on Strings, Trees, and Sequences" por Dan Gusfield
- "Introduction to Algorithms" por Cormen, Leiserson, Rivest e Stein (CLRS)

### Recursos Online

- [CP-Algorithms - String Processing](https://cp-algorithms.com/string/prefix-function.html)
- [GeeksforGeeks - String Algorithms](https://www.geeksforgeeks.org/string-data-structure/)
- [Codeforces - String Manipulation Tutorials](https://codeforces.com/blog/entry/23301)

### Problemas para Prática

- [LeetCode - String Problems](https://leetcode.com/tag/string/)
- [HackerRank - String Manipulation](https://www.hackerrank.com/domains/algorithms?filters%5Bsubdomains%5D%5B%5D=strings)
- [Codeforces - String Problems](https://codeforces.com/problemset?tags=string)
- [SPOJ - String Problems](https://www.spoj.com/problems/tag/string)

---

Este guia foi desenvolvido para ajudar competidores em maratonas de programação a dominar técnicas avançadas de manipulação de strings em C++. As técnicas apresentadas são especialmente úteis para competições como a InterFatecs, onde problemas envolvendo strings são frequentes. Lembre-se de praticar regularmente e adaptar estas técnicas às necessidades específicas de cada problema.

Boa sorte nas suas competições!
