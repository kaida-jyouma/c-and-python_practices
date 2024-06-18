#include <stdio.h>
#include <math.h>
#include <omp.h>

#define MAXIMUM 10000
int leak[MAXIMUM * MAXIMUM] = {0}; // surplus memory
int disp = 10000;

/*

<CAUTION>
Do NOT use "clang" compiler

*/

int indexOf(int ls[], int length, int value){
	int flag = 0;
	for (int i=0;i<length;i++){
		if (ls[i] == value){
			flag ++;
			return i;
		}
	}
	if (flag == 0){
		return -1;
	}
}

int cycle(int n){
	int val = 1;
	int digit = 0;
	if (n == 2 || n == 5 || n == 4 || n == 25){
		return digit;

	}else{
		while (1 == 1){
			if (val < n) val *= 10;
			else break;
		}
		// printf("- - -\n"); // debug
		// printf("%d\n", val); // debug
		// int leak[MAXIMUM * MAXIMUM] = {0}; -> to Global
		
		for (int i=0;i<MAXIMUM*MAXIMUM;i++){
			leak[i] = 0;
		}

		leak[0] = val;
		digit ++;

		// Parallel processing
		#pragma omp parallel
		{
			#pragma omp for
			for (int i=0;i<MAXIMUM*MAXIMUM;i++){
				val = (val % n) * 10;
				leak[digit] = val;
				digit ++;
			}
		}

		// old code
		/*
		while (1 == 1){
			val = (val % n) * 10;
			if (!(indexOf(leak, digit, val) < 0)){
				break;
			}else{
				leak[digit] = val;
				digit ++;
			}
		}
		*/
		if (digit >= MAXIMUM * MAXIMUM) printf("%d - -\n", n);
		if (n > disp){
			printf("%d -\n", n);
			disp *= 10;
		}
		return digit;
	}
	/*
	while (1 == 1){
		if (n == 2 || n == 5 || n == 4 || n == 25){
			break;
		}
		
		val = pow(10, ct) - 1;
		printf("%lf\n", val);
		printf("%lf\n", floor(val / n) * n);
		printf("\n");
		ct += 1;
	}
	return ct;
	*/
}

double mean(double ls[], int length){
	double total = 0;
	for (int i=0;i<length;i++){
		total += ls[i];
	}
	return total / (double)length;
}

double variance(double ls[], int length){
	double total = 0;
	double total2 = 0;
	for (int i=0;i<length;i++){
		total += ls[i];
		total2 += pow(ls[i], 2);
	}
	return (total2 / (double)length) - pow(total / (double)length, 2.0);
}

double cov(double ls1[], double ls2[], int length){
	double m1 = mean(ls1, length);
	double m2 = mean(ls2, length);
	double multi = 0;
	for (int i=0;i<length;i++) multi += ls1[i] * ls2[i];
	return multi / (double)length - m1 * m2;
}

int main(){
	// Sieve of Eratosthenes
	int sq_f = floor(sqrt(MAXIMUM));
	int primeFlags[MAXIMUM] = {0};
	primeFlags[0] = 1; // 1 is not prime number
	// printf("start calculating ......\n");
	
	for (int i=0;i<MAXIMUM;i++){
		// progress viewer
		if (i % (MAXIMUM / 25) == 0){
			// printf("%d\n", i); // debug
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
	// printf("prime numbers list (~10k):\n");
	for (int i=0;i<MAXIMUM;i++){
		if (primeFlags[i] == 0){
			
			if (i < 10000){
				// make primeList
				primeList[primect] = i + 1; 
			
				// display primeNumber
				// printf("%d ", i + 1);

				// count up
				primect10k ++;
			}

			primect ++;
		}
	}
	printf("c0\n");
	double ip[1500] = {0};
	double jp[1500] = {0};
	printf("c1\n");
	printf("%d\n", primect10k);
	printf("%d\n", primeList[1]);
	printf("%d\n", cycle(49));
	printf("c2\n");

	
	for (int i=0;i<primect10k;i++){
		int ccl = cycle(primeList[i]); 
		ip[i] = (double)ccl / (double)primeList[i];
		jp[i] = sqrt(cycle((int)pow((double)primeList[i], 2.0))) / (double)primeList[i];
		if (i % 50 == 0){
			printf("%d - %d, %d\n", i, primeList[i], ccl);
		}
	}
	printf("c3\n");
	printf("%lf\n", cov(ip, jp, primect10k) / sqrt(variance(ip, primect10k) * variance(jp, primect10k)));
	

	return 0;
}
