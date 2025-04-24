#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    
    cin >> a >> b >> c;
    vector<int> dp{ a, b, c };
    sort(dp.begin(), dp.end());
    cout << dp[1] << endl;

    return 0;
}
