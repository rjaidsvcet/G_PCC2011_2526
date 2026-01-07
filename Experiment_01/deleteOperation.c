#include <stdio.h>

void del(int arr[], int *n, int key) {
  
  	// Find the element
  	int i = 0;
  	while (arr[i] != key) i++;
  	
    // Shifting the right side elements one
  	// position towards left
    for (int j = i; j < *n - 1; j++) {
        arr[j] = arr[j + 1];
    }
  
  	// Decrease the size
    (*n)--; 
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

  	// Delete the key from array
    del(arr, &n, key);
  
  	for (int i = 0; i < n; i++)
      	printf("%d ", arr[i]);

    return 0;
}