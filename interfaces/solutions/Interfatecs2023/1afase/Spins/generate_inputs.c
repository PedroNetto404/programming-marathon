#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int n, q;

    scanf("%d %d", &n, &q);

    n++;
    srand(time(NULL));
    for (int i = 0; i < q; i++)
        printf("%d\n", rand() % n);

    printf("0\n");
    return 0;
}

