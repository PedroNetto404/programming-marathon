#include <iostream>
#include <climits>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, i;

    cin >> n;
    for (i = 1; i < n; i++) {
        if (i % 4 == 0)
            cout << "pim ";
        else
            cout << i << " ";
    }
    
    if (i % 4 == 0)
        cout << "pim\n";
    else
        cout << i << endl;
    
    return 0;
}
