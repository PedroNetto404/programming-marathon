#include <iostream>
#include <iomanip>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    int n, min, num = 0, v;

    cin >> n;
    min = pow(2, n) - 1; 
    for (int i = n-1; i >= 0; i--) {
        cin >> v;
        num += v * pow(2,i); 
    }

    cout << min - num << endl;
    return 0;
}
