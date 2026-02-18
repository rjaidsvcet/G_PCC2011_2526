#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Insert at Front
void insertFront(int x) {
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    
    if (t == NULL) {
        printf("Overflow\n");
        return;
    }
    
    t->data = x;
    t->prev = NULL;
    t->next = front;
    
    if (front == NULL) {
        front = rear = t;
    } else {
        front->prev = t;
        front = t;
    }
}

// Insert at Rear
void insertRear(int x) {
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    
    if (t == NULL) {
        printf("Overflow\n");
        return;
    }
    
    t->data = x;
    t->next = NULL;
    t->prev = rear;
    
    if (rear == NULL) {
        front = rear = t;
    } else {
        rear->next = t;
        rear = t;
    }
}

// Delete from Front
void deleteFront() {
    if (front == NULL) {
        printf("Underflow\n");
        return;
    }
    
    struct Node *t = front;
    printf("Deleted: %d\n", t->data);
    
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }
    
    free(t);
}

// Delete from Rear
void deleteRear() {
    if (rear == NULL) {
        printf("Underflow\n");
        return;
    }
    
    struct Node *t = rear;
    printf("Deleted: %d\n", t->data);
    
    if (front == rear) {
        front = rear = NULL;
    } else {
        rear = rear->prev;
        rear->next = NULL;
    }
    
    free(t);
}

// Display Deque
void display() {
    struct Node *p = front;
    
    if (p == NULL) {
        printf("Deque is Empty\n");
        return;
    }
    
    printf("Deque Elements: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Main Function
int main() {
    int choice, value;
    
    while (1) {
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;
                
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;
                
            case 3:
                deleteFront();
                break;
                
            case 4:
                deleteRear();
                break;
                
            case 5:
                display();
                break;
                
            case 6:
                exit(0);
                
            default:
                printf("Invalid Choice\n");
        }
    }
    
    return 0;
}