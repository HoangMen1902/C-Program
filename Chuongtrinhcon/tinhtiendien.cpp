#include <stdio.h>

int main(){
    int tien, kwh;
    printf("Hay nhap vao gia tri dien: ");
    scanf("%d", &kwh);
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
    printf("So tien can phai tra la: %d ", tien);
    return 0;
}