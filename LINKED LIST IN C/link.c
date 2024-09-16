#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char elem;
  struct node *link;
} Node;

void insertElem(Node **head, char elem) {
  // allocate memory for a new node
  Node* new_node = (Node*) malloc(sizeof(Node));

  // set the element and link of the new node
  new_node->elem = elem;
  new_node->link = *head;

  // update the head of the linked list to point to the new node
  *head = new_node;
}

int deleteAllOccur(Node **head, char elem) {
  int count = 0;

  // traverse the linked list using pointer to pointer
  Node **current = head;

  while (*current != NULL) {
    if ((*current)->elem == elem) {
      count++;
      // delete the node by updating the link of the previous node
      Node *temp = *current;
      *current = (*current)->link;
      free(temp);
    } else {
      current = &((*current)->link);
    }
  }

  return count;
}

int main() {
  Node *head = NULL;

  // insert some elements at the beginning of the linked list
  insertElem(&head, 'A');
  insertElem(&head, 'B');
  insertElem(&head, 'C');
  insertElem(&head, 'B');
  insertElem(&head, 'D');

  // print the linked list before deletion
  printf("Linked list before deletion: ");
  Node *current = head;
  while (current != NULL) {
    printf("%c ", current->elem);
    current = current->link;
  }
  printf("\n");

  // delete all occurrences of 'B' from the linked list
  int num_deleted = deleteAllOccur(&head, 'B');

  // print the linked list after deletion
  printf("Linked list after deletion: ");
  current = head;
  while (current != NULL) {
    printf("%c ", current->elem);
    current = current->link;
  }
  printf("\n");

  // print the number of elements deleted
  printf("Number of elements deleted: %d\n", num_deleted);

  // free the memory used by the linked list
  current = head;
  while (current != NULL) {
    Node *temp = current;
    current = current->link;
    free(temp);
  }

  return 0;
}
