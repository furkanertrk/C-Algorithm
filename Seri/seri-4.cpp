#include <iostream>
#include <cmath>
using namespace std;
int main() {
int i,n;
double sonuc;
cout<<"***1 + 1/2 - 1/3 + 1/4 + 1/5 -1/6 + 1/7 .......n serisi***\n\nn terim sayisi:";
cin>>n;
for(i=1;i<=n;i++){
	if(i%3==0){
		sonuc-=1.0/i;
	}
	else{
		sonuc+=1.0/i;
	}
}
cout<<"Sonuc:"<<sonuc;
	return 0;
}
