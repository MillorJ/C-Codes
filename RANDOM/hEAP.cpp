#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Heap {
    int array[MAX];
    int size;
} Heap;

void initHeap(Heap* h) {
    h->size = 0;
}

void heapifyUp(Heap* h, int index) {
    if (index && h->array[(index - 1) / 2] < h->array[index]) {
        int temp = h->array[(index - 1) / 2];
        h->array[(index - 1) / 2] = h->array[index];
        h->array[index] = temp;
        heapifyUp(h, (index - 1) / 2);
    }
}

void insertHeap(Heap* h, int value) {
    if (h->size == MAX) {
        printf("Heap is full!\n");
        return;
    }
    h->array[h->size] = value;
    heapifyUp(h, h->size);
    h->size++;
}

void heapifyDown(Heap* h, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < h->size && h->array[left] > h->array[largest])
        largest = left;

    if (right < h->size && h->array[right] > h->array[largest])
        largest = right;

    if (largest != index) {
        int temp = h->array[index];
        h->array[index] = h->array[largest];
        h->array[largest] = temp;
        heapifyDown(h, largest);
    }
}

void removeHeap(Heap* h) {
    if (h->size == 0) {
        printf("Heap is empty!\n");
        return;
    }
    h->array[0] = h->array[--h->size];
    heapifyDown(h, 0);
}

void printHeap(Heap* h) {
    for (int i = 0; i < h->size; i++)
        printf("%d ", h->array[i]);
    printf("\n");
}

int main() {
    Heap h;
    initHeap(&h);

    insertHeap(&h, 50);
    insertHeap(&h, 30);
    insertHeap(&h, 20);
    insertHeap(&h, 15);
    insertHeap(&h, 10);
    insertHeap(&h, 60);

    printHeap(&h);

    removeHeap(&h);
    printHeap(&h);

    return 0;
}

