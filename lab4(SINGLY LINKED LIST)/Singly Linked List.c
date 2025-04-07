#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *next;
};

typedef struct Node node;
node *start = NULL; // Corrected: NULL instead of Null

node* getnode()
{
	node *newnode;
    newnode=(node*)malloc(sizeof(node));
    if (newnode == NULL) 
	{                                              
        printf("Memory allocation failed!\n");   // Check for allocation failure
        exit(1);
    }

        printf("Enter the data:");
        scanf("%d", &newnode->info);
        newnode->next = NULL;
        return newnode;
    
}

void createlist(int n)
{
    int i;
    node *newnode;
    node *temp;
    for (i = 0; i < n; i++)
    {
        newnode = getnode();
        if (start == NULL)
            start = newnode;
        else
        {
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
}

void traverse()
{
    node *temp;
    temp = start;
    printf("Contents are:\n");
    if (start == NULL)
        printf("List is empty");
    else
    {
        while (temp != NULL)
        {
            printf("%d-->", temp->info);
            temp = temp->next;
        }
    }
         printf("\n"); // Add a newline at the end
}

void insert_first()
{
    node *newnode;
    newnode = getnode();
    if (start == NULL)
        start = newnode;
    else
    {
        newnode->next = start;
        start = newnode;
    }
}

void insert_after()
{
    node *newnode, *ptr, *preptr;
    int val;
    newnode = getnode();
    printf("Enter the value after which the data is to be inserted\n");
    scanf("%d", &val);
    ptr = start;
    preptr = start; // Initialize preptr
    while (ptr != NULL && preptr->info != val) // Check for NULL
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL && preptr->info != val)
	 {
        printf("Value not found\n");
        free(newnode); // Free allocated node
        return;
     }
        preptr->next = newnode;
        newnode->next = ptr;
        traverse();
}

void insert_before()
{
    node *newnode, *ptr, *preptr;
    int val;
    newnode = getnode();
    printf("Enter the value before which the data is to be inserted\n");
    scanf("%d", &val);
    ptr = start;
    preptr = start; // Initialize preptr
    if (start != NULL && start->info == val) 
	{ // Handle insert at beginning
        newnode->next = start;
        start = newnode;
        traverse();
        return;
    }
    while (ptr != NULL && ptr->info != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL) 
	{
        printf("Value not found\n");
        free(newnode); // Free allocated node
        return;
    }
    preptr->next = newnode;
    newnode->next = ptr;
    traverse();
}

void insert_last()
{
    node *newnode, *temp;
    newnode = getnode();
    if (start == NULL)
        start = newnode;
    else
    {
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
            temp->next = newnode;
    }
}

void delete_first()
{
    node *temp;
    if (start == NULL)
        printf("List is empty...");
    else
    {
        temp = start;
        start = temp->next;
        free(temp);
        printf("Node deleted...\n");
        traverse();
    }
}

void delete_last()
{
    node *temp, *prev;
    if (start == NULL)
        printf("List is empty...");
    else if (start->next == NULL) { // Handle single node case
        free(start);
        start = NULL;
        printf("Node deleted..\n");
        traverse();
        return;
    }
    else
    {
        temp = start;
        prev = start;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
            prev->next = NULL;
            free(temp);
            printf("Node deleted..\n");
            traverse();
    }
}

void delete_after()
{
    node *ptr, *preptr;
    int val;
    printf("Enter the value after which the data is to be deleted\n");
    scanf("%d", &val); 
    ptr = start;
    preptr = start;
    while (preptr != NULL && preptr->info != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (preptr == NULL || ptr == NULL || ptr->next == NULL) { // Check for NULL
        printf("Value not found or no node after\n");
        return;
    }
    preptr->next = ptr->next;
    free(ptr);
    traverse();
}

void deletenode()
{
    node *ptr, *preptr;
    int val;
    printf("Enter the value to be deleted\n");
    scanf("%d", &val);
    ptr = start;
    preptr = start;
    if (start != NULL && start->info == val) { // Handle delete first node
        start = start->next;
        free(ptr);
        traverse();
        return;
    }
    while (ptr != NULL && ptr->info != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL) 
	{
        printf("Value not found\n");
        return;
    }
    preptr->next = ptr->next;
    free(ptr);
    traverse();
}

int main()
{
    int ch, n;
    while (1) 
	{
        printf("\n Enter your choice:>\n");
        printf("\n1. Create a list");
        printf("\n2. Insert a node at beginning");
        printf("\n3. Insert a node at end");
        printf("\n4. Insert after a node");
        printf("\n5. Insert before a node");
        printf("\n6. Delete a node from first");
        printf("\n7. Delete a node from last");
        printf("\n8. Delete after a node");
        printf("\n9. Delete a node");
        printf("\n10. Traverse the list");
        printf("\n11. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (start == NULL)
            {
                printf("\n Enter the number of nodes to create");
                scanf("%d", &n);
                createlist(n);
                traverse();
            }
            else
                printf("List is already created...");
            break;
        case 2:
            insert_first();
            break;
        case 3:
            insert_last();
            break;
        case 4:
            insert_after();
            break;
        case 5:
            insert_before();
            break;
        case 6:
            delete_first();
            break;
        case 7:
            delete_last();
            break;
        case 8:
            delete_after();
            break;
        case 9:
            deletenode();
            break;
        case 10:
            traverse();
            break;
        case 11:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    getch();
    return 0;
}
