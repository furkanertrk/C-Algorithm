#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
char *aramafonk(char *a, char aranan);
int main() {
    setlocale(LC_ALL,"Turkish");
    char metin[100];
    printf("Metin girin: "); 
    scanf("%s", metin);
    char aranan;
    printf("Aranacak karakteri girin: ");
    scanf(" %c", &aranan);
    char *sonuc = aramafonk(metin, aranan);
    if (sonuc != NULL) {
        printf("Karakter bulundu. Karakterin adresi: %p\n", (void*)sonuc);
    } else {
        printf("Karakter bulunamadý.\n");
    }
    return 0;
}
char *aramafonk(char *a, char aranan) {
    while (*a != '\0') {
        if (*a == aranan) {
            return a;
        }
        a++;
    }
    return NULL;
}
