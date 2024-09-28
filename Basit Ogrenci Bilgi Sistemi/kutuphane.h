#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <clocale>
#include <algorithm>
using namespace std;
void ogrenci_bilgisi_al();
void ogrencileri_bastir();
void ogrenci_no_gore_bastir();
void ogrenci_sil(string soyad);
void yukle();
void kaydet();
void menu() {
    char x;
    while (true) {
        cout << endl << "1)-Öðrenci ekle" << endl
             << "2)-Öðrencileri Göster" << endl
             << "3)-Öðrenci sil(Soyada göre)" << endl
             << "4)-Öðrenci numarasýna göre göster" << endl
             << "5)-Öðrencileri veritabanýna kaydet"<< endl //sql kullanabilsek daha iyi olurdu.
             << "Çýkýþ için Q basýnýz" << endl;

        cout << "=>";
        cin >> x;

        // 'x' karakterini kontrol et
        if (x == 'q' || x == 'Q') {
            cout << "Çýkýþ yapýlýyor...";
            kaydet();
            exit(0);
        }

        // Menü seçenekleri için geçerli giriþ kontrolü
        if (x < '1' || x > '5') {
            cout << "Yanlýþ seçim yaptýnýz" << endl;
            continue; // Geçersizse döngü baþýna dön
        }

        switch (x) {
            case '1':
                ogrenci_bilgisi_al();
                break;
            case '2':
                ogrencileri_bastir();
                break;
            case '3': {
                cout << "Silinecek öðrenci soyadý: ";
                string silsoyad;
                cin.ignore();
                getline(cin, silsoyad); 
                ogrenci_sil(silsoyad); // Parametre eklendi
                break;
            }
            case '4':
                ogrenci_no_gore_bastir();
                break;
            case '5':
            	kaydet();
            default:
                cout << "Hata";
                break;
        }
    }
}


struct Ders {
    string dersAdi;
    int vizeNotu;
    int finalNotu;
};
struct Ogrenci {
    string adsoyad;
    int ogrenci_numarasi;
    vector<Ders>Dersler;
    Ogrenci *next; //linklist için sonraki elemaný gösterecek pointer
};

Ogrenci* root = NULL;

void __yeni_ogrenciyi_ekle(string ogrenci_adi,int ogrno,vector<Ders>& dersler){
	Ogrenci* yeniogrenci = new Ogrenci(); //yeni bir öðrenci için bellekte(RAM'de) Ogrenci structý kadar yer ayýrýyor.
	yeniogrenci->adsoyad = ogrenci_adi;
	yeniogrenci->Dersler= dersler;
	yeniogrenci->ogrenci_numarasi = ogrno;
	yeniogrenci->next = NULL; //yeniogrencinin pointerý NULL gösterir ki bu listenin sonu demek
	if(root == NULL){ //Eðer ki ilk pointer NULL gösteriyorsa bu liste boþ demektir. (Yani bu ekleyeceðimiz eleman, ilk elemandýr) 
		root = yeniogrenci; //Bu nedenle de bunu root yapýyoruz.
	}
	else{ //Eðer ki listede önceden eleman varsa yeni öðrenciyi listenin sonuna ekliyoruz
		Ogrenci* iter = root;
		while(iter->next !=NULL) //iteratör sona gelene kadar ilerler 
			iter = iter->next;
		iter->next = yeniogrenci; //sona gelince de yeni öðrenciyi ekler
	}
}

void ogrenci_bilgisi_al(){
	cout<<"Öðrenci Adý-Soyadý:";
	Ogrenci ogrenci;  //Yeni ogrenci eklemek için Ogrenci structýndan ogrenci nesnesi oluþturuyoruz.
	cin.ignore();
	getline(cin,ogrenci.adsoyad); 
	cout<<"Öðrenci numarasý: ";
	cin.ignore();
	cin>>ogrenci.ogrenci_numarasi;
	
	int dersSayisi;
    cout << "Kaç ders aldý";  
	while(true){
		cout<<"=>";
		cin >> dersSayisi;
		try{
			if(dersSayisi<3){ //Öðrenci minimum 3 ders alacak
				throw "Ders sayýsý az,ders sayýsýný artýrýn";
					}
			break;}
		catch(const char* hatamesaji){
			cout<<hatamesaji<<endl;
		}
			} 
        // Her ders için bilgileri al
    for (int j = 0; j < dersSayisi; ++j) {
            Ders ders;
            cin.ignore();
            cout << "Dersin adýný giriniz: ";
            getline(std::cin, ders.dersAdi);

            cout << "Vize notunu giriniz: ";
            cin >> ders.vizeNotu;

            cout << "Final notunu giriniz: ";
            cin >> ders.finalNotu;
            ogrenci.Dersler.push_back(ders);  // Öðrencinin derslerine ekle
    };
    __yeni_ogrenciyi_ekle(ogrenci.adsoyad,ogrenci.ogrenci_numarasi,ogrenci.Dersler);
    
}

void ogrencileri_bastir(){
	if (root == NULL) {
        cout << "Þuan öðrenci yok, önce öðrenci ekleyin" << endl;
        return;
    }
    Ogrenci* iter = root;
    while (iter != nullptr) {
        cout << "Öðrenci: " << iter->adsoyad << endl;
        cout<<"Numarasý: "<<iter->ogrenci_numarasi<<endl;
        for (const auto& ders : iter->Dersler) {
            cout << "  Ders: " << ders.dersAdi 
                 << " Vize: " << ders.vizeNotu 
                 << " Final: " << ders.finalNotu << endl;
        }
        iter = iter->next;  // Sýradaki öðrenciye geç
    }
}

void ogrenci_no_gore_bastir() {
    if (root == NULL) {
        cout << "Þu an öðrenci yok, önce öðrenci ekleyin." << endl;
        return;
    }
    vector<Ogrenci*> ogrenciListesi; // Öðrencileri geçici bir listeye al
    Ogrenci* iter = root;
    while (iter != nullptr) {
        ogrenciListesi.push_back(iter);
        iter = iter->next; // Sýradaki öðrenciye geç
    }
    // Öðrencileri numarasýna göre sýralama
    sort(ogrenciListesi.begin(), ogrenciListesi.end(), [](Ogrenci* a, Ogrenci* b) {
        return a->ogrenci_numarasi < b->ogrenci_numarasi; // Numara küçükten büyüðe sýralama
    });
    // Sýralý listeyi yazdýrma
    cout << "Öðrenciler (Numaraya Göre Sýralý):" << endl;
    for (const auto& ogr : ogrenciListesi) {
        cout << "Öðrenci: " << ogr->adsoyad << ", Numarasý: " << ogr->ogrenci_numarasi << endl;
        for (const auto& ders : ogr->Dersler) {
            cout << "  Ders: " << ders.dersAdi 
                 << " Vize: " << ders.vizeNotu 
                 << " Final: " << ders.finalNotu << endl;
        }
    }
}

void ogrenci_sil(string soyad) {
    if (root == NULL) {
        cout << "Öðrenci listesi boþ!" << endl;
        return;
    }

    Ogrenci* current = root;
    Ogrenci* previous = NULL;

    // Baðlantýlý listede gezerek silme iþlemini yapýyoruz
    while (current != NULL) {
        // Eðer soyadý adýn içinde bulunuyorsa
        if (current->adsoyad.find(soyad) != string::npos) {
            if (previous == NULL) { // Ýlk eleman siliniyorsa
                root = current->next; // root'u bir sonraki eleman yap
                delete current; // Bellekten sil
                current = root; // Sonraki elemana geç
            } else {
                previous->next = current->next; // Önceki elemaný güncelle
                delete current; // Bellekten sil
                current = previous->next; // Sonraki elemana geç
            }
            cout << soyad << " soyadýna sahip öðrenci silindi." << endl;
        } else {
            previous = current; // Mevcut elemaný bir önceki yap
            current = current->next; // Sonraki elemana geç
        }
    }
    kaydet();
}

void kaydet() {
    ofstream dosya("ogrenciler.txt");
    if (!dosya) {
        cerr << "Dosya açýlamadý!" << endl;
        return;
    }
    Ogrenci* iter = root;
    while (iter != nullptr) {
        dosya << iter->adsoyad << endl;
        dosya << iter->ogrenci_numarasi << endl;
        for (const auto& ders : iter->Dersler) {
            dosya << ders.dersAdi << "," << ders.vizeNotu << "," << ders.finalNotu << endl;
        }
        iter = iter->next; // Sýradaki öðrenciye geç
        dosya << "-----" << endl; // Her öðrenciden sonra bir ayraç
    }
    dosya.close();
    cout << "Tüm öðrenciler kaydedildi." << endl;
}

void yukle() {
    ifstream dosya("ogrenciler.txt");
    if (!dosya) {
        cerr << "Dosya açýlamadý!" << endl;
        return;
    }
    root = nullptr; // Öncelikle mevcut listeyi temizle
    string line;
    while (getline(dosya, line)) {
        Ogrenci ogrenci;
        ogrenci.adsoyad = line; // Ýlk satýr öðrenci adý
        dosya >> ogrenci.ogrenci_numarasi; // Ýkinci satýr öðrenci numarasý
        dosya.ignore(); // Boþ karakter atla
        while (getline(dosya, line) && line != "-----") {
            Ders ders;
            size_t pos = line.find(',');
            ders.dersAdi = line.substr(0, pos);
            size_t pos2 = line.find(',', pos + 1);
            ders.vizeNotu = stoi(line.substr(pos + 1, pos2 - pos - 1));
            ders.finalNotu = stoi(line.substr(pos2 + 1));
            ogrenci.Dersler.push_back(ders);
        }
        __yeni_ogrenciyi_ekle(ogrenci.adsoyad, ogrenci.ogrenci_numarasi, ogrenci.Dersler);
    }
    dosya.close();
    cout << "Öðrenciler yüklendi." << endl;
}



