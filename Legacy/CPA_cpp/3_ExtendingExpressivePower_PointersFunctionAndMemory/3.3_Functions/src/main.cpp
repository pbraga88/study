#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// // int main_v;
// int main_v(void);

// int main() {

// 	int main = 10;
// 	cout << main << endl;
// 	cout << main_v() << endl;
// 	return 0;
// }

// int main_v(void) {
// 	float main_v = 10.00000;
// 	printf("Some line %.2f\n", main_v);
// 	return 0;
// }

void print_buffer(char* buf);
void print_int(int *nb);

int main() {
	int nb_buffer[10], var = 10, i;
	int *ptr = nb_buffer;
	char *buffer = (char*)malloc(128);
	int result = snprintf(buffer, 128, "How many letters %d", var);
	// puts(buffer);
	// printf("%d\n",result );
	if(result > 0 && result < 128) {
		print_buffer(buffer);
	}
	printf("\n");
	free(buffer);

	for (i = 0; i < 10; i++)
		 *(ptr+i) = i;
	print_int(ptr);
	printf("\n");

	return 0;
}

void print_buffer(char buf[]) {
	int i;
	for(i = 0; buf[i]; i++)
		printf("%c",buf[i]);
}

void print_int(int *nb) {
	int i;
	for(i = 0; i < 10; i++)
		printf("%d ", *(nb+i));
}