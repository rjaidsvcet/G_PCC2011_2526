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
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
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


void reversingWithArray (struct Node *p) {
    int *holderArray, i=0;
    struct Node *q = p;

    holderArray = (int *)malloc(sizeof (int) * count(p));

    while (q != NULL) {
        holderArray[i] = q -> data;
        q = q -> next;
        i++;
    }
    
    q = p;
    i--;

    while (q != NULL) {
        q -> data = holderArray[i];
        q = q -> next;
        i--;
    }
}

void reversingWithLinks (struct Node *p) {
    struct Node *q=NULL, *r=NULL;

    while (p != NULL) {
        r = q;
        q = p;
        p = p -> next;
        q -> next = r;
    }

    head = q;
}

void display (struct Node *p) {
    while (p != NULL) {
        printf("%d ", p -> data);
        p = p -> next;
    }
}

int main () {
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    display (head);
    printf("\n");
    // reversingWithArray (head);
    reversingWithLinks (head);
    display (head);
    return 0;
}