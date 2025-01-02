#include <stdio.h>
#include <string.h> 
#include"functions.h"
extern struct danhsach list[100];
//extern struct tkkhachhang check[100];
int a,b,i,j,mokhoa,thongtin; 
int doi;
int size = 0;
int length = 0;

void account(int *a){  					// nhap tai khoan 
int stk;
int mk;
 do {
		printf("Tai khoan: ");
        if (scanf("%d", &stk) != 1) {  
            printf("so tai khoan khong hop le!\n");
            while (getchar() != '\n');
            continue;
        }
	   printf("Mat khau: ");
        if (scanf("%d", &mk) != 1) {  
            printf("mat khu khong hop le\n");
            while (getchar() != '\n'); 
            continue;
        }
        	if (stk==mk) {
            printf("Dang nhap thanh cong\n");
            *a = 1; 
            break;   
        	} else {
            printf("Tai khoan hoac mat khau khong dung. Vui long thu lai.\n");
            *a = 0;  
            continue;
	}
    } while (*a == 0); 
}

void hienthi(){	                        //hien thi 
	printf("\nkhách hàng:\n");
    printf("+----+----------------+----------------------+-----------------+---------+\n");
    printf("| ID | Name           | Gmail                | Phone           | Status  |\n");
    printf("+----+----------------+----------------------+-----------------+---------+\n");
        for ( i = 0; i < size; i++) {
        	printf("| %-2d | %-14s | %-20s | %-15s | %-7s |\n",
               list[i].id, list[i].name, list[i].gmail,
               list[i].sdt, list[i].khoa);
            printf("+----+----------------+----------------------+-----------------+---------+\n");
        }
    
	}	
		
void timkiem(){                         //tim kiem
int tra=0;
size = size +1;
do{
	printf("nhap id khach hang muon xem: ");
	scanf("%d",&thongtin);
	if(thongtin > 0 && thongtin < size){
			tra=1;
			printf(" khach hang chi tiet:\n");
			for(i = 0 ;i < size ;i++){
    		if(thongtin == list[i].id){	
    		printf("\nDanh sach khach hang:\n");
    printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
    printf("| ID | Name           | CCCD              | Birthday           | Gmail                | Phone           | Status  |\n");
    printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
             printf("| %-2d | %-14s | %-17s | %02d/%02d/%-12d | %-20s | %-15s | %-7s |\n",
               list[i].id, list[i].name, list[i].socancuoc,
               list[i].ngay, list[i].thang, list[i].nam,
               list[i].gmail, list[i].sdt, list[i].khoa);
    printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
			break;	
			}
		}
	}
		if (tra==0) {
            printf("khong co khachh hang .xin vui long nhap lai\n");
        }
	}while(a==0);
}



int kiemtrasdt(const char* phone){      		// da xong
 int length = strlen(phone);
     if (length != 10) {
        return 0;
    }
    for (i = 0; i < length; i++) {
        if (phone[i] < '0' || phone[i] > '9') {
            return 0;
        }
    }
    return 1;
} 



int kiemtragmail(const char*ten , const char*gmail){
     
         if (strcmp(ten, gmail) == 0) {
            return 0; 
        }
    return 1;
}

int kiemtraten(const char*ten ){
int length = strlen(ten);
	for(i=0 ; i<length;i++){
		if(ten[i] >= 'A' && ten[i] <= 'z' ){
			return 1;
		}
	} 
	return 0;
}
int kiemtracancuoc(const char*cm ){
int length = strlen(cm);
	if(length >= 12 ){
		return 1;
	}
	return 0;
}

void themphantu(){		//tham phan tu vao ham 
//FILE *ptr =fopen("khachhang.dat","wb");
printf("\nso luong khanh hang muon nhap: ");
	scanf("%d",&b);
	for ( i = 0 ; i < b ; i++){
    printf("Nhap thong tin khach hang moi:\n");
	
	list[size].id = size + 1; 
    printf("ID: %d\n", list[size].id);
  	getchar();
	
	
	while(1){
	printf("Name: ");
    fgets(list[size].name, sizeof(list[size].name), stdin);
    list[size].name[strcspn(list[size].name, "\n")] = 0; 
	fflush(stdin);		
	   if (kiemtraten(list[size].name)) {
	   	break;
    }else{
    	printf("khong hop le . vui long thu lai\n ");		
   }
}	
while(1){

	printf("So can cuoc: ");
    fgets(list[size].socancuoc, sizeof(list[size].socancuoc), stdin);
    list[size].socancuoc[strcspn(list[size].socancuoc, "\n")] = 0; 
	fflush(stdin);
	
	if (kiemtracancuoc(list[size].socancuoc)) {
		break;
   	} else {
    	printf("so can cuoc khong hop le\n");
}
}	
	printf("Enter date (day month year): ");
    scanf("%d %d %d",&list[size].ngay, &list[size].thang, &list[size].nam);
	fflush(stdin);
while(1){
	printf("gmail: ");
    fgets(list[size].gmail, sizeof(list[size].gmail), stdin);
    list[size].gmail[strcspn(list[size].gmail, "\n")] = 0;
	fflush(stdin);
    if (kiemtragmail(list[size].name, list[size].gmail) == 0) {
    	printf("Khong hop le.xin vui long thu lai\n");
    } else {
    	break;
         
    }
}
   
    while (1) {  // da xong khong doong vao 
            printf("SDT: ");
            fgets(list[size].sdt, sizeof(list[size].sdt), stdin);
            list[size].sdt[strcspn(list[size].sdt, "\n")] = 0;
			fflush(stdin);
            if (kiemtrasdt(list[size].sdt)) {
                break; 
            } else {
                printf("khong hop le.\n");
            }
        }
	strcpy(list[size].khoa, "open");
//	strcpy(list[size].sodu, "0");
    size++;
    printf("\nKhach hang da duoc them thanh cong!\n");
 }      
//    fwrite(list, 100,sizeof(struct danhsach), ptr);
//    fwrite(&list[0], sizeof(struct danhsach), size, ptr);
//	fclose(ptr); 
}
	

void sapxep(){
int sapxep;					//sap xep theo chuwx cai giam dan 
do{
	printf("\n1.sap xep theo ten");
	printf("\n2.sap xep theo nam sinh");
	printf("lua chon: ");
	scanf("%d",&sapxep);
	switch(sapxep){
	case 1:				
	for (i = 0; i < size-1 ; i++) {  
        for (j = i+1; j < size; j++) {  
            if (strcmp(list[i].name, list[j].name) < 0) {
                struct danhsach temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
			break;
	case 2:
	for (i = 0; i < size-1 ; i++) {  
        for (j = i+1; j < size; j++) {  
            if (list[i].nam < list[j].nam) {
                struct danhsach temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
		break;
	}
	printf("da sap xep thanh cong");
    hienthi();
 }while(sapxep != 3); 
}


void trangthai(){						// trang thai mowr / khoa
int x=0;
	hienthi();
	printf("nhap id muon thay doi la: ");
	scanf("%d",&doi);
	for(i=0 ; i < size ;i++){
		if(doi == list[i].id){
		printf("da tim thay khach hang");
		if(strcmp(list[i].khoa, "open") == 0){
		strcpy(list[i].khoa, "close");	
		printf("da khoa khach hang");
		} else if (strcmp(list[i].khoa, "close") == 0){
		strcpy(list[i].khoa, "open");
		printf("da mo khoa khach hang");
	}
		printf("\nda thay doi thanh cong");
		printf("\ntai khoan: %s",list[i].sdt);
    	printf("\nmatkhau: %s\n",list[i].sdt);
		printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
    	printf("| ID | Name           | CCCD              | Birthday           | Gmail                | Phone           | Status  |\n");
    	printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
             printf("| %-2d | %-14s | %-17s | %02d/%02d/%-12d | %-20s | %-15s | %-7s |\n",
               list[i].id, list[i].name, list[i].socancuoc,
               list[i].ngay, list[i].thang, list[i].nam,
               list[i].gmail, list[i].sdt, list[i].khoa);
    	printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
		x=1;
		}
	}
		if (x == 0) {
        printf("Khong tim thay ID.\n");
    }
}

void timkiemkhachhang() {					// tim kiem bang ten
  char name[100]; 
    int g = 0;
    printf("\nnhap ten:\n");
    scanf(" %[^\n]", name); //cho phep nhap chuoi cos dau cach
		for (i = 0; i < size; i++) {
        if (strstr(list[i].name, name) != NULL) { 
            g = 1; 
	printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
    printf("| ID | Name           | CCCD              | Birthday           | Gmail                | Phone           | Status  |\n");
    printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
             printf("| %-2d | %-14s | %-17s | %02d/%02d/%-12d | %-20s | %-15s | %-7s |\n",
               list[i].id, list[i].name, list[i].socancuoc,
               list[i].ngay, list[i].thang, list[i].nam,
               list[i].gmail, list[i].sdt, list[i].khoa);
    printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
    }
  }    
    if (g == 0) {
        printf("khong tim thay khach hang.\n");
    }
}










void menuchoadmin(){					// menu cho quan ly
    do{
printf("\n+---------------------------------------------+\n");
printf("|                 MENU CHINH                  |\n");
printf("+---------------------------------------------+\n");
printf("| 1. Them khach hang                          |\n");
printf("| 2. Hien thi tat ca khach hang               |\n");
printf("| 3. Hien thi chi tiet khach hang             |\n");
printf("| 4. Khoa / Mo khoa khach hang                |\n");
printf("| 5. Sap xep khach hang                       |\n");
printf("| 6. Luu thong tin khach hang                 |\n");
printf("| 7. tim kiem khach hang                      |\n");
printf("| 8. Thoat                                    |\n");
printf("+---------------------------------------------+\n");
    printf("\nlua chon cua ban: ");
	scanf("%d",&a);
	switch(a){	
	case 1:// da xong 
	system("clear || cls");
	themphantu();
 		break;
	case 2 :// da xong 
	system("clear || cls");
	hienthi();
		break;
	case 3: //da xong 
	system("clear || cls");
	timkiem();
   		break;
   	case 4: //da xong 
   	system("clear || cls");
   	trangthai();
   	break;
	case 5 ://da xong 
	system("clear || cls");
 		sapxep();
	break;
	
	case 6: // luu vao tep
	//luuFile(); 
	break;
	case 7:
	system("clear || cls");
	timkiemkhachhang();
	break;

	 case 8:// da xong 
	system("clear || cls");
	printf("\n+---------------------------------+\n");
    printf("|          PAI PAI                |\n");
    printf("|        TAM BIET QUAN LY         |\n");
    printf("+---------------------------------+\n");
	break;
}
	}while(a!= 8);				
}

//void luuFile() {
//    FILE *ptr = fopen("khachhang.dat", "wb"); 
//    if (ptr == NULL) {
//        printf("khong the mo file.\n");
//        return;
//    }
//
//    fwrite(list, sizeof(struct danhsach), size, ptr);
//    fclose(ptr);
//
//    printf("da luu vào file \n");
//}






























































































//void menuchokhachhang(){
//	printf("chao mung khach hang");
//	printf("moi ban nhap stk");
//	fgets(list[length].tk, sizeof(list[size].tk), stdin);
//    list[size].tk[strcspn(list[size].tk, "\n")] = 0; 
//	fflush(stdin);	
//	
//	printf("moi ban nhap mk");
//	fgets(list[size].mk, sizeof(list[size].mk), stdin);
//    list[size].mk[strcspn(list[size].mk, "\n")] = 0; 
//	fflush(stdin);	
//do{
//	printf("\n1. thong tin tai khoan");
//	printf("\n2.lich su giao dich");
//	printf("\n3. doi thong tin ca nhan");
//    printf("\n4. nap tien tai khoan");
//	printf("\n5. rut tien tai khoan");
//    printf("\n5. doi mat khau");
//    printf("thoat");
//    printf("\nlua chon cua ban: ");
//	scanf("%d",&b);
//	switch(b){	
//	case 1:// da xong 
//	system("clear || cls");
//	
// 		break;
//	case 2 :// da xong 
//	system("clear || cls");
//
//		break;
//	case 3: //da xong 
//	system("clear || cls");
//	
//   		break;
//   	case 4: //da xong 
//   	system("clear || cls");
//   	
//   	break;
//	case 5 ://da xong 
//	system("clear || cls");
// 	
//	break;
//	
////	case 6: // luu vao tep
////	break:
//	case 7:
//	system("clear || cls");
//;
//	break;
//
//	 case 8:// da xong 
//	system("clear || cls");
//	printf("\n+---------------------------------+\n");
//    printf("|          PAI PAI                |\n");
//    printf("|        TAM BIET khach hang         |\n");
//    printf("+---------------------------------+\n");
//	break;
//}
//	}while(a!= 8);				
//}
//void thongtintaikhoan(){
//	printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+------------+\n");
//    printf("| ID | Name           | CCCD              | Birthday           | Gmail                | Phone           | Status  | Sodu       |\n");
//    printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+------------+\n");
//
//              printf("| %-2d | %-14s | %-17s | %02d/%02d/%-12d | %-20s | %-15s | %-7s | %-10.2f |\n",
//               list[i].id, list[i].name, list[i].socancuoc,
//               list[i].ngay, list[i].thang, list[i].nam,
//               list[i].gmail, list[i].sdt, list[i].khoa, list[i].sodu);
//}	
