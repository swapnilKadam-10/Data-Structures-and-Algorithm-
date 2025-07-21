#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the queue
struct queue
{
	int data;
	struct queue *next;
} *front = NULL, *rear = NULL;

// Function to check if the queue is empty
int isempty()
{
	if (front == NULL && rear == NULL)
		return 1;
	else
		return 0;
}

// Function to insert an element into the circular queue
void insertq(int n)
{
	struct queue *temp;
	// Allocate memory for new node
	temp = (struct queue *)malloc(sizeof(struct queue));
	temp->next = NULL;
	temp->data = n;

	// If queue is empty
	if (front == NULL)
	{
		front = rear = temp;
	}
	else
	{
		rear->next = temp; // Link new node to the end of queue
		rear = temp;       // Make new node the rear
	}
	rear->next = front; // Make queue circular by pointing rear to front
}

// Function to delete an element from the front of the queue
int deleteq()
{
	int x;
	struct queue *temp;

	// If only one element in the queue
	if (front == rear)
	{
		x = front->data;
		free(front);
		front = rear = NULL;
	}
	else if (isempty()) // Check again if queue is empty
	{
		printf("\nQueue is NULL");
		x = -1;
	}
	else
	{
		x = front->data;
		rear->next = front->next; // Update rear link
		temp = front;
		front = front->next;      // Move front to next
		free(temp);               // Free the old front
	}
	return x;
}

// Function to display elements of the circular queue
void display()
{
	struct queue *temp;

	// If queue is empty
	if (isempty())
	{
		printf("Queue is empty.\n");
		return;
	}

	temp = front;
	do
	{
		printf("%d ", temp->data);
		temp = temp->next;
	} while (temp != front);
	printf("\n");
}

int main()
{
	int n, ch;

	printf("\n1.Insert\n2.Delete\n3.Exit\n");

	while (1)
	{
		printf("\nEnter choice: ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
		{
			// Inserting 3 fixed values for testing
			insertq(1);
			insertq(2);
			insertq(3);
			printf("Queue after insertion: ");
			display();
			break;
		}
		case 2:
		{
			n = deleteq();
			printf("Deleted element: %d\n", n);
			printf("Queue after deletion: ");
			display();
			break;
		}
		case 3:
		{
			exit(0); // Exit the program
		}
		default:
			printf("Invalid choice.\n");
		}
	}
}
