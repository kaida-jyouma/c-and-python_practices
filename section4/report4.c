#include <stdio.h>

int makequestion(){
    printf("Enter an even prime number:"); // ask question
}

int inputKeyPress(){
    int n; // define "n"
    scanf("%d", &n);
    return n;
}

int checkAnswer(int k){
    if (k == 2){
        printf("Correct");
    }else{
        printf("the answer is 2.");
    }
}

int main(void){
    makequestion();
    checkAnswer(inputKeyPress());
    return 0;
}