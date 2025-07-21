#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct queue
{
    int data[MAX];
    int rear;
    int front; 
};
struct queue q;

void init()
{
    q.front=q.rear=-1;
}

int isempty()
{
    if(q.front== -1)

       return 1;
    else
       return 0;
}

int isfull()
{
    if((q.rear==MAX -1 && q.front==0) ||(q.front==q.rear+1)) // check if queue is full or not.

        return 1;
    else
        return 0;
}

void enqueue( )
{ 
          int element;

     
       
       printf("enter the element to add in queue:\t");
                    scanf("%d",&element);
                    
        if(q.front==-1) // before insert an element if queue is empty intialize rear and front to 0.
        {
            q.front=0;
            q.rear=0;
        }
     
        else
        {
            if(q.rear==MAX-1) // check if queue is full , it set rear to first index
             q.rear=0;

             else
              q.rear++;
        }       
            q.data[q.rear]=element;
        
    
}

void dequeue()
{     
      if(isempty())
      {
        printf("queue is empty\n");
      }
    else
    {
     printf("the deleted element is %d\n",q.data[q.front]);

     if(q.front==q.rear) // only one element is present
     {
        q.front=-1;
        q.rear=-1;
     }
     else
     {
        if(q.rear==MAX) // if deleted   element is last element set rear as 0. 
        {
            q.rear=0;
        }
        else if(q.front==MAX)
        {
          q.front=0;
        }
        else
        {
            q.front++;
        }
     } 
    }   
}

void display()
{   
     if(isempty())
      {
        printf("queue is empty\n");
      }
    
    
    printf("the queue elements are:\t");

   /*for(int i=q.front;i<=q.rear;i++)
    {
         printf("%d->",q.data[i]);
    }
    */
   int i=q.front;
   while(i!=q.rear)
		{
			printf("%d ",q.data[i]);
			i=(i+1)%MAX;
		}

}

void peek()
{
    printf("the peek element is %d\n",q.data[q.front+1]);
}

int main()
{   
      int choice,element;
    do{
        printf("\n0.create \n 1.insert\n 2.delete \n 3.peek element \n 4.display \n 5.full \n 6.empty \n 7.exit\n");
        printf("enter the your choice:\t");
        scanf("%d",&choice);

        switch(choice)
        {   case 0:init();
                   break;

            case 1:    if(isfull())
                       {
                        printf("queue is full\n");
                      } 
                      else{
                    enqueue();
                      }
                    break;

            case 2:dequeue();
                    break;

            case 3:peek();
                   break;    

           
            case 4:if(isempty==0)
                   {
                     printf("queue is empty\n");
                   }
                   else{
                   display();
                   }
                   break;   
            
             case 5:if(isfull())
                   {
                     printf("queue is full\n");
                   }
                   break;  
           
           case 6:if(isempty())
                   {
                     printf("queue is empty\n");
                   }
                   break;  

            case 7: printf("\n \t EXIT \t \n");
                    break;

        }
    }while(choice !=7);
}