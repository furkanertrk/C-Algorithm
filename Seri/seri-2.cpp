#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int k,i,n,fakt;
	double toplam=0;
	cout<<"***5^k/(2k!) serisi***\n\nn Sayi giriniz:";
	cin>>n;
	for(k=1;k<=n;k++){
		fakt=1;
		for(i=1;i<=2*k;i++){
			fakt*=i;
		}
		toplam+=pow(5,k)/(double)fakt;
	}
	cout<<toplam;
	return 0;
}
