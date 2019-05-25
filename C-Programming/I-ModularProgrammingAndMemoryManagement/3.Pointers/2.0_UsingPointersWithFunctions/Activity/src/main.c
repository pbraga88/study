#include <stdio.h>

void newAge(int *);

int main(void){
	int age;
	int *ageAddr = &age;
	scanf("%d", ageAddr);
	printf("Your current age is %d.\n", age);

	/*Write your function call here*/
	newAge(&age);

	printf("Your new age will be %d!\n", age);
	return 0;
}


/*Write your function here*/
void newAge(int *a)
{
	if(*a<=21)
		*a *= 2;
	else
		*a -= 10;
}