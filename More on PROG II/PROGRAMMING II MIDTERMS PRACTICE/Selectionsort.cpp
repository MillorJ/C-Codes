#include <stdio.h>

void selectionSort(int arr[], int size);

int main()
{
	int i;
	int arr[] = {2,5,7,34,23,42,21};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	selectionSort(arr, size);
	for (i = 0; i < size; i++)
	{
		printf(" %d", arr[i]);
	}
	
	
}
void selectionSort(int arr[], int size) 
{
  int i,j;
  for (i = 0; i < size - 1; i++)
  {
  	int iMin = i;
  	for (j = i + 1; j < size; j++)
  	{
  		if (arr[j] < arr[iMin])
  		{
  			iMin = j;
		  }
	  }
	  int temp = arr[i];
	  arr[i] = arr[iMin];
	  arr[iMin] = temp;
}
}
