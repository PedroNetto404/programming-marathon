#include <iostream>
#include <iomanip>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int t, dur, tot, a;
} Load;

typedef vector<Load>* Server;

vector<Load> loads;
vector<Server> servers;

bool cmp_t(const Load &a, const Load &b) {
    return a.t < b.t;
}

int main(int argc, char const *argv[])
{
    int s, r, a, mins, ct, srv;
    Load ld;

    cin >> s;
    for (int i = 0; i < s; i++)
        servers.push_back(new vector<Load>);
    cin >> r;
    cin >> a;
    for (int i = 0; i < r; i++) {
        cin >> ld.t >> ld.dur;
        ld.tot = ld.t + ld.dur;
        ld.a = i == a-1 ? a : 0;
        loads.push_back(ld);
    }

    sort(loads.begin(), loads.end(), cmp_t);

    for (Load l: loads) {
        mins = INT_MAX;
        for (int s = 0; s < servers.size(); s++) {
            ct = count_if(servers[s]->begin(), servers[s]->end(), [l](Load sload){
                return l.t < sload.tot;     
            });
            if (ct < mins) {
                mins = ct;
                srv = s;
            }
        }
        servers[srv]->push_back(l);
        if (l.a > 0)
            cout << srv+1 << endl;
    }

    return 0;
}
