#include <iostream>
using namespace std;
//girilen sayiya kadarki asal sayilari bulan kod 
int main() {

    int sayi, sayi2, artis, sayac, k;
    
    cout << "Sayi giriniz: ";
    cin >> sayi;
    
    if (sayi < 2) {
        cout << "Asal sayi: 0 \nAdet: 0";
    } else {
        cout << "Asal sayilar: ";
        for (sayi2 = 2; sayi2 <= sayi; sayi2++) {
            k = 0;
            for (artis = 2; artis < sayi2; artis++) {
                if (sayi2 % artis == 0) {
                    k = 1;
                    break;
                }
            }
            if (k == 0) {
                cout << sayi2 << " ";
                sayac++;
            }
        }
        cout << "\nAdet: " << sayac;
    }

    return 0;
}
