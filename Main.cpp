#include <stdio.h>
#include <stdlib.h>// -------------------------------------TIM UOC CHUNG LON NHAT --------------------------------
int TimUoc(int x, int y){
	if ( y == 0 ) return x;
	return TimUoc(y, x % y); //de quy tim uoc
}
//---------------------------------------TINH TIEN DIEN----------------------------------
int TienDien(int kwh){
	int tien;
    if(kwh <= 50 ){
        tien = kwh * 1678;
    }else if (  kwh > 50 && kwh <= 100 ){
        tien = 50 * 1678 + (kwh - 50) * 1734;
    } else if ( kwh > 100 && kwh <=200){
        tien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
    } else if ( kwh > 200 && kwh <= 300){
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 100) * 2536;
    } else if ( kwh > 300 && kwh <=400 ){
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 100) *2834;
    }else {
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + ( kwh - 100) * 2927;
    }
    return tien;
}
//--------------------------------TINH TIEN KARAOKE----------------------------------------------------------------
int kara(int giobatdau, int gioketthuc){
	int tien;
	int sogio = gioketthuc - giobatdau;
    if (sogio <= 3){
        tien = sogio * 150000;
    } else {
        tien = 3 * 150000 + (sogio - 3) * 150000 * 0.7;
    }
    if(giobatdau >= 14 && giobatdau <= 17) {
        tien = tien * 0.9;
    }
    return tien;

}
// -------------------------- CHUC NANG DOI TIEN --------------------------------
//--------------------------- HAM MAIN ------------------------------------------

int main(){
	int giobatdau, gioketthuc;
	int kwh;
	int x,y;
	int count = 0;
	Batdau:
		system("cls");
		printf("Chao mung ban den voi bai ASM mon Nhap mon lap trinh!\n");
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");	
		printf("+ 1. Chuong trinh kiem tra so nguyen	            +\n");
		printf("+ 2. Chuong trinh tim uoc so chung cua 2 so         +\n");
		printf("+ 3. Chuong trinh tinh tien karaoke                 +\n");	
		printf("+ 4. Chuong trinh tinh tien dien                    +\n");
		printf("+ 5. Chuc nang doi tien                             +\n");		
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("Moi ban chon chuong trinh: ");
	int luaChon;
	scanf("%d",&luaChon);
	if (luaChon > 5 || luaChon < 1){
		goto Batdau;
	}
	//-------------------------------- SWITCH CASE -----------------------
	switch(luaChon){ 
		// CASE ONE: --------------------------------
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
						break;
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
			// -------- CASE 2 -------
		case 2:
			system("cls");
			printf("Hay nhap gia tri cua x: ");
			scanf("%d", &x);
			printf("Hay nhap gia tri cua y: ");
			scanf("%d", &y);
			printf("Uoc chung lon nhat la: %d\n", TimUoc(x,y));
			printf("Boi chung nho nhat la: %d\n", x*y/TimUoc(x,y)); //cong thuc tinh boi chung
			break;
			// ------------- CASE 3 ---------------------
		case 3:
			system("cls");
			do{
				printf("Hay nhap gio bat dau: ");
				scanf("%d",&giobatdau);
				printf("Hay nhap gio ket thuc: ");
				scanf("%d",&gioketthuc);
				if(gioketthuc<giobatdau || gioketthuc>23 || giobatdau<12){
				printf("Gio khong hop le, Xin hay nhap lai\n");
			}
			}while(gioketthuc<giobatdau || gioketthuc>23 || giobatdau<12);
			kara(giobatdau,gioketthuc);
			printf("So tien phai tra la: %d",kara(giobatdau,gioketthuc));
			break;
			// -------------------------CASE 5 ----------
		case 4:
			system("cls");
			printf("Hay nhap vao gia tri dien: ");
    		scanf("%d", &kwh);
			TienDien(kwh);
			printf("Tien dien can phai tra la: %d", TienDien(kwh));
			break;
		default:
			goto Batdau;
			break;
	}
	return 0;
}