#include <stdio.h>

void minMaxSequence(int arr[], int n) {
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }
    printf("Minimum value in sequence: %d\n", min);
    printf("Maximum value in sequence: %d\n", max);
}

int main() {
    int arr[] = {1, 3, 5, 2, 7, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    minMaxSequence(arr, n);
    return 0;
}

