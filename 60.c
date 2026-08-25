#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Check Min-Heap property
    for (int i = 0; i < n / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Parent must be <= left child
        if (left < n && a[i] > a[left]) {
            printf("NO\n");
            return 0;
        }

        // Parent must be <= right child
        if (right < n && a[i] > a[right]) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");

    return 0;
}