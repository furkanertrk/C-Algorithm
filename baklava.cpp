#include <iostream>
using namespace std;

int main() {
    int a;
    jump:
    while(true){
    cout << "Sayi giriniz (tek sayi olmalidir): ";
    cin >> a;

    if (a % 2 == 0) {
        cout << "Lutfen tek sayi giriniz." << endl;
    	goto jump;
    }

    int bosluk = a / 2;

    for (int b = 1; b <= a; b += 2) {
        for (int c = 0; c < bosluk; ++c) {
            cout << " ";
        }
        for (int d = 0; d < b; ++d) {
            cout << "*";
        }

        cout << endl;
        bosluk--;
    }

    bosluk = 1;

    for (int b = a - 2; b >= 1; b -= 2) {
        for (int c = 0; c < bosluk; ++c) {
            cout << " ";
        }
        for (int d = 0; d < b; ++d) {
            cout << "*";
        }

        cout << endl;
        bosluk++;
    }
}
    return 0;
}

