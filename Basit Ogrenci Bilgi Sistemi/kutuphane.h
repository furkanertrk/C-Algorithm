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
        cout << endl << "1)-��renci ekle" << endl
             << "2)-��rencileri G�ster" << endl
             << "3)-��renci sil(Soyada g�re)" << endl
             << "4)-��renci numaras�na g�re g�ster" << endl
             << "5)-��rencileri veritaban�na kaydet"<< endl //sql kullanabilsek daha iyi olurdu.
             << "��k�� i�in Q bas�n�z" << endl;

        cout << "=>";
        cin >> x;

        // 'x' karakterini kontrol et
        if (x == 'q' || x == 'Q') {
            cout << "��k�� yap�l�yor...";
            kaydet();
            exit(0);
        }

        // Men� se�enekleri i�in ge�erli giri� kontrol�
        if (x < '1' || x > '5') {
            cout << "Yanl�� se�im yapt�n�z" << endl;
            continue; // Ge�ersizse d�ng� ba��na d�n
        }

        switch (x) {
            case '1':
                ogrenci_bilgisi_al();
                break;
            case '2':
                ogrencileri_bastir();
                break;
            case '3': {
                cout << "Silinecek ��renci soyad�: ";
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
    Ogrenci *next; //linklist i�in sonraki eleman� g�sterecek pointer
};

Ogrenci* root = NULL;

void __yeni_ogrenciyi_ekle(string ogrenci_adi,int ogrno,vector<Ders>& dersler){
	Ogrenci* yeniogrenci = new Ogrenci(); //yeni bir ��renci i�in bellekte(RAM'de) Ogrenci struct� kadar yer ay�r�yor.
	yeniogrenci->adsoyad = ogrenci_adi;
	yeniogrenci->Dersler= dersler;
	yeniogrenci->ogrenci_numarasi = ogrno;
	yeniogrenci->next = NULL; //yeniogrencinin pointer� NULL g�sterir ki bu listenin sonu demek
	if(root == NULL){ //E�er ki ilk pointer NULL g�steriyorsa bu liste bo� demektir. (Yani bu ekleyece�imiz eleman, ilk elemand�r) 
		root = yeniogrenci; //Bu nedenle de bunu root yap�yoruz.
	}
	else{ //E�er ki listede �nceden eleman varsa yeni ��renciyi listenin sonuna ekliyoruz
		Ogrenci* iter = root;
		while(iter->next !=NULL) //iterat�r sona gelene kadar ilerler 
			iter = iter->next;
		iter->next = yeniogrenci; //sona gelince de yeni ��renciyi ekler
	}
}

void ogrenci_bilgisi_al(){
	cout<<"��renci Ad�-Soyad�:";
	Ogrenci ogrenci;  //Yeni ogrenci eklemek i�in Ogrenci struct�ndan ogrenci nesnesi olu�turuyoruz.
	cin.ignore();
	getline(cin,ogrenci.adsoyad); 
	cout<<"��renci numaras�: ";
	cin.ignore();
	cin>>ogrenci.ogrenci_numarasi;
	
	int dersSayisi;
    cout << "Ka� ders ald�";  
	while(true){
		cout<<"=>";
		cin >> dersSayisi;
		try{
			if(dersSayisi<3){ //��renci minimum 3 ders alacak
				throw "Ders say�s� az,ders say�s�n� art�r�n";
					}
			break;}
		catch(const char* hatamesaji){
			cout<<hatamesaji<<endl;
		}
			} 
        // Her ders i�in bilgileri al
    for (int j = 0; j < dersSayisi; ++j) {
            Ders ders;
            cin.ignore();
            cout << "Dersin ad�n� giriniz: ";
            getline(std::cin, ders.dersAdi);

            cout << "Vize notunu giriniz: ";
            cin >> ders.vizeNotu;

            cout << "Final notunu giriniz: ";
            cin >> ders.finalNotu;
            ogrenci.Dersler.push_back(ders);  // ��rencinin derslerine ekle
    };
    __yeni_ogrenciyi_ekle(ogrenci.adsoyad,ogrenci.ogrenci_numarasi,ogrenci.Dersler);
    
}

void ogrencileri_bastir(){
	if (root == NULL) {
        cout << "�uan ��renci yok, �nce ��renci ekleyin" << endl;
        return;
    }
    Ogrenci* iter = root;
    while (iter != nullptr) {
        cout << "��renci: " << iter->adsoyad << endl;
        cout<<"Numaras�: "<<iter->ogrenci_numarasi<<endl;
        for (const auto& ders : iter->Dersler) {
            cout << "  Ders: " << ders.dersAdi 
                 << " Vize: " << ders.vizeNotu 
                 << " Final: " << ders.finalNotu << endl;
        }
        iter = iter->next;  // S�radaki ��renciye ge�
    }
}

void ogrenci_no_gore_bastir() {
    if (root == NULL) {
        cout << "�u an ��renci yok, �nce ��renci ekleyin." << endl;
        return;
    }
    vector<Ogrenci*> ogrenciListesi; // ��rencileri ge�ici bir listeye al
    Ogrenci* iter = root;
    while (iter != nullptr) {
        ogrenciListesi.push_back(iter);
        iter = iter->next; // S�radaki ��renciye ge�
    }
    // ��rencileri numaras�na g�re s�ralama
    sort(ogrenciListesi.begin(), ogrenciListesi.end(), [](Ogrenci* a, Ogrenci* b) {
        return a->ogrenci_numarasi < b->ogrenci_numarasi; // Numara k���kten b�y��e s�ralama
    });
    // S�ral� listeyi yazd�rma
    cout << "��renciler (Numaraya G�re S�ral�):" << endl;
    for (const auto& ogr : ogrenciListesi) {
        cout << "��renci: " << ogr->adsoyad << ", Numaras�: " << ogr->ogrenci_numarasi << endl;
        for (const auto& ders : ogr->Dersler) {
            cout << "  Ders: " << ders.dersAdi 
                 << " Vize: " << ders.vizeNotu 
                 << " Final: " << ders.finalNotu << endl;
        }
    }
}

void ogrenci_sil(string soyad) {
    if (root == NULL) {
        cout << "��renci listesi bo�!" << endl;
        return;
    }

    Ogrenci* current = root;
    Ogrenci* previous = NULL;

    // Ba�lant�l� listede gezerek silme i�lemini yap�yoruz
    while (current != NULL) {
        // E�er soyad� ad�n i�inde bulunuyorsa
        if (current->adsoyad.find(soyad) != string::npos) {
            if (previous == NULL) { // �lk eleman siliniyorsa
                root = current->next; // root'u bir sonraki eleman yap
                delete current; // Bellekten sil
                current = root; // Sonraki elemana ge�
            } else {
                previous->next = current->next; // �nceki eleman� g�ncelle
                delete current; // Bellekten sil
                current = previous->next; // Sonraki elemana ge�
            }
            cout << soyad << " soyad�na sahip ��renci silindi." << endl;
        } else {
            previous = current; // Mevcut eleman� bir �nceki yap
            current = current->next; // Sonraki elemana ge�
        }
    }
    kaydet();
}

void kaydet() {
    ofstream dosya("ogrenciler.txt");
    if (!dosya) {
        cerr << "Dosya a��lamad�!" << endl;
        return;
    }
    Ogrenci* iter = root;
    while (iter != nullptr) {
        dosya << iter->adsoyad << endl;
        dosya << iter->ogrenci_numarasi << endl;
        for (const auto& ders : iter->Dersler) {
            dosya << ders.dersAdi << "," << ders.vizeNotu << "," << ders.finalNotu << endl;
        }
        iter = iter->next; // S�radaki ��renciye ge�
        dosya << "-----" << endl; // Her ��renciden sonra bir ayra�
    }
    dosya.close();
    cout << "T�m ��renciler kaydedildi." << endl;
}

void yukle() {
    ifstream dosya("ogrenciler.txt");
    if (!dosya) {
        cerr << "Dosya a��lamad�!" << endl;
        return;
    }
    root = nullptr; // �ncelikle mevcut listeyi temizle
    string line;
    while (getline(dosya, line)) {
        Ogrenci ogrenci;
        ogrenci.adsoyad = line; // �lk sat�r ��renci ad�
        dosya >> ogrenci.ogrenci_numarasi; // �kinci sat�r ��renci numaras�
        dosya.ignore(); // Bo� karakter atla
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
    cout << "��renciler y�klendi." << endl;
}



