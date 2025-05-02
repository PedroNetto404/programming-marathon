# Fórmulas Matemáticas para Maratonas de Programação

## Sumário
1. [Teoria dos Números](#teoria-dos-números)
2. [Combinatória](#combinatória)
3. [Geometria](#geometria)
4. [Álgebra](#álgebra)
5. [Teoria dos Grafos](#teoria-dos-grafos)
6. [Otimização](#otimização)
7. [Probabilidade e Estatística](#probabilidade-e-estatística)
8. [Técnicas de Contagem](#técnicas-de-contagem)

## Teoria dos Números

### Divisibilidade e Operações Modulares

#### Propriedades Básicas
- **Divisibilidade**: `a` é divisível por `b` se `a % b == 0`
- **Congruência Modular**: `a ≡ b (mod m)` significa que `a % m == b % m`
- **Adição Modular**: `(a + b) % m = ((a % m) + (b % m)) % m`
- **Subtração Modular**: `(a - b) % m = ((a % m) - (b % m) + m) % m`
- **Multiplicação Modular**: `(a * b) % m = ((a % m) * (b % m)) % m`
- **Exponenciação Modular**: `a^b % m` pode ser calculado eficientemente com exponenciação binária

#### Algoritmo de Exponenciação Binária
```cpp
// Calcula (base^exponent) % modulo
long long modPow(long long base, long long exponent, long long modulo) {
    if (modulo == 1) return 0;
    long long result = 1;
    base = base % modulo;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulo;
        exponent = exponent >> 1;
        base = (base * base) % modulo;
    }
    return result;
}
```

#### Algoritmo de Euclides (MDC)
```cpp
// Calcula o Máximo Divisor Comum de a e b
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```

#### Algoritmo de Euclides Estendido
```cpp
// Calcula coeficientes x e y tais que ax + by = gcd(a, b)
void extendedGcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    int x1, y1;
    extendedGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}
```

#### Inverso Modular
- O inverso modular de `a` módulo `m` é um número `x` tal que `(a * x) % m = 1`
- Existe apenas se `gcd(a, m) = 1` (a e m são coprimos)
- Pode ser calculado usando o algoritmo de Euclides estendido

```cpp
// Calcula o inverso modular de a módulo m
int modInverse(int a, int m) {
    int x, y;
    extendedGcd(a, m, x, y);
    return (x % m + m) % m;  // Garante resultado positivo
}
```

### Números Primos

#### Teste de Primalidade
```cpp
// Verifica se n é primo em O(sqrt(n))
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
```

#### Crivo de Eratóstenes
```cpp
// Encontra todos os primos até n em O(n log log n)
vector<bool> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}
```

#### Fatoração em Primos
```cpp
// Retorna os fatores primos de n
vector<int> primeFactors(int n) {
    vector<int> factors;
    // Trata fatores 2 separadamente
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    // Verifica fatores ímpares
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    // Se n > 2, então n é primo
    if (n > 2)
        factors.push_back(n);
    return factors;
}
```

### Funções Numéricas

#### Função Totiente de Euler
- `φ(n)` conta quantos números de 1 a n são coprimos com n
- Se n é primo, então `φ(n) = n - 1`
- Se n = p^k (potência de primo), então `φ(n) = p^k - p^(k-1) = p^(k-1) * (p - 1)`
- A função é multiplicativa: se gcd(a, b) = 1, então `φ(a * b) = φ(a) * φ(b)`

```cpp
// Calcula a função totiente de Euler para n
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
```

## Combinatória

### Permutações e Combinações

#### Fatorial
- `n! = n × (n-1) × (n-2) × ... × 2 × 1`
- `0! = 1`

```cpp
// Calcula n! (cuidado com overflow para n > 20)
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}
```

#### Permutações
- Número de maneiras de arranjar n elementos distintos: `P(n) = n!`
- Número de maneiras de arranjar k elementos de n elementos distintos: `P(n,k) = n! / (n-k)!`

```cpp
// Calcula P(n,k) = n! / (n-k)!
long long permutation(int n, int k) {
    long long result = 1;
    for (int i = n - k + 1; i <= n; i++)
        result *= i;
    return result;
}
```

#### Combinações
- Número de maneiras de escolher k elementos de n elementos distintos (sem importar a ordem): `C(n,k) = n! / (k! * (n-k)!)`
- Também conhecido como coeficiente binomial: `C(n,k) = (n choose k)`
- Propriedades: `C(n,k) = C(n,n-k)` e `C(n,0) = C(n,n) = 1`

```cpp
// Calcula C(n,k) = n! / (k! * (n-k)!)
long long combination(int n, int k) {
    if (k > n - k)
        k = n - k;  // Otimização usando C(n,k) = C(n,n-k)
    long long result = 1;
    for (int i = 0; i < k; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}
```

#### Triângulo de Pascal
- Método eficiente para calcular coeficientes binomiais
- Cada número é a soma dos dois números acima dele

```cpp
// Calcula todos os C(n,k) para 0 <= k <= n
vector<long long> pascalRow(int n) {
    vector<long long> row(n + 1, 0);
    row[0] = 1;
    for (int i = 1; i <= n; i++)
        row[i] = row[i-1] * (n - i + 1) / i;
    return row;
}
```

### Princípio da Inclusão-Exclusão (PIE)

- Fórmula para calcular o tamanho da união de conjuntos
- Para 3 conjuntos A, B, C:
  |A ∪ B ∪ C| = |A| + |B| + |C| - |A ∩ B| - |A ∩ C| - |B ∩ C| + |A ∩ B ∩ C|

- Fórmula geral para n conjuntos:
  |A₁ ∪ A₂ ∪ ... ∪ Aₙ| = ∑|Aᵢ| - ∑|Aᵢ ∩ Aⱼ| + ∑|Aᵢ ∩ Aⱼ ∩ Aₖ| - ... + (-1)ⁿ⁺¹|A₁ ∩ A₂ ∩ ... ∩ Aₙ|

```cpp
// Exemplo: Contar números de 1 a n que não são divisíveis por nenhum dos primos em primes
long long countNotDivisible(int n, vector<int> primes) {
    int size = primes.size();
    long long result = n;
    
    // Iterar por todos os subconjuntos de primes
    for (int mask = 1; mask < (1 << size); mask++) {
        long long product = 1;
        int bits = 0;
        
        for (int i = 0; i < size; i++) {
            if (mask & (1 << i)) {
                product *= primes[i];
                bits++;
                if (product > n) break;  // Evita overflow
            }
        }
        
        if (product <= n) {
            if (bits % 2 == 1)
                result -= n / product;
            else
                result += n / product;
        }
    }
    
    return result;
}
```

## Geometria

### Geometria Básica

#### Distância entre Pontos
- Distância euclidiana entre pontos (x₁, y₁) e (x₂, y₂): `d = √((x₂ - x₁)² + (y₂ - y₁)²)`

```cpp
// Calcula a distância euclidiana entre dois pontos
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
```

#### Área de Triângulo
- Usando coordenadas dos vértices (x₁, y₁), (x₂, y₂), (x₃, y₃):
  `Area = |1/2 * ((x₁(y₂ - y₃) + x₂(y₃ - y₁) + x₃(y₁ - y₂)))|`
- Usando a fórmula de Heron com lados a, b, c:
  `s = (a + b + c) / 2`
  `Area = √(s * (s - a) * (s - b) * (s - c))`

```cpp
// Calcula a área de um triângulo usando coordenadas
double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

// Calcula a área de um triângulo usando a fórmula de Heron
double triangleAreaHeron(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
```

#### Produto Vetorial
- Para vetores 2D (x₁, y₁) e (x₂, y₂): `x₁ * y₂ - y₁ * x₂`
- O sinal indica a orientação (horária ou anti-horária)
- A magnitude é o dobro da área do triângulo formado pelos vetores

```cpp
// Calcula o produto vetorial de dois vetores 2D
double crossProduct(double x1, double y1, double x2, double y2) {
    return x1 * y2 - y1 * x2;
}
```

#### Produto Escalar
- Para vetores 2D (x₁, y₁) e (x₂, y₂): `x₁ * x₂ + y₁ * y₂`
- Positivo se os vetores formam ângulo agudo, negativo se formam ângulo obtuso, zero se perpendiculares

```cpp
// Calcula o produto escalar de dois vetores 2D
double dotProduct(double x1, double y1, double x2, double y2) {
    return x1 * x2 + y1 * y2;
}
```

### Geometria Computacional

#### Verificação de Ponto dentro de Polígono
- Método do raio: conte quantas vezes uma linha do ponto para o infinito cruza as arestas do polígono
- Se o número for ímpar, o ponto está dentro; se for par, está fora

```cpp
// Verifica se um ponto está dentro de um polígono
bool isPointInPolygon(vector<pair<double, double>> polygon, double x, double y) {
    int n = polygon.size();
    bool inside = false;
    
    for (int i = 0, j = n - 1; i < n; j = i++) {
        double xi = polygon[i].first, yi = polygon[i].second;
        double xj = polygon[j].first, yj = polygon[j].second;
        
        bool intersect = ((yi > y) != (yj > y)) &&
                         (x < (xj - xi) * (y - yi) / (yj - yi) + xi);
        
        if (intersect)
            inside = !inside;
    }
    
    return inside;
}
```

#### Área de Polígono
- Usando a fórmula do shoelace (ou fórmula de Gauss):
  `Area = |1/2 * ∑(i=0 to n-1) (x_i * y_{i+1} - x_{i+1} * y_i)|`
  onde (x_n, y_n) = (x_0, y_0)

```cpp
// Calcula a área de um polígono usando a fórmula do shoelace
double polygonArea(vector<pair<double, double>> polygon) {
    int n = polygon.size();
    double area = 0.0;
    
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += polygon[i].first * polygon[j].second;
        area -= polygon[j].first * polygon[i].second;
    }
    
    return abs(area) / 2.0;
}
```

## Álgebra

### Equações e Sistemas Lineares

#### Método de Gauss para Sistemas Lineares
- Resolve sistemas de equações lineares usando eliminação gaussiana
- Complexidade: O(n³) onde n é o número de variáveis

```cpp
// Resolve um sistema de equações lineares Ax = b usando eliminação gaussiana
// Retorna um vetor vazio se não houver solução única
vector<double> gaussianElimination(vector<vector<double>> A, vector<double> b) {
    int n = A.size();
    
    // Criar a matriz aumentada [A|b]
    for (int i = 0; i < n; i++)
        A[i].push_back(b[i]);
    
    // Eliminação para frente
    for (int i = 0; i < n; i++) {
        // Encontrar pivô máximo
        int maxRow = i;
        for (int j = i + 1; j < n; j++)
            if (abs(A[j][i]) > abs(A[maxRow][i]))
                maxRow = j;
        
        // Trocar linhas
        swap(A[i], A[maxRow]);
        
        // Verificar se a matriz é singular
        if (abs(A[i][i]) < 1e-10)
            return vector<double>();  // Sem solução única
        
        // Eliminar variáveis
        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i] / A[i][i];
            for (int k = i; k <= n; k++)
                A[j][k] -= A[i][k] * factor;
        }
    }
    
    // Substituição para trás
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = A[i][n];
        for (int j = i + 1; j < n; j++)
            x[i] -= A[i][j] * x[j];
        x[i] /= A[i][i];
    }
    
    return x;
}
```

### Matrizes

#### Determinante de Matriz
- Para matriz 2x2: `det = a*d - b*c` onde a matriz é [[a, b], [c, d]]
- Para matrizes maiores: usar expansão de cofatores ou eliminação gaussiana

```cpp
// Calcula o determinante de uma matriz usando eliminação gaussiana
double determinant(vector<vector<double>> matrix) {
    int n = matrix.size();
    double det = 1.0;
    
    // Eliminação gaussiana
    for (int i = 0; i < n; i++) {
        // Encontrar pivô não-zero
        int pivot = i;
        while (pivot < n && abs(matrix[pivot][i]) < 1e-10)
            pivot++;
        
        if (pivot == n)
            return 0;  // Matriz singular
        
        if (pivot != i) {
            swap(matrix[i], matrix[pivot]);
            det = -det;  // Troca de linhas muda o sinal do determinante
        }
        
        det *= matrix[i][i];
        
        // Eliminar elementos abaixo do pivô
        for (int j = i + 1; j < n; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; k++)
                matrix[j][k] -= matrix[i][k] * factor;
        }
    }
    
    return det;
}
```

## Teoria dos Grafos

### Algoritmos de Caminho Mínimo

#### Algoritmo de Dijkstra
- Encontra o caminho mais curto de um vértice para todos os outros em um grafo com pesos não-negativos
- Complexidade: O(E log V) com fila de prioridade

```cpp
// Algoritmo de Dijkstra para encontrar caminhos mínimos
vector<int> dijkstra(vector<vector<pair<int, int>>> graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}
```

#### Algoritmo de Floyd-Warshall
- Encontra os caminhos mais curtos entre todos os pares de vértices
- Funciona com pesos negativos, mas não com ciclos negativos
- Complexidade: O(V³)

```cpp
// Algoritmo de Floyd-Warshall para caminhos mínimos entre todos os pares
vector<vector<int>> floydWarshall(vector<vector<int>> graph) {
    int n = graph.size();
    vector<vector<int>> dist = graph;
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    return dist;
}
```

### Árvore Geradora Mínima (MST)

#### Algoritmo de Kruskal
- Encontra uma árvore geradora mínima em um grafo conectado com pesos
- Complexidade: O(E log E) onde E é o número de arestas

```cpp
// Estrutura para representar uma aresta
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Estrutura para Union-Find
struct DisjointSet {
    vector<int> parent, rank;
    
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return;
        
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY])
                rank[rootX]++;
        }
    }
};

// Algoritmo de Kruskal para MST
vector<Edge> kruskal(vector<Edge> edges, int n) {
    vector<Edge> result;
    sort(edges.begin(), edges.end());
    
    DisjointSet ds(n);
    
    for (Edge edge : edges) {
        int rootU = ds.find(edge.u);
        int rootV = ds.find(edge.v);
        
        if (rootU != rootV) {
            result.push_back(edge);
            ds.unite(rootU, rootV);
        }
    }
    
    return result;
}
```

## Otimização

### Programação Dinâmica

#### Problema da Mochila (Knapsack)
- Dado um conjunto de itens com pesos e valores, encontrar o subconjunto de valor máximo que caiba em uma mochila de capacidade W
- Complexidade: O(n * W) onde n é o número de itens e W é a capacidade da mochila

```cpp
// Resolve o problema da mochila 0-1
int knapsack(vector<int> weights, vector<int> values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i-1] <= w)
                dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    
    return dp[n][W];
}
```

#### Subsequência Comum Mais Longa (LCS)
- Encontrar a subsequência mais longa que é comum a duas sequências
- Complexidade: O(m * n) onde m e n são os comprimentos das sequências

```cpp
// Encontra o comprimento da subsequência comum mais longa
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return dp[m][n];
}
```

### Técnicas de Otimização

#### Decomposição por Raiz Quadrada
- Divide um array em blocos de tamanho aproximadamente √n
- Útil para consultas de intervalo eficientes
- Complexidade: O(√n) por consulta

```cpp
// Implementação de decomposição por raiz quadrada para consultas de soma
class SqrtDecomposition {
private:
    vector<int> arr;
    vector<int> blocks;
    int blockSize;
    int numBlocks;
    
public:
    SqrtDecomposition(vector<int>& input) {
        arr = input;
        int n = arr.size();
        blockSize = sqrt(n);
        numBlocks = (n + blockSize - 1) / blockSize;
        blocks.resize(numBlocks, 0);
        
        for (int i = 0; i < n; i++)
            blocks[i / blockSize] += arr[i];
    }
    
    // Atualiza um elemento
    void update(int idx, int val) {
        int blockIdx = idx / blockSize;
        blocks[blockIdx] -= arr[idx];
        blocks[blockIdx] += val;
        arr[idx] = val;
    }
    
    // Consulta a soma no intervalo [l, r]
    int query(int l, int r) {
        int sum = 0;
        int startBlock = l / blockSize;
        int endBlock = r / blockSize;
        
        if (startBlock == endBlock) {
            // Intervalo está dentro de um único bloco
            for (int i = l; i <= r; i++)
                sum += arr[i];
        } else {
            // Soma dos elementos restantes no primeiro bloco
            for (int i = l; i < (startBlock + 1) * blockSize; i++)
                sum += arr[i];
            
            // Soma dos blocos completos
            for (int i = startBlock + 1; i < endBlock; i++)
                sum += blocks[i];
            
            // Soma dos elementos no último bloco
            for (int i = endBlock * blockSize; i <= r; i++)
                sum += arr[i];
        }
        
        return sum;
    }
};
```

## Probabilidade e Estatística

### Conceitos Básicos

#### Probabilidade
- Probabilidade de um evento A: P(A) = número de casos favoráveis / número de casos possíveis
- Probabilidade condicional: P(A|B) = P(A ∩ B) / P(B)
- Eventos independentes: P(A ∩ B) = P(A) * P(B)
- Eventos mutuamente exclusivos: P(A ∪ B) = P(A) + P(B)
- Regra geral da união: P(A ∪ B) = P(A) + P(B) - P(A ∩ B)

#### Valor Esperado
- Para uma variável aleatória discreta X: E[X] = ∑ x * P(X = x)
- Linearidade da expectativa: E[X + Y] = E[X] + E[Y]

```cpp