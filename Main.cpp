#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Struct
struct SinhVien{
    char hoten[50];
    float diem;
};
//-------------------------------------- Thong tin sinh vien --------------------------------------
void ThongTinSV(){
	    int n;

    printf("Hay nhap so luong sinh vien muon them vao: ");
    scanf("%d", &n);
    SinhVien sv[n];

    //nhap thong tin sinh vien
    for(int i = 0; i < n; i++){
        printf("-------------------------------------\n");
        printf("Nhap thong tin sinh vien thu %d\n", i+1);
        printf("Ho ten: ");
        getchar();
        gets(sv[i].hoten);
        printf("Diem: ");
        scanf("%f",&sv[i].diem);
    }


    //Sap xep
    SinhVien svtemp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if(sv[i].diem < sv[j].diem){
                svtemp = sv[i];
                sv[i] = sv[j];
                sv[j] = svtemp;
            }
        }
    }

    //in
    printf("-------------------- Thong Tin Sinh Vien --------------------\n");
    for(int i = 0; i < n; i++){
        printf("=====================================\n");
        printf("Thong tin sinh vien thu %d\n",i+1);
        printf("Ten: %s\n", sv[i].hoten);
        printf("Diem: %.2f\n", sv[i].diem);
        if(sv[i].diem >= 9){
            printf("Hoc luc: Xuat sac\n");
        }else if(sv[i].diem >= 8 && sv[i].diem < 9){
            printf("Hoc luc: gioi\n");
        }else if(sv[i].diem >= 6.5 && sv[i].diem < 8){
            printf("Hoc luc: Kha\n");
        }else if(sv[i].diem >= 5.0 && sv[i].diem < 6.5){
            printf("Hoc luc: Trung binh\n");
        }else{
            printf("Hoc luc: yeu\n");
        }
    }
}
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
// -------------------------------------TIM UOC CHUNG LON NHAT, BCNN -------------------------------
int TimUoc(int x, int y){
	if ( y == 0 ) return x;
	return TimUoc(y, x % y);
} 		//de quy tim uoc

		//Tim boi chung nho nhat
int TimBoi(int a,int b){
	return (a * b) / TimUoc(a, b); 
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
//--------------------------- Tinh Lai suat ------------------------
void TinhLaiSuat(){
	int tienvay;

    printf("Hay nhap so tien can vay: ");
    scanf("%d", &tienvay);

    int Lai;
    int Goc = tienvay / 12;
    int Tra;
    int Con;

    Con = tienvay;
    printf("Ky Han\t | Lai phai tra\t | Goc phai tra\t | So tien phai tra | So tien con lai\n");

    for(int i = 1 ; i <= 12; i++){
        Lai = Con * 0.05;
        Tra = Goc + Lai;
        Con = Con - Goc;
        printf("%d \t | %d \t | %d \t | %d \t    | %d\n", i, Lai, Goc, Tra, Con);
    }
}
//--------------------------- Chuc nang doi tien --------------------------------
 void DoiTien(){
	int soTienDoi;
	int menhGiaTien[9] = {500,200,100,50,20,10,5,2,1}; //9 menh gia tien
	int SoToTien[9] = {0};//tien can doi
	int i = 0;

	printf("Nhap vao so tien can doi: ");
	scanf("%d",&soTienDoi);



  	while (i < 9){
 		if (soTienDoi > menhGiaTien[i]){ //Tim menh gia nho hon neu so tien can doi = menh gia 
 	break;
	}
	i++;
 }
 
 	while (i<9 && soTienDoi>0){
 		SoToTien[i] = soTienDoi / menhGiaTien[i]; //Tinh ra so to tien
 		soTienDoi = soTienDoi % menhGiaTien[i];
 	i++;
 }

	printf("So tien sau khi da doi la: \n");

	for (int j = 0; j < 9; j++){
		if (SoToTien[j] > 0){
			printf("%d to %d VND \n", SoToTien[j], menhGiaTien[j]);
		}
	}
} 

//----------------------------- Vay tien mua xe ---------------------------------
void TinhVayTra(float phantramvay){
	double PhanTramTratruoc = 1.0 - phantramvay;
	double codinh = 500000000;
	int thoihan = 288;

	double TienTraTruoc = codinh * PhanTramTratruoc;
	codinh = codinh - TienTraTruoc;

	double trahangnam = codinh / thoihan;

	printf("So tien tra truoc la: %lf\n", TienTraTruoc);
	printf("So tien tra hang nam: %lf\n", trahangnam);
	printf("Ky han \t  | Lai phai tra  | Goc phai tra  | So tien phai tra  | So tien con lai\n");

	for(int i = 1; i <= thoihan; i++){
		double traLai = codinh * 0.072;
		double TienPhaiTra = traLai + trahangnam;
		codinh = codinh - trahangnam;

		printf("%d \t | %.2f \t | %.2f \t | %.2f \t    | %.2f\n", i, traLai, trahangnam, TienPhaiTra, codinh);
	}
}
void NhapPhanTramVay(){
	double phantramvay;

	printf("Hay nhap phan tram vay (0-80): ");
	scanf("%lf", &phantramvay);
	phantramvay = phantramvay/100;
	TinhVayTra(phantramvay);
}
//----------------------------- SO XO FPOLY -------------------------------------


void SinhSoKiemTraKQ(int n, int m){
    srand(time(0));

    int min = 1;
    int max = 15;
    int random_number_1,random_number_2;


    random_number_1 = (rand() % (max - min + 1)) + min;
    random_number_2 = (rand() % (max - min + 1)) + min;


	printf("Ket qua xo so la : %d va %d\n",random_number_1,random_number_2);

	if(n == random_number_1 && m == random_number_2 || n == random_number_2 && m == random_number_1) {
		printf("Xin chuc mung ban da trung giai nhat!\n");
	}else if(n == random_number_1 || n == random_number_2 || m == random_number_1 || m == random_number_2){
		printf("Xin chuc mung ban da trung giai nhi!\n");
	}else{
		printf("Chuc ban may man lan sau :< \n");
	}

}

void NhapSo(){
	nhapso:
	int n;
	int m;
	printf("Hay nhap so thu nhat tu 1 - 15: ");
	scanf("%d", &n);
	printf("Hay nhap so thu hai tu 1 - 15: ");
	scanf("%d", &m);
	if( m > 15|| n > 15 || n < 1 || m < 1){
		printf("So khong hop le: xin vui long nhap lai.");
		goto nhapso;
	}else{
		SinhSoKiemTraKQ(n,m); 
	}

}
//--------------------------- Tong hieu tich thuong 2 phan so --------------------------------
struct PhanSo{
	int tu, mau;
};

void Rutgon(PhanSo &PhanSo1) {
	int temp = TimUoc(PhanSo1.tu, PhanSo1.mau);

	if(temp == 1) return;

	PhanSo1.tu /= temp;
	PhanSo1.mau /= temp;
}

PhanSo KetQua;

void InRaPhanSo(PhanSo &PhanSo1) {
	printf("Ket qua: %d/%d\n", PhanSo1.tu, PhanSo1.mau);
}

void TinhTongPhanSo(PhanSo &PhanSo1, PhanSo &PhanSo2) {
	KetQua.tu = PhanSo1.tu*PhanSo2.mau + PhanSo2.tu*PhanSo1.mau; //quy dong
	KetQua.mau = PhanSo1.mau*PhanSo2.mau;
	Rutgon(KetQua);
}

void TinhHieuPhanSo(PhanSo &PhanSo1, PhanSo &PhanSo2) {
	KetQua.tu = PhanSo1.tu*PhanSo2.mau - PhanSo2.tu*PhanSo1.mau;//quy dong
	KetQua.mau = PhanSo1.mau*PhanSo2.mau;
	Rutgon(KetQua);
}

void TinhTichPhanSo(PhanSo &PhanSo1, PhanSo &PhanSo2) {
	KetQua.tu = PhanSo1.tu*PhanSo2.tu; //Tu nhan tu mau nhan mau
	KetQua.mau = PhanSo1.mau*PhanSo2.mau;
	Rutgon(KetQua);
}

void TinhThuongPhanSo(PhanSo &PhanSo1, PhanSo &PhanSo2) {
	KetQua.tu = PhanSo1.tu*PhanSo2.mau;//Tu nhan tu mau nhan mau
	KetQua.mau = PhanSo1.mau*PhanSo2.tu;
	Rutgon(KetQua);
}

void TinhPhanSo() {
	PhanSo x, y;

	printf("Hay nhap tu so x: ");
	scanf("%d", &x.tu);

	printf("Hay nhap mau so x: ");
	scanf("%d", &x.mau);

	printf("Hay nhap tu so y: ");
	scanf("%d", &y.tu);

	printf("Hay nhap mau so y: ");
	scanf("%d", &y.mau);


	printf("Phan so da nhap la: %d/%d va %d/%d\n", x.tu, x.mau, y.tu, y.mau);

	printf("\n");
	printf("=========================Ket Qua=========================\n");
	printf("Tong hai phan so la: ");
	TinhTongPhanSo(x, y);
	InRaPhanSo(KetQua);

	printf("\nHieu hai phan so la: ");
	TinhHieuPhanSo(x, y);
	InRaPhanSo(KetQua);

	printf("\nTich hai phan so la: ");
	TinhTichPhanSo(x, y);
	InRaPhanSo(KetQua);

	printf("\nThuong hai phan so la: ");
	TinhThuongPhanSo(x, y);
	InRaPhanSo(KetQua);
}

//--------------------------- HAM MAIN ------------------------------------------

int main(){
	int enter;
// =================== MENU ================= 
	Begin:
		printf("Chao mung ban den voi bai ASM mon Nhap mon lap trinh!\n");
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");	
		printf("+ 1. Chuong trinh kiem tra so nguyen	            +\n");
		printf("+ 2. Chuong trinh tim uoc so chung cua 2 so         +\n");
		printf("+ 3. Chuong trinh tinh tien karaoke                 +\n");	
		printf("+ 4. Chuong trinh tinh tien dien                    +\n");
 		printf("+ 5. Chuc nang doi tien                             +\n");
		printf("+ 6. Chuc nang tinh lai suat vay ngan hang tra gop  +\n");
		printf("+ 7. Chuong trinh vay tien mua xe                   +\n");
		printf("+ 8. Sap xep thong tin sinh vien                    +\n");	 		 		 		 		 	
		printf("+ 9. game FPOLY-LOTT                                +\n");	 		 	
		printf("+ 10. Chuong trinh tinh toan phan so                +\n");	  		 		 	
		printf("+ 11. Thoat khoi chuong trinh                       +\n");	  	
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("Moi ban chon chuong trinh: ");
	int luaChon;
	scanf("%d",&luaChon);
	//-------------------------------- SWITCH CASE -----------------------
	switch(luaChon){ 
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
			system("pause");
			goto Begin;
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
			printf("Boi chung nho nhat la: %d\n", TimBoi(x,y)); //cong thuc tinh boi chung
			system("pause");
			goto Begin;
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
			system("pause");
			goto Begin;
			break;
			// -------------------------CASE 4 ----------
		case 4:
			/* system("cls"); */
			int kwh;
			printf("Hay nhap vao gia tri dien: ");
    		scanf("%d", &kwh);
			printf("Tien dien can phai tra la: %d", TienDien(kwh));
			system("pause");
			goto Begin;
			break;
		case 5:
			DoiTien();
			system("pause");
			goto Begin;
			break;
		case 6:
			TinhLaiSuat();
			system("pause");
			goto Begin;
			break;
		case 7:
			NhapPhanTramVay();
			system("pause");
			goto Begin;
			break;
		case 8:
			ThongTinSV();
			system("pause");
			goto Begin;
			break;
		case 9:
			NhapSo();
			system("pause");
			goto Begin;
			break;
		case 10:
			TinhPhanSo();
			system("pause");
			goto Begin;
			break;
		case 11:
			system("pause");
			break;
		default:{
			system("cls");
			printf("Ban da chon sai chuc nang! Vui long chon lai!\n");
			printf("--------------------------------------\n\n");
			system("pause");
			goto Begin;
			break;
		}
	}
	return 0;
}