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
    head = (struct Node *)malloc(sizeof (struct Node));
    head -> data = A[0];
    head -> next = NULL;
    last = head;

    for (i=1; i<n; i++) {
        t = (struct Node *)malloc(sizeof (struct Node));
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void displays (struct Node *p) {
    while (p != NULL) {
        printf ("%d -> ", p -> data);
        p = p ->next;
    }
}

int count (struct Node *p) {
    int length = 0;
    while (p) {
        length++;
        p = p -> next;
    }
    return length;
}

void insert (struct Node *p, int index, int x) {
    struct Node *newNode;
    int i = 0;

    if (index < 0 || index > count (p)) {
        return;
    }

    newNode = (struct Node *)malloc(sizeof (struct Node));
    newNode -> data = x;

    if (index == 0) {
        newNode -> next = head;
        head = newNode;
    }
    else {
        for (i=0; i<index-1; i++) {
            p = p -> next;
        }
        newNode -> next = p -> next;
        p -> next = newNode;
    }
}

int main () {
    // int A[] = {3, 4, 5, 6};
    // create (A, 4);
    insert (head, 0, 22);
    insert (head, 0, 21);
    displays (head);
    // printf("The count is %d ", count (   head));
    return 0;
}