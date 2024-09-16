#include <stdio.h>
#include <stdlib.h>

void getInput(int arr[], int size);
void display(int arr[], int size);

int main()
{
	int size;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	
	int* arr = (int*) calloc(size, sizeof(int));
	if (arr != NULL){
		
		
		getInput(arr, size);
		display(arr, size);
	}
	

	return 0;
}

void getInput(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++){
		printf("Enter integer %d: ", i+1);
			scanf("%d", &arr[i]);
}
}
void display(int arr[], int size){
	int i;
	for (i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
}
