#include <stdio.h>

int main(void){
    
    
    // task2-1
    printf("好きな食べ物は蕎麦です。\n"); // why: 安いから
    printf("好きな教科は情報です。\n"); // why: 楽しいから
    printf("\n");
    printf("\n");
    printf("よろしくお願いします。");
    return 0;
    
    
    /*
    // task2-2
    int x = 5;
    int y = 7;
    int z = 9;
    printf("x= %d\n", x);
    printf("y= %d\n", y);
    printf("z= %d\n", z);
    return 0;
    */
    
    
    // task2-3
    int x, y;
    double z, w;
    scanf("%d %d", &x, &y); // scan x and y
    scanf("%lf %lf", &z, &w); // scan z and w
    printf("x+y=%d\n", x+y); // display x+y
    printf("x-y=%d\n", x-y); // display x-y
    printf("x*y=%d\n", x*y); // display x*y
    printf("x/y=%d\n", x/y); // display x/y
    printf("x%y=%d\n", x%y); // display x%y
    printf("z+w=%lf\n", z+w); // display z+w
    printf("z-w=%lf\n", z-w); // display z-w
    printf("z*w=%lf\n", z*w); // display z*w
    printf("z/w=%lf\n", z/w); // display z/w
    printf("x+z=%lf\n", x+z); // display z+w
    printf("x+z*y=%lf\n", x+z*y); // display x+z*y
    return 0;
    
    
}
