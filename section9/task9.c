#include <stdio.h>
#include <math.h>

// 9task21

#define STUDENTS 200
#define SUBJECTS 4

int gainedScore(int i, int u1, int u2, int u3){
	if ((int)ceil(u1 * sin(u2 * i) + 1) % 4 == 0){
		return 90 + (int)ceil(10 * pow(sin(u3 * i), 3));
	}else if ((int)ceil(u1 * sin(u2 * i)) % 2 == 0){
		return 80 + (int)ceil(10 * pow(sin(u3 * i), 3));
	}else{
		return 70 + (int)ceil(20 * pow(sin(u3 * i), 5));
	}
}

double mean(int ls[], int length){
	double total = 0;
	for (int i=0;i<length;i++){
		total += ls[i];
	}
	return total / (double)length;
}

double variance(int ls[], int length){
	double total = 0;
	double total2 = 0;
	for (int i=0;i<length;i++){
		total += ls[i];
		total2 += pow(ls[i], 2);
	}
	return (total2 / (double)length) - pow(total / (double)length, 2.0);
}

double cov(int ls1[], int ls2[], int length){
	double m1 = mean(ls1, length);
	double m2 = mean(ls2, length);
	double multi = 0;
	for (int i=0;i<length;i++) multi += ls1[i] * ls2[i];
	return multi / (double)length - m1 * m2;

}

int failed(int ls[], int length){
	int ct = 0;
	for (int i=0;i<length;i++) if (ls[i] < 60) ct ++;
	return ct;
}

int main(){
	int scoreLists[SUBJECTS][STUDENTS] = {0};
	int coeff[SUBJECTS][3] = {
		{10000, 20000, 30000},
		{20000, 30000, 10000},
		{30000, 10000, 20000},
		{10000, 20000, 40000}
	};
	for (int i=0;i<SUBJECTS;i++){
		for (int j=0;j<STUDENTS / 2;j++){
			scoreLists[i][j] = gainedScore(j, coeff[i][0], coeff[i][1], coeff[i][2]);
		}
	}
	printf("index: mathp, engl, phys, prog\n");
	for (int i=0;i<STUDENTS / 2;i++){
		printf("%d: %d, %d, %d, %d\n", i+1, scoreLists[0][i], scoreLists[1][i], scoreLists[2][i], scoreLists[3][i]);
	}

	printf("ave, variance, failure\n");
	for (int i=0;i<SUBJECTS;i++){
		printf("%lf, %lf, %d\n", mean(scoreLists[i], STUDENTS / 2), variance(scoreLists[i], STUDENTS / 2), failed(scoreLists[i], STUDENTS / 2));
	}

	printf("\ncovariance\n");
	printf("math and engl: ");
	printf("%lf\n", cov(scoreLists[0], scoreLists[1], STUDENTS / 2));
	printf("math and phys: ");
	printf("%lf\n", cov(scoreLists[0], scoreLists[2], STUDENTS / 2));
	printf("math and prog: ");
	printf("%lf\n", cov(scoreLists[0], scoreLists[3], STUDENTS / 2));
	printf("engl and phys: ");
	printf("%lf\n", cov(scoreLists[1], scoreLists[2], STUDENTS / 2));
	printf("engl and prog: ");
	printf("%lf\n", cov(scoreLists[1], scoreLists[3], STUDENTS / 2));
	printf("phys and prog: ");
	printf("%lf\n", cov(scoreLists[2], scoreLists[3], STUDENTS / 2));
}


// 9task22 ..... Under Construcion -> Complete

// copy from 8task22 and rewrite in C language

/*

#include <stdio.h>
#include <math.h>

#define MAXIMUM 100000000

int primeFlags[MAXIMUM] = {0};

int function(int p[], int n){
	int ct = 0;
	while (1 == 1){ // while true ~~~
		if (p[ct] == 0){
			break;
		}else{
			if (n % p[ct] == 0){
				return 1;
			}else{
				return 0;
			}
		}
		ct ++;
	}
}

int main(){

	// Sieve of Eratosthenes
	int sq_f = floor(sqrt(MAXIMUM));
	// int primeFlags[MAXIMUM] = {0}; // -> to global variable
	primeFlags[0] = 1; // 1 is not prime number
	// printf("start calculating ......\n");
	
	for (int i=0;i<MAXIMUM;i++){
		// progress viewer
		if (i % (MAXIMUM / 25) == 0){
			printf("%d\n", i);
		}

		// calculate system
		if (primeFlags[i] == 0){
			// primeFlags == 0 -> the number cannot divide any number other than 1
			for (int j=2*i+1;j<MAXIMUM;j+=(i+1)){
				if (primeFlags[j] == 1){
					continue;
				}
				if ((j + 1) % (i + 1) == 0){
					primeFlags[j] = 1;
				}
			}
		}else{ 
			// primeFlags == 1 -> divisible by some numbers other than 1
			continue;
		}
	}

	int primect = 0;
	int primect10k = 0;
	int primeList[1500] = {0};
	for (int i=0;i<MAXIMUM;i++){
		if (primeFlags[i] == 0){

			
			if (i < 10000){
				// make primeList
				primeList[primect] = i + 1; 
			
				// display primeNumber
				printf("%d ", i + 1);

				// count up
				primect10k ++;
			}

			primect ++;
		}
	}
	printf("end\n");
	printf("%d\n", primect10k);
	printf("%d\n", primect);
	printf("\n");
}

*/
