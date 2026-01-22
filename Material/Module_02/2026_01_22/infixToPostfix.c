#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Stack {
    int size;
    int top;
    char *S;
};

void create (struct Stack *st, int size) {
    st -> size = size;
    st -> top = -1;
    st -> S = (char *)malloc(st -> size*sizeof(char));
}

void push (struct Stack *st, char x) {
    if (st -> top == st -> size - 1)
        printf("Stack overflow condition");
    else {
        st -> top++;
        st -> S[st -> top] = x;
    }
}

int pop (struct Stack *st) {
    int x = -1;
    if (st -> top == -1)
        printf("Stack underflow condition");
    else {
        x = st -> S[st -> top--];
    }
    return x;
}

int isOperand (char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int precendence (char x) {
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

char *infixToPostfix (char *infix) {
    struct Stack st;
    int len = strlen (infix);
    create(&st, len);
    int i=0, j=0;
    char *postfix = (char *)malloc((len+1)*sizeof(char));

    while (infix[i] != '\0') {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else {
            while (st.top != -1 &&
                precendence(infix[i]) <= precendence(st.S[st.top])) {
                    postfix[j++] = pop(&st);
                }
                push (&st, infix[i++]);
        }
    }
    while (st.top != -1)
        postfix[j++] = pop (&st);
    postfix[j] = '\0';
    return postfix;
}

int main () {
    char *infix = "a*b+c";
    char *postfix = infixToPostfix(infix);
    printf("%s\n", postfix);
    return 0;
}
