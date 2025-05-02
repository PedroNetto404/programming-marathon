#include <iostream>

using namespace std;
 
int main()
{
    long t, s, e, sum, i, v1, v2;
    
    cin >> t;
    cin >> v1 >> v2;

    long input[t];
    
    for(i=0; i<t; i++)
      cin >> input[i];

    while(cin >> s >> e) {
      sum=0;
      for(i=s-1; i<e; i++)
        if (input[i] >= v1 && input[i] <= v2)
          sum++;
      cout << sum << endl;
    }

    return 0;
}
