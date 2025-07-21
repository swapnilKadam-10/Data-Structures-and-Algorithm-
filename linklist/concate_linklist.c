// Concatenation of the two linked list in one.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create(struct node *head, int n)
{
    struct node *newnode = NULL, *last = NULL;
    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = last = newnode;
        }
        else
            last->next = newnode;
        last = newnode;
    }
    return head;
}
void display(struct node *head)
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("END");
    printf("\n");
}
void concate(struct node *first, struct node *second)
{
    struct node *first = first;
    do
    {
        first = first->next;
    } while (first->next != NULL);

    first->next = second;
}

int main()
{
    int n;
    struct node *head = NULL, *head1 = NULL, *first = NULL;
    printf("enter how many element");
    scanf("%d", &n);
    // create first list
    printf("\nEnter the element of 1st list:\n");
    head = create(head, n);
    display(head);

    // create second list
    printf("\nEnter the element of 2nd list:\n");
    head1 = create(head1, n);
    display(head);

    concate(head, head1); // function call to concate(). 
    display(head);
}