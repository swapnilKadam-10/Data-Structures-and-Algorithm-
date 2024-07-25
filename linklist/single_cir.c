#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
   struct node *next;
};

 struct node* create( struct node *head,int n)
{
   struct node *newnode,*temp;
 
     for(int i=0;i<n;i++)
      {
   
        newnode=(struct node *)malloc(sizeof(struct node ));
            if(newnode==NULL)
           {
               printf("memory is not allocated\n");
           }
    else{  
           printf("enter the data\t");
           scanf("%d",&newnode->data);
  
           newnode->next=NULL;

         if(head==NULL)
          {
              head=temp=newnode;
              head->next=newnode;
          }
           else
             {
               temp->next=newnode;
               newnode->next=head;
                temp=newnode;
             }
       }
   }
     return head;
}
void display(struct node *head)
{
   struct node *temp=head;
   
     printf("the contents are:\n");
    do
    {
      printf("%d\t",temp->data);
     
       temp=temp->next;
    } while(temp!=head);  
  
}

struct node *search(struct node *head)
{
  int key,count=0,flag=0;
  struct node *temp=head;
   printf("enter the number to check\t");
   scanf("%d",&key);

   do{  
        count++;
       if(key==(temp->data))
       {
         printf("the %d is found at %d",key,count);
          flag=1;
       }
       temp=temp->next;
   }while(temp!=head);

   if(flag==0)
     printf("Number not found\n");

     return head;
}

struct node *insert(struct node *head)
{
   struct node *temp,*newnode;
   int i,pos;

   printf("enter the position you want to add element\t");
   scanf("%d",&pos);

     newnode=(struct node *)malloc(sizeof(struct node));
           printf("enter the data\t");
           scanf("%d",&newnode->data);
  
           newnode->next=NULL;
        
     if(pos==0)
     {           
           for(temp=head;temp->next!=head;temp=temp->next);
               newnode->next=head;
               temp->next=newnode;             
               head=newnode;
     }
         else
         {
           for(i=0,temp=head;i<pos-1 && temp->next!=head;i++,temp=temp->next);
           
              newnode->next=temp->next;
              temp->next=newnode;
                     
         }

     
     return head;
    
}
struct node *remove(struct node *head)
{
    struct node *temp,*temp1;
    int pos,i;
     printf("enetr trhe pos");
     scanf("%d",&pos);
     if(pos==0)
     {
        temp1=head;
        for(temp=head;temp->next!=head;temp=temp->next);

        head=head->next;
        temp->next=head;
        free(temp1);
     }
     else{
        for(i=0,temp=head;i<pos-1&&temp->next!=head;temp=temp->next,i++);
        temp1=temp->next;
        temp->next=temp1->next;
        free(temp1);

     }
  return head;
}
int main()
{
    struct node *head=NULL;
    int n,pos;

     int choice;
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
		scanf("%d",&choice);
		switch(choice)
		{
        case 0:printf("enter no of nodes\n");
               scanf("%d",&n);
               head=create(head,n);
               break;

        case 1:display(head);
                break;

        case 2: search(head);
                break;

        case 3: head=insert(head);
                break;

        case 4:head=remove(head);
                break;


  default:printf("\n Wrong Choice");
                  
    }
  }while(choice!=5);

  return 0;
}
