#include<stdio.h>
#include<stdlib.h>

#define LEN(arr) (sizeof(arr) / sizeof(arr[0]))

void insertionSort(int[], int);

int main() {

    int arr[] = {30, 10, 50, 20, 60, 40};

    int length = LEN(arr);

    insertionSort(arr, length);
    int i;
    for(i = 0; i < length - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void insertionSort(int arr[], int length) {
    int i, j;

    for(i = 0; i < length - 1; i++) {
        // a[i] = arr[i];
        for(j = i; j > 0; j--) {
            if(arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

/*
    1) Best if we do not have any extraspace to allocate for a new array
    2) Simple inmplementation
    3) Best when we have continuous inflow of numbers and we want to keep the list sorted
    4) Average case is bad

    Time complexity -> O(n^2)
    Space complexity -> O(1)

*/