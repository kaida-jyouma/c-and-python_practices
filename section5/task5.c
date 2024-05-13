#include <stdio.h>


// 5task2
double factorial(int n){
    double ans = 1;
    for (int i=n;i>0;i--) ans *= i;
    return ans;
}

double comb(int m, int n){
    return factorial(m)/(factorial(m - n) * factorial(n));
}

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%f\n", comb(m, n));
    return 0;
}
