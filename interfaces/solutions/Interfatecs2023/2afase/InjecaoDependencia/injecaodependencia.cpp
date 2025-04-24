#include <iostream>
#include <iomanip>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<char> AdjList;

map<char, AdjList*> graph;

vector<char> path;

int find_path(char a, AdjList *adjl) {
    if (find(path.begin(), path.end(), a) != path.end())
        return 1;
    path.push_back(a);
    for (auto b: *adjl) {
        auto bt = graph.find(b);
        if (bt != graph.end() and find_path(b, bt->second))
            return 1;
    }
    return 0;
}

int main() {
    int n;
    char a, b;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (graph.find(a) == graph.end()) {
            graph[a] = new AdjList;
            graph[a]->push_back(b);            
        } else {
            graph[a]->push_back(b);
        }
    } 

    for(auto it: graph) {
        path.clear();    
        if (find_path(it.first, it.second)) {
            cout << "usar injecao tardia" << endl;
            return 0;
        }
    }

    cout << "ok" << endl;

    return 0;
}
