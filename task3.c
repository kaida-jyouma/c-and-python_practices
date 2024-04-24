#include <stdio.h>

int main(void){

    // 3task21.c
    
    double a;
    scanf("%lf", &a);
    if (a == 0 || a == 0.1 || a == 1){
        printf("%d", 0);
    }else if (a == 0.2 || a == 3){
        printf("%lf", 3.14);
    }
    

    
    // 3task22.c
    /*
    int n;
    scanf("%d", &n);
    if (n % 400 == 0){
        printf("閏年である");
    }else if (n % 100 == 0){
        printf("閏年でない");
    }else if (n % 4 == 0){
        printf("閏年である");
    }else{
        printf("閏年でない");
    }
    */
    
}
