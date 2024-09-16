#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getHowMany(int arr[], int size)
{
    int count = 0;
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] > 36) {
            count++;
        }
    }
    return count;
}

int* myFunction(int arr[], int size)
{
    int count = getHowMany(arr, size);

    int* retVal;
    int index = 0, i;
    retVal = (int *) malloc (sizeof(int) * count);
    if (retVal != NULL) {
        for (i = 0; i < size; i++) {
            if (arr[i] > 36) {
                retVal[index] = arr[i];
                index++;
            }
        }
    }

    return retVal;

}


int main()
{
    int size = 8;
    int arr[] = {36, 38, 32, 28, 39, 40, 41, 42};
    int *retVal = myFunction(arr, size);

    int count = getHowMany(arr, size);
    for (int i = 0; i < count; i++) {
        printf("%d ", retVal[i]);
    }

    // int arr[] = {1,2,3,4};
    // int arr1[5] = {1,2,3};
    // memcpy(arr1 + 3, arr + 3, sizeof(int) * 1);
    

    char x[] = "hello world";
    printf("\n%s\n", strrev(x));    

    int i;
    for (i = 0; i < strlen(x); i++) {
        printf("%c", x[i]);
    }

    return 0;
}
