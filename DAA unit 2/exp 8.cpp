#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair findMinMax(int arr[], int low, int high) {
    struct Pair minmax, left, right;
    int mid;

    if (low == high) {
        minmax.min = arr[low];
        minmax.max = arr[low];
        return minmax;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.min = arr[high];
            minmax.max = arr[low];
        } else {
            minmax.min = arr[low];
            minmax.max = arr[high];
        }
        return minmax;
    }

    mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    if (left.min < right.min)
        minmax.min = left.min;
    else
        minmax.min = right.min;

    if (left.max > right.max)
        minmax.max = left.max;
    else
        minmax.max = right.max;

    return minmax;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int arr_size = 6;
    struct Pair minmax = findMinMax(arr, 0, arr_size - 1);

    printf("Minimum element is %d\n", minmax.min);
    printf("Maximum element is %d\n", minmax.max);

    return 0;
}

