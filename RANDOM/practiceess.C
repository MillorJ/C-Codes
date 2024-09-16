#include <stdio.h>
#include <stdlib.h>

void inputData(int *arr, int size);
void displayArray(int arr[], int size);



int main(){

   int size;
   printf("Enter the size: ");
   scanf("%d", &size);
   int *arr = (int*) malloc(sizeof(int));
    inputData(arr, size);

  
    
   return 0;
}
void inputData(int *arr, int size){
    //Getting inputs declaring variables
    int i;
    for (i = 0; i < size; i++){
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    displayArray(arr, size);
}
void displayArray(int *arr, int size){
    int i;
    for (i = 0; i < size; i++){
        printf("%d",arr[i]);
    }
}


 