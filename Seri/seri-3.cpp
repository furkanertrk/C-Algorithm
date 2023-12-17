#include <iostream>
#include <cmath>
using namespace std;
int main() {
int n,t;
double k,toplam=1;
cout<<"***k^2-1/k^2 serisi***\n\nn terim sayisini giriniz:";
cin>>t;
n=t+1;
for(k=2;k<=n;k++){
	toplam*=((pow(k,2)-1)/pow(k,2));
}
cout<<"Sonuc:"<<toplam;
	return 0;
}
