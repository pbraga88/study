#include <stdio.h>

int main(){

	int matriz[2][3];
	int lin, col;
	int line_size = sizeof(matriz) / sizeof(*matriz);
	int column_size = sizeof(*matriz) / sizeof(*(*matriz));

	printf("First Round. Enter 6 numbers\n");
	for(lin=0; lin<line_size; lin++){
		for(col=0; col<column_size; col++)
			scanf("%i", &( (*(matriz+lin))[col]) );
	}
	for(lin=0; lin<line_size; lin++){
		for(col=0; col<column_size; col++)
			printf("%i ", matriz[lin][col] );
		printf("\n");
	}

	printf("Second Round. Enter 6 numbers\n");
	for(lin=0; lin<line_size; lin++){
		for(col=0; col<column_size; col++)
			scanf("%i", &( *(matriz[lin] + col)) );
	}

	for(lin=0; lin<line_size; lin++){
		for(col=0; col<column_size; col++)
			printf("%i ", *(*(matriz+lin)+col) );
		printf("\n");
	}

	return 0;
}