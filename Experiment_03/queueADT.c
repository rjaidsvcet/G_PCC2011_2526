#include <stdio.h>
#include <stdlib.h>

struct myQueue {
    // Array to store queue elements
    int *arr;

    // Maximum number of elements the queue can hold
    int capacity;

    // Current number of elements in the queue
    int size;
};

// Create queue
struct myQueue* createQueue(int capacity) {
    struct myQueue* q = (struct myQueue*)malloc(sizeof(struct myQueue));
    q->capacity = capacity;
    q->size = 0;
    q->arr = (int*)malloc(capacity * sizeof(int));
    return q;
}

int isEmpty(struct myQueue* q) {
    return q->size == 0;
}

int isFull(struct myQueue* q) {
    return q->size == q->capacity;
}

// Adds an element x at the rear of the queue
void enqueue(struct myQueue* q, int x) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->arr[q->size] = x;
    q->size++;
}

// Removes the front element of the queue
void dequeue(struct myQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    for (int i = 1; i < q->size; i++) {
        q->arr[i - 1] = q->arr[i];
    }
    q->size--;
}

// Returns the front element of the queue
int getFront(struct myQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[0];
}

// Returns the last element of the queue
int getRear(struct myQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[q->size - 1];
}

int main() {
    struct myQueue* q = createQueue(3);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("Front: %d\n", getFront(q)); 

    dequeue(q);
    printf("Front: %d\n", getFront(q));
    printf("Rear: %d\n", getRear(q));

    enqueue(q, 40);

    return 0;
}