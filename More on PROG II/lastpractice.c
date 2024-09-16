#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef enum {
    FALSE, TRUE
} Boolean;

typedef struct {
    char name[SIZE];
    char brand[SIZE];
    int id;
} ProductInfo;

typedef struct {
    ProductInfo info;
    int qty;
    int price;
} Product;

typedef struct {
    Product productList[SIZE];
    int counter;
} ProductRecord;



/**
 * Given the record of the products as parameter, this function will print all
 * the products found in the record by calling/invoking the printProduct() function.
*/
void printProductList(ProductRecord productRecord)
{
    int i;
    for (i = 0; i < productRecord.counter; i++) {
        printProduct(productRecord.productList[i]);
    }
}

/**
 * Given a product as a parameter, this function will print 
 * the information of a product.
*/
void printProduct(Product product)
{
    printf("%d", product.info.id);
    printf("%10s", product.info.name);
    printf("%10s", product.info.brand);
    printf("%5d", product.qty);
    printf("%4f \n", product.price);
    
}

/**
 * Given the product record and a product as parameters, this function
 * will add the new product to the product record at the end of the record.
*/
void addProduct(ProductRecord *productRecord, Product product)
{
    productRecord->productList[productRecord->counter] = product;
    productRecord->counter++;
}

/**
 * Given an id of the product, this function will look for that product and 
 * delete it in the record if it exists, otherwise, it will print a message
 * that says "Product <id> does not exist."
*/
void deleteProduct(ProductRecord *productRecord, int productId)
{
    int i,j;
    int found = 0;
    for (i = 0; i < productRecord->counter; i++) {
        if(productRecord->productList[i].info.id == productId) {
            found = 1;
            for (j = i; j < productRecord->counter-1; j++) {
                productRecord->productList[j] = productRecord->productList[j+1];
            }
            productRecord->counter--;
            printf("product %d exist", productId);
        }
    }
    if (!found) {
        printf("product %d does not exist", productId);
    }
}

/**
 * Given the product record and the id of a product as parameters, this function
 * will return TRUE if the product can be found in the records, otherwise, it will
 * return FALSE.
 */
Boolean isMember(ProductRecord productRecord, int productId)
{
    int i;
    Boolean found = FALSE;
    for (i = 0; i < productRecord.counter; i++) {
        if(productRecord.productList[i].info.id == productId){
            found = TRUE;
        }
    }
    return found;

}

/**
 * Given the product record, the id of a product, and a new product info as parameters,
 * this function will look for the specific product and update its information, if it exists.
 * Otherwise, it will print a message that says "Product <id> does not exist."
 */
void updateProduct(ProductRecord *productRecord, int productId, ProductInfo info)
{
    int i;
    int found = 0;
    for (i = 0; i < productRecord->counter; i++) {
        if (productRecord->productList[i].info.id == productId) {
            found = 1;
            productRecord->productList[i].info = info;
        }
    }
    return found;
}
/**
 * Given the product record and a list of the products, this function will populate
 * the product record.
 */
void populateProductRecord(ProductRecord *productRecord, Product productList[], int size)
{
    int i;
    for (i = 0; i < size; i++) {
        productRecord->productList[i] = productList[i];
    }
    productRecord->counter = size;
}



int main()
{
    // Initialize the following variables
    ProductRecord productRecord = {.counter = 0};
    int size = 5;
    Product productList[5] = {
        {{"John","bearbrand",111}, .qty = 20, .price = 11},
        {{"Hans","Coke",112}, .qty = 15, .price = 15},
        {{"Mama","Sprite", 125}, .qty = 14, .price = 12},
        {{"Papa","Royal", 126}, .qty = 17, .price = 14},
        {{"Ate", "Pepsi", 127}, .qty = 19, .price = 15},
    };
    // Populate the Product Record.
    populateProductRecord(&productRecord,productList, size);
    printf("before adding: \n");
    // Display the Product Record.
   printProductList(productRecord);
    printf("after adding: \n");
    Product product1 = {"john","hallow", 1224, 154, 123};
    addProduct(&productRecord, product1);
 //   addProduct(___, ____);

    printProductList(productRecord);


    // Delete a Product;
    int productId = 126;
   deleteProduct(&productRecord, productId);
    printf("\n\n\n");
    printf("after deleting: \n\n");

    // Check the deleted product if it exists or not.
    Boolean isExists = isMember(productRecord, productId);
    printf("The product %d is %d\n", productId, isExists);


    // Update a specific product
  //  updateProduct(___, ____, ____);


    return 0;
}