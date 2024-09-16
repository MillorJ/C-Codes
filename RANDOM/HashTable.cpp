#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct HashItem {
    int key;
    int value;
} HashItem;

HashItem* hashTable[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key, int value) {
    int index = hashFunction(key);
    while (hashTable[index] != NULL && hashTable[index]->key != key) {
        index = (index + 1) % TABLE_SIZE;
    }
    if (hashTable[index] != NULL) free(hashTable[index]);
    hashTable[index] = (HashItem*)malloc(sizeof(HashItem));
    hashTable[index]->key = key;
    hashTable[index]->value = value;
}

int search(int key) {
    int index = hashFunction(key);
    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key)
            return hashTable[index]->value;
        index = (index + 1) % TABLE_SIZE;
    }
    return -1;
}

void deleteItem(int key) {
    int index = hashFunction(key);
    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key) {
            free(hashTable[index]);
            hashTable[index] = NULL;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    }
}

void printTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL)
            printf("Key: %d, Value: %d\n", hashTable[i]->key, hashTable[i]->value);
        else
            printf("~\n");
    }
}

int main() {
    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);

    printTable();

    printf("Search for key 42: %d\n", search(42));

    deleteItem(42);
    printTable();

    return 0;
}

