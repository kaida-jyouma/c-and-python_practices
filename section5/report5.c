#include <stdio.h>
#include <math.h>

double arctan_ord20(double x){
    double n;
    for (int i=1;i<=20;i++) n += (pow((-1), (i-1)) * pow(x, 2*i - 1)) / (2*i - 1);
    return n;
}

int main(){
    double x, y;
    x = 16 * arctan_ord20(1.0/5.0);
    y = 4 * arctan_ord20(1.0/239.0);
    printf("%.20lf\n", x + y);
    return 0;
}