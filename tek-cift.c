#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("*****Sayi alan ve bu sayilari tek/cift seklinde ayiran kod*****\n\n");
	int a,i;
	printf("kac tane sayi olsun: ");
	
	scanf("%d",&a); 
    int dizi[a];
    for(i = 0; i < a; i++){
        printf("%d. Sayiyi Giriniz: ", i + 1);
        scanf("%d", &dizi[i]);
    }
    printf("\n\n");
    printf("Ciftler: ");
    for(i=0;i<a;i++){
    	if(dizi[i]%2==0) printf("%d ",dizi[i]);  
	}
	printf("\n");
	printf("Tekler: ");
    for(i=0;i<a;i++){
    	if(dizi[i]%2==1) printf("%d ",dizi[i]);  
	}
	return 0;
}
