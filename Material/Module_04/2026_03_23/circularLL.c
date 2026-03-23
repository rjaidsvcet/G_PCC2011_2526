#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create (int A[], int n) {
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof (struct Node));
    head -> data = A[0];
    head -> next = head;
    last = head;

    for (int i=1; i<n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> next = last -> next;
        last -> next = t;
        last = t;
    }
}

void displays (struct Node *h) {
    do {
        printf ("%d ", h -> data);
        h = h -> next;
    } while (h != head);
    printf ("\n");
}

int main () {
    int A[] = {2, 3, 4, 5, 6};
    create (A, 6);
    displays (head);
    return 0;
}