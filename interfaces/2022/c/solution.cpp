#include <iostream>
#include <cmath> 

int main() {
    
    long number = 0;
    long sum = 0;
    while((std::cin >> number) && number != 0) 
    {
        // an = a1 + (n - 1) * r
        // S = (a1 + an) * (n / 2) => S = (a1 + (a1 + (n - 1) * r)) * (n / 2)
        // => S = (a1 + a1 + r * n - r) * (n / 2)
        // => S = (2 * a1 + r * n - r) *(n / 2)  
        // a1 = 1, r = 2
        // => S = (2 * 1 + 2 * n - 2) * (n / 2)
        // => S = (2 * n) *  (n/2)
        // => S = n * n
        // cqd. n = sqrt(S) && an = 1 + (sqrt(S) - 1) * 2 = 2 * sqrt(S) - 1 
        double n = std::sqrt(number);

        if (std::trunc(n) != n) {
            std::cout << "PERA AI... TA LIDANDO ERRADO!" << '\n';
            continue;
        }

        long an = 2 * (long)n - 1;        
        std::cout << an << '\n';
    }

    return 0; 
}