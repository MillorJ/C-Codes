#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
   char FN[24], LN[16], MI;   //first name, last name, middle initial
} Nametype;

typedef struct {
   char ID[10];
   Nametype name;
   char course[8];
   int yearLevel;
} studrec;

typedef struct node {
    studrec stud;
    struct node *link;
}* LIST;

// Function to find a student record based on the given ID
studrec findStudent(LIST list, char id[]) {
    LIST ptr = list;
    studrec dummy;
    strcpy(dummy.ID, "XXXXXX");

    while (ptr != NULL && strcmp(ptr->stud.ID, id) != 0) {
        ptr = ptr->link;
    }

    if (ptr != NULL) {
        return ptr->stud;
    } else {
        return dummy;
    }
}

int main() {
    // Create a linked list of student records
    LIST list = NULL;

    // Add some sample student records to the list
    studrec s1, s2, s3;
    strcpy(s1.ID, "1001");
    strcpy(s1.name.FN, "John");
    strcpy(s1.name.LN, "Doe");
    s1.name.MI = 'M';
    strcpy(s1.course, "IT");
    s1.yearLevel = 1;

    strcpy(s2.ID, "1002");
    strcpy(s2.name.FN, "Jane");
    strcpy(s2.name.LN, "Smith");
    s2.name.MI = 'C';
    strcpy(s2.course, "CS");
    s2.yearLevel = 2;

    strcpy(s3.ID, "1003");
    strcpy(s3.name.FN, "Bob");
    strcpy(s3.name.LN, "Johnson");
    s3.name.MI = 'R';
    strcpy(s3.course, "EE");
    s3.yearLevel = 3;

    // Link the student records to form a list
    list = (LIST) malloc(sizeof(struct node));
    list->stud = s1;
    list->link = (LIST) malloc(sizeof(struct node));
    list->link->stud = s2;
    list->link->link = (LIST) malloc(sizeof(struct node));
    list->link->link->stud = s3;
    list->link->link->link = NULL;

    // Test the findStudent() function
    char id[10];
    printf("Enter a student ID to search for: ");
    scanf("%s", id);

    studrec result = findStudent(list, id);
    if (strcmp(result.ID, "XXXXXX") == 0) {
        printf("Student not found.\n");
    } else {
        printf("Student record:\n");
        printf("ID: %s\n", result.ID);
        printf("Name: %s %c. %s\n", result.name.FN, result.name.MI, result.name.LN);
        printf("Course: %s\n", result.course);
        printf("Year Level: %d\n", result.yearLevel);
    }

    return 0;
}
