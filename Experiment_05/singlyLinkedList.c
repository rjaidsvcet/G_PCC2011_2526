#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Function to create a new node */
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Insertion at beginning */
void insertAtBeginning(int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

/* Insertion at end */
void insertAtEnd(int data)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = head;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

/* Insertion at given position */
void insertAtPosition(int data, int pos)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    int i;

    if (pos == 1)
    {
        insertAtBeginning(data);
        return;
    }

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

/* Insert before given value */
void insertBefore(int data, int value)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head == NULL)
        return;

    if (head->data == value)
    {
        insertAtBeginning(data);
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found\n");
        return;
    }

    prev->next = newNode;
    newNode->next = temp;
}

/* Insert after given value */
void insertAfter(int data, int value)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Value not found\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

/* Display linked list */
void display()
{
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, data, pos, value;

    do
    {
        printf("\n1.Insert at Beginning");
        printf("\n2.Insert at End");
        printf("\n3.Insert at Position");
        printf("\n4.Insert Before Value");
        printf("\n5.Insert After Value");
        printf("\n6.Display");
        printf("\n7.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;

        case 3:
            printf("Enter data and position: ");
            scanf("%d %d", &data, &pos);
            insertAtPosition(data, pos);
            break;

        case 4:
            printf("Enter data and value before which to insert: ");
            scanf("%d %d", &data, &value);
            insertBefore(data, value);
            break;

        case 5:
            printf("Enter data and value after which to insert: ");
            scanf("%d %d", &data, &value);
            insertAfter(data, value);
            break;

        case 6:
            display();
            break;

        case 7:
            printf("Exiting program\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 7);

    return 0;
}