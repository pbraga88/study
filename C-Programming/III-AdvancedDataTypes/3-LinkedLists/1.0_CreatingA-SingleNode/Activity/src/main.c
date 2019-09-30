#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);

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
	int i = 0;
	struct student *ptr;
	ptr = (struct student *)malloc(sizeof(struct student));
	while(studentName[i]!='0') {
		ptr->name[i] = studentName[i];
		i++;
	}
	ptr->name[i] = '\0';
	ptr->age = studentAge;
	ptr->next = NULL;
	return ptr;
}