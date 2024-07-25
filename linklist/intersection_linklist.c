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
int intersection(struct node *head, struct node *head1)
{
    struct node *temp = head, *temp1 = head1;

    while (temp->next != NULL)
    {
        while (temp1->next != NULL)
        {
            if (temp->data == temp1->data)
            {
                int no = temp->data;
                return no;
            }

            temp1 = temp1->next;
        }
        temp = temp->next;
    }
}

int main()
{
    int n;
    struct node *head = NULL, *head1 = NULL, *first = NULL;
    printf("enter how many element");
    scanf("%d", &n);
    // create first list
    printf("\nenter the element of 1 st list\n");
    head = create(head, n);
    display(head);

    printf("\nenter the element of 2 nd list\n");

    // create second list
    head1 = create(head1, n);
    display(head);

    int result = intersection(head, head1);

    printf("the intersection point is %d\n", result);

    return 0;
}
