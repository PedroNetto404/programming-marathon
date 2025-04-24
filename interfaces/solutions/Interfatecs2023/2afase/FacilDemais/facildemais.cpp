#include <iostream>
#include <iomanip>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> positions;

bool eh_primo(int n) {
    for (int i = 2; i < n/2; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int n, s = 0, num;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        positions.push_back(num);
    }

        

    return 0;
}
