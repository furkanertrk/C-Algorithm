#include <iostream>
#include <locale.h>
using namespace std;
template <typename T>
T topla(T x ,T y){
	return x+y;
}
template <typename U>
U carp(U x ,U y){
	return x*y;
}

template <typename K>
K cikar(K x,K y) {
    return x-y;
}
int main(){
	setlocale(LC_ALL,"Turkish");
	while(1){
	cout<<endl<<"Hangi i�lem olsun?"<<endl<<"1-topla 2-��kar 3-carp"<<endl;
	int a;
	double k,b;
	cin>>a;
	switch(a){
		case 1:
			cout<<"Sayilari girin:";
	 		cin>>k>>b;
			cout<<"Sonuc:"<<topla(k,b);
			break; 
		case 2:
			cout<<"Sayilari girin:";
			cin>>k>>b;
			cout<<"Sonuc:"<<cikar(k,b);
			break; 
		case 3:
			cout<<"Sayilari girin:";
			cin>>k>>b; 
			cout<<"Sonuc:"<<carp(k,b);
			break; 
		default:
			cout<<"hatali islem yapt�n�z.";
			break;
	}
	}
	return 0;
}
