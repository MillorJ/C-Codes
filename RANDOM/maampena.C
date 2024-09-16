#include <stdio.h>

void exchange(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void findpos(int A[], int N) {
    int i = N - 2;
    while (i >= 0 && A[i] > A[N - 1]) {
        exchange(&A[i], &A[i + 1]);
        i--;
    }
}

void display(int A[], int N) {
    int i;
    printf("Array: ");
    for (i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {2, 5, 5, 8, 9, 10, 3};
    int N = sizeof(A) / sizeof(A[0]);
    findpos(A, N);
    display(A, N);
    return 0;
}
