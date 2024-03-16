#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int binarySearch(int arr[], int n, int key){
    int start = 0, end = n - 1;
    while(start <= end){
        int mid = (start + end) / 2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    int index = binarySearch(arr, n, key);
    if(index == -1){
        printf("Element not found");
    }
    else{
        printf("Element found at index %d", index);
    }
    free(arr);
    return 0;
}