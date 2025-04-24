#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int v;
    double vt;

    cin >> v;

    if (v <= 107)
        vt = v+7;
    else
        vt = v*1.07;

    cout << fixed << setprecision(0) << vt << endl;

    return 0;
}
