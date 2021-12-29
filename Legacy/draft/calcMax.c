#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);



/*
 * Complete the 'maxDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY px as parameter.
 */

// int maxDifference(int px_count, int* px) {
// 	int maxnb = 0;
// 	int maxdif = 0;
// 	for (int i = 0; i< px_count-1; i++) {
// 		// printf("maxnb %d\n", maxnb);
// 		if ((maxnb) && (maxnb - px[px_count-i-1]) > maxdif) {
// 			// printf("maxnb %d\n", maxnb);
// 			// printf("maxdif %d\n", maxdif);
// 			// if((maxnb - px[px_count-i-1]) > maxdif) {
// 			maxdif = maxnb - px[px_count-i-1];
// 			// }
// 		}
// 		if (px[px_count-i-1] > maxnb) {
// 			maxnb = px[px_count-i-1];
// 		}

// 	}
// 	// printf("%d\n", maxnb);
// 	// printf("maxnb %d\n", maxnb);
// 	// printf("maxdif %d\n", maxdif);

// 	return maxdif ? maxdif : -1;

// }
// int maxDifference(int px_count, int* px) {
//     int maxnb = 0;
//     int maxdif = 0;
//     for(int i = 0; i < px_count-1; i++) {
        
//         if((maxnb) && (maxnb - px[px_count-i-1]) > maxdif) {
//             maxdif = maxnb - px[px_count-i-1];
//         }
//         if(px[px_count-i-1] > maxnb) {
//             maxnb = px[px_count-i-1];
//         }
//     }
//     return maxdif ? maxdif : -1;
// }

// int main(int argc, char *argv) {
// 	// int values[8] = {7, 2, 3, 10, 2, 4, 8, 1};
// 	// int values[4] = {7,5,3,1};
// 	// int values[4] = {7,1,2,5};
// 	// int values[7] = {6,7,9,5,6,3,2};
// 	// int size_value = 0;

// 	// size_value = sizeof(values)/sizeof(values[0]);

// 	// // printf("%d\n", size_value);

// 	// printf("%d\n", maxDifference(size_value, values));
// 	// char* entrynb;
// 	// scanf("%s", entrynb);

// 	// printf("%c\n", entrynb[2]);
// 	// values = (int*)malloc(sizeof(entrynb));
	
// 	if(argc>1){
// 		printf("Capitalized: \n");
// 		printf("%d\n", argc);
// 	}
// 	else {
// 		printf("Error!\nUsage: capitalize \"String\"");
// 	}



// 	return 0;
// }










// char *capitalize(char* tocapitalize) {
// 	printf("%s\n", tocapitalize);
// 	int stringsize = sizeof(tocapitalize+1);
// 	char *temp = malloc(stringsize);
// 	int loop = 0;

// 	for (loop = 0; loop <= stringsize; loop++) {
// 		if( (tocapitalize[loop] <= 'z') && (tocapitalize[loop] >='a') ) {
// 			temp[loop] = tocapitalize[loop] + 'A' - 'a';
// 		}
// 		else {
// 			temp[loop] = tocapitalize[loop];
// 		}
// 	}

// 	printf("temp = %s\n", temp);
// 	temp[loop] = '\0';

// 	return temp;
// }


// int main(int argc, char **argv) {
// 	printf("%s\n", argv[1]);

// 	if(argc>1){
// 		printf("Capitalized: %s\n\n", capitalize(argv[1]));
// 		printf("%d\n", argc);
// 	}
// 	else {
// 		printf("Error!\nUsage: capitalize \"String\"");
// 	}

// 	return 0;
// }

int main(){
	char *p = "abcde";
	printf("%lu %lu %lu\n", sizeof(p), strlen(p), sizeof("abcdef"));
	return 0;
}