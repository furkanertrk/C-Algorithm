#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
int main() {
    int i, ii, tkm;
    srand(time(NULL));
    i = rand() % 3 + 1;
    cout << "\n***Tas-Kagit-Makas***\n";
    cout<<"\nTas mi Kagit mi Makas mi\n TAS=1\n KAGIT=2\n MAKAS=3\nhadi\n";
    Sleep(1000);
    for (ii = 3; ii >= 1; ii--) {
        cout << "  " << ii << "\n";
        Sleep(1000);
    }
    cout << "SECIM YAP:\n ";
    cin >> tkm;

    switch (tkm) {
    case 1:
        if (i == 2) cout << "Ben kagit yaptim. KAYBETTIN :D";
        else if (i == 1) {
            cout << "TAS yaptik\tTEKRAR";
        }
        else if (i == 3) cout << "Ben makas yaptim. KAZANDIN";
        break;

    case 2:
        if (i == 1) cout << "Ben Tas yapmistim. KAZANDIN";
        else if (i == 2) { cout << "Ben de kagit yaptim. TEKRAR"; }
        else if (i == 3) cout << "Ben makas yaptim. KAYBETTIN :D";
        break;

    case 3:
        if (i == 1) cout << "Tas yaptim. KAYBETTIN:D";
        else if (i == 2) cout << "Kagit yaptim. KAZANDIN.";
        else if (i == 3) {
            cout << "Ben de makas yapmistim\n fnsjkfþndjfpsnpfs\tTekrar yapalim.";
        }
        break;
        
     default:
    	cout<<"HATALI ISLEM :|";
    	break;
}
    return 0;
}
