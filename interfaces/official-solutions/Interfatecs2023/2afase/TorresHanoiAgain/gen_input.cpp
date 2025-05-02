#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    
    int n, min, num, d;
    string sb = "";

    srand(time(NULL));

    n = atoi(argv[1]);
    min = pow(2, n) - 1;
    num = rand() % min + 1;
    
    cout << n << endl;
    d = num;    
    while (num > 1) {
        d = num % 2;
        num /= 2;
        sb += to_string(d);        
    }
    sb += to_string(num);

    reverse(sb.begin(), sb.end());
    for(int i = 0; i < sb.size()-1; i++)
        cout << sb[i] << " ";
    cout << sb[sb.size()-1] << endl;

    return 0;
}
