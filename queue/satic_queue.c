#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Static queue using array
struct queue {
    int data[MAX];
    int rear;
    int front;
};

struct queue q;

// Initialize the queue
void init() {
    q.front = q.rear = -1;
}

// Check if queue is empty
int isempty() {
    return q.front == q.rear;
}

// Check if queue is full
int isfull() {
    return q.rear == MAX - 1;
}

// Enqueue (insert) elements
void enqueue() {
    int element, no;

    if (isfull()) {
        printf("Queue is full\n");
        return;
    }

    printf("Enter how many elements to add in queue:\t");
    scanf("%d", &no);

    for (int i = 0; i < no; i++) {
        if (isfull()) {
            printf("Queue is full. Cannot add more elements.\n");
            return;
        }
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);

        q.rear++;
        q.data[q.rear] = element;
    }
}

// Dequeue (remove) element from front
void dequeue() {
    if (isempty()) {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }

    q.front++;
    printf("The deleted element is: %d\n", q.data[q.front]);

    // Optional: Reset queue if all elements are dequeued
    if (q.front == q.rear) {
        q.front = q.rear = -1;
    }
}

// Display elements of the queue
void display() {
    if (isempty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("The queue elements are:\t");
    for (int i = q.front + 1; i <= q.rear; i++) {
        printf("%d", q.data[i]);
        if (i != q.rear)
            printf(" -> ");
    }
    printf("\n");
}

// View the front element
void peek() {
    if (isempty()) {
        printf("Queue is empty. No front element.\n");
    } else {
        printf("The peek element is: %d\n", q.data[q.front + 1]);
    }
}

// Main function (menu-driven)
int main() {
    int choice;

    do {
        printf("\n0. Create Queue\n1. Insert\n2. Delete\n3. Peek Element\n4. Display\n5. Is Full?\n6. Is Empty?\n7. Exit\n");
        printf("Enter your choice:\t");
        scanf("%d", &choice);

        switch (choice) {
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
                if (isfull())
                    printf("Queue is full\n");
                else
                    printf("Queue has space\n");
                break;

            case 6:
                if (isempty())
                    printf("Queue is empty\n");
                else
                    printf("Queue contains some elements\n");
                break;

            case 7:
                printf("\n\tEXITING...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
