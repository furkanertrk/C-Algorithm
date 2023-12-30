#include <stdio.h>
#include <stdlib.h>

void mbps(){
	double i,ii;
	printf("Mbps?\n==>");
	scanf("%lf",&i);
	ii=i/8;
	printf("%.3lf mb/s",ii); 
}
int main() {
	mbps();
	return 0;
}
