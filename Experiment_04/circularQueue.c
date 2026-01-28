#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int x)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;

        queue[rear] = x;
        printf("Inserted %d\n", x);
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleted %d\n", queue[front]);

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        i = front;
        printf("Queue elements: ");
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\n", queue[rear]);
    }
}

int main()
{
    int choice, value;

    do
    {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting program\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}