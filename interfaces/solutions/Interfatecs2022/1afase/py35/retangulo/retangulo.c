#include <stdio.h>

void retangulo ();

int main() {
    retangulo();
    return 0;
}

void retangulo (){
	int QL;
	int QC;
	int L;
    int C;
	scanf("%d %d %d %d", &QL, &QC, &L, &C);
	long long int arr[QL][QC];
	for (int i=0; i<QL; i++){
		for(int k=0; k<QC; k++){
			if (i==0){
				arr[i][k]=0;
			} else if (k==QC-1){
				arr[i][k]=1;
			} else if(i==QL-1){
				arr[i][k]=2;
			} else if(k==0){
				arr[i][k]=3;
			} else
				arr[i][k]=arr[i-1][k]+arr[i][k-1]+arr[i-1][k-1];
		}
	}
	printf("%ld\n", arr[L-1][C-1]);
	
}
