#include<stdio.h>

int f (int arr[], int i, int n) {
    if (n <= 0) {
        return 0;
    }
    else if (arr[i] % 2 == 0) {
        return arr[i] + f(arr, i+1, n-1);
    }
    else {
        return arr[i] - f(arr, i+1, n-1);
    }
}

int main () {
    int arr[] = {12, 7, 13, 4, 11, 6};
    int n = 6;
    int outcome;

    outcome = f (arr, 0, n);
    printf("%d\n", outcome);

    return 0;
}