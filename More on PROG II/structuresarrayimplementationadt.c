#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef enum {
    FALSE, TRUE
} Boolean;

typedef struct {
    char name[SIZE];
    char description[SIZE];
    int quantity;
    double price;
} Item;

typedef struct {
    Item itemList[SIZE];
    int counter;
} ItemRecord;


void printItem(Item item)
{
    // NAME, DESCRIPTION, QUANTITY, PRICE
    printf("%s", item.name);
    printf("%5s", item.description);
    printf("%7d", item.quantity);
    printf("%7f \n", item.price);
}

/**
 * Given the item record and an item as parameters, this function
 * will add the new item to the item record at the end of the record.
*/

/**
 * Given the record of the items as parameter, this function will print all
 * the items found in the record by calling/invoking the printItem() function.
*/
void printItemList(ItemRecord itemRecord)
{
    int i;
    for (i = 0; i < itemRecord.counter; i++) {
        printItem(itemRecord.itemList[i]);
    }


}

/**
 * Given an item as a parameter, this function will print 
 * the information of an item.
*/

void addItem(ItemRecord *itemRecord, Item item)
{
    itemRecord->itemList[itemRecord->counter++] = item;

}

/**
 * Given a name of the item, this function will look for that item and 
 * delete it in the record if it exists, otherwise, it will print a message
 * that says "Item <name> does not exist."
*/
void deleteItem(ItemRecord *itemRecord, char *itemName)
{
    int i,j;
    int found = 0;
    for (i = 0; i < itemRecord->counter; i++) {
        if (itemRecord->itemList[i].name == itemName) {
            found = 1;
        for (j = i; j < itemRecord->counter-1; j++) {
            itemRecord->itemList[j] = itemRecord->itemList[j];
        }
        itemRecord->counter--;
        printf("Item %s deleted sucessfully", itemName);
        }
    }
    if (!found) {
        printf("Item %s does not exist", itemName);    
}
}

/**
 * Given the item record and the name of an item as parameters, this function
 * will return TRUE if the item can be found in the records, otherwise, it will
 * return FALSE.
 */
Boolean isMember(ItemRecord itemRecord, char *itemName)
{
    int i;
    Boolean FOUND = FALSE;
    for (i = 0; i < itemRecord.counter; i++) {
        if (itemRecord.itemList[i].name == itemName) {
                FOUND = TRUE;
        }
    }
    return FOUND;

}

/**
 * Given the item record, the name of an item, and a new item as parameters,
 * this function will look for the specific item and update its information, 
 * if it exists. Otherwise, it will print a message that says 
 * "Item <name> does not exist."
 */
void updateItem(ItemRecord *itemRecord, char *itemName, Item newItem)
{
    int i;
    Boolean found = FALSE;
    for (i = 0; i < itemRecord->counter; i++) {
        if (strcmp(itemRecord->itemList[i].name, itemName) == 0) {
            itemRecord->itemList[i] = newItem;
            found = TRUE;
            break;
        }
    }
    if (!found) {
        printf("Item %s does not exist.\n", itemName);
    }
}
/**
 * Given the item record and a list of the items, this function will populate
 * the item record.
 */
void populateItemRecord(ItemRecord *itemRecord, Item itemList[], int size)
{
    int i;
    for (i = 0; i < size; i++) {
        itemRecord->itemList[i] = itemList[i];
    }
    itemRecord->counter = size;
    

}
 
int main () {
    ItemRecord iTemRecord = {.counter = 0};
    int size = 3;
    Item itemList[3] = {
        {"bag","good", 100, 150.4},
        {"tshirt","nike", 150, 250.4},
        {"pc","  good quality", 1000, 2000.5},
    };

    populateItemRecord(&iTemRecord, itemList, size);

    printItemList(iTemRecord);
    Item product1 = {"cp", "   excellent", 300, 300.5};
    Item product2 = {"alcohol", "  smooth", 350, 300.50};
    printf("\n");

    printf("after adding:\n");
    addItem(&iTemRecord, product1);
    addItem(&iTemRecord, product2);
    printItemList(iTemRecord);

    printf("\n");

    printf("after deleting:\n");
    deleteItem(&iTemRecord, "bag");

     printItemList(iTemRecord);
    
     Boolean isPencilInRecord = isMember(iTemRecord, "Pencil");
    printf("\nIs 'Pencil' in the item record? %s\n", isPencilInRecord ? "YES" : "NO");

    

    



    return 0;
}

