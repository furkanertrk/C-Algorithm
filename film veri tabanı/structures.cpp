#include "filmislemleri.h"
struct filmsablonu {
    string film;
    string yil;
    string yonetmen;
    string tur;
};

int main() {
    setlocale(LC_ALL, "Turkish");
    struct filmsablonu yenifilmler[100];
    int a = 10, i = 0, sil;
    cout << "*********FİLM VERİ TABANI*********" << endl;
    
    anamenu();
    
    while (a != 5) {
        cout << "==>";
        cin >> a;
        switch (a) {
        case 1:
            mevcutfilmyazdir();
            break;
        case 2:
            for (; i < 100; i++) {
                cout << "Film adını giriniz:";
                cin >> yenifilmler[i].film;
                cout << "Vizyona çıkış tarihi:";
                cin >> yenifilmler[i].yil;
                cout << "Tür:";
                cin >> yenifilmler[i].tur;
                cout << "Yönetmen:";
                cin >> yenifilmler[i].yonetmen;
                cout << "Film eklendi" << endl;

                cout << "Yeni film eklensin mi: (e/h) ";
                char soru;
                cin >> soru;
                if (soru == 'e') continue;
                else break;
            }
            break;

        case 3:
            cout << "Hangi film silinsin:";
            cin >> sil;
            sil -= 2;
            if (sil >= 0 && sil < i) {
                for (int h = sil; h < i-1 ; ++h) {
                    yenifilmler[h] = yenifilmler[h + 1];
                }
                i--;
                cout << "Film silindi" << endl;
            }
            else {
                cout << "Gecersiz indeks!" << endl;
            }
        case 4:
            cout << "Veri tabanındaki mevcut filmler:" << endl;
            mevcutfilmyazdir();
            cout << endl;
            cout << "Eklenen filmler:" << endl;
            cout << "Ad: " << '\t' << "Vizyon yılı: " << '\t' << "Tür:" << '\t' << "Yönetmen:" << endl;
            for (int p=0; p <= i; p++) {
                cout<< yenifilmler[p].film << '\t' << yenifilmler[p].yil <<'\t'<<  yenifilmler[p].tur <<'\t' << yenifilmler[p].yonetmen << endl;
            }
            break;
        case 5:
            break;
        }
     }
    return 0;
}