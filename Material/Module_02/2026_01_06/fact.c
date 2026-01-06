#include<stdio.h>

int factorial (int n) {
    if (n == 0)
        return 1;
    return n * factorial (n -1);
}

int main () {
    int fact;
    fact = factorial (5);
    printf("%d\n", fact);
    return 0;
}