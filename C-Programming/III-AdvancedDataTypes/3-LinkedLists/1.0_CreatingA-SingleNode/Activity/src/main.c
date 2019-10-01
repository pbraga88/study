#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
void copyString(char dest[], char src[]);

int main(void) {
    struct student *studptr;
    int myAge;
    char myName[50];
    scanf("%s %d", myName, &myAge);
    studptr = createStudent(myName, myAge);
    printf("New student created: %s is %d years old.\n", studptr->name, studptr->age);
    free(studptr);
    return 0;
}

struct student *createStudent(char studentName[], int studentAge) {
	struct student *ptr;
	ptr = (struct student *)malloc(sizeof(struct student));
	copyString(ptr->name, studentName);
	ptr->age = studentAge;
	ptr->next = NULL;
	return ptr;
}

void copyString(char dest[], char src[])
{
	int i = 0;
	while(src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}