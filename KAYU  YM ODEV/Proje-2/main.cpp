#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <cstdarg>
using namespace std;
char hesaplamasecimmesaj(){
	cout<<endl<<"iþlem seçiniz: "<<endl<<"1-Toplama  2-çýkarma  3-çarpma  4-Bölme  5-Mod Alma(Kalan bulma)"<<endl;
}
char mesaj(){
	cout<<"Sayi girin:"<<endl;
}

float sayial(){
	float x;
	cout<<"=>";
	cin>>x;
	return x;
}
int intsayial(){
	int x;
	cout<<"=>";
	cin>>x;
	return x;
}
void toplayazdir(float *p1,float *p2){
	cout<< *p1+*p2<<endl;
}
void cikaryazdir(float *p1,float *p2){
	cout<< *p1-*p2<<endl;
}
void carpyazdir(float *p1,float *p2){
	cout<< (*p1)*(*p2)<<endl;
}
void bolyazdir(float *p1,float *p2){
	cout<< (*p1)/(*p2)<<endl;
}
void modal(int *p1,int *p2){
	if(*p1<=*p2) cout<<*p1;
	else{
	cout<<(*p1)%(*p2);	
	}
}
void secimvehesaplama(){
	hesaplamasecimmesaj() ;		
	int a;
	cin>>a;
	mesaj();
	float sayi1=sayial();
	float sayi2=sayial();
	switch(a){
		case 1:
			cout<<"Sonuc:";
			toplayazdir(&sayi1,&sayi2); 
			break;
		case 2:
			cout<<"Sonuc:";
			cikaryazdir(&sayi1,&sayi2);
			break; 
		case 3:
			cout<<"Sonuc:";
			carpyazdir(&sayi1,&sayi2); 
			break;
		case 4:
			cout<<"Sonuc:";
			bolyazdir(&sayi1,&sayi2);
			 break;
			 /*
		case 5:
			cout<<"Sonuc:";
		   	int intSayi1 = static_cast<int>(sayial());
            int intSayi2 = static_cast<int>(sayial());
			modal(&intSayi1,&intSayi2); 
			  break; */
		default:
			cout<<"Hatalý seçim,tekrar deneyiniz:"<<endl;
			break;
	}
}

int main() {
	setlocale(LC_ALL,"Turkish");
	secimvehesaplama();
	return 0;
}

