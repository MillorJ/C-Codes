#include <stdio.h>
#include <stdlib.h>

int* myFunction(int arr[], int size);
int getHowMany(int arr[], int size);

int main()
{
    int size = 8;
    int arr[] = {36, 38, 32, 28, 39, 40, 41, 42};
    int *retVal = myFunction(arr, size);
    int count = getHowMany(arr, size);

    for (int i = 0; i < count; i++) {
        printf("%d ", retVal[i]);
    }

    return 0;
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