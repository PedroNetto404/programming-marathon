#include <iostream>
#include <iomanip>
#include <climits>

using namespace std; 

int main(int argc, char const *argv[]) {
    int num_cand, g, e, a, d, t;

    cin >> num_cand;
    for (int i = 0; i < num_cand; i++) {
        cin >> g >> e >> a >> d >> t;
        if (g == 1) {
            if (a == 1 or d == 1) {
                if (t >= 3)
                    cout << "Cand. " << i+1 << ": deferido (comprovar 3 anos)" << endl;
                else
                    cout << "Cand. " << i+1 << ": INDEFERIDO (exp)" << endl;
            } else if (e == 1) {
                if (t >= 5)
                    cout << "Cand. " << i+1 << ": deferido (comprovar 5 anos)" << endl;
                else
                    cout << "Cand. " << i+1 << ": INDEFERIDO (exp)" << endl;
            } else 
                cout << "Cand. " << i+1 << ": INDEFERIDO (acad)" << endl;
        } else {
            if (a == 1) {
                if (t >= 3)
                    cout << "Cand. " << i+1 << ": deferido (comprovar 3 anos)" << endl;
                else
                    cout << "Cand. " << i+1 << ": INDEFERIDO (exp)" << endl;
            } else 
                cout << "Cand. " << i+1 << ": INDEFERIDO (acad)" << endl;
        }
    }  

    return 0;
}
