#include <stdio.h>
#include <stdlib.h>

int main() {
	//fak hesaplayan kod
	int i,fak;
	fak=1;
	printf("Sayi gir: ");
	scanf("%d",&i);
	while(i>1){
		fak=fak*i ; 
		i--;
	}
	printf("Sonuc: %d",fak);
	return 0;
}
