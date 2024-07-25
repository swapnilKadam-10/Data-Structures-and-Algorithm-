// doubly linked list operations

#include <stdio.h>
#include <stdlib.h>
// Declaring node structure for doubly linked list.
struct node
{
   int data;
   struct node *next, *pre;
};

// Function to create a node.
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
      }
      else
      {
         temp->next = newnode;
         newnode->pre = temp;
         temp = newnode;
      }
   }

   return head;
}
// Function to display the linked list.
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
// Function to insert new node in linklist.
struct node *insert(struct node *head)
{
   struct node *newnode, *temp;
   int i, pos;

   printf("enter the position you want to add element:\t");
   scanf("%d", &pos);

   newnode = (struct node *)malloc(sizeof(struct node));

   printf("enter the node data:\t");
   scanf("%d", &newnode->data);

   newnode->next = NULL;
   newnode->pre = NULL;

   if (pos == 0)
   {
      newnode->next = head;
      head->pre = newnode;
      head = newnode;
   }
   else
   {
      for (i = 0, temp = head; i < pos - 1 && temp->next != NULL; i++, temp = temp->next);

      newnode->next = temp->next;
      if (temp->next != NULL)
      {
         temp->next->pre = newnode;
      }
      temp->next = newnode;
      newnode->pre = temp;
      temp = newnode;
   }

   return head;
}
// Function to search a value in linked list.
void search(struct node *head)
{
   struct node *temp = head;
   int key, pos = 0, flag = 0;

   printf("enter the element you want to check:\t");
   scanf("%d", &key);

   while (temp->next != NULL)
   {
      pos++;
      if (key == temp->data)
      {
         printf(" the given element is found at %d position \n", pos);
         flag = 1;
      }
      temp = temp->next;
   }
   if (flag == 0)
      printf(" the given element is not found\n");
}
// Function to remove node from the linked list.
struct node *remove(struct node *head)
{
   struct node *temp, *temp1;
   int pos, i;

   printf("enter the position yoou want to delete element:\t");
   scanf("%d", &pos);

   if (pos == 0)
   {
      temp = head;
      head = head->next;
      free(temp);
   }
   else
   {
      for (i = 0, temp = head; i < pos - 1 && temp->next != NULL; i++, temp = temp->next);

      temp1 = temp->next;
      temp->next = temp1->next;

      temp1->pre = NULL;
      temp1->next = NULL;
      free(temp1);
   }
   return head;
}

// Main function.
int main()
{
   struct node *head = NULL;
   int choice, i;

   do
   {
      printf("\n*****\n");
      printf("0. Create\n");
      printf("1. display\n");
      printf("2.search\n");
      printf("3. Insert Node in specific position\n");
      printf("4. Delete\n");
      printf("5. ** To exit **");

      printf("\n Enter your choice: ");
      scanf("%d", &choice);
      switch (choice)
      {
      case 0:
         head = create(head);
         break;

      case 1:
         display(head);
         break;

      case 2:
         search(head);
         break;

      case 3:
         head = insert(head);
         break;

      case 4:
         head = remove(head);
      }
   } while (choice != 5);

   return 0;
}