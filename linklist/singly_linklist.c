// singly linked list  operation

#include <stdio.h>
#include <stdlib.h>
// Declaring node structure for singly linked list.
struct node
{
  int data;
  struct node *next;
};

// Function to create a new linked list.
struct node *create(struct node *head, int n)
{
  struct node *newnode, *temp;

  for (int i = 0; i < n; i++)
  {

    newnode = (struct node *)malloc(sizeof(struct node *));
    if (newnode == NULL)
    {
      printf("memory is not allocated\n");
    }
    else
    {
      printf("enter the data\t");
      scanf("%d", &newnode->data);

      newnode->next = NULL;

      if (head == NULL)
      {
        head = temp = newnode;
      }
      else
      {
        temp = temp->next = newnode;
      }
    }
  }
  return head;
}
// Function to display linked list data.
void display(struct node *head)
{
  struct node *temp = head;

  printf("the contents are:\n");

  while (temp != NULL)
  {
    printf("%d\t", temp->data);

    temp = temp->next;
  }
}
// Function to add a new node to the linked list.
struct node *insert(struct node *head, int pos)
{
  struct node *newnode = NULL, *temp = head;
  int i;

  newnode = (struct node *)malloc(sizeof(struct node *));
  if (newnode == NULL)
  {
    printf("memory is not allocated\n");
  }
  else
  {
    printf("enter the data\t");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    if (pos == 0)
    {
      newnode->next = head;
      head = newnode;
    }
    else
    {
      for (i = 0, temp = head; i < pos - 1 && temp->next != NULL; i++, temp = temp->next);
      newnode->next = temp->next;
      temp->next = newnode;
    }
  }
  return head;
}
// Function to remove a node from the linked list.
struct node *remove(struct node *head, int pos)
{
  struct node *temp, *temp1;
  int i;

  if (pos == 1)
  {
    temp = head->next;
    head = temp;
  }
  else
  {
    for (i = 1, temp = head; i <= pos - 1 && temp != NULL; i++, temp = temp->next);

    temp1 = temp->next;
    temp->next = temp1->next;
    temp1 = NULL;
    free(temp1);
  }
  return head;
}
// Function to search a value in linked list.
void search(struct node *head, int key)
{
  struct node *temp = head;
  int flag = 0;

  while (temp != NULL)
  {
    if (temp->data == key)
    {
      flag = 1;
    }
    temp = temp->next;
  }
  if (flag == 1)
    printf("\n The %d is found \n", key);
  else
    printf("\n The %d is  not found \n", key);
}

int main()
{
  struct node *head = NULL;
  int n, pos, pos1, key;

  int choice;
  do
  {
    printf("\n*****\n");
    printf("0. Create\n");
    printf("1. display\n");
    printf("2. Insert Node in specific position\n");
    printf("3.delete\n");
    printf("4.search\n");
    printf("5. ** To exit **");

    printf("\n Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
      printf("enter no of nodes\n");
      scanf("%d", &n);
      head = create(head, n);
      break;

    case 1:
      display(head);
      break;

    case 2:
      printf("enter position of node\n");
      scanf("%d", &pos);
      head = insert(head, pos);
      break;

    case 3:
      printf("enter position of node\n");
      scanf("%d", &pos1);

      head = remove(head, pos1);
      break;

    case 4:
      printf("\n enter the no you want to check:\t");
      scanf("%d", &key);
      search(head, key);
      break;
    }
  } while (choice != 5);

  return 0;
}
