#include <stdio.h>
#include <stdlib.h>

int GetTwoHighNumber(int arr[]);   
    
    int main(){
        int arr[5] = {36, 38, 32, 28, 39};
    
        printf("The two highest number in the array are: ");
        GetTwoHighNumber(arr);
       

        return 0;
    }  

int GetTwoHighNumber(int arr[]){
    int i;
    int max = arr[i];
    int min;
    for (i = 0; i < 5; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }  
    }
    return arr;

}