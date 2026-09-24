#include <stdio.h>

int canPaint(int boards[], int n, int k, long long maxTime) {
    int painters = 1;
    long long currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime)
            return 0;

        if (currentTime + boards[i] <= maxTime) {
            currentTime += boards[i];
        } else {
            painters++;
            currentTime = boards[i];

            if (painters > k)
                return 0;
        }
    }

    return 1;
}

long long minimumTime(int boards[], int n, int k) {
    long long low = 0, high = 0;

    // Minimum possible = largest board
    // Maximum possible = sum of all boards
    for (int i = 0; i < n; i++) {
        if (boards[i] > low)
            low = boards[i];

        high += boards[i];
    }

    long long answer = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (canPaint(boards, n, k, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    int boards[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%lld\n", minimumTime(boards, n, k));

    return 0;
}