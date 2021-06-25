#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node* nextEl;
} Node;

// Funktioner som typiskt implementeras i samband med länkade listor

// Lägg till sist
void addNodeLast(Node* head, int data)
{
  Node* newEl = (Node*)malloc(sizeof(Node));
  newEl->data = data;
  newEl->nextEl = NULL;
  Node* ptr = head;

  while(ptr->nextEl!=NULL)
  {
    ptr = ptr->nextEl;
  }

  ptr->nextEl = newEl;
}

// Ta bort sist
void removeLastNode(Node* head)
{
    Node* ptr = head;
    Node* previousEl;
    while(ptr->nextEl!=NULL)
    {
      if(ptr->nextEl->nextEl == NULL)
      {
        previousEl = ptr;
      }
      ptr = ptr->nextEl;
    }
    previousEl->nextEl = NULL;
    free(ptr);
}

// Skriva ut
void printList(Node* head)
{
  Node* ptr = head;
  printf("\n[");
  while(ptr!=NULL)
  {
    if(ptr->nextEl == NULL)
    {
      printf("%d]\n", ptr->data);
    }
    else
    {
      printf("%d -> ", ptr->data);
    }
    ptr = ptr->nextEl;
  }
}

int main(int argc, char *argv[])
{
  // Initiering av pekare till början av listan
  Node* head = NULL;
  Node* first = NULL;
  Node* second = NULL;

  // Allokerar minne från heapen
  head   = (Node*)malloc(sizeof(Node));
  addNodeLast(head, 1);
  addNodeLast(head, 2);
  addNodeLast(head, 3);
  removeLastNode(head);

  printList(head);

  // Av-allokerar den givna minnesrymden från heapen
  free(head);
  return 0;
}
