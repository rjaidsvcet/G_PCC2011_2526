#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create (int A[], int n) {
    int i;
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));

    head -> data = A[0];
    head -> next = NULL;
    last = head;

    for (i=1; i<n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void traversal (struct Node *p) {
    while (p != NULL) {
        printf ("%d ", p -> data);
        p = p -> next;
    }
}

int main () {
    int A[] = {3, 5, 7, 10, 12};
    create (A, 5);
    traversal (head);
    return 0;
}