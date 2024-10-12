#include <stdio.h>
#include <stdbool.h>
#define swap(a, b) { int temp = a; a = b; b = temp; }
int passes, comparisons;
void selection_sort(int arr[], int n);
void bubble_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void display(int arr[], int n);
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);  
    int arr[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    selection_sort(arr, n);
    printf("Sorted array after selection sort: \n");
    display(arr, n);
    printf("Number of passes after selection sort: %d\n", passes);
    printf("Number of comparisons after selection sort: %d\n\n", comparisons);
    printf("Enter the array elements again: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, n);
    printf("Sorted array after bubble sort: \n");
    display(arr, n);
    printf("Number of passes after bubble sort: %d\n", passes);
    printf("Number of comparisons after bubble sort: %d\n\n", comparisons);
    printf("Enter the array elements again: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, n);
    printf("Sorted array after insertion sort: \n");
    display(arr, n);
    printf("Number of passes after insertion sort: %d\n", passes);
    printf("Number of comparisons after insertion sort: %d\n", comparisons);
    return 0;
}
void selection_sort(int arr[], int n) {
    passes = 0;
    comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        passes++;
        int minIndex = i;  
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
void bubble_sort(int arr[], int n) {
    passes = 0;
    comparisons = 0;
    bool flag;
    for (int i = 0; i < n - 1; i++) {
        passes++;
        flag = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (!flag) {
            break;  
        }
    }
}
void insertion_sort(int arr[], int n) {
    passes = 0;
    int i, j, temp;
    passes = 0;
    comparisons = 0;
    for(i=1; i<n; i++){
        passes++;
        temp = arr[i];
        for(j=i-1;j>=0 && temp<arr[j]; j--){
            comparisons++;
            arr[j+1] = arr[j];
        }
        comparisons++;
        arr[j+1] = temp;
    }
}
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
