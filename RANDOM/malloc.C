#include <stdio.h>
#include <stdlib.h>

void InputData(int arr[], int size);
void DisplayArray(int arr[], int size);

    int main(){
        int i;
        int size;
        int *arr = (int*) malloc(size * sizeof(int));
        if (arr != NULL){
        printf("Enter the size of the array: ");
        scanf("%d", &size);
        InputData(arr, size);
        DisplayArray(arr,size);
        free(arr);
        }   
        return 0;
    }

void InputData(int arr[], int size){
    int i;
    for (i = 0; i < size; i++){
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void DisplayArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++){
        printf("%d", arr[i]);
    }
}
