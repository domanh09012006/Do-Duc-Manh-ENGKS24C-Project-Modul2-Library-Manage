#include"functions.h"
#include<stdio.h>
#include<string.h>
//Logic ham
void printMenu(){
	printf("\n=========== MENU ===========\n");
    printf("[1]. Nhap so luong va thong tin sach\n");
    printf("[2]. Hien thi thong tin sach\n");
    printf("[3]. Them sach vao vi tri cuoi\n");
    printf("[4]. Cap nhat thong tin sach theo ma sach\n");
    printf("[5]. Xoa sach theo ma sach\n");
    printf("[6]. Tim kiem sach theo ten sach\n");
    printf("[7]. Sap xep sach theo gia tien\n");
    printf("[8]. Luu file\n");
    printf("[0]. Quay lai\n");
    printf("============================\n");
}
void inputBook(int *n, Book books[]){
	int i, id, price;
    char title[100], author[100], category[100];
    printf("Nhap so luong sach(so duong): ");
    scanf("%d", n);
    getchar();
    if(*n<=0) {
        printf("So luong sach phai lon hon 0\n");
        return;
    }
    for (i=0; i<*n; i++) {
        printf("\nNhap thong tin quyen sach thu %d:\n", i+1);
        do{
            printf("Nhap ID: ");
            scanf("%d", &id);
            getchar();
            if(checkID(id, i, books)){
                printf("ID da ton tai.\n");
            }else if(id <= 0){
                printf("ID phai lon hon 0\n");
			}
        } while(checkID(id, i, books) || id<=0);
        books[i].id = id;
        do{
            printf("Nhap ten sach: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = '\0';
            if (!checkString(title)) {
                printf("Ten sach khong duoc trong\n");
            }else if (checkTitle(title, i, books)){
                printf("Ten sach da ton tai\n");
            }
        }while(!checkString(title) || checkTitle(title, i, books));
        strcpy(books[i].title, title);
        do{
            printf("Nhap ten tac gia: ");
            fgets(author, sizeof(author), stdin);
            author[strcspn(author, "\n")] = '\0';
            if (!checkString(author)) {
                printf("Ten tac gia khong duoc trong\n");
            }
        }while(!checkString(author));
        strcpy(books[i].author, author);
        do{
            printf("Nhap gia tien: ");
            scanf("%d", &price);
            getchar();
            if (price <= 0) {
                printf("Gia tien phai lon hon 0\n");
            }
        }while(price<=0);
        books[i].price = price;
        do{
            printf("Nhap The loai: ");
            fgets(category, sizeof(category), stdin);
            author[strcspn(category, "\n")] = '\0';
            if (!checkString(category)) {
                printf("The loai khong duoc trong\n");
            }
        }while(!checkString(category));
        strcpy(books[i].category, category);
    }
}
void printBook(int n, Book books[]){
	int i;
	printf("=================================================================================\n");
	printf("|ID ||     Ten sach       ||      Tac gia       ||    Gia tien   ||   The loai   |\n");
	printf("=================================================================================\n");
	for(i=0 ;i<n;i++){
		printf("| %d ||%-20s||%-20s||%-15d||%-14s\n", books[i].id, books[i].title, books[i].author, books[i].price, books[i].category);
		printf("-----------------------------------------------------------------------------\n");
	}
	printf("============================================================================\n");
	printf("\n");
}
void addBook(int *n, Book books[]){
	getchar();
    books[*n].id = *n+1;
    do{
        printf("Moi ban nhap vao ten sach: \n");
        fgets(books[*n].title, 100, stdin);
        books[*n].title[strcspn(books[*n].title, "\n")] = '\0';
        if (!checkString(books[*n].title)){
            printf("Ten sach khong duoc trong\n");
        }else if (checkTitle(books[*n].title, *n, books)){
            printf("Ten sach da ton tai\n");
        }
    }while (!checkString(books[*n].title) ||checkTitle(books[*n].title, *n, books));
    do{
        printf("Moi ban nhap vao ten tac gia: \n");
        fgets(books[*n].author, 100, stdin);
        books[*n].author[strcspn(books[*n].author, "\n")] = '\0';
        if (!checkString(books[*n].author)) {
            printf("Ten tac gia khong duoc trong\n");
        }
    }while (!checkString(books[*n].author));
    do{
        printf("Moi ban nhap vao gia tien: \n");
        scanf("%d", &books[*n].price);
        getchar();
        if (books[*n].price <= 0) {
            printf("Gia tien phai lon hon 0\n");
        }
    }while(books[*n].price <= 0);
    do{
        printf("Moi ban nhap vao the loai: \n");
        fgets(books[*n].category, 100, stdin);
        books[*n].category[strcspn(books[*n].category, "\n")] = '\0';
        if (!checkString(books[*n].category)) {
            printf("Ten tac gia khong duoc trong\n");
        }
    }while (!checkString(books[*n].category));
    (*n)++;
    printf("THEM SACH THANH CONG!\n");
}
void deleteBook(int *n, Book books[]){
	int position, i;
	printf("Moi ban nhap vao ID muon xoa:");
	scanf("%d", &position);
	int findIndex=-1;
	for(i=0;i<*n;i++){
		if(books[i].id==position){
			findIndex =i;
			break;
		}
	} 
	if(findIndex==-1){
		printf("Khong tim thay sach de xoa");
	}else{
		int val;
		printf("\n");
		printf("ID: %d\n", books[i].id);
		printf("Ten sach: %s\n", books[i].title);
		printf("Tac gia: %s\n", books[i].author);
		printf("Gia tien: %d\n", books[i].price);
		printf("The loai: %s\n", books[i].category);
		printf("\n");
		printf("Ban co thuc su mua xoa sach nay khong? [1](co) [2](khong): \n");
		scanf("%d", &val);
		if(val == 1){
			int i;
			for(i=findIndex;i<*n;i++){
				books[i]=books[i+1];
			}
			(*n)--;
			printf("XOA THANH CONG!");
		}else if( val == 2){
			printf("DA HUY QUA TRINH XOA!");
		}else if((val != 1)&&(val != 2)){
			printf("Khong co lua chon nay!");
		}
		
	}
}
void saveOfFile(int n, Book books[]){
	// Mo file 
	FILE *ptr=fopen("studentsData.dat","wb");
	// Thao tac file
	if(ptr==NULL){
		printf("Khong mo duoc file");
	}
	fwrite(&n, sizeof(int), 1, ptr);
	fwrite(books,sizeof(Book),n,ptr);
	printf("Luu thong tin thanh cong");
	// Dong file 
	fclose(ptr);
}
void searchBook(int n, Book books[]){
	char searchTitle[100];
	char searchLower[100];
	void toLowerCase(char *str){
		int i;
    	for(i=0; str[i]; i++){
        	str[i] = tolower(str[i]);
    	}
	}
    int found=0;
    printf("Moi ban nhap vao ten sach can tim: ");
    getchar();
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0';
    strcpy(searchLower, searchTitle);
    toLowerCase(searchLower);
    printf("		---THONG TIN SACH---\n");
    int i;
    for(i = 0; i<n; i++){
        char titleLower[100];
        strcpy(titleLower, books[i].title);
        toLowerCase(titleLower);
        if(strstr(titleLower, searchLower) != NULL){
        	printf("\n");
			printf("ID: %d\n", books[i].id);
			printf("Ten sach: %s\n", books[i].title);
			printf("Tac gia: %s\n", books[i].author);
			printf("Gia tien: %d\n", books[i].price);
			printf("The loai: %s\n", books[i].category);
			printf("\n");
            found = 1;
        }
    }
    if (!found) {
        printf("KHONG TIM THAY SACH!\n");
    }
}
void updateBook(int n, Book books[]) {
    int position;
    char title[100], author[100], category[100];
    int price;
    printf("Moi ban nhap vao ID muon update: ");
    scanf("%d", &position);
    getchar();
    int findIndex = -1;
    int i;
    for(i=0; i<n; i++){
        if (books[i].id == position) {
            findIndex=i;
            break;
        }
    }
    if (findIndex == -1) {
        printf("KHONG TIM THAY SACH DE UPDATE!\n");
    } else {
        printf("\n");
        printf("ID: %d\n", books[findIndex].id);
        printf("Ten sach: %s\n", books[findIndex].title);
        printf("Tac gia: %s\n", books[findIndex].author);
        printf("Gia tien: %d\n", books[findIndex].price);
        printf("The loai: %s\n", books[findIndex].category);
        printf("\n");
        do{
            printf("Moi ban nhap vao ten sach:\n");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = '\0';
            if (!checkString(title)) {
                printf("Ten sach khong duoc trong\n");
            }
        }while(!checkString(title));
            strcpy(books[findIndex].title, title);
        do{
            printf("Moi ban nhap vao ten tac gia: ");
            fgets(author, sizeof(author), stdin);
            author[strcspn(author, "\n")] = '\0';
            if (!checkString(author)) {
                printf("Ten tac gia khong duoc trong\n");
            }
        } while (!checkString(author));
        strcpy(books[findIndex].author, author);
        do{
            printf("Moi ban nhap vao gia tien: ");
            scanf("%d", &price);
            getchar();
            if (price <= 0) {
                printf("Gia tien phai lon hon 0\n");
            }
        }while (price <= 0);
        books[findIndex].price = price;
        do{
            printf("Moi ban nhap vao the loai: ");
            fgets(category, sizeof(category), stdin);
            category[strcspn(category, "\n")] = '\0';
            if (!checkString(category)) {
                printf("The loai khong duoc trong\n");
            }
        } while (!checkString(category));
        strcpy(books[findIndex].category, category);
        printf("QUA TRINH UPDATE SACH HOAN TAT!\n");
    }
}
void arrangeBooks(int n, Book books[]){
	int arrange;
	printf("1.Sap xep giam dan\n");
	printf("2.Sap xep tang dan\n");
	printf("Nhap lua chon cua ban: ");
    scanf("%d", &arrange);
    if (arrange == 1){
    	int i;
        for(i=0; i<n-1; i++){
		int j;
            for(j=i+1; j<n; j++) {
                if(books[i].price < books[j].price){
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
        printf("HOAN TAT SAP XEP SANH THEO GIA TIEN GIAM DAN!\n");
		printf("============================================================================================================\n");
		printf("|   Ma sach   ||         Ten sach          ||        Tac gia        ||     Gia tien    ||     The loai     |\n");
		printf("============================================================================================================\n");
		for(i=0; i<n; i++){
		    printf("| %-11d || %-25s || %-21s || %-15d || %-16s |\n", 
		           books[i].id, 
		           books[i].title, 
		           books[i].author, 
		           books[i].price, 
		           books[i].category);
		    printf("|----------------------------------------------------------------------------------------------------------|\n");
		}
		printf("============================================================================================================\n");
		printf("\n");
    }else if(arrange == 2){
		int i; 
        for(i=0; i<n-1; i++){
			int j;
            for(j=i+1; j<n; j++) {
                if (books[i].price > books[j].price){
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
        printf("HOAN TAT SAP XEP SANH THEO GIA TIEN TANG DAN!\n");
		printf("============================================================================================================\n");
		printf("|   Ma sach   ||         Ten sach          ||        Tac gia        ||     Gia tien    ||     The loai     |\n");
		printf("============================================================================================================\n");
		for(i=0; i<n; i++){
		    printf("| %-11d || %-25s || %-21s || %-15d || %-16s |\n", 
		           books[i].id, 
		           books[i].title, 
		           books[i].author, 
		           books[i].price, 
		           books[i].category);
		    printf("|----------------------------------------------------------------------------------------------------------|\n");
		}
		printf("============================================================================================================\n");
		printf("\n");
    }else{
        printf("LUA CHON KHONG HOP LE!\n");
        return;
    }
}
void loadBooksFromFile(int *n, Book books[]){
	// Mo file 
	FILE *ptr = fopen("studentsData.dat", "rb");
	// Thao tac file
	if(ptr==NULL){
		printf("Khong mo duoc file");
		return;
	}
	fread(n, sizeof(int), 1, ptr);
     if(*n > 0){
        fread(books, sizeof(Book), *n, ptr); 
    }
	int i;
	printf("|==========================================================================================================|\n");
	printf("|   Ma sach   ||         Ten sach          ||        Tac gia        ||     Gia tien    ||     The loai     |\n");
	printf("|==========================================================================================================|\n");
	for(i=0; i<*n; i++){
	    printf("| %-11d || %-25s || %-21s || %-15d || %-16s |\n", 
	           books[i].id, 
	           books[i].title, 
	           books[i].author, 
	           books[i].price, 
	           books[i].category);
	    printf("|----------------------------------------------------------------------------------------------------------|\n");
	}
	printf("|==========================================================================================================|\n");
	printf("\n");
	// Dong file 
	fclose(ptr);
}
void bookMenu(){
	int choice;
	int currentLength;
	char check;
	Book Books[50];
//	loadBooksFromFile(&currentLength, Books);
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
				printf("\n			*****INPUT BOOK*****\n");
				printf("======================================================\n");
				inputBook(&currentLength, Books);
				saveOfFile(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return;
                }
				break;
			case 2:
				system("cls");
				printf("\n			*****ALL BOOK*****\n");
				printf("======================================================\n");
				loadBooksFromFile(&currentLength, Books);
//				printBook(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return;
                }
				break;
			case 3:
				system("cls");
				printf("\n			*****ADD BOOK*****\n");
				printf("======================================================\n");
				addBook(&currentLength, Books);
				saveOfFile(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return;
                }
				break;
			case 4:
				system("cls");
				printf("\n			*****UPDATE BOOK*****\n");
				printf("======================================================\n");
				updateBook(currentLength, Books);
				saveOfFile(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return;
                }
				break;
			case 5:
				system("cls");
				printf("\n			*****DELETE BOOK*****\n");
				printf("======================================================\n");
				deleteBook(&currentLength, Books);
				saveOfFile(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return;
                }
				break;
			case 6:
				system("cls");
				printf("\n			*****SEARCH BOOK*****\n");
				printf("======================================================\n");
				searchBook(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return;
                }
				break;
			case 7:
				system("cls");
				printf("\n			*****ARRANGE BOOK*****\n");
				printf("======================================================\n");
				arrangeBooks(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return;
                }
				break;
			case 8:
				system("cls");
				printf("\n			*****SAVE BOOK*****\n");
				printf("======================================================\n");
				saveOfFile(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return;
                }
			case 0:
				system("cls");
				printf("QUAY LAI MENU CHINH!");
				break;
			default:
				printf("LUA CHON KHONG HOP LE!");
				break;
		}
	}while(choice!=0);
}
void adminMenu(){
	int choice;
    do {
        printf("\n=== Admin Menu ===\n");
        printf("1. Coming soon\n");
        printf("2. Coming soon\n");
        printf("0. Quay lai\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("COMING SOON\\n");
                break;
            case 2:
                printf("COMING SOON\n");
                break;
            case 0:
                printf("QUAY LAI MENU CHINH!\n");
                break;
            default:
                printf("LUA CHON KHONG HOP LE!\n");
        }
    } while(choice != 0);
}
void customerMenu(){
	int choice;
	int Length=0;
	char check;
	Customer Customers[50];
    do {
    	system("cls");
        printf("\n=== Customer Menu ===\n");
        printf("1. Nhap thong tin khach hang\n");
        printf("2. Hien thi thong tin khac hang\n");
        printf("3. Xoa Khach Hang\n");
        printf("4. Them Khach hang\n");
        printf("5. Tim kiem khach hang\n");
        printf("0. Quay lai\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1:
            	system("cls");
            	printf("\n			*****INPUT CUSTOMER*****\n");
				printf("======================================================\n");
                inputCustomer(&Length, Customers);
                saveCustomerOfFile(Length, Customers);
                printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return;
                }
                break;
            case 2:
                system("cls");
                printf("\n			*****PRINT CUSTOMER*****\n");
				printf("======================================================\n");
//                printCustomer(Length, Customers);
				loadCustomerFromFile(&Length, Customers);
                printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return;
                }
                break;
            case 3:
                system("cls");
                printf("\n			*****DELETE CUSTOMER*****\n");
				printf("======================================================\n");
                deleteCustomer(&Length, Customers);
                saveCustomerOfFile(Length, Customers);
                printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return;
                }
                break;
            case 4:
                system("cls");
                printf("\n			*****ADD CUSTOMER*****\n");
				printf("======================================================\n");
                addCustomer(&Length, Customers);
                saveCustomerOfFile(Length, Customers);
                printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return;
                }
                break;
            case 5:
            	system("cls");
            	printf("\n			*****SEARCH CUSTOMER*****\n");
				printf("======================================================\n");
            	searchCustomer(Length, Customers);
            	printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return;
                }
                break;
            case 0:
                printf("QUAY LAI MENU CHINH!\n");
                break;
            default:
                printf("LUA CHON KHONG HOP LE!\n");
        }
    } while(choice != 0);
}
void printMainMenu(){
	printf("\n*** Library Management System Using C ***\n");
    printf("CHOOSE YOUR ROLE\n");
    printf("===============================\n");
	printf("[1] Customer\n");
    printf("[2] Books\n");
    printf("[0] Exit the Program\n");
    printf("===============================\n");
}
int checkID(int id, int n, Book books[]){
	int i;
    for(i=0; i<n; i++) {
        if (books[i].id == id){
        	printf("Nhap lai!");
            return 1;
        }
    }
    return 0;
}
int checkTitle(char *title, int n, Book books[]){
	int i;
    for (i=0; i<n; i++) {
        if ((strcmp(books[i].title, title) == 0)) {
            return 1;
        }
    }
    return 0;
}
int checkString(char *str){
    return strlen(str) > 0;
}
void inputCustomer(int *n, Customer customers[]) {
    int id;
    printf("Nhap so luong khach hang (so duong): ");
    scanf("%d", n);
    getchar();
    if (*n <= 0) {
        printf("So luong khach hang phai lon hon 0\n");
        return;
    }
	int i;
    for(i=0; i<*n; i++){
        printf("\nNhap thong tin khach hang thu %d:\n", i+1);
        do{
            printf("Nhap ID khach hang: ");
            scanf("%d", &id);
            getchar();
            if (id <= 0) {
                printf("ID phai lon hon 0. Vui long nhap lai!\n");
            } else if (checkIDCustomer(id, customers, *n)) {
                printf("ID da ton tai. Vui long nhap ID khac!\n");
            } else {
                customers[i].id = id;
                break;
            }
        }while (id <= 0 || checkIDCustomer(id, customers, *n));
        do{
            printf("Nhap ten khach hang: ");
            fgets(customers[i].name, 100, stdin);
            customers[i].name[strcspn(customers[i].name, "\n")] = '\0';
            if (!checkString(customers[i].name)) {
                printf("Ten khach hang khong duoc trong. Vui long nhap lai!\n");
            } else if (checkName(customers[i].name)) {
                printf("Ten khach hang khong duoc chua so. Vui long nhap lai!\n");
            }
        }while (!checkString(customers[i].name) || checkName(customers[i].name));
        do{
            printf("Nhap so dien thoai: ");
            fgets(customers[i].phone, 20, stdin);
            customers[i].phone[strcspn(customers[i].phone, "\n")] = '\0';
            if (!checkPhoneNumber(customers[i].phone)) {
                printf("So dien thoai khong hop le. Vui long nhap lai!\n");
            }
        } while (!checkPhoneNumber(customers[i].phone));
    }
    printf("THEM KHACH HANG THANH CONG!\n");
}
void loadCustomerFromFile(int *n, Customer customers[]){
	// Mo file 
	FILE *ptr = fopen("studentData.dat", "rb");
	// Thao tac file
	if(ptr==NULL){
		printf("Khong mo duoc file");
		return;
	}
	fread(n, sizeof(int), 1, ptr);
     if(*n>0){
        fread(customers, sizeof(Customer), *n, ptr); 
    }
	int i;
	printf("|================================================================|\n");
	printf("|ID ||     Ten khach       ||      So dien thoai       | Status  |\n");
	printf("|================================================================|\n");
	for(i=0 ;i<*n;i++){
		printf("| %d ||%-21s||%-26s||        |\n", customers[i].id, customers[i].name, customers[i].phone);
		printf("|----------------------------------------------------------------|\n");
	}
	printf("|================================================================|\n");
	printf("\n");
	// Dong file 
	fclose(ptr);
}
void saveCustomerOfFile(int n, Customer customers[]){
	// Mo file 
	FILE *ptr=fopen("studentData.dat","wb");
	// Thao tac file
	if(ptr==NULL){
		printf("Khong mo duoc file");
	}
	fwrite(&n, sizeof(int), 1, ptr);
	fwrite(customers,sizeof(Customer),n,ptr);
	printf("Luu thong tin thanh cong");
	// Dong file 
	fclose(ptr);
}
void deleteCustomer(int *n, Customer customers[]){
    int position, i;
	printf("Moi ban nhap vao ID muon xoa:");
	scanf("%d", &position);
	int findIndex=-1;
	for(i=0;i<*n;i++){
		if(customers[i].id==position){
			findIndex =i;
			break;
		}
	} 
	if(findIndex==-1){
		printf("Khong tim thay khach de xoa!");
	}else{
		int val;
		printf("| %d ||%-20s||%-20s|\n", customers[findIndex].id, customers[findIndex].name, customers[findIndex].phone);
		printf("Ban co thuc su mua xoa khach nay khong? [1](co) [2](khong): \n");
		scanf("%d", &val);
		if(val == 1){
			int i;
			for(i=findIndex;i<*n;i++){
				customers[i]=customers[i+1];
			}
			(*n)--;
			printf("XOA THANH CONG!");
		}else if( val == 2){
			printf("DA HUY QUA TRINH XOA!");
		}else if((val != 1)&&(val != 2)){
			printf("Khong co lua chon nay!");
		}
		
	}
}
void printCustomer(int n, Customer customers[]){
	int i;
	printf("==================================================================\n");
	printf("|ID ||     Ten khach       ||      So dien thoai       |  Status |\n");
	printf("==================================================================\n");
	for(i=0 ;i<n;i++){
		printf("| %d ||%-21s||%-26s|\n", customers[i].id, customers[i].name, customers[i].phone);
		printf("|------------------------------------------------------------------|\n");
	}
	printf("|==================================================================|\n");
	printf("\n");
}
void addCustomer(int *n, Customer customers[]){
	getchar();
    customers[*n].id = *n+1;
    do{
        printf("Moi ban nhap vao ten khach hang: \n");
        fgets(customers[*n].name, 100, stdin);
        customers[*n].name[strcspn(customers[*n].name, "\n")] = '\0';
        if (!checkString(customers[*n].name)){
            printf("Ten khach hang khong duoc trong\n");
        }
    }while(!checkString(customers[*n].name));
    do{
        printf("Moi ban nhap vao so dien thoao: \n");
        fgets(customers[*n].phone, 100, stdin);
        customers[*n].phone[strcspn(customers[*n].phone, "\n")] = '\0';
        if (!checkString(customers[*n].phone)) {
            printf("So dien thoai khong duoc trong\n");
        }
    }while (!checkString(customers[*n].phone));
    (*n)++; 
    printf("THEM KHACH THANH CONG!\n");
}
int checkIDCustomer(int id, Customer customers[], int n){
	int i; 
    for(i=0; i<n; i++) {
        if(customers[i].id == id){
            return 1;
        }
    }
    return 0;
}
void searchCustomer(int n, Customer customers[]){
	char searchCustomer[100];
	char searchLower[100];
	void toLowerCase(char *str){
		int i;
    	for(i=0; str[i]; i++){
        	str[i] = tolower(str[i]);
    	}
	}
    int found=0;
    printf("Moi ban nhap vao ten khach hang can tim: ");
    getchar();
    fgets(searchCustomer, sizeof(searchCustomer), stdin);
    searchCustomer[strcspn(searchCustomer, "\n")] = '\0';
    strcpy(searchLower, searchCustomer);
    toLowerCase(searchLower);
    printf("Ket qua tim kiem:\n");
    int i;
    for(i=0; i<n; i++){
        char customerLower[100];
        strcpy(customerLower, customers[i].name);
        toLowerCase(customerLower);
        if(strstr(customerLower, searchLower) != NULL){
        	printf("\n");
        	printf("---THONG TIN KHACH HANG---\n");
            printf("ID: %d\n", customers[i].id);
            printf("NAME: %s\n", customers[i].name);
            printf("PHONE NUMBER: %s\n", customers[i].phone);
            found=1;
        }
    }
    if (!found) {
        printf("KHONG TIM THAY KHACH HANG!\n");
    }
}
int checkCustomerName(char name[], Customer customers[], int n) {
    int i;
    for(i=0; i<n; i++) {
        if(strcmp(customers[i].name, name) == 0){
            return 1;
        }
    }
    return 0;
}
int checkPhoneNumber(char phone[]){
    int i, len = strlen(phone);
    if(len<10 || len>15){
        return 0;
    }
    for(i=0; i<len; i++){
        if(phone[i]<'0' || phone[i]>'9'){
            return 0;
        }
    }
    return 1;
}
int checkName(char name[]){
	int i;
    for(i=0; name[i] != '\0'; i++) {
        if(name[i]>='0' && name[i]<='9') {
            return 1;
        }
    }
    return 0;
}
