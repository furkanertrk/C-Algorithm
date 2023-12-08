#include <iostream>
using namespace std;
int main() {
	int a,b,c;
	cout<<"*****ORTALAMAYA GORE NOT*****"<<endl;
	
	while(1){
	cout <<"Ilk sinavin sonucu: ";
	cin>>a;
	cout <<"Ikinci sinavin sonucu: ";
	cin>>b;
	c=(a+b)/2;
	
    if (c >= 90 && c <= 100) {
        cout << "NOT: A\n";
    } else if (c>= 80 && c<= 89) {
        cout << "NOT: B\n";
    } else if (c>= 70 && c<= 79) {
        cout << "NOT: C\n";
    } else if (c>= 60 && c<= 69) {
        cout << "NOT: D\n";
    } else if (c>= 0 && c<= 60) {
        cout << "NOT: F\n";
    }

}
	return 0;
}
