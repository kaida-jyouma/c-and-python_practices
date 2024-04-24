#include <stdio.h>

int main(void){
    double a, b, c; // define double a and b and c
    scanf("%lf %lf %lf", &a, &b, &c); // read num from console
    printf("sum=%lf\n", a + b + c); // print average
    printf("ave=%lf\n", (a + b + c) / 3); // print average
}
