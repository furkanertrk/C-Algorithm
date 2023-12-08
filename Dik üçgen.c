#include <stdio.h>
#include <stdlib.h>
int main() {
	int i,j,k;
	printf("Sayi giriniz: ");
	scanf("%d",&k); 
	printf("\n"); 
	for(i=1;i<=k;i++){
		for(j=1;j<=i;j++){
			printf("%d",j);
		}
		printf("\n"); 
	} 
	for(i=1;i<=k;i++){
		for(j=1;j<=k-i;j++){
			printf("%d",j);
		}
		printf("\n"); 
	}
	
	return 0;
}
