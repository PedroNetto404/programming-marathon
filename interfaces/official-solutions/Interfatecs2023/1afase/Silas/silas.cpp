#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct {
    int x;
    int y;
    int depth;
} TPos;
    
int map[80][80] = {{0}};

vector<TPos> fringe;
vector<TPos> visited;
int X, Y;

int valid_pos(int x, int y) {
    return x >= 0 && x < X && y >= 0 && y < Y;
}

int breadth_search(int *force) {
    TPos node;
    char e;

    while(1) {
        if (fringe.empty())
            return -1;

        node = *fringe.begin();
        fringe.erase(fringe.begin());
        
        e = map[node.x][node.y];
        if (e == 'K')
            return node.depth;

        if (e != '.' && e != '#') {
            string se(1, e);
            int ie = stoi(se);
            if (ie <= *force) {
                *force -= ie;
                break;
            }
        } else if (e == '.')
            break;
    }

    for (int i = node.x-1; i < node.x+1; i++) {
        for (int j = node.y-1; j < node.y+1; j++) {
            if (valid_pos(i, j) && 
                    find_if(visited.begin(), visited.end(), [i, j](TPos p){ return p.x == i && p.y == j; }) != visited.end()) {
                TPos nnode { i, j, node.depth+1 };
                fringe.push_back(nnode);
            }
        }
    }

    return breadth_search(force);
}

int main(int argc, char *argv[])
{
    int f;
    char v;
    
    cin >> f;
    cin >> X >> Y;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            if (!cin >> map[i][j]) {
                cin >> v;
                switch (v) {
                    case 'K': 
                        map[i][j] = -100;
                        break;
                    case '#':
                        map[i][j] = -10;
                        break;
                    case '.':
                        map[i][j] = -1;
                        break; 
                }
            }   
            cout << map[i][j] << ",";
        }
        cout << endl;
    }

    /*
    int steps = breadth_search(&f);

    if (steps > -1)
        cout << steps << endl;
    else
        cout << 'N' << endl;
     */
    return 0;
}
