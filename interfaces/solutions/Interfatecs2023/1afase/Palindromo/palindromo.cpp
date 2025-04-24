#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <regex>
#include <cctype>

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

    string frase, rfrase, sub, rsub;
    size_t nponto;

    while (getline(cin, frase)) {
        for_each(frase.begin(), frase.end(), [](char& c) { 
                c = isalpha(c) ? tolower(c) : ' '; 
        });
        for(auto item : map_special) {
            frase = regex_replace(frase, regex(item.first), item.second);
        }
        for_each(frase.begin(), frase.end(), [](char& c) { 
                c = isalpha(c) ? c : ' '; 
        });
        frase = regex_replace(frase, regex(" "), "");
        nponto = frase.find('.');
        if (nponto != string::npos && nponto < frase.size()-1) {
            cout << "A busca continua, o Palindromo Perdido ainda nao foi encontrado." << endl;
            continue;
        }
        rfrase = frase;
        reverse(rfrase.begin(), rfrase.end());
        if (frase == rfrase)
            cout << "Parabens, voce encontrou o Palindromo Perdido!" << endl;
        else
            cout << "A busca continua, o Palindromo Perdido ainda nao foi encontrado." << endl;
    }
    return 0;
}
