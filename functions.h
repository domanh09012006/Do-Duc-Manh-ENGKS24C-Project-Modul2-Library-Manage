#include"datatypes.h"
//Nguyen mau ham
void printMenu();
void printMainMenu();
void inputBook(int *n, Book books[]);
void printBook(int n, Book books[]);
void addBook(int *n, Book books[]);
void updateBook(int n, Book books[]);
void deleteBook(int *n, Book books[]);
void saveOfFile(int n, Book books[]);
void searchBook(int n, Book books[]);
void arrangeBooks(int n, Book books[]);
void loadBooksFromFile(int *n, Book books[]);
void bookMenu();
void adminMenu();
void customerMenu();
int checkID(int id, int n, Book books[]);
int checkTitle(char *title, int n, Book books[]);
int checkString(char *str);
void inputCustomer(int *n, Customer customers[]);
void deleteCustomer(int *n, Customer customers[]);
void searchCustomer(int n, Customer customers[]);
void printCustomer(int n, Customer customers[]);
void addCustomer(int *n, Customer customers[]);
int checkIDCustomer(int id, Customer customers[], int n);
