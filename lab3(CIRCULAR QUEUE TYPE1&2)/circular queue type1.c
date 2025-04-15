#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXSIZE 5
void enqueue(int item);
int dequeue();
void display();
int front=-1, rear=-1;
int a[MAXSIZE];

void main()
{
    int n,i,opt;
    do
    {
       printf("\nEnter a choice");
       printf("\n1: Enqueue operation");
       printf("\n2: Dequeue operation");
       printf("\n3: Display data elements");
       printf("\n4: Exit...");
       printf("\n");
       scanf("%d",&opt); 
       switch (opt)
       {
         case 1:
              printf("enter a number to insert into the queue.....");
              scanf("%d",&n);
              enqueue(n);
              break;
         case 2:
              n=dequeue();
              printf("The deleted item is %d",n);
              break;
         case 3:
              display();
              break;
         case 4:
              exit(0);
        }
    } 
	while (opt!=4);
    getch();
}

void enqueue(int item)
{
    if(front==0 && rear==MAXSIZE-1)
         printf("queue is full");
    else
    {
        if (front==-1 && rear==-1)
        {
            front=0;
            rear=0;
        }
        else if (front!=0 && rear==MAXSIZE-1)
        {
            rear=0;
        }
        else
        ++rear;
        a[rear]=item;
        
    }
}
int dequeue()
{
    if (front==-1 && rear==-1)
    {
        printf("queue is empty");
        return -1;
    }
        int item=a[front];
    if (front==rear)
    {
        front=rear=-1;
    }
    else if (front==MAXSIZE-1)
    {
        front=0;
    }
    else
    front++;
    return item;
}
void display()
{
    printf("the item in the queue are");
    int i;
    if (front<rear)
    {
        for ( i = front; i <=rear; i++)
        {
            printf("%d",a[i]);
        }
        
    }
    else
    {
        for(i=front;i<=MAXSIZE-1;i++)
        {
            printf("%d",a[i]);
        }
        for ( i = 0; i <= rear; i++)
        {
            printf("%d",a[i]);
        }
        
    }
    
}
