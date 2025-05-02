#include <iostream>
#include <cmath>

using namespace std;
 
#define MAXN 10000
#define SQRSIZE  100
 
long arr[MAXN];               
long block[SQRSIZE] = {0};          
long blk_sz;                  
 
int main() {

    long t, sum, l, r, v1, v2;
    cin >> t;
    cin >> v1 >> v2;

    long input[t];
    for(long i=0; i<t; i++)
      cin >> input[i];

    long n = sizeof(input)/sizeof(input[0]); 
    long blk_idx = -1;
 
    blk_sz = sqrt(n);
 
    for (long i=0; i<n; i++) {
        arr[i] = input[i];
        if (i%blk_sz == 0) {
            blk_idx++;
        }
        if (arr[i] >= v1 and arr[i] <= v2)
          block[blk_idx]++;
    }
    
    while(cin >> l >> r) {
      sum = 0;
      l--;
      r--;
      while (l<r and l%blk_sz!=0 and l!=0) {
          if (arr[l] >= v1 and arr[l] <= v2)
            sum++;
          l++;
      }

      while (l+blk_sz-1 <= r) {
          sum += block[l/blk_sz];
          l += blk_sz;
      }

      while (l<=r) {
          if (arr[l] >= v1 and arr[l] <= v2)
            sum++;
          l++;
      }
      cout << sum << endl;
    }


    return 0;
}
