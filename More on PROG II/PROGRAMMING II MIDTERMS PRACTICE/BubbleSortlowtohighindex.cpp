#include <stdio.h>

void BubbleSort(int arr[], int size);

int main()
{
	int i;
	int arr[] = {2,5,7,34,23,42,21};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	BubbleSort(arr, size);
	for (i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	
}

void BubbleSort(int arr[], int size)
{
	int i,j;
	for (i = size-1; i >= 0; i--)
	{
		for (j = size-1; j > size-i-1; j--)
		{
			if (arr[j] < arr[j-1])
			{
				int temp= arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
		}	
}
