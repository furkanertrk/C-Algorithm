#include <iostream>
#include <cstdlib>
using namespace std;
char game[3][3];
int goster();
void alici();
bool kontrol();
void bilgi();

int main() {
	cout<<"***** 3x3 Tic-Tac-Toe Oyunu *****"<<endl<<"Bilgilendirme icin 1'e basiniz:"<<endl<<"Oyuna baslamak icin 2'ye basiniz: ";
	int qq;
	cin>>qq;
	if(qq==1){
		bilgi();
	}
	
	else if(qq==2){
	
	for(int i=0;i<3;i++){
		for(int ii=0;ii<3;ii++){
			game[i][ii]=' ';
		}
	}
	goster();
for(int i=0;i<9;i++){
	alici();
	goster();
	if(kontrol()){
		cout<<endl<<"Kazandiniz";
		return 0;
	}
}

}
else cout<<"hata";
return 0;
}
void alici(){
	jump1:
	cout<<"1-9 arasi yer sec: "<<endl;
	int yer;
	cin>>yer;
	if(yer>9 || yer<1){
		cout<<"hatali oldu, tekrar dene"<<endl;
		goto jump1;
	}
	int sayac=-1;
	yer=yer-1;
	while(yer>=3){	
		yer=yer-3;
		sayac++;
	}
	jump:
	cout<<"x?-o?"<<endl;
	char alici;
	cin>>alici;
	if(alici!='x' && alici!='o'){
		cout<<"hatali oldu, tekrar dene"<<endl;
		goto jump;
	}
	game[sayac+1][yer]=alici;
}
int goster(){
		for(int i=0;i<3;i++){
		for(int ii=0;ii<3;ii++){
			cout<<"["<<game[i][ii]<<"]";
		}
		cout<<endl;
	}
}
bool kontrol(){
	if((game[0][0]=='x' && game[0][1]=='x' && game[0][2]=='x') || 
	(game[1][0]=='x' && game[1][1]=='x' && game[1][2]=='x') || 
	(game[2][0]=='x' && game[2][1]=='x' && game[2][2]=='x') ||
	(game[0][0]=='x' && game[1][1]=='x' && game[2][2]=='x') ||
	(game[2][0]=='x' && game[1][1]=='x' && game[2][0]=='x') ||
	(game[0][0]=='o' && game[1][1]=='o' && game[2][2]=='o') ||
	(game[2][0]=='o' && game[1][1]=='o' && game[2][0]=='o') ||
	(game[0][0]=='o' && game[0][1]=='o' && game[0][2]=='o') ||
	(game[1][0]=='o' && game[1][1]=='o' && game[1][2]=='o') ||
	(game[2][0]=='o' && game[2][1]=='o' && game[2][2]=='o')) {
	return true;
	}

	else {
		return false;
	}
}
void bilgi(){
	cout<<endl<<"-oyun iki kisiliktir"<<endl;
	int dizi[3][3];
	cout<<endl<<"-Yerler: "<<endl;
	int sayac=1;
	for(int i=0;i<3;i++){
		for(int ii=0;ii<3;ii++){
			dizi[i][ii]=sayac;
			cout<<"["<<dizi[i][ii]<<"]";
			sayac++;
		}
		cout<<endl;
	}
	
	cout<<endl<<"-x ve o yerlestirirken kucuk harfler kullaniniz"<<endl<<endl<<"**iyi eglenceler**";
}
