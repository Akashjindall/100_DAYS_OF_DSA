#include <stdio.h>

#define MAX 100

int main() {
    int stack[MAX];
    int top = -1;
    int n, m, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &stack[++top]);
    }

    scanf("%d", &m);

    while (m > 0 && top >= 0) {
        top--;
        m--;
    }

    while (top >= 0) {
        printf("%d", stack[top]);
        if (top > 0)
            printf(" ");
        top--;
    }

    return 0;
}