#include <stdio.h>
#include <stdlib.h>

void inputData(int arr[], int size);
void displayArray(int arr[], int size);
int FindElem(int arr[], int size, int elem);
int findSmallest(int *arr, int size);
void exchange(int *arr, int i, int j);
int FindMin(int arr[], int size, int elem);
int FindMax(int arr[], int size, int max);
int InsertElem(int arr[], int size, int elem);

int main() {
    int size;
    int elem;
    int max;
    printf("Input the size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));


    inputData(arr, size);
    displayArray(arr, size);

    printf("\n\n");

    printf("In Task 2\n");
    printf("Enter an element to search for: ");
    scanf("%d", &elem);
    int index = FindElem(arr, size, elem);
    if (index != -1) {
        printf("Element %d is found in the array at index %d\n", elem, index);
    } else {
        printf("Element %d is not found in the array\n", elem);
}
        printf("\n\nTask 3\n");
    int min = findSmallest(arr, size);
    printf("The smallest element in the array is: %d\n", min);

    printf("\n\nTask 4\n");
    int firstIndex, secondIndex;
    printf("Enter first index to swap: ");
    scanf("%d", &firstIndex);
    printf("Enter second index to swap: ");
    scanf("%d", &secondIndex);
    exchange(arr, firstIndex, secondIndex);
    printf("Array after swapping: ");
    displayArray(arr, size);
    FindMin(arr, size, min);
    printf("\n");
    FindMax(arr, size, max);
    free(arr);
    return 0;
}

void inputData(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
    printf("Input the %d number: ", i + 1);
    scanf("%d", &arr[i]);
}
}

void displayArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
}
    printf("\n");
}
int FindElem(int arr[], int size, int elem){
    int i;
    for (i = 0; i < size; i ++){
    if(arr[i] == elem){
    return i;
}
}
    return -1;
}

int findSmallest(int *arr, int size) {
    int i;
    int *smallest = (int *)malloc(sizeof(int));
    *smallest = arr[0];
    for (i = 1; i < size; i++) {
    if (arr[i] < *smallest) {
    *smallest = arr[i];
}
}
    int result = *smallest;
    free(smallest);
    return result;  
}

void exchange(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int FindMin(int arr[], int size, int min){
    min = arr[0];

    for (int i = 0; i < size; i++){
        if (arr[i] < min){
            min = arr[i];
        }
    }
    printf("\nThe min in the element is %d", min);
    return 0;
    
}
int FindMax(int arr[], int size, int max){
    max = arr[0];
    int i;
    for (i = 0; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    printf("The max element is %d", max);
    return max;
}
int InsertElem(int arr[], int size, int elem){
    
}
