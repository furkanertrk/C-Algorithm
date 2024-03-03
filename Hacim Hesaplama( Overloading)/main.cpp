#include <iostream>
#include <locale.h>
using namespace std;

#include <cmath>
#define pi 3.1416
int dikdhacimhesaplama(int x,int y,int z){
	int sonuc;
	sonuc=x*y*z;
	return sonuc;
}
double dikdhacimhesaplama(double x,double y,double z){
	double sonuc;
	sonuc=x*y*z;
	return sonuc;
}
int kurehacimhesaplama(int r){
	int sonuc;
	sonuc=4/3*pi*pow(r,3);
	return sonuc;
}
double kurehacimhesaplama(double r){
	double sonuc;
	sonuc=4/3*pi*pow(r,3);
	return sonuc;
}
int silindirhacimhesap(int h,int r){
	int sonuc;
	sonuc=pi*pow(r,2)*h;
	return sonuc;
	
}
double silindirhacimhesap(double h,double r){
	double sonuc;
	sonuc=pi*pow(r,2)*h;
	return sonuc;
	
}
int main() {
	setlocale(LC_ALL,"Turkish");
	while(1){
	
	cout<<endl<<"Hacim hesaplama secin: "<<"1-dikdörtgen prizma 2-küre 3-silindir"<<endl;
	int a;
	double i,ii,iii;
	cin>>a;
	switch(a){
		case 1:
			cout<<"Kenar uzunluklarýný girin:"<<endl;
			cin>>i>>ii>>iii;
			cout<<"Sonuc:"<<dikdhacimhesaplama(i,ii,iii); 
			break;
		case 2:
			cout<<"Yarýçapý girin:"<<endl;
			cin>>i;
			cout<<"Sonuc:"<<kurehacimhesaplama(i); 
			break;
		case 3:
			cout<<"Yarýçapý girin:"<<endl;
			cin>>i;
			cout<<"Yüksekliði girin:"<<endl;
			cin>>ii;
			cout<<"Sonuc:"<<silindirhacimhesap(ii,i); 
			break;
		default:
			cout<<"Hatalý seçim yaptýnýz, tekrar deneyin."<<endl;
			break;
	}
}
	return 0;
}
