#include <stdio.h>

int main() {
    int n, pos;
    
    scanf("%d", &n);
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &pos);
    
    // Shift elements to the left
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    // Print updated array
    for (int i = 0; i < n - 1; i++) {
        printf("%d", arr[i]);
        if (i < n - 2)
            printf(" ");
    }
    
    return 0;
}