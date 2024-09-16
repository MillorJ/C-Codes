 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char elem;
    struct node *link;
}*Linklist

void deleteAll(Linklist *list, char elem) {
    int count = 0;

    Linklist *p = *list;
`
    while (*p != NULL) {
        if ((*p)->elem == elem) {
            Linklist temp = *p;
            *p = (*p)->link;
            free(temp);
            count++;
        } else {
            p = &(*p)->link;
        }
    }
    return count;
    
}

void deleteElem(Linklist *list, char elem) {
    Linklist *p = list;
    
    while (*p != NULL && (*p)->elem != elem) {
        p = &(*p)->link;
    }
    
    if (*p != NULL) {
        Linklist temp = *p;
        *p = (*p)->link;
        free(temp);
    }
}

int main() {
    Linklist list = (Linklist)malloc(sizeof(Linklist));
    list->elem = 'a';
    list->link = (Linklist)malloc(sizeof(Linklist));
    list->link->elem = 'b';
    list->link->link = (Linklist)malloc(sizeof(Linklist));
    list->link->link->elem = 'b';
    list->link->link->link = NULL;
    
    printf("Original list: ");
    Linklist current = list;
    while (current != NULL) {
        printf("%c ", current->elem);
        current = current->link;
    }
    printf("\n");
    
    deleteAll(&list, 'b');

    
    printf("List after deleting 'b': ");
    current = list;
    while (current != NULL) {
        printf("%c ", current->elem);
        current = current->link;
    }
    printf("\n");
    
    return 0;
}



