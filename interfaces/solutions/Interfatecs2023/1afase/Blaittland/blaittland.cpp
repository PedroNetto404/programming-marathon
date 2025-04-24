#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, r, d;
    size_t p;
    string livros, lv_org;

    cin >> n;
    cin >> livros;

    lv_org = livros;
    sort(lv_org.begin(), lv_org.end());

    r = 0;
    for (int i = 0; i < n; i++) {
        if (livros[i] != lv_org[i]) {
            p = lv_org.find(livros[i]);
            d = (p - i);
            if (d > 5) {
                cout << "A Database Systems student read a book." << endl;
                return 0;
            }
            r += d;
            lv_org = lv_org.substr(0, i) + livros[i] + lv_org.substr(i, d) + lv_org.substr(p + 1);
        }
    }
    cout << r << endl;

    return 0;
}
