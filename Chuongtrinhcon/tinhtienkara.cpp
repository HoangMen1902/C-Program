#include <stdio.h>

int main(){
    int giobatdau,gioketthuc,tien;
    do{
        printf("Hay nhap gio bat dau: ");
        scanf("%d",&giobatdau);
        printf("Hay nhap gio ket thuc: ");
        scanf("%d",&gioketthuc);
        if(gioketthuc<giobatdau || gioketthuc>23 || giobatdau<12){
            printf("Gio khong hop le, Xin hay nhap lai\n");
        }
    }while (gioketthuc<giobatdau || gioketthuc>23 || giobatdau<12);

    int sogio = gioketthuc - giobatdau;
    if (sogio <= 3){
        tien = sogio * 150000;
    } else {
        tien = 3 * 150000 + (sogio - 3) * 150000 * 0.7;
    }
    if(giobatdau >= 14 && giobatdau <= 17) {
        tien = tien * 0.9;
    }
    printf("Tien phai tra la: %d\n", tien);
    return 0;
}