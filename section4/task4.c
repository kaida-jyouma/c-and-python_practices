#include <stdio.h>
#include <vector>

int calcSum(int req){
    int ret = 0;
    if (req > 500){
        ret += 13000 + 10 * (req - 500);
    }else if (req > 100){
        ret += 5000 + 20 * (req - 100);
    }else{
        ret += 50 * req;
    }
    return ret;
}

int main(void){
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    int total = calcSum(a) + calcSum(b) + calcSum(c);
    printf("%d", total);
    return 0;
}
