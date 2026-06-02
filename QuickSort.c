#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int arr[], int low, int high) {
    int pivot = arr[low]; 
    int i = low;
    int j = high;

    while (i < j) {
        
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
   
    swap(&arr[low], &arr[j]);
    return j;
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 1;

    int *arr = (int*)malloc(n * sizeof(int));
    
    
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorting complete.\n");
    printf("Time taken: %f seconds\n", cpu_time_used);

}