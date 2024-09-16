#include <stdio.h>


int getNegative(int arr[], int num);

    int main(){
        int arr[100];
        int i,num;

        printf("Enter size of the array: ");
        scanf("%d", &num);

        printf("The elements of the array: ");
        for (i = 0; i < num; i++){
            scanf("%d ", &arr[i]);
        }
        printf("\nThe negative elements in the array are: ");
        getNegative(arr, num);
        return 0;

    }

int getNegative(int arr[], int num){
    int i;
    for (i = 0; i < num; i++){
        if (arr[i] < 0){
            printf(" %d", arr[i]);
        }
    }
    return 0;
}