#include <iostream>
#include <cmath>
#include <limits>

void fast_io()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

int main()
{
    fast_io();

    int n0 = 0, n  = 0, t;
    while (std::cin >> n0)
    {
        std::cin >> n >> t;

        double result = (std::log(static_cast<double>(n0)/ n) * t)/ std::log(2.0);
        std::cout << std::trunc(result) << '\n';
    }

    return 0;
}