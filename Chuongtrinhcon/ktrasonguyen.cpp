#include <stdio.h>

int main(){

    int x;
    int count = 0;
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
}