#include <iostream>
#include <conio.h>
#include<windows.h>
using namespace std;
int main() {
	int saat,dk,sn;
	for(saat=0;saat<24;saat++){
		for(dk=0;dk<60;dk++){
			for(sn=0;sn<60;sn++){
				printf("Kronometre: %d:%d:%d",saat,dk,sn);
				Sleep(1000);
				system("cls");
				}
			}
		}
	return 0;
}

