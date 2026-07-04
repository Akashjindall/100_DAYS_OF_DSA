#include <stdio.h>

long long power(long long a, int b) {
    if (b == 0)
        return 1;
    return a * power(a, b - 1);
}

int main() {
    long long a;
    int b;

    scanf("%lld %d", &a, &b);

    printf("%lld", power(a, b));

    return 0;
}