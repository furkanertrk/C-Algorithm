#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Adres bilgilerini tutmak için ikinci bir struct kullanıyoruz.
    Struct içinde struct kullanımını göstermek için eklenmiştir.
*/
typedef struct {
    char il[30];
    char ilce[30];
    char mahalle[50];
} Adres;

/*
    Banka hesap bilgilerini tutan struct.
    İçinde adres yapısı gömülü olarak kullanılır.
*/
typedef struct {
    int hesapNo;
    char ad[30];
    char soyad[30];
    Adres adres;
    float bakiye;
} Hesap;

/*
    Dinamik dizi için global pointer ve kayıt sayısı bilgisi.
    'Hesap *hesaplar' tüm hesapları dinamik dizi şeklinde tutar,
    'toplamHesap' ise kayıt sayısını tutar.
*/
Hesap *hesaplar = NULL;
int toplamHesap = 0;

/* Fonksiyon Prototipleri */
void menu();
void dosyadanOku();
void dosyayaYaz();

void hesapEkle();
void hesapListele();
void hesapGuncelle();
void hesapSil();
void paraYatir();
void paraCek();

/* Ana fonksiyon */
int main() {
    /* Program açıldığında önce dosyadan mevcut hesapları okuyalım. */
    dosyadanOku();

    /* Menü üzerinden kullanıcı işlemlerini başlatalım. */
    menu();

    /* Program kapanırken hesapları dosyaya kaydedelim. */
    dosyayaYaz();

    /* Artık kullanmadığımız bellek alanını serbest bırakalım. */
    free(hesaplar);

    return 0;
}

/* ------------------- MENÜ FONKSİYONU ------------------- */
void menu() {
    int secim;

    do {
        printf("\n--- BANKA OTOMASYONU ---\n");
        printf("1. Yeni Hesap Ekle\n");
        printf("2. Hesaplari Listele\n");
        printf("3. Hesap Guncelle\n");
        printf("4. Hesap Sil\n");
        printf("5. Para Yatir\n");
        printf("6. Para Cek\n");
        printf("0. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);
        getchar(); /* Giriş sırasında kalan '\n' karakterlerini temizlemek için */

        switch(secim) {
            case 1:
                hesapEkle();
                break;
            case 2:
                hesapListele();
                break;
            case 3:
                hesapGuncelle();
                break;
            case 4:
                hesapSil();
                break;
            case 5:
                paraYatir();
                break;
            case 6:
                paraCek();
                break;
            case 0:
                printf("Cikis yapiliyor...\n");
                break;
            default:
                printf("Gecersiz secim!\n");
        }
    } while(secim != 0);
}

/* ------------------ DOSYA İŞLEMLERİ ------------------
   - Program açılırken dosyadanOku():
        'hesaplar.txt' dosyasında bulunan hesap bilgilerini
        satır satır okuyup dinamik diziye yüklüyor.
   - Program kapanırken dosyayaYaz():
        Bellekteki tüm hesapları 'hesaplar.txt' dosyasına yazıyor.
*/

/* 1) DOSYADAN OKUMA */
void dosyadanOku() {
    FILE *fp = fopen("hesaplar.txt", "r");
    if(fp == NULL) {
        // Dosya henüz yoksa, kayıt bulunmuyor olabilir. Hata vermeden geç.
        return;
    }

    Hesap temp;
    while(1) {
        /* Dosyadan okurken fscanf ile aynı sırada yazılmış değişken tiplerinin
           hepsini okumaya çalışıyoruz. Sıralama:
           hesapNo -> ad -> soyad -> il -> ilce -> mahalle -> bakiye
           Eğer okuma başarıyla tamamlanırsa 'okunan' değeri 7 olur.
        */
        int okunan = fscanf(
            fp,
            "%d %s %s %s %s %s %f",
            &temp.hesapNo,
            temp.ad,
            temp.soyad,
            temp.adres.il,
            temp.adres.ilce,
            temp.adres.mahalle,
            &temp.bakiye
        );

        if(okunan == 7) {
            /* Hesabı diziye eklemek için önce 1 eleman genişletilir. */
            toplamHesap++;
            hesaplar = (Hesap*)realloc(hesaplar, toplamHesap * sizeof(Hesap));
            if(hesaplar == NULL) {
                printf("Bellek yetersizligi!\n");
                fclose(fp);
                exit(1);
            }
            /* Yeni kaydı dizinin sonuna yerleştir. */
            hesaplar[toplamHesap - 1] = temp;
        }
        else {
            /* Okuma başarısız veya dosya sonu, döngüden çık. */
            break;
        }
    }

    fclose(fp);
}

/* 2) DOSYAYA YAZMA */
void dosyayaYaz() {
    FILE *fp = fopen("hesaplar.txt", "w");
    if(fp == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }

    for(int i = 0; i < toplamHesap; i++) {
        Hesap h = hesaplar[i];
        /* Dizideki her hesabı düzenli şekilde dosyaya yazıyoruz.
           fscanf() ile 7 değişken okuduysak, fprintf() ile 7 değişken yazmalıyız.
        */
        fprintf(fp, "%d %s %s %s %s %s %.2f\n",
                h.hesapNo,
                h.ad,
                h.soyad,
                h.adres.il,
                h.adres.ilce,
                h.adres.mahalle,
                h.bakiye);
    }

    fclose(fp);
}

/* ------------------ 1) HESAP EKLE ------------------ */
void hesapEkle() {
    Hesap yeni;
    printf("\n--- Yeni Hesap Ekle ---\n");
    printf("Hesap Numarasi: ");
    scanf("%d", &yeni.hesapNo);
    getchar();

    printf("Musteri Adi: ");
    scanf("%s", yeni.ad);
    printf("Musteri Soyadi: ");
    scanf("%s", yeni.soyad);

    printf("Adres - Il: ");
    scanf("%s", yeni.adres.il);
    printf("Adres - Ilce: ");
    scanf("%s", yeni.adres.ilce);
    printf("Adres - Mahalle: ");
    scanf("%s", yeni.adres.mahalle);

    printf("Ilk Bakiye: ");
    scanf("%f", &yeni.bakiye);

    /* Dinamik diziyi 1 eleman büyüterek bu yeni kaydı ekliyoruz. */
    toplamHesap++;
    hesaplar = (Hesap*)realloc(hesaplar, toplamHesap * sizeof(Hesap));
    if(hesaplar == NULL) {
        printf("Bellek yetersizligi!\n");
        exit(1);
    }

    /* Dizi sonuna ekle */
    hesaplar[toplamHesap - 1] = yeni;

    printf("Hesap basariyla olusturuldu!\n");
}

/* ------------------ 2) HESAPLARI LİSTELE ------------------ */
void hesapListele() {
    printf("\n--- Tum Hesaplar ---\n");
    if(toplamHesap == 0) {
        printf("Kayit yok!\n");
        return;
    }

    for(int i = 0; i < toplamHesap; i++) {
        Hesap h = hesaplar[i];
        printf("\nHesap Numarasi : %d\n", h.hesapNo);
        printf("Musteri Adi    : %s\n", h.ad);
        printf("Musteri Soyadi : %s\n", h.soyad);
        printf("Adres [Il]     : %s\n", h.adres.il);
        printf("Adres [Ilce]   : %s\n", h.adres.ilce);
        printf("Adres [Mahalle]: %s\n", h.adres.mahalle);
        printf("Bakiye         : %.2f\n", h.bakiye);
    }
}

/* ------------------ 3) HESAP GÜNCELLE ------------------ */
void hesapGuncelle() {
    if(toplamHesap == 0) {
        printf("Kayit yok!\n");
        return;
    }

    int aranacakNo;
    printf("Guncellenecek hesap numarasini giriniz: ");
    scanf("%d", &aranacakNo);

    for(int i = 0; i < toplamHesap; i++) {
        if(hesaplar[i].hesapNo == aranacakNo) {
            printf("Yeni Musteri Adi: ");
            scanf("%s", hesaplar[i].ad);
            printf("Yeni Musteri Soyadi: ");
            scanf("%s", hesaplar[i].soyad);

            printf("Yeni Adres - Il: ");
            scanf("%s", hesaplar[i].adres.il);
            printf("Yeni Adres - Ilce: ");
            scanf("%s", hesaplar[i].adres.ilce);
            printf("Yeni Adres - Mahalle: ");
            scanf("%s", hesaplar[i].adres.mahalle);

            /* Bakiyeyi direkt değiştirmek yerine menüde Para Yatir / Cek fonksiyonları kullanılabilir.
               Ancak isterseniz burada da güncellenebilir.
            */
            printf("Guncelleme basarili!\n");
            return;
        }
    }

    printf("Hesap bulunamadi!\n");
}

/* ------------------ 4) HESAP SİL ------------------ */
void hesapSil() {
    if(toplamHesap == 0) {
        printf("Kayit yok!\n");
        return;
    }

    int silinecekNo;
    printf("Silinecek hesap numarasini giriniz: ");
    scanf("%d", &silinecekNo);

    int index = -1;
    for(int i = 0; i < toplamHesap; i++) {
        if(hesaplar[i].hesapNo == silinecekNo) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("Hesap bulunamadi!\n");
        return;
    }

    /* index'teki kaydı dizi sonuna kadar kaydırarak yok ediyoruz. */
    for(int i = index; i < toplamHesap - 1; i++) {
        hesaplar[i] = hesaplar[i + 1];
    }

    /* Dinamik diziyi 1 küçültüyoruz. */
    toplamHesap--;
    hesaplar = (Hesap*)realloc(hesaplar, toplamHesap * sizeof(Hesap));
    if(hesaplar == NULL && toplamHesap > 0) {
        printf("Bellek yetersizligi!\n");
        exit(1);
    }

    printf("Hesap silindi!\n");
}

/* ------------------ 5) PARA YATIR ------------------ */
void paraYatir() {
    if(toplamHesap == 0) {
        printf("Kayit yok!\n");
        return;
    }

    int no;
    float miktar;
    printf("Para yatirilacak hesap numarasini giriniz: ");
    scanf("%d", &no);
    printf("Yatirilacak miktari giriniz: ");
    scanf("%f", &miktar);

    for(int i = 0; i < toplamHesap; i++) {
        if(hesaplar[i].hesapNo == no) {
            hesaplar[i].bakiye += miktar;
            printf("Para yatirma basarili! Yeni bakiye: %.2f\n", hesaplar[i].bakiye);
            return;
        }
    }

    printf("Hesap bulunamadi!\n");
}

/* ------------------ 6) PARA CEK ------------------ */
void paraCek() {
    if(toplamHesap == 0) {
        printf("Kayit yok!\n");
        return;
    }

    int no;
    float miktar;
    printf("Para cekilecek hesap numarasini giriniz: ");
    scanf("%d", &no);
    printf("Cekilecek miktari giriniz: ");
    scanf("%f", &miktar);

    for(int i = 0; i < toplamHesap; i++) {
        if(hesaplar[i].hesapNo == no) {
            if(hesaplar[i].bakiye < miktar) {
                printf("Yetersiz bakiye!\n");
            } else {
                hesaplar[i].bakiye -= miktar;
                printf("Para cekme basarili! Yeni bakiye: %.2f\n", hesaplar[i].bakiye);
            }
            return;
        }
    }

    printf("Hesap bulunamadi!\n");
}
