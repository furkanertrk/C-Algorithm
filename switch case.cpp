#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main() {


	int secim;
	printf("Bu programda secebileceginiz islemler\n\n");
	printf("1-Kenar uzunlugunu gireceginiz karenin alan ve cevre hesabi\n");
	printf("2-Dik kenarlarinin uzunlugunu gireceginiz dik ucgenin alan ve cevre hesabi\n");
	printf("3-Yaricapini gireceginiz cemberin alan ve cevre hesabi\n");
	printf("4-Gireceginiz sayinin faktoriyel hesabi\n");
	printf("5-Gireceginiz bir sayinin kupunun hesabi\n");
	printf("6-Gireceginiz bir degerin karekokunu alma\n");
	printf("7-Dik ucgende hipotenus hesabi\n");
	printf("8-Bir kupun hacminin hesabi\n");
	printf("9-Bir silindirin hacminin hesabi\n");
	printf("10-Koninin alaninin ve hacminin hesabi\n");
	
	printf("Lutfen kullanmak istediginiz modulun rakamini giriniz : ");
	scanf("%d", &secim);

	switch (secim)
	{
		case 1: 
			int kenar;
			printf("\n\nLutfen karenin bir kenarini giriniz : ");
			scanf("%d", &kenar);
			printf("Karenin alani : %d\n", (kenar * kenar));
			printf("Karenin cevresi : %d\n", (4 * kenar));
			break;

		case 2: 
			int kenar1, kenar2, alan, cevre, kare, hip;
			printf("\n\nLutfen dik kenarlardan ilkini giriniz : ");
			scanf("%d", &kenar1);
			printf("Lutfen ikinci kenari giriniz : ");
			scanf("%d", &kenar2);

			alan = (kenar1 * kenar2) / 2;
			kare = (kenar1 * kenar1 + kenar2 * kenar2);
			hip = sqrt(kare);
			cevre = kenar1 + kenar2 + hip;
			printf("Dik ucgende hipotenus %d olarak bulunur.\n", hip);
			printf("Dik ucgenin alani : %d\n", alan);
			printf("Dik ucgenin cevresi: %d\n", cevre);
			break;
		
		case 3:
			// alan pi*r*r , cevre 2*pi*r
			float pi, r, cev, al;
			pi = 3.14;
			printf("\n\nLutfen cemberin yaricapini giriniz : ");
			scanf("%f", &r);

			cev = 2 * pi * r;
			al = pi * r * r;
			printf("Cemberin alani: %f olarak bulunur.\n", al);
			printf("Cemberin cevresi %f olarak bulunur.", cev);
			break;

		case 4:
			int faktoriyel, sayi;
			faktoriyel = 1;
			printf("\n\nFaktoriyelini bulmak istediginiz sayiyi giriniz :");
			scanf("%d", &sayi);

			while (sayi > 1)
			{
				faktoriyel = faktoriyel * sayi;
				sayi--;
			}

			printf("Faktoriyel sonucunuz : %d", faktoriyel);
			break;

		case 5:
			int a, kup;
			printf("\n\nLutfen kupunu bulmak istediginiz sayiyi giriniz : ");
			scanf("%d", &a);
			kup = a * a * a;
			printf("Girdiginiz degerin ucuncu kuvveti : %d", kup);
			break;

		case 6:
			float deger, cevap;
			printf("\n\nKarekokunu bulmak icin bir deger giriniz: ");
			scanf("%f", &deger);
			cevap = sqrt(deger);
			printf("Karekok degeriniz : %f", cevap);
			break;

		case 7:
			float x, y, z, t;
			printf("\n\nLutfen dik kenarlardan birincisini giriniz : ");
			scanf("%f", &x);
			printf("Lutfen dik kenarlardan ikincisini giriniz :");
			scanf("%f", &y);
			t = x * x + y * y;
			z = sqrt(t);
			printf("\nGirdiginiz degerlerdeki dik ucgenin hipotenusu : %f", z);
			break;
		case 8:
			float uzunluk, hcm;
			printf("\n\nLutfen kubun bir kenarinin uzunlugunu giriniz: ");
			scanf("%f", &uzunluk);

			hcm = uzunluk * uzunluk * uzunluk;
			printf("Girdiginiz kenara sahip olan bir kubun hacmi : %f", hcm);
			break;

		case 9:
			float cap, yks, hacim, p;
			p = 3.14;
			printf("\n\nLutfen dik silindirin tabanindaki cemberin yaricapini giriniz : ");
			scanf("%f", &cap);
			printf("Lutfen dik silindirin yuksekligini giriniz : ");
			scanf("%f", &yks);
			hacim = p * cap * cap * yks;
			printf("Silindirin hacmi : %f", hacim);
			break;

		case 10:
			float pi_sayisi, yaricap_koni, alan_koni, hacim_koni, yukseklik_koni, emre;
			printf("\n\nLutfen koninin yaricapini giriniz : ");
			scanf("%f", &yaricap_koni);
			printf("Lutfen koninin yuksekligini giriniz : ");
			scanf("%f", &yukseklik_koni);

			pi_sayisi = 3.14;
			hacim_koni = pi_sayisi * yaricap_koni * yaricap_koni * yukseklik_koni / 3;
			emre = sqrt(yaricap_koni * yaricap_koni + yukseklik_koni * yukseklik_koni);
			alan_koni = pi_sayisi * yaricap_koni * (yaricap_koni + emre);

			printf("Girdiginiz degerlerdeki konin alani : %f\n", alan_koni);
			printf("Girdiginiz degerlerdeki konin hacmi : %f", hacim_koni);
			break;
			


		default: printf("\n\nMevcut olmayan bir modulu sectiniz. Tekrar deneyiniz !"); break;
	}
	return 0;
}

