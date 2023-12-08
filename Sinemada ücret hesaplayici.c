#include <stdio.h>
#include <stdlib.h>
int main() {
//Sinemada ücret hesaplayici
	int misir,su,kola,bilet,toplam,a,b,c,d;
	
	misir=20;
	su=5;
	kola=30;
	bilet=90;
	printf("(misir 20TL,su 5TL,kola 30TL,bilet 90TL)\n\n");
	printf("********Sinemamiza Hosgeldiniz******** \n\n");
	
	printf("Alinan su sayisi: ");
	scanf("%d",&a);
	
	printf("Alinan misir sayisi: ");
	    scanf("%d",&b);
		
	printf("Alinan kola sayisi: ");
	scanf("%d",&c)   ;
		
	printf("alinan bilet: ");
	scanf("%d",&d);
		
	toplam=(misir*b)+(su*a)+(kola*c)+(bilet*d);
		  
	printf("Toplam tutar: %d",toplam ) ;	
	return 0;
}
