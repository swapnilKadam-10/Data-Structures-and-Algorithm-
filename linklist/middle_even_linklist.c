#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};

struct node *create(struct node *head)
{
  struct node *newnode, *temp;
  int n;
  printf("enter how many nodes:\t");
  scanf("%d", &n);

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
struct node *median(struct node *head)
{
  struct node *temp, *temp1;
  int count;

  temp = temp1 = head;

  while (temp1->next->next != NULL)
  {
    temp = temp->next;
    // dought - what is the middel position if total number of elements is 6.

    temp1 = temp->next->next;
  }

  return temp;
}
int main()
{
  struct node *head = NULL, *middle;
  int n;

  head = create(head);

  display(head);

  middle = median(head);

  printf("\n the middle position element in given linklist is %d\n", middle->data);
  return 0;
}