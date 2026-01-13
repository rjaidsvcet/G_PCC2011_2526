#include<stdio.h>
#include<stdlib.h>

struct Stack {
    int size;
    int top;
    char *S;
};

void create (struct Stack *st) {
    printf("Enter the size of the stack\n");
    scanf("%d", &st -> size);
    st -> top = -1;
    st -> S = (char *)malloc(st->size*sizeof(char));
}

void display (struct Stack st) {
    int i;
    for (i = st.top; i>=0; i--) {
        printf ("%d ", st.S[i]);
    }
}

void push (struct Stack *st, char x) {
    if (st -> top == st -> size-1)
        printf("Stack overflow");
    else {
        st -> top++;
        st -> S[st -> top] = x;
    }
}

char pop (struct Stack *st) {
    int x = -1;
    if (st -> top == -1)
        printf ("Stack underflow");
    else {
        x = st -> S[st -> top--];
    }
    return x;
}

int isBalanced (struct Stack st, char *exp) {
    int i;
    for (i=0; exp[i]!='\0'; i++) {
        if (exp[i] == '(')
            push(&st, exp[i]);
        else if (exp[i] == ')') {
            if (st.top == -1)
                return 0;
            pop (&st);
        }
    }
    if (st.top == -1)
        return 1;
    else
        return 0;
}

int main () {
    struct Stack st;
    create (&st);
    char *exp = "(((a+b)*(c-d))";
    printf("%d", isBalanced(st, exp));
    return 0;
}