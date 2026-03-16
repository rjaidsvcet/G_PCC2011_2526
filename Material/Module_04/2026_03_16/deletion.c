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

void insertLast (int x) {
    struct Node *t, *p;

    t = (struct Node*)malloc(sizeof(struct Node));
    if (t == NULL) {
        printf("Memory allocation failed");
        return;
    }

    t -> data = x;
    t -> next = NULL;

    if (head == NULL) {
        head = t;
        return;
    }

    p = head;
    while (p -> next != NULL) {
        p = p -> next;
    }

    p -> next = t;
}

int deletion (struct Node *p, int position) {
    struct  Node *tempPointer;
    int x = -1;

    if (position < 1 || position > count (p))
        return -1;

    if (position == 1) {
        tempPointer = head;
        x = head -> data;
        head = head -> next;
        free (tempPointer);
        return x;
    } else {
        for (int i=0; i<position-1; i++) {
            tempPointer = p;
            p = p -> next;
        }
        tempPointer -> next = p -> next;
        x = p -> data;
        free (p);
        return x;
    }
}


int main () {
    insert (head, 0, 22);
    insert (head, 0, 21);
    insertLast (33);
    insertLast (44);
    insert (head, 2, 55);
    insertLast (66);
    displays (head);
    printf("\n");
    deletion (head, 6);
    displays (head);
    return 0;
}