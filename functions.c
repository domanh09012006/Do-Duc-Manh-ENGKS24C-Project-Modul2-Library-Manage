#include"functions.h"
#include<stdio.h>
#include<string.h>
//Logic ham
void printMenu(){
	printf("\n=========== MENU ===========\n");
    printf("[1]. Nhap so luong va thong tin sach\n");
    printf("[2]. Hien thi thong tin sach\n");
    printf("[3]. Them sach vao vi tri\n");
    printf("[4]. Cap nhat thong tin sach theo ma sach\n");
    printf("[5]. Xoa sach theo ma sach\n");
    printf("[6]. Tim kiem sach theo ten sach\n");
    printf("[7]. Sap xep sach theo gia tien\n");
    printf("[8]. Thoat\n");
    printf("============================\n");
}
void inputBook(int *n, Book books[]){
	int i, a=0;
	printf("Nhap vap so luong sach: ");
	scanf("%d", n);
	getchar();
	for(i=0; i < *n; i++){
		printf("Quyen sach thu %d: \n", i+1);
		printf("Nhap ID: ");
		scanf("%d", &books[i].id);
		getchar();
		printf("Nhap ten sach: ");
		fgets(books[i].title, 100, stdin);
		books[i].title[strcspn(books[i].title, "\n")] = '\0';
		printf("Nhap ten tac gia: ");
		fgets(books[i].author, 100, stdin);
		books[i].author[strcspn(books[i].author, "\n")] = '\0';
		printf("Nhap gia tien: ");
		scanf("%d", &books[i].price);
		getchar();
	}
}
void printBook(int n, Book books[]){
	int i;
	printf("==================================================================\n");
	printf("|ID ||     Ten sach       ||      Tac gia       ||    Gia tien   |\n");
	printf("==================================================================\n");
	for(i=0 ;i<n;i++){
		printf("| %d ||%-20s||%-20s||%-15d|\n", books[i].id, books[i].title, books[i].author, books[i].price);
		printf("------------------------------------------------------------------\n");
	}
	printf("==================================================================\n");
	printf("\n");
}
void addBook(int *n, Book books[]){
	getchar();
	books[*n].id=*n+1;
	printf("Moi ban nhap vao ten sach: \n");
	fgets(books[*n].title, 100, stdin);
	books[*n].title[strcspn(books[*n].title, "\n")] = '\0';
	printf("Moi ban nhap vao ten tac gia: \n");
	fgets(books[*n].author, 100, stdin);
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
		int val;
		printf("| %d ||%-20s||%-20s||%-15d|\n", books[findIndex].id, books[findIndex].title, books[findIndex].author, books[findIndex].price);
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
    	for(i = 0; str[i]; i++){
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
    printf("Ket qua tim kiem:\n");
    int i;
    for(i = 0; i<n; i++){
        char titleLower[100];
        strcpy(titleLower, books[i].title);
        toLowerCase(titleLower);
        if (strstr(titleLower, searchLower) != NULL) {
            printf("ID %d: Ten sach: %s, Tac gia: %s, Gia: %d\n",books[i].id, books[i].title, books[i].author, books[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("KHONG TIM THAY SACH!\n");
    }
}
void updateBook(int n, Book books[]){
	int position;
	int i;
	printf("Moi ban nhap vao vi tri muon update:");
	scanf("%d", &position);
	int findIndex=-1;
	for( i=0;i<n;i++){
		if(books[i].id==position){
			findIndex=i;
			break;
		}
	} 
	if(findIndex==-1){
		printf("KHONG TIM THAY SACH DE UPDATE! ");
	}else{
		printf("| %d ||%-20s||%-20s||%-15d|\n", books[i].id, books[i].title, books[i].author, books[i].price);
		getchar();
		printf("CAP NHAT THONG TIN CHO SACH\n");
		printf("Moi ban nhap vao ten sach: \n");
		fgets(books[findIndex].title, 100, stdin);
		books[findIndex].title[strcspn(books[findIndex].title, "\n")] = '\0';
		printf("Moi ban nhap vao ten tac gia: \n");
		fgets(books[findIndex].author, 100, stdin);
		books[findIndex].author[strcspn(books[findIndex].author, "\n")] = '\0';
		printf("Moi ban nhap vao gia tien: \n");
		scanf("%d", &books[findIndex].price);
		getchar();
		printf("QUA TRINH UPDATE SACH HOAN TAT!");
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
		printf("==================================================================\n");
		printf("|ID ||     Ten sach       ||      Tac gia       ||    Gia tien   |\n");
		printf("==================================================================\n");
		for(i=0 ;i<n;i++){
			printf("| %d ||%-20s||%-20s||%-15d|\n", books[i].id, books[i].title, books[i].author, books[i].price);
			printf("------------------------------------------------------------------\n");
		}
		printf("==================================================================\n");
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
		printf("==================================================================\n");
		printf("|ID ||     Ten sach       ||      Tac gia       ||    Gia tien   |\n");
		printf("==================================================================\n");
		for(i=0 ;i<n;i++){
			printf("| %d ||%-20s||%-20s||%-15d|\n", books[i].id, books[i].title, books[i].author, books[i].price);
			printf("------------------------------------------------------------------\n");
		}
		printf("==================================================================\n");
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
	}
	Book readBook[100];
	*n=fread(readBook,sizeof(Book),100,ptr);
	int i; 
	printf("==================================================================\n");
	printf("|ID ||     Ten sach       ||      Tac gia       ||    Gia tien   |\n");
	printf("==================================================================\n");
	for(i=0 ; i<n; i++){
		printf("| %d ||%-20s||%-20s||%-15d|\n", readBook[i].id, readBook[i].title, readBook[i].author, readBook[i].price);
		printf("------------------------------------------------------------------\n");
	}
	printf("==================================================================\n");
	printf("\n");
	printf("Lay Du Lieu Thanh Cong\n");
	// Dong file 
	fclose(ptr);
}

