#include <stdio.h>

void contagem ();

int main() {
    contagem();
    return 0;
}

void contagem (){
    int gw = 1;
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for (i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int k=1;
    for (i=0; i<n; i++){
        while (k<=arr[i]){
            if (k<arr[i]){
                printf("%d\n", k);
                gw=0;
            }
            k++;
        }
    }
    if (gw){
        printf("bom trabalho\n");
    }
}