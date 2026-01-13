#include<stdio.h>
#include<stdlib.h>

struct Stack {
    int size;
    int top;
    int *S;
};

void create (struct Stack *st) {
    printf("Enter the size of the stack\n");
    scanf("%d", &st -> size);
    st -> top = -1;
    st -> S = (int *)malloc(st->size*sizeof(int));
}

void display (struct Stack st) {
    int i;
    for (i = st.top; i>=0; i--) {
        printf ("%d ", st.S[i]);
    }
}

void push (struct Stack *st, int x) {
    if (st -> top == st -> size-1)
        printf("Stack overflow");
    else {
        st -> top++;
        st -> S[st -> top] = x;
    }
}

int pop (struct Stack *st) {
    int x = -1;
    if (st -> top == -1)
        printf ("Stack underflow");
    else {
        x = st -> S[st -> top--];
    }
    return x;
}

int main () {
    struct Stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    display(st);
    printf("%d\n", pop(&st));
    printf("%d\n", pop(&st));
    printf("%d\n", pop(&st));
    printf("%d\n", pop(&st));
    display(st);
    return 0;
}