#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int top;
    int arr[MAX];
} Stack;

void push(Stack *s, int val) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = val;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    return s->arr[s->top--];
}

// Check if token is an operator
bool isOperator(char *token) {
    return strcmp(token, "+") == 0 || strcmp(token, "-") == 0 
        || strcmp(token, "*") == 0 || strcmp(token, "/") == 0
        || strcmp(token, "^") == 0;
}

// Floor division for negative numbers
int floorDiv(int a, int b) {
    if (a * b < 0 && a % b != 0)
        return (a / b) - 1;
    return a / b;
}

// Evaluate postfix expression
int evaluatePostfix(char **arr, int n) {
    Stack s = { -1 };

    for (int i = 0; i < n; i++) {
        
        // If it's an operand (number), push it onto the stack
        if (isdigit(arr[i][0]) || (strlen(arr[i]) > 1 && arr[i][0] == '-')) {
            push(&s, atoi(arr[i]));
        } 
        
        // Otherwise, it must be an operator
        else if (isOperator(arr[i])) {
            int val1 = pop(&s); 
            int val2 = pop(&s); 

            if (strcmp(arr[i], "+") == 0) push(&s, val2 + val1);
            else if (strcmp(arr[i], "-") == 0) push(&s, val2 - val1);
            else if (strcmp(arr[i], "*") == 0) push(&s, val2 * val1);
            else if (strcmp(arr[i], "/") == 0) push(&s, floorDiv(val2, val1));
            else if (strcmp(arr[i], "^") == 0) push(&s, (int)pow(val2, val1));
        }
    }
    return pop(&s);
}

int main() {
    char *arr[] = {"2", "3", "1", "*", "+", "9", "-"};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", evaluatePostfix(arr, n));
    return 0;
}