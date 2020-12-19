#include <stdio.h>

void mergeSort(int *const, int);
void mergeSortHelper(int *const, int, int);
void merge(int *const, int, int, int);

void printArray(const int *const, int);

int main()
{

	int arr[] = {1, 40, 1, 34, 2, 90, 43, 67, 22, 7};

	mergeSort((int *)&arr, 9);

	printArray((int *)&arr, 10);

	return 0;
}

// merge sort // O(nlogn)
void mergeSort(int *const arr, int length)
{
	mergeSortHelper(arr, 0, length);
}

void mergeSortHelper(int *const arr, int start, int end)
{
	if (end <= start)
	{ // base case
		return;
	}
	int mid = (start + end) / 2;
	mergeSortHelper(arr, start, mid);	// sort left half
	mergeSortHelper(arr, mid + 1, end); // sort right half
	merge(arr, start, mid, end);
}

void merge(int *const arr, int start, int mid, int end)
{
	int tempArrLength = end - start + 1;
	int temp[tempArrLength];

	int leftSlot = start;	 // index counter of left array
	int rightSlot = mid + 1; // index counter of right array
	int k = 0;

	while (leftSlot <= mid && rightSlot <= end)
	{
		if (arr[leftSlot] < arr[rightSlot])
		{
			temp[k] = arr[leftSlot];
			leftSlot++;
		}
		else
		{
			temp[k] = arr[rightSlot];
			rightSlot++;
		}
		k++;
	}

	/*
		When it get's to here, that means the above loop has completed
		So both the right and left side of the sub-array can be considered sorted
	*/

	if (leftSlot <= mid)
	{ // consider the right side being sorted. Left must be sorted already
		while (leftSlot <= mid)
		{
			temp[k] = arr[leftSlot];
			leftSlot++;
			k++;
		}
	}
	else if (rightSlot <= end)
	{
		while (rightSlot <= end)
		{
			temp[k] = arr[rightSlot];
			rightSlot++;
			k++;
		}
	}

	// copy over the temp array into the appropriate slots of the array
	int i;
	for (i = 0; i < tempArrLength; i++)
	{
		arr[start + i] = temp[i];
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

