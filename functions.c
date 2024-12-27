#include"functions.h"
#include<stdio.h>
#include<string.h>
//Logic ham
void printMenu(){
	printf("\n=========== MENU ===========\n");
    printf("1. Nhap so luong va thong tin sach\n");
    printf("2. Hien thi thong tin sach\n");
    printf("3. Them sach vao vi tri\n");
    printf("4. Cap nhat thong tin sach theo ma sach\n");
    printf("5. Xoa sach theo ma sach\n");
    printf("6. Tim kiem sach theo ten sach\n");
    printf("7. Sap xep sach theo gia tien\n");
    printf("8. Thoat\n");
    printf("============================\n");
}
void inputBook(int *n, Book books[]){
	int i;
	printf("Nhap vap so luong sach: ");
	scanf("%d", n);
	getchar();
	for(i=0; i < *n; i++){
		printf("Quyen sach thu %d: \n", i+1);
		printf("Nhap ID: ");
		scanf("%d", &books[i].id);
		getchar();
		printf("Nhap ten sach: ");
		fgets(books[i].title, 50, stdin);
		books[i].title[strcspn(books[i].title, "\n")] = '\0';
		printf("Nhap ten tac gia: ");
		fgets(books[i].author, 50, stdin);
		books[i].author[strcspn(books[i].author, "\n")] = '\0';
		printf("Nhap gia tien: ");
		scanf("%d", &books[i].price);
		getchar();
	}
}
void printBook(int n, Book books[]){
	int i;
	printf("In toan bo cac sach: \n");
	for( i=0 ;i<n;i++){
		printf("Ma sach: %d\n", books[i].id);
		printf("Ten sach: %s\n", books[i].title);
		printf("Gia tien: %d\n", books[i].price);
		printf("Tac gia: %s\n", books[i].author);
	}
	printf("\n");
}
void addBook(int *n, Book books[]){
	getchar();
	books[*n].id=*n+1;
	printf("Moi ban nhap vao ten sach: \n");
	fgets(books[*n].title, 100, stdin);
	books[*n].title[strcspn(books[*n].title, "\n")] = '\0';
	printf("Moi ban nhap vao ten tac gia: \n");
	fgets(books[*n].author, 50, stdin);
	books[*n].author[strcspn(books[*n].author, "\n")] = '\0';
	printf("Moi ban nhap vao gia tien: \n");
	scanf("%d", &books[*n].price);
	getchar();
	(*n)++;
	printf("Them sach thanh cong!\n");
}
void deleteBook(int *n, Book books[]){
	int position, i;
	printf("Moi ban nhap vao vi tri muon xoa:");
	scanf("%d", &position);
	int findIndex=-1;
	for( i=0;i<*n;i++){
		if(books[i].id==position){
			findIndex =i;
			break;
		}
	} 
	if(findIndex==-1){
		printf("Khong tim thay sach de xoa");
	}else{
		int i;
		for( i=findIndex;i<*n;i++){
			books[i]=books[i+1];
		}
		(*n)--;
	}
}
void saveOfFile(int n, Book books[]){
	// Mo file 
	FILE *ptr=fopen("studentData.bin","wb");
	// Thao tac file
	if(ptr==NULL){
		printf("Khong mo duoc file");
	}
	fwrite(books,sizeof(Book),n,ptr);
	printf("Luu thong tin thanh cong");
	// Dong file 
	fclose(ptr);
}
