#include <stdio.h>
#include <math.h>

// 7task2.c
/*
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
*/

// 7task3.c

/*
int checkSign4(int a, int b, int c, int d){
	int ct = 0;
	int ls[4] = {a, b, c, d};
	for (int i=0;i<3;i++){
		for (int j=0;j<(3-i);j++){
			if (ls[i] > ls[i+j+1]){
				ct += 1;
			}
		}
	}
	if (ct % 2 == 0){
		return 1;
	}else{
		return -1;
	}
}

int main(){
	
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			for (int k=0;k<4;k++){
				for (int l=0;l<4;l++){
					if ((i == j) || (i == k) || (i == l) || (j == k) || (j == l) || (k == l)){
						continue;
					}else{
						printf("%d %d %d %d , ", i+1, j+1, k+1, l+1);
						printf("%d\n", checkSign4(i, j, k, l));
					}
				}
			}
		}
	}

}
*/

// 7task4.c

extern double v_t(double n);

double v_s(double n){
	if ( n == 0 ) return 2.0;
	else return sqrt(v_s(n - 1) * v_t(n - 1));
}

double v_t(double n){
	if ( n == 0 ) return 4.0;
	else return (2 * (v_s(n) / v_t(n - 1))) / (1 + v_s(n) / v_t(n - 1)) * v_t(n - 1);
}

int main(){
	for (int i=0;i<13;i++) printf("%lf , %lf\n", v_s((double)i), v_t((double)i));
	return 0;
}
