#include <stdio.h>
#include <math.h>
#include <time.h>

// return digits in binary
int keta2(int n){
	int m = 0;
	while (n > 0){
		n = (n - n % 2) / 2;
		m += 1;
	}
	return m;
}

// return floor(cbrt(n))
double cubicrt(int n){
	double k = ((keta2(n) - 1) - ((keta2(n) - 1) % 3)) / 3;
	double m = pow(2.0, k);
	for (double i=0;i<k;i++){
		if (pow((m + pow(2.0, (k - 1.0 - i))), 3.0) <= n){
			m += pow(2.0, (k - 1 - i));
		}
	}
	return m;
}

// check cbrt(n) include "Z"
int check_cubic(int n){
	if (pow(cubicrt(n), 3.0) == (double)n) return 1;
	else return 0;
}


int check_cubic_sum(int n){
	double l = cubicrt((n - (n % 2)) / 2);
	int times = 0;
	int j = 0;
	for (int i=0;i<(l+1);i++){
		if (check_cubic(n - pow((double)i, 3.0)) == 1){
			if (times == 0) j = i;
			times += 1;
		}
		if (times == 3) break;
		
	}
	if (times == 3) return 1;
	else return 0;
}


int main(){
	int i = 0;
	int times = 0;
	time_t st = time(NULL);
	printf("%ld\n\n", st);
	while (times < 1){
		if (check_cubic_sum(i) == 1){
			times += 1;
			printf("%d\n", i);
		}
		if (i % 1000000 == 0){
			time_t nt = time(NULL);
			// Monitor detecting numbers
			printf("%d %ld\n", i, nt - st);
		}

		i += 1;
	}
	time_t ed = time(NULL);
	printf("\n");
	printf("%ld\n", ed);
	printf("%ld\n", ed - st);
}