#include <stdio.h>
#include <stdlib.h>

int* getdata(int arr[], int size);
void display(int arr[], int size);

int main()
{
	int i;
	int size;
	printf("Enter the size: ");
	scanf("%d", &size);
	
	int *arr = (int*) malloc(sizeof(int));
	int *array = getdata(arr,size);
 	display(arr, size);
	
	free(arr);
	return 0;	
}

int* getdata(int arr[], int size)
{


	int i;
		for (i = 0; i < size; i++){
			printf("Enter integer %d: ", i+1);
			scanf(" %d", &arr[i]);
		}
		
	
	return arr;
}

void display(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++){
		printf("%d", arr[i]);
	}
}
