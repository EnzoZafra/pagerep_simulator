/**
  *
  * stack.c
  *
  * Lorenzo Zafra 1395521
  * CMPUT 379 Assignment 4
  */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "stack.h"

uint32_t size = 0;

node* newNode(uint32_t data) {
  node* item = (node *) malloc(sizeof(node));
  item->data = data;
  item->above = NULL;
  item->below = NULL;

  return item;
}

void push(node** head, node** tail, uint32_t data) {
  size++;
  node* temp = newNode(data);

  if(*head == NULL && *tail == NULL) {
    (*head) = temp;
    (*tail) = temp;
    return;
  }

  temp->below = *head;
  (*head)->above = temp;
  *head = temp;
}

node* pop(node** head) {
  size--;
  node* tmp = (*head);
  (*head)->below->above = NULL;
  *head = (*head)->below;

  return tmp;
}

node* search(node** head, uint32_t data) {
  if ((*head) == NULL) {
    printf("Head is null\n");
    return NULL;
  }

  node* tmp = *head;
  // find node to be deleted
  while (tmp->data != data) {
    tmp = tmp->below;
    if (tmp == NULL) {
      return NULL;
    }
  }

  return tmp;
}

uint32_t del(node** head, node** tail, node* tmp) {
  if ((*head) == NULL || tmp == NULL || (*tail) == NULL) {
    return -1;
  }

  // if head or tail being deleted, change corresponding ref
  if ((*head) == tmp) {
    *head = tmp->below;
  }

  if ((*tail) == tmp) {
    *tail = tmp->above;
  }

  // Change below only if node to be deleted is NOT the tail
  if (tmp->below != NULL) {
    tmp->below->above = tmp->above;
  }

  // Change above only if node to be deleted is NOT the head
  if (tmp->above != NULL) {
    tmp->above->below = tmp->below;
  }

  // Free memory occupied
  /* free(tmp); */
  size--;
  return tmp->data;
}

uint32_t delTail(node** head, node** tail) {
  return del(head, tail, (*tail));
}

// This function prints contents of linked list starting from the given node
/* void printList(node* root) { */
/*   /1* printf("\nTraversal in down direction \n"); *1/ */
/*   node* last; */
/*   while (root != NULL) { */
/*     printf(" %d ", root->data); */
/*     last = root; */
/*     root = root->below; */
/*   } */
/*   printf("\n"); */
/* } */

// moves a node from a middle of the stack to the top
void moveToTop(node** head, node** tail, uint32_t data) {
  node* tobedeleted = search(head, data);
  del(head, tail, tobedeleted);
  push(head, tail, data);
}

// returns the size of stack
uint32_t stack_size() {
  return size;
}

// Testing stack
/* int main() { */
/*   node* head = NULL; */
/*   node* tail = NULL; */

/*   push(&head, &tail, 5); */
/*   push(&head, &tail, 10); */
/*   push(&head, &tail, 15); */
/*   push(&head, &tail, 3); */
/*   push(&head, &tail, 23); */
/*   push(&head, &tail, 0); */
/*   push(&head, &tail, 900); */
/*   push(&head, &tail, 150); */
/*   printList(head); */

/*   node* tmp = tail; */
/*   // Traverse (queue) look for page with ref bit = 0 */
/*   while (tmp != NULL) { */
/*     printf("%i->", tmp->data) */
/*     tmp = tmp->above; */

/*     // When we've gone full circle go back up. */
/*     if (tmp == NULL) { */
/*       tmp = tail; */
/*     } */
/*   } */

  /* printf("Delete 23\n"); */
  /* node* tmp = search(&head, 23); */
  /* del(&head, &tail, tmp); */
  /* free(tmp); */
  /* printList(head); */

  /* printf("Try to Delete 696969\n"); */
  /* tmp = search(&head, 696969); */
  /* del(&head, &tail, tmp); */
  /* free(tmp); */
  /* printList(head); */

  /* printf("Move 15 to top\n"); */
  /* moveToTop(&head, &tail, 15); */
  /* printList(head); */

  /* printf("Delete from tail\n"); */
  /* delTail(&head, &tail); */
  /* printList(head); */
  /* if (tail == NULL) { */
  /*   printf("Tail null\n"); */
  /* } else { */
  /*   printf("Tail value: %i\n", tail->data); */
  /* } */

  /* printf("Delete 15\n"); */
  /* tmp = search(&head, 15); */
  /* del(&head, &tail, tmp); */
  /* free(tmp); */
  /* printList(head); */

  /* printf("pop\n"); */
  /* pop(&head); */
  /* printList(head); */

  /* printf("Push 1111 and 2309\n"); */
  /* push(&head, &tail, 1111); */
  /* push(&head, &tail, 2309); */
  /* printList(head); */

  /* printf("pop\n"); */
  /* pop(&head); */
  /* printList(head); */

  /* printf("Delete 10\n"); */
  /* tmp = search(&head, 10); */
  /* del(&head, &tail, tmp); */
  /* free(tmp); */
  /* printList(head); */

  /* printf("Delete from tail\n"); */
  /* delTail(&head, &tail); */
  /* printList(head); */
  /* if (tail == NULL) { */
  /*   printf("Tail null\n"); */
  /* } else { */
  /*   printf("Tail value: %i\n", tail->data); */
  /* } */

  /* printf("Delete from tail\n"); */
  /* delTail(&head, &tail); */
  /* printList(head); */
  /* if (tail == NULL) { */
  /*   printf("Tail null\n"); */
  /* } else { */
  /*   printf("Tail value: %i\n", tail->data); */
  /* } */

  /* printf("Delete from tail\n"); */
  /* delTail(&head, &tail); */
  /* printList(head); */
  /* if (tail == NULL) { */
  /*   printf("Tail null\n"); */
  /* } else { */
  /*   printf("Tail value: %i\n", tail->data); */
  /* } */

  /* printf("Delete from tail\n"); */
  /* delTail(&head, &tail); */
  /* printList(head); */
  /* if (tail == NULL) { */
  /*   printf("Tail null\n"); */
  /* } else { */
  /*   printf("Tail value: %i\n", tail->data); */
  /* } */

  /* printf("Delete from tail\n"); */
  /* delTail(&head, &tail); */
  /* printList(head); */
  /* if (tail == NULL) { */
  /*   printf("Tail null\n"); */
  /* } else { */
  /*   printf("Tail value: %i\n", tail->data); */
  /* } */

  /* printf("Delete from tail\n"); */
  /* delTail(&head, &tail); */
  /* printList(head); */
  /* if (tail == NULL) { */
  /*   printf("Tail null\n"); */
  /* } else { */
  /*   printf("Tail value: %i\n", tail->data); */
  /* } */

  /* printf("Delete from tail\n"); */
  /* delTail(&head, &tail); */
  /* printList(head); */
  /* if (tail == NULL) { */
  /*   printf("Tail null\n"); */
  /* } else { */
  /*   printf("Tail value: %i\n", tail->data); */
  /* } */
/* } */
