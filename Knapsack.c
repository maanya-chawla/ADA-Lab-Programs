#include <stdio.h>

struct Item {
    int weight, value;
    float ratio;
};

void sort(struct Item arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j].ratio < arr[j+1].ratio) {
                struct Item temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

int main() {
    int n, capacity;
    struct Item arr[100];

    printf("Enter number of items: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nItem %d\n", i+1);
        printf("Value: ");
        scanf("%d", &arr[i].value);
        printf("Weight: ");
        scanf("%d", &arr[i].weight);
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }

    printf("\nEnter knapsack capacity: ");
    scanf("%d", &capacity);

    sort(arr, n);

    float totalValue = 0.0;

    printf("\nItems taken:\n");

    for (int i = 0; i < n; i++) {
        if (capacity == 0) break;

        if (arr[i].weight <= capacity) {
            
            capacity -= arr[i].weight;
            totalValue += arr[i].value;
            printf("Item %d -> FULL (Value = %d)\n", i+1, arr[i].value);
        } else {
            
            float fraction = (float)capacity / arr[i].weight;
            totalValue += arr[i].value * fraction;
            printf("Item %d -> %.2f fraction\n", i+1, fraction);
            capacity = 0;
        }
    }

    printf("\nMaximum Value = %.2f\n", totalValue);

    return 0;
}


