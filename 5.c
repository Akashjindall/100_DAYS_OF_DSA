#include <stdio.h>

int main() {
    int p, q;

    // Read size of first array
    scanf("%d", &p);
    int a[p];

    // Read first sorted array
    for (int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    // Read size of second array
    scanf("%d", &q);
    int b[q];

    // Read second sorted array
    for (int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int i = 0, j = 0;

    // Merge both arrays
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }

    // Print remaining elements of first array
    while (i < p) {
        printf("%d ", a[i]);
        i++;
    }

    // Print remaining elements of second array
    while (j < q) {
        printf("%d ", b[j]);
        j++;
    }

    return 0;
}