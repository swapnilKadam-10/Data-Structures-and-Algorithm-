#include <stdio.h>
#include <stdlib.h>

// Define structure for queue node
struct queue
{
  int data;
  struct queue *next;
};

// Global front and rear pointers
struct queue *front = NULL;
struct queue *rear = NULL;

// Initialize the queue
void init()
{
  front = rear = NULL;
}

// Check if the queue is empty
int isempty()
{
  return front == NULL;
}

// Insert elements into the queue
void enqueue()
{
  struct queue *newnode;
  int element, no;

  printf("Enter how many elements to add in queue:\t");
  scanf("%d", &no);

  for (int i = 0; i < no; i++)
  {
    newnode = (struct queue *)malloc(sizeof(struct queue));
    if (!newnode)
    {
      printf("Memory allocation failed!\n");
      return;
    }

    printf("Enter element %d: ", i + 1);
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (isempty())
    {
      front = rear = newnode;
    }
    else
    {
      rear->next = newnode;
      rear = newnode;
    }
  }
}

// Delete element from the front of the queue
void dequeue()
{
  if (isempty())
  {
    printf("Queue is empty! Nothing to delete.\n");
    return;
  }

  struct queue *temp = front;
  printf("The deleted element is: %d\n", front->data);
  front = front->next;
  free(temp);

  if (front == NULL)
  {
    rear = NULL; // reset rear also when queue becomes empty
  }
}

// Display all elements in the queue
void display()
{
  if (isempty())
  {
    printf("Queue is empty\n");
    return;
  }

  struct queue *temp = front;
  printf("The queue elements are:\t");
  while (temp != NULL)
  {
    printf("%d", temp->data);
    if (temp->next != NULL)
      printf(" -> ");
    temp = temp->next;
  }
  printf("\n");
}

// View the front element
void peek()
{
  if (isempty())
  {
    printf("Queue is empty. No front element.\n");
  }
  else
  {
    printf("The peek element is: %d\n", front->data);
  }
}

// Main menu-driven function
int main()
{
  int choice;

  do
  {
    printf("\n0. Create Queue\n1. Insert\n2. Delete\n3. Peek Element\n4. Display\n5. Is Empty?\n6. Exit\n");
    printf("Enter your choice:\t");
    scanf("%d", &choice);

    switch (choice)
    {
    case 0:
      init();
      break;

    case 1:
      enqueue();
      break;

    case 2:
      dequeue();
      break;

    case 3:
      peek();
      break;

    case 4:
      display();
      break;

    case 5:
      if (isempty())
        printf("Queue is empty\n");
      else
        printf("Queue contains elements\n");
      break;

    case 6:
      printf("\n\tExiting...\n");
      break;

    default:
      printf("Invalid choice! Please enter a valid option.\n");
    }
  } while (choice != 6);

  return 0;
}
