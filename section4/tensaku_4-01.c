// 送ってくれたコードを整形したもの + 問題点

/*
問題点
1. 関数mitsumoriA, mitsumoriB, mitsumoriCの返り値はintで宣言してるけど、コード上はぜんぶ真偽値になってるよ。(つまり警告が出るよ)
2. main関数内でint型の変数としてmitsumoriA, mitsumoriB, mitsumoriCを定義してるけど、定義しただけで値は代入されていないから足し算するととんでもない数を吐かれるよ。
3. 関数としてmitsumoriA, mitsumoriB, mitsumoriCが定義されてるけど、コード上は一度も使用(=>main関数内で呼び出し)されてないよ。使わなくても問題ないならいいけど......。
4. 
*/

#include <stdio.h>

int mitsumoriA(int n){
    if (n<=100){
        return n == n*50;
    }
    else if (n<=500){
        return n == 100*50+(500-n)*20;
    }
    else{
        return n == 100*50+400*20+(n-500)*10;
    }
}

int mitsumoriB(int m){
    if (m<=100){
        return m == m*50;
    }
    else if (m<=500){
        return m == 100*50+(500-m)*20;
    }
    else{
        return m == 100*50+400*20+(m-500)*10;
    }
}

int mitsumoriC(int l){
    if (l<=100){
        return l == l*50;
    }
    else if (l<=500){
        return l == 100*50+(500-l)*20;
    }
    else{
        return l == 100*50+400*20+(l-500)*10;
    }
}

int main(void){
    int mitsumorisum;
    int mitsumoriA;
    int mitsumoriB;
    int mitsumoriC;
    mitsumorisum == mitsumoriA + mitsumoriB + mitsumoriC;
    printf("見積額は%d",mitsumorisum);
}
        
