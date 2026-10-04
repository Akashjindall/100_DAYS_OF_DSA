#include <stdio.h>

void merge(int arr[], int temp[], int count[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            // Elements from right half already placed
            // are smaller than arr[i]
            count[i] += j - (mid + 1);

            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        count[i] += j - (mid + 1);
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int temp[], int count[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, temp, count, left, mid);
    mergeSort(arr, temp, count, mid + 1, right);

    merge(arr, temp, count, left, mid, right);
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n], count[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        count[i] = 0;
    }

    mergeSort(arr, temp, count, 0, n - 1);

    printf("Count of smaller elements on right:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}