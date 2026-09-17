#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Find the minimum element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);

        if (i < n - 1)
            printf(" ");
    }

    return 0;
}