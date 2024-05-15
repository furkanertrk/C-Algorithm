#include <iostream>
#include <string>
using namespace std;
class Calisan {
protected:
	string AD;
	string SoyAD;
	double Maas=0;
public:
	Calisan(string ad,string syad, double maas){
		AD = ad;
		SoyAD = syad;
		Maas = maas;
	}
	Calisan(){}
	virtual	void zamYap() {
		Maas = Maas * 1.3;
		cout << AD << " " << SoyAD << " " << Maas << endl;
	}
};

class Muhendis:public Calisan{
public:
	Muhendis(string ad,string syad,double maas):Calisan(ad,syad,maas) {}
	Muhendis(string ad, double maas){
		AD = ad;
		Maas = maas;
	}
	void zamYap() {
		Maas = Maas * 1.4+3000;
		cout << AD << " " << SoyAD<< " " << Maas<<endl;
	}
};
class Hizmetli :public Calisan {
public:
	Hizmetli(string ad, string syad, double maas) :Calisan(ad, syad, maas) {}
	void zamYap() {
		Maas = Maas * 1.1+1500;
		cout << AD << " " << SoyAD << " " << Maas<<endl;
	}
};
class Muhasebe :public Calisan {
public:
	Muhasebe(string ad, string syad, double maas) :Calisan(ad, syad, maas) {}
	void zamYap() {
		Maas = Maas * 1.2+2000;
		cout << AD <<" "<<SoyAD << " " << Maas << endl;
	}
};
class Cayci:public Calisan
{
public:
	Cayci(string ad, double maas) {
		AD = ad;
		Maas = maas;
	}
};


int main()
{
	setlocale(LC_ALL, "Turkish");
	Calisan* ptr[4];
	ptr[0] = new Muhendis("Berat", 25000);
	ptr[1] = new Hizmetli("Göktuğ","Uylaş", 17000);
	ptr[2] = new Muhasebe("Yiğit", "Aypak", 21000);
	ptr[3] = new Cayci("YBB", 15000);
	for (int i = 0; i <= 3; i++) {
		ptr[i]->zamYap();
	}


	return 0;
}