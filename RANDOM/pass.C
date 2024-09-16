#include <stdio.h>
#include <stdlib.h>

int* GetIntegers(int size);

int main(){
    //Declaring Variable
    int i;
    int size;
    //Get Input
    printf("Enter the size: ");
    scanf("%d", &size);

    int* get = GetIntegers(size);
    
    for (i = 0; i < size; i++){
        printf("%d", get[i]);
    }
    return 0;

}
int* GetIntegers(int size){
    int i;
    //Declare malloc because function is int pointer
    int *arr = (int*) malloc(sizeof(int));
    if (arr != NULL){
        for (i = 0; i < size; i++){
            printf("Enter integer %d: ", i + 1);
            scanf("%d", &arr[i]);
        }
    }
    return arr;

}