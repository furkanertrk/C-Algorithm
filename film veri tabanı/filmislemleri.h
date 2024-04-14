#pragma once
#include <iostream>
#include <string>
using namespace std;
enum tur{dram,komedi,aksiyon,gerilim};

string mevcutdizi[4][4][4] = {
        {"Godfather", "1972", "Dram","Francis Ford Coppola"},
        {"Taxi Driver","1976", "Suç","Martin Scorsese"},
        {"Fight Club","1999","Drama","David Fincher"},
        {"Matrix  ", "1999", "Kurgu","Lana/Lilly Wachowski"}
}


; void mevcutfilmyazdir() {
    cout << "Ad: " << '\t' << "Vizyon yılı: " << '\t' << "Tür:" << '\t' << "Yönetmen:" << endl;
    int i, j, p;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (p = 0; p < 4; p++)
            {
                cout << mevcutdizi[i][j][p]<<'\t';
            }
        }
        cout << endl;
    }

}


void anamenu() {
    cout << "(1) Mevcut filmleri göster" << endl;
    cout << "(2) Yeni film ekle" << endl;
    cout << "(3) Film çýkar" << endl;
    cout << "(4) Tüm filmleri göster" << endl;
    cout << "(5) Çıkış" << endl;
}
