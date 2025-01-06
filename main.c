#include <stdio.h>
#include <stdlib.h>
#include"functions.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choice;
	char check;
    do {
    	system("cls");
        printMainMenu();
        printf("Enter The Choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
            	system("cls");
                customerMenu();
                printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return 0;
                }
                break;
            case 2:
            	system("cls");
                bookMenu();
                break;
            case 0:
                system("cls");
				printf("\n        ======= THANK YOU! ======\n");
				printf("======= GOODBYE AND SEE YOU AGAIN! ======\n");
				printf("-----------------------------------------\n");
				return 0;
                break;
            default:
                printf("LUA CHON KHONG HOP LE!\n");
        }
    } while (choice != 0);
	return 0;
}
