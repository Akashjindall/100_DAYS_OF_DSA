#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Check if we can place k cows with at least 'dist'
// distance between any two cows
int canPlace(int stalls[], int n, int k, int dist) {
    int cows = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPosition >= dist) {
            cows++;
            lastPosition = stalls[i];

            if (cows >= k)
                return 1;
        }
    }

    return 0;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    int stalls[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Sort stall positions
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    // Binary Search on Answer
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(stalls, n, k, mid)) {
            // mid is possible, try for a larger distance
            ans = mid;
            low = mid + 1;
        } else {
            // mid is not possible, reduce distance
            high = mid - 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}