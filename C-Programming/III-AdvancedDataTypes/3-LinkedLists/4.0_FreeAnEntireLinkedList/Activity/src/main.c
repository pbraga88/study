#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
struct student *append(struct student * end, struct student * newStudptr);
void printStudents(struct student *start);
void freeStudents(struct student *start);
/* add any other prototypes as needed */
void copyString(char dest[], char src[]);

int main(void) {
    //! stack = showMemory(start=65520)
    struct student *start, *newStudptr, *end;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);

    start = createStudent("Petra", ageP);
    end = start;
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printStudents(start);
    freeStudents(start);

    return 0;
}

/* Place your function definitions here. Be sure to include the definitions for 
   createStudent(), append(), printStudents() as well as any other functions you 
   created for the previous tasks. */
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
  //! heap=showMemory(start=277, cursors=[ptr,start,tmp])
  while(start != NULL) {
    printf("%s is %d years old.\n", start->name, start->age);
    start = start->next;
  }
}

void freeStudents(struct student *start)
{
  struct student *ptr;
  while(ptr != NULL) {
    ptr = start->next;
    free(start);
    start = ptr;
  }
}