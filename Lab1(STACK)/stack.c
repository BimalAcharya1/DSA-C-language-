#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 10

void push(int item);
int pop();
void display();

int top = -1;
int a[MAXSIZE];

int main() {
    int n, opt;

    do {
        printf("\nEnter a choice");
        printf("\n1: Push Operation");
        printf("\n2: Pop Operation");
        printf("\n3: Display data elements");
        printf("\n4: Exit");
        printf("\nEnter your option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter a number to insert into the stack: ");
                scanf("%d", &n);
                push(n);
                break;
            case 2:
                n = pop();
                if (n != -1) {
                    printf("The deleted item is %d\n", n);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (opt != 4);

    return 0;
}

void push(int item) {
    if (top == MAXSIZE - 1) {
        printf("Stack is full\n");
    } else {
        top++;
        a[top] = item;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return a[top--];
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("The items in the stack are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}

