#include <stdio.h>

int TimUoc(int x, int y){
    if (y == 0) return x;
    return TimUoc(y, x%y);
}

int main(){
    int x, y;
    printf("Hay nhap x: ");
    scanf("%d",&x);
    printf("Hay nhap y: ");
    scanf("%d",&y);
    printf("UCLN la: %d\n", TimUoc(x,y));
    printf("BCNN la: %d\n", (x*y)/TimUoc(x,y));
    return 0;
}