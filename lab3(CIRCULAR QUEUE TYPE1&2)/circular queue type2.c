#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#define MAXSIZE 5

void enqueue(int item);
int dequeue();
void display();

             int front = -1, rear = -1;
             int a[MAXSIZE];
             int count = 0;

void main() {
    int n, opt;
    do {
        printf("\nEnter a choice");
        printf("\n1: Enqueue operation");
        printf("\n2: Dequeue operation");
        printf("\n3: Display data elements");
        printf("\n4: Exit...\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter a number to insert into the queue: ");
                scanf("%d", &n);
                enqueue(n);
                break;
            case 2:
                n = dequeue();
                
                    printf("The deleted item is %d\n", n);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (opt != 4);
}

void enqueue(int item) 
{
    if (count == MAXSIZE) {
        printf("Queue is full\n");
    }
    else{
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAXSIZE;
    }
    a[rear] = item;
    count++;
	}
}

int dequeue()
{
	int item;
    if (count == 0)
	 {
        printf("Queue is empty\n");
        return -1;
    }
    else
	{
      int item = a[front];
      front = (front + 1) % MAXSIZE;
      count--;
      return item;
    }
}

void display() 
{
    printf("The items in the queue are: ");
    int i, j = count;
   for(i=front; j!=0; j--)
   {
   	printf("%d",a[i]);
   	i=(i+1)%MAXSIZE;
   }
}

