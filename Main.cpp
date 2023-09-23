#include <stdio.h>
#include <stdlib.h>

int TimUoc(int x, int y){
	if ( y == 0 ) return x;
	return TimUoc(y, x % y); //de quy tim uoc
}

int main(){
	int x,y;
	int count = 0;
	printf("Chao mung ban den voi bai ASM mon Nhap mon lap trinh!\n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");	
	printf("+ 1. Chuong trinh kiem tra so nguyen	            +\n");
	printf("+ 2. Chuong trinh tim uoc so chung cua 2 so         +\n");
	printf("+ 3. Chuong trinh tinh phuong trinh bac 1           +\n");	
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("Moi ban chon chuong trinh: ");
	
	int luaChon;
	scanf("%d",&luaChon);
	
	switch(luaChon){
		case 1:
			system("cls");
			printf("Hay nhap vao 1 gia tri x: ");
			scanf("%d",&x);

			if( x % 1 == 0 ){
				printf("x La so nguyen\n");
			} else {
				printf("x khong phai la so nguyen\n");
			}
			if( x == 0 || x == 1 ){ // Tim so nguyen to
				printf("x khong phai la so nguyen to\n");
			} else {
				for (int i = 2; i < x; i++){
					if ( x % i == 0 ){
						count++;
					}
				}
				if ( count == 0){
					printf("x la so nguyen to\n");
				} else {
					printf("x khong phai la so nguyen to\n");
				}
			}
			count = 0;
			for (int i = 0; i < x; i++){
				if ( i * i == x ){
					printf("x la so chinh phuong\n");
					count++;
					break;
				}
			}
			if ( count == 0 ){
				printf("x khong phai la so chinh phuong\n");
			}
			return 0;
			break;
		case 2:
			system("cls");
			printf("Hay nhap gia tri cua x: ");
			scanf("%d", &x);
			printf("Hay nhap gia tri cua y: ");
			scanf("%d", &y);
			printf("Uoc chung lon nhat la: %d\n", TimUoc(x,y));
			printf("Boi chung nho nhat la: %d\n", x*y/TimUoc(x,y)); //cong thuc tinh boi chung
			break;
		case 3:
            break;
	}
	return 0;
}