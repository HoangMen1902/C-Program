#include <stdio.h>

int main(){
    const int Bac1=50,Bac2=100,Bac3=200,Bac4=300,Bac5=400;
    int kwh;
    int tiendien;
    printf("Hay nhap so dien: ");
    scanf("%d",&kwh);
    if(kwh<50){
        tiendien = Bac1*1678;
        printf("Tien dien la: %d\n",tiendien);
    } else if (kwh<100 && kwh>=50){
        tiendien = Bac1 * 1678 + (kwh - Bac1)*1734;
        printf("Tien dien la: %d\n",tiendien);
    } else if(kwh<200 && kwh>=100){
        tiendien = Bac1 * 1678 + 50 * 1734 + (kwh - Bac2)*2014;
        printf("Tien dien la: %d\n",tiendien);
    } else if(kwh>200 && kwh<=300){
        tiendien = Bac1 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - Bac3)*2536; 
        printf("Tien dien la: %d\n",tiendien);
    }else if(kwh>300 && kwh<=400){
        tiendien = Bac1 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - Bac4)*2834; 
        printf("Tien dien la: %d\n",tiendien);
    }else if(kwh>400){
        tiendien = Bac1 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - Bac5) *2927;
        printf("Tien dien la: %d\n",tiendien);
    }
return 0;
}
