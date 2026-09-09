#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxLen = 0;

    // Store prefix sums and their first occurrence
    int prefixSum[n + 1];
    int firstIndex[n + 1];

    int sum = 0;
    int count = 0;

    // Prefix sum 0 occurs before the array starts
    prefixSum[count] = 0;
    firstIndex[count] = -1;
    count++;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        int found = -1;

        // Check if prefix sum already exists
        for (int j = 0; j < count; j++) {
            if (prefixSum[j] == sum) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            int length = i - firstIndex[found];

            if (length > maxLen) {
                maxLen = length;
            }
        } else {
            prefixSum[count] = sum;
            firstIndex[count] = i;
            count++;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}