#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[50], int studentAge);
struct student * append(struct student * end, struct student * newStudptr); 
void printStudents(struct student *start);
/* add other prototypes here if needed*/
void copyString(char dest[], char src[]);

int main(void) {
    struct student *start, *newStudptr, *end, *tmp;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);

    start = createStudent("Petra", ageP);
    end = start;

    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);

    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printStudents(start);
    tmp = start->next;

    free(start);

    start = tmp;
    tmp = start->next;

    free(start);
    free(tmp);

    return 0;
}

/* Place your function definitions here. Be sure to include the definitions for 
   createStudent() and append() as well as any other functions you created for 
   the previous tasks. */
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

struct student *append(struct student * end, struct student * newStudptr)
{
    return (end->next = newStudptr);
}

void printStudents(struct student *start)
{
  while(start != NULL) {
    printf("%s is %d years old.\n", start->name, start->age);
    start = start->next;
  }

}