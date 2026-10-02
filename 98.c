#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

// Compare function for qsort()
int compare(const void *a, const void *b) {
    Interval *x = (Interval *)a;
    Interval *y = (Interval *)b;

    return x->start - y->start;
}

void mergeIntervals(Interval arr[], int n) {
    // Step 1: Sort intervals by start time
    qsort(arr, n, sizeof(Interval), compare);

    int index = 0;

    // Step 2: Compare with previous interval
    for (int i = 1; i < n; i++) {

        // Overlapping
        if (arr[index].end >= arr[i].start) {
            if (arr[i].end > arr[index].end)
                arr[index].end = arr[i].end;
        }
        // Not overlapping
        else {
            index++;
            arr[index] = arr[i];
        }
    }

    // Step 3: Print merged intervals
    for (int i = 0; i <= index; i++) {
        printf("[%d, %d] ", arr[i].start, arr[i].end);
    }
}

int main() {
    Interval arr[] = {
        {1, 3},
        {2, 6},
        {8, 10},
        {9, 11}
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    mergeIntervals(arr, n);

    return 0;
}