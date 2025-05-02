#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    string forma, letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n;

    cin >> n;
    cin >> forma;

    if (forma == "minusculas")
        for_each(letras.begin(), letras.end(), [](char& c) {
                c = tolower(c);
        });

    for (int i = 0, c = 1; i < n; i++, c++) {
        int l = 0;
        while (l < 26-c) {
            cout << ".";
            ++l;
        }
        l = 0;
        while (l < c)
            cout << letras[l++];
        cout << endl;
    }
    return 0;
}
