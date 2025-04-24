#include <iostream>

using namespace std;
 
int main() {
    
    int n;
    
    cin >> n;
    while (n != 0) {
        for (long i = 1; i*i <= n; i++) {
            if (i > 1)
                cout << " ";
            cout << i*i;
        }
        cout << endl;
        cin >> n;
    }
 
    return 0;
}
