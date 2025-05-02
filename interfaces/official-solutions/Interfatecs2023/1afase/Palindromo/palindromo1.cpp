#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

int main()
{
    map<string, string> map_special;

    map_special.insert(pair<string, string>("ç", "c"));
    map_special.insert(pair<string, string>("é", "e"));
    map_special.insert(pair<string, string>("á", "a"));
    map_special.insert(pair<string, string>("ó", "o"));
    map_special.insert(pair<string, string>("ô", "o"));
    map_special.insert(pair<string, string>("à", "a"));
    map_special.insert(pair<string, string>("ã", "a"));
    map_special.insert(pair<string, string>("õ", "o"));
    map_special.insert(pair<string, string>("õ", "o"));
    map_special.insert(pair<string, string>("ú", "u"));
    map_special.insert(pair<string, string>("í", "i"));
    map_special.insert(pair<string, string>("â", "a"));
    map_special.insert(pair<string, string>(",", ""));
    map_special.insert(pair<string, string>("-", ""));
    map_special.insert(pair<string, string>("_", ""));
    map_special.insert(pair<string, string>(" ", ""));

    string frase, rfrase, sub, rsub;
    size_t nponto, i;

    while (getline(cin, frase)) {
        for_each(frase.begin(), frase.end(), [](char& c) { 
                c = tolower(c); 
        });
        for(auto item : map_special) {
            frase = regex_replace(frase, regex(item.first), item.second);
        }
        cout << frase << endl;
        nponto = frase.find('.');
        if (nponto != string::npos && nponto < frase.size()-1) {
            i = 0;
            while (nponto != string::npos) {
                sub = frase.substr(i, nponto);
                rsub = sub;
                reverse(rsub.begin(), rsub.end());
            }
        }
        else {
            frase = regex_replace(frase, regex("\\."), "");
            rfrase = frase;
            reverse(rfrase.begin(), rfrase.end());
            if (frase == rfrase)
                cout << "Parabens, voce encontrou o Palindromo Perdido!" << endl;
            else
                cout << "A busca continua, o Palindromo Perdido ainda nao foi encontrado." << endl;
        }
    }
    return 0;
}
