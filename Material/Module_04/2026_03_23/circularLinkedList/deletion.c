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

int listLength (struct Node *p) {
    int length = 0;
    do {
        length++;
        p = p -> next;
    } while (p != head);
    return length;
}

void insertion (struct Node *p, int index, int x) {
    struct Node *t;

    if (index < 0 || index > listLength (p))
        return;

    if (index == 0) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = x;

        if (head == NULL) {
            head = t;
            head -> next = head;
        } else {
            while (p -> next != head) {
                p = p -> next;
            }
            p -> next = t;
            t -> next = head;
            head = t;
        }
    } else {
        for (int i=0; i<index-1; i++) {
            p = p -> next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = x;
        t -> next = p -> next;
        p -> next = t;
    }
}

int deletion (struct Node *p, int index) {
    struct Node *q;
    int x;

    if (index < 0 || index > listLength (head))
        return -1;

    if (index == 1) {
        while (p->next != head) {
            p = p -> next;
        }
        x = p -> data;
        if (head == p) {
            free (head);
            head = NULL;
        } else {
            p -> next = head -> next;
            free (head);
            head = p -> next;
        }
    } else {
        for (int i=0; i<index-2; i++) {
            p = p -> next;
        }
        q = p -> next;
        p -> next = q -> next;
        x = q -> data;
        free(q);
    }
    return x;
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
    create (A, 5);
    displays (head);
    printf("\n");
    insertion (head, 3, 15);
    displays (head);
    deletion (head, 2);
    printf ("\n");
    displays (head);
    return 0;
}