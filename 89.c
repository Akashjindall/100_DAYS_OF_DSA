#include <stdio.h>

int canAllocate(int pages[], int n, int m, long long maxPages) {
    int students = 1;
    long long currentPages = 0;

    for (int i = 0; i < n; i++) {

        // If adding this book exceeds the limit,
        // allocate books to a new student.
        if (currentPages + pages[i] > maxPages) {
            students++;
            currentPages = pages[i];

            if (students > m)
                return 0;
        } 
        else {
            currentPages += pages[i];
        }
    }

    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int pages[n];

    long long low = 0;
    long long high = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);

        // Minimum possible answer
        if (pages[i] > low)
            low = pages[i];

        // Maximum possible answer
        high += pages[i];
    }

    // More students than books is impossible
    if (m > n) {
        printf("-1\n");
        return 0;
    }

    // Binary Search on Answer
    while (low < high) {

        long long mid = low + (high - low) / 2;

        if (canAllocate(pages, n, m, mid)) {
            // This maximum is possible.
            // Try to find a smaller value.
            high = mid;
        } 
        else {
            // Need a larger maximum.
            low = mid + 1;
        }
    }

    printf("%lld\n", low);

    return 0;
}