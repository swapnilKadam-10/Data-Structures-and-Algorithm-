#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Doubly linked list node structure
struct queue {
    int data;
    struct queue *next, *pre;
};

// Global front and rear pointers
struct queue *rear = NULL;
struct queue *front = NULL;

// Initialize the queue
void init() {
    front = rear = NULL;
}

// Check if queue is empty
int isempty() {
    return front == NULL;
}

// Insert multiple elements into the queue
void enqueue() {
    struct queue *newnode;
    int element, no;

    printf("Enter how many elements to add in queue:\t");
    scanf("%d", &no);

    for (int i = 0; i < no; i++) {
        newnode = (struct queue *)malloc(sizeof(struct queue));
        printf("Enter element %d: ", i + 1);
        scanf("%d", &newnode->data);

        newnode->next = NULL;
        newnode->pre = NULL;

        if (isempty()) {
            // If queue is empty, set front and rear to the new node
            front = rear = newnode;
        } else {
            // Link the new node at the end of queue
            rear->next = newnode;
            newnode->pre = rear;
            rear = newnode;
        }
    }
}

// Delete element from the front of the queue
void dequeue() {
    if (isempty()) {
        printf("Queue is empty\n");
        return;
    }

    struct queue *temp = front;
    printf("The deleted element is: %d\n", temp->data);

    // If only one element is present
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        front->pre = NULL;
    }

    free(temp);
}

// Display all queue elements
void display() {
    if (isempty()) {
        printf("Queue is empty\n");
        return;
    }

    struct queue *temp = front;
    printf("The queue elements are:\t");

    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

// Show the front element
void peek() {
    if (isempty()) {
        printf("Queue is empty\n");
    } else {
        printf("The peek element is: %d\n", front->data);
    }
}

// Main menu-driven function
int main() {
    int choice;

    do {
        printf("\n0. Create Queue\n1. Insert\n2. Delete\n3. Peek Element\n4. Display\n5. Is Empty?\n6. Exit\n");
        printf("Enter your choice:\t");
        scanf("%d", &choice);

        switch (choice) {
            case 0: init(); break;

            case 1: enqueue(); break;

            case 2: dequeue(); break;

            case 3: peek(); break;

            case 4: display(); break;

            case 5:
                if (isempty())
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;

            case 6: printf("\n\tExiting...\n"); break;

            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
