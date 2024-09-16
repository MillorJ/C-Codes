#include <stdio.h>

int main(){
    int size;
    int i;
    int j;

    printf("Enter the size: ");
    scanf("%d", &size);

    for(i = 1; i <= size; i++){
        for (j = 1; j <= i; j++){
            printf("%d\n", j);
        }
    }
    return 0;
}