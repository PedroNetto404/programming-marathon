#include <stdio.h>
 
int main() {
    
    int n;
    
    scanf("%d", &n);
    while (n != 0) {
        for (long i = 1; i*i <= n; i++) {
            if (i > 1)
                printf(" ");
            printf("%ld", i*i);
        }
        printf("\n");
        scanf("%d", &n);
    }
 
    return 0;
}
