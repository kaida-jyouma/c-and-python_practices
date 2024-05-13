#include <stdio.h>

// 5task2
// /*
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
// */

// 5task42
// /*
double gcd(int n, int m){
    // convert x > y
    if (n > m){
        int x = n;
        int y = m;
    }else if (n < m){
        int x = m;
        int y = n;
    }
    if (y == 0){
        return x;
    }else{
        return gcd(y, x % y);
    }
}

double lcm(int n, int m){
    
}

int main(){
    printf("%d\n", gcd(6, 3));
    return 0;
}
// */