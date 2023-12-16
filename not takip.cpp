#include <iostream>
using namespace std;
int MAX_OGRENCI_SAYISI= 100;
int NOT_SAYISI;

int main() {
	int ogrenci,NOTLAR[NOT_SAYISI][MAX_OGRENCI_SAYISI],genelort;
	cout<<"Ogrenci sayisi: ";
	cin>>ogrenci;
	cout<<"Sinav sayisi:";
	cin>>NOT_SAYISI;
	for(int j=0;j<ogrenci;++j){
		for(int i=0;i<NOT_SAYISI;++i){
			cout<<j+1<<". ogrencinin "<<i+1<<".notu: ";
			cin>>NOTLAR[i][j];
		}
	}
    for (int j = 0; j < ogrenci; ++j) {
        int toplam = 0;
        for (int i = 0; i < NOT_SAYISI; ++i) {
            toplam += NOTLAR[i][j];
        }
        int ortalama = toplam / NOT_SAYISI;
        cout << "Ogrenci " << j + 1 << " not ortalamasi: " << ortalama << endl;  
    }
    return 0;
}
