#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *createlist()
{
    int i,n;
    struct node *nn,*start=NULL,*temp;
    printf("Enter node:");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        nn=(struct node *)malloc(sizeof(struct node));
        nn->next=NULL;
        printf("Enter data:");
        scanf("%d",&nn->data);

        if(start==NULL)
        {
            start=temp=nn;
            temp=start;
        }
        else
        {
            temp->next=nn;
            temp=temp->next;
        }
    }
    return(start);
}

void reverse(struct node *temp)
{
    if(temp==NULL)
    {
        printf("\n");
        return;
    }
    reverse(temp->next);
    printf("%d->",temp->data);
}
void display(struct node *start)
{
    struct node *temp;
    temp=start;
    printf("START->");

    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("END\n");
}

int main()
{
    struct node *list;
    list=createlist();
    display(list);
    reverse(list);
    printf("START");
}