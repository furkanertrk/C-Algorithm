#include <iostream>
#include <clocale>
#include <cstring>
using namespace std;
class Package {
protected:
	string m_isim;
	string m_adres;
	string m_sehir;
	string m_ulke;
	double paket_kutle=0;
	int twodaypackagecost = 5;
	int overnightpackagecost = 15;
	double totalmoney = 0;
public:
	Package() = default;
	Package(string isim, string adres, double kutle) {
		m_isim = isim;
		m_adres = adres;
		paket_kutle = kutle;
	}
	virtual double calculateCost() = 0;
	void printmusteri() {
		cout << "Musteri Adı:" << m_isim << "\t" << "Adres:" << m_adres << "\t" << "Ücret:" << calculateCost() << "TL" << endl;
	}

};
 class TwoDayPackage :public Package {
private:
	int sabit_ucret = 25;
public:
	TwoDayPackage(string isim, string adres, double kutle) :Package(isim, adres, kutle) {
		m_isim = isim;
		m_adres = adres;
		paket_kutle = kutle;
	}
	double calculateCost() override {
		totalmoney = paket_kutle * twodaypackagecost;
		totalmoney += sabit_ucret;
		return totalmoney;
	}
};
class OverNightPackage : public Package {
private:
	int sabit_ucret = 35;
public:
	OverNightPackage(string isim, string adres, double kutle) : Package(isim, adres, kutle) {
		m_isim = isim;
		m_adres = adres;
		paket_kutle = kutle;
	}
	double calculateCost() override {
		totalmoney = paket_kutle * overnightpackagecost;
		totalmoney += sabit_ucret;
		return totalmoney;
	}

};

int main()
{
	setlocale(LC_ALL, "Turkish");
	Package* ptr[2];
	ptr[0] = new TwoDayPackage("Ahmet", "Talas/Kayseri", 12);
	ptr[1] = new OverNightPackage("Mehmet", "Kocasinan/Kayseri",5);

	for (int i = 0; i < 2; i++) {
		ptr[i]->printmusteri();
	}
	return 0;
}
