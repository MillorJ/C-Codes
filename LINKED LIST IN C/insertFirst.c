#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int elem;
    struct node *next;
}*LIST, IType;

void initialize(LIST *h) {
    *h = NULL;
}

void insertFirst (LIST *head, int data) {
    LIST temp = malloc(sizeof(struct node));
    if (temp != NULL) {
        temp->elem = data;
        temp->next = *head;
        *head = temp;
    }
}

void displayList(LIST L) {
LIST trav;
for (trav = L; trav != NULL ; trav = trav->next) {
    printf("%d -> ", trav->elem);
}
printf("NULL");
}

int searchElem(LIST L, int data) {
    LIST trav;
    for (LIST trav = L; trav != NULL && trav->elem != data; trav = trav->next);
    return (trav != NULL) ? trav->elem : -1;
}




int main () {
    LIST L;
    initialize(&L);

    insertFirst(&L, 2);
    //displayList(L);


    int search = searchElem(L,2);
    printf("\n%d", search);


    return 0;
}