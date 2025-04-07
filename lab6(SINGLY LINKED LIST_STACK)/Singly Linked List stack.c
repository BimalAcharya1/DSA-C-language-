#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node 
{
    int info;
    struct Node *next; 
};

typedef struct Node node;
node *top = NULL;

void push(int num);
void pop();
void display();

int main() 
{
    int ch, num;

    while (1) 
	{
        printf("\nEnter your choice:\n");
        printf("\n1. Push operation");
        printf("\n2. Pop operation");
        printf("\n3. Display");
        printf("\n4. Exit\n");

        scanf("%d", &ch);

        switch (ch) 
		{
            case 1:
                printf("Enter data to push into the stack...");
                scanf("%d", &num);
                push(num);
                break;
            case 2:
                pop();
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

void push(int num)
 {
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
	 {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->info = num;
    newnode->next = top; 
    top = newnode;
    printf("%d is pushed into the stack\n", num);
}

void pop()
 {
    node *temp;
    if (top == NULL)
	{
        printf("Stack is empty...\n");
    } else {
        temp = top;
        top = top->next;
        printf("Popped element is: %d\n", temp->info);
        free(temp);
    }
}

void display() 
{
    node *temp;
    if (top == NULL) 
	{
        printf("Stack is empty\n");
    } else {
        temp = top;
        printf("Contents are:\n");
        while (temp != NULL)
		 {
            printf("%d->", temp->info);
            temp = temp->next;
        }
        printf("\n"); 
    }
}
