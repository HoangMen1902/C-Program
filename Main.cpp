#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// -------------------------------------KIEM TRA SO NGUYEN --------------------------------
bool KiemTraSoNguyen(float x){
	if (x != int(x)) return false;
	return true;
}

bool KiemTraSoNguyenTo(int x) {
    if(x == 1 || x == 0) return false;
    for(int i = 2; i <= sqrt(x); i++) {
        if(x%i == 0) return false;
    }
    return true;
}
bool KiemTraSoChinhPhuong(int x){
	for(int i = 2; i < x; i++) {
		if ( i * i == x ){
			return true;
			break;
		}
	}
	return false;
}
// -------------------------------------TIM UOC CHUNG LON NHAT --------------------------------
/* int TimUoc(int x, int y){
	if ( y == 0 ) return x;
	return TimUoc(y, x % y); */ //de quy tim uoc
	// con 1 cach nua la viet vong lap while loop:

	int TimUoc(int x, int y){
    int temp;

	if( y > x ){

		temp = y;
		y = x;
		x = temp;
	}

    do{ //su dung vong lap 
        temp = x % y;
        x = y;
        y = temp;
    }while(x % y != 0);


    return temp; 
}
//---------------------------------------TINH TIEN DIEN----------------------------------
int TienDien(int kwh){
	const int Bac1=50,Bac2=100,Bac3=200,Bac4=300,Bac5=400;
	int tiendien;
    if(kwh<50){
        tiendien = Bac1*1678;
    } else if (kwh<100 && kwh>=50){
        tiendien = Bac1 * 1678 + (kwh - Bac1)*1734;
    } else if(kwh<200 && kwh>=100){
        tiendien = Bac1 * 1678 + 50 * 1734 + (kwh - Bac2)*2014;
    } else if(kwh>200 && kwh<=300){
        tiendien = Bac1 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - Bac3)*2536; 
    }else if(kwh>300 && kwh<=400){
        tiendien = Bac1 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - Bac4)*2834; 
    }else if(kwh>400){
        tiendien = Bac1 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - Bac5) *2927;
    }
	return tiendien;
}
//--------------------------------TINH TIEN KARAOKE----------------------------------------------------------------
int kara(int gbd, int gkt){
	int tien;
	int sogio = gkt - gbd;
    if (sogio <= 3){
        tien = sogio * 150000;
    } else {
        tien = 3 * 150000 + (sogio - 3) * 150000 * 0.7;
		printf("Ban da guoc giam 30 phan tram\n");
    }
    if(gbd >= 14 && gbd <= 17) {
        tien = tien * 0.9;
		printf("Ban da guoc giam them 10 phan tram\n");
    }
    return tien;

}
//--------------------------- HAM MAIN ------------------------------------------

int main(){


// =================== MENU ================= 
	Begin:
		system("cls");
		printf("Chao mung ban den voi bai ASM mon Nhap mon lap trinh!\n");
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");	
		printf("+ 1. Chuong trinh kiem tra so nguyen	            +\n");
		printf("+ 2. Chuong trinh tim uoc so chung cua 2 so         +\n");
		printf("+ 3. Chuong trinh tinh tien karaoke                 +\n");	
		printf("+ 4. Chuong trinh tinh tien dien                    +\n");
/* 		printf("+ 5. Chuc nang doi tien                             +\n");	 */	
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("Moi ban chon chuong trinh: ");
	int luaChon;
	scanf("%d",&luaChon);
	if (luaChon > 4 || luaChon < 1){
		goto Begin;
	}
	//-------------------------------- SWITCH CASE -----------------------
	switch(luaChon){ 
		// CASE ONE: --------------------------------
		case 1:{
			float x;
			/* system("cls"); */ //Comment lai de chup hinh output
			printf("Hay nhap vao 1 gia tri x: ");
			scanf("%f",&x);
			if(KiemTraSoNguyen(x) == true){
				printf("X la so nguyen\n");


				if(KiemTraSoNguyenTo(x) == true){
					printf("X la so nguyen to\n");

				} else {
					printf("X khong phai la so nguyen to\n");
				}
				// If thu 2
				if(KiemTraSoChinhPhuong(x) == true ){
					printf("X la so chinh phuong");

				}else{
					printf("X khong phai la so chinh phuong");
				}
				// Ket thuc chuoi if else


			} else { //Else cua if dau tien
				printf("X khong phai la so nguyen\n");
				printf("X khong phai la so nguyen to\n");
				printf("X khong phai la so chinh phuong\n");
			}
			break;
		}
			// -------- CASE 2 -------
		case 2:{
			int x,y;
			/* system("cls"); */
			printf("Hay nhap gia tri cua x: ");
			scanf("%d", &x);
			printf("Hay nhap gia tri cua y: ");
			scanf("%d", &y);
			printf("Uoc chung lon nhat la: %d\n", TimUoc(x,y));
			printf("Boi chung nho nhat la: %d\n", x*y/TimUoc(x,y)); //cong thuc tinh boi chung
			break;
			}
			// ------------- CASE 3 ---------------------
		case 3:
			/* system("cls"); */
			int gbd, gkt;
			Nhapgio:
				printf("Hay nhap gio bat dau: ");
				scanf("%d",&gbd);
				printf("Hay nhap gio ket thuc: ");
				scanf("%d",&gkt);
			if(gkt<gbd || gkt>23 || gbd<12){
				printf("Quan chi mo cua tu 12 - 23h, xin vui long nhap lai\n");
				goto Nhapgio;
			} //Lap lai neu bi sai gio


			printf("So tien phai tra la: %d",kara(gbd,gkt));
			break;
			// -------------------------CASE 4 ----------
		case 4:
			/* system("cls"); */
			int kwh;
			printf("Hay nhap vao gia tri dien: ");
    		scanf("%d", &kwh);
			printf("Tien dien can phai tra la: %d", TienDien(kwh));
			break;
	}
	return 0;
}