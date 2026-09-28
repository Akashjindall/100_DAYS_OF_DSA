#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    // 1. Find maximum element
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // 2. Create frequency array
    int *freq = (int *)calloc(max + 1, sizeof(int));

    // Store frequency of each element
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // 3. Compute prefix sums
    for (int i = 1; i <= max; i++) {
        freq[i] = freq[i] + freq[i - 1];
    }

    // 4. Build output array
    int *output = (int *)malloc(n * sizeof(int));

    for (int i = n - 1; i >= 0; i--) {
        output[freq[arr[i]] - 1] = arr[i];
        freq[arr[i]]--;
    }

    // 5. Copy output back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(freq);
    free(output);
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}