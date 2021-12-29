#include <stdio.h>

int main(){
	int anos = 6;
	float juros = 7.90;
	float dep = 55000;
	int i;

	for(i = 0; i<anos; i++){
		printf("x%i: %.2f\n",i+1 ,dep);
		dep *= (1+(juros/100));
	}
	printf("%.2f\n", dep);
	
	return 0;
}
