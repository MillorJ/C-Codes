#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef enum {
    FALSE, TRUE
} Boolean;

typedef struct {
    char title[100];
    char author[100];
    int yearPublished;
    double price;
} Book;

typedef struct {
    Book bookList[MAX_BOOKS];
    int counter;
} BookRecord;

/**
 * Given the record of books as parameter, this function will print all
 * the books found in the record by calling/invoking the printBook() function.
 */
void printBookList(BookRecord bookRecord);

/**
 * Given a book as a parameter, this function will print the information of a book.
 */
void printBook(Book book);

/**
 * Given the book record and a book as parameters, this function
 * will add the new book to the book record at the end of the record.
 */
void addBook(BookRecord* bookRecord, Book book);

/**
 * Given a title and the book record, this function will look for the book with the
 * matching title in the record, and delete it if it exists. Otherwise, it will
 * print a message that says "Book <title> does not exist."
 */
void deleteBook(BookRecord* bookRecord, char* title);

/**
 * Given the book record and the title of a book as parameters, this function
 * will return TRUE if the book can be found in the records, otherwise, it will
 * return FALSE.
 */
Boolean isBookInRecord(BookRecord bookRecord, char* title);

/**
 * Given the book record, the title of a book, and a new book as parameters,
 * this function will look for the specific book and update its information,
 * if it exists. Otherwise, it will print a message that says
 * "Book <title> does not exist."
 */
void updateBook(BookRecord* bookRecord, char* title, Book newBook);

/**
 * Given the book record and a list of books, this function will populate
 * the book record.
 */
void populateBookRecord(BookRecord* bookRecord, Book bookList[], int size) {
    int i;
    for (i = 0; i < bookRecord->counter; i++) {
        bookRecord->bookList[i] = bookList[i];
    }
    bookRecord->counter = size;
}

int main() {
    BookRecord bookRecord;
    bookRecord.counter = 0;

    // populate book record with initial data
    Book books[] = {
        {"The Great Gatsby", "F. Scott Fitzgerald", 1925, 12.99},
        {"To Kill a Mockingbird", "Harper Lee", 1960, 8.99},
        {"1984", "George Orwell", 1949, 9.99},
        {"The Catcher in the Rye", "J.D. Salinger", 1951, 10.99},
        {"Pride and Prejudice", "Jane Austen", 1813, 7.99}
    };
    populateBookRecord(&bookRecord, books, 5);
    
    
    
    return 0;
}  