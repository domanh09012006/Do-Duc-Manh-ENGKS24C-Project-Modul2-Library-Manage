#include <stdio.h>
#include <stdlib.h>
#include"functions.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choice;
	int currentLength;
	char check;
	Book Books[50];
	printf("\n			>**********LIBRARY MANAGEMENT**********< 			\n");
	printf("=========================================================================================\n");
	do{
		system("cls");
		printMenu();
		printf("Vui long nhap lua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				system("cls");
				printf("\n			****INPUT BOOK****\n");
				printf("======================================================\n");
				inputBook(&currentLength, Books);
//				saveOfFile(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return 0;
                }
				break;
			case 2:
				system("cls");
				printf("\n			****ALL BOOK****\n");
				printf("======================================================\n");
				printBook(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return 0;
                }
				break;
			case 3:
				system("cls");
				printf("\n			****ADD BOOK****\n");
				printf("======================================================\n");
				addBook(&currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return 0;
                }
				break;
			case 4:
				system("cls");
				printf("\n			****UPDATE BOOK****\n");
				printf("======================================================\n");
				updateBook(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return 0;
                }
				break;
			case 5:
				system("cls");
				printf("\n			****DELETE BOOK****\n");
				printf("======================================================\n");
				deleteBook(&currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return 0;
                }
				break;
			case 6:
				system("cls");
				printf("\n			****SEARCH BOOK****\n");
				printf("======================================================\n");
				searchBook(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return 0;
                }
				break;
			case 7:
				system("cls");
				printf("\n			****ARRANGE BOOK****\n");
				printf("======================================================\n");
				arrangeBooks(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return 0;
                }
				break;
			case 8:
				system("cls");
				printf("\n        ======= THANK YOU! ======\n");
				printf("======= GOODBYE AND SEE YOU AGAIN! ======\n");
				printf("-----------------------------------------\n");
				return 0;
				break;
			default:
				printf("LUA CHON KHONG HOP LE!");
				break;
		}
	}while(choice!=8);
	return 0;
}
