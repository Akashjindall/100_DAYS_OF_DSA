#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n) {
    // Create n buckets
    float buckets[n][n];
    int count[n];

    // Initialize bucket counts
    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * n);
        buckets[index][count[index]++] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < count[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;

            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }

            buckets[i][k + 1] = key;
        }
    }

    // Concatenate all buckets
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];

    printf("Enter %d real numbers in [0,1):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}