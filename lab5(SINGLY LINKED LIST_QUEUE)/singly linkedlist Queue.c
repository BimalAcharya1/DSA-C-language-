#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
	int info;
	struct Node *next;
};
//typedef struct Node node;
struct Node *front=NULL;
struct Node *rear=NULL;
void enqueue(int num);
void dequeue();
void display();
int main()
{
	int ch,n,num;
	while(1)
	{
		printf("\nEnter your choice:\n");
		printf("\n1. Enqueue operation");
		printf("\n2. Dequeue operation");
		printf("\n3. Display");
		printf("\n4. Exit");
		printf("\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter data to enqueue into the stack....");
				scanf("%d",&num);
				enqueue(num);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
		}
	}
	getch();
	return 0;
}
void enqueue(int num)
{
	struct Node *newnode;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->info=num;
	if(front==NULL)
	{
		front=newnode;
		rear=newnode;
		front->next=NULL;
		rear->next=NULL;		
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
		rear->next=NULL;
	}
	printf("%d is required into the queue",num);
}
void dequeue()
{
	struct Node *temp;
	if(front==NULL)
	   printf("Queue is empty...");
	   else
	   {
	   	temp=front;
	   	front=front->next;
	   	printf("Dequeued element is %d",temp->info);
	   	free(temp);
	   }
}
void display()
{
	
	 struct Node *temp;
	if(front==NULL)
	   printf("Queue is empty");
	else
	{
		temp=front;
		printf("Contents are:\n");
		while(temp!=rear)
		{
			printf("%d-->",temp->info);
			temp=temp->next;
		}
		printf("%d",temp->info);
	}
}
