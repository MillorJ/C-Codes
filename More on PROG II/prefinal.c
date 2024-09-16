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
 * Given a product as a parameter, this function will print
 * the information of a product.
 */
void printProduct(Product product)
{
    printf("%d", product.info.id);
    printf("%10s", product.info.name);
    printf("%10s",product.info.brand);
    printf("%4d", product.qty);
    printf("%4d \n", product.price);
}   


/**
 * Given the record of the products as parameter, this function will print all
 * the products found in the record by calling/invoking the printProduct() function.
*/
void printProductList(ProductRecord productRecord)
{
    int i;
    for(i = 0; i < productRecord.counter; i++) {
        printProduct(productRecord.productList[i]);
    }
}

/**
 * Given a product as a parameter, this function will print 
 * the information of a product.
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

}

/**
 * Given the product record and the id of a product as parameters, this function
 * will return TRUE if the product can be found in the records, otherwise, it will
 * return FALSE.

 */
Boolean isMember(ProductRecord productRecord, int productId)
{
    Boolean found = FALSE;
    int i;
    for (i = 0; i < productRecord.counter; i++) {
        if(productRecord.productList[i].info.id == productId) {
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

}

/**
 * Given the product record and a list of the products, this function will populate
 * the product record.
 */
void populateProductRecord(ProductRecord *productRecord, Product productList[], int size)
{
    int i;
    for(i = 0; i < size; i++) {
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
    populateProductRecord(&productRecord, productList, size);

    // Display the Product Record.
    printProductList(productRecord);

    // Add a New Product
   // Product product1, product2;
    Product product1 = {{"Softdrinks", "Mouintaindew", 1234}, .qty = 32, .price = 2500};
	Product product2 = {{"Biscuit", "Hansel", 1245}, .qty = 43, .price = 140};
    addProduct(&productRecord, product1);
    addProduct(&productRecord, product2);
    printProductList(productRecord);
    // Delete a Product;
   // int productId;
   // deleteProduct(___, ____);


    // Check the deleted product if it exists or not.
  //  Boolean isExists = isMember(___, ___);
   // printf("The product %d is %d\n", productId, isExists);


    // Update a specific product
 //   updateProduct(___, ____, ____);


    return 0;
}