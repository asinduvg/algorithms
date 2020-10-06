#include <stdio.h>
#define LEN(arr) (sizeof(arr) / sizeof(arr[0]))

// void bubbleSort(int[], int);
void bubbleSort(int *a, int);

int main() {

    int arr[] = {12, 34, 1, 67, 90, 3};
    int length = LEN(arr);

    // printf("1. Address of the passing array: %x\n", arr);

    bubbleSort(arr, length);

    int i;
    
    for(i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

// void bubbleSort(int a[], int length) {
//     int i, j;
//     // printf("2. Address of the taking array: %x\n", a);
//     for (i = 0; i < length; i++) {
//         for (j = 0; j < length - i - 1; j++) {
//             if (a[j] > a[j + 1]) {
//                 int temp = a[j];
//                 a[j] = a[j + 1];
//                 a[j + 1] = temp;
//             }
//         }
//     } 
// }

void bubbleSort(int *a, int length) {
    int i, j;
    // printf("3. Address of the taking array: %x\n", a);
    for (i = 0; i < length; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    } 
}


/*
    1) We should pass length of the array since it has no track of it's length as we are passing a pointer to the function
    2) In both implementations functions get the pointer of the array, which is represented the address of the first element of the array by the word 'array'
*/