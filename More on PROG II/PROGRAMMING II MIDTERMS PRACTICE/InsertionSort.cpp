#include <stdio.h>

void insertionSort(int arr[], int size);

int main()
{
	int i;
	int arr[] = {2,5,7,34,23,42,21};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	insertionSort(arr, size);
	for (i = 0; i < size; i++)
	{
		printf(" %d", arr[i]);
	}
	
	
}
void insertionSort(int arr[], int size) {
    int i,j,temp;
    for (i = 1; i < size; i++)
    {
    	temp = arr[i];
    	j = i - 1;
    	while (j >= 0 && arr[j] > temp)
    	{
    		arr[j+1] = arr[j];
    		j--;
		}
		arr[j+1] = temp;
	}
}
