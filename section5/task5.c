#include <stdio.h>

// 5task2
/*
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
*/

// 5task42
// /*
double gcd(int n, int m){
    // convert x > y
    int x, y = 0;
    if (n >= m){
        x = n;
        y = m;
    }else if (n < m){
        x = m;
        y = n;
    }
    if (y == 0){
        return x;
    }else{
        return gcd(y, x % y);
    }
}

double lcm(int n, int m){
    return (n * m) / gcd(n, m);
}

int main(){
    // printf("%f\n", gcd(3289, 5083));
    int n, m;
    scanf("%d %d\n", &n, &m);
    printf("%lf", lcm(n, m));
    return 0;
}
// */