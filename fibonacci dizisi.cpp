#include <iostream>
#include <time.h>
using namespace std;
int main() {
	int t;
	jump:
	cout<<"Terim sayisini giriniz: ";
	cin>>t;
	t+=1;
	if(t<48 && t>1){
			int p,a,b,F[t];
	F[0]=0;
	F[1]=1;
	printf("1");
	for(int i=2;i<t;i++){
		F[i]=F[i-1]+F[i-2];
		cout<<" "<<F[i];
	}
	}
	else{
		cout<<"kod hata veriyo baska sayi girer misin\n\n";
		goto jump;
	}
	return 0;
}
