#include <stdio.h>

void insertElement(int arr[], int n, int x, int pos)
{
    for (int i = n - 1; i >= pos; i--)
        arr[i + 1] = arr[i];

    arr[pos] = x;
}

int main()
{
    int arr[15] = { 2, 4, 1, 8, 5 };
    int n = 5;

    printf("Before insertion : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    int x = 10, pos = 2;
  
      // Function call
    insertElement(arr, n, x, pos);
    n++;

    printf("After insertion : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}