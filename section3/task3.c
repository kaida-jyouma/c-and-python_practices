#include <stdio.h>

int main(void){

    // 3task21.c
    
    double a; // define "a" with type "double"
    scanf("%lf", &a); // receive number and input it to "a"
    double stnum = 1001;
    if (a == 0 || a == 0.1 || a == 1){
        printf("%d", 0);
    }else if (a == 0.2 || a == 3){
        printf("%lf", stnum);
    }else{
		printf("%lf", 3.14); 
	}
    return 0;
        
}


    
    // 3task22.c
    /*
    int n; // define "n" with type "int"
    scanf("%d", &n); // receive number and input it to "n"
    if (n % 400 == 0){
        printf("閏年である");
    }else if (n % 100 == 0){
        printf("閏年でない");
    }else if (n % 4 == 0){
        printf("閏年である");
    }else{
        printf("閏年でない");
    }
    return 0;
    */
    
}
