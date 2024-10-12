//1. Implement linear search and binary search using recursion.
#include<stdio.h>
int Linear_Search(int arr[], int n, int key, int i);
int Binary_Search(int arr[], int n, int key, int left, int right);
int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter a key to search in array: ");
    scanf("%d", &key);
    int output = Linear_Search(arr, n, key, 0);
    if(output == -1){
        printf("(Linear Search Result) Key %d is not present in array.\n", key);
    }
    else{
        printf("(Linear Search Result) Key %d is present at array index: %d.\n", key,  output);
    }
    int output1 = Binary_Search(arr, n, key, 0, n-1);
    if(output1 == -1){
        printf("(Binary Search Result) Key %d is not present in array.\n", key);
    }
    else{
        printf("(Binary Search Result) Key %d is present at array index: %d.\n", key,  output);
    }
    return 0;
}
int Linear_Search(int arr[], int n, int key, int i){
    if(i>n-1){
        return -1;
    }
    else if(arr[i] == key){
        return i;
    }
    return Linear_Search(arr, n, key, ++i);
}
int Binary_Search(int arr[], int n, int key, int left, int right){
    int mid = left + (right-left) / 2;
    if(mid > n-1){
        return -1;
    }
    else if(arr[mid] == key){
        return mid;
    }
    else if(arr[mid]>key){
        return Binary_Search(arr, n, key, left, mid-1);
    }
    else if(arr[mid]<key){
        return Binary_Search(arr, n, key, mid+1, right);
    }
}
