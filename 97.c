#include <stdio.h>
#include <stdlib.h>

// Structure for meeting
struct Meeting {
    int start;
    int end;
};

// Compare meetings by start time
int compareStart(const void *a, const void *b) {
    struct Meeting *m1 = (struct Meeting *)a;
    struct Meeting *m2 = (struct Meeting *)b;

    return m1->start - m2->start;
}

// Min-heap functions
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index])
            break;

        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

void push(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

int pop(int heap[], int *size) {
    int min = heap[0];

    heap[0] = heap[*size - 1];
    (*size)--;

    if (*size > 0)
        heapifyDown(heap, *size, 0);

    return min;
}

int minMeetingRooms(struct Meeting meetings[], int n) {
    // Step 1: Sort meetings by start time
    qsort(meetings, n, sizeof(struct Meeting), compareStart);

    int *heap = (int *)malloc(n * sizeof(int));
    int heapSize = 0;
    int maxRooms = 0;

    // Step 2: Process meetings
    for (int i = 0; i < n; i++) {

        // If earliest meeting has ended,
        // remove it from the heap
        if (heapSize > 0 && heap[0] <= meetings[i].start) {
            pop(heap, &heapSize);
        }

        // Add current meeting's end time
        push(heap, &heapSize, meetings[i].end);

        // Maximum heap size = rooms required
        if (heapSize > maxRooms)
            maxRooms = heapSize;
    }

    free(heap);

    return maxRooms;
}

int main() {
    struct Meeting meetings[] = {
        {0, 30},
        {5, 10},
        {15, 20}
    };

    int n = sizeof(meetings) / sizeof(meetings[0]);

    printf("Minimum rooms required = %d\n",
           minMeetingRooms(meetings, n));

    return 0;
}