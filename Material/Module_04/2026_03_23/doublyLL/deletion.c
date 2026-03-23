#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node *previous;
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create (int A[], int n) {
    struct Node *t, *last;

    head = (struct Node *)malloc(sizeof(struct Node));
    head -> data = A[0];
    head -> previous = head -> next = NULL;
    last = head;

    for (int i=1; i<n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> next = last -> next;
        t -> previous = last;
        last -> next = t;
        last = t;
    }
}

void displays (struct Node *p) {
    while (p) {
        printf ("%d ", p->data);
        p = p -> next;
    }
    printf ("\n");
}

int listLength (struct Node *p) {
    int length = 0;

    while (p) {
        length++;
        p = p -> next;
    }
    return length;
}

void insertion (struct Node *p, int index, int x) {
    struct Node *t;

    if (index < 0 || index > listLength (p))
        return;

    if (index == 0) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = x;
        t -> previous = NULL;
        t -> next = head;
        head -> previous = t;
        head = t;
    } else {
        for (int i=0; i<index-1; i++) {
            p = p -> next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = x;
        t -> previous = p;
        t -> next = p -> next;

        if (p -> next)
            p -> next -> previous = t;
        
        p -> next = t;
    }
}

int delete (struct Node *p, int index) {
    struct Node *q;
    int x = -1;

    if (index < 1 || index > listLength(p))
        return -1;

    if (index == 1) {
        head = head -> next;
        
        if (head)
            head -> previous = NULL;

        x = p -> data;
        free (p);
    } else {
        
        for (int i = 0; i < index - 1; i++) {
            p = p -> next;
        }

        p -> previous -> next = p -> next;

        if (p -> next)
            p -> next -> previous = p -> previous;

        x = p -> data;
        free (p);

    }
    return x;
}

int main () {

    int A[] = {10, 20, 30, 40, 50};
    create (A, 5);
    displays(head);
    printf ("\n");
    insertion (head, 0, 25);
    displays (head);
    printf("\n");
    delete (head, 3);
    displays (head);
    return 0;
}