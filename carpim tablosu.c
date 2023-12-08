#include <stdio.h>
#include <stdlib.h>

int main() {
	   printf("************Carpim Tablosu*********\n");
int a,b,c;
for(a=1;a<=10;a++){
	for(b=1;b<=10;b++){
		c=a*b;
		printf("%d x %d = %d  ",a,b,c); 
		printf("\n");
	}
	printf("\n"); 
}
	return 0;
}
