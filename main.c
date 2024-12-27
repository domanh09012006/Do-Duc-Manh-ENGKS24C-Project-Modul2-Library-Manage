#include <stdio.h>
#include <stdlib.h>
#include"functions.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choice;
	int currentLength;
	Book Books[50];
	do{
		printMenu();
		printf("Vui long nhap lua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				inputBook(&currentLength, Books);
				saveOfFile(currentLength, Books);
				break;
			case 2:
				printBook(currentLength, Books);
				break;
			case 3:
				addBook(&currentLength, Books);
				break;
			case 4:
				deleteBook(&currentLength, Books);
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				printf("Thoat!");
				break;
			default:
				printf("Lua chon khong hop le!");
				break;
		}
	}while(choice!=7);
	return 0;
}
