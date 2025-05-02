#include <iostream>

using namespace std;

int main()
{
    int L, C, B, X, Y, batidas;
    string acoes;

    cin >> L >> C >> B;
    cin >> X >> Y;
    cin >> acoes;

    batidas = 0;
    for(char& a : acoes) {
        if (B == 0)
            break;
        switch(a) {
            case 'C':
                if (X-1 == 0)
                    batidas++;
                else
                    X--;
                break;
            case 'B':
                if (X+1 > L)
                    batidas++;
                else
                    X++;
                break;
            case 'E':
                if (Y-1 == 0)
                    batidas++;
                else
                    Y--;
                break;
            case 'D':
                if (Y+1 > C)
                    batidas++;
                else
                    Y++;
                break;
        }
        B--;
    }

    cout << X << " " << Y << " " << batidas << endl;

    return 0;
}
