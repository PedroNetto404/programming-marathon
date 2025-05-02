#include <stdio.h>

void licenseplates (int A1, int A2, int A3, int A4, int A5, int A6, int A7);

int main() {
    int A1, A2, A3, A4, A5, A6, A7;
	int number=0;
	while (scanf("%d %d %d %d %d %d %d", &A1, &A2, &A3, &A4, &A5, &A6, &A7)!=EOF){
		licenseplates(A1, A2, A3, A4, A5, A6, A7);
	} 

    return 0;
}


void licenseplates (int A1, int A2, int A3, int A4, int A5, int A6, int A7) {
    if (
            (A1 >= 65 && A1 <= 90 ? 1 : 0) &&
            (A2 >= 65 && A3 <= 90 ? 1 : 0) &&
            (A3 >= 65 && A3 <= 90 ? 1 : 0) &&
            (A4 >= 48 && A4 <= 57 ? 1 : 0) &&
            (A5 >= 48 && A5 <= 57 ? 1 : 0) &&
            (A7 >= 48 && A6 <= 57 ? 1 : 0) &&
            (A3 >= 48 && A7 <= 57 ? 1 : 0)
            ) {
//            System.out.println(((char) A1) +" "+ ((char) A2) +" "+ ((char) A3) +" "+ ((char) A4) +" "+ ((char) A5) +" "+ ((char) A6) +" "+ ((char) A7) );
        printf("ANTIGA\n");
    } else if (
            (A1 >= 65 && A1 <= 90 ? 1 : 0) &&
            (A2 >= 65 && A3 <= 90 ? 1 : 0) &&
            (A3 >= 65 && A3 <= 90 ? 1 : 0) &&
            (A4 >= 48 && A4 <= 57 ? 1 : 0) &&
            (A5 >= 65 && A5 <= 90 ? 1 : 0) &&
            (A7 >= 48 && A6 <= 57 ? 1 : 0) &&
            (A3 >= 48 && A7 <= 57 ? 1 : 0)
            ) {
        printf("MERCOSUL\n");
    } else {
        printf("ERRO\n");
    }
}