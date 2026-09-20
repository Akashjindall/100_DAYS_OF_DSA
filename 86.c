#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long low = 0, high = n;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (mid * mid == n) {
            ans = mid;
            break;
        }
        else if (mid * mid < n) {
            ans = mid;       // mid can be the answer
            low = mid + 1;   // search for a larger value
        }
        else {
            high = mid - 1;  // search in left half
        }
    }

    printf("%lld\n", ans);

    return 0;
}