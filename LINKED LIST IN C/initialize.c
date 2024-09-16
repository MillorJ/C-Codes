#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int elem;
    struct node *next;

}*LIST, IType;

void initialize(LIST *h) {
    *h = NULL;
}

int main () {
    LIST *head;
    initialize(&h);

}