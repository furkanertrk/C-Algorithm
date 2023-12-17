#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int i,j;
	double toplam=0;
	cout<<"***(k+1)/3^k serisi***\n\nSayi giriniz:";
	cin>>j;
	for(i=1;i<=j;i++){
		toplam += (i+1)/pow(3,i);
	}
	cout<<toplam;
	return 0;
}
