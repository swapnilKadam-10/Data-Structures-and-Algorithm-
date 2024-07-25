// doubly  circular linked list

#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next, *pre;
};
static int total;
struct node *create(struct node *head)
{
  struct node *newnode, *temp;
  int no, i;

  printf("enter the no of nodes ");
  scanf("%d", &no);

  for (i = 0; i < no; i++)
  {
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("enter the data:\t");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->pre = NULL;

    if (head == NULL)
    {
      head = temp = newnode;
      head->next = head->pre = newnode;
    }
    else
    {
      newnode->next = head;
      newnode->pre = temp;
      temp->next = newnode;
      temp = newnode;
    }
    total++;
  }
  return head;
}
void display(struct node *head)
{
  struct node *temp = head;

  printf("the list contents are:\t");

  do
  {
    printf("%d->", temp->data);

    temp = temp->next;

  } while (temp != head);
}

struct node *insert(struct node *head)
{
  struct node *newnode, *temp;
  int i, pos;

  printf("Enter the position you want to add element:\t");
  scanf("%d", &pos);

  newnode = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter the data\t");
  scanf("%d", &newnode->data);

  newnode->next = newnode->pre = NULL;

  if (pos == 0)
  {

    for (temp = head; temp->next != head; temp = temp->next)
      ;
    newnode->next = head;
    temp->next = newnode;
    newnode->pre = temp;
    head = newnode;
  }
  else
  {
    for (i = 0, temp = head; i < pos - 1 && temp->next != head; i++, temp = temp->next)
      ;
    newnode->next = temp->next;
    temp->next->pre = newnode;
    newnode->pre = temp;
    temp->next = newnode;
  }
  total++;
  return head;
}

struct node *remove(struct node *head)
{
  struct node *temp, *temp1;
  int pos, i;

  printf("enter the position you want to delete element:\t");
  scanf("%d", &pos);

  if (pos == 0)
  {
    for (temp = head; temp->next != head; temp = temp->next)
      ;
    temp1 = head;
    head = head->next;
    temp->next = head;
    free(temp1);
  }
  else
  {
    for (i = 0, temp = head; i < pos - 1 && temp->next != head; i++, temp = temp->next)
      ;

    temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
  }
  total--;
  return head;
}
int main()
{
  struct node *head = NULL;
  int n, pos;

  int choice;
  do
  {
    printf("\n*****\n");
    printf("0. Create\n");
    printf("1. display\n");
    printf("2. Insert Node in specific position\n");
    printf("3. Delete\n");
    printf("4. ** To exit **");

    printf("\n Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 0:
      head = create(head);
      break;

    case 1:
      if (total == 0)
      {
        printf("list is empty\n");
      }
      else
      {
        display(head);
      }
      break;

    case 2:
      head = insert(head);
      break;

    case 3:
      head = remove(head);
      break;

    default:
      printf("\n Wrong Choice");
      break;
    }
  } while (choice != 4);

  return 0;
}
