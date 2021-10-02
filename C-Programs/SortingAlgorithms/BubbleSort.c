// C program for implementation of Bubble sort
#include<stdio.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
int i, j;
for (i = 0; i < n-1; i++)	

	// Last i elements are already in place
	for (j = 0; j < n-i-1; j++)
		if (arr[j] > arr[j+1])
			swap(&arr[j], &arr[j+1]);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
	int arr[] = {-32, 59, 10, 121, -2};
	printf("Before Sorted Array:");
	int n = sizeof(arr)/sizeof(arr[0]);
	int i;
	for(i=0;i<n;i++){
	    printf("%d ", arr[i]);
	}
	bubbleSort(arr, n);
	printf("\nSorted array: \n");
	printArray(arr, n);
	return 0;
}