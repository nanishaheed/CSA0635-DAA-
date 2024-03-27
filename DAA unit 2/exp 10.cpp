#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
} Item;

int compare(const void *a, const void *b) {
    double ratio1 = ((Item *)a)->value / (double)((Item *)a)->weight;
    double ratio2 = ((Item *)b)->value / (double)((Item *)b)->weight;
    return ratio2 > ratio1 ? 1 : -1;
}

double fractionalKnapsack(int capacity, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare);

    int currentWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        } else {
            int remainingWeight = capacity - currentWeight;
            finalValue += items[i].value * ((double)remainingWeight / items[i].weight);
  

