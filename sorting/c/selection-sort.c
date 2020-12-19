#include <stdio.h>

void selectionSort(int *const, int);

void printArray(const int *const, int);

int main()
{

	int arr[] = {1, 40, 1, 34, 2, 90, 43, 67, 22, 7};

    selectionSort((int *)&arr, 10);

	printArray((int *)&arr, 10);

	return 0;
}

// selection sort // O(n^2)
void selectionSort(int *const arr, int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		int j;
		int min = i;
		for (j = i + 1; j < length; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

void printArray(const int *const arr, int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
}
