#include <stdio.h>

int main(void){
    printf("Enter an even prime number:"); // ask question
    int n; // define "n"
    scanf("%d", &n);
    if (n == 2){
        printf("Correct");
    }else{
        printf("the answer is 2.");
    }
    return 0;
}