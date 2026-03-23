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

int main () {

    int A[] = {10, 20, 30, 40, 50};
    create (A, 5);
    displays(head);
    printf("\nLength is : %d\n", listLength(head));
    return 0;
}