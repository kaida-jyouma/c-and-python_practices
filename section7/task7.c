#include <stdio.h>
#include <math.h>

// 7task2.c

int comb(int n, int k){
	if (k == 0){
		return 1;
	}else if (k > (n - k)){
		return comb(n, n - k);
	}else if (k > 0){
		return (comb(n, k - 1) * (n - k + 1)) / k;
	}
}

int main(){
	int a = comb(4, 2);
	printf("%d\n", a);
}
