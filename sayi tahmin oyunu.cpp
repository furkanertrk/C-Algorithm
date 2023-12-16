#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {
    srand(time(NULL));
    jump:
    printf("Zorluk ne olsun? (Kolay 1, Orta 2, Zor 3)\n==> ");
    int aa;
    scanf("%d",&aa); 
    if(aa==1) aa=100;
    else if(aa==2) aa=200;
    else if(aa==3) aa=300;
    else if(aa!= 1 && aa!= 2 && aa!= 3){
    	 printf("Hatali giris\n\n"); 
		 goto jump;
	}
    int rastgele_sayi = rand() % aa + 1;
    int tahmin, sayac = 0;
    printf("1 ile %d arasinda bir sayi tahmin edin.\n", aa);
    do {
        printf("Tahmininiz: ");
        scanf("%d", &tahmin);

        sayac++;
        if (tahmin == rastgele_sayi) {
            printf("Tebrikler! %d. denemede bildiniz.\n", sayac);
        } else if (tahmin < rastgele_sayi) {
            printf("Daha buyuk bir sayi tahmin edin.\n");
        } else {
            printf("Daha kucuk bir sayi tahmin edin.\n");
        }

    } while (tahmin != rastgele_sayi);
    if(sayac<10) printf("%d puan kazandiniz.",10-sayac); 
	else printf("Kaybettiniz.");
    return 0;
}
